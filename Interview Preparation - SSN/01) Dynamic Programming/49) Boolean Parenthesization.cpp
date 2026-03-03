You are given a boolean expression s containing
    'T' ---> true
    'F' ---> false 
and following operators between symbols
   &   ---> boolean AND
    |   ---> boolean OR
   ^   ---> boolean XOR
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

Note: The answer is guaranteed to fit within a 32-bit integer.

Examples:

Input: s = "T|T&F^T"
Output: 4
Explaination: The expression evaluates to true in 4 ways: ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T)).
Input: s = "T^F|F"
Output: 2
Explaination: The expression evaluates to true in 2 ways: ((T^F)|F) and (T^(F|F)).



//**********************************************************************Code****************************************************************************************

class Solution {
public:
    int solve(int i, int j, bool isTrue, string &s, 
              vector<vector<vector<int>>> &dp) {
        
        if(i > j) return 0;
        
        if(i == j) {
            if(isTrue)
                return s[i] == 'T';
            else
                return s[i] == 'F';
        }
        
        if(dp[i][j][isTrue] != -1)
            return dp[i][j][isTrue];
        
        int ways = 0;
        
        for(int k = i+1; k <= j-1; k += 2) {
            
            int LT = solve(i, k-1, true, s, dp);
            int LF = solve(i, k-1, false, s, dp);
            int RT = solve(k+1, j, true, s, dp);
            int RF = solve(k+1, j, false, s, dp);
            
            if(s[k] == '&') {
                if(isTrue)
                    ways += LT * RT;
                else
                    ways += LT*RF + LF*RT + LF*RF;
            }
            
            else if(s[k] == '|') {
                if(isTrue)
                    ways += LT*RT + LT*RF + LF*RT;
                else
                    ways += LF * RF;
            }
            
            else if(s[k] == '^') {
                if(isTrue)
                    ways += LT*RF + LF*RT;
                else
                    ways += LT*RT + LF*RF;
            }
        }
        
        return dp[i][j][isTrue] = ways;
    }
    
    int countWays(string &s) {
        int n = s.length();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(n, vector<int>(2, -1))
        );
        
        return solve(0, n-1, true, s, dp);
    }
};


//***********************************************************************Code**************************************************************************************

// Function to evaluate a
// boolean condition.
function evaluate(b1, b2, op)
{
    if (op === "&") {
        return b1 & b2;
    }
    else if (op === "|") {
        return b1 | b2;
    }
    return b1 ^ b2;
}

// Function which returns the number of ways
// s[i:j] evaluates to req.
function countRecur(i, j, req, s, memo)
{

    // Base case:
    if (i === j) {
        return req === (s[i] === "T" ? 1 : 0) ? 1 : 0;
    }

    // If value is memoized
    if (memo[i][j][req] !== -1) {
        return memo[i][j][req];
    }

    let ans = 0;
    for (let k = i + 1; k < j; k+=2) {

        // Count Ways in which left substring
        // evaluates to true and false.
        let leftTrue = countRecur(i, k - 1, 1, s, memo);
        let leftFalse = countRecur(i, k - 1, 0, s, memo);

        // Count Ways in which right substring
        // evaluates to true and false.
        let rightTrue = countRecur(k + 1, j, 1, s, memo);
        let rightFalse = countRecur(k + 1, j, 0, s, memo);

        // Check if the combinations result
        // to req.
        if (evaluate(1, 1, s[k]) === req) {
            ans += leftTrue * rightTrue;
        }
        if (evaluate(1, 0, s[k]) === req) {
            ans += leftTrue * rightFalse;
        }
        if (evaluate(0, 1, s[k]) === req) {
            ans += leftFalse * rightTrue;
        }
        if (evaluate(0, 0, s[k]) === req) {
            ans += leftFalse * rightFalse;
        }
    }

    return (memo[i][j][req] = ans);
}

function countWays(s)
{
    let n = s.length;
    let memo = Array.from(
        {length : n},
        () => Array.from({length : n},
                         () => Array(2).fill(-1)));
    return countRecur(0, n - 1, 1, s, memo);
}

// driver code
const s = "T|T&F^T";
console.log(countWays(s));

// ***************************************************************Intuition****************************************************************************************

We try all possible places to partition the expression at every operator.

We define:

dp[i][j][isTrue]

i → starting index

j → ending index

isTrue → 1 if we want expression to be True, 0 if False

It stores:

👉 Number of ways substring s[i…j] evaluates to isTrue.

🧠 Transition Logic

For every operator at position k:

Left: i → k-1

Right: k+1 → j

We calculate:

LT = ways left is True
LF = ways left is False
RT = ways right is True
RF = ways right is False

Then combine according to operator:

If operator is &
True  = LT * RT
False = LT*RF + LF*RT + LF*RF
If operator is |
True  = LT*RT + LT*RF + LF*RT
False = LF*RF
If operator is ^
True  = LT*RF + LF*RT
False = LT*RT + LF*RF
