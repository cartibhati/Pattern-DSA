class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>f;
        for(int i=0;i<s.size();i++){
            f[s[i]]++;
        }
        bool odd = false;
        int res=0;
        for(auto i:f){
            int val = i.second;
            if(val%2==0){
                res+=val;
            }
            else
            odd=true;
        }

        if(odd==false)
        return res;

        for(auto i:f){
            int val = i.second;
            if(val%2==1)
            res+=val-1;
        }
        return res+1;//last me string ke bad jitne odd bache unme se kisi ek ko bich me ek bar add krna pdta hai
    }
};