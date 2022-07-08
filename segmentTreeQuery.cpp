#include<bits/stdc++.h>
using namespace std;

#define mx 100001
int arr[mx];
int tree[mx * 3];

void init(int node, int b, int e)
{
    if (b == e) {
        tree[node] = arr[b];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;

    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node] = tree[Left] + tree[Right];
}
int query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
       { 
        return 0; 
       }

    if (b >= i && e <= j)
       { 
        return tree[node]; 
       }
    
    int Left = node * 2; 
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;

    int p1 = query(Left, b, mid, i, j);
    int p2 = query(Right, mid + 1, e, i, j);
    return p1 + p2; 
}

int main()
{
    int n;
    cout << "Enter array size: ";
    cin >> n;
    cout << "Enter the element : ";

    for(int i=1; i<=n; i++)
    {
        cin >> arr[i];
    }

    init(1, 1, n);
    int sum = query(1, 1, n, 3, 5);
    
    cout << "Sum is: " << sum << endl;

    return 0;
}
