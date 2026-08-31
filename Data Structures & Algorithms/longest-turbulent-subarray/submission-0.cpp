class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        //sliding window approach
        string prev = "";
        int l = 0; 
        int r = 1; 
        int count = 1;
        while(r < arr.size()){
            if(arr[r] > arr[r-1] && prev != ">"){
                count = max(count,r - l + 1);
                r++;
                prev = ">";
                
            }
            else if(arr[r] < arr[r-1] && prev != "<"){
                count = max(count, r - l + 1);
                r++;
                prev = "<";
                
            }
            else if(arr[r] == arr[r-1]){
                prev = "";
                l = r;
                r++;
                
            }
            else if(arr[r] < arr[r-1] && prev == "<"){
                prev = "<";
                l = r-1;
                r++;
            }else if(arr[r] > arr[r-1] && prev == ">"){
                prev = ">";
                l = r -1;
                r++;
            }
        }
        return count;
    }
};
/*thinking..
sliding window
two pointers 
greedy  
order matters so no sorting
we can think of sliding window
sliding window is the approach but how we can create a window

*/