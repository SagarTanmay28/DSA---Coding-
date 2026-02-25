class Solution {
public:

    bool isPredecessor(string &small, string &big){
        if(big.length() != small.length() + 1)
            return false;

        int i = 0, j = 0;

        while(i < small.length() && j < big.length()){
            if(small[i] == big[j]){
                i++; j++;
            }
            else{
                j++;
            }
        }

        return i == small.length();
    }

    int longestStrChain(vector<string>& words) {

        sort(words.begin(), words.end(),
             [](string &a, string &b){
                 return a.length() < b.length();
             });

        int n = words.size();
        vector<int> dp(n, 1);

        int maxi = 1;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){

                if(isPredecessor(words[j], words[i])){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }
};
