// Method 1 
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        int i = 0;

        for(int j = 0; j < n; j++) {
            if(nums[j] != 0) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
    }
};

// Method 2 
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int j = -1;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                j = i;
                break;
            }
        }
        if(j==-1) return; // if zeroes are not present 
        int i = j+1;
        while(i<n){
            if(nums[i]!=0){
                swap(nums[i],nums[j]);
                j++;
            }
            i++;  
        }    
        
    }
};
