#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid array size." << endl;
        return 0;
    }

    vector<int> arr(n);
    cout << "Enter " << n << " binary elements (0 or 1):\n";

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        if (arr[i] != 0 && arr[i] != 1) {
            cout << "Invalid input! Only 0s and 1s allowed." << endl;
            return 1;
        }
    }

    int count = 0;

    for (int i = 0; i < n; ++i) {
        if (arr[i] == 0)
            count++;
    }

    for (int i = 0; i < n; ++i) {
        if (i < count)
            arr[i] = 0;
        else
            arr[i] = 1;
    }

    cout << "No. of zeroes: " << count << endl;
    cout << "Array after shifting zeroes to the left:\n";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
