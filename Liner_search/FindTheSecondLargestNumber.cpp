#include <iostream>
using namespace std;
#define size 10
int main()
{
    int arr[size];
    for (int i = 0; i < size; i++){
        cin >> arr[i];
    }
    int lessbig, big;
    if(arr[0]>arr[1]){
        big = arr[0];
        lessbig = arr[1];
    }
    else{
        big = arr[1];
        lessbig = arr[0];
    }        
    for (int a = 2; a < size; a++){
        int current = arr[a];
        if(current > big){
            lessbig = big;
            big = current;
        }
        else if(current == big){
            if(lessbig < current){
                lessbig = current;
            }
        }
        else if(current > lessbig){
            lessbig = current;
        }
    }
    cout << "Second largest: " << lessbig << endl;
    return 0;
}


