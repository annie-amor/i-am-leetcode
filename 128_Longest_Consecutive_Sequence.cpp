class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return 1;
        
        std::unordered_set<int> mySet;
        for(int i = 0; i<nums.size(); i++)
            mySet.insert(nums[i]);

        int countFinal = 0;
        
        for(int i = 0; i<nums.size(); i++)
        {
            int countTemp = 0;
            int num = nums[i];
            // 1st check if left neighbor is in the vector
            //remember, mySet.count returns 1 if found, 0 of otherwise
            if(mySet.count(num - 1) == 0){ // check if no predecessor
                countTemp++;
                num++;
                while(mySet.count(num) != 0){
                    countTemp++;
                    num++;
                }

            }else
                continue;

            countFinal = max(countTemp, countFinal);
        }

        return countFinal;
    }
};
