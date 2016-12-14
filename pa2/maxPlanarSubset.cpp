#include <iostream>
#include <cstdlib>
using namespace std;

int answer[90000][90000];

int n;

int *info;
int main(){
	cin>>n;
	info=new int[n];
	for(int k=0;k<n;k++){
		info[k]=-1;
	}
	int str, en;
	while(1){
		cin>>str>>en;
		info[str]=en;
		info[en]=str;
		str=-1; en=-1;
		if(str==0 && en==-1){
			break;
		}
	}

	FindMaxPlanarSubset();
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			cout<<answer[x][y]<<" ";
		}
		cout<<endl;
	}
}

void FindMaxPlanarSubset(){	
		for(int a=0;a<n;a++){
			for(int b=0;b<n;b++){
				if(a==b){
					answer[a][b]=0;
				}
				else if(info[a]!=-1){
					if(info[a]>b){
						answer[a][b] = answer[a][b];
					}
					else{
						answer[a][b] = answer[a][info[a]-1]+1+answer[info[a]+1][b-1];
					}
				}
				else{
					answer[a][b] = answer[a+1][b-1]+1;
				}
			}
		}
	
	
}