class Solution:
    def isPalindrome(self, s: str) -> bool:

        newString = "".join(char.lower() for char in s if char.isalnum())

        L, R = 0, len(newString) - 1

        while L < R:
            if newString[L] != newString[R]:
                return False

            L += 1
            R -= 1
            
        return True