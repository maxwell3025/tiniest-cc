enum token_type {
	SEMI,
	L_CURL,
	R_CURL,
	ADD,
	SUB,
	MUL,
	DIV
};

union token {
	
};

typedef struct token {
	
	union token data;
} token;
