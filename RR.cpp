#include <iostream>
#include<iomanip>
#include<cstdlib>

using namespace std;

int main()

{

int process[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100};

int burstTime[100];

for (int i=0;i<100;i++)
	{
		burstTime[i] = rand() % 100;
	}

int arrivalTime[100];
for (int i=0;i<100;i++)
        {
                arrivalTime[i] = rand() % 100;
        }

int quantam;

cout<<"Enter time quantam: ";

cin>>quantam;

bool flag=true;

int waitingTime[100];
for (int i=0;i<100;i++)
        {
                waitingTime[i] = rand() % 100;
        }

int bTime[100];

for(int i=0;i<100;i++)

bTime[i]=burstTime[i];

while(flag)

{

for(int i=0;i<100;i++)

{

int executionTime=0;

if(bTime[i]>quantam)

{

bTime[i]-=quantam;

executionTime=quantam;

}

else

{

executionTime=bTime[i];

bTime[i]=0;

}

for(int j=0;j<100;j++)

{

if(i!=j && bTime[j]!=0)

{

waitingTime[j]+=executionTime;

}

}

}

flag=false;

for(int k=0;k<100;k++)

{

if(bTime[k]==0)

continue;

else

{

flag=true;

break;

}

}

}

float avgWaitingTime=0.0,avgTurnaroundTime=0.0;

cout<<"\nProcess ID"<<" "<<"BurstTime"<<" "<<"WaitingTime"<<" "<<"TurnaroundTime\n"<<endl;

for(int i=0;i<100;i++)

{

cout<<process[i]<<"\t\t"<<burstTime[i]<<"\t"<<waitingTime[i]<<"\t"<<waitingTime[i]+burstTime[i]<<endl;

avgWaitingTime+=waitingTime[i];

avgTurnaroundTime+=waitingTime[i]+burstTime[i];

}

cout<<"\nAverage waiting time: "<<avgWaitingTime/100;

cout<<"\nAverage turnaround time: "<<avgTurnaroundTime/100<<endl;

return 0;

}
