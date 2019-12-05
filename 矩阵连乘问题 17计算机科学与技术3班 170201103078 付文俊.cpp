#include <iostream>
using namespace std;

const int N=4;
void MatrixChain(int *p,int r,int m[N][N],int s[N][N])
{
	int n=r-1;
	for(int i=1;i<=n;i++)
		m[i][i]=0;
	for(int r=2;r<=n;r++)
	{
		for(int i=1;i<=n-r+1;i++)
		{
			int j=i+r-1;
			m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];
			s[i][j]=i;
			for(int k=i+1;k<j;k++)
			{
				int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(t<m[i][j])
				{
					m[i][j]=t;
					s[i][j]=k;
				}
			}
		}
	}
	cout<<m[1][N-1]<<endl;
}

void Traceback(int i,int j,int s[N][N])
{

	if(i==j)
    {
        cout<<"A"<<i;
    }
    else
    {
        cout<<"(";
        Traceback(i,s[i][j],s);
        Traceback(s[i][j]+1,j,s);
        cout<<")";
    }
}

int main()
{
	int p[N]={10,100,5,50};//p[0]p[1]是一个矩阵，p[1]p[2],又是一个矩阵 
    int m[N][N],s[N][N];
    MatrixChain(p,N,m,s);
    Traceback(1,N-1,s);
    return 0;
}

