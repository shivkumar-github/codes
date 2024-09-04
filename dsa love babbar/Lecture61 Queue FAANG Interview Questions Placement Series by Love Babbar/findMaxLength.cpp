#include<bits/stdc++.h>
using namespace std;
int longest(int arr[], int n, int key){
int length=0;
int sum=0;
int j=0;
for(int i=0;i<n;i++){
    sum=sum+arr[i];
    if(sum==key){
        length=max(length,(i-j+1));
         i=j;
        sum=0;
        j++;
    }
    else if(sum>key){
        i=j;
        sum=0;
        j++;
    }
}
return length;
}
int main(){
int arr[]={1,2,3,1,1,1,1,4,2,3};
cout<<"The length of largest subarray is: "<<longest(arr,10,6);
return 0;
}