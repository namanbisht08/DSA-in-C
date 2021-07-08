//funtion to determine the smallest item present the node.

#include<stdio.h>
#include<malloc.h>

typedef struct _Node
{
 int val;
 struct _Node* next;
}Node;

Node* makeNode(int);
Node* getMin(Node*);

main()
{
 Node *start='\0', *last='\0', *nd='\0';
 int n;

 printf("\n\n");
 while(1)
 {
  printf("Enter a Number [0 to stop] : ");
  scanf("%d",&n);

  if (n==0) break;

  nd=makeNode(n);

  if(start=='\0')
   start=nd;
  else
   last->next=nd;
  last=nd;
 }
 nd=getMin(start);
 printf("\nSmallest Item in the list  : %d", nd->val);

}

Node* makeNode(int n)
{
 Node * nd;
 nd=malloc(sizeof(Node));
 nd-> val=n;
 nd-> next='\0';
 return nd;
}

Node* getMin(Node* ptr)
{
 Node*min=ptr;
 while(ptr)
 {
  if(ptr->val<min->val) ptr=min;
  ptr=ptr->next;
 }
 return min;
}

