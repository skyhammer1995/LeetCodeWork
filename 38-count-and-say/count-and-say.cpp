#include <string>
class Solution {
public:
    string countAndSay(int n) {
        switch (n)
        {
            case 1:
            return "1";
            case 2:
            return "11";
        }
        string str = "11";
        int cnt = 1;
        string temp = "";
        for(int i=3; i<=n ; ++i)
        {
            str += "&"; 
              
            
            for(int j = 1; j<str.length(); ++j)
            {
                if(str[j]!=str[j-1])
                {
                    temp += to_string(cnt) + str[j-1]; 
                    cnt = 1; 
                }
                else
                    ++cnt; 
            }
            cnt = 1;
            str = std::move(temp);
            temp.clear();
        }
        
    return str;
    }
};