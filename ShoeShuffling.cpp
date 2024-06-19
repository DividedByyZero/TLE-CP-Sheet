//problem link : https://codeforces.com/contest/1691/problem/B
// Tags : constructive ,algorithms greedy ,implementation ,two pointers
#include<bits/stdc++.h>
#define ll              long long
#define ull             unsigned long long
#define pb              push_back
#define all(v) v.begin(), v.end()
#define fastread()      (ios_base:: sync_with_stdio(false),cin.tie(NULL));
#define debug(x) cout << #x <<" "<< x << endl;
using namespace std;
const ll M = 1e9+7;
ll mypow(ll a, ll b){
    ll ans = 1;
    while(b){
        if (b&1) ans = (ans*a) % M;
        b /= 2;
        a = (a*a) % M;
    }
    return ans;
}
ll sumup(vector<ll>v,ll pos,ll value){
    if(pos != -1){
        v[pos] = value;
    }
    ll mx = v[v.size()-1];
    ll sum = 0;
    for(ll i=v.size()-1;i>=0;i--){
        if(v[i]<mx){
            v[i] *= (-1*1ll);
        }
        else if(v[i]>mx){
            mx = v[i];
        }
        sum += v[i];
    }
    return sum;
}

// vector<string>v;

// void generateBalanceString(string s,int value,int l,int r){
//     if(value < 0) return;
//     if(l<0) return;
//     if(r>0) return;
//     if(value == 0 && l == 0 && r==0){
//         v.push_back(s);
//         return;
//     }
//     string s1 = s+"(";
//     string s2 = s+")";
//     generateBalanceString(s1,value+1,l-1,r);
//     generateBalanceString(s2,value-1,l,r+1);
// }

int main()
{
    ll t ; cin >> t;
    while(t--){
        ll n; cin >> n;
        map<ll,vector<ll>>m;
        for(int i=0;i<n;i++){
            ll x; cin >> x;
            m[x].push_back(i+1);
        }
        ll flag = 1;
        for(auto x :m){
            if(x.second.size()==1){
                flag = 0;
                break;
            }
        }
        if(flag){
            for(auto x : m){
                cout <<x.second[x.second.size()-1]<<" ";
                for(int i=0;i<x.second.size()-1;i++){
                    cout << x.second[i]<<" ";
                }
            }
            cout << endl;
        }
        else{
            cout << -1 <<endl;
        }

    }
}
