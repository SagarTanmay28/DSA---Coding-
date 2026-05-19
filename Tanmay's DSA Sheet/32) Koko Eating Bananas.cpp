class Solution {
public:
    bool check(int mid,vector<int>& piles,int h){
        int n = piles.size();
        int m = mid;
        int count = 0;
         // Input: piles = [30,11,23,4,20], h = 6
        // Output: 23
        for(int i=0;i<n;i++){
            if(count>h) return false;
            if(piles[i]<=m) count++;
            else if(piles[i]%m == 0) count += piles[i]/m;
            else count += piles[i]/m + 1;
        }
        return count <= h;

    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int max = -1;
        for(int i=0;i<n;i++){
           if(piles[i]>max) max = piles[i];
        }
        int lo = 1;
        int hi = max;
        int ans = max;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(check(mid,piles,h)){
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;

        }
        return ans;
    }
};
