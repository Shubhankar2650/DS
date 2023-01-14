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

node *insertHead(node *head, int s_id, bool dsaOpt, bool javaOpt, bool dbmsOpt)
{
    node *temp = new node(s_id, dsaOpt, dbmsOpt, javaOpt);
    if (head)
        temp->next = head;
    return temp;
}

void enrolledInAll(node *head)
{
    cout << "UID'S ENROLLED IN ALL THREE:" << endl;
    while (head)
    {
        if (head->dsa && head->dbms && head->java)
            cout << head->id << endl;
        head = head->next;
    }
}

int main()
{
    // insert bool values node in order of HEAD-S_ID DSA -JAVA- DBMS
    node *head = NULL;
    head = insertHead(head, 101, 0, 0, 1);
    head = insertHead(head, 102, 0, 1, 1);
    head = insertHead(head, 103, 1, 1, 1);
    head = insertHead(head, 104, 1, 1, 0);
    head = insertHead(head, 105, 1, 0, 0);
    head = insertHead(head, 106, 0, 0, 0);
    head = insertHead(head, 107, 1, 1, 1);
    head = insertHead(head, 108, 1, 1, 1);
    enrolledInAll(head);
    return 0;
}