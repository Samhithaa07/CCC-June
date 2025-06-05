#include <iostream>
#include <limits.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    int smallest = INT_MAX;
    int largest = INT_MIN;
    int secondLargest = INT_MIN;
    
    for(int i = 0; i < n; i++){
        if(arr[i] < smallest){
            smallest = arr[i];
        }
        
        if(arr[i] > largest){
            secondLargest = largest;
            largest = arr[i];
        }
        
        else if(arr[i] > secondLargest && arr[i] != largest){
            secondLargest = arr[i];
        }
        
    }
    
    cout << "Smallest element: " << smallest << endl;
    cout << "Largest element: " << largest << endl;
    cout << "Second largest element: " << secondLargest << endl;

    return 0;
}