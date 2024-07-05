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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> critical;
        ListNode* prev=head;
        ListNode* curr=head->next;
        int position=1;
        
        while(curr!=NULL && curr->next!=NULL){
            if((curr->val>prev->val && curr->val>curr->next->val) || (curr->val < prev->val && curr->val < curr->next->val)){
                critical.push_back(position);
            }
            prev=curr;
            curr=curr->next;
            position++;
        }
        
        if(critical.size()<2){
            return {-1,-1};
        }
        
        int mindistance=INT_MAX;
        for(int i=1;i<critical.size();i++){
            mindistance=min(mindistance,critical[i]-critical[i-1]);            
        }
        
        int maxdistance=critical.back()-critical.front();
        
        return {mindistance,maxdistance};
    }
};