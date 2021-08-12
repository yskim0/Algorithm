class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        tmp = "".join(str(n) for n in digits)
        tmp_n = str(int(tmp) + 1)
        ans = [i for i in tmp_n]
        return ans
        
