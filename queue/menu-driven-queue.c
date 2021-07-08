#include<stdio.h>
#include<stdlib.h>

#define MAX 5

typedef struct 
{
 int front,rear;
 int items[MAX];
}Queue;

void initialize(Queue*);
int insertq(Queue*,int);
int deleteq(Queue*);

void main()
{
 Queue q;
 char *menu[]={"[I]nsert","[D]elete","[P]rint","[Q]uit"};
 int i,n;
 char opt;

 initialize(&q);

 while(1)
 {
  system("cls");
  printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tQ U E U E");
  printf("\n\t\t\t\t\t\t\t---------\n");
  
  for(i=0;i<4;i++)
  {
   printf("\n\n\t\t\t\t\t\t\t%s",menu[i]);
  }

  printf("\n\n\n\t\t\t\t\t\t\tEnter Option : ");

  opt=getchar();
  fflush(stdin);

  switch(opt)
  {
   case 'I':
   case 'i': system("cls");
             printf("\n\n\n\n\n\n\t\t\t\t\t\t\tI N S E R T");
             printf("\n\t\t\t\t\t\t\t-----------");

             printf("\n\n\n\n\t\t\t\t\t\tEnter the Item to Insert : ");
             scanf("%d",&n);
             fflush(stdin);

             if(insertq(&q,n)) 
              printf("\n\n\n\n\n\t\t\t\t\titem inserted successfully.. press any key..");
             else
              printf("\n\n\n\n\n\t\t\t\t\tqueue overflow - insertion failed.. press any key..");

             getch();
             fflush(stdin);   
             break;
   case 'D':
   case 'd': system("cls");
             printf("\n\n\n\n\n\n\t\t\t\t\t\t\tD E L E T E");
             printf("\n\t\t\t\t\t\t\t-----------");

             n=deleteq(&q);
             if(n) 
             {
              printf("\n\n\n\n\n\t\t\t\t\t\t\tItem Deleted - %d",n);
              printf("\n\n\n\n\n\t\t\t\t\t\t\tpress any key..");
             }
             else
              printf("\n\n\n\n\n\t\t\t\t\tqueue underflow - deletion failed.. press any key..");

             getch();
             fflush(stdin);   
             break;
   case 'P':
   case 'p': system("cls");
             printf("\n\n\n\n\n\n\t\t\t\t\t\t\tI T E M S");
             printf("\n\t\t\t\t\t\t\t---------\n\n");

             while(n=deleteq(&q))
             {
              printf("\n\t\t\t\t\t\t\t    %d",n);
             } 

             printf("\n\n\n\n\n\t\t\t\t\t\t\tpress any key..");

             getch();
             fflush(stdin);   
             break;
   case 'Q':
   case 'q': exit(0);
             break;
   default : printf("\n\n\n\n\n\n\t\t\t\t\t\tinvalid option.. press any key..");
             getch();
             fflush(stdin);
  } 
 }
}

void initialize(Queue *p)
{
 p->rear=-1;
 p->front=0;
}

int insertq(Queue *p,int n)
{
 if(p->rear==MAX-1)
  return 0;
 p->items[++p->rear]=n;
 return 1;
}

int deleteq(Queue *p)
{
 if(p->rear<p->front)
  return 0;
 return p->items[p->front++];
}























