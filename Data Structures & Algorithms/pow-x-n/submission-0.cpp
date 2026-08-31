class Solution {
public:
    double res = 1;

    double myPow(double x, int n) {
        double ans = solve(x,n);
        return (n>0) ? ans : 1/ans;
    }
    double solve(double x, int n){
        if(x == 0){
            return 0;
        }
        if(n == 0){
            return 1;
        }
        res = solve(x, n/2);
        res = res * res; 
        return (n%2 == 0) ? res : res*x;
    }
};
