#include <iostream>
#include <math.h>
#include <ctime>
#include <stdlib.h>
using namespace std;

const unsigned long maxshort = 65536L;  
const unsigned long multiplier = 1194211693L;  
const unsigned long adder = 12345L;  
class RandomNumber  
{  
private:    
    unsigned long randSeed;  
public:  
    RandomNumber(unsigned long s=0); 
    unsigned short Random(unsigned long n);  
    double fRandom(void); 
};  
  
RandomNumber::RandomNumber(unsigned long s) 
{  
    if(s==0)  
        randSeed = time(0);  
    else  
        randSeed = s;  
}  
unsigned short RandomNumber::Random(unsigned long n)  
{  
    randSeed=multiplier*randSeed+adder;  
    return (unsigned short)((randSeed>>16) % n);  
}  
double RandomNumber::fRandom(void) 
{  
    return Random(maxshort) / double(maxshort);  
}


class Queen{
	friend bool nQueen(int,int);
	private:
		bool Place(int k);
		bool QueensLV(int a);
		bool Backtrack(int t); 
		int n,
			*x,*y,sv;
}; 

bool Queen::Place(int k){
	for (int j=1;j<k;j++)
		if((abs(k-j) == abs(x[j]-x[k])) || (x[j] == x[k]))
			return false;
	return true;
}

bool Queen::Backtrack(int t){
	if(t>n){
		for(int i=1;i<=n;i++)
		{
			y[i]=x[i];
		}
		return true;
	}
	else{
		for(int i=1;i<=n;i++){
			x[t]=i;
			if(Place(t) && Backtrack(t+1))
				return true;
		}
	}
	return false;
}



bool Queen::QueensLV(int a){
	RandomNumber rnd;
	int k=1;
	int count=1;
	while((k<=a)&&(count>0)){
		count=0;
		for(int i=1;i<=n;i++){
			x[k]=i;
			if(Place(k))
				y[count++]=i;
		}
		if(count>0)
			x[k++]==y[rnd.Random(count)];
	}
	return (count>0);
}

bool nQueen(int n,int sv){
	Queen X;
	X.n=n;
	int *p=new int[n+1];
	int *q=new int[n+1];
	for(int i=0;i<=n;i++){
		p[i]=0;
		q[i]=0;
	}
	X.x=p;
	X.x=q;
	int stop=sv;
	if(n>15)
		stop=n-15;
	bool found=false;
	while(!X.QueensLV(stop))  ;
	if(X.Backtrack(stop+1)){
		for(int i=1;i<=n;i++)
			cout<<p[i]<<"";
		found=true;
	}
	cout<<endl;
	delete[] p;
	delete[] q;
	return found;
}
int main(){
 	int n,sv;
    cout<<"����ʺ����n �� stopVrgasֵ"<<endl; 
	while(cin>>n>>sv){
    
       if(!nQueen(n,sv))  
       {  
           cout<<"No Answer"<<endl;  
       }  
		
		
	} 
    return 0;
}
