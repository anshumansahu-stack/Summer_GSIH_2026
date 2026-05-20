#include <bits/stdc++.h>
using namespace std;

vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map <int,int> mpp;
        // lengths of both vectors are same
        int len=A.size();
        vector<int> prefixCommonArray;
        for(int i=0;i<len;i++){
            int comElements=0;
            mpp[A[i]]++;
            mpp[B[i]]++;
            for(auto it:mpp){
                if(it.second==2){
                    comElements++;
                }
            }
            prefixCommonArray.push_back(comElements);
        }
        return prefixCommonArray;
    }// Solved in Leetcode
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    
    return 0;
}