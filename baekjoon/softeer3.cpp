#include<algorithm>
#include<iostream>
#include<vector>
#include <sstream>

using namespace std;

struct person{
  long long age;
  int sex;//여자가 0, 남자가 1
  int handicap=0;//3 비장애, 2환자, 1DP, 0PW;
};
bool sex_same(person p1,person p2){
  return p1.sex==p2.sex;
}
bool age_same(person p1,person p2){
  return (p1.age<=7&&p2.age<=7)||p1.age==p2.age;
}
bool handicap_same(person p1,person p2){
  return p1.handicap<p2.handicap;
}
bool cmp1(person p1,person p2){//123
  if(sex_same(p1,p2)){
    if(age_same(p1,p2)){
      return p1.handicap<p2.handicap;
    }else{
      return p1.age<p2.age;
    }
  }else{
    return p1.sex<p2.sex;
  }
}
bool cmp2(person p1,person p2){//132
  if(sex_same(p1,p2)){
    if(handicap_same(p1,p2)){
      return p1.age<p2.age;
    }else{
      return p1.handicap<p2.handicap;
    }
  }else{
    return p1.sex<p2.sex;
  }
}
bool cmp3(person p1,person p2){//213
  if(age_same(p1,p2)){
    if(sex_same(p1,p2)){
      return p1.handicap<p2.handicap;
    }else{
      return p1.sex<p2.sex;
    }
  }else{
    return p1.age<p2.age;
  }
}
bool cmp4(person p1,person p2){//231
  if(age_same(p1,p2)){
    if(handicap_same(p1,p2)){
      return p1.sex<p2.sex;
    }else{
      return p1.handicap<p2.handicap;
    }
  }else{
    return p1.age<p2.age;
  }
}
bool cmp5(person p1,person p2){//312
  if(handicap_same(p1,p2)){
    if(sex_same(p1,p2)){
      return p1.age<p2.age;
    }else{
      return p1.sex<p2.sex;
    }
  }else{
    return p1.handicap<p2.handicap;
  }
}
bool cmp6(person p1,person p2){//321
  if(handicap_same(p1,p2)){
    if(age_same(p1,p2)){
      return p1.sex<p2.sex;
    }else{
      return p1.age<p2.age;
    }
  }else{
    return p1.handicap<p2.handicap;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
    int c1, c2, c3;
    cin >> c1 >> c2 >> c3;
    int p;
    cin >> p;
    cin.ignore(); 
    vector<person> ps;
    for (int i = 0; i < p; ++i) {
        string line;
        getline(cin, line); 
        istringstream iss(line);
        person ip;
        string handicap_str;
        iss >> ip.sex >> ip.age;
        if (iss >> handicap_str) {
            if (handicap_str == "PW") ip.handicap = 0;
            else if (handicap_str == "DP") ip.handicap = 1;
            else ip.handicap = 2; 
        } else {
            ip.handicap = 3; 
        }

        ps.push_back(ip);
    }
  if(c1==1){
    if(c2==2){//123
      sort(ps.begin(),ps.end(),cmp1);
    }else{
      sort(ps.begin(),ps.end(),cmp2);
    }
  }else if(c1==2){//213
    if(c2==1){
      sort(ps.begin(),ps.end(),cmp3);
    }else{
      sort(ps.begin(),ps.end(),cmp4);
    }
  }else{
    if(c2==1){
      sort(ps.begin(),ps.end(),cmp5);
    }else{
      sort(ps.begin(),ps.end(),cmp6);
    }
  }
  for(int i=0;i<p;i++){
    if(ps[i].sex==0){
      cout<<"F ";
    }else{
      cout<<"M ";
    }
    cout<<ps[i].age<<" ";
    if(ps[i].handicap==0){
      cout<<"PW";
    }else if(ps[i].handicap==1){
      cout<<"DP";
    }else if(ps[i].handicap==2){
      cout<<"P";
    }
    cout<<"\n";
  }
} 