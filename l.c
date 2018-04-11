//Lexical analyser
#include<stdio.h>
#include<string.h>

typedef struct
{
	char data[80];
}table;

struct uniform_st
{
char data[80];
char type[5];
int index;
}ust[100];

int temp,id=0,l=0,t=0,k=0,u=0;
char buffer[180],tok1[20],tok2[20],tok3[20],tok4[20],tok5[20],tok6[20];
char tok7[20],tok8[20],tok9[20],tok10[20],tok11[20],tok12[20],tok13[20],tok14[20];
char fname[20];
table ident[20],keyw[20],term[20],lit[20];
table sampleter[20],samplekeyw[20];

void disp(table s[20],int n)
{
int i;
for(i=0;i<n;i++)
	printf("\n\t%s",s[i].data);
}

void disp_ust()
{
int i;
for(i=0;i<u;i++)
{
		printf("\n%s \t\t%s \t%d",ust[i].data,ust[i].type,ust[i].index);
	}
}

int search_ident(char str[20],int n)
{
int i;
for(i=0;i<n;i++)
	if(strcmp(ident[i].data,str)==0)
		return i;
return -1;
}

int search_keyw(char str[20],int n)
{
	int i;
	for(i=0;i<n;i++)
		if(strcmp(keyw[i].data,str)==0)
			return i;
	return -1;
}

int search_term(char str[20],int n)
{
int i;
for(i=0;i<n;i++)
	if(strcmp(term[i].data,str)==0)
		return i;
return -1;
}

int search_lit(char str[20],int n)
{
int i;
for(i=0;i<n;i++)
	if(strcmp(lit[i].data,str)==0)
		return 1;
return -1;
}

int isliteral(char str[20])
{
if((isdigit(str[0])!=0)||(isdigit(str[1])!=0))
	return 1;
return 0;
}

int isterminal(char str[20])
{
int i;
for(i=0;i<15;i++)
if(strcmp(sampleter[i].data,str)==0)
	return 1;
return 0;
}

int iskeyword(char str[20])
{
int i;
for(i=0;i<6;i++)
if(strcmp(samplekeyw[i].data,str)==0)
	return 1;
return 0;
}

void check(char str[20])
{
	if(iskeyword(str)==1)
	{
		temp=search_keyw(str,k);
		strcpy(ust[u].data,str);
		strcpy(ust[u].type,"KEY");
		ust[u].index=temp;
		u++;
		
		if(temp==-1)
		{
			strcpy(keyw[k].data,str);
			u--;
			ust[u].index=k;
			u++;
			k++;
		}
	} 
	else
	{
		if(isterminal(str)==1)
		{
			temp=search_term(str,t);
strcpy(ust[u].data,str);
strcpy(ust[u].type,"TRM");
ust[u].index=temp;
u++;

if(temp==-1)
			{
strcpy(term[t].data,str);
u--;
ust[u].index=t;
u++;
t++;
			}
		} 
		else
		{
			if(isliteral(str)==1)
			{
				temp=search_lit(str,l);
strcpy(ust[u].data,str);
strcpy(ust[u].type,"LIT");
ust[u].index=temp;
u++;

if(temp==-1)
{
strcpy(lit[l].data,str);
u--;
ust[u].index=l;
u++;
l++;
}
			} 
			else
{
//identifiers
temp=search_ident(str,id);
strcpy(ust[u].data,str);
strcpy(ust[u].type,"IDN");
ust[u].index=temp;
u++;

if(temp==-1)
			{
					strcpy(ident[id].data,str);
u--;
ust[u].index=id;
u++;
id++;
}
			}
		}
	}
}

void main()
{
FILE *fs;

//initialise
//keywords
strcpy(samplekeyw[0].data,"int");
strcpy(samplekeyw[1].data,"void");
strcpy(samplekeyw[2].data,"char");
strcpy(samplekeyw[3].data,"float");
strcpy(samplekeyw[4].data,"if");
strcpy(samplekeyw[5].data,"for");

//terminal
strcpy(sampleter[0].data,"+");
strcpy(sampleter[1].data,"-");
strcpy(sampleter[2].data,"*");
strcpy(sampleter[3].data,"/");
strcpy(sampleter[4].data,"=");
strcpy(sampleter[5].data,"++");
strcpy(sampleter[6].data,"{");
strcpy(sampleter[7].data,"}");
strcpy(sampleter[8].data,"(");
strcpy(sampleter[9].data,")");
strcpy(sampleter[10].data,";");
strcpy(sampleter[11].data,"<");
strcpy(sampleter[12].data,">");
strcpy(sampleter[13].data,",");
strcpy(sampleter[14].data,"&");

printf("\n\t ** LEXICAL ANALYSER **\n");
printf("\n Enter the Source File Name : ");
	scanf("%s",&fname);
	fs=fopen(fname,"r");
if(fs==NULL)
{
printf("\n Error in Openning File \n");
exit(0);
}

while(fgets(buffer,180,fs))
{
//init tokens
strcpy(tok1,"");
strcpy(tok2,"");
strcpy(tok3,"");
strcpy(tok4,"");
strcpy(tok5,"");
strcpy(tok6,"");
strcpy(tok7,"");
strcpy(tok8,"");
strcpy(tok9,"");
strcpy(tok10,"");
strcpy(tok11,"");
strcpy(tok12,"");
strcpy(tok13,"");
strcpy(tok14,"");

sscanf(buffer,"%s%s%s%s%s%s%s%s%s%s%s%s%s%s",tok1,tok2,tok3,tok4,tok5,tok6,tok7,tok8,tok9,tok10,tok11,tok12,tok13,tok14);

printf("\n%s%s%s%s%s%s%s%s%s%s%s%s%s%s",tok1,tok2,tok3,tok4,tok5,tok6,tok7,tok8,tok9,tok10,tok11,tok12,tok13,tok14);

if(strcmp(tok1,"")!=0)
check(tok1);
if(strcmp(tok2,"")!=0)
	check(tok2);
if(strcmp(tok3,"")!=0)
	check(tok3);
if(strcmp(tok4,"")!=0)
	check(tok4);
if(strcmp(tok5,"")!=0)
	check(tok5);
if(strcmp(tok6,"")!=0)
	check(tok6);
if(strcmp(tok7,"")!=0)
	check(tok7);
if(strcmp(tok8,"")!=0)
	check(tok8);
if(strcmp(tok9,"")!=0)
	check(tok9);
if(strcmp(tok10,"")!=0)
	check(tok10);
if(strcmp(tok11,"")!=0)
	check(tok11);
if(strcmp(tok12,"")!=0)
	check(tok12);
if(strcmp(tok13,"")!=0)
	check(tok13);
if(strcmp(tok14,"")!=0)
	check(tok14);
}//while

//display functions
printf("\n\n Keyword Table (KEW)\n");
disp(keyw,k);

printf("\n Terminal Table (TRM)\n");
disp(term,t);

printf("\n Literal Table (LIT)\n");
disp(lit,l);

printf("\n Identifier Table (IDN)\n");
disp(ident,id);

printf("\n\n Uniform Symbol Table (UST)\n");
disp_ust();
printf("\n");
}
