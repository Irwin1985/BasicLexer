#include "parser_calc.h"
#include <string.h>
#include <stdlib.h>

struct Parser* new_parser(struct Lexer* lexer)
{
	struct Parser *parser = malloc(sizeof(struct Parser));
	if (parser)
	{
		parser->lexer = lexer;
		parser->cur_token = get_next_token(lexer);
		return parser;
	}
}
// Verifica si type coincide con cur_token para avanzar o mostrar error.
void match(struct Parser* parser, char type[TOKEN_TYPE_SIZE])
{
	if (strcmp(parser->cur_token, type) == 0)
	{
		free(parser->cur_token);
		parser->cur_token = get_next_token(parser->lexer);
	}
	else
	{
		printf("unexpected token type '%s', wanted '%s'\n", parser->cur_token->type, type);
	}
}

// expression ::= term (('+'|'-') term)*
int expression(struct Parser* parser)
{
	int exp = term(parser);
	while (strcmp(parser->cur_token->type, "PLUS") == 0 || strcmp(parser->cur_token->type, "MINUS") == 0)
	{
		if (strcmp(parser->cur_token->type, "PLUS") == 0)
		{
			match(parser, "PLUS");
			exp += term(parser);
		}
		else if (strcmp(parser->cur_token->type, "MINUS") == 0)
		{
			match(parser, "MINUS");
			exp -= term(parser);
		}
	}
	return exp;
}
// term ::= factor (('*'|'/') factor)*
int term(struct Parser* parser)
{
	int term = factor(parser);
	while (strcmp(parser->cur_token->type, "MUL") == 0 || strcmp(parser->cur_token->type, "DIV") == 0)
	{
		if (strcmp(parser->cur_token->type, "MUL") == 0)
		{
			match(parser, "MUL");
			term *= factor(parser);
		}
		else if (strcmp(parser->cur_token->type, "DIV") == 0)
		{
			match(parser, "DIV");
			term /= factor(parser);
		}
	}
	return term;
}
// factor ::= INTEGER
int factor(struct Parser* parser)
{
	int value = 0;
	
	// Copiamos el Lexeme
	char lexeme[TOKEN_LEXEME_SIZE];
	strcpy_s(lexeme, TOKEN_LEXEME_SIZE, parser->cur_token->lexeme);

	match(parser, "INTEGER"); // Avanzamos el token

	// Generamos el ast
	value = atoi(lexeme);

	return value;
}