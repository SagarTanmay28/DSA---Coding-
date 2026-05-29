Given an array arr[] and an integer k, where every element is at most k positions away from its correct sorted position. This means that if the array were completely sorted, the element at index i in the given array can be at any index from i - k to i + k.

Examples: 

Input: arr[]= [2, 3, 1, 4],  k = 2 
Output: [1, 2, 3, 4]
Explanation: All elements are at most k = 2 positions away from their correct positions.
Element 1 moves from index 2 to 0
Element 2 moves from index 0 to 1
Element 3 moves from index 1 to 2
Element 4 stays at index 3

Input: arr[]= [1, 4, 5, 2, 3, 6, 7, 8, 9, 10], k = 2
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
Explanation :  The sorted array will be 1 2 3 4 5 6 7 8 9 10

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void nearlySorted(vector<int> &arr, int k) {

    int n = arr.size();

    // creating a min heap
    priority_queue<int, vector<int>, greater<int>> pq;

    // pushing first k elements in pq
    for (int i = 0; i < k; i++)
        pq.push(arr[i]);

    int i;

    for (i = k; i < n; i++) {

        pq.push(arr[i]);

        // size becomes k+1 so pop it
        // and add minimum element in (i-k) index
        arr[i - k] = pq.top();
        pq.pop();
    }

    // puting remaining elements in array
    while (!pq.empty()) {
        arr[i - k] = pq.top();
        pq.pop();
        i++;
    }
}

int main() {
    vector<int> arr = {2, 3, 1, 4};
    int k = 2;
    nearlySorted(arr, k);
    for (int x : arr)
        cout << x << ' ';
    return 0;
}
