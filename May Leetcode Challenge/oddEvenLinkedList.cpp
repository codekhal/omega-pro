/*
    Given a singly linked list, group all odd nodes together followed by the even nodes. 
    Please note here we are talking about the node number and not the value in the nodes.

    Input: 2->1->3->5->6->4->7->NULL
    utput: 2->3->6->7->1->5->4->NULL
*/

/* We have 2 methods for this.
    Method 1: Take a temppointer and point it to head. Then create end 
    pointer by traversing at the end of the list. Maintain a counter. 
    Counter = counter/2+1 in case of even nodes and counter/2 when odd.
    Now do the following 
    steps:
    1. end->next = temp->next; // bringing last element in place of 1st even.
    2. temp->next = temp->next->next; // placing odd terms ahead of even.
    3. end->next->next = NULL; // moving 1st even to the last.
    4. increment end as well as temp, until counter becomes zero.
    
    Method2:
    Split odd linkedlist and even list then finally put, 
    odd->next = even_head;
*/

ListNode* oddEvenList(ListNode* head) 
{
    
    if(!head)
        return head;
    
    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* odd_head = head;
    ListNode* even_head = head->next;
    
    while(even && even->next) // while we reach end of the list
    {
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    
    odd->next = even_head; // Assign end of odd with begining of even.
    
    return head;
}

// Time: O(n), where n is number of nodes.
// Space: O(1)