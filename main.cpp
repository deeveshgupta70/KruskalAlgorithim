#include<bits/stdc++.h>

using namespace std;


#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define F first
#define S second
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(vector<vector <T>> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(vector<vector<T>> v) {cerr << "\n"; for (auto i : v) { for( auto t : i){cerr<<t; cerr << " ";} cerr<<"\n";}}

class edges{
public:
	pair<int,int> src;
	int weight;
};


bool cmp( edges a , edges b){

	return a.weight < b.weight ;

}

int findParent( int v, vector<int>& parent){

	if( parent[v] == v) return v;

	return findParent( parent[v] , parent);
}


vector<edges> KruskalsAlgo( vector<edges>& req , int V){


	vector<edges> res;

	vector<int> parent( V , 0);
	for( int i = 0; i < V ; i++) parent[i] = i;

	int count = 0;
	int i = 0;

	while ( count != V-1 && i <= req.size()){

		edges cur = req[i];

		int sourceParent = findParent( cur.src.first , parent);
		int destParent = findParent( cur.src.second , parent);

		if( sourceParent != destParent){

			res.push_back( cur);

			count++;

			parent[sourceParent] = destParent;
		}

		i++;
	}

	return res;
}


int main() {
#ifndef ONLINE_JUDGE
  freopen("Error.txt", "w", stderr);
#endif
fastio();
	
	int v;
	cin>>v;

	int e;
	cin>>e;

	vector<edges> edg(e);

	for( int i = 0; i < e; i++){
		int x,y,z;
		cin>>x>>y>>z;

		edg[i].src = make_pair(x,y);
		edg[i].weight = z;
	}



	sort( edg.begin() , edg.end() , cmp);

	vector<edges> res = KruskalsAlgo( edg , v);

	for( auto i : res){

		cout<<i.src.first <<" "<< i.src.second<<" "<<i.weight<<"\n";
	}

 

return 0;

}

/*
Input:
6 11
0 1 1
0 2 5
2 3 10
0 3 4
1 3 3
1 2 6
3 4 7
2 4 8 
4 5 2
2 5 9
3 5 6

Ouput:
0 1 1
4 5 2
1 3 3
0 2 5
3 5 6

 */
