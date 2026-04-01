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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        int size = 0;
        while (curr != nullptr) {
            size++;
            curr = curr->next;
        }

        ListNode* prev = head;
        curr = head;
        ListNode* next = head->next;
        int i = size - n;
        int it = 0;

        if (i == 0) {
            return next;
        }

        while (curr != nullptr) {
            if (it == i) {
                prev->next = next;
                break;
            }

            prev = curr;
            curr = curr->next;
            next = next->next;
            it++;
        }

        return head;
    }
};
