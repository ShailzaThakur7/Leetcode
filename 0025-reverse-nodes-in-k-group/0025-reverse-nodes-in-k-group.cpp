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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* current=head;
        int count=0;
        
        //count of nodes
        while(current!=NULL && count<k){
            current=current->next;
            count++;
        }
        
        //if exactly k nodes then reverse them
        if(count==k){
            ListNode* reversehead=reverseList(head,k);
            head->next=reverseKGroup(current,k);
            return reversehead;
        }
        return head;
        
    }
    private:
    
    ListNode* reverseList(ListNode* head, int k) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;

        // Reverse k nodes
        while (k > 0) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            k--;
        }

        // Return the new head of the reversed sublist
        return prev;
    }
};