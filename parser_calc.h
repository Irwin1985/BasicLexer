#ifndef PARSER_CALC_H
	#define PARSER_CALC_H
	#include "token.h"
	#include "lexer.h"

	typedef struct Parser {
		struct Lexer* lexer;
		struct Token* cur_token;
	};

	void match(struct Parser* parser, char type[TOKEN_TYPE_SIZE]);

	int expression(struct Parser* parser);
	int term(struct Parser* parser);
	int factor(struct Parser* parser);
	struct Parser* new_parser(struct Lexer* lexer);
#endif