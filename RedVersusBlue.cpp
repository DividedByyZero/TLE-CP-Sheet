//problem Link : https://codeforces.com/contest/1659/problem/A


#include<bits/stdc++.h>
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
		int n,r,c; cin >> n >> r >> c;
		int mx,mn;
		char mx_char,min_char;
		if(r>=c){
			mx= r;
			mn = c;
			mx_char = 'R';
			min_char = 'B';
		}
		else{
			mx = c;
			mn = r;
			mx_char = 'B';
			min_char = 'R';
		}
		int repeat_after = (mx+mn)/(mn+1);
		int cnt = 0;
		vector<char>ans;
		for(int i=1;i<=mx;i++){
			ans.push_back(mx_char);
			if(i%repeat_after==0 && mn!=0){
				ans.push_back(min_char);
				mn--;
			}
			
		}
		if(mn){
			for(int i=1;i<ans.size();i++){
				if(ans[i-1]==mx_char && ans[i]==mx_char){
					ans.insert(ans.begin()+i,min_char);
					mn--;
				}
				if(mn==0) break;
			}
		}
		for(auto x : ans){
			cout << x ;
		}
		cout << endl;
	} 
}
