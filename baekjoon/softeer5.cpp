#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<vector<pair<int,int>>> v(N+1); //(출발지, 코스트, 도착지)
  for(int i=0;i<N-1;i++){
    int st,en,cost;
    cin>>st>>en>>cost;
    v[st].push_back({cost,en});
    v[en].push_back({cost,st});
  }
  int costs[1005];
  bool vis[1005];
  for(int i=1;i<=N;i++){
    costs[i]=0;
    vis[i]=false;
  }
  stack<pair<int,int>> s;
  s.push({1,0});
  vis[1]=true;
  while(!s.empty()){
    int cur=s.top().first;
    int bef=s.top().second;
    s.pop();
    for(int i=0;i<v[cur].size();i++){
      int nxt=v[cur][i].second;
      if(vis[nxt]&&(nxt!=bef)){
        cout<<-1;
        return 0;
      }
      if(!vis[nxt]){
      vis[nxt]=true;
      s.push({nxt,cur});
      }
    }
  }
  for(int i=0;i<=N;i++){
    vis[i]=false;
  }
  queue<int> q;
  q.push(1);
  vis[1]=true;
  while(!q.empty()){
    int cur=q.front();
    q.pop();
    for(int i=0;i<v[cur].size();i++){
      int nxt=v[cur][i].second;
      if(!vis[nxt]){
        costs[nxt]=costs[cur]+v[cur][i].first;
        q.push(nxt);
        vis[nxt]=true;
      }
    }
  }
  int f_node=1;//이게 중요
  int f_cost=0;
  for(int i=2;i<=N;i++){
    if(f_cost<costs[i]){
      f_cost=costs[i];
      f_node=i;
    }
  }
  for(int i=1;i<=N;i++){
    costs[i]=0;
    vis[i]=false;
  }
  q.push(f_node); //제일 먼 노드
  vis[f_node]=true; //제일 먼 노드 방문처리
  while(!q.empty()){
    int cur=q.front();
    q.pop();
    for(int i=0;i<v[cur].size();i++){
      int nxt=v[cur][i].second;
      if(!vis[nxt]){
        costs[nxt]=costs[cur]+v[cur][i].first;
        q.push(nxt);
        vis[nxt]=true;
      }
    }
  }
  int e_node=f_node;
  int e_cost=0;
  for(int i=1;i<=N;i++){
    if(e_cost<costs[i]){
      e_cost=costs[i];
      e_node=i;
    }
  }
  if(e_node<f_node){
    swap(e_node,f_node);
  }
  cout<<e_cost<<"\n"<<f_node<<"\n"<<e_node;
}