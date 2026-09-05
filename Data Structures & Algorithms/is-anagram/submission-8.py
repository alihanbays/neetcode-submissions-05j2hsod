class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        letters1 = {}
        letters2 = {}

        for char in s:
            if char in letters1.keys():
                letters1[char] += 1
            else:
                letters1[char] = 0;
        

        for char in t:
            if char in letters2.keys():
                letters2[char] += 1
            else:
                letters2[char] = 0;
        
        if len(letters1) != len(letters2):
            return False

        for i in s:
            if i not in letters1.keys() or i not in letters2.keys() or letters1[i] != letters2[i]:
                return False

        return True;