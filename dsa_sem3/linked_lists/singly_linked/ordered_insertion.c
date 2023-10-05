//demonstrating how to take the elements and orderly inserting them in the list
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
   struct node *link;
}node;

void orderedinsertion(node **head,int ele){
    node *newnode=(node *)malloc(sizeof(node));
    if(!newnode) {printf("memory not allocated "); exit(0);}
   
    else{ newnode->data=ele;
          newnode->link=NULL;
    
        if(!(*head)) *head=newnode;
        else{
            node *p=*head;node *q=NULL;
            while(p!=NULL && p->data<ele){
                q=p;
                p=p->link;
            }
            if(p==NULL){
                //inserting at the end
                q->link=newnode;
            } 
            
            else if(p== *head) {//inserting at the front
            newnode->link=*head;
            *head=newnode;}
            else{
                //inserting middle
                q->link=newnode;
                newnode->link=p;
                
            }

        }

    }
}
void display(node *head){
    if(head==NULL) printf("list is empty");
      node *p=head;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->link;
    }
    printf("\n");
}
int main(){
    node *head=NULL;
    int ele,choice;
    do{ 
        printf("enter an element ");
        scanf("%d",&ele);
        orderedinsertion(&head,ele);
        display(head);
        printf("do you wish to continue ? press 1 else 0\n");
        scanf("%d",&choice);
    }while(choice);
}