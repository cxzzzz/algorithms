#
# @lc app=leetcode.cn id=507 lang=python3
#
# [507] 完美数
#
# https://leetcode-cn.com/problems/perfect-number/description/
#
# algorithms
# Easy (33.73%)
# Total Accepted:    3.8K
# Total Submissions: 11.2K
# Testcase Example:  '28'
#
# 对于一个 正整数，如果它和除了它自身以外的所有正因子之和相等，我们称它为“完美数”。
# 
# 给定一个 正整数 n， 如果他是完美数，返回 True，否则返回 False
# 
# 
# 
# 示例：
# 
# 
# 输入: 28
# 输出: True
# 解释: 28 = 1 + 2 + 4 + 7 + 14
# 
# 
# 
# 
# 注意:
# 
# 输入的数字 n 不会超过 100,000,000. (1e8)
# 
#

class Solution:
    def checkPerfectNumber(self, num: int) -> bool:
        if num ==1:
            return False

        sum=1
        a=2
        while( a*a < num):
            if( num % a == 0):
                sum += a
                sum += (num // a)
            a+=1

        if( a*a == num):
            sum += a
        
        return  sum == num

print ( Solution().checkPerfectNumber( 28))
        
        

