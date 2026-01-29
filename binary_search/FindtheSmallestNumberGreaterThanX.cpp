#include <iostream>
#include <vector>
using namespace std;

int next(const vector<int>& arr, int X) {
    int left = 0;
    int right = arr.size() - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] > X) {
            result = arr[mid];           
            right = mid - 1;
        } else {           
            left = mid + 1;
        }
    }
    return result;
}



int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    int X = 6;
    int result = next(arr, X);
    if (result != -1) {
        cout << "The smallest number greater than " << X << " is: " << result << endl;
    } else {
        cout << "No number greater than " << X << " exists in the array." << endl;
    }
    return 0;
}
