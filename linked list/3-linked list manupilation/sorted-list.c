// function to create sorted list..

#include<stdio.h>
#include<malloc.h>

typedef struct _Node
{
 int val ;
 struct _Node *next;
}Node;

Node* makeNode(int);
void print(Node*);
Node *insert(Node*, int);

main()
{
 int n;
 Node *start='\0';
 
 printf("\n\n");
 while(1)
 {
  printf("Enter a number [0  to stop] : ");
  scanf("%d",&n);
  if(n==0) break;
  start=insert(start,n);
 }
 
 printf("\n");
 print(start);
}

Node* makeNode(int n)
{
 Node*nd=(Node*)malloc(sizeof(Node));
 nd->val=n;
 nd->next='\0';
}

void print(Node*ptr)
{
 printf("\nItems in in List : ");
 while(ptr)
 {
  printf("[%d] ",ptr->val);
  ptr=ptr->next;
 }
 printf("\n");
}

Node* insert(Node* start, int n)
{
 Node* ptr , *prev, *nd;
 nd=makeNode(n);
 for(ptr=start; ptr && n>ptr->val; prev=ptr, ptr=ptr->next);

 nd->next=ptr;
 if(ptr==start)
  start=nd;
 else
  prev->next=nd;
  
return start;
}
