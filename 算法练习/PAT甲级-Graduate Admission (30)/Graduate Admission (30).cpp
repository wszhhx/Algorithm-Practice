/*
��Ŀ��������Ϥ��2013���㽭ʡԼ��100���о���Ժ׼������40000�������롣������дһ���Զ�����ѧ������ô���ṩ�ܴ�İ�����
         ÿ��������Ҫ�ṩ����������1.ͳ���ɼ�����GE��2.���Գɼ�����GI����������Ϊ��(GE + GI) / 2����ѧ����Ϊ��
		 1.���뽫����ÿ��ѧ�������������������򣬲��ӵ�һ������ɸѡ�ܹ���ѧ�����롣
		 2.������������һ�£���������ǵ�ͳ������GE�������ǵ��Ⱥ���������Ȼһ�£����ǵ���������һ�¡�
		 3.ÿλ��������K��ѡ��¼ȡ��������ѡ����У�������������ĳ��Ӧ�ñ�¼ȡ����������ϲ����ѧУ����û�г�������ô�����ᱻ���ѧУ¼ȡ��
		   ������������־Ը��������ѭ��������һ����ɸѡ֪���ܱ�ĳ־Ը¼ȡ����ĳ���޷���������־Ը��ѧУ������Ҫ�����޷���¼ȡ��
		 4.������ͬ����������ͬ������������պ�������ͬһ��ѧУ,��ô����ѧУ����ͬ�����Ǽ�����ͬ���������루���������ᵼ������������������

����������ÿ���������һ������.ÿ�������ĵ�һ�а���������������N (<=40000)(����������); M (<=100)����ѧУ����; K (<=5)ÿ���������־Ը��
         �ڶ��и���M����������ÿ�������ÿո��������i����Ϊ��i��ѧУ���������
		 ����������N�У�ÿ�а���K + 2�����������ÿո��������Ե�i��ͷ������Ϊ��i��ѧ����ͳ������GE�븴������GI����������K������Ϊ��������
		 ־Ը����һ־Ը���ڶ�־Ը������������
		 Ϊ�˼򻯣����Ǽ���ѧУ��0��M-1��ţ�ѧ����0��N-1��š�

�������������ÿ�����ӣ�����Ҫ�������ѧУ�����������ÿ��ѧУ�Ľ��ռһ�У�ÿ�������ȡѧ���ı�ţ��ұ�Ŵ�С��������ѧУҲһ������ĳ��ѧУû����
         �κ�ѧ�������ÿ��д��档ÿ����ĩβ�����ж���Ŀո�

*/
#include<iostream>
#include<cstdlib>
#include<algorithm>

#define MAXN 40000
#define MAXM 100
#define MAXK 5
using namespace std;
int SchoolsList[MAXM][MAXN + 2];     ///[][0]Ϊ��������   [][1 ~ MAXN]Ϊ¼ȡѧ����š� [][MAXN+1]Ϊ��¼ȡ����  -1Ϊ��
int ApplicantsList[MAXN][MAXK + 4];  ///[][3 ~ MAXK+2]Ϊ־Ը  [][0]Ϊ��������  [][1]ΪGE  [][2]ΪGI  [][MAXK+3]Ϊ���
int *Applicants[MAXN];               ///ָ�����飬����ѧ����������
int M, N, K;
//Applicants���±�Ϊ����˳����ʵ������
//ApplicantsList���±�Ϊѧ��ԭ��ţ��Ժ��ڲ����а���

bool MySort(int *a, int *b) {
	return (a[1] + a[2] > b[1] + b[2] ||(a[1] + a[2] == b[1] + b[2] && a[1] > b[1]) );    //������GE+GI��GE�����ɴ�С����
}

void GenerateRank() { //��ѧ�����������������Ա����水˳�����¼ȡ
	sort(Applicants, Applicants + N,MySort);
	int Rank = 1;
	int *temp;                     //��������ָ�������Ա���߼��ϵ�ͬ����Applicants�н�������Ԫ��
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

bool Admit(int stu_index,int sch_index) { //�ж��Ƿ�������ѧ��
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
	for (int i = 0; i < N; ++i) {              //���������ɸߵ��������ж���ѧ���
		for (int j = 3; j < 3 + K; ++j) {
			if (Admit(i, Applicants[i][j])) {
				SchoolsList[Applicants[i][j]][++SchoolsList[Applicants[i][j]][MAXN + 1]] = Applicants[i][K + 3];
				break;
			}
		}
	}
	for (int i = 0; i < M; ++i) {            //������
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