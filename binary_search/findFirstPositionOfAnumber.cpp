#include<iostream>
using namespace std;
#define size 5
int p = 0;

typedef struct node{
    int data,pos;
    struct node *left, *right;
    node(int val){
        data = val;
        p++;
        pos = p;
        left = NULL;
        right = NULL;
    }
}bst;


bst *add_into_bst(bst *root, int value){
    if(root == NULL){
        return new bst(value);
    }
    if(value < root->data){
        root->left = add_into_bst(root->left, value);
    }else{
root->right = add_into_bst(root->right, value);
    }
    return root;  
}

void inorder(bst *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data;
    inorder(root->right);
}

bst *search(bst *root, int val){
    if(root == NULL){
        return NULL;
    }
    else if(val == root->data){
        return root;
    }
    else if(val < root->data){
        return search(root->left, val);
    }else{
        return search(root->right, val);
    }
    return root;        
}

int main(){
    //given a sorted array where number can appear multiple times.
    //find the first position of a specific number.
    //if the number is not present, return -1
    bst *root = NULL;
    cout<< "Enter 5 random num to store in bst : ";
    int i=1, num;
    while(i<=size){
        cin >> num;
        root = add_into_bst(root , num);
        i++;
    }
    int nm;
    cout << "find the number: ";
    cin >> nm;
    bst *temp = search(root, nm);
    if(temp == NULL){
        cout << "Number not found\n";
        return -1;
    }else{
        cout << "Position : " << temp->pos;    
        return 0;  
    }
}

