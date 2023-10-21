#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll n,m,lvl[4005],s,d,ptr[4005],con,avl[4005],ans[10005],q;
struct edge
{
    ll a,b,cap,flow;
};
vector<edge>e;
vector<pair<ll,ll> >pp,qry;
vector<ll>v[4005];
void init()
{
    ll i;
    for(i=1;i<=4003;i++)
    {
        v[i].clear();
        avl[i]=0;
    }
    for(i=1;i<=10000;i++)
    {
        ans[i]=0;
    }
    e.clear();
    pp.clear();
    qry.clear();
}
void add_edge(ll a,ll b,ll cap)
{
    edge e1={a,b,cap,0};
    edge e2={b,a,0,0};
    v[a].push_back(e.size());
	e.push_back(e1);
	v[b].push_back(e.size());
	e.push_back(e2);
}
bool bfs()
{
    ll i,j,k;
    queue<ll>q;
    q.push(s);
    memset(lvl,-1,sizeof lvl);
    lvl[s]=0;
    while(!q.empty())
    {
        j=q.front();
        q.pop();
        for(k=0;k<v[j].size();k++)
        {
            ll id=v[j][k];
            ll to=e[id].b;
            if(lvl[to]==-1&&e[id].flow<e[id].cap)
            {
                lvl[to]=1+lvl[j];
                q.push(to);
            }
        }
    }
    return (lvl[d]!=-1);
}
ll dfs(ll cur,ll flow)
{
    ll i,j;
    if(cur==d)
    return flow;
    for(;ptr[cur]<v[cur].size();ptr[cur]++)
    {
        ll id=v[cur][ptr[cur]];
        ll to=e[id].b;
        if(lvl[to]!=(1+lvl[cur])||(e[id].cap-e[id].flow<=0))
        continue;
        ll f=dfs(to,min(flow,e[id].cap-e[id].flow));
        if(f>0)
        {
           e[id].flow+=f;
           e[id^1].flow-=f;
           return f;
        }
    }
    return 0;
}
ll maxflow()
{
    ll total_flow=0,j;
    while(bfs())
    {
        memset(ptr,0,sizeof ptr);
        while(1)
        {
            if(j=dfs(s,10000000000000000))
            {
                total_flow+=j;
            }
            else
            break;
        }
    }
    return total_flow;
}
void flow_ans()
{
    ll i,j,k,x,y;
    for(i=0;i<con;i++)
    {
        x=pp[i].first;
        y=pp[i].second;
        add_edge(x,n+y,1);
    }
    for(i=1;i<=n;i++)
    {
        add_edge(s,i,1);
    }
    vector<ll>eids;
    for(i=1;i<=m;i++)
    {
        add_edge(i+n,d,avl[i]);
        eids.push_back(e.size()-2);
    }
    ll prt=maxflow();
    for(i=q-1;i>=0;i--)
    {
        x=qry[i].first;
        y=qry[i].second;
        e[eids[x-1]].cap+=y;
        //cout<<e[eids[x-1]].a<<" "<<e[eids[x-1]].b<<" "<<e[eids[x-1]].cap<<"\n";
        prt+=maxflow();
        //cout<<prt<<"\n";
        ans[i]=prt;
    }
    cout << "OUTPUT:" <<endl;
    for(i=0;i<q;i++)
    {
        cout<<ans[i]<<"\n";
    }
}
void solve()
{
    init();
    ll i,j,ans,x,y;
    cin>>n>>m>>con;
    s=n+m+1;
    d=n+m+2;
    ans=0;
    for(i=1;i<=con;i++)
    {
        cin>>x>>y;
        pp.push_back({x,y});
    }
    for(i=1;i<=m;i++)
    {
        cin>>avl[i];
    }
    cin>>q;
    for(i=1;i<=q;i++)
    {
        cin>>x>>y;
        qry.push_back({x,y});
        avl[x]-=y;
    }
    flow_ans();
}
int main()
{
    solve();
    return 0;
}