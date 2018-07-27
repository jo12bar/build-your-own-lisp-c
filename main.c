/**
 * lispy
 *
 * An implementation of the "Build Your Own Lisp!" book.
 * Currently just displays a prompt and insults the user.
 */

#include <stdio.h>
#include <stdlib.h>

#include <editline/readline.h>
#include <editline/history.h>

int main(int argc, char** argv) {
	// Print version & exit info
	puts("Lispy version 0.0.1");
	puts("Press Ctrl+c to Exit\n");

	while(1) {
		// Output our prompt and get input.
		char* input = readline("lispy> ");

		add_history(input);
		printf("No you're a %s\n", input);
		free(input);
	}

	return 0;
}
