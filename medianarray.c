/*Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.*/
 
    #include<stdio.h>
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    double median;
    int mid1,mid2,mid3;
    int i=0,j=0;
    int x=nums1Size+nums2Size;
    int c[x];
    for(i=0;i<nums1Size;i++) //merging two arrays
    {
       c[i]=nums1[i];
    }
    for(i=0,j=nums1Size;j<x && i<nums2Size;i++,j++) 
    {
        c[j]=nums2[i];
    }
     for (int m = 0; m <x; m++) //Sorting the array
  {
    int temp;
    for (int n = m + 1; n < x; n++) {
      if (c[m] > c[n]) {
        temp = c[m];
        c[m] = c[n];
        c[n] = temp;
      }
    }
  }

    if((x%2)!=0)
    {
        mid1=(x/2);
        median=c[mid1];
        return median;
    }
else
{
    mid2=(x/2);
    mid3=(x/2)-1;
    median=(double)(c[mid2]+c[mid3])/2;
    return median;
}
    
}
int main(){
    int nums1[100],nums2[100];
    int n1,n2;
    printf("enter the number of elements of the first and second array\n");
    scanf("%d%d",&n1,&n2);
    printf("enter the elements of first array\n");
    for(int i=0;i<n1;i++){
        scanf("%d",&nums1[i]);
    }
    printf("enter the elements of first array\n");
    for(int i=0;i<n2;i++){
        scanf("%d",&nums2[i]);
    }
    printf("the two arrays are :\n ");
    printf("[");
    for(int i=0;i<n1;i++){
        printf("%d",nums1[i]);
    }
    printf("]\n");
    printf("[");
    for(int i=0;i<n2;i++){
        printf("%d",nums2[i]);
    }
    printf("]\n");

  double result = findMedianSortedArrays(nums1, n1, nums2, n2);
  printf("%lf",result);
    



}
