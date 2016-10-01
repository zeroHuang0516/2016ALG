#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include "parser.h"
using namespace std;



class Word{
    public:
      void setContent(string con ){
          content=con;
      }
      void setOrder(int num){
          order=num;
      }

      string getContent(){
          return content;
      }
      int getOrder(){
          return order;
      }

    private:
        string content;
        int order;
};

Word *arr;
int size;

/************************************************************************/
//insertion sort
/************************************************************************/
void InsertionSort(int size){
    int j;
    Word key;
	   for(int i=1;i<size;i++){
 	        key.setContent(arr[i].getContent());
          key.setOrder(arr[i].getOrder());
		      j=i-1;

		      while(j>-1 && arr[j].getContent()>key.getContent()){
              arr[j+1]=arr[j];
			        j--;
		      }

		      arr[j+1]=key;
	   }

}

/************************************************************************/
//Merge sort
/************************************************************************/

void Merge(int l,int m, int r){
    Word* tmp=new Word[size];
    int i=l;
    int j=m+1;
    int k=l;
    while(i<=m && j<=r){
        if(arr[i].getContent()<=arr[j].getContent()){
              tmp[k]=arr[i];
              i++;
        }
        else{
              tmp[k]=arr[j];
              j++;
        }
        k++;
    }

    if(i>m){
        for(int t=j;t<=r;t++){
            tmp[k]=arr[t];
            k++;
        }
    }
    else{
        for(int u=i;u<=m;u++){
            tmp[k]=arr[u];
            k++;
        }
    }

    for(int h=l;h<=r;h++){
          arr[h]=tmp[h];
    }
}

void MergeSort(int l, int r){
    if (l<r){
        int m=(l+r)/2;
        MergeSort(l,m);
        MergeSort(m+1,r);
        Merge(l,m,r);
    }
    
}

/************************************************************************/
//quick sort
/************************************************************************/


void swap(Word& a, Word& b){
    string con=a.getContent();
    int num=a.getOrder();
    a.setContent(b.getContent());
    a.setOrder(b.getOrder());
    b.setContent(con);
    b.setOrder(num);
}

int partition(int l,int r,int pIdx){
    string pValue=arr[pIdx].getContent();
    swap(arr[pIdx],arr[r]);
    int pNewIdx=l;
    for(int i=l;i<=pIdx-1;i++){
        if(arr[i].getContent()<=pValue){
            swap(arr[pNewIdx],arr[i]);
            pNewIdx++;
        }
    }
    swap(arr[pNewIdx],arr[r]);
    return pNewIdx;
}

void QuickSort(int l,int r){
    Word pivot;
    int pNewIdx;
    int pIdx=r;
    if(r>l){
        pNewIdx=partition(l,r,pIdx);
        QuickSort(l,pNewIdx-1);
        QuickSort(pNewIdx+1,r);
    }

}


/************************************************************************/
//heap sort
/************************************************************************/


class minHeap{
private:
    vector<Word>words;
    int heapSize;
    int getLeftChIndex(int nodeId){
        return 2*nodeId+1;
    }
    int getRightChIndex(int nodeId){
        return 2*nodeId+2;
    }
    int getParentIndex(int nodeId){
        return (nodeId-1)/2;
    }
    void BubbleDown(int id);
    void BubbleUp(int id);
    void Heapify();
public:
    minHeap(){heapSize=0;};
    int size()const;
    bool empty() const;
    void insert(const Word& word);
    Word& getMin();
    void removeMin();
    void removeNode(Word& word);
    void changeShare(int number);
};


int minHeap::size()const{
    return heapSize;
}
bool minHeap::empty()const{
    return (heapSize==0);
}
Word& minHeap::getMin(){
    return words[0];
}
void minHeap::insert(const Word& word){
    heapSize++;
    words.push_back(word);
    BubbleUp(heapSize-1);
}
void minHeap::BubbleUp(int id){
    int parentIndex;
    Word temp;
    if(id!=0){
        parentIndex=getParentIndex(id);
        if(words[parentIndex].getContent()>=words[id].getContent()){
            temp=words[parentIndex];
            words[parentIndex]=words[id];
            words[id]=temp;
            BubbleUp(parentIndex);
        }
    }
}
void minHeap::BubbleDown(int id){
    int lchId,rchId,minId;
    Word temp;
    lchId=getLeftChIndex(id);
    rchId=getRightChIndex(id);
    if(rchId>=heapSize){
        if(lchId>=heapSize){
            return;
        }
        else{
            minId=lchId;
        }
    }
    else{
        if(words[lchId].getContent()<words[rchId].getContent()){
            minId=lchId;
        }
        else{
            minId=rchId;
        }
    }
    if(words[id].getContent()>words[minId].getContent()){
        temp=words[id];
        words[id]=words[minId];
        words[minId]=temp;
        BubbleDown(minId);
    }
}
void minHeap::Heapify(){
    for(int i=heapSize-1;i>=0;--i){
        BubbleDown(i);
    }
}
void minHeap::removeMin(){
    if(empty()){
        return;
    }
    else{
        words[0]=words[heapSize-1];
        words.pop_back();
        heapSize--;
        if (heapSize > 0)
            BubbleDown(0);
    }
}

void minHeap::removeNode(Word& word){
    int parent;
    for(int i=0;i<heapSize;i++){
        if(words[i].getContent()==word.getContent()){
            parent=getParentIndex(i);
            words[i]=words[heapSize-1];
            words.pop_back();
            heapSize--;
            if((i==0) || (words[parent].getContent()<words[i].getContent())){
              BubbleDown(i);
            }
            else{
                BubbleUp(i);
            }
            break;
        }
    }
}


void HeapSort(){
    minHeap wordList;
    for(int i=0;i<size;i++){
		    wordList.insert(arr[i]);
    }
    for(int j=0;j<size;j++){
        cout<<wordList.getMin().getContent()<<" "<<wordList.getMin().getOrder()<<endl;
        wordList.removeMin();
    }
}










int main( int argc, char** argv )
{
 
 	  AlgParser parser;
 	  AlgTimer timer;
 	  parser.Parse( "case1.dat" );
    size=parser.QueryTotalStringCount();
    arr=new Word[size];
    int orderNum;
    
    
    for(int t=0;t<parser.QueryTotalStringCount();t++){
        arr[t].setContent(parser.QueryString(t));
        orderNum+=parser.QueryNumOfLine(parser.QueryLineNumber(t)-1);
        orderNum+=parser.QueryWordOrder(t);
        arr[t].setOrder(orderNum);
        orderNum=0;
    }
    
    timer.Begin();
    cout<<"word count: "<<size<<endl;

 	  //InsertionSort(size);
    //MergeSort(0,size-1);
    //QuickSort(0,size-1);
    HeapSort();
    /*
    for(int t=0;t<size;t++){
          cout<<arr[t].getContent()<<" "<<arr[t].getOrder()<<endl;
     }*/
    
    cout << "The execution spends " << timer.End() << " seconds" << endl;

    delete[] arr;
    return 1;
} 