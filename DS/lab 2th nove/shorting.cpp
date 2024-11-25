#include<bits/stdc++.h>
using namespace std;
void bubble(int *arr,int n){
    int i;
    bool swaphuakya=false;
    for( i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j+1]<arr[j]){
                swap(arr[j+1],arr[j]);
                swaphuakya=true;
            }
        }
        if(!swaphuakya){
            return;
        }
    }

}
void select(int *arr,int n){
    bool sorted=false;
    for(int i=0;i<n;i++){
        sorted=true;
        int m=i;
        for(int j=i+1;j<n;j++){
            if(arr[m]>arr[j]){
                m=j;
                sorted=false;
            }
        }
        if(i!=m){
            swap(arr[i],arr[m]);
            sorted=false;
        }
        if(sorted){
            
        }
    }
}
void insert(int *arr,int n){
    for(int i=0;i<n;i++){
        int j=i-1,key=arr[i];
        while(j>=0 and arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
int part(int *arr,int l,int h){
    int i=l-1,p=arr[h];
    for(int j=l;j<h;j++){
        if(arr[j]<p){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[h]);
    return i+1;
}
void quick(int *arr,int l,int h){
    if(l<h){
        int p=part(arr,l,h);
        quick(arr,l,p-1);
        quick(arr,p+1,h);
    }
}
void merge(int *arr,int l,int m,int h){
    int n1=(m-l+1),n2=h-m;
    int left[n1],right[n2];
    int i=0,j=0,k=l;
    for(int i=0;i<n1;i++){
        left[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++){
        right[i]=arr[i+1+m];
    }
    while(i<n1 and j<n2){
        if(left[i]<right[j]){
            arr[k]=left[i];
            i++;
        }else{
            arr[k]=right[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k++]=left[i++];
    }
    while(j<n2){
        arr[k++]=right[j++];
    }
}
void mergesort(int *arr,int l,int h){
    if(l<h){
        int m=(l+h)>>1;
        mergesort(arr,l,m);
        mergesort(arr,m+1,h);
        merge(arr,l,m,h);
    }
}
int main(){
    int arr[]={2,142,1,42,12,512,7},n=7;
    bubble(arr,n);
    // select(arr,n);
    // insert(arr,n);
    // quick(arr,0,n-1);
    // mergesort(arr,0,n);
    for(int i:arr){
        cout<<i<<"\t";
    }
}