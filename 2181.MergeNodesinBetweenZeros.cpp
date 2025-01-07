#include <iostream>

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Your Solution class
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* current = head;
        
        while (current != nullptr) {
            int sum = 0;
            ListNode* nextNode = current;
            
            // Calculate sum of current node and all subsequent nodes
            while (nextNode != nullptr) {
                sum += nextNode->val;
                nextNode = nextNode->next;
            }
            
            // Update current node's value with the calculated sum
            current->val = sum;
            current = current->next; // Move to the next node
        }
        
        return head;
    }
};

// Utility function to print the linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val;
        if (current->next != nullptr) {
            std::cout << " -> ";
        }
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    // Example linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Print original linked list
    std::cout << "Original Linked List: ";
    printList(head);

    // Create instance of Solution class
    Solution solution;

    // Call mergeNodes function to modify the linked list
    ListNode* modifiedHead = solution.mergeNodes(head);

    // Print modified linked list
    std::cout << "Modified Linked List: ";
    printList(modifiedHead);

    // Clean up allocated memory (optional in this short example)
    ListNode* current = modifiedHead;
    while (current != nullptr) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
