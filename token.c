#include "token.h"
#include <stdio.h>
#include <stdlib.h>

void print_token(struct Token tok)
{
	printf("-------------------------\n");
	printf("token.type: '%s'\n", tok.type);
	printf("token.lexeme: '%s'\n", tok.lexeme);
}

struct Token* new_token(char type[TOKEN_TYPE_SIZE], char lexeme[TOKEN_LEXEME_SIZE])
{
	struct Token *tok = malloc(sizeof(struct Token));
	if (tok)
	{
		strcpy_s(tok->type, sizeof(tok->type), type);
		strcpy_s(tok->lexeme, sizeof(tok->lexeme), lexeme);
		return tok;
	}
}