Problem Description
You have n courses numbered from 1 to n that you need to take. Some courses have prerequisites - you must complete certain courses before you can take others.

The prerequisite relationships are given as an array relations, where each element relations[i] = [prevCoursei, nextCoursei] means you must complete course prevCoursei before taking course nextCoursei.

In each semester, you can take as many courses as you want, as long as you've already completed all their prerequisites in previous semesters.

Your task is to find the minimum number of semesters needed to complete all n courses. If it's impossible to complete all courses (for example, due to circular dependencies), return -1.

Example scenarios:

If you have 3 courses and course 1 must be taken before course 2, and course 2 before course 3, you'd need 3 semesters (one course per semester due to the chain of dependencies).
If you have 3 courses where course 1 must be taken before both courses 2 and 3, you'd need 2 semesters (take course 1 in semester 1, then courses 2 and 3 together in semester 2).
If there's a circular dependency (course 1 requires course 2, and course 2 requires course 1), it's impossible to complete all courses, so return -1.
The solution uses topological sorting with BFS to process courses level by level, where each level represents one semester. Courses with no prerequisites can be taken immediately, and as courses are completed, they unlock other courses for future semesters.


This is a classic Topological Sort (Kahn's BFS) problem where each BFS level = one semester.

Intuition

Suppose

1 → 2 → 3

Initially,

indegree

1 : 0
2 : 1
3 : 1

Semester 1:

Take 1

Semester 2:

Take 2

Semester 3:

Take 3

Answer = 3 semesters

Now consider

     1
    / \
   2   3

Initially

indegree

1 : 0
2 : 1
3 : 1

Semester 1

Take {1}

Now both become available.

Semester 2

Take {2,3}

Answer = 2 semesters

Algorithm
Step 1: Build graph
u → v

means

u must be finished before v

Store

adj[u].push_back(v);
indegree[v]++;
Step 2: Push all courses with indegree 0

These have no prerequisites.

Queue

1 5 7

All these can be taken in the first semester.

Step 3: BFS Level Order

This is the important part.

while(!q.empty())
{
    int sz = q.size();

    semester++;

    while(sz--)
    {
        ...
    }
}

Notice

Queue

1 5 7

All three are processed together.

That means

Semester 1

Take

1
5
7

Only after finishing the entire semester do new courses become available.

Suppose graph

1 → 3
5 → 3
7 → 4

Initially

Queue

1 5 7

Semester 1

Take

1
5
7

Now

Queue

3 4

Semester 2

Take

3
4

Exactly as required.

Why do we process one level at a time?

Because

In one semester, every available course can be taken simultaneously.

So every BFS level represents

One Semester
Complete Code


class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {

        vector<vector<int>> adj(n + 1);
        vector<int> indegree(n + 1, 0);

        // Build graph
        for (auto &edge : relations) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;

        // Courses with no prerequisites
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        int semester = 0;
        int completed = 0;

        while (!q.empty()) {

            int sz = q.size();

            semester++;

            while (sz--) {

                int node = q.front();
                q.pop();

                completed++;

                for (int nei : adj[node]) {

                    indegree[nei]--;

                    if (indegree[nei] == 0)
                        q.push(nei);
                }
            }
        }

        if (completed != n)
            return -1;

        return semester;
    }
};


Dry Run
Input
n = 4

1 → 3
2 → 3
3 → 4
Initial indegree
Course	Indegree
1	0
2	0
3	2
4	1

Queue

1 2
Semester 1

Take

1
2

Now

indegree[3] = 0

Queue

3
Semester 2

Take

3

Now

indegree[4] = 0

Queue

4
Semester 3

Take

4

Queue becomes empty.

Answer

3
Complexity
Time: O(V + E) (each course and prerequisite is processed once)
Space: O(V + E) (adjacency list, indegree array, and queue)

The key insight is that BFS is performed level by level, and each level corresponds to one semester, since all currently available courses can be taken in parallel.
