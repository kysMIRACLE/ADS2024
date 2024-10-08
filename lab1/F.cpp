#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int n;
    cin >> n;
    int cnt = 0;
    int number = 1;
    
    while(cnt < n) {
        number++;
        bool isPrime = true;

        if(number <= 1) isPrime = false;
        else if(number == 2 || number == 3) isPrime = true;
        else if(number % 2 == 0 || number % 3 == 0) isPrime = false;
        else {
            for(int i = 5; i * i <= number; i += 6) {
                if(number % i == 0 || number % (i + 2) == 0) {
                    isPrime = false;
                    break;
    
                }
            }
        }
        if(isPrime) {
            cnt++;
        }
    }

    cout << number << endl;
    return 0;


}