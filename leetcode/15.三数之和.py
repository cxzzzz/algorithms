#
# @lc app=leetcode.cn id=15 lang=python3
#
# [15] 三数之和
#
# https://leetcode-cn.com/problems/3sum/description/
#
# algorithms
# Medium (21.33%)
# Total Accepted:    40.6K
# Total Submissions: 189.6K
# Testcase Example:  '[-1,0,1,2,-1,-4]'
#
# 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0
# ？找出所有满足条件且不重复的三元组。
# 
# 注意：答案中不可以包含重复的三元组。
# 
# 例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
# 
# 满足要求的三元组集合为：
# [
# ⁠ [-1, 0, 1],
# ⁠ [-1, -1, 2]
# ]
# 
# 
#
from typing import List
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        solution = set()
        nums=sorted(nums)
        for i in range( 0 , len(nums)):
            k=nums[i]
            begin = i+1
            end = len(nums)-1
            while(begin < end):
                if(nums[begin] + nums[end] + k == 0):
                    solution.add( (k,nums[begin],nums[end]))
                    begin +=1
                    end -=1
                elif(nums[begin] + nums[end] + k > 0):
                    end -=1
                else:
                    begin +=1

        return list(solution)

print(Solution().threeSum([-1,0,1,2,-1,-4]))
                 

        

