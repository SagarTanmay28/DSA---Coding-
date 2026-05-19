
We are given N chocolates whose sweetness value is given by arr[]. We need to divide chocolates into K sets such that each set will contain consecutive chocolates and each chocolate should be present in exactly 1 set. The task is to maximize the minimum sweetness among all the K sets.

Note: A set may be empty, meaning someone might get 0 sweetness.

Examples:

Input: N = 3, K = 2, arr = {1, 2, 4}
Output: 3
Explanation:  If we put the first two chocolates in the 1st set and the third chocolate in the 2nd set. Then the total sweetness value that you will get will be 3. Hence, the answer is 3 in this case.



Input: N = 3, K = 1, arr = {1, 3, 5}
Output: 9
Explanation: As you don’t have any other friends other than yourself. You will get all the chocolates. Hence, the answer is 9 in this case. 

class Solution {
public:
    
    bool check(int mid, int k, vector<int>& arr){
        int sum = 0;
        int count = 0;
        
        for(int i=0;i<arr.size();i++){
            sum += arr[i];
            
            if(sum >= mid){
                count++;
                sum = 0;
            }
        }
        
        return count >= k;
    }
    
    int maxSweetness(vector<int>& arr, int k) {
        
        int lo = 0;
        int hi = accumulate(arr.begin(), arr.end(), 0);
        
        int ans = 0;
        
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            
            if(check(mid, k, arr)){
                ans = mid;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        
        return ans;
    }
};
