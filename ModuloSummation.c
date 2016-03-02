long long int modu(long long int sa,long long int sw,long long int m)
{
	long long int ret;
	if(sw==0)
		return 0;
	if(sw==1)
		return sa;
	if(sw%2==0)
	{
		ret=modu(sa,sw/2,m);
		ret+=ret;
		return (ret%m);
	}
	else
	{
		ret=modu(sa,sw-1,m);
		ret+=sa;
		return (ret%m);
	}		
}
