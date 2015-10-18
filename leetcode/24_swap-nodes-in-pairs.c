/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *first, *second;
    
    if (head == NULL)
        return head;
        
    first = head;
    second = head->next;
    
    if (second == NULL)
        return head;
    
    first->next = swapPairs(second->next);
    second->next = first;
    
    return second;
}