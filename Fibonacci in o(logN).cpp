//array exponential
//some help from GEEKSFORGEEKS
#include<bits/stdc++.h>
using namespace std;
multiply(int fib[2][2],int f[2][2])
{
	int x=fib[0][0]*f[0][0]+fib[0][1]*f[1][0];
	int y=fib[0][0]*f[0][1]+fib[0][1]*f[1][1];
	int z=fib[1][0]*f[0][0]+fib[1][1]*f[1][0];
	int a=fib[1][0]*f[0][1]+fib[1][1]*f[1][1];
	fib[0][0]=x;
	fib[0][1]=y;
	fib[1][0]=z;
	fib[1][1]=a;
}
void powe(int fib[2][2],int n)
{
	if(n==1||n==0)
		return;
	int f[2][2]={{1,1},{1,0}};	
	powe(fib,n/2);
	multiply(fib,fib);
	if(n%2!=0)
		multiply(fib,f);	
}
int fibo(int n)
{
	int fib[2][2]={{1,1},{1,0}};
	if(n==0)
		return 0;
	powe(fib,n-1);
	return fib[0][0];	
}
int main()
{
	int x;
	cin>>x;
	int y=fibo(x);
	cout<<y;
}
