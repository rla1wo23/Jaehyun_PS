#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;

int main(){
  char c;
  queue<char> q;
  unordered_map<char,int> um;
  while(cin>>c){
    if(c!=cin.eof()||c!='\n'){
      if(q.size()<3){
        q.push(c);
        continue;
      }
      if(um[c]==1){//이미 큐에 인입
        q.push(q.front());
        q.pop();
      }else{//없음
       cout<<q.front()<<" ";
       um[q.front()]=0;
       q.pop();
       um[c]=1;
       q.push(c);
      }
    }else{
      break;
    }
  }
}