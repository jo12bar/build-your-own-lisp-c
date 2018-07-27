/**
 * ch3_bonus_marks.c
 *
 * Implements various challenges in the "Bonus Marks" section at the end of
 * chapter 3 of the book.
 */

#include <stdio.h>

/**
 * Outputs "Hello World!\n" to stdout n number of times.
 * @param {int} n The number of times to output
 */
void nhello(int n) {
	for (int i = 0; i < n; i++) {
		puts("Hello World!");
	}
}

int main(int argc, char** argv) {
	// 1. Use a for loop to print out "Hello World!" five times.
	puts("--- TASK 1 ---");
	for (int i = 0; i < 5; i++) {
		puts("Hello World!");
	}

	// 2. Use a while loop to print out "Hello World!" five times.
	puts("--- TASK 2 ---");
	int j = 0;
	while (j < 5) {
		puts("Hello World!");
		j++;
	}

	// 3. Declare a function that outputs "Hello World!" n number of times.
	//    Call this from main.
	puts("--- TASK 3 ---");
	nhello(7);
}
