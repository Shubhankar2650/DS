#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int id;
    bool dsa;
    bool java;
    bool dbms;
    node *next;
    node(int s_id, bool dsaOpt, bool javaOpt, bool dbmsOpt)
    {
        this->id = s_id;
        this->dsa = dsaOpt;
        this->java = javaOpt;
        this->dbms = dbmsOpt;
    }
};

node *insert(node *head, int s_id, bool dsaOpt, bool javaOpt, bool dbmsOpt)
{
    node *temp = new node(s_id, dsaOpt, dbmsOpt, javaOpt);
    if (head)
        temp->next = head;
    return temp;
}

void enrolledInAll(node *head)
{
    cout << "Students UID'S ENROLLED IN ALL THREE:" << endl;
    while (head)
    {
        if (head->dsa && head->dbms && head->java)
            cout << head->id << endl;
        head = head->next;
    }
}

int main()
{
    // insert bool values 0- for not enrolled and 1 - for enrolled
    node *head = NULL;
    head = insert(head, 101, 0, 0, 1);
    head = insert(head, 102, 0, 1, 1);
    head = insert(head, 103, 1, 1, 1);
    head = insert(head, 104, 1, 1, 0);
    head = insert(head, 105, 1, 0, 0);
    head = insert(head, 106, 0, 0, 0);
    head = insert(head, 107, 1, 1, 1);
    head = insert(head, 108, 1, 1, 1);
    enrolledInAll(head);
    return 0;
}