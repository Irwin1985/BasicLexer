#include "lexer.h"
#include "token.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Avanza el siguiente caracter del código fuente.
void advance(struct Lexer *lexer)
{
	lexer->pos += 1;
	if (lexer->pos >= strlen(lexer->text))
	{
		lexer->current_char = NONE;
	}
	else 
	{
		lexer->current_char = lexer->text[lexer->pos];
	}
}

// Retorna una instancia de Lexer.
struct Lexer* new_lexer(char text[TEXT_SIZE])
{
	struct Lexer *lexer;
	lexer = malloc(sizeof(struct Lexer));
	if (lexer)
	{
		strcpy_s(lexer->text, sizeof(lexer->text), text);
		lexer->pos = 0;
		lexer->current_char = lexer->text[lexer->pos];

		return lexer;
	}
}

// Ignoramos los espacios en blanco
void skip_whitespace(struct Lexer *lexer)
{
	while (isspace(lexer->current_char))
	{
		advance(lexer);
	}
}

// Obtiene un número desde el código fuente y devuelve su Token.
struct Token* number(struct Lexer* lexer)
{
	char lexeme[TOKEN_LEXEME_SIZE];
	int cur_pos = 0;
	while (lexer->current_char != NONE && isdigit(lexer->current_char))
	{
		lexeme[cur_pos] = lexer->current_char;
		cur_pos += 1;
		advance(lexer);
	}
	lexeme[cur_pos] = '\0';
	return new_token("INTEGER", lexeme);
}

// Retorna el siguiente token desde el código fuente.
struct Token* get_next_token(struct Lexer *lexer)
{
	while (lexer->current_char != NONE)
	{
		// whitespace
		if (isspace(lexer->current_char))
		{
			skip_whitespace(lexer);
			continue;
		}
		// number
		if (isdigit(lexer->current_char))
		{
			return number(lexer);
		}
		// one digit operators
		if (lexer->current_char == '+')
		{
			advance(lexer);
			return new_token("PLUS", "+");
		}
		if (lexer->current_char == '-')
		{
			advance(lexer);
			return new_token("MINUS", "-");
		}
		if (lexer->current_char == '*')
		{
			advance(lexer);
			return new_token("MUL", "*");
		}
		if (lexer->current_char == '/')
		{
			advance(lexer);
			return new_token("DIV", "/");
		}
		// Carácter desconocido.
		printf("unknown character '%c'\n", lexer->current_char);
		exit(-1);
	}
	return new_token("EOF", "EOF");
}