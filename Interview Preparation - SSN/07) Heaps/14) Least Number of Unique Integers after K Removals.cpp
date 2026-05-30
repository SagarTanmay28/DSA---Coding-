Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.

 

Example 1:

Input: arr = [5,5,4], k = 1
Output: 1
Explanation: Remove the single 4, only 5 is left.
Example 2:
Input: arr = [4,3,1,1,3,3,2], k = 3
Output: 2
Explanation: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3 will be left.


// Sorting 

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {

        unordered_map<int,int> mp;

        for(int x : arr){
            mp[x]++;
        }

        vector<int> freq;

        for(auto &x : mp){
            freq.push_back(x.second);
        }

        sort(freq.begin(), freq.end());

        int unique = freq.size();

        for(int x : freq){

            if(k >= x){
                k -= x;
                unique--;
            }
            else{
                break;
            }
        }

        return unique;
    }
};

// Heap 
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {

        unordered_map<int,int> mp;

        for(int x : arr){
            mp[x]++;
        }

        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto &x : mp){
            pq.push(x.second);
        }

        while(k > 0){

            int freq = pq.top();

            if(k >= freq){
                k -= freq;
                pq.pop();
            }
            else{
                break;
            }
        }

        return pq.size();
    }
};
