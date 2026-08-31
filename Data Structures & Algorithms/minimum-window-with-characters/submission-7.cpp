class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>charcount(128,0);
        int x = t.size(),left =0,right = 0, minLen = INT_MAX,head = 0;
        for(char ch : t)charcount[ch]++;
        while(right < s.size()){
            if(charcount[s[right++]]-->0){x--;}
            while(x == 0){
                if(right-left < minLen)minLen = right-(head = left);
                if(charcount[s[left++]]++ == 0)x++;
            }
            
        }
        return minLen == INT_MAX?"":s.substr(head,minLen);
    }
};
