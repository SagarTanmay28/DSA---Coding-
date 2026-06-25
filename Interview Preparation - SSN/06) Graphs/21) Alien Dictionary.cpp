A new alien language uses the English alphabet, but the order of letters is unknown. You are given a list of words[] from the alien language’s dictionary, where the words are claimed to be sorted lexicographically according to the language’s rules.

Your task is to determine the correct order of letters in this alien language based on the given words. If the order is valid, return a string containing the unique letters in lexicographically increasing order as per the new language's rules. If there are multiple valid orders, return any one of them.

However, if the given arrangement of words is inconsistent with any possible letter ordering, return an empty string ("").

A string a is lexicographically smaller than a string b if, at the first position where they differ, the character in a appears earlier in the alien language than the corresponding character in b. If all characters in the shorter word match the beginning of the longer word, the shorter word is considered smaller.

Note: Your implementation will be tested using a driver code. It will print true if your returned order correctly follows the alien language’s lexicographic rules; otherwise, it will print false.

Examples:

Input: words[] = ["baa", "abcd", "abca", "cab", "cad"]
Output: true
Explanation: A possible correct order of letters in the alien dictionary is "bdac".
The pair "baa" and "abcd" suggests 'b' appears before 'a' in the alien dictionary.
The pair "abcd" and "abca" suggests 'd' appears before 'a' in the alien dictionary.
The pair "abca" and "cab" suggests 'a' appears before 'c' in the alien dictionary.
The pair "cab" and "cad" suggests 'b' appears before 'd' in the alien dictionary.
So, 'b' → 'd' → 'a' → 'c' is a valid ordering.
Input: words[] = ["caa", "aaa", "aab"]
Output: true
Explanation: A possible correct order of letters in the alien dictionary is "cab".
The pair "caa" and "aaa" suggests 'c' appears before 'a'.
The pair "aaa" and "aab" suggests 'a' appear before 'b' in the alien dictionary. 
So, 'c' → 'a' → 'b' is a valid ordering.
Input: words[] = ["ab", "cd", "ef", "ad"]
Output: ""
Explanation: No valid ordering of letters is possible.
The pair "ab" and "ef" suggests "a" appears before "e".
The pair "ef" and "ad" suggests "e" appears before "a", which contradicts the ordering rules.
Constraints:
1 ≤ words.length ≤ 500
1 ≤ words[i].length ≤ 100
words[i] consists only of lowercase English letters.



// Optimized Code :: 

class Solution {
public:
    string findOrder(vector<string> &words) {
        
        vector<vector<int>> adj(26);
        vector<int> indegree(26, 0);
        vector<bool> present(26, false);

        // Mark all characters present in the dictionary
        for (auto &word : words) {
            for (char ch : word) {
                present[ch - 'a'] = true;
            }
        }

        int n = words.size();

        for (int i = 0; i < n - 1; i++) {
            string &s = words[i];
            string &t = words[i + 1];

            int n1 = s.size();
            int n2 = t.size();

            // Invalid case
            if (n1 > n2 && s.substr(0, n2) == t)
                return "";

            int len = min(n1, n2);

            for (int j = 0; j < len; j++) {
                if (s[j] != t[j]) {

                    int u = s[j] - 'a';
                    int v = t[j] - 'a';

                    // Avoid duplicate edges
                    bool found = false;
                    for (int x : adj[u]) {
                        if (x == v) {
                            found = true;
                            break;
                        }
                    }

                    if (!found) {
                        adj[u].push_back(v);
                        indegree[v]++;
                    }

                    break;
                }
            }
        }

        queue<int> q;

        for (int i = 0; i < 26; i++) {
            if (present[i] && indegree[i] == 0)
                q.push(i);
        }

        string ans;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            ans += char(u + 'a');

            for (int v : adj[u]) {
                indegree[v]--;

                if (indegree[v] == 0)
                    q.push(v);
            }
        }

        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            if (present[i]) cnt++;
        }

        if (ans.size() != cnt)
            return "";

        return ans;
    }
};


// My Code :: Passed 

class Solution {
public:
    string findOrder(vector<string> &words) {
        
        vector<vector<int>> adj(26);
        vector<int> indegree(26, 0);
        vector<bool> present(26, false);

        // Mark all characters present in the dictionary
        for (auto &word : words) {
            for (char ch : word) {
                present[ch - 'a'] = true;
            }
        }

        int n = words.size();

        for (int i = 0; i < n - 1; i++) {
            string &s = words[i];
            string &t = words[i + 1];

            int n1 = s.size();
            int n2 = t.size();

            // Invalid case
            if (n1 > n2 && s.substr(0, n2) == t)
                return "";

            int len = min(n1, n2);

            for (int j = 0; j < len; j++) {
                if (s[j] != t[j]) {

                    int u = s[j] - 'a';
                    int v = t[j] - 'a';

                    // Avoid duplicate edges
                    bool found = false;
                    for (int x : adj[u]) {
                        if (x == v) {
                            found = true;
                            break;
                        }
                    }

                    if (!found) {
                        adj[u].push_back(v);
                        indegree[v]++;
                    }

                    break;
                }
            }
        }

        queue<int> q;

        for (int i = 0; i < 26; i++) {
            if (present[i] && indegree[i] == 0)
                q.push(i);
        }

        string ans;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            ans += char(u + 'a');

            for (int v : adj[u]) {
                indegree[v]--;

                if (indegree[v] == 0)
                    q.push(v);
            }
        }

        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            if (present[i]) cnt++;
        }

        if (ans.size() != cnt)
            return "";

        return ans;
    }
};
