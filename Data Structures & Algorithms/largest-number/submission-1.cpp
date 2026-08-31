class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a ,int b){
            if(to_string(a) + to_string(b) > to_string(b) + to_string(a)){
                return true;
            }else{
                return false;
            }
        });
        if(nums[0] == 0){
            return "0";
        }
        string result; 
        for(auto it : nums)
        {
            result  += to_string(it);
        }
        return result;
    }
};
/* thinking ...
3 30 34 5 9
95343330

if we consider taking a hashmap how can we solve it using that 

if i sort this array it can be different
3 5 9 30 34
smallest at last and largest at the right most
what can we do to make it a largest number
we sort them on the basis of wherever larger number is awailable for ex
9 
5
34
3
30

larger
that too on the tens place for ten digit and ones place for one digit
leftmost digit should be larger
how will we do that
how can we implement this
*/