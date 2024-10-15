#include <iostream>
#include <vector>
using namespace std;

int Binary_Search(vector<int> List, int n, int key)
{
    int low = List[0], high = List[n - 1], mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (List[mid] == key)
        {
            cout << "Element Found at index";
            return 1;
        }
        if (List[mid] > key)
            high = List[mid - 1];

        else
            low = List[mid + 1];
    }
    cout << "!Element Not found";
    return 0;
}

int main()
{
    int n, a;
    vector<int> v;
    cout << "Enter the size of vector: ", cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        v.push_back(a);
    }
    Binary_Search(v, n, 2);
    return 0;
}