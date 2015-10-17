#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        char left[] = "({[";
        char right[] = ")}]";
        stack<char> stk;
        int len = s.size();
        int i, j;

        for (i = 0; i < len ; i++) {
            for (j = 0; j < 3; j++) {
                if (s[i] == left[j]) {
                    stk.push(s[i]);
                    break;
                } else if (s[i] == right[j]) {
                    if (!stk.empty() && stk.top() == left[j]) {
                        stk.pop();
                        break;
                    } else
                        return false;
                }
            }
        }
        if (stk.empty())
            return true;
        else
            return false;
        }
};


int main(void) {
    Solution s;
    printf("%d\n", s.isValid("([])"));
    return 0;
}
