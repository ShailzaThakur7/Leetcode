class Solution {
public:
    string reverseParentheses(string s) {
        int m=s.length();
        stack<int> st;
        
        for(int i=0;i<m;i++){
            if(s[i]=='('){
                st.push(i);
            }else if(s[i]==')'){
                int start=st.top();
                st.pop();
                reverse(s.begin()+start+1,s.begin()+i);
            }
        }
        
        string result;
        for(char c:s){
            if(c!='(' && c!=')'){
                result+=c;
            }
        }
        return result;
        
    }
};