// function to delete any perticular node(taking care of last)..

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
Node*rmvNode(Node*, Node**, int);

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
 printf("Enter a postion from where you want to delete the node :");
 scanf("%d",&n);
 start=rmvNode(start, &last, n);
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

Node* rmvNode(Node*start, Node**p2last, int pos)
{
 Node*ptr,*prev='\0';
 for(ptr=start; ptr && pos>1; prev=ptr, ptr=ptr->next,pos--);
 if(ptr)
  {
    if(ptr==start)
     {
       start=start->next;
       if(start=='\0') *p2last='\0';
     }
     else
      {
        prev->next=ptr->next;
        if(ptr==*p2last) *p2last=prev;
      }
  free(ptr);
  }
 return start;
} 
