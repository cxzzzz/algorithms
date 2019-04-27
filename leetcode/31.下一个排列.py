#
# @lc app=leetcode.cn id=31 lang=python3
#
# [31] 下一个排列
#
# https://leetcode-cn.com/problems/next-permutation/description/
#
# algorithms
# Medium (30.08%)
# Total Accepted:    9.3K
# Total Submissions: 30.8K
# Testcase Example:  '[1,2,3]'
#
# 实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
# 
# 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
# 
# 必须原地修改，只允许使用额外常数空间。
# 
# 以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
# 1,2,3 → 1,3,2
# 3,2,1 → 1,2,3
# 1,1,5 → 1,5,1
# 
#

from typing import List

class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """

        for i in range(len(nums)-1,-1,-1):
            j = i-1
            if( j>=0 and nums[j] >= nums[i] ):
                continue
            else:
                nums[i:] = sorted(nums[i:])
                for k in range(i,len(nums)):
                    if j>= 0 and nums[j]<nums[k]:
                        tmp = nums[j]
                        nums[j]=nums[k]
                        nums[k]=tmp
                        break
                return 
                
k = [5,1,1]
Solution().nextPermutation(k)
print(k)

        

