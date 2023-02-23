"""
An equivalent Python implementation of the linked list
that was implemented in `linkedlist.c`.
"""

from typing import Any

class _Node(object):
    """Equivalent to `struct node`."""
    def __init__(self, item):
        self.item = item
        self.next = None

class LinkedList(object):
    """Equivalent to `struct linkedlist`."""
    head: _Node
    
    # equivalent to linkedlist_create.
    def __init__(self) -> None:
        self.head = None

    # equivalent to linkedlist_index.
    def __getitem__(self, idx: int) -> Any:
        if self.head is None:
            raise IndexError
        
        cur = self.head
        while idx > 1:
            cur = cur.next
            if cur is None:
                raise IndexError

        return cur.item

    # almost equivalent to linkedlist_print,
    # but returns a string rather than printing directly.
    def __str__(self) -> str:
        ret = ""
        cur = self.head
        while cur is not None:
            ret += f"{cur.item} -> "
            cur = cur.next
        
        ret += "END"

        return ret

    def push(self, item: Any) -> None:
        temp = self.head

        self.head = _Node(item)
        self.head.next = temp

    def append(self, item: Any) -> None:
        if self.head is None:
            self.head = _Node(item)
        else:
            cur = self.head
            while cur.next is not None:
                cur = cur.next

            cur.next = _Node(item)

    def remove(self, idx: int) -> Any:
        if self.head is None:
            raise IndexError
        
        cur = self.head
        for _ in range(idx):
            cur = cur.next
            if cur is None:
                raise IndexError

        return cur.item


# equivalent to `int main(void)`.
if __name__ == "__main__":
    lst = LinkedList()

    for i in range(5):
        lst.push(i + 1)

    lst.append(6)
    lst.append(7)

    print(lst)