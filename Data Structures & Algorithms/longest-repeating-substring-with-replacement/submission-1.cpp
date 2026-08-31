class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        vector<int>vt(26,0);
        int n = s.size();
        int max_count = 0;
        int max_len = 0;
        for(int right = 0; right < s.size(); right++){
            vt[s[right] - 'A']++;
            int current = vt[s[right] - 'A'];
            max_count = max(max_count ,current);
            while(right-left +1 -max_count > k){
                vt[s[left] - 'A']--;
                left++;
            }
            max_len = max(max_len, right - left + 1);

        }
        return max_len;
        
    }
};
