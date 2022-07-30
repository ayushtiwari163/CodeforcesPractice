#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;
    Node(int data)
    {
       this -> data = data;
       this -> next = NULL;
    }
};

Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}
Node* getUnion(Node* head1, Node* head2)
{
    Node *unionList = NULL;
    Node *temp1 = head1, *temp2 = head2;
 
    // Insert all elements of linked list 1
    while (temp1 != NULL) 
    {
        helper(&unionList, temp1->data);
        temp1 = temp1 -> next;
    }
 
    // Insert elements from Linked list 2 whose duplicates are not available in 'unionList'
    while (temp2 != NULL) 
    {
        if (!present(unionList, temp2 -> data)
        {
            helper(&unionList, temp2 -> data);
        }
        temp2 = temp2 -> next;
    }
    return unionList;
}

void helper(Node** head, int x)
{
    Node* temp = NULL;
 
    // Insert the data
    temp -> data = x;
 
    // Add new node to linked list
    temp -> next = (*head);
 
    // new node is the head now
    (*head) = temp;
}
bool ispresent(Node* head, int x)
{
    Node* temp = head;
    while (temp != NULL) {
        if (temp -> data == x)
        {
            return true;
        }
        temp = temp -> next;
    }
    return false;
}
Node* getIntersection(Node* head1, Node* head2)
{
    Node* intersectionList = NULL;
    Node* temp = head1;
 
    // traverse list 1 
    while (temp != NULL) 
    {
        // Check each element in list 2
        if (isPresent(head2, temp -> data))
        {
            helper(&intersectionList, temp -> data);
        }
        temp = temp -> next;
    }
    return intersectionList;
}

/* Function to print the linked list */
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    return;
}  
int main()
{
    Node *head1 = takeinput();
    Node *head2 = takeinput();
    Node *resultIntersection = NULL;
    Node *resultUnion = NULL;

    cout << "Given Linked List1:- " ;
    print(head1);
    cout << endl;
    cout << "Given Linked List2:- " ;
    print(head2);
    cout << endl;
    resultUnion = getUnion(head1, head2);
    cout << "Union:- " ;
    print(resultUnion); 
    cout << endl;
    cout << "Intersection:- " ;
    print(resultIntersection);
}