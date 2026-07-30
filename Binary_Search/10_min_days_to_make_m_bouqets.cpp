class Solution {
public:
    int max(vector<int>&a){ 
        int maxi=INT_MIN;
        for(int i=0;i<a.size();i++){
            if(a[i]>maxi)
            maxi=a[i];
        }
        return maxi;
    }
    bool canMake(vector<int>& bloomDay, int day, int m, int k) {
    int flowers = 0;
    int bouquets = 0;

    for (int i=0;i<bloomDay.size();i++) {
        if(bloomDay[i]<=day){// if flower has bloomed
            flowers++;//     flowers++;
        }
        else
        flowers=0;

        if(flowers==k){
        bouquets++;
        flowers=0;
        }
    }

    return bouquets >= m;
}

    int minDays(vector<int>& bloomDay, int m, int k) {
        int low=1;
        int high=max(bloomDay);
        int res=-1;
        while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canMake(bloomDay, mid, m, k)) {
            res = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return res;
    }
};
