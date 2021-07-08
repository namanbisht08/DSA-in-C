#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct _Queue
{
 char wrd[25];
 struct _Queue *next;
}Queue;

typedef struct _Stack
{
 char wrd[25];
 struct _Stack *next;
}Stack;

Queue *insertq(Queue *front, Queue **p2rear,char *wrd)
{
 Queue *nd=(Queue*)malloc(sizeof(Queue));
 strcpy(nd->wrd,wrd);
 nd->next='\0';
 if(front=='\0')
  front=nd;
 else
  (*p2rear)->next=nd;
 *p2rear=nd;
 return front;
}

Queue *deleteq(Queue *front)
{
 if(front)
 {
  Queue *tmp=front;
  front=front->next;
  free(tmp);
 }
 return front;
}

Stack *push(Stack *top,char *wrd)
{
 Stack *nd=(Stack*)malloc(sizeof(Stack));
 strcpy(nd->wrd,wrd);
 nd->next=top;
 return nd;
}

Stack *pop(Stack *top)
{
 if(top)
 {
  Stack *tmp=top;
  top=top->next;
  free(tmp);
 }
 return top;
}

void main()
{
 Stack *top='\0';
 Queue *front='\0',*rear;

 char str[1000],wrd[25],*p;
 int i,n;

 printf("\nEnter a String : ");
 gets(str);

 i=0;
 while(str[i])
 {
  while(str[i]==' ') i++;
  
  if(str[i]=='\0') break;

  n=0;
  p=str+i;
  while(str[i] && str[i]!=' ')
  {
   i++;
   n++;
  }

  strncpy(wrd,p,n);
  wrd[n]='\0';

  front=insertq(front,&rear,wrd);
  top=push(top,wrd);
 } 

 while(top && strcmp(front->wrd,top->wrd)==0)
 {
  front=deleteq(front);
  top=pop(top);
 }

 if(top)
  printf("\nThe String is Not a Palindrome..\n");
 else
  printf("\nThe String is a Palindrome..\n");
}











