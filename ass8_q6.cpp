#include <bits/stdc++.h>
using namespace std;

class MaxPriorityQueue {
    vector<int> heap;

    void siftUp(int i) {
        while(i > 0) {
            int p = (i - 1) / 2;
            if(heap[p] >= heap[i]) break;
            swap(heap[p], heap[i]);
            i = p;
        }
    }

    void siftDown(int i) {
        int n = heap.size();
        while(true) {
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            int largest = i;

            if(l < n && heap[l] > heap[largest]) largest = l;
            if(r < n && heap[r] > heap[largest]) largest = r;

            if(largest == i) break;

            swap(heap[i], heap[largest]);
            i = largest;
        }
    }

public:
    void push(int x) {
        heap.push_back(x);
        siftUp(heap.size() - 1);
    }

    int top() {
        if(heap.empty()) return INT_MIN;
        return heap[0];
    }

    void pop() {
        if(heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        if(!heap.empty()) siftDown(0);
    }

    bool empty() { 
        return heap.empty(); 
    }
};

class MinPriorityQueue {
    vector<int> heap;

    void siftUp(int i) {
        while(i > 0) {
            int p = (i - 1) / 2;
            if(heap[p] <= heap[i]) break;
            swap(heap[p], heap[i]);
            i = p;
        }
    }

    void siftDown(int i) {
        int n = heap.size();
        while(true) {
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            int smallest = i;

            if(l < n && heap[l] < heap[smallest]) smallest = l;
            if(r < n && heap[r] < heap[smallest]) smallest = r;

            if(smallest == i) break;

            swap(heap[i], heap[smallest]);
            i = smallest;
        }
    }

public:
    void push(int x) {
        heap.push_back(x);
        siftUp(heap.size() - 1);
    }

    int top() {
        if(heap.empty()) return INT_MAX;
        return heap[0];
    }

    void pop() {
        if(heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        if(!heap.empty()) siftDown(0);
    }

    bool empty() { 
        return heap.empty(); 
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    MaxPriorityQueue maxpq;
    for(int i = 0; i < n; i++) maxpq.push(a[i]);

    while(!maxpq.empty()) {
        cout << maxpq.top();
        maxpq.pop();
        if(!maxpq.empty()) cout << " ";
    }
    cout << "\n";

    MinPriorityQueue minpq;
    for(int i = 0; i < n; i++) minpq.push(a[i]);

    while(!minpq.empty()) {
        cout << minpq.top();
        minpq.pop();
        if(!minpq.empty()) cout << " ";
    }
    cout << "\n";

    return 0;
}
