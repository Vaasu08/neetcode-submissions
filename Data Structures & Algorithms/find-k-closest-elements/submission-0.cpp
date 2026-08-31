class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>result;
        int l = 0;
        int r = arr.size() -k;
        while(l < r){
            int m = l + (r-l)/2;
            if((abs(x - arr[m])) > abs(arr[m+k]-x)){
                l = m+1;
            }else{
                r = m;
            }
        }
        for(int i = l;i<l+k;i++){
            result.push_back(arr[i]);
        }
        return result;
        
    }
};