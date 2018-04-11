#include<stdio.h>
#include<stdlib.h>
#define MAX 80
char Infix[MAX];

int InpPtr = 0;
void TPRIME(),F(),EPRIME(),E(),T();

void ERROR()
{
	printf("\n Invalid Expression...");
	exit(0);
}

int ISALPHA(char c)
{
	return(c>='a' && c<='z');
}

void TPRIME()
{
	if(Infix[InpPtr] == '*' || Infix[InpPtr] == '/')
	{
		InpPtr++;
		F();
		TPRIME();
	}
	 if(ISALPHA(Infix[InpPtr]))
		ERROR();
}

void F()
{
	if(Infix[InpPtr] == '(')
	{
		InpPtr++;
		E();
		if(Infix[InpPtr] == ')')
			InpPtr++;
		else
			ERROR();
	} 
	else if(ISALPHA(Infix[InpPtr]))
		InpPtr++;
	else
		ERROR();
}

void T()
{
	F();
	TPRIME();
}

void EPRIME()
{
	if(Infix[InpPtr] == '+' || Infix[InpPtr] == '-')
	{
		InpPtr++;
		T();
		EPRIME();
	}
	if(ISALPHA(Infix[InpPtr]))
		ERROR();
}

void E()
{
	T();
	EPRIME();
}

void main()
{
	printf("\nEnter Infix Expression...");
	scanf("%s",Infix);
	E();
	printf("\nValid Infix Expression...");
}
