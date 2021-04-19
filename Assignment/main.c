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

node* insertathead(node** head, node* tobeinseted) 
{
	/*a function that adds a node at the head
	of the linked list then returns the new head*/

	tobeinseted->next = *head;
	*head = tobeinseted;
	return tobeinseted;
}

void insertattail(node* head, node* tobeinserted)
{
	/*a function that adds a node at the tail
	of the linked*/

	tobeinserted->next = NULL;
	node* temp;
	temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = tobeinserted;
}

void insertatmiddle(node* head, node* tobeinserted)
{
	/*a function that adds a node at the middle
	of the linked*/

	int n = 0;
	node* temp = head;
	while (temp != NULL)
	{
		n++;
		temp = temp->next;
	}
	int mid = (n-1) / 2;
	temp = head;
	for (int i = 0; i < mid; i++)
	{
		temp = temp->next;
	}
	tobeinserted->next = temp->next;
	temp->next = tobeinserted;
}

void visualizelinkedlist(node* head)
{
	/*
	this a function that visualizes the linked list 
	to help us better understand the code.
	*/
	node* temp = head;
	while (temp != NULL)
	{
		printf("name:%s  Student_ID:%d  date of birth:%d/%d/%d  Student_score_of_last_year:%d\n\t\t\t\t%c\n",
			temp->studentD.Student_name, 
			temp->studentD.Student_ID,
			temp->studentD.date[0],
			temp->studentD.date[1],
			temp->studentD.date[2],
			temp->studentD.Student_score_of_last_year,
			25);
		temp = temp->next;
	}
	printf("\t\t\t       NULL\n\n");
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
