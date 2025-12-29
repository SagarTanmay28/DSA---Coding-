// TC: Each push/pop → O(log n), peek/size → O(1)
// SC: O(n)

void priorityQueueSTLDemo() {

    // Min-heap
    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(10);        // O(log n)
    pq.push(20);        // O(log n)
    pq.push(-30);       // O(log n)

    pq.top();           // O(1)

    pq.push(35);        // O(log n)
    pq.top();           // O(1)

    pq.size();          // O(1)

    pq.pop();           // O(log n)
    pq.top();           // O(1)

    pq.push(5);         // O(log n)
    pq.push(8);         // O(log n)
    pq.push(2);         // O(log n)
    pq.push(0);         // O(log n)
    pq.push(3);         // O(log n)
    pq.push(1);         // O(log n)
    pq.push(7);         // O(log n)
    pq.push(6);         // O(log n)

    // Note:
    // Iterating over priority_queue does NOT give sorted order
    // Access is only guaranteed via top()
}
