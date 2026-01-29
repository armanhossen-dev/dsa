/*Find the first and last position of a given number in an array. If the number is not present, return -1 for both.*/
#include <iostream>
using namespace std;
#define size 5
int main()
{
    int n[size];
    int num;
    int FIRST = 0;
    int LAST = 0;
    for (int i = 0; i < size; i++)
    {
        cin >> n[i];
    }
    cin >> num;

    for (int k = 0; k < size; k++)
    {
        if (num == n[k])
        {
            FIRST = k;
        }
    }
    
    for (int G = (size-1); G > 0; G--)
    {
        if (num == n[G])
        {
            LAST = G;
        }
    }
    cout << "index: \n";
    cout << "First Position : ";
    cout << FIRST << endl;
    cout << "Last Position : ";
    cout << LAST << endl;

    return 0;
}

