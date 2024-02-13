class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        ListNode l = new ListNode();
        for (int i = 0; i < ListNode.length(); i++){
            l = mergeTwoLists(l, list[i]);
        }
        return l;
    }
    private ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        ListNode curr = dummy;

        while (l1 != null && l2 != null) {
            if (l1.val < l2.val) {
                curr.next = l1;
                l1 = l1.next;
            }
            else {
                curr.next = l2;
                l2 = l2.next;
            }
            curr = curr.next;
        }

        if (l1 != null) {
            curr.next = l1;
        }
        else {
            curr.next = l2;
        }

        return dummy.next;
    }
}
