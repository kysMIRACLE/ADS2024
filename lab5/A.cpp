#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

struct PriorityQueue {
    vector<ll> heap;

    ll parent(ll i) {
        return (i - 1 / 2);
    }

    ll left(ll i) {
        return (2 * i + 1);
    }

    ll right(ll i) {
        return (2 * i + 2);
    }

    void up(ll i) {
        ll p = parent(i);
        if(i != 0 && heap[i] < heap[p]) {
            swap(heap[i], heap[p]);
            up(p);
        }
    }

    void down(ll i) {
        ll l = left(i);
        ll r = right(i);
        ll min = i;
        ll size = heap.size();
        if(l < size && heap[min] > heap[l]) min = l;
        if(r < size && heap[min] > heap[r]) min = r;
        if(min != i) {
            swap(heap[i], heap[min]);
            down(min);
        }
    }

    ll getsize() {
        return heap.size();
    }

    bool isEmpty() {
        return heap.empty();
    }

    void push(ll x) {
        heap.push_back(x);
        up(heap.size() - 1);
    }

    void pop() {
        if (isEmpty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        down(0)
    

    ll top() {
        if (!isEmpty()) return heap.front();
    }
};

int main() {
    ll n; cin >> n;
    PriorityQueue pq;
    for (ll i = 0; i < n; i++) {
        ll x; cin >> x;
        pq.push(x);
    }
    ll cost = 0;
    while (pq.getsize() > 1) {
        ll first = pq.top(); pq.pop();
        ll second = pq.top(); pq.pop();
        ll merged = first + second;


        cost += merged;
        pq.push(merged);
    }
    cout << cost;
    return 0;
}