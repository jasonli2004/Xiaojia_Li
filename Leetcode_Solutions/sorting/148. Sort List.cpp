/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *merge(ListNode *head1, ListNode *head2)
    {
        ListNode *dummy_head = new ListNode(0);
        ListNode *cur = dummy_head;
        while (head1 != nullptr && head2 != nullptr)
        {
            if (head1->val <= head2->val)
            {
                cur->next = head1;
                cur = cur->next;
                head1 = head1->next;
            }
            else
            {
                cur->next = head2;
                cur = cur->next;
                head2 = head2->next;
            }
        }
        if (head1 == nullptr)
        {
            cur->next = head2;
        }
        else
        {
            cur->next = head1;
        }
        return dummy_head->next;
    }
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *second = slow->next;
        slow->next = nullptr;
        ListNode *head1 = sortList(head);
        ListNode *head2 = sortList(second);
        return merge(head1, head2);
    }
};