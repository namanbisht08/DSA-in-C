//Recursive function to print frequency a perticular elements present in a list.

#include<stdio.h>
#include<malloc.h>

typedef struct _Node
{
 int val;
 struct _Node* next;
}Node;

Node* makeNode(int);
int frequency(Node*,int);

main()
{
 Node *start='\0', *last='\0', *nd='\0';
 int n,m;

 printf("\n\n");
 while(1)
 {
  printf("Enter a Number [0 to stop]         : ");
  scanf("%d",&n);

  if (n==0) break;

  nd=makeNode(n);

  if(start=='\0')
   start=nd;
  else
   last->next=nd;
  last=nd;
 }
 printf("\nEnter a no. whose frequency you want to find : ");
 scanf("%d",&n);
 m=frequency(start,n);
 printf("\nFrequency of %d is %d ",n,m);
 printf("\n\n");
}

Node* makeNode(int n)
{
 Node * nd;
 nd=malloc(sizeof(Node));
 nd-> val=n;
 nd-> next='\0';
 return nd;
}

int frequency(Node* start,int n)
{
 int f;
 if(start=='\0')
  return 0;
 f=frequency(start->next,n);
 if(start->val==n) f++;
 return f;
}