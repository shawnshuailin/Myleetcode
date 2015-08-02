ListNode* rotateRight(ListNode* head, int k) 
{
	if (k <= 0 || head == NULL)
		return head;
	ListNode* newHead = head;
	ListNode* end = head;
	int iTotalNode = 1;
	while (end->next != NULL)
	{
		end = end->next;
		++iTotalNode;
	}
	k = k % iTotalNode;
	if (k <= 0)
		return head;
	iTotalNode -= k;
	while (iTotalNode > 0)
	{
		end->next = newHead;
		end = newHead;
		newHead = newHead->next;
		end->next = NULL;
		--iTotalNode;
	}
	return newHead;
}