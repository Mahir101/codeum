"""
Two Pointers - Fast & Slow Pointers (Floyd's Cycle Detection)
Template for linked list cycle detection and array problems
Time: O(n), Space: O(1)
"""

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def has_cycle(head):
    """
    LeetCode 141: Linked List Cycle
    Detect if linked list has a cycle.
    """
    if not head or not head.next:
        return False
    
    slow = head
    fast = head
    
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        
        if slow == fast:
            return True
    
    return False


def detect_cycle(head):
    """
    LeetCode 142: Linked List Cycle II
    Find the node where cycle begins.
    """
    if not head or not head.next:
        return None
    
    # Phase 1: Detect cycle
    slow = fast = head
    has_cycle = False
    
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        
        if slow == fast:
            has_cycle = True
            break
    
    if not has_cycle:
        return None
    
    # Phase 2: Find cycle start
    slow = head
    while slow != fast:
        slow = slow.next
        fast = fast.next
    
    return slow


def find_duplicate(nums):
    """
    LeetCode 287: Find the Duplicate Number
    Array contains n+1 integers in range [1, n].
    Find the duplicate using Floyd's algorithm.
    """
    # Treat array as linked list: nums[i] points to nums[nums[i]]
    slow = fast = nums[0]
    
    # Phase 1: Find intersection point
    while True:
        slow = nums[slow]
        fast = nums[nums[fast]]
        if slow == fast:
            break
    
    # Phase 2: Find entrance to cycle (duplicate)
    slow = nums[0]
    while slow != fast:
        slow = nums[slow]
        fast = nums[fast]
    
    return slow


def middle_of_linked_list(head):
    """
    LeetCode 876: Middle of the Linked List
    Return middle node (if two, return second).
    """
    slow = fast = head
    
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
    
    return slow


def is_happy_number(n):
    """
    LeetCode 202: Happy Number
    A happy number is defined by:
    - Replace number by sum of squares of digits
    - Repeat until =1 (happy) or cycles
    """
    def get_next(num):
        total = 0
        while num > 0:
            digit = num % 10
            total += digit * digit
            num //= 10
        return total
    
    slow = n
    fast = get_next(n)
    
    while fast != 1 and slow != fast:
        slow = get_next(slow)
        fast = get_next(get_next(fast))
    
    return fast == 1


# Test cases
if __name__ == "__main__":
    # Test has_cycle
    node1 = ListNode(3)
    node2 = ListNode(2)
    node3 = ListNode(0)
    node4 = ListNode(-4)
    node1.next = node2
    node2.next = node3
    node3.next = node4
    node4.next = node2  # Creates cycle
    assert has_cycle(node1) == True
    print("✓ has_cycle")
    
    # Test find duplicate
    assert find_duplicate([1,3,4,2,2]) == 2
    assert find_duplicate([3,1,3,4,2]) == 3
    print("✓ find_duplicate")
    
    # Test happy number
    assert is_happy_number(19) == True
    assert is_happy_number(2) == False
    print("✓ is_happy_number")
    
    # Test middle of linked list
    head = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
    middle = middle_of_linked_list(head)
    assert middle.val == 3
    print("✓ middle_of_linked_list")
    
    print("\n✅ All tests passed!")
