//题目描述
//Given N rational numbers in the form "numerator/denominator", you are supposed to calculate their sum.

//输入描述:
//Each input file contains one test case. Each case starts with a positive integer N (<=100), 
//followed in the next line N rational numbers "a1/b1 a2/b2 ..." where all the numerators and 
//denominators are in the range of "long int".  If there is a negative number, then the sign 
//must appear in front of the numerator.

//输出描述:
//For each test case, output the sum in the simplest form "integer numerator/denominator" where "integer" is 
//the integer part of the sum, "numerator" < "denominator", and the numerator and the denominator have no 【common factor】(公因子).  
//You must output only the fractional part if the integer part is 0.

#include<cstdio>  
#include<iostream>  
#include<cmath>  
typedef long long ll;  
ll gcd(ll a,ll b){  
    for(int t;t=b;b=a%b,a=t);  
    return a;  
}  
ll aa,bb; 
 
int main(){  
    ll a,b,g;  
    int n;  
    aa=0,bb=1;  
    scanf("%d",&n);  
    while(n--){  
        scanf("%lld/%lld",&a,&b);  
        aa=aa*b+bb*a;  
        bb=bb*b;  
        g=gcd(labs(aa),labs(bb));  
        aa/=g;  
        bb/=g;   
    }  
    
    if(aa==0){  
        printf("0");  
	} 
	else{  
        if(aa/bb && aa%bb)printf("%10d %d/%d\n",aa/bb,aa%bb,bb);  
        else if(aa/bb){  
                printf("%lld\n",aa/bb);  
        }  
        else if(aa%bb){  
            printf("%lld/%lld\n",aa,bb);  
        }  
    }  
    return  0;  
} 
