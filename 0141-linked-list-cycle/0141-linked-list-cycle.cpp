// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode(int x) : val(x), next(NULL) {}
//  * };
//  */
// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         if(head==NULL || head->next==NULL){
//             return false;
//         }        
        
//         ListNode* slow=head;
//         ListNode* fast=head->next;
        
//         while(slow!=fast){
//             if(fast==NULL | fast->next==NULL){
//                 return false;
//             }
//             slow=slow->next;
//             fast=fast->next->next;
//         }
//         return true;
//     }
// };
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return false; // No cycle if the list is empty or has only one node
        }

        ListNode *slow = head;
        ListNode *fast = head->next;

        while (slow != fast) {
            if (fast == nullptr || fast->next == nullptr) {
                return false; // No cycle if the fast pointer reaches the end
            }

            slow = slow->next;
            fast = fast->next->next;
        }

        return true; // Cycle detected
    }
};
