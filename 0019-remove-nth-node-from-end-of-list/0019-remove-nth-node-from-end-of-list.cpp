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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int m=0;
        ListNode* temp=head;
        
        while(temp){
            m++;
            temp=temp->next;
        }
        temp=head;
        
        int last=m-n;
        
        if(last==0){
            ListNode* newHead=head->next;
            delete head;
            return newHead; 
        }
        for(int i=0;i<last-1;i++){
            temp=temp->next;
            
        }
        ListNode* prev=temp->next;
        temp->next=temp->next->next;
        
        delete prev;
        return head;
        
        
    }
};