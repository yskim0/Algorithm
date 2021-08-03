class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        if haystack=="" and needle=="": return 0
        idx = haystack.find(needle)
        return idx
