class Solution {
public:
    string simplifyPath(string path) {
        string res;
        
        stack<string>Stack;
        int n = path.size();
        for(int i =0;i<n;i++){
            if(path[i] == '/'){
                continue;
            }
            string word;
            while(i < n && path[i] != '/'){
                word+= path[i];
                i++;

            }
            if(word == "."){
                continue;
            }
            if(word == ".."){
                if(Stack.size() != 0){
                    Stack.pop();
                    continue;
                }
            }
            else{
                Stack.push(word);
            }
        }
        while(!Stack.empty()){
            res = "/" + Stack.top() + res;
            Stack.pop();
        }
        if(res.size() == 0){
            return "/";
        }
        return res;
    }
    
};