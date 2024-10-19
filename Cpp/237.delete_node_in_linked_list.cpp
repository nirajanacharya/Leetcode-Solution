#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        // Copy the value of the next node to the current node
        node->val = node->next->val;
        // Point to the next of next node, effectively deleting the next node
        ListNode* temp = node->next;
        node->next = node->next->next;
        delete temp; // Free the memory of the deleted node
    }
};

int main() {
    // Example usage:
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    Solution solution;
    solution.deleteNode(head->next); // Deleting node with value 5

    cout << "Updated List: ";
    ListNode* current = head;
    while (current) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    // Clean up (delete nodes) here if necessary
    return 0;
}
