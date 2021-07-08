//Recursive function to print elements of list in reverse order.

#include<stdio.h>
#include<malloc.h>

typedef struct _Node
{
 int val;
 struct _Node* next;
}Node;

Node* makeNode(int);
void printRev(Node*);

main()
{
 Node *start='\0', *last='\0', *nd='\0';
 int n;

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

 printf("\nItems in the list in reverse order : ");
 printRev(start);
}

Node* makeNode(int n)
{
 Node * nd;
 nd=malloc(sizeof(Node));
 nd-> val=n;
 nd-> next='\0';
 return nd;
}

void printRev(Node* start)
{
 if(start=='\0') return;
 // printf("%d ",start->val);
 printRev(start->next);
  printf("%d ",start->val);
}
