class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>stkpair;
        for(int i =0; i < s.size();i++){
            if(!stkpair.empty() && stkpair.top().first == s[i]){
                stkpair.top().second++;
                if(stkpair.top().second == k){
                    stkpair.pop();
                }

            }else{
                stkpair.push({s[i],1});
            }
        }
        string result = "";
        while(!stkpair.empty()){
            char a = stkpair.top().first;
            int cnt = stkpair.top().second;
            while(cnt--){
                result+= stkpair.top().first;
                

            }
            stkpair.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};