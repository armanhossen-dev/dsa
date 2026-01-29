#include<iostream>
using namespace std;
int main(){
    int n[10];
    for(int i = 0 ; i<10; i++){
        cin >> n[i];
    }
    int num;
    cin >> num;
    for(int i = 0 ; i<10; i++){
        if(num == n[i]){
            cout << i << endl;
            return 0;
        }
    }
    return -1;
}
/*Search for a specific number in an unsorted array. Return its position if found or -1 if it doesn’t exist.*/