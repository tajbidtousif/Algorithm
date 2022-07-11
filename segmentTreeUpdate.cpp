#include<bits/stdc++.h>
using namespace std;

const int mx = 1005;
int ar[mx];
int tree[mx*4];

void init(int node, int b, int e)
{
    if (b == e) {      // base case
        tree[node] = ar[b];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;

    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node] = tree[Left] + tree[Right];
}

void update(int node, int b, int e, int i, int newnode)
{
    if(i > e || i < b)
    {
       return;
    }

    if(b>=i && e<=i)
    {
        tree[node] = newnode;
        return;
    }

    int left = node*2;
    int right = (node*2)+1;
    int mid = (b+e)/2;

    update(left, b, mid, i, newnode);
    update(right, mid+1, e, i, newnode);

    tree[node] = tree[left] + tree[right];
}

int main()
{
    int n;

    cout << "Size of array : ";
    cin >> n;

    for(int i=1; i<=n; i++)
    {
        cin >> ar[i];
    }

    init(1, 1, n);

    update(1, 1, n, 2, 10);

    cout << "Updated array : ";

    for(int i=1; i<=n; i++)
    {
        cout << ar[i] << " ";
    }

}
