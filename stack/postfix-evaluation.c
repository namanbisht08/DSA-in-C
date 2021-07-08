#include<stdio.h>
#include<malloc.h>
#include<math.h>

typedef struct 
{
 char op;
 int val;
}SymbolTable;

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

int isHigh(Stack *top,char op)
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
  
 for(i=0;ifx[i];i++);

 pfx=(char*)malloc(i+1);

 i=0;
 while(*ifx)
 {
  op=*ifx++;
    
  if(isOperator(op))
  {
   if(isHigh(top,op))
    top=push(top,op);
   else
   {
    if(op==')')
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

int evaluate(char *pfx)
{
 Stack *top='\0';
 SymbolTable st[10];
 int n,i,j,lft,ryt;
 char op;

 printf("\n\n");
 for(i=0;pfx[i];i++)
 {
  op=pfx[i];

  if(!isOperator(op))
  {
   for(j=0;j<n&&st[j].op!=op;j++);
   if(j==n)
   {
    st[j].op=op;
    printf("Enter Value for %c : ",op);
    scanf("%d",&st[j].val);
    n++; 
   }
  }
 }

 for(i=0;pfx[i];i++)
 {
  op=pfx[i];
  if(isOperator(op))
  {
   ryt=top->op;
   top=pop(top);
   lft=top->op;
   top=pop(top);
  
   switch(op)
   {
    case '+' : lft=lft+ryt;
               break;
    case '-' : lft=lft-ryt;
               break;
    case '*' : lft=lft*ryt;
               break;
    case '/' : lft=lft/ryt;
               break;
    case '^' : lft=pow(lft,ryt);
   }

   top=push(top,lft);
  }
  else
  {
   for(j=0;st[j].op!=op;j++);
   top=push(top,st[j].val);
  }
 }
 return top->op;
}

void main()
{
 char ifx[200],*pfx;
 
 printf("\nEnter an Infix Expression     : ");
 gets(ifx);

 pfx=postfix(ifx);

 printf("\nEquivalent Postfix Expression : %s",pfx);

 printf("\nResult of Evaluation          : %d\n",evaluate(pfx));

}

