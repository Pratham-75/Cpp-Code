//contains duplicate

#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         map<int, int> countMap;
//         for (int i = 0; i < nums.size(); i++) {
//             if(countMap[nums[i]]) {
//                 return true;
//             }
//             countMap[nums[i]]++;
//         }
//         return false;
//     }
// };


//Maximum Subarray


int main() {
    int n;
    cin>>n;
    int a[n] = {0};
    for (int j = 0; j < n; j++)
    {
        cin>>a[j];
    }
    
    for (int i = 0; i < n-1; i++)
    {
        int sum = 0;
        for (int j = 0; j < n-1; j++)
        {
            sum += a[j];    
        }
        cout<<sum<<endl;
        // n = n-1;
    }
    
    
}

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         vector<int> nums;
//         int sum = 0;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             while (i>0)
//             {
//                 sum+=nums[i];

//             }
            
//         }
        
//     }
// };