//adding polynomials using linkedlistss

#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int c;
    int e;
    struct node* link;
}polynode;
void attach(int c,int e, polynode **head){//functions like insertend 
    polynode *newnode=(polynode *)malloc(sizeof(polynode));
    if(!(newnode)) {printf( "Memory allocation failed for new node.\n");
    exit(1);}
    else{
        newnode->c=c;
        newnode->e=e;
        newnode->link=NULL;
        if(!(*head)) *head=newnode;
        else{
            polynode *p= *head;
            while(p->link!=NULL)
                p=p->link;
            p->link=newnode;
        }
    }
}
polynode* readpoly(){
    polynode *head=NULL;
    int ch=1,c,e;
    while(ch){
        printf("enter the coefficient and exponent values\n");
        scanf("%d%d",&c,&e);
        attach(c,e,&head);//this has code similar to insert end
        printf("do you want to give more?\n press 1 else 0\n");
        scanf("%d",&ch);
    }
    return head;
}
int compare(int x,int y){
    if(x==y) return 0;
    else if(x>y) return 1;
    else return -1;
}
polynode *addpoly(polynode *head1,polynode *head2){
    polynode *head=NULL;int res;
    while(head1!=NULL && head2!=NULL){
        switch(compare(head1->e,head2->e)){
            case 0: //this is when both the exponents of the x are same
                    res= head1->c+head2->c;
                    if(res!=0)
                        attach(res,head1->e,&head);
                    head1=head1->link;
                    head2=head2->link;
                    break;
            case 1: //this is when the list1 exponent part is greater than list 2's exponent
                    res=head1->c;
                    if(res!=0)
                        attach(res,head1->e,&head);
                    head1=head1->link;
                    break;
            case -1: //this is when the list2 exponent part is greater than list 1's
                    res=head2->c;
                    if(res!=0)
                        attach(res,head2->e,&head);
                    head2=head2->link;
                    break;
        }
    }
    if(head2==NULL){
        while(head1!=NULL){
            attach(head1->c,head1->e,&head);
            head1=head1->link;
        }
    }
    else if(head1==NULL){
        while(head2!=NULL){
            attach(head2->c,head2->e,&head);
            head2=head2->link;
        }
    }
    return head;
}
void display(polynode *head){
    if(head==NULL) printf("list is empty");
    polynode *p=head;
    while(p!=NULL)
    {
        printf("(%d , %d) ",p->c,p->e);
        p=p->link;
    }
    printf("\n");
}
int main(){
    polynode *head1=NULL,*head2=NULL,*head3=NULL;
    head1=readpoly();
    head2=readpoly();
    head3=addpoly(head1,head2);
    printf("the coefficients and exponents in the polynomial1 are\n ");
    display(head1);
    printf("the coefficients and exponents in the polynomial2 are\n ");
    display(head2);
    printf("the coefficients and exponents in the resultant polynomial are\n ");
    display(head3);
    return 0;
}