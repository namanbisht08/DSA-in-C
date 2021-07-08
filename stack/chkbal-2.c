#include<stdio.h>
#include<malloc.h>

typedef struct _Stack
{
 char bkt;
 struct _Stack *next;
}Stack;


Stack *push(Stack *top,char b)
{
 Stack *nd=(Stack*)malloc(sizeof(Stack));
 nd->bkt=b;
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

int isBracket(char b)
{
 if(b=='(') return ')';
 if(b=='{') return '}';
 if(b=='[') return ']';

 if(b==')'||b==']'||b=='}') return -1;

 return 0;
}


void main()
{
 Stack *top='\0';
 char exp[1000],b;
 int i;

 printf("\nEnter the Expression : ");
 gets(exp);

 for(i=0;exp[i];i++)
 {
  if(b=isBracket(exp[i]))
  {
   if(b>0)
    top=push(top,b);
   else
   {
    if(top&&top->bkt==exp[i])
     top=pop(top);
    else
     break;
   }
  }
 }

 if(top||exp[i])
  printf("\nThe Expression is Not Balanced..\n");
 else
  printf("\nThe Expression is Balanced..\n");
}








