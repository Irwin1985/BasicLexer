/*
* Un REPL es una máquina de estados que interactua con el usuario programador.
*/
#include "token.h"
#include "lexer.h"
#include "parser_calc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PROMPT "<<Ni hao REPL>>\nPara salir pulse CTRL+C"
#define TRUE 1
#define BUFFER_SIZE 1024

int main(int argc, char* argv)
{
	// variable input para obtener la entrada desde el teclado.
	char input[BUFFER_SIZE];
	int result = 0;

	// Imprimir mensaje de bienvenida al REPL
	printf("%s\n", PROMPT);
	// Iniciar el LOOP
	while (TRUE)
	{
		// solicitar una entrada al usuario programador
		printf(">> ");
		if (fgets(input, BUFFER_SIZE, stdin) && strlen(input) >= 2)
		{
			// prueba invocar al lexer.
			struct Lexer *lexer = new_lexer(input);
			struct Parser* parser = new_parser(lexer);

			int result = expression(parser);
			printf("%d\n", result);

			free(lexer);
			free(parser); 

			// Si ha ingresado "quit" salimos del REPL.
			if (strcmp(input, "quit") == 0)
			{
				break;
			}
		}
	}
}