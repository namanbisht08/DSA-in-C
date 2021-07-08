#include<stdio.h>
#include<malloc.h>

typedef struct _Stack
{
 int op;
 struct _Stack *next;
}Stack;

Stack *push(Stack *top,int op)
{
 Stack *nd=(Stack*)malloc(sizeof(Stack));
 nd->op=op;
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

int isOperator(char op)
{
 return op=='+'||op=='-'||op=='*'||op=='/'||op=='^'||op=='('||op==')';
}

int isHigh(Stack *top,char op)    //when upcoming operator has higer precedence or it can pushed into stack - (return 1)
{
 if(top=='\0'||top->op=='('||op=='(')
  return 1;
 if(top->op=='^')
  return 0;
 if(op=='^') 
  return 1;
 if((op=='*'||op=='/')&&(top->op=='+'||top->op=='-'))
  return 1;
 return 0;
}

char *postfix(char *ifx)
{
 Stack *top='\0';
 char *pfx,op;

 int i;
  
 for(i=0;ifx[i];i++);           //to calculate size of string passed... infix expression

 pfx=(char*)malloc(i+1);       // [i] is the lenght of string + 1 for string null

 i=0;
 while(*ifx)    // while(op= *ifx++)
 {              //.....
  op=*ifx++;
    
  if(isOperator(op))
  {
   if(isHigh(top,op))
    top=push(top,op);
   else
   {
    if(op==')')    // ittrate uptill closing bracket. 
    {
     while(top->op!='(')
     {
      pfx[i++]=top->op;
      top=pop(top);
     }
     top=pop(top);
    }
    else
    {
     while(top&&!isHigh(top,op))
     {
      pfx[i++]=top->op;
      top=pop(top);
     }
     top=push(top,op);   
    }
   }   
  }
  else
   pfx[i++]=op; 
 }
 while(top)
 {
  pfx[i++]=top->op;
  top=pop(top);
 }
 pfx[i]='\0';
 return pfx;
}

void main()
{
 char ifx[200],*pfx;   
 
 printf("\nEnter an INfix Expression     : ");
 gets(ifx); fflush(stdin);

 pfx=postfix(ifx);

 printf("\nEquivalent Postfix Expression : %s\n",pfx);
}



