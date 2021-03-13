#include "ast.h"
#include "token.h"
#include "lexer.h"

typedef struct Parser {
	struct Lexer* lexer;
	struct Token* cur_token;
};

void match(struct Parser *parser, char type[TOKEN_TYPE_SIZE]);

struct Integer* expression(struct Parser* parser);
struct Integer* term(struct Parser* parser);
struct Integer* factor(struct Parser* parser);