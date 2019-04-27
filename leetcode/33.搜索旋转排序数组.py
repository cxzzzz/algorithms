#
# @lc app=leetcode.cn id=33 lang=python3
#
# [33] 搜索旋转排序数组
#
# https://leetcode-cn.com/problems/search-in-rotated-sorted-array/description/
#
# algorithms
# Medium (35.86%)
# Total Accepted:    17K
# Total Submissions: 47.4K
# Testcase Example:  '[4,5,6,7,0,1,2]\n0'
#
# 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
# 
# ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
# 
# 搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
# 
# 你可以假设数组中不存在重复的元素。
# 
# 你的算法时间复杂度必须是 O(log n) 级别。
# 
# 示例 1:
# 
# 输入: nums = [4,5,6,7,0,1,2], target = 0
# 输出: 4
# 
# 
# 示例 2:
# 
# 输入: nums = [4,5,6,7,0,1,2], target = 3
# 输出: -1
# 
#
from typing import List
class Solution:



    def search(self, nums: List[int], target: int) -> int:
        start = 0
        end = len(nums)-1

        if end <0:
            return -1

        while(start < end):
            pos = (start+end)//2
            if nums[pos]> nums[start]:
                start = pos
            elif nums[pos] < nums[start]:
                end = pos - 1
            else:
                break
        
        if nums[start] > nums[end]:
            pos = start
        else:
            pos = end


        def find(nums:List[int],start:int,end:int,target:int) -> int:
            if start > end or end >= len(nums):
                return -1

            while(start < end):
                pos = (start+end)//2
                if nums[pos] == target:
                    break
                elif nums[pos] > target:
                    end = pos -1
                else:
                    start = pos + 1

            pos = (start+end)//2
            if(nums[pos]!= target):
                return -1
            else:
                return pos

        a = find(nums,0,pos,target)
        b = find(nums,pos+1,len(nums)-1,target)

        if( a<0 and b <0 ):
            return -1
        elif a>=0:
            return a
        elif b>=0:
            return b
             

print ( Solution().search([4,5,6,7,8,1,2,3],8))
print ( Solution().search([1,],1))
print ( Solution().search([3,4,5,-1,0],0))
print ( Solution().search([3,4,5,-1,],5))
print ( Solution().search([3,4,5,-1,],2))
        


                    


        
        

