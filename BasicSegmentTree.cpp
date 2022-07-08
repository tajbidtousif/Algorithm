#include<bits/stdc++.h>
using namespace std;

const int mx = 100005;
int ar[100];
int tree[100*4];

void init(int node, int b, int e)
{
    if(b==e) //base condition
    {
        tree[node] = ar[b];
        return;
    }

    int left = node*2;
    int right = (node*2)+1;
    int mid = (b+e)/2;
    
    init(left, b, mid);
    init(right, mid+1, e);

    tree[node] = tree[left] + tree[right];
}

int main()
{
    int n;
    cin >> n;

    //repl(i,n) cin >> ar[i];

    for(int i=0; i<n; i++)
    {
        cin >> ar[i];
    }

    init(1, 1, n);
}