#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = nullptr;

        while (temp != nullptr) {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

void insertAtEnd(ListNode*& head, int val) {
    ListNode* newNode = new ListNode(val);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    ListNode* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

int main() {
    ListNode* head = nullptr;
    int n, val;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> val;
        insertAtEnd(head, val);
    }

    cout << "Original List:\n";
    printList(head);

    Solution sol;
    ListNode* reversed = sol.reverseList(head);

    cout << "Reversed List:\n";
    printList(reversed);

    return 0;
}
