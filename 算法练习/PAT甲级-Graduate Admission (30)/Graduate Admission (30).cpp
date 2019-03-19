/*
题目描述：据悉，2013，浙江省约有100所研究生院准备进行40000多项申请。若你能写一个自动化入学程序，那么将提供很大的帮助。
         每个申请需要提供两个东西：1.统考成绩排名GE。2.复试成绩排名GI。最终排名为：(GE + GI) / 2。入学规则为：
		 1.申请将根据每个学生的最终排名进行排序，并从第一名往下筛选能够入学的申请。
		 2.若两个人排名一致，则更具他们的统考排名GE决定他们的先后，若排名仍然一致，他们的最终排名一致。
		 3.每位申请者有K种选择，录取根据他的选择进行：若根据排名表，某人应该被录取并且他的最喜欢的学校名额没有超过，那么他将会被这个学校录取，
		   否则他的其他志愿将依次遵循上述条件一个个筛选知道能被某志愿录取，若某人无法满足所有志愿中学校的排名要求，则无法被录取。
		 4.若有相同的排名且相同排名的申请这刚好申请了同一所学校,那么这所学校必须同意他们几个相同排名的申请（哪怕这样会导致招生人数大于配额）。

输入描述：每次输入包含一个用例.每个用例的第一行包含三个正整数：N (<=40000)(申请人总数); M (<=100)招生学校总数; K (<=5)每个人能填报的志愿数
         第二行给出M个正整数，每个整数用空格隔开，第i个数为第i所学校的招生名额。
		 接下来给出N行，每行包括K + 2个正整数，用空格隔开。相对第i行头两个数为第i个学生的统考排名GE与复试排名GI，接下来的K个整数为这个人填报的
		 志愿（第一志愿、第二志愿。。。。）。
		 为了简化，我们假设学校从0到M-1编号，学生从0到N-1编号。

输出描述：对于每个例子，你需要输出所有学校的招生结果。每个学校的结果占一行，每行输出招取学生的编号，且编号从小到大排序，学校也一样。若某个学校没有招
         任何学生，则用空行代替。每行最末尾不能有额外的空格。

*/
#include<iostream>
#include<cstdlib>
#include<algorithm>

#define MAXN 40000
#define MAXM 100
#define MAXK 5
using namespace std;
int SchoolsList[MAXM][MAXN + 2];     ///[][0]为招生人数   [][1 ~ MAXN]为录取学生编号。 [][MAXN+1]为已录取人数  -1为空
int ApplicantsList[MAXN][MAXK + 4];  ///[][3 ~ MAXK+2]为志愿  [][0]为最终排名  [][1]为GE  [][2]为GI  [][MAXK+3]为编号
int *Applicants[MAXN];               ///指针数组，方便学生进行排序
int M, N, K;
//Applicants的下标为处理顺序，无实际意义
//ApplicantsList的下标为学生原编号，对后期查找有帮助

bool MySort(int *a, int *b) {
	return (a[1] + a[2] > b[1] + b[2] ||(a[1] + a[2] == b[1] + b[2] && a[1] > b[1]) );    //根据总GE+GI与GE进行由大到小排名
}

void GenerateRank() { //给学生进行最终排名，以备后面按顺序决定录取
	sort(Applicants, Applicants + N,MySort);
	int Rank = 1;
	int *temp;                     //用来交换指针数组成员，逻辑上等同于在Applicants中交换两行元素
	Applicants[0][0] = Rank;
	for (int i = 1; i < N; ++i) {
		if (Applicants[i][1] == Applicants[i - 1][1] && Applicants[i][1] + Applicants[i][2] == Applicants[i-1][1] + Applicants[i-1][2]) {
			Applicants[i][0] = Applicants[i - 1][0];
		}
		else {
			Applicants[i][0] = ++Rank;
		}
	}
	return;
}

bool Admit(int stu_index,int sch_index) { //判断是否允许入学，
	if (SchoolsList[sch_index][MAXN + 1] < SchoolsList[sch_index][0])
		return true;
	else {
		if (Applicants[stu_index][0] == ApplicantsList[ SchoolsList[sch_index][ SchoolsList[sch_index][MAXN + 1] ] ][0]) { 
			return true;
		}
	}
	return false;
}

void GenerateResult() {
	for (int i = 0; i < N; ++i) {              //根据排名由高到第依次判断入学许可
		for (int j = 3; j < 3 + K; ++j) {
			if (Admit(i, Applicants[i][j])) {
				SchoolsList[Applicants[i][j]][++SchoolsList[Applicants[i][j]][MAXN + 1]] = Applicants[i][K + 3];
				break;
			}
		}
	}
	for (int i = 0; i < M; ++i) {            //输出结果
		if (SchoolsList[i][MAXN + 1] == 0)
			cout << endl;
		else {
			sort(SchoolsList[i] + 1, SchoolsList[i] + SchoolsList[i][MAXN+1]+1);
			for (int j = 1; j <= SchoolsList[i][MAXN + 1]; ++j) {
				cout << SchoolsList[i][j];
				if (j != SchoolsList[i][MAXN + 1])
					cout << ' ';
				else
					cout << endl;
			}
		}
	}
}

int main() {
	memset(SchoolsList, 0, sizeof(SchoolsList));
	cin >> N >> M >> K;
	for (int i = 0; i < M; ++i) {
		cin>>SchoolsList[i][0];
	}
	for (int i = 0; i < N; ++i) {
		Applicants[i] = ApplicantsList[i];
		Applicants[i][K + 3] = i;
		for (int j = 1; j < 3 + K; ++j) {
			cin>>ApplicantsList[i][j];
		}
	}
	GenerateRank();
	GenerateResult();
	system("pause");
	return 0;
}