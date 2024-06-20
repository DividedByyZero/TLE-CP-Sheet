//Problem Link : https://codeforces.com/contest/1632/problem/B

#include<bits/stdc++.h>
#define ll long long int
#define yes cout << "YES" << endl
#define show(x) cout << x << endl;
#define no cout << "NO" << endl
#define ull unsigned long long int
#define all(v) v.begin(),v.end()
#define print(v) for(auto x : v) cout << x << " "; cout << endl;
ll mypow(ll a, ll b){ ll ans = 1; while(b){ if (b&1) ans = (ans*a) ; b /= 2; a = (a*a); } return ans; }
#define init(arr, val) memset(arr, val, sizeof(arr))
using namespace std;

void ans(string &s ,int low,int high,int &remain,char ch){
	if(remain<=0)return;
	if(low>high){
		return;
	}
	int mid = (low+high+1)/2;
	s.insert(mid+1,1,ch);
	remain--;
	ans(s,low,mid-1,remain,ch);
	ans(s,mid,high,remain,ch);
}

int main()
{
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int x = log2(n-1);
		int stop = mypow(2,x);
		for(int i=stop-1;i>0;i--){
			cout << i << " ";
		}
		cout << 0 << " ";
		for(int i=stop;i<n;i++){
			cout << i << " ";
		}
		cout << endl;
	} 
}
