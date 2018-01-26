#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int i;
int tockenizer(char c[] )
{
   char str[] = "READX";
  char *point = strtok(c , " ");
  while(point)
  {
  if(strcmp(point , str)==0)
   {
   	 point = strtok(NULL, " ");
   	 i = atoi(point);
   	 return i;
   	 break;	
   }
   
   point = strtok(NULL, " ");
  }
  //point = strtok(NULL, " ");
  // i = atoi(point);
  
 // return i;
  return 0;
  
}

/*int main()
{
  int j;
  char c[255];
  fgets(c ,255,stdin);
  //strcpy(s , c);
   j = tockenizer(c);
  printf("%d\n" , j);
   
}*/

