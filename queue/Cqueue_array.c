// Array representation of Circular queue...

#include<stdio.h>
#define MAX 5

typedef struct
{
 int front,rear;
 int items[MAX];
} Cqueue;

void initialize(Cqueue*);
int insertq(Cqueue*,int);
int deleteq(Cqueue*);

void main()
{
 int n;
 Cqueue q;
 
 initialize(&q);
 
 if(insertq(&q,25))
  printf("\nInsertion Failed.... Queue Overflow");
  
 n=deleteq(&q) ;
 if(n)
  printf("\nItem Deleted - %d", n);
 else
  printf("\nQueue underflow... Deletion failed...");
}

// -----------------definations--------------------//

void initialize(Cqueue* p)
{
 p->rear=MAX-1;
 p->front=MAX-1;
}

int insertq(Cqueue* p, int n)
{
  if(p->rear==MAX-1)
   p->rear=0;
  else
   p->rear++;

  if(p->rear==p->front)
   {
    if(p->rear==0)
   	 p->rear=MAX-1;
    else
	 p->rear--;
    return 1;
   }

  p->items[p->rear]=n;
  return 0;
}


int deleteq(Cqueue* p)
{
 if(p->front==p->rear)
  return 0;
 if(p->front==MAX-1)
  p->front=0;
 else
  p->front++;
 return p->items[p->front];
}
