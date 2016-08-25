class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pm = m - 1, pn = n - 1;
        int p = m + n - 1;
        while (pm >= 0 && pn >= 0)
        {
            if (nums1[pm] > nums2[pn])
                nums1[p--] = nums1[pm--];
            else
                nums1[p--] = nums2[pn--];
        }
        if (pm < 0)
        {
            while (p >= 0)
                nums1[p--] = nums2[pn--];
        }
    }
};