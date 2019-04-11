#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <emscripten.h>
int ns=0;
typedef struct
 { 
  	int* rollno;
	int *tot;
  	char* name;
 	char* grade;
  	//int mark[20][3];
  	int* per;
}stu;

  stu *s = (stu*)calloc(20, sizeof(stu));
//int* ns = (int*)calloc(1, sizeof(int));
//*ns=0;

extern "C" EMSCRIPTEN_KEEPALIVE int valid(char* p,char* u)
        {
            return strcmp(p,u);
        }


extern "C" EMSCRIPTEN_KEEPALIVE stu* add(int* rno,char* name,int m1,int m2,int m3)
{

		//char * c;
		
		s[ns].rollno = (int*)calloc(1, sizeof(int));
 		s[ns].rollno=rno;
		s[ns].name = (char*)calloc(1, sizeof(char)*(strlen(name)+1));
		strcpy(s[ns].name,name);
		s[ns].tot = (int*)calloc(1, sizeof(int));		
		*s[ns].tot = m1+m2+m3; 
		s[ns].per = (int*)calloc(1, sizeof(int));
		*s[ns].per=*s[ns].tot/3;
		s[ns].grade = (char*)calloc(1, sizeof(char)*(3));
		if(*s[ns].per<=100 && *s[ns].per>90)
		{
			//c="S";
			strcpy(s[ns].grade,"S");
		}
		else if(*s[ns].per<90 && *s[ns].per>80)
		{
			//c="A";
			strcpy(s[ns].grade,"A");			
		}
		else  if(*s[ns].per<=80 && *s[ns].per>70)
		{
			//c="B";
			strcpy(s[ns].grade,"B");
		}
		else if(*s[ns].per<=70 && *s[ns].per>60)
		{
			//c="C";
			strcpy(s[ns].grade,"C");
		}
		else if(*s[ns].per<=60 && *s[ns].per>=50)
		{
			//c="D";
			strcpy(s[ns].grade,"D");	
		}
		else
		{
			//c='F';
			strcpy(s[ns].grade,"F");
		}		
	
	ns=ns+1;
	return s;
	//return s[ns-1].rollno;
   }
 extern "C" EMSCRIPTEN_KEEPALIVE char* view(stu* s,int* r)
   {
	int idx=20,i;
	for(i=0;i<20;i++)
	{
	   if(r==s[i].rollno)
	  {
	     idx=i;  
	  }
	}
	return s[idx].name;
   }
