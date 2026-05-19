#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    int x;
    cin>>x;
     
     // INPUT
    vector <int> v;
    for(int i=0;i<n;i++){
        int q;
        cin>>q;
        v.push_back(q);
    }
   
   // CONCEPT
    for(int i=0;i<=v.size()-2;i++){
        for(int j=i+1;j<=v.size()-1;j++){
            if(v[i]+v[j]==x) cout<<"("<<i<<","<<j<<")"<<endl;
            
        }
    }
}

// int n=nums.size();
//        for(int i=0;i<=n-2;i++){
//         for(int j=i+1;i<=n-1;j++){
//             if ( nums[i] + nums[j] == target) {
//               return {i, j};
//             }
//           }
//        }

//         return {};
//        }
    
// };