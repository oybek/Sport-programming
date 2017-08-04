# Programming trainings

Source codes from solving problems on 
* [USACO Training Program][usaco]
* [Timus Online Judge][timus]
* [Codeforces][codeforces]
* [UVa Online Judge][uva] and other.

# Common algorithms
Mostly used algorithms and their illustrations
## Graph
### Dijkstra
![Found](https://upload.wikimedia.org/wikipedia/commons/5/57/Dijkstra_Animation.gif)
```cpp
#define INF 1000000001

struct edge
{
	int v, w;

	edge( int av, int aw )
		: v(av), w(aw)
	{}

	bool operator< ( const edge& a ) const
	{
		return w > a.w;
	}
};

int N, M;
vector< edge > G[ M_MAX ];
int dist[ N_MAX ];

void dijkstra( int src )
{
	priority_queue< edge > Q;

	for( int i = 1; i <= N; ++i )
	{
		dist[ i ] = INF;
	}
	dist[ src ] = 0;

	Q.push( edge( src, dist[src] ) );

	while( !Q.empty() )
	{
		edge cur = Q.top(); Q.pop();
		if( cur.w > dist[cur.v] )
		{
			continue;
		}

		for( int i = 0; i < G[ cur.v ].size(); ++i )
		{
			edge next = G[cur.v][i];
			if( dist[cur.v] + next.w < dist[next.v] )
			{
				dist[next.v] = dist[cur.v] + next.w;
				Q.push( edge(next.v, dist[next.v]) );
			}
		}
	}
}

```
# Gifs

When you found counter test after sending your code to the testing system

![Found](https://media.giphy.com/media/uoYauVJj6anpC/giphy.gif)

# For inspiration

[![Alt text](http://www.letsbebrief.co.uk/letsbebrief-content/uploads/nike_take_it_to_the_next_level_535.jpg)](https://www.youtube.com/watch?v=lZA-57h64kE)

[timus]: <http://acm.timus.ru>
[usaco]: <http://train.usaco.org>
[uva]: <http://uva.online-judge.org>
[codeforces]: <http://codeforces.ru>
