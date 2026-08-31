class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int avg = 0; 
        int n = arr.size();
        for(int i =0;i<k;i++){
            avg += arr[i];
            
        }
        int count = 0;
        for(int i =k;i<=n;i++){
            if(avg/k >= threshold){
                count++;
            }
            avg = avg - arr[i-k];
            avg += arr[i];
        }
        return count;
    }
};