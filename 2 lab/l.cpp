#include <bits/stdc++.h>
using namespace std;
 
int maxSubArraySum(int a[], int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0;
 
    for (int i = 0; i < size; i++) {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}
 
// Driver Code
int main()
{
    int size; cin>>size;
    int arr[size];
    for (int i = 0;i < size;i++){
        cin>>arr[i];
    }
    int max_sum = maxSubArraySum(arr, size);
    cout<<max_sum;
}