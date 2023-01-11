#include <bits/stdc++.h.txt>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    int size = 0;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        size++;
    }
};

Node *insertTillNegativeOne()
{
    int data;
    cin >> data;

    Node *head = NULL;
    Node *tail = NULL;

    while (data != -1)
    {
        Node *new_node = new Node(data);
        if (!head)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
        }
        cin >> data;
    }

    return head;
}

// 1.	Addition of a new value at a given position

void add(Node **root, int data, int place)
{
    // if (place == 1)
    // {
    //     root = new Node(data);
    //     return;
    // }
    if (place < 1)
    {
        cout << "Invalid input";
        return;
    }
    else
    {
        int count = 1;
        while (*root != NULL)
        {
            if (count == place)
            {
                Node *temp = new Node(data);
                temp->next = *root;
                *root = temp;
                return;
            }
            count++;
            root = &(*root)->next;
        }
    }
}

// 2.	Print all the values in the list

void print(Node *root)
{
    Node *temp = root;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// 3.	Delete a given value from a location

void deleteValue(Node *root, int data)
{
    if (root == NULL)
        return;
    Node *prev = root;
    while (root != NULL)
    {

        if (root->data == data)
        {
            Node *temp = root;
            prev->next = root->next;
            delete temp;
            return;
        }
        prev = root;
        root = root->next;
    }
}

int main()
{
    Node *head = NULL;
    head = insertTillNegativeOne();
    print(head);

    add(&head, 10, 3);
    print(head);
    cout << endl;

    int n;
    cout << "Type the value to be deleted from list: ";

    cin >> n;
    deleteValue(head, n);
    print(head);
}
