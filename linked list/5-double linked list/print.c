// function to print doublely linked list..

#include<stdio.h>
#include<malloc.h>

typedef struct _Node
{
 int val ;
 struct _Node *next,*prev;
}Node;

Node* makeNode(int);
Node *print(Node*);

main()
{
 int n;
 Node *last='\0',*nd;

 printf("\n\n");
 while(1)
 {
  printf("Enter a number to store in list [0 to stop] : ");
  scanf("%d",&n);
  if(n==0) break;
  nd=makeNode(n);
  if(start=='\0')
    start=nd;
  else
    last->next=nd;
  last=nd;
 }
Node* makeNode(int n)
{
 Node*nd=(Node*)malloc(sizeof(Node));
 nd->val=n;
 nd->next=nd->prev='\0';
}


}

Node* print(Node* ptr)
{
 while(ptr)
{
 printf(" %d ",ptr->val);
 ptr=ptr->val;
}
}
