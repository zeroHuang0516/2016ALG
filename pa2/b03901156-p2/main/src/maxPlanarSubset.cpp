#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
using namespace std;

class edge{
public:
	int str;
	int end;
};
class point{
public:
	bool isStr=false;
	int no;
};
struct less_than_key{
	inline bool operator() (const edge& edge1, const edge& edge2){
		return (edge1.str < edge2.str);
	}
};
int **answer;
int **index; 
int n;
point info[180000];
int k;
vector<int>backTrace;
edge tmpEdge;
vector<edge> s;
vector<edge> e;
FILE* fp;
int fd;
void FindMaxPlanarSubset(){
	for(int j=0;j<n;j++){
       k=info[j].no;
			for(int i=0;i<=j;i++){
				if(i==j){
					answer[i][i]=0;
					 
				}
				
				//else if(info[j]!=-1){
          if(k>=i && k<=j-1 && ((answer[i][k-1]+1+answer[k+1][j-1])>answer[i][j-1])){
            answer[i][j]=answer[i][k-1]+1+answer[k+1][j-1];
       
              index[i][j]=k;
              // cout<<"("<<k<<","<<n-1<<")"<<endl;
              if(i==0 && j==n-1){
          		tmpEdge.str = 0;
          		tmpEdge.end = k-1;
          		s.push_back(tmpEdge);

          		tmpEdge.str = k+1;
          		tmpEdge.end = n-1;
          		s.push_back(tmpEdge);
 	               
 	            if(info[j].isStr){
 	            	tmpEdge.str = n-1;
          			tmpEdge.end = k;
 	            }
 	            else{
 	            	tmpEdge.str = k;
          			tmpEdge.end = n-1;
 	            }
 	            
          		e.push_back(tmpEdge);
              
            //cout<<">"<<answer[i][j]<<" ";
          }
      }
	else{	
			index[i][j]=-1;
			answer[i][j] = answer[i][j-1];
			if(i==0 && j==n-1){
          		tmpEdge.str = 0;
          		tmpEdge.end = n-1;
          		s.push_back(tmpEdge);
          	}
           /* if(info[j-1]!=-1){
                cout<<"("<<i<<","<<j<<")->";
                cout<<"("<<i<<","<<j-1<<")"<<endl;
                cout<<"*"<<info[109]<<endl;                
            } */                          
            
            
            
             //cout<<"- "<<answer[i][j]<<" ";
		}
                    
                      
           
				//}
				
			}
      //cout<<endl;
		}
	
	
}


int main(){
	cin>>n;
	index = new int*[n];
	for(int i=0;i<n;i++){
		index[i] = new int[n];
	}
	answer = new int*[n];
	for(int i=0;i<n;i++){
		answer[i] = new int[n];
	}
	
	for(int k=0;k<n;k++){
		info[k].no=-1;
	}


	int str, en;
	while(1){
     str=-1; en=-1;
		cin>>str>>en;
   
   if(str==0 && en==-1){
			break;
		}

		info[str].no=en;
		info[str].isStr=true;
		info[en].no=str;
		info[en].isStr=false;
		
		
	}

	FindMaxPlanarSubset();
	edge Edge;
	while(s.size()!=0){
   	Edge=s.front();
   	if(Edge.end<=Edge.str+1){
   		s.erase(s.begin());
   	}
   	else{
   		s.erase(s.begin());
   		int k=index[Edge.str][Edge.end];
   	if(k>=0){
   		tmpEdge.str = Edge.str;
        tmpEdge.end = k-1;
        s.push_back(tmpEdge);

        tmpEdge.str = k+1;
        tmpEdge.end = Edge.end-1;
        s.push_back(tmpEdge);

        if(info[k].isStr){
        	tmpEdge.str = k;
        	tmpEdge.end = Edge.end;
        }
        else{
        	tmpEdge.str = Edge.end;
        	tmpEdge.end = k;
        }
        
        e.push_back(tmpEdge);
   	}
   	else{
   		tmpEdge.str = Edge.str;
        tmpEdge.end = Edge.end-1;
        s.push_back(tmpEdge);
   	}
   	}
 }

 sort(e.begin(),e.end(),less_than_key());
 cout<<answer[0][n-1]<<endl;
 for(int i=0;i<e.size();i++){

   cout<<e[i].str<<" "<<e[i].end<<endl;
 }
 
 for(int i =0;i<n;i++){
 	delete [] index[i];
 }
 delete [] index;

 for(int i =0;i<n;i++){
 	delete [] answer[i];
 }
 delete [] answer;

}

