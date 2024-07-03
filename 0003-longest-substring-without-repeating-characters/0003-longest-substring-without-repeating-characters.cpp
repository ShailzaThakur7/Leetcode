class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> c;
        int left=0;
        int max_length=0;
        
        for(int right=0;right<s.length();right++){
            if(c.find(s[right])!=c.end() && c[s[right]]>=left){
                left=c[s[right]]+1;
            }
            c[s[right]]=right;
            max_length=max(max_length,right-left+1);
        }
        return max_length;
    }
};