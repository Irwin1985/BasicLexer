typedef struct Integer {
	int value;
};
typedef struct BinaryOp {
	struct Integer* left;
	char* ope;
	struct Integer* right;
};