/*
    YES PAIN YES GAIN
*/

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;
template<class T> using rbTree=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long int
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define unmap unordered_map
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define mem(u,v) memset(u,v,sizeof(u))
#define all(x) x.begin(),x.end()
#define r_all(x) x.rbegin(),x.rend()
#define vvi vector<vector<int>>
#define bug1 cout<<"hi1"<<endl
#define bug2 cout<<"hi2"<<endl
#define bug3 cout<<"hi3"<<endl

const int N=1e5+5;
const int M=3e5;
const int mod=1e9+7;

struct node
{
    int id,bribe,members;
}parent[N];

int find(int n)
{
    if(n==parent[n].id) return n;
    return parent[n].id=find(parent[n].id);
}

void unioN(int a,int b)
{
    a=find(a);
    b=find(b);
    
    if(a!=b)
    {
        if(parent[a].members<parent[b].members)
        {
            parent[a].id=parent[b].id;
            parent[b].members+=parent[a].members;
            parent[b].bribe=min(parent[b].bribe,parent[a].bribe);
        }
        else
        {
            parent[b].id=parent[a].id;
            parent[a].members+=parent[b].members;
            parent[a].bribe=min(parent[a].bribe,parent[b].bribe);
        }
    }
}

void solve()
{
    int n,m,a,b,ans=0;

    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        parent[i].id=i;
        parent[i].members=1;
        cin>>parent[i].bribe;
    }

    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        a--;
        b--;
        unioN(a,b);
    }

    for(int i=0;i<n;i++)
    {
        if(parent[i].id==i)
        {
            ans+=parent[i].bribe;
        }
    }

    cout<<ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif

    clock_t t1,t2;
    t1=clock();

    int t=1;
    //cin>>t;

    while(t--)
    {
        solve();
    }

    #ifndef ONLINE_JUDGE
    t2=clock();
    cerr<<"timeTaken : "<<(t2-t1)/(double)CLOCKS_PER_SEC;
    #endif

    return 0;
}