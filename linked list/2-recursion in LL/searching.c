//recursive function to searching for a perticular number and return its address.
//"undefined refference to a <function-name>" error occurs when the linker cannot find the defination of a linked object. 

#include<stdio.h>
#include<malloc.h>

typedef struct _Node
{
 int val;
 struct _Node* next;
}Node;

Node* makeNode(int);
Node* locate(Node*,int);

main()
{
 Node *start='\0', *last='\0', *nd='\0';
 int n;

 printf("\n\n");
 while(1)
 {
  printf("Enter a Number [0 to stop]             : ");
  scanf("%d",&n);

  if (n==0) break;

  nd=makeNode(n);

  if(start=='\0')
   start=nd;
  else
   last->next=nd;
  last=nd;
 }
 printf("\nEnter a number which you want to find : ");
 scanf("%d",&n);
 nd=locate(start,n);
 printf("\nEntered Number [%d] present at        : %d",n,nd);
}

Node* makeNode(int n)
{
 Node * nd;
 nd=malloc(sizeof(Node));
 nd-> val=n;
 nd-> next='\0';
 return nd;
}

Node* locate(Node *start,int n)
{
 if(start=='\0' || start->val==n) return start;
 return locate (start->next,n);
}
