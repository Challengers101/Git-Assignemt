#include <stdio.h>
#include <stdlib.h>

struct student
	{
	    char Student_name[100];
	    int Student_ID;
	    int date[3];                        //in the format dd/mm/yy
	    int Student_score_of_last_year;
	};
typedef struct student student;     //for convenience

int main()
{
    printf("Hello world!\n");
    return 0;
}
