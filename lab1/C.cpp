#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1, str2;
    cin >> str1 >> str2;

    string processedStr1 = "";
    string processedStr2 = ""; 

    for (char ch : str1) {
        if (ch == '#') {
            if (!processedStr1.empty()) {
                processedStr1.pop_back(); 
            }
        } else {
            processedStr1.push_back(ch); 
        }
    }

    
    for (char ch : str2) {
        if (ch == '#') {
            if (!processedStr2.empty()) {
                processedStr2.pop_back();
            }
        } else {
            processedStr2.push_back(ch); 
        }
    }

    if (processedStr1 == processedStr2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}