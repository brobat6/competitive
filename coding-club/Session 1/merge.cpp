// https://leetcode.com/problems/merge-intervals/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        array <int,2> arr[n];
        for(int i=0;i<n;i++) {
            arr[i][0] = intervals[i][0];
            arr[i][1] = intervals[i][1];
        }
        sort(arr,arr+n);
        vector <vector<int>> v;
        int start=arr[0][0],end=arr[0][1];
        for (int i=1; i<n; i++) {
            if (arr[i][0]<=end) {
                if (arr[i][1]>end) {
                    end = arr[i][1];
                }
            }
            else {
                v.push_back({start,end});
                start = arr[i][0];
                end = arr[i][1];
            }
        }
        v.push_back({start,end});
        return v;   
    }
};