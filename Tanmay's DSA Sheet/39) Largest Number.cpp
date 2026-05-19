Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

Since the result may be very large, so you need to return a string instead of an integer.

 

Example 1:

Input: nums = [10,2]
Output: "210"
Example 2:

Input: nums = [3,30,34,5,9]
Output: "9534330"


class Solution {
public:
    
    static bool cmp(string a, string b){
        return a + b > b + a;
    }

    string largestNumber(vector<int>& nums) {
        
        vector<string> v;

        for(int x : nums){
            v.push_back(to_string(x));
        }

        sort(v.begin(), v.end(), cmp);

        if(v[0] == "0"){
            return "0";
        }

        string ans = "";

        for(string s : v){
            ans += s;
        }

        return ans;
    }
};
