// TC: addNum → O(log n), findMedian → O(1)
// SC: O(n)

class MedianFinder {
    priority_queue<int> maxHeap;                               // left half
    priority_queue<int, vector<int>, greater<int>> minHeap;    // right half

public:
    MedianFinder() {}

    void addNum(int num) {

        // O(1)
        if (maxHeap.empty())
            maxHeap.push(num);
        else {
            // O(1)
            if (num < maxHeap.top())
                maxHeap.push(num);      // O(log n)
            else
                minHeap.push(num);      // O(log n)
        }

        // balance heaps → O(log n)
        if (maxHeap.size() == minHeap.size() + 2) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        if (minHeap.size() == maxHeap.size() + 2) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {

        // O(1)
        if (maxHeap.size() == minHeap.size() + 1)
            return maxHeap.top();
        else if (minHeap.size() == maxHeap.size() + 1)
            return minHeap.top();
        else
            return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};
