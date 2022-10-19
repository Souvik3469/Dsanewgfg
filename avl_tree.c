
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
};
struct node *newnode(int data)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    temp->height=1;
    return temp;
}
int height(struct node *temp)
{
    if(temp==NULL)
        return 0;
    return temp->height;
}
int max(int a,int b)
{
    return (a>b)?a:b;
}
struct node *rightrotate(struct node *y)
{
    struct node *x=y->left;
    struct node *T2=x->right;
    x->right=y;
    y->left=T2;
    y->height=max(height(y->left),height(y->right))+1;
    x->height=max(height(x->left),height(x->right))+1;
    return x;
}
struct node *leftrotate(struct node *x)
{
    struct node *y=x->right;
    struct node *T2=y->left;
    y->left=x;
    x->right=T2;
    x->height=max(height(x->left),height(x->right))+1;
    y->height=max(height(y->left),height(y->right))+1;
    return y;
}
struct node *insert(struct node *root,int data)
{
    if(root==NULL)
        return newnode(data);
    if(data<root->data)
    {
        root->left=insert(root->left,data);
        if(height(root->left)-height(root->right)==2)
        {
            if(data<root->left->data)
                root=rightrotate(root);
            else
                root=leftrotate(root);
        }
    }
    else if(data>root->data)
    {
        root->right=insert(root->right,data);
        if(height(root->right)-height(root->left)==2)
        {
            if(data>root->right->data)
                root=leftrotate(root);
            else
                root=rightrotate(root);
        }
    }
    root->height=max(height(root->left),height(root->right))+1;
    return root;
}
struct node *minvalue(struct node *root)
{
    struct node *current=root;
    while(current->left!=NULL)
        current=current->left;
    return current;
}

void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void display(struct node *root)
{
    
    if(root!=NULL)
    {
        printf("%d ",root->data);
        display(root->left);
        display(root->right);
    }
}
int main()
{
    struct node *root=NULL;
    int choice,data;
    while(1)
    {
        printf("\nEnter your choice \n1.Insert \n2.Inorder \n3.Preorder \n4.Exit: ");
       
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the data: ");
                scanf("%d",&data);
                fflush(stdin);
                root=insert(root,data);
                break;
            case 2:
                inorder(root);
                break;
            case 3:
                display(root);
                break;
	    
	    
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");

        }
    }
    

    return 0;
}
