#include <iostream>
#include <vector>

using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

void insertAtTail(ListNode*& head, ListNode*& tail, int val) {
    ListNode* temp = new ListNode(val);
    if( head == NULL ) {
        head = temp;
    } else {
        tail->next = temp;
    }
    tail = temp;
}

void insertAtHead(ListNode*& head, ListNode*& tail, int val) {
    ListNode* temp = new ListNode(val);
    if( head == NULL ) {
        tail = temp;
    } else {
        temp->next = head;
    }
    head = temp;
}

void print(ListNode* head) {
    while( head != NULL ) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    vector<int> val = { 1, 2, 5, 6, 7 };

    ListNode* head = NULL;
    ListNode* tail = NULL;

    for( auto i : val )
        insertAtTail(head, tail, i);

    print(head);

    return 0;
}