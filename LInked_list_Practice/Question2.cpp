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

void print(Node *root)
{
    Node *temp = root;
    while (temp != NULL)
    {
        if (!temp->next)
        {
            cout << temp->data;
        }
        else
        {
            cout << temp->data << "->";
        }
        temp = temp->next;
    }
}

int rest(Node *n1, Node *n2)
{
    int a = 0, b = 0;
    int i = 0, j = 0;

    while (n1 != NULL)
    {
        a = a + (n1->data * pow(10, i));
        n1 = n1->next;
        i++;
    }

    while (n2 != NULL)
    {
        a = a + (n2->data * pow(10, i));
        n2 = n2->next;
        j++;
    }

    a = a + b;
    return a;
}

// inserting finally obtained integer as  astring.

Node *insertNumberInLL(int n)
{
    Node *head = NULL;
    Node *tail = NULL;
    while (n != 0)
    {
        int temp = n % 10;
        Node *new_node = new Node(temp);
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
        n = n / 10;
    }
    return head;
}

int main()
{
    Node *list1 = insertTillNegativeOne();
    Node *list2 = insertTillNegativeOne();
    cout << "List 1: ";
    print(list1);
    cout << "\nList 2: ";
    print(list2);

    int n = rest(list1, list2);
    Node *result = insertNumberInLL(n);
    cout << "\n\nFinal List: ";
    print(result);
}