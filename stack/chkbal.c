#include<stdio.h>
#include<malloc.h>

typedef struct _Stack
{
 char bkt;
 struct _Stack *next;
}Stack;

Stack *push(Stack *top,char bkt)
{
 Stack *nd=(Stack*)malloc(sizeof(Stack));
 nd->bkt=bkt;
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
 char exp[200];
 Stack *top='\0';
 int i,err=0;

 printf("\nEnter the Expression : ");
 gets(exp);

 for(i=0;exp[i]&&!err;i++)
 {
  if(exp[i]=='('||exp[i]=='['||exp[i]=='{')
   top=push(top,exp[i]);
  else
  if(exp[i]==')'||exp[i]==']'||exp[i]=='}')
  {
   if(!top)
    err=1;
   else
   {
    switch(exp[i])
    {
     case ')' : if(top->bkt!='(') err=1;
                break;
     case ']' : if(top->bkt!='[') err=1;
                break;
     case '}' : if(top->bkt!='{') err=1;
    }
   }
   if(!err) top=pop(top);
  }
 } 

 if(err||top)
  printf("\nExpression Not Balanced..\n");
 else
  printf("\nExpression is Balanced..\n");
  
}











