/*
* Token: se encarga de descomponer el código fuente en pequeñas estructuras
* de datos llamadas Tokens.
*/
#ifndef TOKEN_H
	#define TOKEN_H
	#define TOKEN_TYPE_SIZE 25
	#define TOKEN_LEXEME_SIZE 1024

	typedef struct Token {
		char type[TOKEN_TYPE_SIZE];
		char lexeme[TOKEN_LEXEME_SIZE];
	};

	// Imprimir el contenido de un token (para debug)
	void print_token(struct Token tok);
	struct Token* new_token(char type[TOKEN_TYPE_SIZE], char lexeme[TOKEN_LEXEME_SIZE]);
#endif