#include<iostream>
using namespace std;
#define size 5
typedef struct node{
    int data;
    struct node *left, *right;
    node(int value){
        data = value;
        left = nullptr;
        right = nullptr;
    }
}bst;
bst *add(bst *root, int num){
    if(root == nullptr){
        return new bst(num);
    }
    if(num <= root->data){
        root->left = add(root->left, num);
    }else{
        root->right = add(root->right, num);
    }
    return root;
}
bst *find_val(bst *root, int val){
    if(root == nullptr){
        return nullptr;
    }
    if(root->data == val){
        return root;
    }
    if(val < root->data){
        return find_val(root->left, val);
    }else{
        return find_val(root->right, val);
    }
}

int main(){
    bst *root = nullptr;
    int n;
    for(int i = 1; i<= size; i++){
        cin >> n;
        root = add(root, n);
    }
    int f;
    cin >> f;
    bst *temp = find_val(root, f);
    if(temp == nullptr){
        cout << "NO.\n" ;
    }else{
        cout << "YES\n";

}
	return 0;
}
