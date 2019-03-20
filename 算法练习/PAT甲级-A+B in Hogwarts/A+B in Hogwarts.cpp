//If you are a fan of Harry Potter, you would know the world of magic has its own currency system -- as Hagrid explained it to Harry, 
//"Seventeen silver Sickles to a Galleon and twenty-nine Knuts to a Sickle, it's easy enough."  Your job is to write a program to compute
// A+B where A and B are given in the standard form of "Galleon.Sickle.Knut" (Galleon is an integer in [0, 107], Sickle is an integer in 
//[0, 17), and Knut is an integer in [0, 29)).
//如果你是哈利波特系列的粉丝，你或许知道哈利波特的魔法世界拥有自己的货币体系 ，就像鲁伯·海格向哈利波特说明的那样：
// 17 Sickles    -> 1Galleon
// 29 Knuts      -> 1Sickle
//你要编一个程序，要求计算以Galleon.Sickle.Knut为格式的加法运算（Galleon是0到10000000之间的整数，Sickle是0到17之间，Knut是0到29之间） 

//输入描述：
//每次输入包含一个用例，一个用例由两个需要相加的，格式为A.B.C的因子构成，两个因子由空格隔开,如：123.12.4 100.13.23 

//输出描述：
// 要求以同样的格式输出
#include<iostream> 
int main(){
	int a_g,a_s,a_k;
	int b_g,b_s,b_k;
	int c_g,c_s,c_k;
	scanf("%d.%d.%d %d.%d.%d",&a_g,&a_s,&a_k,&b_g,&b_s,&b_k);
	c_g = a_g + b_g + (a_s + b_s)/17;
	c_s = (a_s + b_s)%17 + (a_k + b_k)/29;
	c_k = (a_k + b_k)%29;
	printf("%d.%d.%d",c_g,c_s,c_k);
	exit(0);
}
