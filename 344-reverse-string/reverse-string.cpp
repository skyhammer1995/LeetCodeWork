class Solution {
public:
    void reverseString(vector<char>& s) {
        // half of size, will truncate due to integer math, or we can floor if need be
        // we take half for sake of two pointers, 
        // and odd sized strings will need to skip middle
        int n = (s.size()/2);
        
        std::vector<char>::iterator front = s.begin();
        std::vector<char>::iterator back = s.end() - 1;
        
        while (front < back) {
            // assign back's value to temp value
            char tmp = *back;
            // move front value to back's value
            *back = *front;
            // move tmp value to front
            *front = tmp;

            // move iterators to new elements to be switched
            ++front;
            --back;
        }
    }
};