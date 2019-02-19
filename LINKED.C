/* Singly linked list */
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define DMA (struct node*)malloc(sizeof(struct node))
struct node *insert_at_last(struct node *root,int data);
struct node *insert_at_begin(struct node *root,int data);
void display(struct node *root);
void count(struct node *root);
struct node *delete_at_begin(struct node *root);
struct node *delete_at_last(struct node *root);
struct node *delete_at_pos(struct node *root);
struct node *insert_at_pos(struct node *root,int data);
struct node
{
   int data;
   struct node *next;
};
void main()
{
	int ch,data;
	struct node *root;
	root=NULL;
	while(1)
	{                clrscr();
	   printf("\n Linked list Menu\n");
	   printf("1.Insert at last\n");
	   printf("2.Insert at Begin\n");
	   printf("3.Insert at position\n");
	   printf("4.Display list\n");
	   printf("5.Count node\n");
	   printf("6.Delete at last\n");
	   printf("7.Delete at first\n");
	   printf("8.Delete at positon\n");
	   printf("0.exit\n");
	   printf("Enter your choice=");
	   scanf("%d",&ch);
	   switch(ch)
	   {
	     case 1:
		 printf("Enter data=");
		 scanf("%d",&data);
		 root=insert_at_last(root,data);
		 break;
	     case 2:
		 printf("Enter data=");
		 scanf("%d",&data);
		 root=insert_at_begin(root,data);
		 break;
	     case 3:
		 printf("Enter data=");
		 scanf("%d",&data);
		 root=insert_at_pos(root,data);break;
	     case 4:
		     display(root);
		      break;
	     case 5:
		   count(root);break;
	     case 6:
		 root=delete_at_last(root);break;
	     case 7:
		  root=delete_at_begin(root);break;
	     case 8:
		   root=delete_at_pos(root);break;
	     case 0:exit(0);
	   }
	}
}
/* Insert_At_Last */
struct node *insert_at_last(struct node *root,int data)
{
      struct node *temp,*newnode,*prevnode;
      newnode=DMA;
      newnode->data=data;
      newnode->next=NULL;
      if(root==NULL)
	root=newnode;
      else
	temp=root;
      while(temp)
      {
	 prevnode=temp;
	 temp=temp->next;
      }
      prevnode->next=newnode;
      return root;
}
/* Display_List  */
void display(struct node *root)
{
   struct node *temp;
   temp=root;
   if(root==NULL)
   {
     printf("LIst empty\n");
     sleep(2);
   }
   else
   {
     while(temp)
     {
       printf("%3d",temp->data);
       temp=temp->next;
     }
   }
   sleep(3);
}
/*  Count_Of_Node  */
void count(struct node *root)
{
     struct node *temp;
     int count=0;
     temp=root;
     if(root==NULL)
     {
	printf("list is Empty");
	sleep(2);
     }
     else
     {
	while(temp)
	{
	  count++;
	  temp=temp->next;
	}
	printf("\n Number of node=%d",count);
     }
sleep(2);
}
/*  Insert_At_Begin  */
struct node *insert_at_begin(struct node *root,int data)
{
  struct node *temp,*newnode,*prevnode;
	 newnode=DMA;
	 newnode->data=data;
	 newnode->next=NULL;
	 temp=root;
	 if(root==NULL)
	  root=newnode;
	 else
	   {
	      newnode->next=temp;
	      root=newnode;
	   }
return root;
}
/*  Delete_At_Last_Node  */
struct node *delete_at_last(struct node *root)
{
     struct node *temp,*prevnode;
     temp=root;
     if(root==NULL)
     {
      printf("List Empty");
      sleep(3);
      }
     else
	{
	  while(temp->next!=NULL)
	  {
	     prevnode=temp;
	     temp=temp->next;
	  }
	}
	prevnode->next=NULL;
	free(temp);
     return root;
}
/*  Delete_At_Begin_Node  */
struct node *delete_at_begin(struct node *root)
{
  struct node *temp;
   temp=root;
   if(root==NULL)
   {
     printf("List empty");
     sleep(2);
   }
   else
   {    root=temp->next;
	 temp->next=NULL;
   }
       free(temp);
   return root;
}
/* Delete_At_Position_Node  */
struct node *delete_at_pos(struct node *root)
{
      int c=0,p;
	    struct node *temp,*prevnode,*v;
      printf("you want to delete node=");
      scanf("%d",&p);
      temp=root;
      if(temp==NULL)
      {
	printf("List Empty");
	sleep(2);
      }
      else
      {
	while(temp)
	{
	    c++;
	   if(c==p)
	  { if(p==1)
	    {
		 root=temp->next;
		 temp->next=NULL;
	    }
	     else
	     {
	    v=temp->next;
	    prevnode->next=v;
	    temp->next=NULL;
	    free(temp);
	    }
	  }
	  prevnode=temp;
	   temp=temp->next;
	}
      }
      return root;
}
/* Insert_At_Position_Node  */
struct node *insert_at_pos(struct node *root,int data)
{
   int c=0,p;
     struct node *temp,*newnode,*prevnode;
   printf("You want to insert position of data=");
   scanf("%d",&p);
      newnode=DMA;
      newnode->data=data;
      newnode->next=NULL;
      temp=root;
      if(root==NULL)
      {
	root=newnode;
      }
      else if(p==1)
      {
	newnode->next=root;
	root=newnode;
      }
      while(temp)
      {
	c++;
	prevnode=temp;
	temp=temp->next;
	if(c==(p-1))
	  {
	 newnode->next=prevnode->next;
	 prevnode->next=newnode;
	  }

	}
 return root;
}













