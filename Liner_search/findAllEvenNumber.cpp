/*Traverse the array and collect all even numbers in a new array. Return the list of even numbers.*/
#include <iostream>
#include <vector>
#define size 10
using namespace std;
int main()
{
    int n[size];
    int even = 0;
    for (int i = 0; i < size; i++){
        cin >> n[i];
        if (n[i] % 2 == 0){
            even++;
        }
    }
    vector<int> allev(even);
    int a = 0;
    for(int i=0;i<size;i++){
        if(n[i]%2==0){
            allev[a]=n[i];
            a++;
        }
    }
    for(int k : allev){
        cout << k << ' ';
    }
    return 0;
}
