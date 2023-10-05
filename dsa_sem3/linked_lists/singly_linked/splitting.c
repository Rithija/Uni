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

void display(node *head){ 
    if(head==NULL) printf("list is empty");
    node *p=head;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->link;
    }
    printf("\n");}
//splitting the original list into two lists based on a splitting point
void splitting1(node *original,node **first,node **second,int splitting_point){
    node *current = original;

    while (current != NULL) {
        if (current->data <= splitting_point) {
            insertingend(first, current->data);
        } else {
            insertingend(second, current->data);
        }
        current = current->link;
    }
}
void splitList(node* original, node** first, node** second, int i, int j) {
    node* current = original;
    int count = 0;

    while (current != NULL) {
        if (count < i) {
            insertingend(first, current->data);
        } else if (count < i + j) {
            insertingend(second, current->data);
        }
        count++;
        current = current->link;
    }
}
/* //using a split ratio 
void splitList(node* original, node** first,node** second, float splitRatio) {
    if (splitRatio <= 0.0 || splitRatio >= 1.0) {
        printf("Invalid split ratio. It should be between 0 and 1.\n");
        return;
    }

    int totalNodes = 0;
    node* current = original;

    while (current != NULL) {
        totalNodes++;
        current = current->link;
    }

    int nodesInFirstList = (int)(splitRatio * totalNodes);
    int nodesInSecondList = totalNodes - nodesInFirstList;

    current = original;
    int count = 0;

    while (current != NULL) {
        if (count < nodesInFirstList) {
           insertingend(first, current->data);
        } else {
            insertingend(second, current->data);
        }
        count++;
        current = current->next;
    }
}
*/
int main(){
    node *head=NULL;
    node *first=NULL, *second=NULL;
    int ele,choice;
    int splitting_point,i,j;
    
    do{
        printf("\n1. inserting\n"
                "2.splitting using a splitpoint\n"
                "3.splitting\n"
                "4.displaying\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("enter the element ");
                    scanf("%d",&ele);
                    insertingend(&head,ele);
                    break;
            case 2: printf("enter the splitting point");
                    scanf("%d",&splitting_point);
                    splitting1(head,&first,&second,splitting_point); break;
            case 3: printf("enter the number of element you wish to have in each sublist ");
                    scanf("%d%d",&i,&j);
                    splitList(head,&first,&second,i,j); break;
            case 4: printf("\nsublist 1: ");
                    display(first);
                    printf("\nsublist 2: ");
                    display(second); break;

        }

        
    }while(choice<=3);
    return 0;
}