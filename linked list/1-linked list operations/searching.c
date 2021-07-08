//funtion to search for perticular item present in list and return the address of the node where it is found in the list.

#include<stdio.h>
#include<malloc.h>

typedef struct _Node
{
 int val;
 struct _Node* next;
}Node;

Node* makeNode(int);
Node* locate(Node*, int);

main()
{
 int n;
 Node *start='\0', *nd, *last='\0';
 printf("\n\n");
 while(1)
 {
  printf("Enter a number to store [0 to exit] : ");
  scanf("%d", &n);
  if (n==0) break;
  nd=makeNode(n);
  if(start=='\0')
   start=nd;
  else
   last->next=nd;
  last=nd;
 }
 printf("\n Enter a Number to find..\n");
 scanf("%d",&n);
 
 nd=locate(start,n);
 if(nd)
  printf("\n %d Found at : %d\n", nd->val,nd);
 else
  printf("\n Item not found... \n");
}

Node* makeNode(int n)
{
 Node* nd=(Node*)malloc(sizeof(Node));
 nd->val=n;
 nd->next='\0';
return nd;
}

Node* locate(Node* ptr,int n)
{
 while(ptr && ptr->val !=n)
  {ptr=ptr->next;}
return ptr;
}
