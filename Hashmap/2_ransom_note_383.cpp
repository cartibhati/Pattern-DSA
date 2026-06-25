class Solution {
public:
    bool fun(unordered_map<char,int>have,unordered_map<char,int>need ){
        for(auto i:need){
            char c = i.first;
            int fneed = i.second;
            int fhave = have[c];

            if(fhave<fneed)
            return false;
        }
        return true;
    }
    bool canConstruct(string ransom, string magzine) {
        unordered_map<char,int>have;
        unordered_map<char,int>need;
        for(int i=0;i<ransom.size();i++){
            need[ransom[i]]++;
        }
        for(int i=0;i<magzine.size();i++){
            have[magzine[i]]++;
        }
        return fun(have,need);
    }
};