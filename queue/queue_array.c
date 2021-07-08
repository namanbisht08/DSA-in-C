// Array representation of queue...

#include<stdio.h>
#define MAX 5
typedef struct
{
 int front, rear;
 int items[MAX];
}queue;

void intialize (queue*);
int isEmpty(queue);
int insertq (queue*, int);
int deleteq(queue*);

void main()
{
 queue q;
 int n;
 initialize(&q);

 if(isEmpty(q))
  printf("\nqueue is empty....\n");
  
 if(!insertq(&q,25))
  printf("\nqueue overflow - insertion failed...");
  
 n=delete(&q);
 if(n)
  printf("\nitem delete - %d",n);
 else
  printf("\nqueue underflow - deletion failed...");
}

void initialize (queue *p)
{
p->front=0;
p->rear= -1;
}

int isEmpty(queue p)
{
return p.rear<p.front;
}

int insertq(queue *p, int n)
{
 if(p->rear == MAX-1)
  return 0;
  
 p->items[++p->rear]=n;
  return 1;
}

int delete (queue *p)
{
 if(p->rear < p->front)
  return 0;
 return p-> items[p->front++];
}
