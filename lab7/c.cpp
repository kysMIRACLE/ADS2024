#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    set<int> first_person_numbers;
    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        first_person_numbers.insert(num);
    }

    
    set<int> common_numbers;
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        if (first_person_numbers.count(num)) {
            common_numbers.insert(num);
        }
    }

    
    for (int num : common_numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}