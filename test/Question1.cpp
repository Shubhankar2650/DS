// #include <bits/stdc++.h>
// using namespace std;

// /*
//     The hierarchy of a family is shown in a form of  Tree. Assume that all parent have max of 2 children.
//     For some reason  the last generation want to separate themselves from the tree.
//     Write a code to remove those children from the hierarchy tree
// */

// class Node
// {
// public:
//     int data;
//     Node *left;
//     Node *right;

//     Node(int data)
//     {
//         this->data = data;
//         this->left = NULL;
//         this->right = NULL;
//     }
// };

// void nodeAt_K_distance(Node *root, int k)
// {
//     if (root == NULL)
//         return;
//     if (k == 0)
//     {
//         cout << root->data << ", ";
//         return;
//     }
//     else
//     {
//         nodeAt_K_distance(root->left, k - 1);
//         nodeAt_K_distance(root->right, k - 1);
//     }
// }

// int height(Node *root)
// {
//     if (root == NULL)
//         return 0;
//     else
//     {
//         return max(height(root->left), height(root->right)) + 1;
//     }
// }

// void levelOderTraversal(Node *root)
// {
//     int h = height(root);
//     for (int i = 0; i <= h; i++)
//     {
//         nodeAt_K_distance(root, i);
//     }
// }

//  nullify_nodeAt_K_distance(Node *root, int k)
// {
//     if (root == NULL)
//         return;
//     if (k == 0)
//     {
//         root = NULL;
//         return;
//     }
//     else
//     {
//         nullify_nodeAt_K_distance(root->left, k - 1);
//         nullify_nodeAt_K_distance(root->right, k - 1);
//     }
// }

// void removeLastDecendent(Node *root)
// {
//     int h = height(root);
//     nullify_nodeAt_K_distance(root, h);
// }

// void levelOrderQueue(Node *root)
// {
//     if (root == NULL)
//         return;
//     queue<Node *> q;
//     q.push(root);
//     while (q.empty() == false)
//     {
//         int n = q.size();
//         for (int i = 0; i < n; i++)
//         {
//             Node *currt = q.front();
//             cout << currt->data << ",";
//             if (currt->left != NULL)
//             {
//                 q.push(currt->left);
//             }
//             if (currt->right != NULL)
//             {
//                 q.push(currt->right);
//             }
//             q.pop();
//         }
//     }
// }

// int main()
// {
//     Node *head = NULL;
//     head = new Node(10);
//     head->left = new Node(5);
//     head->right = new Node(20);
//     head->left->right = new Node(7);
//     head->right->left = new Node(15);
//     head->right->right = new Node(30);
//     head->left->right->left = new Node(12);

//     cout << "Given tree : ";
//     levelOderTraversal(head);

//     cout << "\nTree after removing last childreen of the family:";
//     removeLastDecendent(head);
//     levelOderTraversal(head);
// }

#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *createNewNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int height(Node *root)
{
    if (root == NULL)
        return 0;
    else
    {
        return max(height(root->left), height(root->right)) + 1;
    }
}

void removeGeneration(Node *root, int generation)
{
    if (root == NULL)
    {
        return;
    }

    if (generation == 0)
    {
        root->left = root->right = NULL;
    }
    else
    {
        removeGeneration(root->left, generation - 1);
        removeGeneration(root->right, generation - 1);
    }
}

void levelOrderQueue(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while (q.empty() == false)
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *currt = q.front();
            cout << currt->data << ",";
            if (currt->left != NULL)
            {
                q.push(currt->left);
            }
            if (currt->right != NULL)
            {
                q.push(currt->right);
            }
            q.pop();
        }
    }
}

int main()
{
    Node *root = createNewNode(1);
    root->left = createNewNode(2);
    root->right = createNewNode(3);
    root->left->left = createNewNode(4);
    root->left->right = createNewNode(5);
    root->left->right->left = createNewNode(5);

    cout << "Original Tree : ";
    levelOrderQueue(root);
    cout << endl;

    int generation = height(root) - 2;
    removeGeneration(root, generation);

    cout << "Tree after removing generation " << generation << ": ";
    levelOrderQueue(root);
    cout << endl;

    return 0;
}