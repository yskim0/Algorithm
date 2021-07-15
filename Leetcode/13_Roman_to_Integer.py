class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        roman = {'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}
        result = 0
        for i in range(len(s)-1):
            num = roman[s[i]]
            next_num = roman[s[i+1]]
            if (num>=next_num):
                result += num
            else:
                result -= num
        result += roman[s[len(s)-1]]
        return result
