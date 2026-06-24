// Course Schedule I 

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.



class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        int n = pre.size();

        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);

        for(int i=0;i<n;i++){

            int v = pre[i][0];
            int u = pre[i][1];

            adj[u].push_back(v);

            indegree[v]++;
        }

        queue<int> q;
        int count = 0;

        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0){
                q.push(i);
                count++;
            }
        }

        while(q.size()){

            int front = q.front();
            q.pop();

            for(auto neigh : adj[front]){

                indegree[neigh]--;
                if(indegree[neigh] == 0){
                    q.push(neigh);
                    count++;
                }

            }
        }

        return numCourses == count;
    }
};

// Course Schedule II

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers,
return any of them. If it is impossible to finish all courses, return an empty array.

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        int n = pre.size();

        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);

        for(int i=0;i<n;i++){

            int v = pre[i][0];
            int u = pre[i][1];

            adj[u].push_back(v);

            indegree[v]++;
        }

        queue<int> q;
        vector<int> ans;

        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(q.size()){

            int front = q.front();
            q.pop();

            ans.push_back(front);

            for(auto neigh : adj[front]){

                indegree[neigh]--;
                if(indegree[neigh] == 0){
                    q.push(neigh);
                }

            }
        } 

        return (ans.size() == numCourses) ? ans : vector<int>();
        
    }
};

