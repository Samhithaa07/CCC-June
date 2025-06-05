#include <iostream>
using namespace std;

int* largestElement(int* arr, int n) {
    int* largest = arr;
    for (int i = 1; i < n; i++) {
        if (*(arr + i) > *largest) {
            largest = arr + i;
        }
    }
    return largest;
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    int* largest = largestElement(arr, n);
    if (largest) {
        cout << "Largest element is: " << *largest << endl;
        cout << "Address of largest element: " << largest << endl;
    } else {
        cout << "Array is empty." << endl;
    }

    delete[] arr;
    return 0;
}
