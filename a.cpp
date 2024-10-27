#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int T; 
    cin >> T;
    cin.ignore();

    for (int i = 0; i < T; ++i) {
        string line;

        vector<string> strings;
        string word;
        for (char ch : line) {
            if (ch == ' ') {
                if (!word.empty()) {
                    strings.push_back(word);
                    word.clear();
                }
            } else {
                word += ch;
            }
        }
        if (!word.empty()) {
            strings.push_back(word);  
        }

        stable_sort(strings.begin(), strings.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        });

        
        for (size_t j = 0; j < strings.size(); ++j) {
            if (j > 0) cout << " ";  
            cout << strings[j];
        }
        cout << endl;
    }

    return 0;
}