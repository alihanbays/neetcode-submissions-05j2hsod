class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        targetMap = {}

        for i in range(len(nums)):
            needs = target - nums[i]

            # Do I have it in my hashmap already?
            if needs in targetMap.keys():
                # I've found the pair
                if i < targetMap[needs]:
                    return [i, targetMap[needs]]
                return [targetMap[needs], i]
            targetMap[target-needs] = i
        return [0,0]