typedef enum {
	SEMI,
	L_CURL,
	R_CURL,
	ADD,
	SUB,
	MUL,
	DIV
} token_type;

typedef union token_data {
		
} token_data;

typedef struct token {
	token_type type;
	token_data data;
} token;

typedef struct token_list {
	token current;
	struct token_list *next;
} token_list;

