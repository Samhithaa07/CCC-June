#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr;
    int num;

    cout << "Enter binary array elements (0s and 1s), then press Enter:\n";

    while (cin >> num) {
        if (num != 0 && num != 1) {
            cout << "Invalid input! Only 0s and 1s allowed." << endl;
            return 1;
        }
        arr.push_back(num);
        if (cin.peek() == '\n') break;
    }

    int countZeros = 0;

    for (int val : arr) {
        if (val == 0)
            countZeros++;
    }

    for (int i = 0; i < arr.size(); ++i) {
        if (i < countZeros)
            arr[i] = 0;
        else
            arr[i] = 1;
    }

    cout << "Number of zeroes: " << countZeros << endl;
    cout << "Array after shifting zeroes to the left:\n";
    for (int val : arr)
        cout << val << " ";
    cout << endl;

    return 0;
}
