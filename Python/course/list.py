class ListNode:
    def __init__(self, v):
        self.value = v
        self.next = None

head = ListNode(1)
head.next = ListNode(2)
head.next.next = ListNode(3)

node = head
while node:
    print node.value
    node = node.next
