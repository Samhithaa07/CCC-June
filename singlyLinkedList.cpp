#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

Node* head = nullptr;

void insertAtBeginning(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    cout << "Inserted " << value << " at the beginning.\n";
}

void insertAtEnd(int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }
    cout << "Inserted " << value << " at the end.\n";
}

void deleteByValue(int value) {
    Node* temp = head;
    Node* prev = nullptr;
    bool deleted = false;

    while (temp != nullptr) {
        if (temp->data == value) {
            deleted = true;
            if (prev == nullptr) {
                // Deleting head node
                head = temp->next;
                delete temp;
                temp = head;
            } else {
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            }
        } else {
            prev = temp;
            temp = temp->next;
        }
    }

    if (deleted)
        cout << "Deleted all occurrences of " << value << " from the list.\n";
    else
        cout << "Value " << value << " not found in the list.\n";
}

void search(int value) {
    Node* temp = head;
    int index = 0;
    bool found = false;

    while (temp != nullptr) {
        if (temp->data == value) {
            cout << "Found " << value << " at index " << index << ".\n";
            found = true;
        }
        temp = temp->next;
        index++;
    }

    if (!found)
        cout << "Value " << value << " not found in the list.\n";
}

void displayList() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    cout << "List: ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void countNodes() {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    cout << "Total nodes: " << count << "\n";
}

void insertAtIndex(int index, int value) {
    if (index < 0) {
        cout << "Invalid index.\n";
        return;
    }

    Node* newNode = new Node(value);

    if (index == 0) {
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << value << " at index " << index << ".\n";
        return;
    }

    Node* temp = head;
    for (int i = 0; i < index - 1 && temp != nullptr; i++)
        temp = temp->next;

    if (temp == nullptr) {
        cout << "Index out of bounds.\n";
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    cout << "Inserted " << value << " at index " << index << ".\n";
}

void deleteAtIndex(int index) {
    if (index < 0 || head == nullptr) {
        cout << "Invalid index or empty list.\n";
        return;
    }

    Node* temp = head;

    if (index == 0) {
        head = head->next;
        cout << "Deleted value " << temp->data << " at index " << index << ".\n";
        delete temp;
        return;
    }

    Node* prev = nullptr;
    for (int i = 0; i < index && temp != nullptr; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Index out of bounds.\n";
        return;
    }

    prev->next = temp->next;
    cout << "Deleted value " << temp->data << " at index " << index << ".\n";
    delete temp;
}

void getValueAtIndex(int index) {
    if (index < 0) {
        cout << "Invalid index.\n";
        return;
    }

    Node* temp = head;
    int currentIndex = 0;

    while (temp != nullptr) {
        if (currentIndex == index) {
            cout << "Value at index " << index << " is " << temp->data << ".\n";
            return;
        }
        temp = temp->next;
        currentIndex++;
    }

    cout << "Index " << index << " out of bounds.\n";
}

void reverseList() {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
    cout << "List reversed.\n";
}

void sortListAscending() {
    if (head == nullptr || head->next == nullptr) {
        cout << "List is too short to sort.\n";
        return;
    }

    for (Node* i = head; i != nullptr; i = i->next) {
        for (Node* j = i->next; j != nullptr; j = j->next) {
            if (i->data > j->data)
                swap(i->data, j->data);
        }
    }

    cout << "List sorted in ascending order.\n";
}

void sortListDescending() {
    if (head == nullptr || head->next == nullptr) {
        cout << "List is too short to sort.\n";
        return;
    }

    for (Node* i = head; i != nullptr; i = i->next) {
        for (Node* j = i->next; j != nullptr; j = j->next) {
            if (i->data < j->data)
                swap(i->data, j->data);
        }
    }

    cout << "List sorted in descending order.\n";
}

int main() {
    int choice, value, index;

    while (true) {
        cout << "\n--- Menu ---\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Delete by value\n";
        cout << "4. Search\n";
        cout << "5. Display\n";
        cout << "6. Count nodes\n";
        cout << "7. Insert at index\n";
        cout << "8. Delete at index\n";
        cout << "9. Get value at index\n";
        cout << "10. Reverse list\n";
        cout << "11. Sort list in ascending order\n";
        cout << "12. Sort list in descending order\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            insertAtBeginning(value);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            insertAtEnd(value);
            break;
        case 3:
            cout << "Enter value to delete: ";
            cin >> value;
            deleteByValue(value);
            break;
        case 4:
            cout << "Enter value to search: ";
            cin >> value;
            search(value);
            break;
        case 5:
            displayList();
            break;
        case 6:
            countNodes();
            break;
        case 7:
            cout << "Enter index and value: ";
            cin >> index >> value;
            insertAtIndex(index, value);
            break;
        case 8:
            cout << "Enter index to delete: ";
            cin >> index;
            deleteAtIndex(index);
            break;
        case 9:
            cout << "Enter index to get value: ";
            cin >> index;
            getValueAtIndex(index);
            break;
        case 10:
            reverseList();
            break;
        case 11:
            sortListAscending();
            break;
        case 12:
            sortListDescending();
            break;
        case 0:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}