class Solution {
public:
    bool isVowel(char& c){
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int>prefixsum(n+1,0);
        for(int i =0; i < words.size(); i++){
            char start = words[i][0];
            char end = words[i].back();
            if(isVowel(start) && isVowel(end)){
                prefixsum[i+1] = prefixsum[i]+1; 
            }
            else{
                prefixsum[i+1] = prefixsum[i];

            }
        }
        int m = queries.size();
        vector<int>result;
        for(auto it : queries){
            result.push_back(prefixsum[it[1]+1] - prefixsum[it[0]]);
        }
        return result;
    }
};
/*
thinking...
defining a function which return vowel or not makes things easier a bit

*/