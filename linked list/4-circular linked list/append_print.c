// function to append then print circular linked list..

#include<stdio.h>
#include<malloc.h>

typedef struct _Node
{
 int val ;
 struct _Node *next;
}Node;

Node* makeNode(int);
void print(Node*);
Node *append(Node*, int);

main()
{
 int n;
 Node *last='\0';

 printf("\n\n");
 while(1)
 {
  printf("Enter a number [0  to stop] : ");
  scanf("%d",&n);
  if(n==0) break;
  last=append(last,n);
 }

 printf("\n");
 print(last);
}

Node* makeNode(int n)
{
 Node*nd=(Node*)malloc(sizeof(Node));
 nd->val=n;
 nd->next='\0';
}

void print(Node*last)
{Node* ptr=last;
 if(last=='\0') return;
 printf("Item(s) in Circular Linked List :\n\n");
 do
 {
  ptr=ptr->next;
  printf("[%d] ",ptr->val);
 }
 while(ptr!=last);

}

Node* append(Node* last, int n)
{
 Node* nd= makeNode(n);
 if(last=='\0')
   last=nd;
 else
    nd->next=last->next;
 last->next=nd;
 return nd;
}
