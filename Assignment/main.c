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
    int n=3;
student* x=create_array(n);
strcpy(x[0].Student_name,"BIBO");

x[0].Student_ID=1;
x[0].date[0]=11;
x[0].date[1]=9;
x[0].date[2]=2000;
x[0].Student_score_of_last_year=100;

strcpy(x[1].Student_name,"Ahmed");
x[1].Student_ID=2;
x[1].date[0]=3;
x[1].date[1]=4;
x[1].date[2]=2002;
x[1].Student_score_of_last_year=200;

strcpy(x[2].Student_name,"Mohamed");
x[2].Student_ID=3;
x[2].date[0]=4;
x[2].date[1]=5;
x[2].date[2]=2005;
x[2].Student_score_of_last_year=300;
display(x,n);
printf("\n\n\n");
x=insert(x,&n,1);
display(x,n);
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
