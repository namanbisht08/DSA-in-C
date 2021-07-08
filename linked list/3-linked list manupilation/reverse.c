// function to reverse whole list(ittretative method)..

#include<stdio.h>
#include<malloc.h>

typedef struct _Node
{
 int val ;
 struct _Node* next;
}Node;

Node* makeNode(int);
print(Node*);
Node* append(Node*, Node**, int);
Node*reverse(Node*, Node**);

main()
{
 int n;
 Node *start='\0', *last='\0', *nd='\0';
 printf("\n\n");
 while(1)
 {
  printf("Enter a number [0  to stop] :");
  scanf("%d",&n);
  if(n==0) break;
  start=append(start, &last, n);
 }
 printf("list after reverse :");
 start=reverse(start, &last);
 printf("\n");
 print(start);
}

Node* makeNode(int n)
{
 Node*nd=(Node*)malloc(sizeof(Node));
 nd->val=n;
 nd->next='\0';
}

Node* append(Node*start, Node**p2last, int n)
{
 Node* nd=makeNode(n);
 if(start=='\0')
   start=nd;
 else
   (*p2last)->next=nd;
 *p2last=nd;
 return start;
}

print(Node*ptr)
{
 printf("\nValues available in list :");
 printf("\n");
 while(ptr)
 {
  printf(" [%d] ",ptr->val);
  ptr=ptr->next;
 }
}

Node* reverse(Node*start, Node**p2last)
{
 Node*ptr=start, *temp, *prev='\0';
 while(ptr)
 {
   temp=ptr->next;
   ptr->next=prev;
   prev=ptr;
   ptr=temp;
 }
 *p2last=start;
 return prev;
}
