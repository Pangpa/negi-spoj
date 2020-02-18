#include<iostream>
#include<cstring>
using namespace std;
#define G(i) (i &(-i))

typedef long long ll;

const int maxn = 1e5 + 10;

ll BIT1[maxn];
ll BIT2[maxn];
int n;
void update (ll * b , int i, ll x){
	while (i <= n){
		b[i] += x;
		i += G(i);
	}
}
ll sum(ll * b, int i){
	ll r = 0;
	while (i > 0){
		r += b[i];
		i -= G(i);
	}
	return r;
}
void range_update(int l, int r, ll x){
	update(BIT1, l, x);
	update(BIT1, r+1,-x);
	update(BIT2, l, (l-1) * x);
	update(BIT2, r+1, -x*r);
}
ll prefix_sum(int i){
	return sum(BIT1, i) * i - sum(BIT2, i);
}
ll range_sum(int l , int r){
	return prefix_sum(r) -prefix_sum(l-1);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t,i,c, test,p,q;
	ll v;
	cin>>t;
	while(t--){
		cin>>n>>c;
		while(c--){
			cin>>test>>p>>q;
			if(test == 0){
				cin>>v;
				range_update(p, q, v);
			}
			else {
				cout<<range_sum(p,q)<<"\n";
			}
		}
		memset(BIT1,0, sizeof(BIT1));
		memset(BIT2,0, sizeof(BIT2));
	}
	return 0;
}
