#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    b.insert(b.end(), a.begin(), a.end());
    
    sort(b.begin(), b.end());

    for (int i = 0; i < b.size(); ++i) {
        if (i > 0) cout << " ";
        cout << b[i];
    }
    cout << endl;

    return 0;
}