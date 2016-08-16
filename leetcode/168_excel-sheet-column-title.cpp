class Solution {
public:
    string convertToTitle(int n) {
        string title = "";
        while (n)
        {
            --n;
            title.insert(0, 1, 'A'+(n%26));
            n /= 26;
        }
        
        return title;
    }
};