#
# @lc app=leetcode.cn id=3 lang=python3
#
# [3] 无重复字符的最长子串
#
# https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
#
# algorithms
# Medium (28.49%)
# Total Accepted:    90.4K
# Total Submissions: 316.6K
# Testcase Example:  '"abcabcbb"'
#
# 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
# 
# 示例 1:
# 
# 输入: "abcabcbb"
# 输出: 3 
# 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
# 
# 
# 示例 2:
# 
# 输入: "bbbbb"
# 输出: 1
# 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
# 
# 
# 示例 3:
# 
# 输入: "pwwkew"
# 输出: 3
# 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
# 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
# 
# 
#
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        idx = dict()
        s=list(s)  
        begin=0

        m = 0
        for i in range(0,len(s)):
            if idx.get(s[i],-1) == -1:
                idx[s[i]]= i
                m= max(m, i-begin+1)
                continue
            else:
                for j in range(begin,idx[s[i]]) :
                    idx.pop(s[j])

                begin = idx[s[i]]+1
                idx[s[i]] = i

        return m

print( Solution().lengthOfLongestSubstring("abcabcbb"))


