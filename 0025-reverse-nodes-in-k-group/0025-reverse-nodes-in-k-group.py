# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        #step1 lets append all the values in an array this helps
        #with having all the elements at once
        arr = []
        while head:
            arr.append(head.val)
            head = head.next

        # Step 2: reverse every k elements in the array
        # we just need to reverse k window size till
        # end is equal to i+k or end is less than that(end < n)
        
        n = len(arr)
        for i in range(0, n, k):
            start = i
            end = min(i + k, n) 
            if end < i+k:
                break
            arr[start:end] = reversed(arr[start:end])

        #Step3: The Fun begins here
        ans = ListNode(0)  
        temp = ans
        for num in arr:
            temp.next = ListNode(num)  
            temp = temp.next           

        return ans.next
 
            