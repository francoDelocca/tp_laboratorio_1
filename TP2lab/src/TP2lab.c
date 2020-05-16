#include <stdio.h>
#include <stdlib.h>

//Bibliotecas
#include "Library/Library.Validate/Validate.h"
#include "Library/ArrayEmployees/ArrayEmployees.h"
#define LEN 1000

int main(void) {
	system("title #ABMapp - [ALPHA v0.1]");
	system("color 02");
	system("mode con: cols=80 lines=35");
	//system("mode con: cols=52 lines=35");
	ABM();

	return EXIT_SUCCESS;
}
