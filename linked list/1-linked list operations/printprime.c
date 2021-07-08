//funtion to count and print the no. of prime numbers present in list and return back the no. of prime digits. 

#include<stdio.h>
#include<malloc.h>
#include<math.h>

typedef struct _Node
{
 struct _Node* next;
 int val;
}Node;

Node* makeNode(int);
int printPrime(Node*);

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

 n=printPrime(start);
 printf("\nPrime number(s) present in list : %d\n",n);
}

Node* makeNode(int n)
{
 Node* nd=(Node*)malloc(sizeof(Node));
 nd->val=n;
 nd->next='\0';
 return nd;
}

int printPrime(Node* ptr)
{
 int n=0,d,root;
 printf("\nPrime no(s) in the list : ");
 while(ptr)
 {
  for(d=2,root=sqrt(ptr->val); d<=root && ptr->val%d!=0; d++);
  if(d>root)
  {
   printf("%d ",ptr->val);
   n++;
  }
  ptr=ptr->next;
 }
printf("\n");
 return n;
}
