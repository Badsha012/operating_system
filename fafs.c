#include<stdio.h>
#include<stdlib.h>
int main()
{
  int ReadyQueue[100],i,n,TotalHeadMov=0,initial;
  //Enter the number of requests
  printf("Enter number:");

  scanf("%d",&n);
  printf("Element is number:");
  for(i=0;i<n;i++){
    //Enter the sequence of request
  scanf("%d",&ReadyQueue[i]);
  }
  // Enter initial head position
  printf("Input initial:");
  scanf("%d",&initial);
  for(i=0;i<n;i++)
  {
    TotalHeadMov=TotalHeadMov+abs(ReadyQueue[i]-initial);
    initial=ReadyQueue[i];
  }
  printf("Total Head Movement=%d",TotalHeadMov);

    return 0;
}



