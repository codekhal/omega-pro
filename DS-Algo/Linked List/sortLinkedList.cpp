// Resource: https://www.educative.io/edpresso/how-to-sort-a-linked-list-using-merge-sort

/* Given a linked list sort it in O(nlogn) time.
    We always apply merge sort in case of linkedlist since more efficient 
    and quick sort in case of arrays (allows random access).
    
    Merge Sort Algorithm:
    Step 1: If -> fewer than 1 or 1 element we return.
    Step 2: Else -> divide list into 2 halfves.
    Step 3: Mergesort -> sort the half sized list
    Step 4: Merge -> after we are done sorting individual lists we merge them
    
    We need functions for mergesort, splitting and merging.

*/

void splitting_list(ListNode* head, ListNode **start, ListNode **end)
{
    ListNode* ptr1;
    ListNode* ptr2;
    ptr2 = head;
    ptr1 = head->next;
    
    // fast and slow pointer appraoch to reach at the mid of the list
    // for splitting
    
    while(ptr1 && ptr1->next)
    {
        ptr1 = ptr1->next->next;
        ptr2 = ptr2->next;
    }
    
    // ptr2 is at the middle of the list
    *start = head; // new list
    *end = ptr2->next; // another list
    ptr2->next = NULL; // we split 
}
    
ListNode* merge(ListNode* l1, ListNode* l2)
{
    ListNode* result = NULL; // creating new list of sorted elements
    
    if(!l1)
        return l2;
    else if(!l2)
        return l1;
    
    if(l1->val <= l2->val) // recursively adding new nodes to the list
    {
        result = l1;
        result->next = merge(l1->next, l2);
    }
    
    else
    {
        result = l2;
        result->next = merge(l1,l2->next);
    }
    
    return result;
}

void mergesort(ListNode **head)
{
    
    ListNode* headptr = *head;
    ListNode *ptr1;
    ListNode *ptr2;
    
    if(headptr == NULL || headptr-> next == NULL) // base case
        return;
    
    // else we split list into 2 halfves
    
    splitting_list(headptr, &ptr1, &ptr2); 
    // we passing ptr1 and ptr2 with reference since they are new list now
    // we need to preserve their existence.
    
    // split until each list reaches the base case.
    
    mergesort(&ptr1);
    mergesort(&ptr2);
    
    // finally we merge
    
    *head = merge(ptr1, ptr2);   
}

ListNode* sortList(ListNode* head) {
    
    ListNode* newsortedlist = head;
    
    mergesort(&newsortedlist);
    
    return newsortedlist;
    
}

// Time: O(nlogn)
// Space: O(n), recursive call stack