#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int* ptr = &n;
    int** doublePtr = &ptr;
    
    cout << "Variable value: " << n << endl;
    cout << "Variable value via pointer: " << *ptr << endl;
    cout << "Variable value via double pointer: " << **doublePtr << endl;
    
    return 0;
}
