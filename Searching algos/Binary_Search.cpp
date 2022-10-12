// Base Condition
//***** ARRAY SHOULD BE SORTED *********

#include<bits/stdc++.h>
using namespace std;

int BinarySearch(int arr[], int key, int size){
    int left = 0;
    int right = size-1;
    /*for large array size, mid can cross the integer range, so we must optimize it
    (left + right)/2 == (left + ((right-left)/2))
    
    */
    int mid = left + ((right-left)/2);

    while(left<=right){
        if(arr[mid] == key){
            return mid;
        }else{
            if(arr[mid]<key){
                left = mid+1;
            }else{
                right = mid-1;
            }
            mid = left + ((right-left)/2);
        }
    }
    return mid;
}

bool BinarySearchRecur(int arr[],int s, int e,int key){
    int mid = s + (e - s)/2;
    if(s>e){
        return false;
    }
    if(arr[mid] == key){
        return true;
    }
    if(arr[mid]<key){
        return BinarySearchRecur(arr,mid+1,e,key);
    }
    else{
        return BinarySearchRecur(arr,s,mid-1,key);
    }
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,1};
    int size = sizeof(arr)/sizeof(int);
    if(size == 0){
        cout<<"Array is empty";
        return 0;
    }

    cout<<"Input the element you are searching for ";
    int key;
    cin>>key;
    // int index = BinarySearch(arr,key,size);
    // if(index!=-1){
    //     cout<<"Key is present in the array at position "<<index+1<<endl;
    // }else{
    //     cout<<"Key is not present in the array"<<endl;
    // }
    bool ans = BinarySearchRecur(arr,0,size-1,key);
    if(ans){
        cout<<"Key is Present"<<endl;
    }
    else{
        cout<<"Key not Found"<<endl;
    }
    return 0;
}