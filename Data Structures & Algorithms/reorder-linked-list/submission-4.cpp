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

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head) {
            return;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* l1 = head;
        ListNode* l2 = slow;

        if (l1 == l2) {
            return;
        }

        ListNode* curr = l1;
        while (curr->next != l2) {
            curr = curr->next;
        }
        curr->next = nullptr;
        
        ListNode* prev = nullptr;
        curr = l2;

        while (curr != nullptr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        l2 = prev;

        ListNode dummy(-1);
        curr = &dummy;

        while (l1 != nullptr && l2 != nullptr) {
            curr->next = l1;
            l1 = l1->next;
            curr = curr->next;

            curr->next = l2;
            l2 = l2->next;
            curr = curr->next;
        }

        if (l2 != nullptr) {
            curr->next = l2;
        }
    }
};
