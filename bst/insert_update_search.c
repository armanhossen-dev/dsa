#include <stdio.h>
#include <stdlib.h>

// define  node
struct bst {
    int num;
    struct bst* lc;
    struct bst* rc;
};

struct bst* c_new_node(int num) {
    struct bst* newNode = (struct bst*)malloc(sizeof(struct bst));
    newNode->num = num;
    newNode->lc = NULL;
    newNode->rc = NULL;
    return newNode;
}

// insert bst
struct bst* add_new(struct bst* root, int num) {
    if (root == NULL) {
        return c_new_node(num);
    }
    if (num < root->num) {
        root->lc = add_new(root->lc, num);
    } else if (num > root->num) {
        root->rc = add_new(root->rc, num);
    }
    return root;
}

// search  a num in bst
struct bst* s_num(struct bst* root, int num) {
    if (root == NULL || root->num == num) {
        return root;
    }
    if (num < root->num) {
        return s_num(root->lc, num);
    } else {
        return s_num(root->rc, num);
    }
}

// update  num in  bst
void update_num(struct bst* root, int old_num, int nv) {
    struct bst* nodeToUpdate = s_num(root, old_num);
    if (nodeToUpdate != NULL) {
        nodeToUpdate->num = nv;
    }
}

// print  bst nums ascending
void inorder(struct bst* root) {
    if (root != NULL) {
        inorder(root->lc);
        printf("%d ", root->num);
        inorder(root->rc);
    }
}

int main() {
    struct bst* root = NULL;

    // insert  into the bst
    root = add_new(root, 55);
    root = add_new(root, 25);
    root = add_new(root, 75);
    root = add_new(root, 15);
    root = add_new(root, 35);
    root = add_new(root, 65);
    root = add_new(root, 85);

    // display
    printf("The tree nums in order are:\n");
    inorder(root);
    printf("\n");

    // search specific num
    int searchFor = 35;
    struct bst* found = s_num(root, searchFor);
    if (found != NULL) {
        printf("num %d was found in the tree!\n", searchFor);
    } else {
        printf("num %d is not in the tree.\n", searchFor);
    }

    // update  num
    int old_num = 35, nv = 37;
    update_num(root, old_num, nv);
    printf("The tree nums after the update are:\n");
    inorder(root);
    printf("\n");

    // confirm update
    found = s_num(root, nv);
    if (found != NULL) {
        printf("Updated num %d is now in the tree!\n", nv);
    } else {
        printf("Updated num %d could not be found in the tree.\n", nv);
    }
    return 0;
}
