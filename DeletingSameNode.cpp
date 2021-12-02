#include<stdio.h>
#include<stdlib.h>
typedef struct node{
int data;
struct node *next;
}node;
void atHead(node **head,int val)
{
node *n=(node *)malloc(sizeof(node));
n->data=val;
n->next=(*head);
(*head)=n;
}
void atTail(node **head,int val)
{
node *n=(node *)malloc(sizeof(node));
if((*head)==NULL)
{
atHead(head,val);
return;
}
n->data=val;
n->next=NULL;
node* temp=*head;
while(temp->next!=NULL)
{
temp=temp->next;
}
temp->next=n;
}
void delete_node(node **head,int val)
{
node *temp=*head;
while(temp->next->data!=val)
{
temp=temp->next;
}
node *n=(node *)malloc(sizeof(node));
n=temp->next;
temp->next=temp->next->next;
free(n);
}
void display(node *temp)
{
node *temp1=temp;
while(temp!=NULL)
{
printf("%d->",temp->data);
temp=temp->next;
}
printf("NULL\n");
}
void ddisplay(node **head)
{
node *temp=*head;
while(temp!=NULL)
{
node *temp1=temp;
while(temp1->next!=NULL)
{
if(temp->data==temp1->next->data)
delete_node(head,temp->data);
temp1=temp1->next;
}
temp=temp->next;
}
display(*head);
}
int main(){
node *head=NULL;
atHead(&head,19);
atHead(&head,19);
atTail(&head,21);
atTail(&head,22);
atTail(&head,23);
atTail(&head,22);
atTail(&head,23);
atTail(&head,23);
display(head);
ddisplay(&head);
}
