#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct EXPRESSION_t EXPRESSION;

typedef struct INT_t {
	int64_t value;
} INT;

typedef struct CHAR_t {
	uint8_t value;
} CHAR;

typedef struct BOOL_t {
	bool value;
} BOOL;

typedef struct FLOAT_t {
	double value;
} FLOAT;

typedef struct STRING_t {
	char* value;
} STRING;

typedef struct IDENTIFIER_t {
	char* name;
} IDENTIFIER;

typedef struct EXPRESSION_t* ARGUMENT;

typedef struct FUNC_CALL_t {
	EXPRESSION* callee;
	ARGUMENT* args;
} FUNC_CALL;

typedef struct ASSIGN_t {
	uint8_t op;
	EXPRESSION* left;
	EXPRESSION* right;
} ASSIGN;

typedef struct BINARY_OP_t {
	uint8_t op;
	EXPRESSION* left;
	EXPRESSION* right;
} BINARY_OP;

typedef struct UNARY_OP_t {
	uint8_t op;
	bool position;
	EXPRESSION* expr;
} UNARY_OP;

typedef struct EXPRESSION_t {
	uint8_t type;
	union {
		INT i;
	};
} EXPRESSION;

typedef struct EXPR_STATEMENT_t {
	EXPRESSION expr;
} EXPR_STATEMENT;

typedef struct STATEMENT_t {
	uint8_t type;
} STATEMENT;

typedef struct AST_t {
	STATEMENT* statements;
} AST;
