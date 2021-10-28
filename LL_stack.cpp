#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
int data;
struct node* next;

}node;
void push (node **head,int val)
{
node *n=(node*)malloc(sizeof(node));
n->data=val;
n->next=NULL;
if((*head)==NULL)
{
*head=n;
return;
}
node *temp=*head;
while(temp->next!=NULL)
temp=temp->next;
temp->next=n;
}
void pop(node **head,int pos)
{
node *temp=*head;
node *n=(node*)malloc(sizeof(node));
if(temp->next==NULL)
{
n=temp;
free(n);
return;
}
for(int i=2;i<pos;i++)
temp=temp->next;
n=temp->next;
temp->next=NULL;
free(n);
}
void display(node *head)
{
while(head!=NULL)
{
printf("%d->",head->data);
head=head->next;
}
printf("NULL\n");

}
int main()
{
node *head=NULL;
while(1)
{
printf("1 Push\n2 Pop\n3 Display\n4 Exit\n");
int n;
scanf("%d",&n);
switch(n)
{
case 1:
{
int c;
printf("Enter a number\n");
scanf("%d",&c);
push(&head,c);
break;
}

case 2:
{
int c;
printf("Enter a postion\n");
scanf("%d",&c);
pop(&head,c);
break;
}
case 3:
{
display(head);
break;
}
case 4:
{
printf("___EXITING____");
return 0;
}
}

}
}
