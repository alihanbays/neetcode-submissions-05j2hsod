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
        vector<ListNode*> nodes;
        ListNode* curr = head;

        while (curr != nullptr) {
            nodes.push_back(curr);
            curr = curr->next;
        }

        // Now literally merging 2 list question
        // Create dummy head
        ListNode dummy;
        ListNode* tail = &dummy; // now we will use tail to go through the list and
        // return dummy next. In this case we dont return just edit the head.

        int l = 0;
        int r = nodes.size() - 1;
        while (l < r) {
            // First left then right;
            tail->next = nodes[l];
            tail = tail->next;
            l++;

            tail->next = nodes[r];
            tail = tail->next;
            r--;

            if (l == r && nodes.size() % 2 == 1) {
                tail->next = nodes[l];
                tail = tail->next;
            }
        }
        tail->next = nullptr;
    }
};
