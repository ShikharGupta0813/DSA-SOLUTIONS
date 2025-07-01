/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        if(head==null || head.next==null) return head;
        ListNode dummy=new ListNode(0);
        dummy.next=head;
        ListNode current=dummy;
        while(current.next!=null && current.next.next!=null){
            ListNode slow=current.next;
            ListNode fast=current.next.next;

            slow.next=fast.next;
            fast.next=slow;
            current.next=fast;

            current=slow;
        } 
        return dummy.next;
    }
}