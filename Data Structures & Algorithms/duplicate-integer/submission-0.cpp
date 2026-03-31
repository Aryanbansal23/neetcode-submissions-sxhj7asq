class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int>p;
        for(int i : nums){
            p.insert(i);
        }
        int q=nums.size();
        int w = p.size();
        if(q==w){
            return false;
        }
        else{
            return true;
        }
        
    }
};