/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> hashset;
        ListNode *ptrA = headA;
        ListNode *ptrB = headB;
        while (ptrA != nullptr && ptrB != nullptr){
            if (hashset.find(ptrA) != hashset.end()){
                return ptrA;
            }
            hashset.insert(ptrA);
            if (hashset.find(ptrB) != hashset.end()){
                return ptrB;
            }
            hashset.insert(ptrB);
            ptrA = ptrA->next;
            ptrB = ptrB->next;
        }
        while (ptrA == nullptr && ptrB != nullptr){
            if (hashset.find(ptrB) != hashset.end()){
                return ptrB;
            }
            hashset.insert(ptrB);
            ptrB = ptrB->next; 
        }
        while (ptrA != nullptr && ptrB == nullptr){
            if (hashset.find(ptrA) != hashset.end()){
                return ptrA;
            }
            hashset.insert(ptrA);
            ptrA = ptrA->next;
        }
        return nullptr;
        
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curA = headA;
        ListNode* curB = headB;
        while (curA != curB){
            if (curA == nullptr){
                curA = headB;
            }
            else{
                curA = curA->next;
            }
            if (curB == nullptr){
                curB = headA;
            }
            else{
                curB = curB->next;
            }
        }
        return curB;

    }
};