//funtion to return the how many time a perticular item repeating in a list.

#include<stdio.h>
#include<malloc.h>

typedef struct _node
{
 int val;
 struct _node* next;
}Node;

Node*makeNode(int);
int frequency(Node*,int);

main()
{
 int n,m;
 Node* start='\0', *last='\0', *nd='\0';
 printf("\n\n");
 while(1)
 {
  printf("Enter a Number to store in List : ");
  scanf("%d",&n);
  if(n==0) break;
  nd=makeNode(n);
  if(start=='\0')
   start=nd;
  else
   last->next=nd;
  last=nd;
 }
printf("\nEnter a Number whose frequency you want to find : ");
scanf("%d",&n);
m=frequency(start,n);
printf("\nFrequency of %d is : %d",n,m);
}

Node* makeNode(int n)
{
 Node* nd=(Node*)malloc(sizeof(Node));
 nd->val=n;
 nd->next='\0';
 return nd;
}

int frequency(Node* ptr, int n)
{
 int g=0;
 while(ptr)
 {
  if(ptr->val==n)
   g++;
  ptr=ptr->next;
 }
return g;
}




