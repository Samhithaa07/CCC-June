#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int* ptr = &n;
    
    cout << "Variable value: " << *ptr << endl;
    cout << "Variable address: " << ptr << endl;
    
    return 0;
}