/*** بسم الله الرحمن الرحيم  ***/
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define watch(x) cout<<(#x)<<" = "<<x<<endl
#define endl    "\n"	
#define all(v) ((v).begin()), ((v).end())
#define allr(s) s.rbegin(),s.rend()
#define vi      vector<int>
#define vl      vector<ll>
#define SetPrecision(x)  cout << fixed << setprecision(x)
#define sz(s)	(ll)(s.size())
#define PI   acos(-1)
#define Fast  std::ios_base::sync_with_stdio(0);cin.tie(NULL);	cout.tie(NULL);
typedef long long ll;
const ll mod = 1e9 + 7, oo = 0x3f3f3f3f;
using namespace std;

int dr[] = { 0,0,1,-1,1,-1,1,-1 };
int dc[] = { 1,-1,0,0,1,-1,-1,1 };


void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
}

int n, m;
vector<vi>grid;
bool valid(int r, int c)
{
	return r > 0 && r <= n && c > 0 && c <= m;
}
int dijkstra(int sr, int sc, int tr, int tc)
{
	vector<vi>dis(n + 1, vi(m + 1, oo));
	dis[sr][sc] = grid[sr][sc];
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>q;
	q.push({ dis[sr][sc],{sr,sc} });
	while (!q.empty())
	{
		int ur = q.top().second.first;
		int uc = q.top().second.second;
		int w = q.top().first;
		q.pop();
		if (ur == tr && uc == tc)
			break;
		if (w != dis[ur][uc])
			continue;
		for (int i = 0; i < 4; i++)
		{
			int vr = ur + dr[i];
			int vc = uc + dc[i];
			if (valid(vr, vc) && dis[vr][vc] > dis[ur][uc] + grid[vr][vc]) {
				dis[vr][vc] = dis[ur][uc] + grid[vr][vc];
				q.push({ dis[vr][vc],{vr,vc} });
			}
		}
	}
	return dis[tr][tc];
	
}
void solve()
{
	cin >> n >> m;
	grid.clear();
	grid.resize(n + 1, vi(m + 1));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> grid[i][j];
		}
	}
	cout << dijkstra(1, 1, n, m) << "\n";
}
int main()
{
	Fast  file();

	int tstCase = 0, i = 1;
	cin >> i;
	while (i--)
	{
		solve();
	}
}