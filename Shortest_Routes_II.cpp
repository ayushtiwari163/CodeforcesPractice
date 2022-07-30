#include <bits/stdc++.h>
using namespace std;


// Link list node
struct Node 
{
    int data;
    struct Node* next;
};


// Add node to the linked list
void push(struct Node** head_ref, int new_data)
{
    /* allocate node */
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));


    // Insert Data
    new_node->data = new_data;


    // Link the node with the linked list
    new_node->next = (*head_ref);


    // Increment the header pointer
    (*head_ref) = new_node;
}


// Store elements
void helper(struct Node* head1, struct Node* head2, unordered_map<int, int>& mp)
{
    struct Node* temp1 = head1;
    struct Node* temp2 = head2;


    // Traverse both linked lists
    while (temp1 != NULL || temp2 != NULL) 
    {
        // store element in the map
        if (temp1 != NULL) 
        {
            mp[temp1->data]++;
            temp1 = temp1->next;
        }


        // store element in the map
        if (temp2 != NULL) 
        {
            mp[temp2->data]++;
            temp2 = temp2->next;
        }
    }
}


// Union of both the linked list
struct Node* getUnion(unordered_map<int, int> mp)
{
    struct Node* result = NULL;


    for (auto it = mp.begin(); it != mp.end(); it++)
        push(&result, it->first);


    return result;
}


// Intersection of both the linked list
struct Node* getIntersection(unordered_map<int, int> mp)
{
    struct Node* result = NULL;


    for (auto it = mp.begin(); it != mp.end(); it++)
        if (it->second == 2)
            push(&result, it->first);


    // return resultant linked list
    return result;
}


void printList(struct Node* node)
{
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}


void printUnionIntersection(Node* head1,Node* head2)
{
    // Store all the elements of
    // both lists in the map
    unordered_map<int, int> mp;
    helper(head1, head2, mp);


    Node* intersection_list = getIntersection(mp);
    Node* union_list = getUnion(mp);


    printf("\nIntersection list is \n");
    printList(intersection_list);


    printf("\nUnion list is \n");
    printList(union_list);
}


/* Driver program to test above function*/
int main()
{
    /* Start with the empty list */
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;


    /* create a linked list 11->10->15->4->20 */
    push(&head1, 10);
    push(&head1, 15);
    push(&head1, 45);
    push(&head1, 17);
    push(&head1, 145);


    /* create a linked list 8->4->2->10 */
    push(&head2, 145);
    push(&head2, 5);
    push(&head2, 11);
    push(&head2, 45);
    push(&head2, 43);
    push(&head2, 1);


    printf("First list is \n");
    printList(head1);


    printf("\nSecond list is \n");
    printList(head2);


    printUnionIntersection(head1, head2);

    return 0;
}