class Solution {
public:
    bool isValid(string s) {
        std::stack<int> stringStack;
        if (s.empty() || s.size()%2 != 0) {
            return false;
        }

        for (const char& letter : s) {
            switch(letter) {
                case '(':
                    // passthrough
                case '[':
                    // passthrough
                case '{':
                    stringStack.push(letter);
                    break;
                case ')':
                    if (stringStack.empty()) {
                        return false;
                    }

                    if (stringStack.top() != '(') {
                        return false;
                    } else {
                        stringStack.pop();
                    }
                    break;
                case ']':
                    if (stringStack.empty()) {
                        return false;
                    }
                    
                    if (stringStack.top() != '[') {
                        return false;
                    } else {
                        stringStack.pop();
                    }
                    break;
                case '}':
                    if (stringStack.empty()) {
                        return false;
                    }
                    
                    if (stringStack.top() != '{') {
                        return false;
                    } else {
                        stringStack.pop();
                    }
                    break;
                default:
                    // Unmatched char, bad test case
                    return false;
            }
        }

        if (!stringStack.empty()) {
            return false;
        }

        return true;
    }
};