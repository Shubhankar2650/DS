#include <bits/stdc++.h>
using namespace std;

void countingSort(vector<int> &arr)
{
    int maximumElement = *max_element(arr.begin(), arr.end());
    int minimumElement = *min_element(arr.begin(), arr.end());
    int range = maximumElement - minimumElement + 1;

    vector<int> count(range);
    vector<int> output(arr.size());
    for (int i = 0; i < arr.size(); i++)
        count[arr[i] - minimumElement]++;

    for (int i = 1; i < count.size(); i++)
        count[i] += count[i - 1];

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        output[count[arr[i] - minimumElement] - 1] = arr[i];
        count[arr[i] - minimumElement]--;
    }

    for (int i = 0; i < arr.size(); i++)
        arr[i] = output[i];
}

int main()
{
    vector<int> arr = {5, 3, 4, 6, 7, -11, 10};
    cout << "Given Array: ";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";

    countingSort(arr);
    cout << "\nSorted Array: ";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}