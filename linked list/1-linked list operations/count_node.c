//function to count the no. of node present and return that number.

#include<stdio.h>
#include<malloc.h>

typedef struct _Node
{
 int val;
 struct _Node* next;
}Node;

Node* makeNode(int);
int count(Node*);

main()
{
 int n,m;
 Node* start='\0', *nd='\0', *last='\0';
 printf("\n\n");
 while(1)
 {
  printf("Enter a Number to store in list [ 0 to stop] :  ");
  scanf("%d",&n);
  if(n==0) break;
  nd=makeNode(n);
  if(start=='\0')
    start=nd;
  else
    last->next=nd;
  last=nd;
 }

 m=count(start);
 printf("\n");
 printf("Number of Nodes : %d",m);
}

Node* makeNode(int n)
{
 Node* nd=(Node*)malloc(sizeof(Node));
 nd->val=n;
 nd->next='\0';
return nd;
}

int count(Node* ptr)
{
 int g=0;
 while(ptr)
 {
  g++;
  ptr=ptr->next;
 }
return g;
}
