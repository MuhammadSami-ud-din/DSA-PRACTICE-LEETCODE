class Solution {
public:
    bool isValid(string s) {
        std::stack<char> st;
        bool Balanced = true;
        int i = 0;

        while (i < s.length()) {

            if (s[i] == '{' || s[i] == '(' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if (st.empty())
                    return false;

                if (s[i] == ']' && st.top() != '[')
                    return false;
                if (s[i] == '}' && st.top() != '{')
                    return false;
                if (s[i] == ')' && st.top() != '(')
                    return false;

                st.pop();
            }

            i++;
        }
        return st.empty();
    }
};