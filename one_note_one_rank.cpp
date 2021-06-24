/*
 * main.cpp
 *
 *  Created on: 2021Äê6ÔÂ24ÈÕ
 *      Author: wghaotian
 */
#include<bits/stdc++.h>
#define maxn 1000
using namespace std;
struct element{
	int note, rank, year;
	element(){note=0,rank=0,year=0;}
	element(int x, int y, int z){
		note=x,rank=y,year=z;
	}
};
bool operator <(const element& x,const element& y){
	return (x.rank<y.rank);
}
bool operator >(const element& x,const element& y){
	return (x.rank>y.rank);
}
bool operator ==(const element& x,const element& y){
	return (x.rank==y.rank);
}
queue<element> q_last,q_this;
inline void read(){
	int x=0,y,z=2020;
	cin>>x>>y;
	while (x<=480){
		q_last.push(element(x,y,2020));
		cin>>x>>y;
	}
	while (x!=0){
		q_this.push(element(x,y,2021));
		cin>>x>>y;
	}
}
vector<element>ans;
inline void merge(){
	element x;
	while((!q_this.empty())&&(!q_last.empty())){
		if (q_this.front().rank<q_last.front().rank){
			x=q_this.front();
			q_this.pop();
			ans.push_back(x);
		}
		else{
			x=q_last.front();
			q_last.pop();
			ans.push_back(x);
		}
	}
	while (!q_this.empty()){
		ans.push_back(q_this.front());
		q_this.pop();
	}
	while (!q_last.empty()){
		ans.push_back(q_last.front());
		q_last.pop();
	}
}
inline void print(){
	int n=ans.size();
	for (int i=0;i<n;i++){
		if (ans[i].year==2020) continue;
		int j1,j2;
		for (j1=i-1;ans[j1].year==2021;j1--);
		for (j2=i+1;ans[j2].year==2021;j2++);
		cout<<ans[i].note<<"\t"<<ans[i].rank<<"\t"<<ans[j1].note<<"\t"<<ans[j2].note<<"\n";
	}
}
int main(){
	read();
	merge();
	print();
}
