long long int josephus(long long int n,int k)
{
  if(n==1)
    return 1;
  else
    return (josephus(n-1,k)+k-1)%n+1;	//adjustment is made here
}
//if k==2,just observe the pattern from  n=0 t0 15
