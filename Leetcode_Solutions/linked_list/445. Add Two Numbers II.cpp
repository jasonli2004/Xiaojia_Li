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
    ListNode *reverse(ListNode *head)
    {
        ListNode *cur = head;
        ListNode *temp;
        ListNode *prev = NULL;
        while (cur != NULL)
        {
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        return prev;
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode *l1_head = l1;
        int plus_one = 0;
        while (true)
        {
            int sum = l1->val + l2->val + plus_one;
            l1->val = sum % 10;
            if (sum >= 10)
            {
                plus_one = 1;
            }
            else
            {
                plus_one = 0;
            }
            if (l1->next == nullptr || l2->next == nullptr)
            {
                break;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l1->next == nullptr && l2->next == nullptr)
        {
        }
        else
        {
            if (l1->next == nullptr)
            {
                l1->next = l2->next;
                l2->next = nullptr;
                l1 = l1->next;
            }
            else
            {
                l1 = l1->next;
            }
            while (l1 != nullptr)
            {
                int sum = l1->val + plus_one;
                l1->val = (sum) % 10;
                if (sum >= 10)
                {
                    plus_one = 1;
                }
                else
                {
                    plus_one = 0;
                }
                if (l1->next == nullptr)
                {
                    break;
                }
                l1 = l1->next;
            }
        }
        if (plus_one == 1)
        {
            ListNode *one = new ListNode(1, nullptr);
            l1->next = one;
        }
        return reverse(l1_head);
    }
};