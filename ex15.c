#include <stdio.h>

int main(int argc, char *argv[])
{
	// create two arrays we care about
	int ages[] = { 23, 43, 12, 89, 2 };
	char *names[] = {
		"Alan", "Frank",
		"Mary", "John", "Lisa"
	};

	// safely get the size of ages
	int count = sizeof(ages) / sizeof(int);
	int i = 0;

	// first way using indexing
	for (i = 0; i < count; i++) {
		printf("%s has %d yaers alive.\n", name[i], ages[i]);
	}

	printf("---\n"); 
