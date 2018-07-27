/**
 * lispy
 *
 * An implementation of the "Build Your Own Lisp!" book.
 * Currently just displays a prompt and insults the user.
 */

#include <stdio.h>

#define INPUT_BUF_SIZE 2048
static char input[INPUT_BUF_SIZE];

int main(int argc, char** argv) {
	// Print version & exit info
	puts("Lispy version 0.0.1");
	puts("Press Ctrl+c to Exit\n");

	while(1) {
		fputs("lispy> ", stdout);
		fgets(input, INPUT_BUF_SIZE, stdin);

		// Just echo input back to the user, hopefully insulting them.
		printf("No you're a %s", input);
	}

	return 0;
}
