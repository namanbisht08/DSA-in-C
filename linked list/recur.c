#include<stdio.h>
#include<malloc.h>

typedef struct _Node
{
 int val;
 struct _Node *next;
}Node;

Node *makeNode(int);
void print(Node*);

void printrev(Node*);
int  count(Node*);
Node *locate(Node*,int);
int  frequency(Node*,int);
Node *getMin(Node*);
void reverse(Node*);

void main()
{
 Node *start='\0',*last='\0',*nd;
 int n;

 printf("\n");
 while(1)
 {
  printf("Enter a Number [0 to stop] : ");
  scanf("%d",&n);
  
  if(n==0) break;

  nd=makeNode(n);
  if(start=='\0')
   start=nd;
  else
   last->next=nd;

  last=nd;
 }

 printf("\n");
 printf("\nItems in Original Order    : ");
 print(start);
 printf("\nItems in Reverse  Order    : ");
 printrev(start);

 printf("\n");
 printf("\nCount of Items in the List : %d",count(start));

 printf("\n");
 printf("\nEnter the Item to Locate   : ");
 scanf("%d",&n);

 nd=locate(start,n);
 if(nd)
  printf("\nItem Found at Location     : %d",nd);
 else
  printf("\nItem Not Found..");

 printf("\nCount of Occurrence        : %d",frequency(start,n));

 printf("\nSmallest Item in the List  : ");
 nd=getMin(start);
 if(nd)
  printf("%d",nd->val);
 else
  printf("No Items..");
  
 reverse(start);
 nd=start;
 start=last;
 last=nd;
 printf("\n\nReversed List              : ");
 print(start);
 
 printf("\n\n");
}

Node *makeNode(int n)
{
 Node *nd=(Node*)malloc(sizeof(Node));
 nd->val=n;
 nd->next='\0';
 return nd;
}

void print(Node *ptr)
{
 while(ptr)
 {
  printf("%d ",ptr->val);
  ptr=ptr->next;
 }
}

void printrev(Node *ptr)
{
 if(ptr=='\0') return;
 printrev(ptr->next);
 printf("%d ",ptr->val);
}

int count(Node *start)
{
 if(!start) return 0;
 return count(start->next)+1;
}

Node *locate(Node *start,int n)
{
 if(start=='\0' || start->val==n) return start;
 return locate(start->next,n);
}

int frequency(Node *start,int n)
{
 int f;

 if(!start) return 0;

 f=frequency(start->next,n);
 if(start->val==n) f++;
 return f;
} 

Node *getMin(Node *start)
{
 Node *min;

 if(!start) return start;

 min=getMin(start->next);
 
 if(min=='\0' || start->val<min->val) min=start;
 return min;
} 

void reverse(Node *ptr)
{
 if(ptr=='\0' || ptr->next=='\0') return;
 reverse(ptr->next);
 ptr->next->next=ptr;
 ptr->next='\0';
}

















