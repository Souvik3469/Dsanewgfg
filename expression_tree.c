#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node {
    char data;
    struct node* left;
    struct node* right;
    struct node* next;
};
 struct node *head=NULL;
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(char data)
{
    struct node* node
        = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->next = NULL;
     
    return (node);
}
void printInorder(struct node* node)
{
    if (node == NULL)
        return;
    else{
    /* first recur on left child */
    printInorder(node->left);
 
    /* then print the data of node */
    printf("%c ", node->data);
 
    /* now recur on right child */
    printInorder(node->right);
    }
}
 
void push(struct node* x)
{
    if(head==NULL)
    head = x;
    else
    {
        (x)->next = head;
        head  = x;
    }
    // struct node* temp;
    // while(temp!=NULL)
    // {
    //     printf("%c ", temp->data);
    //     temp = temp->next;
    // }
}
struct node* pop()
{
    // Poping out the top most[ pointed with head] element
    struct node* p = head;
    head = head->next;
    return p;
}
int main()
{
    char s[]= {'A','B','C','*','+','D','/'};
  //  scanf("%[^\n]*c",s);
    int l = sizeof(s) / sizeof(s[0]) ;
    struct node *x, *y, *z;
    int i;
    for (i = 0; i < l; i++) {
        // if read character is operator then poping two
        // other elements from stack and making a binary
        // tree
        if (s[i] == '+' || s[i] == '-' || s[i] == '*'
            || s[i] == '/' || s[i] == '^') {
            z = newNode(s[i]);
            x = pop();
            y = pop();
            z->left = y;
            z->right = x;
            push(z);
        }
        else {
            z = newNode(s[i]);
            push(z);
        }
    }
    printf(" The Inorder Traversal of Expression Tree: ");
    printInorder(z);
    return 0;
}
