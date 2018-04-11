%{
	#include<stdio.h>
	#include<stdlib.h>

%}

%token name num
%left GE LE NE EQ '<' '>' '%'
%left '-' '+'
%left '*' '/'
%nonassoc UMINUS

%%
	statement:name'='exp|exp{printf("=%d\n",$1);};
	exp:num{$$=$1;}
	|exp'+'exp{$$=$1+$3;}
	|exp'-'exp{$$=$1-$3;}
	|exp'*'exp{$$=$1*$3;}
	|exp'/'exp{$$=$1/$3;}
	|exp'<'exp{$$=$1<$3;}
	|exp'>'exp{$$=$1>$3;}
	|exp'%'exp{$$=$1%$3;}
	|exp GE exp{$$=($1>=$3);}
	|exp LE exp{$$=($1<=$3);}
	|exp NE exp{$$=($1!=$3);}
	|exp EQ exp{$$=($1==$3);}
	|'-' exp %prec UMINUS{$$=-$2;}
	|'('exp')' {$$=$2;};
%%

int main()
{
 yyparse();
}

int yyerror()
{
}

int yywrap()
{
 return 1;
}



/*

OUTPUT



pranshul@pranshul:~$ yacc -d cal.y
pranshul@pranshul:~$ lex cal.l
pranshul@pranshul:~$ cc -o cal y.tab.c lex.yy.c
pranshul@pranshul:~$ ./cal
((9*2)+7)/5
=5

*/
