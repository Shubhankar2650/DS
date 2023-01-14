
/*
    A social networking site has the users  who are friends with each other.
    A edge between two nodes shows that the they are friends with each other.
    Write a code to find the immediate friend of each of the user in the site

*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<char>> edges = {{'A', 'B'}, {'B', 'D'}, {'A', 'D'}, {'B', 'C'}, {'C', 'E'}, {'E', 'D'}};

    int total = 5;
    vector<char> graph[total];

    for (int i = 0; i < edges.size(); i++)
    {
        char u = edges[i][0];
        char v = edges[i][1];
        graph[u - 'A'].push_back(v);
        graph[v - 'A'].push_back(u);
    }

    for (int i = 0; i < total; i++)
    {
        string s = "";
        s += (char)(i + 'A');
        cout << "Friends of " + s + " are: ";
        for (auto j : graph[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }
}