int searchInsert(int* nums, int numsSize, int target) {
    int i;
    
    while (i < numsSize && nums[i] < target)
        ++i;
    
    return i;    
}