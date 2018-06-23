#include<bits/stdc++.h>
using namespace std;

int spanningTree(vector <pair<int,int> > g[], int n);
int main()
{
	int t ;
	cin>>t;
	while(t--)
	{
    int n,e;
    int w, mC;
    cin >> n>> e;
    vector <pair<int,int> > adj[n+1];
    for(int i = 0;i < e;++i)
    {
    	int x,y;
        cin >> x >> y >> w;
        adj[x].push_back({w, y});
        adj[y].push_back({w, x});
    }
    mC= spanningTree(adj, n);
    cout << mC << endl;
	}
  return 0;
}

class edge
{
public:
    int u,v,w;
    edge(int u,int w,int v)
    {
        this->u=u;
        this->v=v;
        this->w=w;
    }
};

class myComparator
{
public:
    int operator() (const edge& e1, const edge& e2)
    {
        return e1.w > e2.w;
    }
};

int spanningTree(vector <pair<int,int> > g[], int n)
{
	//Your code here
    priority_queue<edge, vector<edge>, myComparator> min_hp;
    int mC=0;
    for(int i=0;i<n;i++)
        for(auto itr=g[i].begin();itr!=g[i].end();itr++)
            min_hp.push(edge(i,itr->first,itr->second));
    vector<int> in_tree(n,0);
    int disc_comp=1;
    int num_edges_in_mst=0;
    while(!min_hp.empty() && num_edges_in_mst<n-1)
    {
        edge min=min_hp.top();
        min_hp.pop();
        if(in_tree[min.u]==in_tree[min.v] && in_tree[min.u]!=0)
            continue;
        mC+=min.w;
        if(in_tree[min.u]==0 && in_tree[min.u]==0)
        {
            in_tree[min.u]=disc_comp;
            in_tree[min.v]=disc_comp++;
        }
        if(in_tree[min.u]==0)
            in_tree[min.u]=in_tree[min.v];
        else
            in_tree[min.v]=in_tree[min.u];
        num_edges_in_mst++;
    }
    return mC;
}
