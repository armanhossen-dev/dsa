#include <iostream>
using namespace std;
#define size 10
int main()
{
    int n[size];
    int num;
    int cnt = 0;
    for (int i = 0; i < size; i++)
    {
        cin >> n[i];
    }
    cin >> num;
    for(int k = 0; k< size ; k++){
        if(num == n[k]){
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}

/*
Count how many times a given number appears in an array. Return the count or 0 if the number is not present.
*/