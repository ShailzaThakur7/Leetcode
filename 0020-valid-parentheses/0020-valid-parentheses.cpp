// class Solution {
// public:
//     bool isValid(string s) {
//         stack <char> st;
//         // unordered_map<char,char> brackets={{'(',')'},{'[',']'},{'{','}'}};
//         unordered_map<char, char> brackets = {{')', '('}, {'}', '{'}, {']', '['}};

        
//         for(char c:s){
//             if(brackets.find(c)==brackets.end()){
//                 st.push(c);
//             }else{
//                 if(st.top()!=brackets[c] || st.empty()){
//                 return false;
//                 }
//             st.pop();
//         }
//         }
//         return st.empty();
        
        
        
//     }
// };

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> brackets = {{')', '('}, {'}', '{'}, {']', '['}};

        for (char c : s) {
            if (brackets.find(c) == brackets.end()) {
                st.push(c);
            } else {
                if (st.empty() || st.top() != brackets[c]) {
                    return false;
                }
                st.pop();
            }
        }

        return st.empty();
    }
};