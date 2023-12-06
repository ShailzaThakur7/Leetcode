// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* rotateRight(ListNode* head, int k) {
        
//         //empty list
//         if(!head || !head->next || k==0){
//             return head;
//         }
//         int length=1;
//         ListNode* current=head;
        
//         while(current->next){
//             current=current->next;
//             length++;
//         }
//         //efffective rotations
//         int check=k%10;
        
//         if(check==0){
//             return head;
//         }
//         //circular list
//         current->next=head;
        
//         //find tail
//         for(int i=0;i<length-check-1;i++){
//             head=head->next;
//         }
        
//         ListNode* dummy=head->next;
//         head->next=NULL;
        
//         return dummy;
        
//     }
// };

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // Edge Case: Empty list or list with one node
        if (!head || !head->next || k == 0) {
            return head;
        }

        // Calculate the length of the linked list
        int length = 1; // Start from 1 to include the head node
        ListNode* current = head;
        while (current->next) {
            current = current->next;
            length++;
        }

        // Adjust the rotation value
        int effective_rotations = k % length;

        // If effective rotations are 0, the list remains unchanged
        if (effective_rotations == 0) {
            return head;
        }

        // Find the new tail and head
        current->next = head; // Make it a circular linked list
        for (int i = 0; i < length - effective_rotations - 1; i++) {
            head = head->next;
        }

        // Update pointers
        ListNode* new_head = head->next;
        head->next = nullptr; // Break the circular linked list

        return new_head;
    }
};
