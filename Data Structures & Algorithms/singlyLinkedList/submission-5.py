class Node:
    
    def __init__(self, val, next=None):
        self.val = val
        self.next = next

class LinkedList:
    
    def __init__(self):
        self.head = Node(-1)
    
    def get(self, index: int) -> int:
        curr = self.head.next
        for i in range(index):
            if not curr:
                return -1
            curr = curr.next
        if not curr:
            return -1
        return curr.val


    def insertHead(self, val: int) -> None:
        node = Node(val)
        node.next = self.head.next
        self.head.next = node


    def insertTail(self, val: int) -> None:
        curr = self.head
        while curr.next:
            curr = curr.next
        node = Node(val)
        curr.next = node

    def remove(self, index: int) -> bool:
        curr = self.head
        for i in range(index):
            if not curr.next:  
                return False
            curr = curr.next
        if not curr.next:
            return False
        temp = curr.next
        curr.next = curr.next.next
        del temp
        return True

            

    def getValues(self) -> List[int]:
        arr = []
        curr = self.head.next
        while curr:
            arr.append(curr.val)
            curr = curr.next
        return arr
