#include <stdio.h>
#include <stdlib.h>

struct student
	{
	    char Student_name[100];
	    int Student_ID;
	    int date[3];
	    int Student_score_of_last_year;
	};
typedef struct student student;

int main()
{
    printf("Hello world!\n");
    return 0;
}
