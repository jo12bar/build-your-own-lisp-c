/**
 * lispy
 *
 * An implementation of the "Build Your Own Lisp!" book.
 * Currently just displays a prompt and insults the user.
 */

#include <stdio.h>
#include <stdlib.h>

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
