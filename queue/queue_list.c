// Linked List representation of queue...

#include<stdio.h>
#include<malloc.h>

typedef struct _queue
{
 int val;
 struct queue*next;
}queue;

queue* makeNode(int);
queue* insertq(queue*, queue**, int);
queue* deleteq(queue*);

main()
{
 queue*rear='\0',*front='\0';
 int n;
 front=insertq(front,&rear,25);
 front=deleteq(front);
}

queue* makeNode(int n)
{
 queue* nd=(queue*)malloc(sizeof(queue));
 nd->val=n;
 nd->next='\0';
}

queue* insertq(queue*front, queue**p2rear, int n)
{
 queue* nd=makeNode(n);
 if(front=='\0')
  front=nd;
 else
  (*p2rear)->next=nd;
 *p2rear=nd;
 return front;
}

queue* deleteq(queue*front)
{
 queue* temp;
 if(front)
 {
  temp=front;
  front=front->next;
  free(temp);
 }
 return front;
}
