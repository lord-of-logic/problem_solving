#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int * topoSort(vector<int> graph[], int N)
{
    int *A=new int[N];
    queue<int> Q;
    vector<int> in_deg(N,0);
    for(int i=0;i<N;i++)
        for(auto itr=graph[i].begin();itr!=graph[i].end();itr++)
           in_deg[*itr]++;
    for(int i=0;i<in_deg.size();i++)
        if(in_deg[i]==0)
            Q.push(i);
    int i=0;
    while(!Q.empty())
    {
        int now=Q.front();
        Q.pop();
        A[i++]=now;
        in_deg[now]=-1;
        for(auto itr=graph[now].begin();itr!=graph[now].end();itr++)
        {
            in_deg[*itr]--;
            if(in_deg[*itr]==0)
                Q.push(*itr);
        }
    }
    return A;
}

int main()
{
    int T;
    cin>>T;
    while(T)
    {
        int num_nodes,num_edges;
        cin>>num_nodes>>num_edges;
        vector<int> G[num_nodes];
        for(int i=0;i<num_edges;i++)
        {
            int start,end;
            cin>>start>>end;
            G[start-1].push_back(end-1);
            G[end-1].push_back(start-1);
        }
        topoSort(G,num_nodes);
        T--;
    }
    return 0;
}
