The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
 

Example 1:

Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
 

Constraints:

-105 <= num <= 105
There will be at least one element in the data structure before calling findMedian.
At most 5 * 104 calls will be made to addNum and findMedian.
 

Follow up:

If all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?
If 99% of all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?

If all numbers are in the range [0,100], I would optimize the solution by using a frequency array of size 101 instead of two heaps.
  Since there are only 101 possible values, I can store the count of each number directly. Insertion becomes very efficient because
I only need to increment the corresponding frequency, which takes O(1) time. To find the median, I traverse the frequency array 
cumulatively until I reach the middle element(s).
Because the array size is fixed and very small, median calculation is also effectively O(1). This approach is both faster
and more memory-efficient than the heap-based solution.
If 99% of the numbers are in the range [0,100], I would use a hybrid approach. I would maintain a frequency array for
numbers within [0,100] and store the remaining outlier values separately using heaps or balanced data structures.
Since almost all elements belong to the small range, most insertions are still O(1), and the median can usually be
found directly from the frequency array. Only in rare cases would I need to consider the outlier elements.
This optimization reduces both time and memory overhead compared to handling every number with heaps.

class MedianFinder {
public:
    priority_queue<int> left; // max heap 
    priority_queue<int,vector<int>,greater<int>> right; // min heap

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.size() == 0 || left.top() > num) left.push(num);
        else right.push(num);

        // if right heap has more size than left heap so 
        // more top element of right to the left heap
        if(right.size() > left.size()){
            left.push(right.top());
            right.pop();
        }
        // if left ka size is more than right size + 1 so 
        // left ka top ka element right heap me daalo
        else if(left.size() > right.size() + 1){
            right.push(left.top());
            left.pop();
        }
    }
    
    double findMedian() {
        int n = left.size();
        int m = right.size();

        if((n + m) % 2 == 0){
            return (left.top() + right.top()) / 2.0;
        }

        else return left.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
