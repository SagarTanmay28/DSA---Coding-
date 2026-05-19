class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();

        unordered_map<char,int> mp1,mp2;

        for(char ch : s1) mp1[ch]++;

        int i = 0;
        int j = 0;
        // Sliding Window 
        while(j < n2){
            mp2[s2[j]]++;

            while(j-i+1 > n1){
                mp2[s2[i]]--;
                if(mp2[s2[i]] == 0) mp2.erase(s2[i]);
                i++;
            }

            if(n1 == j - i + 1){
                if(mp1 == mp2) return true;
            }
           
            
            j++;
        }

        return false;
        
    }
};
