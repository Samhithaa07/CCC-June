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

    cout << "Array elements: ";
    for (int i = 0; i < n; i++) {
        cout << *(ptr + i) << " ";
    }
    cout << endl;
    return 0;
}
