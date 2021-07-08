#include<stdio.h>
#include<malloc.h>

typedef struct _BST
{
 int val;
 struct _BST *left, *right;
}BST;

typedef struct _queue
{
 BST* root;
 struct _queue* next;
 int level;
}queue;

BST* insert(BST*, int);
int getlevel(BST*,int);
void levelbylevel(BST*);



void main()
{
 BST* root='\0';
 int n;
 
 printf("\nEnter elements int tree.. [ 0 to stop]\n");
 while(1)
 {
  scanf("%d",&n);
  if(n==0) break;
  root=insert(root,n);
 }

printf("\n\n\n");
levelbylevel(root);

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ D E F I N A T I O N S ~~~~~~~~~~~~~~~~~~~~~~~~


BST* insert(BST* root, int n)
{
 if(root=='\0')
 {
  BST* nd=(BST*)malloc(sizeof(BST));
  nd->val=n;
  nd->left=nd->right='\0';
  return nd;
 }
if(n<root->val)
 root->left=insert(root->left,n);
else
 root->right=insert(root->right,n);
return root;
}


queue* insertq(queue* front, queue**p2rear, BST*root)
{
 queue*nd=(queue*)malloc(sizeof(queue));
 nd->root=root;
 nd->next='\0';
 
 if(front=='\0')
  front=nd;
 else
  (*p2rear)->next=nd;
 *p2rear=nd;
 return front;
}
 
queue* deleteq(queue* front)
{
 if(front)
 {
  queue*temp=front;
  front=front->next;
  free(temp);
 }
return front;
}

void levelbylevel(BST* root)
{
 queue*front='\0', *rear;
 if(root) front=insertq(front, &rear, root);
 while(front)
 {
  root=front->root;
  front=deleteq(front);
  printf(" [%d] ",root->val);
  if(root->left)
   front=insertq(front, &rear, root->left);
  else
   front=insertq(front, &rear, root->right);
 }
}

