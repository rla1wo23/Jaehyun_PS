#include <iostream>
#include <stack>
using namespace std;
int arr[1000005];
int value[1000005];
int ans[1000005];
int calc_value(int idx){
	return value[arr[idx]];
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>arr[i];
		value[arr[i]]++;
		ans[i]=-1;
	}
	stack<int> s;
	for(int i=0;i<N;i++){
		while(!s.empty()&&calc_value(s.top())<calc_value(i)){
			int idx=s.top(); s.pop();
			ans[idx]=arr[i];	
		}
		s.push(i);
	}
	for(int i=0;i<N;i++){
		cout<<ans[i]<<" ";
	}
}
