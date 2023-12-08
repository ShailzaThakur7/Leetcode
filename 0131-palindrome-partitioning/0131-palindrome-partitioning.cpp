class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        backtrack(s,0,ds,ans);
        return ans;       
        
    }
private:
    void backtrack(const string &s,int ind,vector<string> &ds,vector<vector<string>> &ans){
        if(ind==s.length()){
            ans.push_back(ds);
            return;
        }
        
        for(int end=ind;end<s.length();end++){
            if(ispalindrome(s,ind,end)){
                string sub=s.substr(ind,end-ind+1);
            ds.push_back(sub);
            backtrack(s,end+1,ds,ans);
            ds.pop_back();
        }
        }
        
        
    }
    
    bool ispalindrome(const string&s,int ind,int end){
        while(ind<end){
            if(s[ind]!=s[end]){
                return false;
            }
            ind++;
            --end;
        }
        return true;
    }
};