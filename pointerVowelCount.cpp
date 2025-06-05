#include <iostream>
using namespace std;

int countVowels(const char* str) {
    int count = 0;
    while (*str) {
        char ch = tolower(*str);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
        str++;
    }
    return count;
}

int main() {
    char str[100];
    cin.getline(str, 100);

    int vowels = countVowels(str);
    cout << "Number of vowels: " << vowels << endl;
    return 0;
}
