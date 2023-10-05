//basic operations of inserting and deleting in a singly linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
   struct node *link;
}node;
//case 1 of insert front: without making changes to the linked list directly, ie function has its own copy and makes changes to that 
node* insertfront(node *head, int ele){
    node* temp=(node *)malloc(sizeof(node)); 
    temp->data=ele;
    temp->link=NULL;
    if(!head) head=temp;
    else{
        temp->link=head;
        head=temp;
    }
    return head;
}
//case 2: using double pointer to make changes directly to the linked list
int insertfront1(node* *head,int ele){
    
   node* temp=(node*)malloc(sizeof(node));
if(temp==NULL) return 0;
else{
temp->data=ele;
temp->link=NULL;
if((*head)!=NULL)
    temp->link=*head;
*head=temp;
return 1;
    }
}
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
int insertend1(node* *head,int ele){
    node *temp=(node *)malloc(sizeof(node));
    if(temp==NULL) return 0;
    else{
        temp->data=ele;
        temp->link=NULL;
        if(!(*head)) *head=temp;
        else{
            node *p =*head;
            while(p->link!=NULL){
                p=p->link;
            }
            p->link=temp;
        }
        return 1;
    }
}
//insertion at random position using position
int insertrand(node* *phead,int ele, int pos){
    node *temp=(node *)malloc(sizeof(node));int flag;int res;
    if(temp==NULL) flag=0;
    else{
        temp->data=ele;
        temp->link=NULL;
        if((*phead)==NULL||pos==1)
        res=insertfront1(phead,ele);
        else{
            int i=1;
            node* p=*phead;
            node *q=NULL;
            while(i<pos && (p->link)!=NULL){
            q=p; 
            p=p->link;
            i++;
            }
            if(i==pos){
                q->link=temp;
                temp->link=p;
            }
            if(pos==i+1)
                {p->link=temp;flag=1;}
            else flag=0;
            return flag;
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
}
void deletefront(node* *head){
    if(!(*head)) printf("list is empty ");
    else{
        node *p=*head;
        *head=p->link;
        printf("%d just got deleted ",p->data);
        free(p);
        p=NULL;
        }
}
void deleteend(node **head){
    if(!(*head)) printf("list is empty\n");
    else{
        if((*head)->link==NULL){
            free(*head); *head=NULL;
        }
        else{
            node *p=*head;
            node *q=NULL;
            while(p->link!=NULL){
                q=p;
                p=p->link;
            }
            printf("%d ",p->data);
            q->link=NULL;
            free(p);
            p=NULL;
        }
    }
}
int deleterand(node* *head, int pos){
    if(!(*head)) return 0;
    else{
        if(pos==1)
            deletefront(head);    
        else{int i=1;node* p=*head; node *q=NULL;
            while(i<pos && (p->link)!=NULL){
                q=p;
                p=p->link;
                i++;
            }
            if(i==pos){
                q->link=p->link;
                free(p);p=NULL; return 1;
            }
            else{
                printf("invalid");return 0;
            }
        }
    }

}
int deletekey(node* *head,int key){
    if(!(*head)) return 0;
    else{node *p=*head;
        int i=0;
        while((p->data)!=key &&(p->link)!=NULL){
            p=p->link;
            i++;
        }
        if((p->data)!=key) return 0;
        else
      { int res= deleterand(head,i+1);
        return res;}
    }
}
/* //without using the deleterand function, to delete key-----
void deletekey(node **head, int key){
    if(!(*head)) {printf("list is empty");return;}
    else{
        node *p=*head;
        if(p->data==key && p!=NULL)//if key is found at first position 
        {   
            *head=(*head)->link;//also deals with the case of single element
            printf("%d got deleted",p->data); 
            free(p);
        }
        else{node *q=NULL;
            while(p->link!=NULL && p->data!=key)
                q=p;
                p=p->link;
            if(p->data==key)
            {
                q->link=p->link;
                free(p);
            }
            else
                printf("element not found");
        }

    }
}
*/
int main(){
    node* head=NULL;
    int ele,pos,choice,n,res,key;
    do{
        printf("\nthe allowed functions\n"
        "1. for insertfront using pass by value\n"
        "2. for insertfront using pass by address\n"
        "3. for insertend using pass by value\n"
        "4. for insertend using pass by address\n"
        "5. for inserting at a random position\n"
        "6. deleting from front\n"
        "7. deleting from end\n"
        "8. deleting at a random position\n"
        "9. deleting a node with given element\n"
        "10. displaying...\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("give an element ");
                scanf("%d",&ele);
                head=insertfront(head,ele);
                break;
            case 2: printf("give any element ");
                scanf("%d",&ele);
                res=insertfront1(&head,ele);
                printf(res? "insertion was successful\n":"insertion was unsuccessful\n");
                break;
            case 3: printf("enter an element ");
                scanf("%d",&ele);
                head=insertend(head,ele);
                break;
            case 4:  printf("give any element ");
                scanf("%d",&ele);
                res=insertend1(&head,ele);
                printf(res? "insertion was successful\n":"insertion was unsuccessful\n");
                break;
            case 5: printf("give the element and the position you want the element to be inserted in\n");
                scanf("%d%d",&ele,&pos);
                res=insertrand(&head,ele,pos);
                printf(res? "insertion was successful\n":"insertion was unsuccessful\n");
                break;
            case 6: deletefront(&head);
                    break;
            case 7: deleteend(&head);
                    break;
            case 8: printf("enter the position ");
                    scanf("%d",&pos);
                    res=deleterand(&head,pos);
                    printf(res? "deletion successful":"deletion unsuccessful");
                    break;
            case 9: printf("enter the key element to delete "); 
                    scanf("%d",&key);
                    res=deletekey(&head,key);
                    printf(res? "deletion successful":"deletion unsuccessful");
                    break;
            case 10: display(head);
                    break;
           
        }
    }while(choice<=10);
    return 0;
}