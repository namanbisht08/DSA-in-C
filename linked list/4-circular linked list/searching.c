// function to search in circular linked list..

#include<stdio.h>
#include<malloc.h>

typedef struct _Node
{
 int val ;
 struct _Node *next;
}Node;

Node* makeNode(int);
Node* locate(Node*,int);
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
 printf("Enter the value to find in list : ");
 scanf("%d",&n);
 printf("\n");
 Node* nd=locate(last,n);
 if(nd)
  printf("Item [%d] found at : [%d]",n,nd);
 else
   printf("\nItem not found in list");
}

Node* makeNode(int n)
{
 Node*nd=(Node*)malloc(sizeof(Node));
 nd->val=n;
 nd->next='\0';
}

Node* locate(Node*last,int n)
{Node* ptr;
 if(last=='\0') return last;
 for(ptr=last->next; ptr!=last && ptr->val!=n; ptr=ptr->next);
 if(ptr->val==n)
  return ptr;
 else
  return '\0';
 

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
