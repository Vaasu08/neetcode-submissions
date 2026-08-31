class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size(); 
        while(n > 0 && digits[n-1] == 9){
            digits[n-1] = 0;
            n--;
            
        }
        if(n == 0){
            digits.insert(digits.begin(), 1); 
        }
        if(n > 0 )digits[n-1]++;
        return digits;
        

    }
};
