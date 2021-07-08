#include<stdio.h>
#include<malloc.h>

typedef struct _Stack
{
 char chr;
 struct _Stack *next;
}Stack;

Stack *push(Stack *top,char chr)
{
 Stack *nd=(Stack*)malloc(sizeof(Stack));
 nd->chr=chr;
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
 char str[200];
 Stack *top='\0';
 int i;

 printf("\nEnter a String : ");
 gets(str);

 for(i=0;str[i];i++) top=push(top,str[i]);

 for(i=0;str[i];i++)
 {
  if(str[i]==top->chr)
   top=pop(top);
  else
   break;
 }

 if(str[i]||top)
  printf("\nThe Stringf is Not a Palindrome..\n");
 else
  printf("\nThe Stringf is a Palindrome..\n");
  
}











