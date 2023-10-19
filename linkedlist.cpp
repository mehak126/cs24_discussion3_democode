// Code from: https://www.geeksforgeeks.org/program-to-implement-singly-linked-list-in-c-using-class/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList
{
    Node *head;

public:
    // Default constructor
    LinkedList()
    {
        head = NULL;
    }

    // Destructor
    ~LinkedList()
    {
        // You will implement this in lab01 :)
        return;
    }

    // Insert new node with data
    void insertNode(int);

    // Print linked list
    void printList();
};

void LinkedList::insertNode(int data)
{

    Node *newNode = new Node(data); // This is on the heap!

    if (head == NULL) // If the linked list is empty, make the new node head
        head = newNode;
    else
    { // Else, traverse till the end of the list and add the new node as the last node
        Node *temp = head;
        while (temp->next != NULL) // While temp is not the last element
            temp = temp->next;

        temp->next = newNode;
    }
}

void LinkedList::printList()
{
    Node *temp = head;

    if (head == NULL)
    {
        cout << "Empty List" << endl;
        return;
    }

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    LinkedList list;

    // Print list before inserting anything
    list.printList();

    // Insert some elements
    list.insertNode(1);
    list.insertNode(2);
    list.insertNode(3);
    list.insertNode(4);

    list.printList();

    return 0;
}