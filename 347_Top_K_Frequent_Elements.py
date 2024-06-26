class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        table = {} # key is the number in the list 'nums'
        #value is the frequency of the number
        result = []
        n = len(nums)

        for num in range(n):
            curr = nums[num]
            if curr in table:
                table[curr] += 1
            else:
                table[curr] = 1

        for x in range(k):
            max_value = max(table, key = table.get)
            # print(max_value)
            result.append(max_value)
            table.pop(max_value)

        return result
