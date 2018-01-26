#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char str[255];
char st2[255] = " enter right request";
 char str1[] = "READX";
   char str2[] =    "WRITEX";
char * tocken2(char c[] )
{
  // char str1[] = "READX";
  // char str2[] =    "WRITEX";
  //int i =0;
  char *point = strtok(c , " ");
  while(point)
  {
  if(strcmp(point , str1)==0 )
{
	strcpy(str,point);
       //return str;
       //break;
   }
   else if(strcmp(point ,str2)==0)
  { 
  strcpy(str ,point);
 // return str;
  //break;
  
  }
 point = strtok(NULL , " ");
  }
	if(strcmp(str,"")==0)
	return st2;
	else 
	return str;
}

/*int main()
{
  int j;
  char c[255] = "nikhil hjsdh WRIT 56 jujjfjhduj";
 char str[255];
  //fgets(c ,255,stdin);
  //strcpy(s , c);
   strcpy(str , tockenizer(c));
  printf("%s\
  
  
  
  */
