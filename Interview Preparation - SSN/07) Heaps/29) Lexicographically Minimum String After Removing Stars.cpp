You are given a string s. It may contain any number of '*' characters. Your task is to remove all '*' characters.

While there is a '*', do the following operation:

Delete the leftmost '*' and the smallest non-'*' character to its left. If there are several smallest characters, you can delete any of them.
Return the lexicographically smallest resulting string after removing all '*' characters.

 

Example 1:

Input: s = "aaba*"

Output: "aab"

Explanation:

We should delete one of the 'a' characters with '*'. If we choose s[3], s becomes the lexicographically smallest.

Example 2:

Input: s = "abc"

Output: "abc"

Explanation:

There is no '*' in the string.



class Solution {
public:
    typedef pair<char,int> p;
    
    struct cmp{
        bool operator()(pair<char,int>& a, pair<char,int>& b){
            if(a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        }

    };
    string clearStars(string s) {
        int n = s.size();
        priority_queue<p,vector<p>,cmp> pq;

        for(int i=0;i<n;i++){
            if(s[i] != '*') pq.push({s[i],i});
            else{
                auto x = pq.top();
                pq.pop();
                char ch = x.first;
                int idx = x.second;

                s[idx] = '*';
            }
        }

        string ans = "";
        for(int i=0;i<n;i++){
            if(s[i] != '*') ans += s[i];
        }

        return ans;

    }
};

// Comparator Explanation ::

1st priority -> smaller character
2nd priority -> larger index

Meaning heap top should become:

smallest char + largest index
VERY IMPORTANT

In priority_queue comparator:

return true

means:

a has LOWER priority than b

NOT "a should come first".

This changes everything.

Part 1
return a.first > b.first;

Suppose:

a = {'b',1}
b = {'a',5}

Then:

'b' > 'a'

TRUE.

Meaning:

'b' has LOWER priority

So 'a' stays on top.

Thus:

smaller characters get higher priority

Exactly what we want.

Part 2 (Tie Case)
return a.second < b.second;

Suppose:

a = {'a',2}
b = {'a',5}

Then:

2 < 5

TRUE.

Meaning:

index 2 has LOWER priority

So:

index 5 stays on top

Thus:

larger index gets higher priority

Exactly what problem wants.
