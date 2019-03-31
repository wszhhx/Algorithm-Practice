//描述：给定N个三维坐标点(包含整形x,y,z)，找到位于同一条直线上点的最大个数
//思路：先固定一点，然后判断其他所有点与其构成的直线斜率是否相同，相同的即视为共线并记录在map中以供后期定其他点的判断累加
#include<iostream>
#include<vector>
#include<map>
using namespace std;

typedef struct vector3{
	int x;
	int y;
	int z;
	
}Vector3;

int gcd(int a, int b) {
	int t;
	while (b != 0) {
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int gcd3d(int a, int b, int c) {
	return gcd(gcd(a, b), c);
}

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	vector<Vector3> points;

	Vector3 temp;
	int n;
	int maxNum = 0;
	int cnt, overlap;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> temp.x >> temp.y >> temp.z;
		points.push_back(temp);
	}
	for (int i = 0; i < points.size(); ++i) {
		cnt = 0;
		overlap = 0;
		map<pair<pair<int,int>, int>,int> lines;
		for (int j = i + 1; j < points.size(); ++j) {
			int dx = points[j].x - points[i].x;
			int dy = points[j].y - points[i].y;
			int dz = points[j].z - points[i].z;
			if (dx == 0 && dy == 0 && dz == 0) {
				overlap++;
				continue;
			}
			int gys = gcd3d(dx, dy, dz);
			dx /= gys;
			dy /= gys;
			dz /= gys;
			temp.x = dx;
			temp.y = dy;
			temp.z = dz;
			cnt = max(cnt, ++lines[pair<pair<int,int>,int>(pair<int,int>(dx,dy),dz)]);	//得出的是当前过点i的直线中计数最大的
		}
		maxNum = max(maxNum, cnt + overlap + 1);	

	}
	cout << maxNum << endl;
	system("pause");
	return 0;
}