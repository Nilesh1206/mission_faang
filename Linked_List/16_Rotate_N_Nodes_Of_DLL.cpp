#include <bits/stdc++.h>
using namespace std;
 
/* Link list node */
struct Node {
    char data;
    struct Node* prev;
    struct Node* next;
};
 
// This function rotates a doubly linked
// list counter-clockwise and updates the
// head. The function assumes that N is
// smallerthan size of linked list. It
// doesn't modify the list if N is greater
// than or equal to size
void rotate(struct Node** head_ref, int N)
{
    if (N == 0)
        return;
 
    // Let us understand the below code
    // for example N = 2 and
    // list = a <-> b <-> c <-> d <-> e.
    struct Node* current = *head_ref;
 
    // current will either point to Nth
    // or NULL after this loop. Current
    // will point to node 'b' in the
    // above example
    int count = 1;
    while (count < N && current != NULL) {
        current = current->next;
        count++;
    }
 
    // If current is NULL, N is greater
    // than or equal to count of nodes
    // in linked list. Don't change the
    // list in this case
    if (current == NULL)
        return;
 
    // current points to Nth node. Store
    // it in a variable. NthNode points to
    // node 'b' in the above example
    struct Node* NthNode = current;
 
    // current will point to last node
    // after this loop current will point
    // to node 'e' in the above example
    while (current->next != NULL)
        current = current->next;
 
    // Change next of last node to previous
    // head. Next of 'e' is now changed to
    // node 'a'
    current->next = *head_ref;
 
    // Change prev of Head node to current
    // Prev of 'a' is now changed to node 'e'
    (*head_ref)->prev = current;
 
    // Change head to (N+1)th node
    // head is now changed to node 'c'
    *head_ref = NthNode->next;
 
    // Change prev of New Head node to NULL
    // Because Prev of Head Node in Doubly
    // linked list is NULL
    (*head_ref)->prev = NULL;
 
    // change next of Nth node to NULL
    // next of 'b' is now NULL
    NthNode->next = NULL;
}