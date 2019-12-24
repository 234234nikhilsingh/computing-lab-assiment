#include <stdio.h>
#include <string.h>
#include<stdlib.h>
char line[256];
char c[] ="please enter lower number";
char *reading(int k)
	{

	static const char filename[] = "ab.txt"	;
	FILE *file = fopen(filename, "a+");
	int count = 0;
	if ( file != NULL )
	{
	   // char line[256]; /* or other suitable maximum line size */
	    while (fgets(line, sizeof line, file) != NULL) /* read a line */
	    {
	        if (count == k)
	        {
	          fclose(file);
	          return line;
	        }
	        else
	        {
	            count++;
	        }
	    }
	    fclose(file);
	}
	else
		{
	    printf("file not avaolable");
		}
		
	return c;
	}
	

//int main()
//{
  //char str[255];
  //strcpy(str,read(89));
  //printf("%s\n",str);
  
  
  
//}	
	
