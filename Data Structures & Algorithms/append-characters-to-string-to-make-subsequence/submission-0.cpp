class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0; 
        int j = 0; 
        while(i < s.size() && j < t.size()){
            if(s[i] == t[j]){
                i+= 1; 
                j+=1;
            }
            else{
                i+=1;
            }
        }
        return t.length() - j;
    }
};
/* thinking
 think of all the examples 
 coaching coding 
 coachingding 
 co and co of coaching and coding are same 
 how can we find minimum number of character needed to be appended
 coaching 
 coding
 ding 
 is not common from both 
 z abcde 
 abcde is not in s 
 so zabcde is taken 
 if some letters of t matches some letters of s then finding only the letters which are not matching works
 no of letters which are not matching from t to s
 coaching cooking 
 co is common
 ing is common
 but ding is not 
 so for coing it's okay
 but in order to get the ans 
 adding oking works
codding coding
hashmaps is a possiblity 
checking the availablity of c o d and 
why does it work 
coaching coding 
no d add a d append it
coachingd

*/