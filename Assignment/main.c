/*
محمود هشام فتحى عبدالباقى           sec:4     BN:6
محمود عبدالباسط محمد حسين على       sec:4     BN:2
محمود حسن شحاتة حسن                  sec:3     BN:53
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct student
{
	char Student_name[50];
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

void insertinlinkedlist(node** head, node* tobeinserted, char name[], int n)
{
	/*a function that adds a node at the head, tai, or head*/

	if (*head == NULL) //just incase the head pointer is NULL
	{
		*head = tobeinserted;
		return;
	}
	else
	{
		if (strcmp(name, "head") == 0)
		{
			tobeinserted->next = *head;
			*head = tobeinserted;
		}
		else if (strcmp(name, "tail") == 0)
		{
			tobeinserted->next = NULL;
			node* temp = *head;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = tobeinserted;
		}
		else if (strcmp(name, "mid") == 0)
		{
			node* temp = *head;
			int mid = (n - 1) / 2;
			temp = *head;
			for (int i = 0; i < mid; i++)
			{
				temp = temp->next;
			}
			tobeinserted->next = temp->next;
			temp->next = tobeinserted;
		}
	}
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
			temp->studentD.date[1],
			temp->studentD.date[0],
			temp->studentD.date[2],
			temp->studentD.Student_score_of_last_year,
			25);
		temp = temp->next;
	}
	printf("\t\t\t       NULL\n\n");
}

node* createlinkedlist()
{
	/*
	this function creates a linked list
	and takes the input from the user directly
	*/
	int n; //number of students
	student s;
	char name[50];
	int ID, day, month, year, score;
	node* head = NULL; //the head of the linked list
	node* temp; //a temporary pointer to a node
	printf("please enter the number of students that you want to store: ");
	scanf("%d", &n);
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		printf("please enter the name of student number %d\n", i+1);
		scanf("%s", name);
		printf("please enter the id of student number %d\n", i+1);
		scanf("%d", &ID);
		printf("please enter the day of birth of student number %d\n", i+1);
		scanf("%d", &day);
		printf("please enter the month of birth of student number %d\n", i+1);
		scanf("%d", &month);
		printf("please enter the year of birth of student number %d\n", i+1);
		scanf("%d", &year);
		printf("please enter the score of the previous year of student number %d\n", i+1);
		scanf("%d", &score);
		s = create_student(name, ID, day, month, year, score);
		temp = createnode(s);
		insertinlinkedlist(&head, temp, "head", n);
	}
	printf("\n\n\n");
	return head;
}

student* init_dynamic_array(int n)
{
    /* this function initializes the dynamic array*/
    return (student*)calloc(n,sizeof(student));
}

student* insert_in__dynamic_array(student* s, int* n, int p, student  student_to_be_inserted)
{   
    /* this function inserts a new student at position p*/
	student x;
    s=(student*)realloc(s,sizeof(student)*(*n+1));
    for(int i=*n-1;i>=p-1;i--)
    {
        x=s[i];
        s[i]=s[i+1];
        s[i+1]=x;
    }

	s[p-1] = student_to_be_inserted;
    *n=*n+1;
    return s;
}

void display_dynamic_array(student* s, int n)
{
	/*
	this a function that visualizes the array
	to help us better understand the code.
	*/
	
	for(int i=0; i<n; i++)
	{
		printf("name:%s  Student_ID:%d  date of birth:%d/%d/%d  Student_score_of_last_year:%d\n\t\t\t\t%c\n",
			s[i].Student_name,
			s[i].Student_ID,
			s[i].date[0],
			s[i].date[1],
			s[i].date[2],
			s[i].Student_score_of_last_year,
			25);
	}
	printf("\t\t\t       END\n\n");
}

student* create_dynamic_array(int *n)
{
    /*
	this function creates a dynamic array
	and takes the input from the user directly
	*/
	student* s;
	char name[50];
	int ID, day, month, year, score;
	printf("please enter the number of students that you want to store: ");
	scanf("%d", n);
	printf("\n");
	s=init_dynamic_array(*n);
	for (int i = 0; i < *n; i++)
	{
		printf("please enter the name of student number %d\n", i+1);
		scanf("%s", name);
		printf("please enter the id of student number %d\n", i+1);
		scanf("%d", &ID);
		printf("please enter the day of birth of student number %d\n", i+1);
		scanf("%d", &day);
		printf("please enter the month of birth of student number %d\n", i+1);
		scanf("%d", &month);
		printf("please enter the year of birth of student number %d\n", i+1);
		scanf("%d", &year);
		printf("please enter the score of the previous year of student number %d\n", i+1);
		scanf("%d", &score);
		s[i] = create_student(name, ID, day, month, year, score);
	}
	printf("\n\n\n");
	return s;
}

int main()
{
	student s1 = create_student("Mahmoud", 406, 23, 7, 2000, 84);
    
    /*int n;
    student* s = create_dynamic_array(&n);
    display_dynamic_array(s,n);*/
    
	/*int n = 1;
	student* s = init_dynamic_array(n);
	s[0] = s1;
	for (int i=0; i<9; i++)
	{
		s = insert_in__dynamic_array(s, &n, n+1, s1);
	}*/
	//display_dynamic_array(s, n);

	/*s = insert_in__dynamic_array(s, &n, 1, create_student("in", 406, 23, 7, 2000, 84)); //insert at the start
	display_dynamic_array(s, n);*/
	
	/*s = insert_in__dynamic_array(s, &n, n+1, create_student("in", 406, 23, 7, 2000, 84)); //insert at the end
	display_dynamic_array(s, n);*/
	
	/*s = insert_in__dynamic_array(s, &n, (n+2)/2, create_student("in", 406, 23, 7, 2000, 84)); //insert at the mid
	display_dynamic_array(s, n);*/
	
	/*int start = clock();
	s = insert_in__dynamic_array(s, &n, 1, create_student("in", 406, 23, 7, 2000, 84));
	int stop = clock();
	printf("\ntime to insert at start is %f\n\n", ((double)(stop-start)/CLOCKS_PER_SEC));
	
		start = clock();
	s = insert_in__dynamic_array(s, &n, (n+2)/2, create_student("in", 406, 23, 7, 2000, 84));
	stop = clock();
	printf("\ntime to insert at middle is %f\n\n", ((double)(stop-start)/CLOCKS_PER_SEC));
	
	start = clock();
	s = insert_in__dynamic_array(s, &n, n+1, create_student("in", 406, 23, 7, 2000, 84));
	stop = clock();
	printf("\ntime to insert at end is %f\n\n", ((double)(stop-start)/CLOCKS_PER_SEC));*/
	
	/*node *head = createlinkedlist();
    visualizelinkedlist(head);*/
    
    /*int N = 10;
    node* head = createnode(s1);
	for (int i=0; i<N-1; i++)
	{
		insertinlinkedlist(&head, createnode(s1), "head", N);
	}*/
	//visualizelinkedlist(head);

	/*insertinlinkedlist(&head, createnode(create_student("in", 406, 23, 7, 2000, 84)), "head",N);
	visualizelinkedlist(head);*/
	
	/*insertinlinkedlist(&head, createnode(create_student("in", 406, 23, 7, 2000, 84)), "mid",N);
	visualizelinkedlist(head);*/

    /*insertinlinkedlist(&head, createnode(create_student("in", 406, 23, 7, 2000, 84)), "tail",N);
	visualizelinkedlist(head);*/
	
    /*int start = clock();
	insertinlinkedlist(&head, createnode(create_student("in", 406, 23, 7, 2000, 84)), "head",N);
	int stop = clock();
	printf("\n\ntime to insert at start is %f\n\n", ((double)(stop-start)/CLOCKS_PER_SEC));
	
	start = clock();
	insertinlinkedlist(&head, createnode(create_student("in", 406, 23, 7, 2000, 84)), "mid",N);
	stop = clock();
	printf("\n\ntime to insert at middle is %f\n\n", ((double)(stop-start)/CLOCKS_PER_SEC));
	
	start = clock();
	insertinlinkedlist(&head, createnode(create_student("in", 406, 23, 7, 2000, 84)), "tail",N);
	stop = clock();
	printf("\n\ntime to insert at end is %f\n\n", ((double)(stop-start)/CLOCKS_PER_SEC));*/
    
    /*printf("\n\nthe size of the structure is %d\n\n", sizeof(student));
    printf("\n\nthe size of the node is %d\n\n", sizeof(node));*/
    
    return 0;
}
