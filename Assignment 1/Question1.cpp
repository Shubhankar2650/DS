#include <iostream>
using namespace std;

// 👌13-Dec -2022

// 👌code string methods but using the pointers.
int slen(char *c)
{
    int i = 0;
    while (*(c + i) != '\0')
    {
        i++;
    }
    return i;
}

void rev(char *c)
{
    int n = slen(c);
    int i = 0,
        j = n - 1;
    char temp;
    while (i < n / 2)
    {
        temp = *(c + i);
        *(c + i) = *(c + j);
        *(c + j) = temp;
        i++;
        j--;
    }
}

void strcpy(char *c1, char *c2)
{

    while (*c1 != '\0')
    {
        c1++;
    }
    while (*c2 != '\0')
    {
        *c1 = *c2;
        c1++;
        c2++;
    }
    *c1 = '\0';
}

void strncpy(char *c1, char *c2, int n)
{
    while (*c1 != '\0')
    {
        *c1++;
    }
    while (n--)
    {
        *c1 = *c2;
        *c1++;
        *c2++;
    }
    *c1 = '\0';
}

int strcmp(char *c1, char *c2)
{
    int result;
    while (*c1 != '\0' && *c2 != '\0')
    {
        result += (*c1 - *c2);
        *c1++;
        *c2++;
    }
    while (*c1 != '\0')
    {
        result += *c1;
        *c1++;
    }
    while (*c2 != '\0')
    {
        result += *c2;
        *c2++;
    }
    return result;
}

int main()
{
    // ✒️strcpy(s1, s2); Copies string s2 into string s1.
    char s1[] = "Shubh";
    char s2[] = "ankar";

    // strcpy(s1, s2);
    // rev(s2);
    cout << slen(s1) << endl;
    cout << s1 << endl;
    cout << s2 << endl;

    // strncpy(s1, s2, 3);
    cout << strcmp(s1, s2) << endl;
}