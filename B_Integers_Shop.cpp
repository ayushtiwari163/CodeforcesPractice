// C++ program to Merge one Linked List into another at alternate positions
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

// insertion at the beginning
void push(Node **head_ref, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// printing a singly linked list
void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// merging both linked list according to the given condition. Say p be the first linked list and q be the second linked list.
void merge(Node *p, Node **q)
{
    Node *p_curr = p, *q_curr = *q;
    Node *p_next, *q_next;

    // is alternate position is available in p
    while (p_curr != NULL && q_curr != NULL)
    {
        // Saving the very next pointers
        p_next = p_curr->next;
        q_next = q_curr->next;

        // Making current of q as the next of current of p
        q_curr->next = p_next;
        p_curr->next = q_curr;

        // Updating current pointers
        p_curr = p_next;
        q_curr = q_next;
    }

    // Updating head of second list
    *q = q_curr;
}

int main()
{
    Node *p = NULL, *q = NULL;
    push(&p, 7);
    push(&p, 5);
    push(&p, 3);
    push(&p, 1);

    push(&q, 9);
    push(&q, 8);
    push(&q, 6);
    push(&q, 4);
    push(&q, 2);

    merge(p, &q);

    printList(p);
    printList(q);

    return 0;
}
