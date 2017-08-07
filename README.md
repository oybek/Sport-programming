git# Programming trainings

Source codes from solving problems on 
* [HackerRank][hackerrank] ([oybek][hackerrankme])
* [USACO Training Program][usaco]
* [Timus Online Judge][timus] ([oybek][timusme])
* [Codeforces][codeforces] ([oybek][codeforcesme])
* [UVa Online Judge][uva] ([_oybek_][uvame])
and other.

[timus]: <http://acm.timus.ru>
[timusme]: <http://acm.timus.ru/author.aspx?id=124580&sort=difficulty>
[usaco]: <http://train.usaco.org>
[uva]: <http://uva.online-judge.org>
[uvame]: <http://uhunt.felix-halim.net/id/289023>
[codeforces]: <http://codeforces.ru>
[codeforcesme]: <http://codeforces.com/profile/oybek>
[hackerrank]: <https://www.hackerrank.com>
[hackerrankme]: <https://www.hackerrank.com/oybekjon>

# Life situations
When you found counter test after sending your code to the testing system

![](https://media.giphy.com/media/uoYauVJj6anpC/giphy.gif)

But whatever got AC

![](https://media.giphy.com/media/fDzM81OYrNjJC/giphy.gif)


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
# For inspiration

[![Alt text](http://www.letsbebrief.co.uk/letsbebrief-content/uploads/nike_take_it_to_the_next_level_535.jpg)](https://www.youtube.com/watch?v=lZA-57h64kE)
