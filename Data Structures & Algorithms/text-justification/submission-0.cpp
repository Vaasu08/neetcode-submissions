class Solution {
public:
    int MAX_WIDTH;
    string FinalLine(int i , int j , int EachSpace, int ExtraSpaces, vector<string>&words){
        string line;
        for(int z = i; z < j; z++){
            line += words[z];
            if(z == j -1){
                continue;
            }
            for(int a = 0; a < EachSpace; a++){
                line += " ";
            }
            if(ExtraSpaces>0){
                line += " ";
                ExtraSpaces--;
            }

        }
        while(line.length() < MAX_WIDTH){
            line+= " ";
        }
        return line;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        MAX_WIDTH = maxWidth; // public variable define to use it everywhere
        int i =0;
        int spaces = 0;
        int n = words.size();
        vector<string>result; 
        while(i < words.size()){

            int j = i+1;
            int lettercount = words[i].size();
            spaces = 0;
            while(j < n && lettercount + 1 + spaces + words[j].size()<= maxWidth){
                lettercount+= words[j].size();
                spaces++; 
                j++;

            }
            int AllSpaces = maxWidth - lettercount;
            int EachSpace = (spaces == 0)? 0 : AllSpaces/spaces;
            int ExtraSpaces =  (spaces == 0)? 0 : AllSpaces%spaces;
            if(j == n){
                EachSpace = 1; 
                ExtraSpaces = 0;
            }
            result.push_back(FinalLine(i , j , EachSpace, ExtraSpaces, words));
            i = j;


        }
        return result;

    }
};
/*thinking...
traversing thru each word

*/