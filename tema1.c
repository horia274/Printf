#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

static int write_stdout(const char *token, int length)
{
	int rc;
	int bytes_written = 0;

	do {
		rc = write(1, token + bytes_written, length - bytes_written);
		if (rc < 0)
			return rc;

		bytes_written += rc;
	} while (bytes_written < length);

	return bytes_written;
}

/* Functia converteste numarul number in baza base si pastreaza rezultatul in convert_number */
static void convert(unsigned int number, int base, char *alph, int *count, char *convert_number)
{
	if(number == 0)
		return;

	convert(number / base, base, alph, count, convert_number);
	convert_number[++(*count)] = alph[number % base];
}

int iocla_printf(const char *format, ...)
{
	int count, bytes_written = 0;
	char convert_number[100], alph[16] = "0123456789abcdef";
	va_list args;

	memset(convert_number, 0, sizeof(convert_number));
	va_start(args, format);

	/* parcurg sirul caracter cu caracter */
	for (; *format; format++) {
		if (*format != '%') {
			/* daca nu am '%' afisez direct */
			bytes_written += write_stdout(format, sizeof(*format));
		} else {
			/* altfel disting cazuri in functie de caracterul urmator */
			count = 0;
			format++;

			/* folosesc functiile convert si write_stdout in fiecare caz */
			if (*format == 'd') {
				int arg = va_arg(args, int);
				if (arg > 0) {
					convert(arg, 10, alph, &count, convert_number);
					bytes_written += write_stdout((const char*)(convert_number + 1), count);
				} else {
					convert_number[0] = '-';
					convert(-arg, 10, alph, &count, convert_number);
					bytes_written += write_stdout((const char*)convert_number, ++count);
				}
			}

			if (*format == 'u') {
				unsigned int arg = va_arg(args, int);
				convert(arg, 10, alph, &count, convert_number);
				bytes_written += write_stdout((const char*)(convert_number + 1), count);
			}

			if (*format == 'x') {
				unsigned int arg = va_arg(args, int);
				convert(arg, 16, alph, &count, convert_number);
				bytes_written += write_stdout((const char*)(convert_number + 1), count);
			}

			if (*format == 'c') {
				char arg = va_arg(args, int);
				bytes_written += write_stdout((const char*)&arg, sizeof(arg));
			}

			if (*format == 's') {
				char* arg = va_arg(args, char*);
				bytes_written += write_stdout((const char*)arg, strlen(arg) * sizeof(*arg));
			}

			if (*format == '%') {
				bytes_written += write_stdout(format, sizeof(*format));
			}
		}
	}

	va_end(args);
	return bytes_written;
}
