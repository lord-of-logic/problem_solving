#include<bits/stdc++.h>
using namespace std;

int spanningTree(vector <pair<int,int> > g[], int n);
int main()
{
	int t ;
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
        if(e1.w==e2.w)
            return e1.u+e1.v+e1.w > e2.u+e2.v+e2.w;
        return e1.w > e2.w;
	}
};

int spanningTree(vector <pair<int,int> > g[], int n)
{
	//Your code here
	priority_queue<edge, vector<edge>, myComparator> min_hp;
	int mC=0;//cost of mst
	for(int i=1;i<n+1;i++)
		for(auto itr=g[i].begin();itr!=g[i].end();itr++)
			if(i!=itr->second)//to ignore self loops
				min_hp.push(edge(i,itr->first,itr->second));
	vector<int> in_tree(n+1,0);//sub component tracking
	int disc_comp=1;
	int num_edges_in_mst=0;
	while(!min_hp.empty() && num_edges_in_mst<n-1)
	{
		edge min=min_hp.top();
		min_hp.pop();
        //cout<<in_tree[min.u]<<" "<<min.w<<" "<<in_tree[4]<<"\n";
		if(in_tree[min.u]==in_tree[min.v] && in_tree[min.u]!=0)
			continue;
		mC+=min.w;
        	num_edges_in_mst++;
		if(in_tree[min.u]==0 && in_tree[min.v]==0)
		{
			in_tree[min.u]=disc_comp;
			in_tree[min.v]=disc_comp++;
			continue;
		}
		if(in_tree[min.u]==0)
	    		in_tree[min.u]=in_tree[min.v];
		else if(in_tree[min.v]==0)
			in_tree[min.v]=in_tree[min.u];
		else
		{
			int old_comp=in_tree[min.v];
			for(int i=1;i<n+1;i++)
				if(in_tree[i]==old_comp)
					in_tree[i]=in_tree[min.u];
		}
	}
	return mC;
}
