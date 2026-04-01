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
        int size = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            size++;
            curr = curr->next;
        }

        int indexToRemove = size - n;
        curr = head;

        if (indexToRemove == 0) {
            return curr->next;
        }

        for (int i = 0; i < size - 1; i++) {
            if (i+1 == indexToRemove) {
                curr->next = curr->next->next;
            }
            curr = curr->next;
        }

        return head;
    }
};
