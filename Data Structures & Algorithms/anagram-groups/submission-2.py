class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagramMap = {}

        for word in strs:
            temp = word;
            temp = ''.join(sorted(word))

            if temp in anagramMap.keys():
                anagramMap[temp].append(word)
            else:
                result = []
                result.append(word)
                anagramMap[temp] = result
        
        res = []
        for anagrams in anagramMap.values():
            res.append(anagrams)
        return res;
        