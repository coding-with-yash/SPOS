#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
int main()
{
	int i,id=0,num=0,op=0;
	char s[30];
	printf("Enter equation: ");
	fflush(stdout);
	scanf("%s",s);
	for(i=0;s[i]!='\0';i++)
	{
		char ch=s[i];
		if(isalpha(ch))
		{
			printf("%c is an identifier.\n",ch);
			id++;
		}
		else if(isdigit(ch))
		{
			printf("%c is a number.\n",ch);
			num++;
		}
		else
		{
			printf("%c is an operator.\n",ch);
			op++;
		}
	}
	printf("Total identifiers: %d \n",id);
	printf("Total Numbers: %d \n",num);
	printf("Total Operators: %d \n",op);
	printf("Total Tokens: %d \n",(id+num+op));
}
