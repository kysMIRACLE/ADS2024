#include <iostream>
#include <deque>
using namespace std;
int main() {

    deque <int> Boris;
    deque <int> Nursik;
    
    int card;
    for(int i = 0; i < 5; i++) {
        cin >> card;
        Boris.push_back(card);
    }

    for(int i = 0; i < 5; i++) {
        cin >> card;
        Nursik.push_back(card);
    }

    int moves = 0;
    const int max_moves = 1000000;
    
    while(moves < max_moves) {
        if(Boris.empty()){
            cout << "Nursik" << " " << moves;
            return 0;
        }
        if (Nursik.empty()) {
            cout << "Boris " << " " << moves;
            return 0;
        }
        int borisCard = Boris.front();
        int nursikCard = Nursik.front();
        Boris.pop_front();
        Nursik.pop_front();

        if (borisCard == 0 && nursikCard == 9) {
            Boris.push_back(borisCard);
            Boris.push_back(nursikCard);
        } else if (borisCard == 9 && nursikCard == 0) {
            Nursik.push_back(borisCard);
            Nursik.push_back(nursikCard);
        } else if (borisCard > nursikCard) {
            Boris.push_back(borisCard);
            Boris.push_back(nursikCard);
        } else {
            Nursik.push_back(borisCard);
            Nursik.push_back(nursikCard);
        }
        moves++;

    }
    cout << "blin nichya";
    return 0;

}