// Custom Sort 

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        sort(arr.begin(), arr.end(), [x](int a, int b) {
            int diff = abs(a - x) - abs(b - x);
            return diff == 0 ? a < b : diff < 0;
        });
        vector<int> result(arr.begin(), arr.begin() + k);
        sort(result.begin(), result.end());
        return result;
    }
};

// Two Pointers

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0, r = arr.size() - 1;
        while (r - l >= k) {
            if (abs(x - arr[l]) <= abs(x - arr[r])) {
                r--;
            } else {
                l++;
            }
        }
        return vector<int>(arr.begin() + l, arr.begin() + r + 1);
    }
};

// Binary Search
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0, r = arr.size() - k;
        while (l < r) {
            int m = (l + r) / 2;
            if (x - arr[m] > arr[m + k] - x) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return vector<int>(arr.begin() + l, arr.begin() + l + k);
    }
};

// Priority Queue 

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int> ans;

        priority_queue< pair<int,int> > pq;
        for(int i=0;i<n;i++){
            pq.push({abs(x-arr[i]),arr[i]});
            if(pq.size() > k) pq.pop();
        }
        while(pq.size()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};
