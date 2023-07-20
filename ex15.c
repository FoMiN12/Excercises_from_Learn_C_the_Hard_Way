#include <stdio.h>

void first_function(size_t count, int ages[], char *names[]);
void second_function(size_t count, int *ages, char **names);
void third_function(size_t count, int *ages, char **names);
void fourth_function(size_t count, int *ages, char **names);
void print_adresses(size_t count, int *ages, char **names);

void first_function(size_t count, int ages[], char *names[])
{
	for (int i = count - 1; i >= 0; i--) {
		printf("%s has %d yaers alive.\n", names[i], ages[i]);
	}
}

void second_function(size_t count, int *ages, char **names)
{
	for (int i = count - 1; i >= 0; i--) {
		printf("%s is %d years old.\n",
				*(names + i), *(ages + i));
	}
}

void third_function(size_t count, int *ages, char **names)
{
	for (int i = count - 1; i >= 0; i--) {
		printf("%s is %d years old again.\n", names[i], ages[i]);
	}
}

void fourth_function(size_t count, int *ages, char **names)
{	
	char **cur_name;
	int *cur_age;
	for (cur_name = names + count - 1, cur_age = ages + count - 1;
			cur_age >= ages; cur_name--, cur_age--) {
		printf("%s lived %d years so far.\n", *cur_name, *cur_age);
	}
}

void print_adresses(size_t count, int *ages, char **names)
{
	for (int i = count - 1; i >= 0; i--) {
		printf("%p is %p years old.\n",
				names + i, ages + i);
	}
}

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

	// set up the pointers to the start of the arrays
	int *cur_age = ages;
	char **cur_name = names;

	// first way using indexing
	first_function(count, cur_age, cur_name);

	printf("---\n"); 

	// second way using pointers
	second_function(count, cur_age, cur_name);

	printf("---\n");

	// third way, pointers are just arrays
	third_function(count, cur_age, cur_name);

	printf("---\n");

	// fourth way with pointers in a stupid complex way
	fourth_function(count, cur_age, cur_name);

	printf("---\n");

	print_adresses(count, cur_age, cur_name);

	return 0;
}
