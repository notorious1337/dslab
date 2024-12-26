#include <stdio.h>
#include <stdlib.h>
 
struct node {
    int info;
    struct node *llink;
    struct node *rlink;
};
typedef struct node* NODE;
 
// Function to insert a node into the BST
NODE insert_node(int item, NODE root) {
    NODE cur, temp, prev;
    temp = (NODE)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        return root;
    }
    temp->info = item;
    temp->llink = temp->rlink = NULL;
 
    if (root == NULL)
        return temp;
 
    prev = NULL;
    cur = root;
    while (cur != NULL) {
        prev = cur;
        if (item < cur->info)
            cur = cur->llink;
        else
            cur = cur->rlink;
    }
 
    if (item < prev->info)
        prev->llink = temp;
    else
        prev->rlink = temp;
 
    return root;
}
 
// Function to traverse the BST in inorder
void inorder(NODE root) {
    if (root == NULL)
        return;
    inorder(root->llink);
    printf("%d\t", root->info);
    inorder(root->rlink);
}
 
// Function to traverse the BST in preorder
void preorder(NODE root) {
    if (root == NULL)
        return;
    printf("%d\t", root->info);
    preorder(root->llink);
    preorder(root->rlink);
}
 
// Function to traverse the BST in postorder
void postorder(NODE root) {
    if (root == NULL)
        return;
    postorder(root->llink);
    postorder(root->rlink);
    printf("%d\t", root->info);
}
 
// Function to search for a key in BST
NODE search(int item, NODE root) {
    if (root == NULL || item == root->info)
        return root;
 
    if (item < root->info)
        return search(item, root->llink);
 
    return search(item, root->rlink);
}
 
int main() {
    int choice, item;
    NODE root = NULL, temp;
 
    while (1) {
        printf("\n1. Insert an element\n");
        printf("2. Traverse the Tree (Preorder, Inorder, Postorder)\n");
        printf("3. Search for an element\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
 
        switch (choice) {
            case 1:
                printf("Enter the item to be inserted: ");
                scanf("%d", &item);
                root = insert_node(item, root);
                break;
 
            case 2:
                if (root == NULL) {
                    printf("Tree is empty\n");
                } else {
                    printf("\nInorder Traversal: ");
                    inorder(root);
                    printf("\nPreorder Traversal: ");
                    preorder(root);
                    printf("\nPostorder Traversal: ");
                    postorder(root);
                    printf("\n");
                }
                break;
 
            case 3:
                printf("Enter the element to be searched: ");
                scanf("%d", &item);
                temp = search(item, root);
                if (temp == NULL)
                    printf("Element does not exist\n");
                else
                    printf("The element %d is found\n", temp->info);
                break;
 
            case 4:
                exit(0);
 
            default:
                printf("Invalid choice\n");
        }
    }
 
    return 0;
}
 
 
