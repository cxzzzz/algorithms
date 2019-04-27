#
# @lc app=leetcode.cn id=24 lang=python3
#
# [24] 两两交换链表中的节点
#
# https://leetcode-cn.com/problems/swap-nodes-in-pairs/description/
#
# algorithms
# Medium (57.77%)
# Total Accepted:    15.3K
# Total Submissions: 26.4K
# Testcase Example:  '[1,2,3,4]'
#
# 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
# 
# 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
# 
# 
# 
# 示例:
# 
# 给定 1->2->3->4, 你应该返回 2->1->4->3.
# 
# 
#
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:

        if( head == None  or head.next==None):
            return head
        hn = head.next

        n_pre = ListNode(0)
        n_pre.next=head
        while n_pre.next !=None and n_pre.next.next !=None:
            n = n_pre.next
            n_pre.next = n.next
            n.next = n.next.next
            n_pre.next.next = n
            n_pre = n_pre.next.next

        return hn

in1 = ListNode(1)
in2 = ListNode(2)
in3 = ListNode(3)

in1.next = in2
in2.next = in3

i=Solution().swapPairs(in1)
while i != None:
    print(i.val)
    i=i.next





        

