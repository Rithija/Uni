//binary search tree inserting the elements and in-pre-post order traversal
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *rchild, *lchild;
}node;
node *createnode(int data){
    node *temp=(node *) malloc(sizeof(node));
    temp->lchild= NULL;
    temp->rchild=NULL;
    temp->data=data;
    return temp;
}
node *insert(node *root,int data){
    node *newnode=createnode(data);
    if(root==NULL)
        root= newnode;

    else{
        if(data>root->data) root->rchild=insert(root->rchild,data);
        else root->lchild=insert(root->lchild,data);
    }
    return root;
}
void inorder(node *root){
    if(root!=NULL){
    inorder(root->lchild);
    printf("%d ",root->data);
    inorder(root->rchild);
    }
}
void preorder(node *root){
    if(root!=NULL){
    printf("%d ",root->data);
    preorder(root->lchild);
    preorder(root->rchild);
    }
}
void postorder(node *root){
    if(root!=NULL){
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d ",root->data);
    }
}
int main(){
    node *root=NULL;
    int ele,x;
    do{
        printf("1: insertion\n"
        "2: in order traversal\n"
        "3: pre order traversal\n"
        "4: post order traversal\n");
        scanf("%d",&x);
        switch(x){
            case 1: printf("enter the element for insertion ");
                    scanf("%d",&ele);
                    root=insert(root,ele); break;
            case 2: inorder(root); break;
            case 3: preorder(root); break;
            case 4: postorder(root); break;
        }
    }while(x<=4);
    return 0;
}