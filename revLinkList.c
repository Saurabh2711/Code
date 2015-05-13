#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* head = NULL;
void reverse(struct node*& head_ref,struct node*& rest)
{
  if(rest->link==NULL)
  {
    head=rest;
    rest->next=head_ref;
  }
  else
  {
    reverse(head_ref->next,rest->next);
    rest->next=head;
  }
  return;
}
 
void push(struct node** head_ref, int new_data)
{
    struct node* new_node =
            (struct node*) malloc(sizeof(struct node));
            
    new_node->data  = new_data;
                
    new_node->next = (*head_ref);   
        
    (*head_ref)    = new_node;
}
void printList(struct node *head)
{
    struct node *temp = head;
    while(temp != NULL)
    {
        printf("%d  ", temp->data);   
        temp = temp->next; 
    }
}   
int main()
{
   
     push(&head, 20);
     push(&head, 4);
     push(&head, 15);
     push(&head, 85);     

     printList(head);   
     reverse(head,head->next);                     
     printf("\n Reversed Linked list \n");
     printList(head);   
     getchar();
}