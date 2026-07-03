class Solution {
public:
    long long fun(vector<int>&a,int n,int speed){
        long long h=0;
        for(int i=0;i<n;i++){
            h=h+a[i]/speed;
            if(a[i]%speed!=0)
            h++;
        }
        return h;
    }
    int max(vector<int>&a){
        int maxi=INT_MIN;
        for(int i=0;i<a.size();i++){
            if(a[i]>maxi)
            maxi=a[i];
        }
        return maxi;
    }
    int minEatingSpeed(vector<int>& a, int h) {
        int res=-1;
        int s=1;
        int e=max(a);
        int n=a.size();
        while(s<=e){
            int mid=s+(e-s)/2;
            long long hr=fun(a,n,mid);
            if(hr>h)
            s=mid+1;
            else{
                res=mid;
                e=mid-1;
            }
        }
        return res;
    }
};