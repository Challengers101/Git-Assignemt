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
student* create_array(int);
student* insert(student*,int*,int);
void clear_array(student*);
void display(student* s,int);

int main()
{

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
