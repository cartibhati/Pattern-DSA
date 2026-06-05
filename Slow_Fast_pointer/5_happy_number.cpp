class Solution {
public:
    int sumOfSq(int n){
        int sum=0;
        while(n>0){
            int d=n%10;
            n=n/10;
            sum+=d*d;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow=n;
        int fast=n;
        while(fast!=1){
            slow = sumOfSq(slow);
            fast = sumOfSq(sumOfSq(fast));

            if(slow==fast && slow!=1){
                return false;
            }
        }
        return true;
    }
};