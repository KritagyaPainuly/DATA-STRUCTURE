#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
  int data;
  struct node *next;
} node;
void atHead (node ** list, int val)
{
  node *n = malloc (sizeof (node));
  n->data = val;
  n->next = *list;
  *list = n;
}

void atTail(node ** list, int val)
{
  node *n = malloc (sizeof (node));
  n->data = val;
  n->next = NULL;
  if (*list == NULL)
    {
      *list = n;
      return;
    }
  node *temp = *list;
  while (temp->next != NULL)
    {
      temp = temp->next;
    }
  temp->next = n;
}

void display (node * list)
{
  while (list != NULL)
    {
      printf ("%d->", list->data);
      list = list->next;
    }
  printf ("NULL\n");
}
void search(node *list,int val)
{
    if(list==NULL){
    printf("List is empty\n");
    return;}
    int flag=0;
     while (list != NULL)
    {
      if(list->data==val)
      flag=1;
      list = list->next;
    }
    if(flag==1)
    printf("FOUND!!!!\n");
    else
    printf("NOT FOUND!!!!\n");
    return;
}

int main()
{
  node *list = NULL;
  while (1)
    {
      printf ("1 Head\n2 Tail\n3 Display\n4 Search\n5 Exit\n");
      int n;
      scanf ("%d", &n);
      switch (n)
	{
	case 1:
	  {
	    int val;
	    printf ("Enter a number\n");
	    scanf ("%d", &val);
	    atHead (&list, val);
	    break;
	  }
	case 2:
	  {
	    int val;
	    printf ("Enter a number\n");
	    scanf ("%d", &val);
	    atTail (&list, val);
	    break;
	  }
	case 3:
	  {
	    display (list);
	    break;
	  }
	case 4:
	 {
	   int val;
	   printf ("Enter a number\n");
	   scanf ("%d", &val);
	   search(list,val);
	   break;
	 }
	 
	case 5:
	  {
	    return 0;
	  }
	}
}
}
