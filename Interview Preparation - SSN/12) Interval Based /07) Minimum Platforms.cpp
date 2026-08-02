Given arrival arr[] and departure dep[] times of trains on the same day, find the minimum number of platforms needed so that no train waits. A platform cannot serve two trains at the same time; if a train arrives before another departs, an extra platform is needed.

Note: Time intervals are in the 24-hour format (HHMM) , where the first two characters represent hour (between 00 to 23 ) and the last two characters represent minutes (this will be <= 59 and >= 0). Leading zeros for hours less than 10 are optional (e.g., 0900 is the same as 900).

Examples:

Input: arr[] = [900, 940, 950, 1100, 1500, 1800], dep[] = [910, 1200, 1120, 1130, 1900, 2000]
Output: 3
Explanation: There are three trains during the time 9:40 to 12:00. So we need a minimum of 3 platforms.
Input: arr[] = [900, 1235, 1100], dep[] = [1000, 1240, 1200]
Output: 1
Explanation: All train times are mutually exclusive. So we need only one platform.
Input: arr[] = [1000, 935, 1100], dep[] = [1200, 1240, 1130]
Output: 3
Explanation: All 3 trains have to be there from 11:00 to 11:30


class Solution {
public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {

        vector<pair<int,int>> events;

        int n = arr.size();

        for (int i = 0; i < n; i++) {
            events.push_back({arr[i], 1});
            events.push_back({dep[i], -1});
        }

        sort(events.begin(), events.end(),
             [](auto &a, auto &b) {

                if (a.first == b.first)
                    return a.second > b.second;

                return a.first < b.first;
             });

        int curr = 0;
        int ans = 0;

        for (auto &event : events) {
            curr += event.second;
            ans = max(ans, curr);
        }

        return ans;
    }
};

// Best Approach 

class Solution {
public:
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int n = arr.size();
        int i = 0, j = 0;
        int platforms = 0;
        int ans = 0;

        while (i < n && j < n) {
            if (arr[i] <= dep[j]) {
                platforms++;
                ans = max(ans, platforms);
                i++;
            } else {
                platforms--;
                j++;
            }
        }

        return ans;
    }
};

