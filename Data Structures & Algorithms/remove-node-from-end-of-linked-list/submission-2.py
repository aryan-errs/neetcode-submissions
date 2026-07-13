# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        falseHead = ListNode(0)
        falseHead.next = head
        slow, fast = falseHead, falseHead
        for i in range(n):
            fast = fast.next
        print(fast.val)
        while fast.next:
            slow = slow.next
            fast = fast.next
        tmp = slow.next
        print(tmp.val)
        slow.next = slow.next.next
        return falseHead.next