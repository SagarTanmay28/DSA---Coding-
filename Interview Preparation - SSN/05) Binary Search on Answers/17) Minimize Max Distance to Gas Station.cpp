We have a horizontal number line. On that number line, we have gas stations at positions stations[0], stations[1], ..., stations[n-1]. Now, we add k more gas stations so that d, the maximum distance between adjacent gas stations, is minimized. We have to find the smallest possible value of d. Find the answer exactly to 6 decimal places.
Note: stations is in a strictly increasing order.

Examples:

Input: stations[] = [1, 2, 3, 4, 5], k = 2
Output: 1.00
Explanation: Since all gaps are already equal (1 unit each), adding extra stations in between does not reduce the maximum distance.
Input: stations[] = [3, 6, 12, 19, 33], k = 3
Output: 6.00 
Explanation: The largest gap is 14 (between 19 and 33). Adding 2 stations there splits it into approx 4.67. The next largest gap is 7 (between 12 and 19). Adding 1 station splits it into 3.5. Now the maximum gap left is 6.



class Solution {
public:

    bool check(double mid, vector<int>& stations, int k){
        
        int cnt = 0;
        
        for(int i=0;i<stations.size()-1;i++){
            
            double gap = stations[i+1] - stations[i];
            
            int needed = gap / mid;
            
            if(gap == needed * mid) needed--;
            
            cnt += needed;
        }
        
        return cnt <= k;
    }

    double findSmallestMaxDist(vector<int> &stations, int k) {
        
        double lo = 0;
        double hi = stations.back() - stations.front();
        
        while(hi - lo > 1e-6){
            
            double mid = lo + (hi - lo)/2.0;
            
            if(check(mid, stations, k)){
                hi = mid;
            }
            else{
                lo = mid;
            }
        }
        
        return hi;
    }
};

// Explanation 

We use Binary Search on Answer because we need to minimize the maximum distance d between adjacent gas stations after adding k new stations.
lo = 0 because minimum possible distance can approach 0.
hi = stations.back() - stations.front() because maximum possible distance initially can be the whole range.
Since answer is decimal, we use binary search on double.
while(hi - lo > 1e-6) means continue binary search until search space becomes extremely small (0.000001). This guarantees answer accuracy up to 6 decimal places because after this precision difference, both hi and lo are almost same.
mid = lo + (hi - lo)/2.0 represents the maximum allowed distance between adjacent gas stations.
check(mid, stations, k) checks whether it is possible to make every adjacent gap ≤ mid using at most k new stations.
Inside check function:
cnt = 0 stores total new stations required.

Loop runs for every adjacent gap:

gap = stations[i+1] - stations[i]
We calculate how many stations are needed to break this gap into smaller parts such that every part ≤ mid.

Formula:

needed = gap / mid

Example:

gap = 10
mid = 3

We need:

0 --- x --- x --- x --- 10

so 3 stations needed.

Special case:

if(gap == needed * mid) needed--;

because if gap divides perfectly, one extra station gets counted.

Example:

gap = 6
mid = 3

Actual need:

0 --- x --- 6

only 1 station needed, not 2.

cnt += needed adds required stations for all gaps.
return cnt <= k means:
if required stations are within limit k, then current mid is possible.
Back in binary search:

if possible:

hi = mid;

because we try smaller maximum distance.

else:

lo = mid;

because current distance is too small and needs more than k stations.

Finally return hi because it stores the smallest possible maximum distance after binary search finishes.
