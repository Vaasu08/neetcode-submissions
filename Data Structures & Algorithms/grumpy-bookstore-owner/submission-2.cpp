class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int validsum = 0;
        int res = 0;
        for(int i =0;i<customers.size();i++){
            if(grumpy[i] == 0){
                validsum+= customers[i];
            }
        }
        
        int sum = 0;
        for(int i = 0; i < minutes; i++){
            if(grumpy[i] == 1){
                sum+= customers[i];
            }
        }
        res = sum;
        for(int i = minutes;i<customers.size();i++)
        {
            if(grumpy[i] == 1 && grumpy[i - minutes] == 1)sum += customers[i] - customers[i-minutes];
            else if(grumpy[i] == 1 && grumpy[i-minutes] == 0)sum += customers[i];
            else if(grumpy[i] == 0 && grumpy[i-minutes] == 1) sum-= customers[i-minutes];
            else{
                continue;
            }
            res = max(res, sum);
        }
        return res + validsum;
    }
};