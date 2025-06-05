#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];  

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int* ptr = arr;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += *(ptr + i);
    }

    cout << "Sum = " << sum << endl;
    return 0;
}
