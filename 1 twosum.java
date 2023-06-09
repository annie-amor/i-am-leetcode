class Solution {
    public int[] twoSum(int[] nums, int target) {
        int indices [] = new int[2];
    Map<Integer, Integer> map = new HashMap<Integer, Integer>();
    for(int i = 0; i<nums.length; i++){
        if(map.containsKey(target - nums[i])){
            indices[1] = i;
            indices[0] = map.get(target - nums[i]);
            return indices;
        }
        map.put(nums[i], i);
    }

    return indices;
}

}
