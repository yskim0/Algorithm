class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        shortest_str = min(strs, key=lambda n:len(n))
        shortest_len = len(shortest_str)
        result = ""
        for i in range(shortest_len):
            for j in range(len(strs)-1):
                if strs[j][i] == strs[j+1][i]: pass
                else: return result
            result += strs[0][i]
        return result
