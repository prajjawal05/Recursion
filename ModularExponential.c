int power(int a,int b)
{
	int mod=11;
	if(b==0)
		return 1;
	int x=power(a,b/2);
	if(b%2==0)
		return ((x%mod)*(x%mod))%mod;//if power(a,b/2)*power(a,b/2) then more time;
	else
		return ((((a%mod)*(x%mod))%mod)*(x%mod))%mod;//log b
}
