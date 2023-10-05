// for concantenating 2strings using singly linked lists
//2 ways L1=L1L2 L3=L1L2
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* link;
} node;
node* insertend(node* head,int ele){
     node* temp=(node *) malloc(sizeof(node)); 
    temp->data=ele;
    temp->link=NULL;
    if(!head) head=temp;
    else{
        node* p=head;
        while(p->link!=NULL){
            p=p->link;
        }
        p->link=temp;
    }
    return head;
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
node* concatenate(node *head1, node *head2){//L1=L1+L2 format
    node *p=head1;
    if(!(head1)) printf("list is empty\n");
    else{
        while(p->link!=NULL)
            p=p->link; 
        p->link=head2;
    }
    return head1;
 
}
node* concatenate2(node* head1,node *head2){//L3=L1+L2 format
    node* head3=NULL;
    node* p=head1;
    node *q=head2;
    while(p!=NULL){
       head3=insertend(head3,p->data);
       p=p->link;
    }
    while(q!=NULL){
        head3=insertend(head3,q->data);
        q=q->link;
    }
    return head3;
}
void freeList(node *head) {
    node *temp;
    while (head != NULL) {
        temp = head;
        head = head->link;
        free(temp);
    }
}
int main(){
    node *head1=NULL, *head2=NULL,*head3=NULL;int m,n,ele,x;
    printf("enter the number of elements for list 1 ");
    scanf("%d",&m);
    for(int i=0; i<m;i++)
        {
            printf("enter the element ");
            scanf("%d",&ele);
            head1=insertend(head1,ele);
        }
    display(head1);
    printf("enter the number of elements for list 2 ");
    scanf("%d",&n);
    for(int i=0; i<n;i++)
        {
            printf("enter the element ");
            scanf("%d",&ele);
            head2=insertend(head2,ele);
        }
    display(head2);
    printf("what format do you want to concatenate\n"
           "1. concatenate to the first list\t"
           "2. concatenate intact to a new list\n");
    scanf("%d",&x);
    switch(x){
        case 1: head1= concatenate(head1,head2);display(head1); break;
        case 2: head3=concatenate2(head1,head2);display(head3); break;
        default: printf("wrong option");
    }
    freeList(head1);freeList(head2);freeList(head3);
    return 0;
}