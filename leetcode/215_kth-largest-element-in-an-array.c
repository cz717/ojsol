void down(int* heap, int size, int x);


int findKthLargest(int* nums, int numsSize, int k) {
    
    // build a heap
    int *h = (int*) malloc(sizeof(int)*(k+1));
    for (int i = 0; i < k; i++)
        h[i+1] = nums[i];
    for (int i = k/2; i > 0; i--)
        down(h, k, i);
        
    // insert
    for (int i = k; i < numsSize; i++)
        if (h[1] < nums[i])
        {
            h[1] = nums[i];
            down(h, k, 1);
        }
    
    return h[1];
}


void down(int* heap, int size, int x)
{
    int left, right, next;
    int temp = heap[x];
    
    while((left = x * 2) <= size)
    {
        right = left + 1;
        
        if (right > size)
            next = left;
        else
            next = (heap[left]<heap[right]) ? left : right;
            
        if (heap[next] < temp)
        {
            heap[x] = heap[next];
            x = next;
        }
        else {
            break;
        }
    }
    
    heap[x] = temp;
}