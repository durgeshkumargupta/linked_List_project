/* Doubly_Linked_List */
#include<stdio.h>  /*Header file */
#include<conio.h>  /*Header file */
#include<dos.h>    /*Header file */
#define DMA (struct dnode*)malloc(sizeof(struct dnode))
struct dnode
{
  int data;
  struct dnode *prev;
  struct dnode *next;
};
/*  Insert_At_Last_Node  */
struct dnode *insert_at_last(struct dnode *root,int data)
{
   struct dnode *temp,*newnode,*prevnode;
   newnode=DMA;
   newnode->data=data;
   newnode->next=NULL;
   newnode->prev=NULL;
   if(root==NULL)
   root=newnode;
   else
     temp=root;
     while(temp)
     {
       prevnode=temp;
       temp=temp->next;
       temp->prev=prevnode;
     }
     prevnode->next=newnode;
   return root;
}
/* Insert_At_First_Node */
struct dnode *insert_at_first(struct dnode *root,int data)
{
   struct dnode *temp,*newnode;
      newnode=DMA;
      newnode->data=data;
      newnode->next=NULL;
      newnode->prev=NULL;
      temp=root;
      if(root==NULL)
	root=newnode;
      else
      {
       temp->prev=newnode;
       newnode->next=temp;
       root=newnode;
      }
      return root;
   }
/* Insert_At_Position_Node */
struct dnode *insert_at_position(struct dnode *root,int data)
{
    struct dnode *temp,*newnode,*prevnode;
    int c=0,p;
    newnode=DMA;
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;
    temp=root;
    printf("Enter you choice position to insert data=");
    scanf("%d",&p);
    if(root==NULL)
    root=newnode;
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
      temp->prev=prevnode;
      if(c==(p-1))
      {
	newnode->next=prevnode->next;
	prevnode->next=newnode;
	newnode->prev=prevnode;
      }
    }
      return root;
}
/* Display_All_node */
void display(struct dnode *root)
{
    struct dnode *temp;
    temp=root;
    if(temp==NULL)
    {
     printf("List empty\n");
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
sleep(2);
}
/* Count_All_Node */
void count(struct dnode *root)
{
    struct dnode *temp;
    int c;
    temp=root;
    if(temp==NULL)
    {
     printf("List empty\n");
     sleep(2);
    }
    else
    {
      while(temp)
      {
	c++;
	temp=temp->next;
      }
    }
    printf("number of node=%d",c);
sleep(2);
}
/* Delete_At_Last_Node */
struct dnode *delete_at_last(struct dnode *root)
{
  struct dnode *temp,*prevnode;
  temp=root;
  if(root==NULL)
  {
    printf("list empty\n");
    sleep(2);
  }
  else
  {  while(temp->next!=NULL)
     {
       prevnode=temp;
       temp=temp->next;
     }
     temp->prev=NULL;
     prevnode->next=NULL;
     free(temp);
     }
     return root;
  }
/* Delete_At_First_Node */  
struct dnode *delete_at_first(struct dnode *root)
{
   struct dnode *temp,*v;
   temp=root;
   if(root==NULL)
   {
     printf("list empty");
     sleep(2);
   }
   else
   {
     root=temp->next;
     temp->next=NULL;
     free(temp);
   }
   v=root;
   v->prev=NULL;
   return root;
}
/* Searching_Date */
void search(struct dnode *root)
{
    struct dnode *temp;
    int s,v;
    temp=root;
    if(root==NULL)
     printf("List empty");
    else
    {
       printf("Searching data enter=");
       scanf("%d",&s);
       while(temp)
       {
	 if(s==temp->data)
	     v=s;
	 temp=temp->next;
       }
    if(v==s)
      printf("Data found\n");
    else
      printf("Data not found\n");
      }
      sleep(2);
}
/* Find_maximum_and_minimum_Number  */
void max_min(struct dnode *root)
{
    struct dnode *temp;
    int min,max;
    temp=root;
    min=max=temp->data;
    if(root==NULL)
       printf("List empty");
    else
    {
	while(temp)
	{
	  if(min>temp->data)
	  min=temp->data;
	  else if(max<temp->data)
	  max=temp->data;
	  temp=temp->next;
	}
	printf("Maximum data=%d",max);
	printf("\nMinimum data=%d",min);
    }
	sleep(3);
}
/* Delete_At_Position_Node */
struct dnode *delete_at_position(struct dnode *root)
{
     struct dnode *prevnode,*temp,*v;
     int c=0,p;
     printf("Enter position=");
     scanf("%d",&p);
     temp=root;
     if(root==NULL)
     printf("Empty");
     else
     {
	while(temp)
	{
	c++;
	if(c==p)
	{   if(p==1)
	    {
	     root=temp->next;
	     temp->next=temp->prev=NULL;
	     free(temp);
	    }
	   else
	  {
	  prevnode=temp->prev;
	  v=temp->next;
	  prevnode->next=v;
	  v->prev=prevnode;
	  temp->next=temp->prev=NULL;
	  free(temp);
	  }
	}
	temp=temp->next;
     }
  }
     return root;
}
/*  Sorting_Node  */
struct dnode *sorting(struct dnode *root)
{
      struct dnode *temp,*prevnode;
      int v;
      temp=root;
      if(root==NULL)
      {
      printf("List is Empty");
      sleep(2);
      }
      else
      {
	  while(temp)
	  {
	    prevnode=temp;
	    while(temp->next!=NULL)
	    {
	    temp=temp->next;
		if(prevnode->data>temp->data)
		 {
		   v=prevnode->data;
		   prevnode->data=temp->data;
		   temp->data=v;
		 }
	    }
	 temp=prevnode;
	 temp=temp->next;
	 }
      }
      return root;
}
/* Reverse_of_Node */
struct dnode *reverse_of_node(struct dnode *root)
{
    struct dnode *temp1,*temp2,*nextnode;
    if(root==NULL)
    printf("List Empty");
    else
    {
	temp1=root;
	while(temp1)
	{
	   nextnode=temp1;
	   temp1=temp1->next;
	}
	temp2=nextnode;
	while(temp2)
	{
	  printf("%3d",temp2->data);
	  temp2=temp2->prev;
	}
    }
    sleep(2);
    return root;
}
/* Defination_Of_Main_Function */
void main()
{
	int data,ch;
	struct dnode *root;
	root=NULL;
	while(1)
	{  clrscr();
	   printf("\n Menu of doubly linked linked\n");
	   printf("1.insert at last\n");
	   printf("2.insert at first\n");
	   printf("3.insert at position\n");
	   printf("4.Display list\n");
	   printf("5.Count node\n");
	   printf("6.Delete at last\n");
	   printf("7.Delete at first \n");
	   printf("8.Delete at position\n");
	   printf("9.Reverse of node\n");
	   printf("10.searching \n");
	   printf("11.sorting\n");
	   printf("12.Difference max and min\n");
	   printf("0.Exit\n");
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
		root=insert_at_first(root,data);
		break;
	     case 3:
		printf("Enter data=");
		scanf("%d",&data);
		root=insert_at_position(root,data);
		break;
	     case 4:
		display(root);
		break;
	     case 5:
		count(root);
		break;
	     case 6:
		root=delete_at_last(root);
		break;
	     case 7:
		root=delete_at_first(root);
		break;
	     case 8:
		 root=delete_at_position(root);break;
	     case 9:
		  root=reverse_of_node(root);break;
	     case 10:
		 search(root);break;
	     case 11:
		  root=sorting(root);break;
	     case 12:
		 max_min(root);break;
	     case 0:
		exit(0);
	     }
	}
}