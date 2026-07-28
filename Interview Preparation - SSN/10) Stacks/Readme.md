
# Stack & Monotonic Stack — LeetCode Problem Set

A curated, pattern-wise collection of Stack-based LeetCode problems with problem statements, examples, intuition, and complete C++ solutions.

## Table of Contents

1. [Basic Stack Simulation](#1-basic-stack-simulation)
   - [Implement Queue using Stacks](#implement-queue-using-stacks)
   - [Build an Array With Stack Operations](#build-an-array-with-stack-operations)
2. [Parentheses / Bracket Problems](#2-parentheses--bracket-problems)
   - [Valid Parentheses](#valid-parentheses)
   - [Minimum Add to Make Parentheses Valid](#minimum-add-to-make-parentheses-valid)
   - [Minimum Deletions to Make String Balanced](#minimum-deletions-to-make-string-balanced)
   - [Minimum Number of Swaps to Make the String Balanced](#minimum-number-of-swaps-to-make-the-string-balanced)
   - [Check if a Parentheses String Can Be Valid](#check-if-a-parentheses-string-can-be-valid)
   - [Maximum Nesting Depth of the Parentheses](#maximum-nesting-depth-of-the-parentheses)
   - [Reverse Substrings Between Each Pair of Parentheses](#reverse-substrings-between-each-pair-of-parentheses)
3. [Monotonic Stack](#3-monotonic-stack)
   - [Daily Temperatures](#daily-temperatures)
   - [Online Stock Span](#online-stock-span)
   - [132 Pattern](#132-pattern)
   - [Sum of Subarray Minimums](#sum-of-subarray-minimums)
   - [Largest Rectangle in Histogram](#largest-rectangle-in-histogram)
   - [Maximal Rectangle](#maximal-rectangle)
   - [Trapping Rain Water (using stack)](#trapping-rain-water-using-stack)
   - [Remove K Digits](#remove-k-digits)
   - [Final Prices With a Special Discount in a Shop](#final-prices-with-a-special-discount-in-a-shop)
   - [Maximum Width Ramp](#maximum-width-ramp)
   - [Minimum Operations to Convert All Elements to Zero](#minimum-operations-to-convert-all-elements-to-zero)
4. [String Building with a Stack](#4-string-building-with-a-stack)
   - [Remove All Adjacent Duplicates In String](#remove-all-adjacent-duplicates-in-string)
   - [Removing Stars From a String](#removing-stars-from-a-string)
   - [Remove All Occurrences of a Substring](#remove-all-occurrences-of-a-substring)
   - [Clear Digits](#clear-digits)
   - [Maximum Score From Removing Substrings](#maximum-score-from-removing-substrings)
5. [Expression Evaluation](#5-expression-evaluation)
   - [Basic Calculator](#basic-calculator)
   - [Evaluate Reverse Polish Notation](#evaluate-reverse-polish-notation)
   - [Number of Atoms](#number-of-atoms)
   - [Parsing A Boolean Expression](#parsing-a-boolean-expression)
6. [Path / Log Simulation](#6-path--log-simulation)
   - [Simplify Path](#simplify-path)
   - [Crawler Log Folder](#crawler-log-folder)
7. [Collision / Merge Simulation](#7-collision--merge-simulation)
   - [Asteroid Collision](#asteroid-collision)
   - [Robot Collisions](#robot-collisions)
   - [Replace Non-Coprime Numbers in Array](#replace-non-coprime-numbers-in-array)
8. [Sequence Validation](#8-sequence-validation)
   - [Validate Stack Sequences](#validate-stack-sequences)

---

## 1. Basic Stack Simulation

### Implement Queue using Stacks

**LeetCode:** https://leetcode.com/problems/implement-queue-using-stacks/

**Problem:** Implement a first-in-first-out (FIFO) queue using only two stacks. The implemented queue should support `push`, `pop`, `peek`, and `empty`, using only the standard stack operations (push, pop, top, size, is empty).

**Example:**
```
Input:  ["MyQueue", "push", "push", "peek", "pop", "empty"]
        [[], [1], [2], [], [], []]
Output: [null, null, null, 1, 1, false]
```

**Intuition:** Maintain two stacks — `input` for pushes and `output` for pops/peeks. When `pop`/`peek` is called and `output` is empty, dump everything from `input` into `output`, which reverses the order and gives FIFO behavior. This gives amortized O(1) for `pop`. A separate `peekEl` variable tracks the front element cheaply while items still sit only in `input`.

```cpp
#include <bits/stdc++.h>

using namespace std;

/*                                             SCROLL BELOW FOR JAVA CODE ALSO                                         */
/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=V1vqtGW0X0Y
      Company Tags                : Google, Amazon, Microsoft, Meta 
      Leetcode Link               : https://leetcode.com/problems/implement-queue-using-stacks/
      GfG Link                    : https://practice.geeksforgeeks.org/problems/queue-using-stack/1
*/


/************************************************************************ C++ ************************************************************************/
//T.C : push - O(1), pop - Amortized O(1) , peek() - O(1), empty() - O(1)
//S.C : O(n)
class MyQueue {
public:
    
    stack<int> input;
    stack<int> output;
    int peekEl = -1;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        if(input.empty()) {
            peekEl = x;
        }
        input.push(x); //ye to har baar karna hai
    }
    //amortized O(1)
    int pop() {
        if(output.empty()) {
            //input -> output O(n)
            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        
        int val = output.top(); //O(1)
        output.pop();
        return val;
    }
    
    int peek() {
        if(output.empty())
            return peekEl;
        
        return output.top();
    }
    
    bool empty() {
        if(input.empty() && output.empty())
            return true;
        
        return false;
    }
};
```

---

### Build an Array With Stack Operations

**LeetCode:** https://leetcode.com/problems/build-an-array-with-stack-operations/

**Problem:** Given a target array and an integer `n` (stream `1..n`), return the list of stack operations (`"Push"`, `"Pop"`) needed to build `target` using an initially empty stack, reading `1` to `n` one at a time.

**Example:**
```
Input:  target = [1,3], n = 3
Output: ["Push","Push","Pop","Push"]
```

**Intuition:** Walk the stream `1..n`. Always `Push` the current number. If it matches the next value we need in `target`, keep it and move to the next target index; otherwise immediately `Pop` it. Stop once `target` is fully built.

```cpp
#include <bits/stdc++.h>

using namespace std;

/*         Scroll below to see JAVA code as well        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=nmNLu1Qz-C0
    Company Tags                : Google, Adobe
    Leetcode Link               : https://leetcode.com/problems/build-an-array-with-stack-operations/
*/

/************************************************** C++ **************************************************/
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int stream = 1;
        
        vector<string> result;
        
        int i = 0;
        while(i < target.size() && stream <= n) {
            result.push_back("Push");
            
            if(stream == target[i]) {
                i++;
            } else {
                result.push_back("Pop");
            }
            stream++;
        }
        
        return result;
    }
};
```

---

## 2. Parentheses / Bracket Problems

### Valid Parentheses

**LeetCode:** https://leetcode.com/problems/valid-parentheses/

**Problem:** Given a string containing just the characters `(`, `)`, `{`, `}`, `[`, `]`, determine if the input string is valid — every opening bracket must be closed by the same type of bracket, in the correct order.

**Example:**
```
Input:  s = "()[]{}"
Output: true

Input:  s = "(]"
Output: false
```

**Intuition:** Push opening brackets onto a stack. On a closing bracket, check whether the stack's top matches its corresponding opener; if not (or the stack is empty), the string is invalid. At the end the stack must be empty. An elegant variant pushes the *expected closing bracket* itself, so a closer just needs to equal `st.top()`.

```cpp
#include <bits/stdc++.h>

using namespace std;

/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=3ssh_mk4LqY
    Company Tags                : Google, Meta, Adobe, Amazon, OYO, Microsoft
    Leetcode Link               : https://leetcode.com/problems/valid-parentheses/
*/

//Approach-1 (Simple and basic approach using stack)
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(char ch:s) {
            if(st.empty() || ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
                continue;
            }
            
            if(ch == ')') {
                if(st.top() == '(')
                    st.pop();
                else
                    return false;
            } else if(ch == '}') {
                if(st.top() == '{')
                    st.pop();
                else
                    return false;
            } else if(ch == ']') {
                if(st.top() == '[')
                    st.pop();
                else
                    return false;
            }
        }
        
        return st.empty();
    }
};

//Approach-2 (Tricky)
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(char ch:s) {
            if (ch == '(')
			    st.push(')');
		    else if (ch == '{')
			    st.push('}');
            else if (ch == '[')
                st.push(']');
            else if (st.empty() || st.top() != ch)
                return false;
            else {
                st.pop();
            }
        }
        
        return st.empty();
    }
};
```

---

### Minimum Add to Make Parentheses Valid

**LeetCode:** https://leetcode.com/problems/minimum-add-to-make-parentheses-valid

**Problem:** Given a string `s` of `(` and `)`, find the minimum number of parentheses you must add to make it valid.

**Example:**
```
Input:  s = "())"
Output: 1
```

**Intuition:** Track unmatched `(` using a stack (or a counter). Every `)` either closes an existing unmatched `(` or, if there is none, becomes an unmatched `)` that needs a future `(` inserted. At the end, the leftover unmatched `)` count plus leftover unmatched `(` count is the answer.

```cpp
#include <bits/stdc++.h>

using namespace std;

/*     Scroll below to see JAVA code also   */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=lIdHFWyIrYE
    Company Tags                : Meta
    Leetcode Link               : https://leetcode.com/problems/minimum-add-to-make-parentheses-valid
*/


/********************************************************************** C++ **********************************************************************/
//Approach-1 (Using stack)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int open = 0;
        
        for(char &ch : s) {
            if(ch == '(')
                st.push(ch);
            else if(!st.empty())
                st.pop();
            else
                open++;
        }
        
        return open + st.size();
    }
};


//Approach-2 (without using stack)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int minAddToMakeValid(string s) {
        int size = 0;
        int open = 0;

        for(char &ch : s) {
            if(ch == '(') {
                size++;
            } else if(size > 0) {
                size--;
            } else {
                open++;
            }
        }

        return open + size;
    }
};
```

---

### Minimum Deletions to Make String Balanced

**LeetCode:** https://leetcode.com/problems/minimum-deletions-to-make-string-balanced

**Problem:** Given a string `s` of `'a'` and `'b'` characters, a string is balanced if there is no `'a'` after a `'b'`. Return the minimum number of deletions to make `s` balanced.

**Example:**
```
Input:  s = "aababbab"
Output: 2
```

**Intuition (stack approach):** Push characters onto a stack; whenever the current character is `'a'` but the stack top is `'b'`, that's an "out of place" `'a'` — delete it (count++) instead of pushing, since deleting the `'a'` fixes that one violation cheaply. Other approaches precompute, for every index, the number of `'b'`s to its left and `'a'`s to its right, and minimize their sum.

```cpp
#include <bits/stdc++.h>

using namespace std;

/*     Scroll below to see JAVA code also   */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=gorAMHTwDfU
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/minimum-deletions-to-make-string-balanced
*/

/********************************************************************** C++ **********************************************************************/
//Approach-1 (Using stack)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int minimumDeletions(string s) {
        int n     = s.length();
        int count = 0;

        stack<char> st;

        for(int i = 0; i < n; i++) {
            if(!st.empty() && s[i] == 'a' && st.top() == 'b') { //'ba'
                st.pop();
                count++;
            } else {
                st.push(s[i]);
            }
        }

        return count;
    }
};


//Approach-2 (3 Pass + O(2*n) space)
//T.C : O(3*n)
//S.C : O(2*n)
class Solution {
public:
    int minimumDeletions(string s) {
        int n     = s.length();
        
        vector<int> left_b(n, 0);
        vector<int> right_a(n, 0);

        int countb = 0;
        for(int i = 0; i < n; i++) {
            left_b[i] = countb;
            if(s[i] == 'b')
                countb++;
        }

        int counta = 0;
        for(int i = n-1; i >= 0; i--) {
            right_a[i] = counta;
            if(s[i] == 'a')
                counta++;
        }

        int count = INT_MAX;
        for(int i = 0; i < n; i++) {
            count = min(count, left_b[i] + right_a[i]);
        }

        return count;
    }
};


//Approach-3 (2 Pass + O(n) space)
//T.C : O(2*n)
//S.C : O(n)
class Solution {
public:
    int minimumDeletions(string s) {
        int n     = s.length();
        
        vector<int> right_a(n, 0);

        
        int counta = 0;
        for(int i = n-1; i >= 0; i--) {
            right_a[i] = counta;
            if(s[i] == 'a')
                counta++;
        }

        int count = INT_MAX;
        int countb = 0;

        for(int i = 0; i < n; i++) {
            count = min(count, countb + right_a[i]);
            if(s[i] == 'b')
                countb++;
        }

        return count;



    }
};


//Approach-4 (Constant space)
//T.C : O(2*n)
//S.C : O(1)
class Solution {
public:
    int minimumDeletions(string s) {
        int n     = s.length();

        
        int counta = 0;
        for(int i = n-1; i >= 0; i--) {
            if(s[i] == 'a')
                counta++;
        }

        int count = INT_MAX;
        int countb = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] == 'a')
                counta--;
            count = min(count, countb + counta);

            if(s[i] == 'b')
                countb++;
        }

        return count;
    }
};
```

---

### Minimum Number of Swaps to Make the String Balanced

**LeetCode:** https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced

**Problem:** Given a balanced (equal count) string `s` of `[` and `]`, find the minimum number of adjacent-style swaps needed to make it a valid bracket sequence (any two characters may be swapped, not just adjacent).

**Example:**
```
Input:  s = "][]["
Output: 1
```

**Intuition:** Simulate with a stack (or counter) of open brackets `[`. Every `]` either matches an open `[` (pop) or, if the stack is empty, is an unmatched close bracket. At the end, the number of leftover unmatched items (which come in `][` pairs) divided appropriately gives `(unmatched + 1) / 2` swaps — each swap fixes two mismatches at once.

```cpp
#include <bits/stdc++.h>

using namespace std;

/*     Scroll below to see JAVA code also   */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=W61jIP-O8lw
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced
*/


/********************************************************************** C++ **********************************************************************/
//Approach-1 (Using stack)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        
        for(char &ch : s) {
            if(ch == '[')
                st.push(ch);
            else if(!st.empty())
                st.pop();
        }
        
        return (st.size()+1)/2;
    }
};


//Approach-2 (without using stack)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int minSwaps(string s) {
        int size = 0;
        
        for(char &ch : s) {
            if(ch == '[')      
              size++;
            else if(size != 0)
              size--;
        }
        
        return (size+1)/2;
    }
};
```

---

### Check if a Parentheses String Can Be Valid

**LeetCode:** https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid

**Problem:** Given a parentheses string `s` and a binary `locked` string (a `'0'` at a position means that character in `s` can be freely changed to `(` or `)`), determine whether `s` can be made valid.

**Example:**
```
Input:  s = "))()))", locked = "010100"
Output: true
```

**Intuition:** Length must be even. Use two stacks of indices: one for locked `(`, one for unlocked (changeable) positions. On a `)`, prefer closing a locked `(` first, else consume an unlocked slot as a "virtual `(`". Finally, match remaining locked `(`s against unlocked slots that occur *after* them (since an unlocked slot before an unmatched `(` can't act as its closer). The no-stack variant does two linear passes — left-to-right ensures enough potential openers, right-to-left ensures enough potential closers.

```cpp
#include <bits/stdc++.h>

using namespace std;

/*     Scroll below to see JAVA code also   */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Xw8SkHIu2bI
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid
*/


/********************************************************************** C++ **********************************************************************/
//Approach-1 (Using stack)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();

        if(n%2 != 0) { //odd
            return false;
        }

        stack<int> open;
        stack<int> openClose;

        for(int i = 0; i < n; i++) {
            if(locked[i] == '0') {
                openClose.push(i);
            } else if(s[i] == '(') {
                open.push(i);
            } else if(s[i] == ')') {
                if(!open.empty()) {
                    open.pop();
                } else if(!openClose.empty()) {
                    openClose.pop();
                } else {
                    return false;
                }
            }
        }

        while(!open.empty() && !openClose.empty() && open.top() < openClose.top()) {
            open.pop();
            openClose.pop();
        }


        return open.empty(); //true

    }
};


//Approach-2 (Without using stack)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();

        if(n%2 != 0) { //odd
            return false;
        }

        //L to R
        int open = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(' || locked[i] == '0') {
                open++;
            } else {
                open--;
            }

            if(open < 0) {
                return false;
            }
        }

        //R to L
        int close = 0;
        for(int i = n-1; i >= 0; i--) {
            if(s[i] == ')' || locked[i] == '0') {
                close++;
            } else {
                close--;
            }

            if(close < 0) {
                return false;
            }
        }

        return true;

    }
};
```

---

### Maximum Nesting Depth of the Parentheses

**LeetCode:** https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

**Problem:** Given a valid parentheses string `s` (may contain other characters too, per the general problem family), return the maximum nesting depth of the parentheses.

**Example:**
```
Input:  s = "(1+(2*3)+((8)/4))+1"
Output: 3
```

**Intuition:** A stack of `(` naturally represents current nesting depth — its size *is* the depth at any point. Push on `(`, pop on `)`, and track the maximum size seen. This can be simplified to a single counter since we never need to inspect stack contents, only its size.

```cpp
#include <bits/stdc++.h>

using namespace std;

/*     Scroll down to see jAVA code also   */
/*
    MY YOUTBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=uzP77oJVLos
    Company Tags               : will update soon
    Leetcode Link              : https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
*/

/******************************************************************* C++ ***********************************************************************/
//Approach-1 (using stack)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int maxDepth(string s) {
        int result = 0;

        stack<char> st;
        
        for (char& ch : s) {
            
            if (ch == '(') {
                st.push(ch);
            } else if (ch == ')') {
                st.pop();
            }
            
            result = max(result, (int)st.size());
        }
        
        return result;
    }
};


//Approach-2 (using constant space)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maxDepth(string s) {
        int result = 0;
        int openBrackets = 0;

        for (char &ch : s) {
            if (ch == '(') {
                openBrackets++;
            } else if (ch == ')') {
                openBrackets--;
            }
            
            result = max(result, openBrackets);
        }
        
        return result;
    }
};
```

---

### Reverse Substrings Between Each Pair of Parentheses

**LeetCode:** https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description

**Problem:** Given a string `s` with lowercase letters and parentheses, reverse the string inside each pair of matching parentheses (starting from the innermost), then return the final string with no brackets.

**Example:**
```
Input:  s = "(u(love)i)"
Output: "iloveu"
```

**Intuition (brute force):** Track the starting position (in the output built so far) of each `(` on a stack; when a `)` is hit, reverse the output substring from that saved index onward — this is O(n²) in the worst case due to repeated reversals.
**Intuition (linear):** Precompute a "door" mapping between every matched `(` and `)` (like a wormhole). Walk the string; on hitting any bracket, teleport to its partner and flip the walking direction. Non-bracket characters are appended directly. This achieves each character being visited O(1) times → O(n).

```cpp
#include <bits/stdc++.h>

using namespace std;

/*    Scroll below to see JAVA code also      */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=dUQRS4luBvA
    Company Tags                : META, AMAZON
    Leetcode Link               : https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description
*/


/************************************************************ C++ ************************************************************/
//Approach-1 (Brute Force)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> openeBracket; //You can use a vector also as stack
        string result;
        for (char currentChar : s) {
            if (currentChar == '(') {
                openeBracket.push(result.length());
            } else if (currentChar == ')') {
                int start = openeBracket.top();
                openeBracket.pop();
                reverse(result.begin() + start, result.end());
            } else {
                result += currentChar;
            }
        }
        return result;
    }
};


//Approach-2 (Linear Approach)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        stack<int> openBracket;
        vector<int> door(n);

        // First pass: Pair up parentheses
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                openBracket.push(i);
            } else if (s[i] == ')') {
                int j = openBracket.top();
                openBracket.pop();
                door[i] = j;
                door[j] = i;
            }
        }

        // Second pass: Build the result string
        string result;
        int direction = 1; //Left to Right
        for (int i = 0; i < n; i += direction) {
            if (s[i] == '(' || s[i] == ')') {
                i = door[i];
                direction = -direction;
            } else {
                result += s[i];
            }
        }
        return result;
    }
};
```

---

## 3. Monotonic Stack

### Daily Temperatures

**LeetCode:** https://leetcode.com/problems/daily-temperatures/

**Problem:** Given daily temperatures, for each day return the number of days you'd have to wait until a warmer temperature. If there's no future warmer day, put `0`.

**Example:**
```
Input:  temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
```

**Intuition:** Classic "next greater element" pattern. Traverse right to left keeping a monotonic decreasing stack of *indices*. Before pushing the current index, pop off all indices whose temperature is ≤ current (they can never be the answer for anything further left, since the current, closer, warmer day dominates). The new top (if any) is the next warmer day.

```cpp
#include <bits/stdc++.h>

using namespace std;

/**                                                SCROLL BELOW TO SEE JAVA CODE ALSO                                        **/

/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=ZhZEmGv-sOY
    Company Tags                : Google, Meta, Tokopedia
    Leetcode Link               : https://leetcode.com/problems/daily-temperatures/
*/


/******************************************************************** C++ ********************************************************************/
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        
        vector<int> result(n);
        
        for(int i = n-1; i>=0; i--) {
            while(!st.empty() && temperatures[i] >= temperatures[st.top()]) {
                st.pop();
            }
            
            if(st.empty()) {
                result[i] = 0;
            } else {
                result[i] = st.top() - i; //days
            }
            
            st.push(i);
        }
        
        return result;
        
    }
};
```

---

### Online Stock Span

**LeetCode:** https://leetcode.com/problems/online-stock-span/

**Problem:** Design an algorithm that, given the price of a stock on the current day, returns its "span" — the number of consecutive days (including today) that the price has been less than or equal to today's price.

**Example:**
```
Input:  ["StockSpanner","next","next","next","next","next","next","next"]
        [[],[100],[80],[60],[70],[60],[75],[85]]
Output: [null,1,1,1,2,1,4,6]
```

**Intuition:** Keep a stack of `(price, span)` pairs. When a new price arrives, pop and absorb all previous entries whose price is ≤ the current price, accumulating their spans, since those days are now "covered" by today's higher price. Push the new `(price, totalSpan)`.

```cpp
#include <bits/stdc++.h>

using namespace std;

/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=IDC1rnr3vus
    Company Tags                : Microsoft, Accolite, Amazon, FactSet, Samsung, Adobe, Flipkart
    Leetcode Link               : https://leetcode.com/problems/online-stock-span/
    GfG Link                    : https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1
*/

class StockSpanner {
public:
    stack<pair<int, int>> st;
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;
        
        while(!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        
        st.push({price, span});
        return span;
    }
};
```

---

### 132 Pattern

**LeetCode:** https://leetcode.com/problems/132-pattern/

**Problem:** Given an array `nums`, find indices `i < j < k` such that `nums[i] < nums[k] < nums[j]` (a "1-3-2" pattern). Return `true` if such a triplet exists.

**Example:**
```
Input:  nums = [3,1,4,2]
Output: true   // (1, 4, 2)
```

**Intuition:** Scan from right to left maintaining a stack that stores candidates for `num2` (the largest of the triplet) and a running `num3` (the best "middle" value found so far, i.e. some value that was popped because a bigger number came before it). If the current number is less than `num3`, it can serve as `num1`, completing the pattern. Otherwise, while the current number is bigger than the stack top, pop it into `num3` (a valid `num3` is always < the popped `num2`), then push the current number as a new `num2` candidate.

```cpp
#include <bits/stdc++.h>

using namespace std;

/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=RZXxX1EU364
    Company Tags                : Amazon, META
    Leetcode Link               : https://leetcode.com/problems/132-pattern/
    Monotonic Data Structures Concepts Playlist - https://www.youtube.com/watch?v=yRyumGu_owg&list=PLpIkg8OmuX-IpUPXh3z8oeKSfRkKhjaTV
*/

/*********************************************************** C++ *********************************************/
//Approach-1
//T.C : O(n^3) - T.L.E : [94 / 103 test cases passed.]
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            
            for(int j = i+1; j<n; j++) {
                
                if(nums[j] > nums[i]) {
                    
                    for(int k = j+1; k<n; k++) {
                        if(nums[i] < nums[k] && nums[k] < nums[j] )
                            return true;
                    }
                    
                }
            }
        }
        return false;
    }
};


//Approach-2
//T.C : O(n^2) - T.L.E : [101 / 103 test cases passed.]
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int min_i = INT_MAX;
        int n = nums.size();
        for(int j = 0; j<n-1; j++) {
            min_i = min(min_i, nums[j]);
            for(int k = j+1; k<n; k++) {
                if(min_i < nums[k] && nums[k] < nums[j])
                    return true;
            }
        }
        return false;
    }
};

//Approach-3 --> Using Monotonic stack
//T.C : O(n) - We don't visit any element more than once
/*
    We are only storing one item in the stack, which is our ideal candidate for num2 (number that needs to be the largest). 
    If we find a number that is bigger than what we thought was our ideal candidate for num2; we pop out our stack 
    and store the value in num3 (mid value number), then we store the new ideal candidate for num2 in the stack. 
    On the next ith iteration, if nums[i] is actually less than s3, then we are done!
*/
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        //num1, num2, num3
        //num1 < num3 < num2
        int n  = nums.size();
        int num3 = INT_MIN;
        stack<int> st;
        
        for(int i = n-1; i >= 0; i--) {
            if(nums[i] < num3)
                return true;
            
            while(!st.empty() && nums[i] > st.top()) {
                num3 = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }

        return false;
    }
};
```

---

### Sum of Subarray Minimums

**LeetCode:** https://leetcode.com/problems/sum-of-subarray-minimums/

**Problem:** Given an array of integers `arr`, find the sum of `min(b)` over every contiguous subarray `b` of `arr`. Return the answer modulo `10^9 + 7`.

**Example:**
```
Input:  arr = [3,1,2,4]
Output: 17
```

**Intuition:** Each element `arr[i]` is the minimum of exactly `d1 * d2` subarrays, where `d1` is the distance to the previous strictly-smaller element (its "domain" to the left) and `d2` is the distance to the next smaller-or-equal element (to the right, using non-strict to avoid double counting duplicates). Compute Next Smaller to Left (NSL) and Next Smaller to Right (NSR) in O(n) each with a monotonic stack, then sum `arr[i] * d1 * d2` for every index.

```cpp
#include <bits/stdc++.h>

using namespace std;

/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=HRQB7-D2bi0
    Company Tags                : Facebook, Amazon, Google
    Leetcode Link               : https://leetcode.com/problems/sum-of-subarray-minimums/
*/


/****************************************************************** C++ ******************************************************************/
//Approach-1 (Simple Brute Force) - TLE
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    int M = 1e9 + 7;
    int sumSubarrayMins(std::vector<int>& arr) {
        int n = arr.size();
        long result = 0;

        for (int i = 0; i < n; i++) {
            int minVal = arr[i];

            for (int j = i; j < n; j++) {
                minVal = min(minVal, arr[j]);
                result = (result + minVal) % M;
            }
        }

        return result;
    }
};


    
/*
    First see the code and video to understand, then read this paragraph.
    
    Explanation on why we have done "strictly less" in one case and "non-strictly less"
    in another. (They can be interchanged but both can't be non-strictly less)
    
    Ans : This it to avoid repeated inclusion of same subarray
          s . . . m1 . . . . . m2 . . . s’
          ....r1 ...... r2 ........ r3

Basically we have A[s] is the PLE of A[m1] (strictly less), and all the elements in-between
which I denote by r1 is greater than A[m1]. A[m1] == A[m2], and all elements in-between
which I denote by r2 are greater, and A[s'] is the NLE of A[m2] (strictly less), and again all
elements in-between which I denote by r3 are greater.

If we used the strictly less definition for both PLE and NLE, then A[s] and A[s'] are the PLE
and NLE for both A[m1] and A[m2]. m1 will count [r1, r2] and m2 will count [r2, r3], but
both will count [r1, r3]. To avoid this, notice our definition of NLE is less than or equal.
So that means NLE of A[m1] is A[m2]. This means [r1, r3] is only counted once.
*/

//Approach-2
//T.C : O(n)
//S.C : O(n)
typedef unsigned long long ll;
class Solution {
public:
    
    //This is just we are finding next smaller to each element to left
    //Similar : Leetcode-84
    vector<int> getNSL(vector<int>& arr, int n) {
        vector<int> result(n);
        stack<int> st;
        
        for(int i = 0; i<n; i++) {
            if(st.empty()) {
                result[i] = -1;
            } else {
                while(!st.empty() && arr[st.top()] > arr[i]) //strictly less
                    st.pop();
                
                result[i] = st.empty() ? -1 : st.top();
            }
            st.push(i);
        }
        
        return result;
    }
    
    //This is just we are finding next smaller to each element to right
    //Similar : Leetcode-84
    vector<int> getNSR(vector<int>& arr, int n) {
        vector<int> result(n);
        stack<int> st;
        
        for(int i = n-1; i>=0; i--) {
            if(st.empty()) {
                result[i] = n;
            } else {
                while(!st.empty() && arr[st.top()] >= arr[i]) //non-strictly less
                    st.pop();
                
                result[i] = st.empty() ? n : st.top();
            }
            st.push(i);
        }
        
        return result;
    }
    
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> NSL = getNSL(arr, n); //Next smaller to left
        vector<int> NSR = getNSR(arr, n); //Next smaller to right
        
        
        ll sum = 0;
        int M = 1e9+7;
        for(int i = 0; i<n; i++) {
            ll d1 = i - NSL[i]; //distance to nearest smaller to left from i
            
            ll d2 = NSR[i] - i; //distance to nearest smaller to right from i
            
            /*
                we have d1 numbers in the left and d2 numbers in the right
                i.e. We have d1 options to start from the left of arr[i] 
                and d2 options to end in the right of arr[i]
                so the total options to start and end are d1*d2
            */
            ll total_ways_for_i_min = d1*d2;
            ll sum_i_in_total_ways  = arr[i] * (total_ways_for_i_min);
            
            sum  = (sum + sum_i_in_total_ways)%M;
        }
        
        return sum;
        
    }
};
```

---

### Largest Rectangle in Histogram

**LeetCode:** https://leetcode.com/problems/largest-rectangle-in-histogram/

**Problem:** Given an array of bar heights forming a histogram, find the area of the largest rectangle that fits entirely within it.

**Example:**
```
Input:  heights = [2,1,5,6,2,3]
Output: 10
```

**Intuition:** For every bar, its maximum possible rectangle height is `heights[i]`, bounded on each side by the nearest strictly-smaller bar (NSL/NSR). Compute both boundaries with a monotonic increasing stack, then the area for bar `i` is `heights[i] * (right[i] - left[i] - 1)`. A simplified single-pass version pushes indices while heights are non-decreasing and, on a decrease, pops and finalizes rectangles on the fly, using the current index and the new stack top as the right/left bounds.

```cpp
#include <bits/stdc++.h>

using namespace std;

/*
    Company Tags  : Amazon, MAQ Software, Paytm, Snapdeal
    Leetcode Link : https://leetcode.com/problems/largest-rectangle-in-histogram/
    Monotonic Data Structures Concepts Playlist - https://www.youtube.com/watch?v=yRyumGu_owg&list=PLpIkg8OmuX-IpUPXh3z8oeKSfRkKhjaTV
*/

//Approach-1 (Using NSL, NSR concept - Monotonic Stack)
class Solution {
public:
    //NSR = Next smaller to right
    vector<int> NSR(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int pseudo_index = n;
        vector<int> right(n);
        for(int i = n-1; i>=0; i--) {
            if(st.empty()) {
                right[i] = pseudo_index;
            } else {
                //This is actually a concept of monotonic stack
                while(!st.empty() && heights[st.top()] >= heights[i])
                    st.pop();
                if(st.empty())
                    right[i] = pseudo_index;
                else
                    right[i] = st.top();
            }
            st.push(i);
        }
        return right;
    }
    
    //NSL = Next smaller to left
    vector<int> NSL(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int pseudo_index = -1;
        vector<int> left(n);
        for(int i = 0; i<n; i++) {
            if(st.empty()) {
                left[i] = pseudo_index;
            } else {
                //This is actually a concept of monotonic stack
                while(!st.empty() && heights[st.top()] >= heights[i])
                    st.pop();
                if(st.empty())
                    left[i] = pseudo_index;
                else
                    left[i] = st.top();
            }
            st.push(i);
        }
        return left;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left  = NSL(heights, n);
        vector<int> right = NSR(heights, n);
        
        int sum = 0;
        
        for(int x:left)
            cout << x << " ";
        cout << endl;
        for(int x:right)
            cout << x << " ";
        
        for(int i = 0; i<n; i++) {
            int area_i = heights[i]*(right[i]-left[i]-1);
            sum = max(sum, area_i);
        }
        
        return sum;
        
    }
};


//Approach-2 (Simplified version of Approach-1)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int i = 0;
        int n = heights.size();
        
        int maxArea = 0;
        int area    = 0;
        while(i < n) {
            if(st.empty() || heights[i] >= heights[st.top()])
                st.push(i++);
            else {
                int index = st.top();
                st.pop();
                if(st.empty()) {
                    area = heights[index] * i;
                } else {
                    area = heights[index] * (i - st.top() - 1);
                }
                maxArea = max(maxArea, area);
            }
        }
        
        while(!st.empty()) {
            int index = st.top();
            st.pop();

            if(st.empty()) {
                area = heights[index] * i;
            } else {
                area = heights[index] * (i - st.top() - 1);
            }
            maxArea = max(maxArea, area);
        }
        
        return maxArea;
    }
};
```

---

### Maximal Rectangle

**LeetCode:** https://leetcode.com/problems/maximal-rectangle/

**Problem:** Given a 2D binary matrix filled with `'0'`s and `'1'`s, find the area of the largest rectangle containing only `1`s.

**Example:**
```
Input:  matrix = [["1","0","1","0","0"],
                   ["1","0","1","1","1"],
                   ["1","1","1","1","1"],
                   ["1","0","0","1","0"]]
Output: 6
```

**Intuition:** Reduce the 2D problem to repeated 1D "Largest Rectangle in Histogram" calls. Maintain a `heights` array across rows — for each row, `heights[col]` increases by 1 if the cell is `'1'`, and resets to 0 if it's `'0'` (like a running column of stacked 1s). After updating heights for each row, run the histogram algorithm (via NSL/NSR with a monotonic stack) and track the maximum area across all rows.

```cpp
#include <bits/stdc++.h>

using namespace std;

/*        Scroll below to see JAVA code also        */
/*
    Company Tags  : Amazon, Directi, Intuit, MakeMyTrip, Microsoft, Samsung
    Leetcode Link : https://leetcode.com/problems/maximal-rectangle/
*/

/***************************************************** C++ ****************************************************/
//Approach-1 (using NSL and NSR to find MAH (Maximum Area in Histogram)
//T.C : O(row*(col+col)) ~= O(row*col)
//S.C : O(col)
class Solution {
public:
    vector<int> NSR(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int pseudo_index = n;
        vector<int> right(n);
        for(int i = n-1; i>=0; i--) {
            if(st.empty()) {
                right[i] = pseudo_index;
            } else {
                while(!st.empty() && heights[st.top()] >= heights[i])
                    st.pop();
                if(st.empty())
                    right[i] = pseudo_index;
                else
                    right[i] = st.top();
            }
            st.push(i);
        }
        return right;
    }
    vector<int> NSL(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int pseudo_index = -1;
        vector<int> left(n);
        for(int i = 0; i<n; i++) {
            if(st.empty()) {
                left[i] = pseudo_index;
            } else {
                while(!st.empty() && heights[st.top()] >= heights[i])
                    st.pop();
                if(st.empty())
                    left[i] = pseudo_index;
                else
                    left[i] = st.top();
            }
            st.push(i);
        }
        return left;
    }
    
    int MAH(vector<int>& heights) {
        int n = heights.size();
        vector<int> right = NSR(heights);
        vector<int> left  = NSL(heights);
        vector<int> width(n);
        for(int i = 0; i<n; i++)
            width[i] = right[i]-left[i]-1;
        int max_area = 0;
        
        for(int i = 0; i<n; i++) {
            int a =  width[i]*heights[i];
            if(max_area < a)
                max_area = a; 
        }
        return max_area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0)
            return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> height(m);
        for(int i = 0; i<m; i++) {
            height[i] = (matrix[0][i]=='1')?1:0;
        }
        int maxA = MAH(height);
        for(int i = 1; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(matrix[i][j] == '0')
                    height[j] = 0;
                else
                    height[j] += 1;
            }
            maxA = max(maxA, MAH(height));
        }
        return maxA;
    }
};

//Approach-2 (Simplified MAH)
class Solution {
public:
    //SImplified
    int MAH(vector<int>& heights, int& n) {
        stack<int> st;
        int i = 0;
        int maxArea = 0;
        int area = 0;
        while(i < n) {
            if(st.empty() || heights[i] >= heights[st.top()]) {
                st.push(i++);
            } else {
                int index = st.top();
                st.pop();
                
                if(st.empty()) {
                    area = heights[index] * i;
                } else {
                    area = heights[index] * (i - st.top() - 1);
                }
                
                maxArea = max(maxArea, area);
            }
        }
        
        while(!st.empty()) {
            int index = st.top();
            st.pop();

            if(st.empty()) {
                area = heights[index] * i;
            } else {
                area = heights[index] * (i - st.top() - 1);
            }

            maxArea = max(maxArea, area);
        }
        
        return maxArea;
        
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0)
            return 0;
        
        int maxArea = 0;
        int m       = matrix.size();
        int n       = matrix[0].size();
        
        /*
        [1, 0, 1, 0, 0]
        [1, 0, 1, 1, 1] =>  [2, 0, 2, 1, 1]
        [1, 1, 1, 1, 1] =>  [3, 1, 3, 2, 2]
        [1, 0, 0, 1, 0] ->  [3, 0, 0, 3, 0]
        */
        
        vector<int> heights(n, 0);
        for(int col = 0; col < n; col++) {
            heights[col] = matrix[0][col] == '0' ? 0 : 1;
        }
        
        maxArea = MAH(heights, n);
        
        for(int row = 1; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(matrix[row][col] == '0') {
                    heights[col] = 0;
                } else {
                    heights[col] += 1;
                }
            }
            
            maxArea = max(maxArea, MAH(heights, n));
        }
        
        return maxArea;
    }
};
```

---

### Trapping Rain Water (using stack)

**LeetCode:** https://leetcode.com/problems/trapping-rain-water/

**Problem:** Given `n` non-negative integers representing an elevation map where each bar has width 1, compute how much water it can trap after raining.

**Example:**
```
Input:  height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
```

**Intuition:** Maintain a monotonic decreasing stack of indices. When the current bar is taller than the stack's top, the top is a "valley" (`mid`) bounded by a `left` wall (new stack top after popping) and a `right` wall (current index). Water trapped over that valley is `(min(height[left], height[right]) - height[mid]) * (right - left - 1)`. Pop and accumulate until the stack top is no longer smaller, then push the current index.

```cpp
#include <bits/stdc++.h>

using namespace std;

/*
    MY YOUTUBE VIDEO ON THIS Qn : Will soon come
    Company Tags                : Accolite, Adobe, Amazon, D-E-Shaw, MakeMyTrip, Microsoft, Payu
    Leetcode Link               : https://leetcode.com/problems/trapping-rain-water/
    Monotonic Data Structures Concepts Playlist - https://www.youtube.com/watch?v=yRyumGu_owg&list=PLpIkg8OmuX-IpUPXh3z8oeKSfRkKhjaTV
*/


/************************************************************ C++ ************************************************************/
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> st;
        int water = 0;

        for(int i = 0; i < n; i++) {
            //This is actually the concept of monotonic stack
            while(!st.empty() && height[i] > height[st.top()]) {
                //It means "mid" is bounded from left (i.e. height[st.top()]) and right(i.e. height[i])
                int mid = st.top();
                st.pop();

                //But, for bounding mid, we need left (height[st.top()])
                if(st.empty()) {
                    break; //no left bound found
                }
                
                int right = i;
                int left  = st.top();

                int h = min(height[right], height[left]) - height[mid];
                int w = right - left - 1;
                
                water += (h*w);
            }
            st.push(i);
        }

        return water;
    }
};
```

---

### Remove K Digits

**LeetCode:** https://leetcode.com/problems/remove-k-digits/

**Problem:** Given a non-negative integer `num` represented as a string, remove `k` digits so that the remaining number is the smallest possible (no leading zeros, unless the result is "0").

**Example:**
```
Input:  num = "1432219", k = 3
Output: "1219"
```

**Intuition:** Build the result greedily using a string as a monotonic increasing stack. For each incoming digit, while the last kept digit is larger than the current digit and we still have removals (`k > 0`) left, pop it — a smaller digit earlier makes the overall number smaller. Skip leading zeros while the result is still empty. After processing, if `k` removals remain, trim from the end (the string is now non-decreasing, so trailing digits are the largest).

```cpp
#include <bits/stdc++.h>

using namespace std;

/*         Scroll down to see JAVA code also        */
/*
    YOUTUBE LINK  : https://www.youtube.com/watch?v=lWcZB7l-O7M
    Company Tags  : Snapchat, Microsoft, Google, Meta
    Leetcode Link : https://leetcode.com/problems/remove-k-digits/
*/


/********************************************************************* C++ ***********************************************************/
//Using simple Monotonic Nature of Numbers
//T.C : O(n)
//S.C : O(1) - I am ignoring the space taken for result variable
class Solution {
public:
    string removeKdigits(string num, int k) {
        
        string result = ""; //it will act like a stack
        int n = num.length();
        
        for(int i = 0; i < n; i++) {
            
            while(result.length() > 0 && result.back() > num[i] && k > 0) {
                result.pop_back();
                k--;
            }
            
            if(result.length() > 0 || num[i] != '0') {
                result.push_back(num[i]); //to avoid the case when we have preceeding zeros
            }
            
        }
        
        
        while(result.length() > 0 && k > 0) {
            result.pop_back();
            k--;
        }

        if(result == "") {
            return "0";
        }
        
        return result;
        
    }
};
```

---

### Final Prices With a Special Discount in a Shop

**LeetCode:** https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop

**Problem:** Given `prices`, for each item `i`, if there exists a later item `j` with `prices[j] <= prices[i]`, subtract `prices[j]` from `prices[i]` as a discount. Return the final prices.

**Example:**
```
Input:  prices = [8,4,6,2,3]
Output: [4,2,4,2,3]
```

**Intuition:** This is "next smaller or equal element" applied as a subtraction. Use a monotonic non-decreasing stack of indices; when the current price is ≤ the price at the stack's top, that top item found its discount — subtract the current price from it and pop. Push the current index regardless.

```cpp
#include <bits/stdc++.h>

using namespace std;

/*                   Scroll below to see JAVA code as well                */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=y5CZ7LhqSAU
    Company Tags                : will update later
    Letcode Link                : https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop
    
    Monotonic Data Structures Concepts Playlist - https://www.youtube.com/watch?v=yRyumGu_owg&list=PLpIkg8OmuX-IpUPXh3z8oeKSfRkKhjaTV
*/


/************************************************************ C++ ************************************************************/
//Approach-1 (Brute Force)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> result(begin(prices), end(prices));

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(prices[j] <= prices[i]) {

                    result[i] -= prices[j];
                    break;
                }
            }
        }

        return result;
    }
};


//Approach-2 (Monotonic Stack)
//T.C : O(2*n) ~= O(n)
//S.C : O(n) due to stack
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> result(begin(prices), end(prices));
        stack<int> st;
        
        for(int i = 0; i < n; i++) {

            while(!st.empty() && prices[i] <= prices[st.top()]) {
                result[st.top()] -= prices[i];
                st.pop();
            }
            st.push(i);
        }

        return result;
    }
};
```

---

### Maximum Width Ramp

**LeetCode:** https://leetcode.com/problems/maximum-width-ramp/

**Problem:** A ramp is a pair `(i, j)` with `i < j` and `nums[i] <= nums[j]`. Return the maximum width `j - i` of a ramp in `nums`, or `0` if none exists.

**Example:**
```
Input:  nums = [6,0,8,2,1,5]
Output: 4
```

**Intuition:** Build a monotonic decreasing stack of indices while scanning left to right — only push an index if it's smaller than (or equal to) the current stack top, since a larger earlier index could never be the *left* end of a wider ramp than a smaller one. Then scan `j` from right to left; while the value at the stack's top index is ≤ `nums[j]`, it's a valid ramp — pop it and update the max width, since moving `j` further left can only shrink future ramps for that same `i`.

```cpp
#include <bits/stdc++.h>

using namespace std;

/*     Scroll below to see JAVA code also   */
/*
    MY YOUTUBE VIDEO ON THIS Qn   : https://www.youtube.com/watch?v=ClboFCGDT4I
    Company Tags                  : Google, Amazon
    Leetcode Link                 : https://leetcode.com/problems/maximum-width-ramp/
    Using 2-Pointer Approach Link : https://www.youtube.com/watch?v=mcJBhWXel-Y
*/


/********************************************************************** C++ **********************************************************************/
//Approach (Using monotonic stack)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();

        stack<int> st; //stores indices of the elements

        for(int i = 0; i < n; i++) {
            if(st.empty() || nums[st.top()] >= nums[i]) {
                st.push(i);
            }
        }

        int ramp = 0;

        int j = n-1;
        while(j >= 0) {
            while(!st.empty() && nums[st.top()] <= nums[j]) { //st.top() = i
                int i = st.top();
                ramp = max(ramp, j-i);
                st.pop();
            }
            j--;
        }

        return ramp;
        
    }
};
```

---

### Minimum Operations to Convert All Elements to Zero

**LeetCode:** https://leetcode.com/problems/minimum-operations-to-convert-all-elements-to-zero

**Problem:** Given an array `nums`, in one operation you may pick a subarray and replace every occurrence of the *minimum* value in that subarray with `0`. Find the minimum number of operations to make all elements `0`.

**Example:**
```
Input:  nums = [0,2]
Output: 1
```

**Intuition:** Each *distinct* value that appears as a "locally minimal run" (a maximal contiguous block where that value is the minimum, not interrupted by a smaller value) needs exactly one operation to zero it out — one operation can knock out all equal occurrences in one contiguous stretch at once. Use a monotonic non-decreasing stack of values: pop any stack-top values greater than the current number (they're no longer the running minimum for this stretch); if the current number (non-zero) is strictly greater than the new top, it starts a *new* zeroing operation, so push it and increment the answer.

```cpp
#include <bits/stdc++.h>

using namespace std;

/*     Scroll below to see JAVA code also   */
/*
    MY YOUTUBE VIDEO ON THIS Qn   : https://www.youtube.com/watch?v=Q1OSaRRkEcs
    Company Tags                  : Will update later
    Leetcode Link                 : https://leetcode.com/problems/minimum-operations-to-convert-all-elements-to-zero
*/


/********************************************************************** C++ **********************************************************************/
//Approach (Brute Force)
//T.C : O(n*u), u = unique elements, in worst case  u = n
//S.C : O(u), in worst case u = n
class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_set<int> st(begin(nums), end(nums)); //O(n) space

        int n = nums.size();

        int ops = 0;

        for(int target : st) { //O(U*n)
            if(target == 0)
                continue;
            
            bool flow = false;
            for(int i = 0; i < n; i++) {
                if(nums[i] == target) {
                    if(!flow) {
                        flow = true;
                        ops++;
                    }
                } else if(nums[i] < target) {
                    flow = false;
                }
            }
        }

        return ops;

        
    }
};



//Approach (Optimal using Monotonic Increasing Stack)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> st;

        int ops = 0;

        for(int i = 0; i < nums.size(); i++) {
            while(!st.empty() && st.top() > nums[i]) {
                st.pop();
            }

            if(nums[i] == 0)
                continue;
            
            if(st.empty() || st.top() < nums[i]) {
                st.push(nums[i]);
                ops++;
            }
        }

        return ops;
    }
};
```

---

## 4. String Building with a Stack

### Remove All Adjacent Duplicates In String

**LeetCode:** https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

**Problem:** Given a string `s`, repeatedly remove adjacent pairs of identical characters until none remain, and return the final string.

**Example:**
```
Input:  s = "abbaca"
Output: "ca"
```

**Intuition:** Use the output itself as a stack. Append each character; if it equals the last character already appended, that's an adjacent duplicate — pop it instead of adding. This processes the string in a single O(n) pass without needing repeated scans.

```cpp
#include <bits/stdc++.h>

using namespace std;

/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=VeOUal3_s6c
    Company Tags                : Microsoft, Paytm, Samsung
    Leetcode Link               : https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
*/

//Approach-1 (With stack)
string removeDupUsingStack(string S) {
        stack<char> st;
        
        for(int i = S.length()-1; i>=0; i--) {
            if(st.empty() || st.top() != S[i])
                st.push(S[i]);
            else
                st.pop();
        }
    
        string result = "";
        while(!st.empty()) {
            result += st.top();
            st.pop();
        }
        return result;
    }

//Appraoch-2 (Without stack)
class Solution {
public:
    string removeDuplicates(string s) {
        string result = "";
        
        for(char &ch : s) {
            if(result.empty() || result.back() != ch) {
                result.push_back(ch);
            } else {
                result.pop_back();
            }
        }
        
        return result;
    }
};
```

---

### Removing Stars From a String

**LeetCode:** https://leetcode.com/problems/removing-stars-from-a-string/

**Problem:** Given a string `s` containing lowercase letters and `*`, repeatedly remove the closest previous non-star character every time a `*` is encountered, along with the star itself. Return the final string.

**Example:**
```
Input:  s = "leet**cod*e"
Output: "lecoe"
```

**Intuition:** A stack is a perfect fit: push normal characters, and on encountering `*`, pop the top (removing the nearest character to its left). The two-pointer variant achieves the same thing in-place using an index `j` as a virtual stack pointer.

```cpp
#include <bits/stdc++.h>

using namespace std;

/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=s1pcdsRCVDg
    Company Tags                : MICROSOFT
    Leetcode Link               : https://leetcode.com/problems/removing-stars-from-a-string/
*/

//Approach-1 (Using Stack)
class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        
        for(char &ch : s) {
            
            if(ch == '*') {
                st.pop();
            } else {
                st.push(ch);
            }
            
        }
        
        string result = "";
        
        while(!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        
        reverse(begin(result), end(result));
        return result;
    }
};

//Approach-2 (using string as stack)
class Solution {
public:
    string removeStars(string s) {
        string result = "";
        
        for(char &ch : s) {
            
            if(ch == '*') {
                result.pop_back();
            } else {
                result.push_back(ch);
            }
            
        }
        
        return result;
    }
};

//Approach-3 (Using Two pointers)
class Solution {
public:
    string removeStars(string s) {
        vector<char> ch(s.size());
        int j = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '*') {
                j--;
            } else {
                ch[j++] = s[i];
            }
        }

        string result = "";
        for (int i = 0; i < j; i++) {
            result.push_back(ch[i]);
        }

        return result;
    }
};
```

---

### Remove All Occurrences of a Substring

**LeetCode:** https://leetcode.com/problems/remove-all-occurrences-of-a-substring

**Problem:** Given strings `s` and `part`, repeatedly remove the leftmost occurrence of `part` in `s` until it no longer occurs. Return the final `s`.

**Example:**
```
Input:  s = "daabcbaabcbc", part = "abc"
Output: "dab"
```

**Intuition:** A brute-force `find` + `erase` loop works but re-scans repeatedly. Instead, build the result incrementally (using a stack of characters, or a string acting as a stack): push each character, and whenever the top `n` characters match `part`, pop them off. This handles cascading removals correctly since newly exposed characters can form new matches, just like a real stack-based bracket matching.

```cpp
#include <bits/stdc++.h>

using namespace std;

/*     Scroll below to see JAVA code also   */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=v6_q_fu1ev0
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/remove-all-occurrences-of-a-substring
*/


/********************************************************************** C++ **********************************************************************/
//Approach-1 (Brute Force)
//T.C : O(m*n)
//S.C : O(1)
class Solution {
public:
    string removeOccurrences(string s, string part) {
        //s.length() = m
        //part.length() = n;
        //O(m*n)
        while(true) {
            int idx = s.find(part);

            if(idx == string::npos) {
                break;
            }

            s.erase(idx, part.length());
        }

        return s;
    }
};


//Approach-2 (Using Stack)
//T.C : O(m*n)
//S.C : O(m)
class Solution {
public:
    bool check(stack<char>& st, string& part, int n) {
        stack<char> tempSt = st;

        for(int idx = n-1; idx >= 0; idx--) {
            if(tempSt.top() != part[idx]) {
                return false;
            }

            tempSt.pop();
        }

        return true;
    }


    string removeOccurrences(string s, string part) {
        stack<char> st;

        int m = s.length();
        int n = part.length();

        for(int i = 0; i < m; i++) {
            st.push(s[i]);

            if(st.size() >= n && check(st, part, n) == true) {
                for(int j = 0; j < n; j++) {
                    st.pop();
                }
            } 
        }

        string result = "";
        while(!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        reverse(begin(result), end(result));
        return result;
    }
};


//Approach-3 (Using string as a stack)
//T.C : O(m*n)
//S.C : O(1), not considering result as extra space
class Solution {
public:
    string removeOccurrences(string s, string part) {
        string result = "";
        int n = part.length();

        for(char &ch : s) {
            result.push_back(ch);

            if(result.length() >= n && result.substr(result.length() - n) == part) {
                result.erase(result.length() - n);
            }
        }

        return result;
    }
};
```

---

### Clear Digits

**LeetCode:** https://leetcode.com/problems/clear-digits/description/

**Problem:** Given a string `s` containing lowercase letters and digits, repeatedly remove the first digit and the closest non-digit character to its left. Return the resulting string.

**Example:**
```
Input:  s = "abc"
Output: "abc"

Input:  s = "cb34"
Output: ""
```

**Intuition:** Push letters onto a stack; whenever a digit is seen, pop the last pushed letter (its "closest character to the left"), effectively cancelling one letter per digit. A pure in-place two-pointer version uses a write index `j` that steps back one position (bounded at 0) whenever a digit is seen, instead of writing it.

```cpp
#include <bits/stdc++.h>

using namespace std;

/*      Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=WI9PhnDxAik
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/clear-digits/description/
*/


/********************************************* C++ *********************************************/
//Approach-1 (Brute Force)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    string clearDigits(string s) {
        int i = 0;

        while (i < s.size()) {
            if (isdigit(s[i])) {

                s.erase(i, 1);
                if (i > 0) {
                    s.erase(i - 1, 1);
                    i--;
                }
            } else {
                i++;
            }
        }
        return s;
    }
};


//Approach-2 (Using stack)
//T.C : O(n)
//S.C : O(n) for stack
class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;

        for(char &ch : s) {
            if(ch >= 'a' && ch <= 'z') {
                st.push(ch);
            } else if(!st.empty()) {
                st.pop();
            }
        }

        string result = "";
        while(!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        reverse(begin(result), end(result));

        return result;
    }
};


//Approach-3 (Using result string to avoid reverse call)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    string clearDigits(string s) {
        string result = "";

        for(char &ch : s) {
            if(ch >= 'a' && ch <= 'z') {
                result.push_back(ch);
            } else if(!result.empty()) {
                result.pop_back();
            }
        }

        return result;
    }
};


//Approach-4 (Solving inplace)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    string clearDigits(string s) {
        int j = 0;

        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                j = max(j - 1, 0); //max used to avoid negative
            } else {
                s[j] = s[i];
                j++;
            }
        }

        s.resize(j);
        return s;
    }
};
```

---

### Maximum Score From Removing Substrings

**LeetCode:** https://leetcode.com/problems/maximum-score-from-removing-substrings

**Problem:** Given a string `s` and points `x`, `y`, repeatedly remove one occurrence of `"ab"` (scoring `x` points) or `"ba"` (scoring `y` points). Maximize the total score.

**Example:**
```
Input:  s = "cdbcbbaaabab", x = 4, y = 5
Output: 19
```

**Intuition:** Greedily remove the *higher-scoring* pair first across the whole string (this is provably optimal — removing the higher value pair first never blocks a better outcome), then remove the lower-scoring pair from what remains. Use a stack: push characters, and whenever the top of the stack together with the incoming character forms the target pair, pop instead of pushing. Repeat this stack-removal process for the second (lower-value) pair on the leftover string.

```cpp
#include <bits/stdc++.h>

using namespace std;

/*      Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=WTAjAcjSTqM
    Company Tags                : Google, Meta, Amazon
    Leetcode Link               : https://leetcode.com/problems/maximum-score-from-removing-substrings
*/


/**************************************************************** C++ ********************************************************/
//Approach-1 (Using Stack)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n     = s.length();
        int score = 0;

        string maxStr = (x > y) ? "ab" : "ba";
        string minStr = (maxStr == "ab") ? "ba" : "ab"; //This is updated after the video was made as a new test case was added in Leetcode

        //First Pass
        string temp_first     = removeSubstring(s, maxStr);
        int removedPairsCount = (n - temp_first.length()) / 2;
        score                += removedPairsCount * max(x, y);


        //Second Pass
        string temp_second = removeSubstring(temp_first, minStr);
        removedPairsCount  = (temp_first.length() - temp_second.length()) / 2;
        score             += removedPairsCount * min(x, y);

        return score;
    }

private:
    string removeSubstring(string& s, string& matchStr) {
        stack<char> st;

        for (char &ch : s) {
            if (ch == matchStr[1] && !st.empty() && st.top() == matchStr[0]) {
                st.pop();
            } else {
                st.push(ch);
            }
        }

        string remainStr;
        while (!st.empty()) {
            remainStr.push_back(st.top());
            st.pop();
        }
        reverse(remainStr.begin(), remainStr.end());
        return remainStr;
    }
};



//Approach-2 (Without Stack)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n     = s.length();
        int score = 0;

        string maxStr = (x > y) ? "ab" : "ba";
        string minStr = (maxStr == "ab") ? "ba" : "ab"; //This is updated after the video was made as a new test case was added in Leetcode

        //First Pass
        string temp_first     = removeSubstring(s, maxStr);
        int L                 = temp_first.length();
        int removedPairsCount = (n - L) / 2;
        score                += removedPairsCount * max(x, y);


        //Second Pass
        string temp_second = removeSubstring(temp_first, minStr);
        removedPairsCount  = (L - temp_second.length()) / 2;
        score             += removedPairsCount * min(x, y);

        return score;
    }

    string removeSubstring(string& inputString, string& matchStr) {
        int j = 0;

        for (int i = 0; i < inputString.size(); i++) {
            inputString[j++] = inputString[i];

            if (j > 1 &&
                inputString[j - 2] == matchStr[0] &&
                inputString[j - 1] == matchStr[1]) {
                j -= 2;
            }
        }

        inputString.erase(inputString.begin() + j, inputString.end());

        return inputString;
    }
};
```

---

## 5. Expression Evaluation

### Basic Calculator

**LeetCode:** https://leetcode.com/problems/basic-calculator/

**Problem:** Implement a basic calculator to evaluate a string expression containing non-negative integers, `+`, `-`, parentheses, and spaces.

**Example:**
```
Input:  s = "(1+(4+5+2)-3)+(6+8)"
Output: 23
```

**Intuition:** Track a running `result`, the current `number` being built, and the `sign` to apply next. On `(`, push the result-so-far and the current sign onto a stack (saving context), then reset for the inner expression. On `)`, finalize the inner result, pop the saved sign and outer result, and combine: `outerResult + savedSign * innerResult`.

```cpp
#include <bits/stdc++.h>

using namespace std;

/*
    MY YOUTUBE VIDEO IN THIS Qn : https://www.youtube.com/watch?v=3AEKyHx3tzU
    Company Tags                : Google, Facebook, Airbnb
    Frequency                   : 66% (As per 2021)
    Leetcode Link               : https://leetcode.com/problems/basic-calculator/
*/

class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int number = 0;
        int result = 0;
        int sign   = 1;
        
        for(int i = 0; i<s.length(); i++) {
            if(isdigit(s[i])) {
                number  = 10*number + (s[i] - '0');
            } else if(s[i] == '+') {
                result += sign*number;
                number  = 0;
                sign = 1; //For further
            } else if(s[i] == '-') {
                result += sign*number;
                number  = 0;
                sign = -1; //For further
            } else if(s[i] == '(') {
                st.push(result);
                st.push(sign);
                result = 0;
                number = 0;
                sign = 1;
            } else if(s[i] == ')') {
                result += sign*number;
                number = 0;
                int top = st.top(); st.pop();
                result *= top;
                top = st.top(); st.pop();
                result += top;
            }
        }
        result += (sign*number);
        return result;
    }
};
```

---

### Evaluate Reverse Polish Notation

**LeetCode:** https://leetcode.com/problems/evaluate-reverse-polish-notation/

**Problem:** Evaluate the value of an arithmetic expression given in Reverse Polish Notation (postfix), where tokens are either operands or one of `+ - * /`.

**Example:**
```
Input:  tokens = ["4","13","5","/","+"]
Output: 6
```

**Intuition:** RPN is the textbook use case for a stack. Push operands. When an operator is encountered, pop the top two operands (`b` then `a`, so order matters for `-` and `/`), apply the operator, and push the result back. At the end, the stack holds exactly the final answer.

```cpp
#include <bits/stdc++.h>

using namespace std;

/*                                                        SCROLL DOWN FOR JAVA CODE ALSO                                   */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=BM-bu4tJz7U
    Company Tags                : Apple, Microsoft, Flipkart, Amazon, LinkedIn
    Leetcode Link               : https://leetcode.com/problems/evaluate-reverse-polish-notation/
*/

/********************************************************************* C++ ************************************************************************/
//Approach-1 (Basic stack approach)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int operate(int &a, int &b, const string &s) {
        if(s == "+")
            return a+b;
        
        if(s == "-")
            return a-b;
        
        if(s == "*")
            return (long)a*(long)b;
        
        if(s == "/")
            return a/b;
        
        return -1;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int result = 0;
        for(const string& s:tokens) {
            if(s == "+" || s == "-" || s == "*" || s == "/") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                
                result = operate(a, b, s);
                st.push(result);
            } else {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};


/*
    Using fancy Lambda on unordered_map
    For my fancy STL collection with easy exlanation with examples, see the link below -
    https://github.com/MAZHARMIK/Cpp-STL-Quick-Help/blob/main/README.md
*/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int result = 0;
        
        unordered_map<string, function<int (int, int)> > mp = {
            {"+", [](int a, int b) {return a + b; } },
            {"-", [](int a, int b) {return a - b; } },
            {"*", [](int a, int b) {return (long)a * (long)b; } },
            {"/", [](int a, int b) {return a / b; } },
        };
        
        for(const string& s:tokens) {
            if(s == "+" || s == "-" || s == "*" || s == "/") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                
                result = mp[s](a, b);
                st.push(result);
            } else {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};
```

---

### Number of Atoms

**LeetCode:** https://leetcode.com/problems/number-of-atoms

**Problem:** Given a chemical formula (possibly with nested parentheses and multipliers, e.g. `"K4(ON(SO3)2)2"`), return the count of each atom in the formula, formatted in a canonical sorted string.

**Example:**
```
Input:  formula = "H2O"
Output: "H2O"

Input:  formula = "Mg(OH)2"
Output: "H2MgO2"
```

**Intuition:** Use a stack of hashmaps, one map per open parenthesis "scope". Parse atom names (capital letter + optional lowercase letters) and their counts directly into the top map. On `(`, push a fresh map for the new scope. On `)`, pop the scope's map, multiply every count in it by the trailing multiplier digits (if any), then merge it into the new top of the stack (the enclosing scope). Finally sort all atoms alphabetically for the output.

```cpp
#include <bits/stdc++.h>

using namespace std;

/*     Scroll below to see JAVA code also    */
/*
        MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=XnVWIT47H0Y
        Company Tags                : GOOGLE
        Leetcode Link               : https://leetcode.com/problems/number-of-atoms
*/


/*************************************************************************** C++ *****************************************************************/
//Using stack
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    typedef unordered_map<string, int> MAP;

    string countOfAtoms(string formula) {
        int n = formula.length();
        
        stack<MAP> st;
        st.push(MAP());

        int i = 0;

        while (i < n) {
            if (formula[i] == '(') {
                st.push(MAP());
                i++;
            } else if (formula[i] == ')') {
                MAP currMap = st.top();
                st.pop();
                i++;
                string multiplier;
                while (i < formula.length() && isdigit(formula[i])) {
                    multiplier += formula[i];
                    i++;
                }
                if (!multiplier.empty()) {
                    int mult = stoi(multiplier);
                    for (auto& [atom, count] : currMap) {
                        currMap[atom] = count * mult;
                    }
                }

                for (auto& [atom, count] : currMap) {
                    st.top()[atom] += count;
                }
            } else {
                string currAtom;
                currAtom += formula[i];
                i++;
                while (i < formula.length() && islower(formula[i])) {
                    currAtom += formula[i];
                    i++;
                }

                string currCount;
                while (i < formula.length() && isdigit(formula[i])) {
                    currCount += formula[i];
                    i++;
                }

                int count = currCount.empty() ? 1 : stoi(currCount);
                st.top()[currAtom] += count;
            }
 
        }
        
        map<string, int> sortedMap(begin(st.top()), end(st.top()));

        string result;
        for (auto& [atom, count] : sortedMap) {
            result += atom;
            if (count > 1) {
                result += to_string(count);
            }
        }

        return result;
    }
};
```

---

### Parsing A Boolean Expression

**LeetCode:** https://leetcode.com/problems/parsing-a-boolean-expression

**Problem:** Evaluate a boolean expression given as a string, where `t` = true, `f` = false, `!(...)` = NOT, `&(...)` = AND of comma-separated operands, `|(...)` = OR of comma-separated operands.

**Example:**
```
Input:  expression = "&(|(f))"
Output: false
```

**Intuition:** Push every character except `,` onto a stack. When `)` is hit, pop all values until `(` — these are the operands for the innermost expression. Pop `(`, then pop the operator (`!`, `&`, `|`) right below it, apply the operator to the collected operands, and push the single resulting `t`/`f` back. This naturally resolves from the innermost parentheses outward.

```cpp
#include <bits/stdc++.h>

using namespace std;

/*     Scroll below to see JAVA code also   */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=AXfTSqFUopw
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/parsing-a-boolean-expression
*/


/********************************************************************** C++ **********************************************************************/
//Approach (Using stack)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    char solveOp(char op, vector<char>& values) {
        if (op == '!') 
            return values[0] == 't' ? 'f' : 't';
    
        if (op == '&') 
            return any_of(values.begin(), values.end(), [](char ch) { return ch == 'f'; }) ? 'f' : 't';
    
        if (op == '|') 
            return any_of(values.begin(), values.end(), [](char ch) { return ch == 't'; }) ? 't' : 'f';
    
        return 't'; // Unreachable
    }

    bool parseBoolExpr(string s) {
        int n = s.size();
        stack<char> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == ',') continue;

            if (s[i] == ')') {
                vector<char> values;
                // Gather all values inside the parentheses
                while (st.top() != '(') {
                    values.push_back(st.top());
                    st.pop();
                }
                st.pop();  // Remove '('
                char op = st.top();
                st.pop();  // Remove the operator
                st.push(solveOp(op, values));
            } else {
                st.push(s[i]);
            }
        }
        return (st.top() == 't');
    }
};
```

---

## 6. Path / Log Simulation

### Simplify Path

**LeetCode:** https://leetcode.com/problems/simplify-path/

**Problem:** Given an absolute Unix-style file path, simplify it to its canonical form (resolve `.`, `..`, and redundant slashes).

**Example:**
```
Input:  path = "/home//foo/"
Output: "/home/foo"

Input:  path = "/a/./b/../../c/"
Output: "/c"
```

**Intuition:** Split the path on `/` into tokens. Skip empty tokens and `.` (they mean "stay here"). For `..`, pop the last directory off the stack (go up one level) if the stack isn't already empty. Push every other valid directory/file name. Finally join the stack contents back with `/` to form the canonical path.

```cpp
#include <bits/stdc++.h>

using namespace std;

/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=ZV-Hi1e1KL8
      Company Tags                : META
      Leetcode Link               : https://leetcode.com/problems/simplify-path/
*/

//Approach-1 (Using Stack)
class Solution {
public:
    string simplifyPath(string path) {
        string token = "";
        
        stringstream ss(path);
        stack<string> st;
        
        while(getline(ss, token, '/')) {

            if(token == "" || token == ".") continue;
            
            if (token != "..") 
                st.push(token);
            else if (!st.empty()) 
                st.pop();
        }
        
        string result = "";
        
        while(!st.empty()){ // add all the stack elements
            result="/"+st.top()+result;
            st.pop();
        }
        
        if(result.length()==0) // if no directory or file is present
            result="/"; // minimum root directory must be present in result
        
        return result;
    }
};

//Approach-2 (Using vector as stack)
class Solution {
public:
    string simplifyPath(string path) {
        string token = "";
        
        stringstream ss(path);
        vector<string> st;
        
        while(getline(ss, token, '/')) {

            if(token == "" || token == ".") continue;
            
            if (token != "..") 
                st.push_back(token);
            else if (!st.empty()) 
                st.pop_back();
        }
        
        string result = "";
        
        for(auto &token : st) {
            result += "/" + token;
        }
        
        return result.empty() ? "/" : result;
    }
};
```

---

### Crawler Log Folder

**LeetCode:** https://leetcode.com/problems/crawler-log-folder

**Problem:** Given a sequence of folder-navigation operations (`"../"` go up, `"./"` stay, `"x/"` go into folder `x`), starting from the main folder, return the minimum number of `"../"` needed to get back to the main folder after performing all operations.

**Example:**
```
Input:  logs = ["d1/","d2/","../","d21/","./"]
Output: 2
```

**Intuition:** Since the answer only needs the final depth, a simple counter works: increment on entering a folder, decrement (bounded at 0) on `"../"`, ignore `"./"`. A stack-based simulation achieves the same thing by literally pushing/popping folder names — its final size equals the depth, useful if you also cared about the actual path.

```cpp
#include <bits/stdc++.h>

using namespace std;

/*      Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=xAI0hcwzuuE
    Company Tags                : GOOGLE, and some other company Online Assessment problem
    Leetcode Link               : https://leetcode.com/problems/crawler-log-folder
*/


/********************************************* C++ *********************************************/
//Approach-1 (Using simple simulation)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;

        for(string &s : logs) {
            if(s == "../") {
                depth = max(0, depth-1);
            } else if(s == "./") {
                continue;
            } else {
                depth++;
            }
        }

        return depth;
    }
};


//Approach-2 (Using Stack for simulation)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> st;

        for (const string& currentOperation : logs) {
            if (currentOperation == "../") {
                if (!st.empty()) {
                    st.pop();
                }
            } else if (currentOperation != "./") {
                st.push(currentOperation);
            }
        }

        return st.size();
    }
};
```

---

## 7. Collision / Merge Simulation

### Asteroid Collision

**LeetCode:** https://leetcode.com/problems/asteroid-collision/

**Problem:** Given an array of integers representing asteroids in a row (sign = direction, magnitude = size), simulate collisions — two asteroids collide if the left one moves right (positive) and the right one moves left (negative). The smaller explodes; equal-size ones both explode. Return the state after all collisions.

**Example:**
```
Input:  asteroids = [5,10,-5]
Output: [5,10]

Input:  asteroids = [8,-8]
Output: []
```

**Intuition:** A stack naturally models "asteroids currently moving right, waiting to possibly collide." For each new asteroid, if it's moving left and the stack top is moving right, they collide: pop/destroy the smaller, keep the larger, or destroy both if equal. Keep resolving collisions in a `while` loop before deciding whether the current asteroid survives to be pushed.

```cpp
#include <bits/stdc++.h>

using namespace std;

/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=7isfomHzzno
    Company Tags                : Uber, lyft
    Leetcode Link               : https://leetcode.com/problems/asteroid-collision/
*/

//Using a stack<int> (T.C : O(n))
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        
        for(int &a : asteroids) {
            
            while(!st.empty() && a < 0 && st.top() > 0) {
                int sum = a + st.top();
                if(sum < 0) {
                    st.pop();
                } else if(sum > 0) {
                    a = 0;
                    break;
                } else {
                    st.pop();
                    a = 0;
                }
            }
            
            if(a != 0)
                st.push(a);
            
        }
        
        int s = st.size();
        
        vector<int> result(s);
        int i = s-1;
        while(!st.empty()) {
            result[i] = st.top();
            st.pop();
            i--;
        }
        
        return result;
    }
};


//Using vector<int> as stack - T.C (O(n))
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        
        for(int &a : asteroids) {
            
            while(!st.empty() && a < 0 && st.back() > 0) {
                int sum = a + st.back();
                if(sum < 0) {
                    st.pop_back();
                } else if(sum > 0) {
                    a = 0;
                    break;
                } else {
                    st.pop_back();
                    a = 0;
                }
            }
            
            if(a != 0)
                st.push_back(a);
            
        }
        
        
        return st;
    }
};
```

---

### Robot Collisions

**LeetCode:** https://leetcode.com/problems/robot-collisions/description

**Problem:** Given robot `positions`, `healths`, and `directions` (`'L'`/`'R'`), simulate collisions: when two robots moving toward each other meet, the one with lower health is destroyed and the survivor's health decreases by 1 (both are destroyed if health is equal). Return the healths of surviving robots, in their original relative order.

**Example:**
```
Input:  positions = [3,5,2,6], healths = [10,10,15,18], directions = "RLRL"
Output: [14]
```

**Intuition:** Sort robot indices by position so collisions can be simulated left to right in spatial order. Push right-moving (`'R'`) robots onto a stack, since they can only collide with a later left-moving robot. When a left-moving robot appears, repeatedly fight it against the stack top: the weaker one dies, the stronger loses 1 health, ties destroy both. Continue until the left-mover dies or the stack runs out of right-movers to fight. Finally, collect surviving robots (health > 0) in original index order.

```cpp
#include <bits/stdc++.h>

using namespace std;

/*     Scroll below to see JAVA Code also    */
/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=fkcA9zvP7_w
      Company Tags                : Will update soon
      Leetcode Link               : https://leetcode.com/problems/robot-collisions/description
*/


/*********************************************************************** C++ ********************************************************************************/
//Using Stack
//T.C : O(nlogn)
//T.C : O(n)
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> indices(n);
        
        iota(indices.begin(), indices.end(), 0); //This will fill the array as -> 0, 1, 2, 3, 4, n-1
        stack<int> st;

        auto lambda = [&](int i, int j) {
            return positions[i] < positions[j];
        };

        sort(begin(indices), end(indices), lambda);

        vector<int> result;
        for (int currentIndex : indices) {
            if (directions[currentIndex] == 'R') {
                st.push(currentIndex);
            } else {
                while (!st.empty() && healths[currentIndex] > 0) {
                    int topIndex = st.top();
                    st.pop();

                    if (healths[topIndex] > healths[currentIndex]) {
                        healths[topIndex] -= 1;
                        healths[currentIndex] = 0;
                        st.push(topIndex);
                    } else if (healths[topIndex] < healths[currentIndex]) {
                        healths[currentIndex] -= 1;
                        healths[topIndex] = 0;
                    } else {
                        healths[currentIndex] = 0;
                        healths[topIndex] = 0;
                    }
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (healths[i] > 0) {
                result.push_back(healths[i]);
            }
        }
        return result;
    }
};
```

---

### Replace Non-Coprime Numbers in Array

**LeetCode:** https://leetcode.com/problems/replace-non-coprime-numbers-in-array

**Problem:** Given `nums`, repeatedly find two adjacent non-coprime numbers (`gcd > 1`), replace them with their LCM, and repeat until no adjacent pair shares a common factor. Return the final array.

**Example:**
```
Input:  nums = [6,4,3,2,7,6,2]
Output: [12,7,6]
```

**Intuition:** Process left to right using a vector as a stack. For each new number, keep merging it with the stack's top as long as they're non-coprime (`gcd > 1`) — replace both with their LCM and keep checking the new merged value against the (now exposed) previous top, since merging can cascade. Once coprime with the top (or the stack is empty), push the current merged value.

```cpp
#include <bits/stdc++.h>

using namespace std;

/*     Scroll below to see JAVA code also   */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=ll-m8RR7EcU
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/replace-non-coprime-numbers-in-array
*/


/********************************************************************** C++ **********************************************************************/
//Approach (Using vector as a stack)
//T.C : O(n * log(x)), where log comes from GCD
//S.C : O(1)
class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> result; //or you can use a stack

        //Processing left to right
        for(int num : nums) {

            while(!result.empty()) {
                int prev = result.back();
                int curr = num;

                int GCD = gcd(prev, curr);
                if(GCD == 1) {
                    break;
                }

                result.pop_back();
                int LCM = prev / GCD * curr;

                num = LCM; //merged number
            }
            result.push_back(num); //merged num put back to result
        }
        return result;
    }
};
```

---

## 8. Sequence Validation

### Validate Stack Sequences

**LeetCode:** https://leetcode.com/problems/validate-stack-sequences/

**Problem:** Given two sequences `pushed` and `popped` (both permutations of the same numbers), determine whether they could correspond to a valid sequence of push and pop operations on an initially empty stack.

**Example:**
```
Input:  pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
Output: true
```

**Intuition:** Simulate directly. Push elements from `pushed` one at a time; after each push, greedily pop as long as the stack top matches the next expected value in `popped`. If, after processing everything, the stack ends up empty, the sequences are consistent with a valid push/pop order.

```cpp
#include <bits/stdc++.h>

using namespace std;

/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=HEh7EtNSXtg
    Company Tags                : AMAZON
    Leetcode Link               : https://leetcode.com/problems/validate-stack-sequences/
*/


class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        
        int n = pushed.size();
        
        int i = 0, j = 0;
        
        while(i < n && j < n) {
            
            st.push(pushed[i]);
            
            while(!st.empty() && j < n && st.top() == popped[j]) {
                st.pop();
                j++;
            }
            i++;
            
        }
        
        return st.empty();
    }
};
```

---

*Compiled from personal LeetCode solutions covering Stack and Monotonic Stack patterns.*
