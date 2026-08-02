You are given a string s of lowercase English letters and a 2D integer array shifts where shifts[i] = [starti, endi, directioni]. For every i, shift the characters in s from the index starti to the index endi (inclusive) forward if directioni = 1, or shift the characters backward if directioni = 0.

Shifting a character forward means replacing it with the next letter in the alphabet (wrapping around so that 'z' becomes 'a'). Similarly, shifting a character backward means replacing it with the previous letter in the alphabet (wrapping around so that 'a' becomes 'z').

Return the final string after all such shifts to s are applied.

 

Example 1:

Input: s = "abc", shifts = [[0,1,0],[1,2,1],[0,2,1]]
Output: "ace"
Explanation: Firstly, shift the characters from index 0 to index 1 backward. Now s = "zac".
Secondly, shift the characters from index 1 to index 2 forward. Now s = "zbd".
Finally, shift the characters from index 0 to index 2 forward. Now s = "ace".
Example 2:

Input: s = "dztz", shifts = [[0,0,0],[1,1,1]]
Output: "catz"
Explanation: Firstly, shift the characters from index 0 to index 0 backward. Now s = "cztz".
Finally, shift the characters from index 1 to index 1 forward. Now s = "catz".

//Approach (Using Difference Array Technique)
//T.C : O(m+n), m = length of queries, n = length of array
//S.C : O(n)
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n , 0); // Difference array with size n + 1
        
        // Step 1: Populate the difference array
        for (const auto& shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2];
            
            if (direction == 1) { // Forward shift
                diff[start] += 1;
                if(end+1 < n)
                    diff[end + 1] -= 1;
            } else { // Backward shift
                diff[start] -= 1;
                if(end+1 < n)
                    diff[end + 1] += 1;
            }
        }
        
        // Step 2: Compute the prefix sum to get the net shifts for each character
        for (int i = 1; i < n; ++i) {
            diff[i] += diff[i - 1]; // Add the value from the previous index
        }
        
        // Step 3: Apply the shifts to the string
        for (int i = 0; i < n; ++i) {
            int shift = diff[i] % 26; // Ensure shift is within the range [0, 25]
            if (shift < 0)
                shift += 26; // Handle negative shifts (backward)
            
            // Apply the shift to character
            s[i] = ((s[i] - 'a' + shift) % 26) + 'a';
            /*
                Note : s[i]-'a' gives the corresponding number of character s[i]
                       +shift adds the shift
                       %26 is to wrap around (0-25)
                       'a' + in the end converts back the number to character
            */
        }
        
        return s;
    }
};
