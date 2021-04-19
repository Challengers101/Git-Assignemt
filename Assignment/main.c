#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student
	{
	    char Student_name[100];
	    int Student_ID;
	    int date[3];                        //in the format dd/mm/yy
	    int Student_score_of_last_year;
	};typedef struct student student;     //for convenience
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

student* create_array(int);
student* insert(student*,int*,int);
void display(student* s,int);
student* Read_Data(int*);

int main()
{
    int n;
student* s=Read_Data(&n);
display(s,n);
    return 0;
}
student* create_array(int n)
{
    return (student*)calloc(n,sizeof(student));
}
void display(student* s,int n)
{   for(int i=0;i<n;i++)
{
    printf("name=%s\nid=%d\ndate=%d\\%d\\%d\nscore=%d\n",s[i].Student_name,s[i].Student_ID,s[i].date[0],s[i].date[1],s[i].date[2],s[i].Student_score_of_last_year);
}
}
student* insert(student*s,int* n,int p)
{   student x;
    s=(student*)realloc(s,sizeof(student)*(*n+1));
    for(int i=*n-1;i>=p-1;i--)
    {
        x=s[i];
        s[i]=s[i+1];
        s[i+1]=x;
    }
    *n=*n+1;
    return s;
}
student* Read_Data(int *n)
{

	 //number of students
	student* s;
	char name[100];
	int ID, day, month, year, score;
	printf("please enter the number of students that you want to store:");
	scanf("%d", n);
	printf("\n");
	s=create_array(*n);
	for (int i = 0; i < *n; i++)
	{
		printf("please enter the name of student number %d\n", i+1);
		scanf("%s", name);
		printf("please enter the id of student number %d\n", i+1);
		scanf("%d", &ID);
		printf("please enter the day of birth of student number %d\n", i+1);
		scanf("%d", &day);
		printf("please enter the month of bith of student number %d\n", i+1);
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
