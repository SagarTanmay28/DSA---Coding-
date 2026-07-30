There is a car with capacity empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).

You are given the integer capacity and an array trips where trips[i] = [numPassengersi, fromi, toi] indicates that the ith trip has numPassengersi passengers and the locations to pick them up and drop them off are fromi and toi respectively. The locations are given as the number of kilometers due east from the car's initial location.

Return true if it is possible to pick up and drop off all passengers for all the given trips, or false otherwise.

 

Example 1:

Input: trips = [[2,1,5],[3,3,7]], capacity = 4
Output: false
Example 2:

Input: trips = [[2,1,5],[3,3,7]], capacity = 5
Output: true


// Heaps / Priority Queues

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        if(n == 0) return true;

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > pq;

        for(int i=0;i<n;i++){
            pq.push({trips[i][1],trips[i][0]});
            pq.push({trips[i][2],-trips[i][0]});
        }

        int sum = 0;
        while(pq.size()){
            auto v = pq.top();
            pq.pop();

            sum += v[1];
            if(sum > capacity) return false;
        }

        return true;
    }
};


// Line Sweep 

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        if(n == 0) return true;

        map<int,int> mp;

        for(auto x : trips){
            int s = x[1];
            int e = x[2];
            int p = x[0];

            mp[s] += p;
            mp[e] -= p;
            
            int count = 0;
            for(auto &y : mp){
                count += y.second;
                if(count > capacity) return false;
            }
        }

        return true;
    }
};
