#include<iostream>

#define size 6
using namespace std;

int position = 0;
//bst struct to have the number;
typedef struct node{
    int num,pos;
    struct node *left, *right;
    node(int val){
        num = val;
        pos = ++position;
        left = NULL;
        right = NULL;
    }
}bst;

bst *addToBst(bst *root, int val){
    if(root == NULL){
        return new bst(val);
    }
    if(val < root->num){
        root->left =  addToBst(root->left, val);
    }else{// if(val > root->num){
        root->right = addToBst(root->right, val);
}
    return root;
}

void inorder(bst *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->num << ' ';
    inorder(root->right);
}

bst *search(bst *root, int val){
    if(root == NULL){
        return NULL;
    }
    if(root->num == val){
        return root;
    }
    if(val < root->num ){
        return search(root->left, val);
    }else{
    //if(val > root->num ){
        return search(root->right, val);
    }
}

int main(){   
    //you are given a sorted array of numbers.
    //use binary search to find the position of a specific number.
    //if the number is not in the array, return -1.
    //int array[size];
    bst *root = NULL;
    //root = addToBst(root, 5);
    //inorder(root);
    //array = 1,2,3,4,5,6
    int number;
    cout<< "Enter sorted array numbers: ";
    for(int i = 0; i<size; i++){
        cin >> number;
        root = addToBst(root, number);
    }
    cout << "Enter the number you want to find: ";
    bst *temp = NULL;
    int nm;
    cin >> nm;
    temp = search(root, nm);
    if(temp == NULL){
        cout << "The number was not there";
        return -1;
    }else{
        int index = temp->pos;
        index -= 1;
        cout << "number   : " << temp->num << '\n';
        return 0;    
    }
}