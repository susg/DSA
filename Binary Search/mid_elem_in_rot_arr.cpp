/*
Given an array in which elements are first increasing and then decreasing. 
Find the maximum element in the array.
1 4 7 9 6 5 2
      ^
*/

int find_max_elem(int ar[], int l, int h, int n) {
    
    if(l > h)   return max(ar[0], ar[n-1]);
    if(l == h)  return ar[l];

    int mid = (l+h)/2;
    if(mid-1 >= 0 && mid+1 >= n-1) 
    {
        if(ar[mid] > ar[mid-1] && ar[mid > ar[mid+1]])
            return ar[mid];
        else if(ar[mid] > ar[mid-1] && ar[mid] < ar[mid+1])
            return find_max_elem(ar, mid+1, h,n);
        else if(ar[mid] < ar[mid-1] && ar[mid] > ar[mid+1])
            return find_max_elem(ar, l, mid-1, n);
    } 
    else   return max(ar[0], ar[n-1]);
}

int countRotations(int arr[], int low, int high) 
{ 
    // This condition is needed to handle the case 
    // when array is not rotated at all 
    if (high < low) 
        return 0; 
  
    // If there is only one element left 
    if (high == low) 
        return low; 
  
    // Find mid 
    int mid = low + (high - low)/2; /*(low + high)/2;*/
  
    // Check if element (mid+1) is minimum element. 
    // Consider the cases like {3, 4, 5, 1, 2} 
    if (mid < high && arr[mid+1] < arr[mid]) 
       return (mid+1); 
  
    // Check if mid itself is minimum element 
    if (mid > low && arr[mid] < arr[mid - 1]) 
       return mid; 
  
    // Decide whether we need to go to left half or 
    // right half 
    if (arr[high] > arr[mid]) 
       return countRotations(arr, low, mid-1); 
  
    return countRotations(arr, mid+1, high); 
} 

int findMaximum(int arr[], int low, int high) 
{ 
  
   /* Base Case: Only one element is present in arr[low..high]*/
   if (low == high) 
     return arr[low]; 
  
   /* If there are two elements and first is greater then 
      the first element is maximum */
   if ((high == low + 1) && arr[low] >= arr[high]) 
      return arr[low]; 
  
   /* If there are two elements and second is greater then 
      the second element is maximum */
   if ((high == low + 1) && arr[low] < arr[high]) 
      return arr[high]; 
  
   int mid = (low + high)/2;   /*low + (high - low)/2;*/
  
   /* If we reach a point where arr[mid] is greater than both of 
     its adjacent elements arr[mid-1] and arr[mid+1], then arr[mid] 
     is the maximum element*/
   if ( arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1]) 
      return arr[mid]; 
  
   /* If arr[mid] is greater than the next element and smaller than the previous  
    element then maximum lies on left side of mid */
   if (arr[mid] > arr[mid + 1] && arr[mid] < arr[mid - 1]) 
     return findMaximum(arr, low, mid-1); 
   else // when arr[mid] is greater than arr[mid-1] and smaller than arr[mid+1] 
     return findMaximum(arr, mid + 1, high); 
} 