
//http://codeforces.com/contest/873/problem/B
#include<bits/stdc++.h>
using namespace std;
# define INF 1e19
typedef pair<unsigned long, unsigned long> iPair;
unsigned long n,m,f,s,t;
class Graph
{
    unsigned long V;
    list< pair<unsigned long, unsigned long> > *adj;

public:
    Graph(unsigned long V);
    void addEdge(unsigned long u, unsigned long v, unsigned long w);
    void shortestPath(unsigned long s, unsigned long d);
    void addFlight(unsigned long u, unsigned long v);
};

Graph::Graph(unsigned long V)
{
    this->V = V;
    adj = new list<iPair> [2*V];
    for(int i = 0 ; i < V; i++) {
        adj[i].push_back(make_pair(i+V, 0));
    }
}

void Graph::addEdge(unsigned long u, unsigned long v, unsigned long w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
    adj[u+this->V].push_back(make_pair(v+this->V, w));
    adj[v+this->V].push_back(make_pair(u+this->V, w));
}

void Graph::addFlight(unsigned long u, unsigned long v){
    adj[u].push_back(make_pair(v+this->V, 0));
}


void Graph::shortestPath(unsigned long src, unsigned long d)
{
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;

    vector<unsigned long> dist(2*V, INF);
    pq.push(make_pair(0, src));
    dist[src] = 0;
    while (!pq.empty())
    {
        unsigned long u = pq.top().second;
        pq.pop();

        list< pair<unsigned long, unsigned long> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            unsigned long v = (*i).first;
            unsigned long weight = (*i).second;

            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    cout << min(dist[d+this->V], dist[d]) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n >>m >> f >> s >> t;

    Graph g(n);

    for(unsigned long i = 0; i < m; i++) {
        unsigned long u,v,w;
        cin >> u >> v >> w;
        g.addEdge(u,v,w);
    }

    for(unsigned long i = 0; i < f; i++){
        unsigned long u,v;
        cin >> u >> v;
        g.addFlight(u,v);
    }

    g.shortestPath(s,t);

    return 0;
}
