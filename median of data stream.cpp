#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
private:
    priority_queue<long long> maxHeap;  // Lower half (max-heap)
    priority_queue<long long, vector<long long>, greater<long long>> minHeap;  // Upper half (min-heap)

public:
    void addNumber(long long num) {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }
        
        // Rebalance: sizes differ by at most 1
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double getMedian() const {
        if (maxHeap.size() == minHeap.size()) {
            return (double)(maxHeap.top() + minHeap.top()) / 2.0;
        }
        return maxHeap.top();
    }
};

int main() {
    MedianFinder mf;
    vector<long long> stream = {5, 2, 10, 8, 3, 1, 7};
    
    cout << "Stream Medians:\n";
    for (auto num : stream) {
        mf.addNumber(num);
        cout << "After " << num << ": " << mf.getMedian() << endl;
    }
    return 0;
}
