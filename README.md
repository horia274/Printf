					Tema1 - Printf
	
		
		Functia "convert"
	
	Convertesc numarul "number" din baza 10, in baza "base" (orice baza de la 2
la 16), pastrand rezultat in string-ul convert_number. "Count" da dimensiunea
acestui string si implicit numarul de cifre din baza "base". Pozitia 0, a acestui
string (convert_number[0]) este lasata libera, pentru a pune semnul '-' pentru
numerele negative. "Alph" va fi declarat in "iocla_printf" si contine toate cifele
din baza 16.


		Functia "iocla_printf"
		
	Pornesc cu variabila "bytes_written" initializata cu 0, la care voi adauga
return-ul functiei "write_stdout" la fiecare apel. Aceasta variabila ca fi
returnata ulterior.

	Parcurg string-ul "format" iar daca am bucati de text (ceva diferit de '%')
le afisez. Daca nu, ma uit la urmatorul caracter din "format" si disting niste
cazuri. Pe masura ce gasesc cate un specificator, ma uit la urmatorul argument
din lista de argumente data ca parametru.

	Cazurile sunt (pentru urmatorul caracter de dupa '%'):

* d -> in caz ca numarul este negativ, apelez "convert" pentru opusul acelui
numar si ii pastrez semnul, altfel apelez direct "convert"; in ambele situatii,
baza este 10.

* u -> la fel ca mai sus, fara sa mai verific semnul, caci se face o conversie
automata.

* x -> apelez "convert" pentru baza 16.

* c / s -> afisez direct char-ul / string-ul

* % -> afisez caracterul '%'

