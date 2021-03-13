#ifndef LEXER_H
	#define LEXER_H
	#define NONE 0
	#define TEXT_SIZE 1024
	typedef struct Lexer {
		char text[TEXT_SIZE];
		int pos;
		char current_char;
	};

	void advance(struct Lexer *lex);
	struct Lexer* new_lexer(char text[TEXT_SIZE]);
	struct Token* get_next_token(struct Lexer *lexer);
	void skip_whitespace(struct Lexer* lexer);
	struct Token* number(struct Lexer* lexer);
#endif