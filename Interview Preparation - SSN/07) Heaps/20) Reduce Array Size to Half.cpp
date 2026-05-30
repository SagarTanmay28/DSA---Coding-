You are given an integer array arr. You can choose a set of integers and remove all the occurrences of these integers in the array.

Return the minimum size of the set so that at least half of the integers of the array are removed.

 

Example 1:

Input: arr = [3,3,3,3,5,5,5,2,2,7]
Output: 2
Explanation: Choosing {3,7} will make the new array [5,5,5,2,2] which has size 5 (i.e equal to half of the size of the old array).
Possible sets of size 2 are {3,5},{3,2},{5,2}.
Choosing set {2,7} is not possible as it will make the new array [3,3,3,3,5,5,5] which has a size greater than half of the size of the old array.
Example 2:

Input: arr = [7,7,7,7,7,7]
Output: 1
Explanation: The only possible set you can choose is {7}. This will make the new array empty.


class Solution {
public:
    typedef pair<int,int> pi;
    int minSetSize(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int,int> mp;
        for(int i=0;i<n;i++) mp[arr[i]]++;

        int half = n / 2;
        // n = 10 half = 5
        // 3 -> 4 , 5 -> 3, 2 -> 2, 7 -> 1

        int ans = 0;

        priority_queue<pi> pq;
        for(auto &x : mp){
            pq.push({x.second,x.first});
        }

        while(n > half){
            n = n - pq.top().first;
            ans++;
            pq.pop();
        }

        return ans;

        
    }
};
