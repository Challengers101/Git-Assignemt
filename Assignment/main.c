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

int main()
{
    printf("Hello world!\n");
    return 0;
}
