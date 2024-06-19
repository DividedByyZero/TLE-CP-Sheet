// Problem Link : https://codeforces.com/contest/1690/problem/D

#include<bits/stdc++.h>
#define ll              long long
#define ull             unsigned long long
#define pb              push_back
#define ss              second
#define ff              first
#define fr(m) for(int i=0; i<m; i++)
#define fro(m) for(int i=1; i<m; i++)
#define frj(m) for(int j=0; j<m; j++)
#define frr(n) for(int i=n; i>=0; i--)
#define nl '\n'
#define yes cout<<"YES"<<nl
#define no cout<<"NO"<<nl
#define all(v) v.begin(), v.end()
#define fastread()      (ios_base:: sync_with_stdio(false),cin.tie(NULL));
#define debug(x) cout << #x <<" "<< x << endl;
using namespace std;
ll fact(ll n){ if(n==0) return 1; ll res = 1; for (ll i = 2; i <= n; i++) res = res * i; return res;}
ll nPr(ll n, ll r) { return fact(n) / fact(n - r); }
ll nCr(ll n, ll r) { return fact(n) / (fact(r) * fact(n - r)); }
ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b);}
ll mypow(ll a, ll b){ ll ans = 1; while(b){ if (b&1) ans = (ans*a) ; b /= 2; a = (a*a); } return ans; }
const ll M = 1e9+7;
////////////////////// Sort by Value MAP ////////////////////////////////////
bool cmp(pair<string, int>& a,
        pair<string, int>& b)
{
    return a.second < b.second;
}
void sort(map<string, int>& M)
{
    vector<pair<string, int> > A;
    for (auto& it : M) {
        A.push_back(it);
    }
    sort(A.begin(), A.end(), cmp);
    for (auto& it : A) {
        cout << it.first << ' '
            << it.second << endl;
    }
}
///////////////////////////////////////////////////////////////////////////////
///////////////////////////// Count Divisors O(n^1/3) ////////////////////////
void SieveOfEratosthenes(ll n, bool prime[],
                         bool primesquare[], ll a[])
{
    for (ll i = 2; i <= n; i++)
        prime[i] = true;
    for (ll i = 0; i <= (n * n + 1); i++)
        primesquare[i] = false;
    prime[1] = false;
    for (ll p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (ll i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
 
    ll j = 0;
    for (ll p = 2; p <= n; p++) {
        if (prime[p]) {
            a[j] = p;
            primesquare[p * p] = true;
            j++;
        }
    }
}
int countDivisors(ll n)
{
    if (n == 1)
        return 1;
    bool prime[n + 1], primesquare[n * n + 1];
    ll a[n];
    SieveOfEratosthenes(n, prime, primesquare, a);
    ll ans = 1;
    for (ll i = 0;; i++) {
        if (a[i] * a[i] * a[i] > n)
            break;
        ll cnt = 1;
        while (n % a[i] == 0)
        {
            n = n / a[i];
            cnt = cnt + 1;
        }
        ans = ans * cnt;
    }
    if (prime[n])
        ans = ans * 2;
    else if (primesquare[n])
        ans = ans * 3;
    else if (n != 1)
        ans = ans * 4;
    return ans;
}
///////////////////////////////////////////////////////////////////////////////////
///////////////////////////Check Prime ////////////////////////////////////////////

bool isPrime(ll n)
{
    // Corner case
    if (n <= 1)
        return false;
 
    // Check from 2 to square root of n
    for (ll i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
 
    return true;
}



int main() 
{
	ll t; cin >> t;
	while(t--){
		ll n,k; cin >> n >> k;
		string s; cin >> s;
		ll ans = n;
		ll color = 0;
		for(int i=0;i<k;i++){
			if(s[i] == 'W') color++;
		}
		ans = min(ans,color);
		ll track = 0;
		for(int i=k;i<n;i++){
			if(s[track] == 'W'){
				color--;
				track++;
			}
			else{
				track++;
			}
			if(s[i] == 'W') color++;
			ans = min(ans,color);
			//cout << ans << endl;
		}
		cout << ans << endl;
	}
}
