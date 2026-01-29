#include<iostream>
using namespace std;
//to find the how many times a number is in the stored memory, and form that count i can find the last position
#define size 6
int p = 0;

typedef struct node{
    int data;
    int pos;
    int count;
    struct node *left, *right;
    node(int num){
        data = num;
        ++p;
        pos = p;
        count = 1;
        left = NULL;
        right = NULL;
    }
}bst;

bst *add(bst *root, int val){
     
     if(root == NULL){
        return new bst(val);
     }
     if(val == root->data){
      root->count++;
     }
     if(val < root->data){
     //else if(val <= root->data){
        root->left = add(root->left, val);
     }else{
        root->right = add(root->right, val);
     }
}

void inorder(bst *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";  
    inorder(root->right);
}

//inorder to find or count target num how many time
int Tcount = 0;
int cTarget(bst *root, int val){
    if(root == NULL){
        return Tcount;
    }
    cTarget(root->left,val);
    if(root->data == val){
        Tcount++;
    }
    cTarget(root->right,val);
}


int main(){
    bst *root = NULL;
    int num;
    cout << "Enter six number to the bst:\n";
    for(int i = 0; i < size; i++){
        cin >>num;
        root = add(root, num);
    }
   
    int fn, howManyTimes = 0;
    cout << "Enter the number: ";
    cin >> fn;
    howManyTimes = cTarget(root, fn);
    cout << "howManyTimes: " << howManyTimes;
    return 0;
}
