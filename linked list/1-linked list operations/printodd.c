//funtion to count and print the no. of odd digit present in list and return back the no. of odd digits. 

#include<stdio.h>
#include<malloc.h>

typedef struct _Node
{
 struct _Node* next;
 int val;
}Node;

Node* makeNode(int);
int printodd(Node*);

main()
{
 int n;
 Node *start='\0', *nd='\0', *last='\0';
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

 n=printodd(start);
 printf("\nNumber of odd digit(s) present in list      : %d\n",n);
}

Node* makeNode(int n)
{
 Node* nd=(Node*)malloc(sizeof(Node));
 nd->val=n;
 nd->next='\0';
 return nd;
}

int printodd(Node* ptr)
{
 int count=0;
 printf("\nOdd digit(s) are : ");
 while(ptr)
  {
   if(ptr->val%2!=0)
    {
     printf("%d ",ptr->val);
     count++;
    }
   ptr=ptr->next;
  }
  printf("\n");
 return count;
}
