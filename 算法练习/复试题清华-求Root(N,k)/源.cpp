#include<iostream>
#include<cmath>
using namespace std;

int Aggregate(long long x, long long y,int d) {  //统计十进制的source在d进制下各位的和
		long long sum = 1;
	    while (y) {
		if (y & 1) 
			sum = sum * x % d;
		x = x * x % d;
		y >>= 1;
	}
	return sum;
}


int main() {
	int x, y, k;
	int result;
	long long source;
	while (cin >> x >> y >> k) {
		k--;
		result = Aggregate(x, y,k );
		cout << (result==0?k:result) << endl;
	}
	return 0;
}