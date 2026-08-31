class Solution {
public:
    string repeatedString(string s, int k){
        string repeatedstring;
        for(int i =0;i<k;i++){
            repeatedstring += s;
        }
        return repeatedstring;
    }
    string decodeString(string s) {
        int n = s.size();
        stack<string>Stack;
        for(int i = 0;i<n;i++){
            if(s[i] != ']'){
                Stack.push(string(1,s[i]));
            }
            else{
                string substr;
                while(Stack.top() != "["){
                    substr= Stack.top() + substr;
                    Stack.pop();
                }
                Stack.pop();
                string k = "";
                while(!Stack.empty() && isdigit(Stack.top()[0])){
                    k = Stack.top() + k;
                    Stack.pop();
                }
                int b = stoi(k);
                substr = repeatedString(substr,b);
                Stack.push(substr);
                
            }
        }
        string result = "";
        while(!Stack.empty()){
            result = Stack.top() + result;
            Stack.pop();
        }
        return result;
    }
};