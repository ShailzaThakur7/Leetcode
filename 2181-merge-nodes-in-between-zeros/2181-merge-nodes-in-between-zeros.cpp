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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy=new ListNode(0);
        ListNode* current=dummy;
        ListNode* iter=head->next;
        
        int sum=0;
        
        while(iter!=NULL){
            if(iter->val!=0){
                sum+=iter->val;
            }else{
                current->next=new ListNode(sum);
                current=current->next;
                sum=0;
                
            }
            iter=iter->next;
        }
        return dummy->next;  
        
        
    }
};