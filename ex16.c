// including library for work with standart input output functional
#include <stdio.h>
// verify program assertion library
#include <assert.h>
// standart library definition
#include <stdlib.h>
// string operations
#include <string.h>

// define a structure
struct Person {
	// define a char pointer for name string
	char *name;
	// define age variable
	int age;
	// define height variable
	int height;
	// define weight variable
	int weight;
};

// define a function that create and returns pointer on instance of struct Person
struct Person *Person_create(char *name, int age, int height,
		int weight)
{	
	// allocation of memory for insctance of strauct Person and initializing pointer on addres of this allocation
	struct Person *who = malloc(sizeof(struct Person));
	// check for memory allocation
	assert(who != NULL);
	
	// initializing name field with name string via strdup
	who->name = strdup(name);
	// initializing age field with age
	who->age = age;
	// initializing height field with height
	who->height = height;
	// initializing weight field with weight
	who->weight = weight;
	
	// return pointer on created instance of struct Person
	return who;
}

// define function for deleting struct Person from memory
void Person_destroy(struct Person *who)
{
	// check for valide pointer argument
	assert(who != NULL);
	
	// clearing memory of name field
	free(who->name);
	// clearing memory of whole struct
	free(who);
}

// define function for printing information about struct Person instance
void Person_print(struct Person *who)
{
	// print name field
	printf("name: %s\n", who->name);
	// print age field
	printf("\tAge: %d\n", who->age);
	// print height field
	printf("\tHeight: %d\n", who->height);
	// print weight field
	printf("\tWeight: %d\n", who->weight);
}

// define main function
int main(int argc, char *argv[])
{
	// make two people structures
	struct Person *joe = Person_create("Joe Alex", 32, 64, 140);
	
	struct Person *frank = Person_create("Frank Blank", 20, 72, 180);

	// print them out and where they are in memory
	printf("Joe is at memory location %p:\n", joe);
	Person_print(joe);

	printf("Frank is at memory location %p:\n", frank);
	Person_print(frank);

	// make everyone age 20 years and print them again
	joe->age += 20;
	joe->height -= 2;
	joe->weight += 40;
	Person_print(joe);

	frank->age += 20;
	frank->weight += 20;
	Person_print(frank);

	// destroy them both so we clean up
	Person_destroy(joe);
	Person_destroy(frank);

	return 0;
}
