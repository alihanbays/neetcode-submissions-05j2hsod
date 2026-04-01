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

        // First find the middle of the linked list with fast and slow pointers;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // so now we have can have 2 lists one [2,4] one [6,8]
        ListNode* l1 = head;
        ListNode* l2 = slow;

        if (l1 == l2) {
            return;
        }

        ListNode* p = l1;
        // Disconnect l1 from l2 to have 2 linked lists.
        while (p->next != l2) {
            p = p->next;
        }
        p->next = nullptr;
        

        // We now reverse the second list;
        ListNode* prev = nullptr;
        ListNode* curr = l2;

        while (curr != nullptr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        l2 = prev;

        // Now the list should be reverted
        // [2,4] [8,6]
        // Now we do the relinking of the nodes
        // basic merging two with dummy node;
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
