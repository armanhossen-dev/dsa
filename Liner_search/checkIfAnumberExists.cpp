/*Check if a specific number is present in an array. Return "YES" if it exists and "NO" otherwise.*/
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
    for (int k = 0; k < size; k++)
    {
        if (num == n[k])
        {
            cnt++;
        }
    }
    if (cnt == 0)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
    return 0;
}
