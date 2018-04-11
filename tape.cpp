//============================================================================
// Name        : DAA_2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

float meanTime[10];
int length[10];
int processes, tapes;

void Input();
void Sort();
void Output();

int main()
{
	cout<<"\n\nTotal Number of Processes : ";
	cin>>processes;


	inputTapes:
	cout<<"\n\nEnter number of tapes : ";
	cin>>tapes;

	if((tapes > 10) || (tapes < 1))
	{
		cout<<"Number of tapes should be <= 10 and > 0";
		goto inputTapes;
	}

	Input();
	Sort();
	Output();

	return 0;
}

void Input()
{
    int i;
    for(i=0; i<processes; i++)
    {
		cout<<"Length of Process-"<<i+1<<" : ";
		cin>>length[i];
    }
}

void Sort()
{
    int i,j,temp;
    for(i=0; i<processes; i++)
    {
		for(j=1; j<(processes-i); j++)
		{
			if(length[j] < length[j-1])
			{
				temp = length[j];
				length[j] = length[j-1];
				length[j-1] = temp;
			}
		}
    }
}

void Output()
{
	float temp1, temp2;
	int k = 0, l = 0;
	float finalMean = 0.0;

	cout<<"\n";
	while(k < tapes)
	{
		l = 0;
		temp1 = temp2 = 0.0;

		cout<<"\nProcesses on Tape-"<<k+1<<" : ";

		for(int j=k; j<processes; j += tapes)
		{
			l++;
			temp1 += length[j];
			temp2 +=temp1;

			cout<<" P"<<j+1;
		}

		meanTime[k] = temp2/l;
		k++;
	}

	cout<<"\n";

	for(int i = 0; i < tapes; i++)
	{
		finalMean += meanTime[i];
		cout<<"\nMean Time for Tape "<<i+1<<" : "<< meanTime[i];
	}

	cout<<"\n\nTotal Mean Time : "<< finalMean/tapes;
}
