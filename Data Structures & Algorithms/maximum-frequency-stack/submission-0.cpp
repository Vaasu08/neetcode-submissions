class FreqStack {
public:
    unordered_map<int,int>freq;
    unordered_map<int, stack<int>>group;
    int maxfreq;
    FreqStack() {
        maxfreq = 0;
    }
    
    void push(int val) {
        freq[val]++;
        int f = freq[val];
        group[f].push(val);
        maxfreq = max(maxfreq, f);
    }
    
    int pop() {
        int a = group[maxfreq].top();
        group[maxfreq].pop();
        freq[a]--;
        if(group[maxfreq].empty()){
            maxfreq--;
        }
        return a;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */


 /*thinking...
 5 7 5 7 4 5
 freq = 5 ; 3times
 remove 5
 every time an element is inserted , we have to keep track of all the elements frequency using hashmap
 max of stack element will be stored along with it's value;
 we have to remove the value and retain the stack structure 
 how can we do that
 if we foubnd
 we can use another stack for this we pop the element until we found new
 */