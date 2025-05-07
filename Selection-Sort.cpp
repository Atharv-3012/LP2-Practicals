#include<iostream>
#define Max 100
using namespace std;
int main(){
    int arr[Max];
    int n=0;
    int temp;
    cout<<"Enter number of elements in array: ";
    cin>>n;
    cout<<"Enter those "<<n<<" numbers : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n-1;i++){
    int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
    cout<<"Sorted Array:";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
        
    }
    return 0;
}

// Enter number of elements in array: 3
// Enter those 3 numbers in a row separated by space :10
// 30
// 5
// sorted array:5 10 30 
