Aluno : Jorge Luís Melgarejo RA: 201519050011 - EC

Para sudoku 9x9:
	usar "#define MAX 9"
	compilar: gcc -Wall -pedantic -std=c99 *.c -o exec
	executar: time ./exec < in.txt

Para sudoku 16x16:
	usar "#define MAX 16"
	compilar: gcc -Wall -pedantic -std=c99 *.c -o exec
	executar: time ./exec < in16.txt