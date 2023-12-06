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
    ListNode* rotateRight(ListNode* head, int k) {
        
        //empty list
        if(!head || !head->next || k==0){
            return head;
        }
        int length=1;
        ListNode* current=head;
        
        while(current->next){
            current=current->next;
            length++;
        }
        //efffective rotations
        int check=k%length;
        
        if(check==0){
            return head;
        }
        //circular list
        current->next=head;
        
        //find tail
        for(int i=0;i<length-check-1;i++){
            head=head->next;
        }
        
        ListNode* dummy=head->next;
        head->next=NULL;
        
        return dummy;
        
    }
};