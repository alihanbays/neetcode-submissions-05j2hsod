class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode* next) : val(val), next(next) {}
};

class LinkedList {
private:
    ListNode* head;
    ListNode* tail;
public:
    LinkedList() {
        head = new ListNode(-1);
        tail = head;
    }

    int get(int index) {
        ListNode* curr = head->next;
        int i = 0;
        while (curr != nullptr) {
            if (i == index) {
                return curr->val;
            }
            curr = curr->next;
            i++;
        }
        return -1;
    }

    void insertHead(int val) {
        ListNode* node = new ListNode(val, head->next);
        head->next = node;
        if (node->next == nullptr) {
            tail = node;
        }
    }
    
    void insertTail(int val) {
        ListNode* node = new ListNode(val);
        tail->next = node;
        tail = tail->next;
    }

    bool remove(int index) {
        ListNode* curr = head;
        int i = 0;
        while (i < index && curr != nullptr) {
            curr = curr->next;
            i++;
        }

        if (curr != nullptr && curr->next != nullptr) {
            if (curr->next == tail) {
                tail = curr;
            }
            ListNode* toDelete = curr->next;
            curr->next = curr->next->next;
            delete toDelete;
            return true;
        }
        
        return false;
    }

    vector<int> getValues() {
        vector<int> result;
        ListNode* curr = head->next;
        while (curr != nullptr) {
            result.push_back(curr->val);
            curr = curr->next;
        }
        return result;
    }
};
