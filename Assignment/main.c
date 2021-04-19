#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
	{
	    char Student_name[100];
	    int Student_ID;
	    int date[3];                        //in the format dd/mm/yy
	    int Student_score_of_last_year;
	};
typedef struct student student;     //for convenience

student create_student(char name[], int ID, int day, int month, int year, int score)
{
	// a function to define a student.
	student result;
	strcpy(result.Student_name, name);
	result.Student_ID = ID;
	result.date[0] = day;
	result.date[1] = month;
	result.date[2] = year;
	result.Student_score_of_last_year = score;
	return result;
}

struct NodeOfLinkedList
{
	student studentD;    //a struct that represent the data of the student in the node
	struct NodeOfLinkedList* next;  //a pointer to the next node in the list
};
typedef struct NodeOfLinkedList node;    //for convenience

node* createnode(student studen1)   //a function to create a node of a linked list
{
	node* result = malloc(sizeof(node)); //allocating a node in the heap 
	result->studentD = studen1;
	result->next = NULL;
	return result;
}



int main()
{
    printf("Hello world!\n");
    return 0;
}
