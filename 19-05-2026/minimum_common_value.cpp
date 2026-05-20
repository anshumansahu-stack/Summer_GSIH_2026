//Leetcode Daily Challenge
#include <bits/stdc++.h>
using namespace std;
int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int solnum=-1;
        int num1ptr=0,num2ptr=0;
        while(num1ptr<nums1.size() && num2ptr<nums2.size()){
            //start iterating over nums 1
            if(nums1[num1ptr]<nums2[num2ptr] && num1ptr<nums1.size()){
                num1ptr++;
            }
            else if(nums1[num1ptr]>nums2[num2ptr] && num2ptr<nums2.size()){
                num2ptr++;
            }
            else{
                if(nums1[num1ptr]==nums2[num2ptr]){
                    solnum=nums1[num1ptr];
                    break;
                }
            }
        }//O(nums1.size()+nums2.size())
        return solnum;
    }// Solved and submitted in Leetcode itself.
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    
    return 0;
}