#include "my_printf.h"

int main() {
    iocla_printf("%d\n", 3);
    iocla_printf("%u\n", 3);
    iocla_printf("%c\n", 65);
    iocla_printf("%x\n", 123);
    iocla_printf("%s\n", "Ana are mere");
    iocla_printf("Ana are %d mere si \t%%Hex@na%% are 0x%x mere\n", 5, 16);

    return 0;
}
