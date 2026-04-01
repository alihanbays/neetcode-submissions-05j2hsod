class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        countMap = {}

        for n in nums:
            if n in countMap:
                countMap[n] += 1
            else:
                countMap[n] = 1


        # have the indexes be the number of occourences aka countMap.values()
        # and make the values be the array of number of that elements

        values = [[] for i in range(len(nums) + 1)]
        for key in countMap:
            values[countMap[key]].append(key)

        res = []
        for n in reversed(values):
            for val in n:
                if k == 0: break;
                res.append(val)
                k -= 1
        return res

        
            