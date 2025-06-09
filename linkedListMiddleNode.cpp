#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};

void insertAtEnd(ListNode*& head, int value) {
    ListNode* newNode = new ListNode(value);
    if (!head) {
        head = newNode;
        return;
    }
    ListNode* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = nullptr;
    int n, value;

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> value;
        insertAtEnd(head, value);
    }

    Solution sol;
    ListNode* middle = sol.middleNode(head);

    cout << "Middle node value: " << middle->val << endl;

    cout << "List from middle node onwards: ";
    printList(middle);

    return 0;
}
