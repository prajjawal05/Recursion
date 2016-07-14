/*An inversion (i, j) could be in the same half (left or right half), or i could be in the left half and j could be in the right half (i cannot be in the right half because we have the constraint i < j). However, by the inductive hypothesis, the number of inversions within the left and right half of the array would be returned by the respective recursive calls to each half of the array, so we only need to count the number of inversions across the two halves (i in left and j in right).

How do we count the number of inversions across left and right array? In the merge step of the merge sort, we are given a two sorted array (left and right). For each element left[i] in the left array we want to know how many element right[j] in the right array is strictly smaller than left[i]. Note that when we insert  left[i] into the merged array, we know that every element to the left of j is less than left[i] (since they are inserted to merged array before left[i]). So, each time left[i] is inserted into the merged array increment the counter by j. This will be the number of inversions.*/

#include<bits/stdc++.h>
using namespace std;

//int cnt;

long long int merge(long long int a[],long long int l,long long int m,long long int r)
{
	long long int n1,n2,i,j,k,cnt=0;
	n1=m+1-l;
	n2=r-m;							//be careful with this
	int a1[n1], a2[n2];
	for(i=0;i<n1;i++)
		a1[i]=a[l+i];	
	for(i=0;i<n2;i++)
		a2[i]=a[m+1+i];					//BE CAREFUL WITH THIS AS WELL
	i=0,j=0,k=l;						//Rememnber them
	while(i<n1 && j<n2)
	{
		if(a1[i]<=a2[j])
		{
			a[k]=a1[i];
			i++;
			cnt+=j;                     //previously of these numbers, all numbers were small(INDEXING FROM 0)
			
		}
		else
		{
			a[k]=a2[j];
			//cnt+=j;                     //recursion
			j++;
			
		}
		k++;
	}
	cnt+=j*(n1-i);                      //JITNA ELEMENTS BACHA HAI
	while(i<n1)
	{
		a[k]=a1[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		a[k]=a2[j];
		j++;
		k++;
	}
	//printf("%d\n",cnt);
	return cnt;
}

long long int mergesort(long long int a[],long long int l,long long int r)
{
    long long int m,cnt=0;
	if(l<r){
	    m=l+(r-l)/2;
		cnt=mergesort(a,l,m);
		cnt+=mergesort(a,m+1,r);
		cnt+=merge(a,l,m,r);
	}
	return cnt;
}

int main()
{
    long long int n,p;
  
    scanf("%lld",&n);
    long long int a[n];
    for(long long int i=0;i<n;i++)
    	scanf("%lld",&a[i]);
        //cnt=0;    
    p=mergesort(a,0,n-1);
    printf("%lld\n",p);
    
    return 0;
}
