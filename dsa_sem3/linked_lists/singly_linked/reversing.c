//reversing a singly linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
   struct node *link;
}node;
void insertingend(node **head,int ele){
    node *newnode= (node *)malloc(sizeof(node));
    if(!newnode) printf("memory not allocated ");
    else{
        newnode->data=ele;
        newnode->link=NULL;
        if(!(*head)) *head=newnode;
        else{
            node *p=*head;
            while(p->link!=NULL)
            p=p->link;
            p->link=newnode;
        }
    }
}
void reverse(node **head){
    node *prev=NULL;
    node *current= *head;
    node *next=NULL;
    while(current!=NULL){
        next=current->link;
        current->link=prev;
        prev=current;
        current=next;
    }
    *head=prev;
}
void display(node *head){ 
    if(head==NULL) printf("list is empty");
    node *p=head;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->link;
    }
    printf("\n");}
int main(){
    node *head=NULL;
    int ele,choice;
    
    do{
        printf("\n1. inserting\n"
                "2.reversing\n"
                "3.displaying\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("enter the element ");
                    scanf("%d",&ele);
                    insertingend(&head,ele);
                    break;
            case 2: reverse(&head); break;
            case 3: display(head);break;
        }  
    }while(choice<=3);
    return 0;
}