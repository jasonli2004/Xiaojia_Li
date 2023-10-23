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
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode l = new ListNode();
        ListNode head = new ListNode();
        head = l;
        int cnt = 0;
        while (list1 != null || list2 != null){
            cnt++;
            if (list1 == null && list2 != null){
                    l.next = new ListNode(list2.val);
                    list1 = list2.next;
                    l = l.next;
            }
            if (list1 != null && list2 == null){
                    l.next = new ListNode(list1.val);
                    list1 = list1.next;
                    l = l.next;
            }
            if (list1 != null && list2 != null){
                if (list1.val >= list2.val){
                    l.next = new ListNode(list1.val);
                    list1 = list1.next;
                    l = l.next;
                }
                else{
                    l.next = new ListNode(list2.val);
                    list2 = list2.next;
                    l = l.next;
                }

            }        
            if (cnt ==5){
                return head.next;
            }
    }
                 return head.next;
    }
}