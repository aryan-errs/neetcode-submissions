# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        tmp = None
        ans = tmp
        carry = 0
        while l1 and l2:
            summ = l1.val + l2.val + carry
            digit = summ % 10
            carry = summ // 10
            node = ListNode(digit)
            if not tmp:
                tmp = node
                ans = tmp
            else:
                tmp.next = node
                tmp = tmp.next
            l1 = l1.next
            l2 = l2.next
        remaining = None
        if l1 or l2:
            remaining = l1 if l1 else l2
        while remaining or carry > 0:
            summ = carry
            if remaining:
                summ += remaining.val
            digit = summ % 10
            carry = summ // 10
            node = ListNode(digit)
            if not tmp:
                tmp = node
                ans = tmp
            else:
                tmp.next = node
                tmp = tmp.next
            if remaining:
                remaining = remaining.next
        return ans