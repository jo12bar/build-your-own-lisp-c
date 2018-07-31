/**
 * lispy
 *
 * An implementation of the "Build Your Own Lisp!" book.
 * Currently just displays a prompt and insults the user.
 */

#include <stdio.h>
#include <stdlib.h>

#include "mpc/mpc.h"

// Windows doesn't need the editline library, so we'll use some trick,
// compatibility functions instead.
#ifdef _WIN32
#include <string.h>

#define _WIN_INPUT_BUF_SIZE 2048
static char buffer[_WIN_INPUT_BUF_SIZE];

/** Fake readline function. */
char* readline(char* prompt) {
	fputs(prompt, stdout);
	fgets(buffer, _WIN_INPUT_BUF_SIZE, stdin);
	char* cpy = malloc(strlen(buffer) + 1);
	strcpy(cpy, buffer);
	cpy[strlen(cpy) - 1] = '\0';
	return cpy;
}

/** Fake add_history function */
void add_history(char* unused) {}

#else
#include <editline/readline.h>
#include <editline/history.h>
#endif // _WIN32

int main(int argc, char** argv) {
	// Create some parsers
	mpc_parser_t* Number   = mpc_new("number");
	mpc_parser_t* Operator = mpc_new("operator");
	mpc_parser_t* Expr     = mpc_new("expr");
	mpc_parser_t* Lispy    = mpc_new("lispy");

	mpca_lang(MPCA_LANG_DEFAULT,
		"                                                  \
		number   : /-?[0-9]+\\.?[0-9]*/ ;                  \
		operator : '+' | \"add\"                           \
		         | '-' | \"sub\"                           \
		         | '*' | \"mul\"                           \
		         | '/' | \"div\"                           \
		         | '%' | \"mod\" ;                         \
		expr     : <number> | '(' <operator> <expr>+ ')' ; \
		lispy    : /^/ <operator> <expr>+ /$/ ;            \
		",
		Number, Operator, Expr, Lispy);

	// Print version & exit info
	puts("Lispy version 0.0.2");
	puts("Press Ctrl+c to Exit\n");

	while(1) {
		// Output our prompt and get input.
		char* input = readline("lispy> ");
		add_history(input);

		// Attempt to parse the user input
		mpc_result_t r;
		if (mpc_parse("<stdin>", input, Lispy, &r)) {
			// Print the AST on success.
			mpc_ast_print(r.output);
			mpc_ast_delete(r.output);
		}
		else {
			mpc_err_print(r.error);
			mpc_err_delete(r.error);
		}

		free(input);
	}

	// Undefine & delete our parsers.
	mpc_cleanup(4, Number, Operator, Expr, Lispy);

	return 0;
}
