class Solution {
public:
    bool isValid(string s) {
        std::stack<char> st;
        bool Balanced = true;
        int i = 0;

        while (i < s.length()) {

            if (s[i] == '{') {
                st.push(s[i]);

            } else if (s[i] == '}') {
                if (st.empty())
                    return false;
                if (st.top() == '{') {
                    Balanced = true;
                    st.pop();

                } else {
                    return false;
                }
            }

            if (s[i] == '[') {
                st.push(s[i]);

            } else if (s[i] == ']') {
                if (st.empty())
                    return false;
                if (st.top() == '[') {
                    Balanced = true;
                    st.pop();

                } else {
                    return false;
                }
            }

            if (s[i] == '(') {
                st.push(s[i]);

            } else if (s[i] == ')') {
                if (st.empty())
                    return false;
                if (st.top() == '(') {
                    Balanced = true;
                    st.pop();

                } else {
                    return false;
                }
            }

            i++;
        }
        return st.empty();
    }
};