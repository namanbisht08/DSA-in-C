//funtion to append node into linked list.

#include<stdio.h>
#include<malloc.h>

typedef struct _Node
{
 struct _Node* next;
 int val;
}Node;

Node* makeNode(int);
Node* append(Node*,Node**,int);
void  print(Node*);

main()
{
 int n;
 Node *start='\0', *last='\0';
 printf("\n");
 while(1)
 {
  printf("Enter a Number [0 to stop] : ");
  scanf("%d",&n);
  if(n==0) break;
  
  start=append(start, &last, n);
 }
 print(start);
}

Node* makeNode(int n)
{
 Node* nd=(Node*) malloc(sizeof(Node));
 nd->val=n;
 nd->next='\0';
 return nd;
}

Node* append(Node* start, Node**p2last, int n)
{
 Node* nd=makeNode(n);
 if(start=='\0')
  start=nd;
 else
  (*p2last)->next=nd;  //2 operators *and-> and precedence of ->[lv 2] is higher than *[lv 3] so we had used brakets.
 
 *p2last=nd;
 return start;
}

void print(Node* ptr)
{
 while(ptr)
 {
  printf("%d ",ptr->val);
  ptr=ptr->next;
 }
}
