class Solution {
public:
    string addBinary(string a, string b) {
        auto al = a.length(), bl = b.length();
        if (al > bl)
            b.insert(0, al-bl, '0');
        else if (bl > al)
            a.insert(0, bl-al, '0');
        
        string r;
        reverse_iterator<string::iterator> ra = a.rbegin(), rb = b.rbegin();
        int s = 0, c = 0;
        
        for (; ra != a.rend(); ra++, rb++)
        {
            s = (*ra - '0') + (*rb - '0') + c;
            c = s / 2;
            s %= 2;
            
            r.insert(0, 1, '0'+s);
        }
        
        if (c)
            r.insert(0, 1, '1');
            
        return r;
        
    }
};