#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	int c;
    struct ListNode *sum, *p, *q;
    p = sum = (struct ListNode *) malloc(sizeof(struct ListNode));
    p->val = 0;
    p->next = NULL;

    while (l1 || l2) {
    	if (l1)	p->val += l1->val;
    	if (l2)	p->val += l2->val;
    	if (p->val >= 10) {
    		p->val %= 10;
    		c = 1;
    	} else
    		c = 0;
    	printf("[%d %d]\n", p->val, c);

    	p->next = (struct ListNode *) malloc(sizeof(struct ListNode));
    	q = p;
    	p = p->next;
    	p->val = c;
    	p->next = NULL;

    	if (l1)	l1 = l1->next;
    	if (l2)	l2 = l2->next;
    }

    if (p->val == 0 && sum != p) {
    	free(p);
    	q->next = NULL;
    }

    return sum;
}


int main(void) {
	struct ListNode a;
	struct ListNode b;

	a.val = 0;
	a.next = NULL;
	b.val = 1; 
	b.next = NULL;

	struct ListNode* sum = addTwoNumbers(&a, &b);
	while (sum) {
		printf("%d ", sum->val);
		sum = sum->next;
	}
	return 0;
}
