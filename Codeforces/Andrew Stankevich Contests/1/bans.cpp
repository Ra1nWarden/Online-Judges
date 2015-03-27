#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=100005;
const int INF=0x3f3f3f3f;

struct Edge
{
    int to,next,cap,flow;
}edge[1000000];

int Size,Adj[maxn];
int gap[maxn],dep[maxn],pre[maxn],cur[maxn];

void init()
{
    Size=0;
    memset(Adj,-1,sizeof(Adj));
}

void add_edge(int u,int v,int w,int rw=0)
{
    edge[Size].to=v;edge[Size].cap=w;edge[Size].next=Adj[u];
    edge[Size].flow=0;Adj[u]=Size++;
    edge[Size].to=u;edge[Size].cap=rw;edge[Size].next=Adj[v];
    edge[Size].flow=0;Adj[v]=Size++;
}

int sap(int start,int end,int N)
{
    memset(gap,0,sizeof(gap));
    memset(dep,0,sizeof(dep));
    memcpy(cur,Adj,sizeof(Adj));
    
    int u=start;
    pre[u]=-1; gap[0]=N;
    int ans=0;
    
    while(dep[start]<N)
    {
        if(u==end)
        {
            int Min=INF;
            for(int i=pre[u];~i;i=pre[edge[i^1].to])
                if(Min>edge[i].cap-edge[i].flow)
                    Min=edge[i].cap-edge[i].flow;
            for(int i=pre[u];~i;i=pre[edge[i^1].to])
            {
                edge[i].flow+=Min;
                edge[i^1].flow-=Min;
            }
            u=start;
            ans+=Min;
            continue;
        }
        bool flag=false;
        int v;
        for(int i=cur[u];~i;i=edge[i].next)
        {
            v=edge[i].to;
            if(edge[i].cap-edge[i].flow&&dep[v]+1==dep[u])
            {
                flag=true;
                cur[u]=pre[v]=i;
                break;
            }
        }
        if(flag)
        {
            u=v;
            continue;
        }
        int Min=N;
        for(int i=Adj[u];~i;i=edge[i].next)
        {
            if(edge[i].cap-edge[i].flow&&dep[edge[i].to]<Min)
            {
                Min=dep[edge[i].to];
                cur[u]=i;
            }
        }
        gap[dep[u]]--;
        if(!gap[dep[u]]) return ans;
        dep[u]=Min+1;
        gap[dep[u]]++;
        if(u!=start) u=edge[pre[u]^1].to;
    }
    return ans;
}

int n,m;
int in[maxn],low[maxn];

int main()
{
    int T_T;
    scanf("%d",&T_T);
    while(T_T--)
    {
        /// INIT
        scanf("%d%d",&n,&m);
        init();
        memset(in,0,sizeof(in));
        memset(low,0,sizeof(low));
        int a,b,c,d;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d%d",&a,&b,&c,&d);
            in[a]-=c;in[b]+=c;
            low[i]=c;
            add_edge(a,b,d-c);
        }
        for(int i=1;i<=n;i++)
        {
            if(in[i]<0) add_edge(i,n+1,-in[i]);
            if(in[i]>0) add_edge(0,i,in[i]);
        }
        sap(0,n+1,n+2);
        bool flag=true;
        for(int i=Adj[0];~i;i=edge[i].next)
        {
            if(edge[i].cap!=edge[i].flow)
            {
                flag=false; break;
            }
        }
        if(flag==true)
        {
            puts("YES");
            for(int i=0;i<m;i++)
            {
                printf("%d\n",edge[2*i].flow+low[i]);
            }
        }
        else
        {
            puts("NO");
        }
    }
    return 0;
}
