#include "parser.h"
#include <string.h>
#include <stdlib.h>

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
struct Integer* expression(struct Parser* parser)
{
	
}
// term ::= factor (('*'|'/') factor)*
struct Integer* term(struct Parser* parser)
{
	char state = 'i'; // i quiere decir que retorne Integer y 'b' que retorne binary.
	struct Integer* term = factor(parser);
	while (parser->cur_token->type == '*' || parser->cur_token->type == '/')
	{
		char ope[TOKEN_LEXEME_SIZE];
		strcpy_s(ope, TOKEN_LEXEME_SIZE, parser->cur_token->lexeme);

		match(parser, parser->cur_token->type); // Advance the token.

		// Create the BinaryOp type.
		struct BinaryOp* BinOp;
		BinOp = malloc(sizeof(struct BinaryOp));
		if (BinOp)
		{
			BinOp->left = term;
			BinOp->ope = ope;
			BinOp->right = factor(parser);
		}
	}

}
// factor ::= INTEGER
struct Integer* factor(struct Parser* parser)
{
	struct Integer *integer = malloc(sizeof(struct Integer));
	if (integer)
	{
		// Copiamos el Lexeme
		char lexeme[TOKEN_LEXEME_SIZE];
		strcpy_s(lexeme, TOKEN_LEXEME_SIZE, parser->cur_token->lexeme);

		match(parser, "INTEGER"); // Avanzamos el token
		
		// Generamos el ast
		integer->value = atoi(parser->cur_token->lexeme);

		return integer;
	}
}