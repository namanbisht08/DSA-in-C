//function to print elements smaller than average of all the items present in the list and retrun back the no. of items being printed as per the condition.

#include<stdio.h>
#include<malloc.h>

typedef struct _Node
{
 int val;
 struct _Node* next;
}Node;

Node* makeNode(int);
int printSmaller(Node*);

main()
{
 Node *start='\0', *last='\0', *nd='\0';
 int n;

 printf("\n\n");
 while(1)
 {
  printf("Enter a Number [0 to stop]     : ");
  scanf("%d",&n);

  if (n==0) break;

  nd=makeNode(n);

  if(start=='\0')
   start=nd;
  else
   last->next=nd;
  last=nd;
 }
 n=printSmaller(start);
 printf("\nNumber of items less than average : %d",n);
}

Node* makeNode(int n)
{
 Node * nd;
 nd=malloc(sizeof(Node));
 nd-> val=n;
 nd-> next='\0';
 return nd;
}

int printSmaller(Node*start)
{
 Node*ptr;
 int avg,count;
 
 for(ptr=start,avg=count=0;ptr;count++)
 {
  avg=avg+ptr->val;
  ptr=ptr->next;
 }
 if(count) avg=avg/count;
 printf("\nItems smaller than average [%d]    : ",avg);

 for(ptr=start,count=0;ptr;ptr=ptr->next)
  {
   if(ptr->val<avg)
    {
     printf("%d ",ptr->val);
     count++;
    }
  }
 return count;
}

