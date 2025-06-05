class Solution {
public:
    double myPow(double x, int n) {
        long long z=n;
        if(z<0){
            x=1/x;
            z=-z;
        }
        double res=1.0;
        while(z>0){
            if(z%2 !=0){
                res *=x;
            }
            x *=x;
            z /=2;
        }
        return res;
    }

};