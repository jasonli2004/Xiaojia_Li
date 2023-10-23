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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode result = new ListNode();
        ListNode head = result;
        int roundup = 0;
        int sum = 0;
        while( l1 != null || l2 != null ){
            sum = 0;
            if (l1 == null){
                sum = l2.val + roundup;
                if (sum >= 10){
                    roundup = 1;
                    sum = sum - 10;
                    result.next = new ListNode(sum);
                    result = result.next;
                    l2 = l2.next;
                }
                else{
                    result.next = new ListNode(sum);
                    result = result.next;
                    l2 = l2.next;
                    roundup = 0;
                }
                continue;
            }
            if (l2 == null){
                sum = l1.val + roundup;
                if (sum >= 10){
                    roundup = 1;
                    sum = sum - 10;
                    result.next = new ListNode(sum);
                    result = result.next;
                    l1 = l1.next;
                }
                else{
                    result.next = new ListNode(sum);
                    result = result.next;
                    l1 = l1.next;
                    roundup = 0;
                }
                continue;
            }
            sum = l1.val + l2.val +roundup;
            if (sum >= 10){
                roundup = 1;
                sum = sum - 10;
                result.next = new ListNode(sum);
                result = result.next;
                l1 = l1.next;
                l2 = l2.next;
            }
            else{
                result.next = new ListNode(sum);
                result = result.next;
                l1 = l1.next;
                l2 = l2.next;
                roundup = 0;
            }
        }
        if (roundup == 1){
            result.next = new ListNode(1);
        }
        return head.next;
    }
}