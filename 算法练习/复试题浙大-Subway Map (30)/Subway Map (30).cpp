/*
˼·��1.��ͼ���߼��ṹ�洢������ͼ
	 2.��ȱ�����Ҫ�õ��ԱȾ�ͣվ�뻻�˴��������˴���Ҫ����дһ�����ܺ������㣩
	 3.���޲��ؽ�����·���洢Ϊһ������
	 4.����������У�������վ��֮�����·��ű��ˣ������ǰһ����·���ݡ�
*/


#include<iostream>
#include<cstdlib>
#include<stack>
#include<vector>

using namespace std;
#define MAXMN 101

int min_count;								  //��С��ͣվ
int min_transfer;							  //��С������
int Matrix[10000][10000];					  //��¼����վ������·���
vector<vector<int> > StationSeq(10000);       //��¼�ڽ�վ������(��վ����Ϊ����)
bool Visited[10000];						  //��¼վ����ʱ�־����վ����Ϊ������
vector<int> Path;                             //��¼����·��
vector<int> temp_Path;						  //��¼��ʱ�Ա���·��
 
int CountTransStation(vector<int> path) {                    //���ĳ��·���еĻ������
	int count = 0;
	int preLine = Matrix[path[0]][path[1]];
	for (int j = 1; j < path.size(); ++j) {
		if (Matrix[path[j - 1]][path[j]] != preLine)
			count++;
		preLine = Matrix[path[j - 1]][path[j]];
	}
	return count;
}

void DFS(int start_station, int end_station, int station_count) {
	if (start_station == end_station && (station_count < min_count || (station_count == min_count && CountTransStation(temp_Path) < min_transfer))) {
		min_count = station_count;
		min_transfer = CountTransStation(temp_Path);
		Path = temp_Path;
	}
	if (start_station == end_station)
		return;
	for (int i = 0; i < StationSeq[start_station].size(); ++i) {
		if (!Visited[StationSeq[start_station][i]]) {
			Visited[StationSeq[start_station][i]] = true;
			temp_Path.push_back(StationSeq[start_station][i]);
			DFS(StationSeq[start_station][i], end_station, station_count + 1);
			Visited[StationSeq[start_station][i]] = false;
			temp_Path.pop_back();
		}
	}
	return;
}

int main() {
	int M, N, K;
	int start_station, end_station;
	int pre_station, temp_station;
	int pre_line, pre_Transfer;
	memset(Visited, false, sizeof(bool) * 10000);
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> M >> pre_station;
		for (int j = 0; j < M - 1; ++j) {
			cin >> temp_station;
			StationSeq[pre_station].push_back(temp_station);
			StationSeq[temp_station].push_back(pre_station);
			Matrix[pre_station][temp_station] = Matrix[temp_station][pre_station] = i;
			pre_station = temp_station;
		}
	}
	cin >> K;
	for (int i = 0; i < K; ++i) {
		cin >> start_station >> end_station;
		min_count = 99999;
		min_transfer = 99999;
		temp_Path.clear();
		temp_Path.push_back(start_station);
		Visited[start_station] = true;
		DFS(start_station, end_station, 0);
		Visited[start_station] = false;
		cout << min_count << endl;
		pre_line = 0;
		pre_Transfer = start_station;
		for (int j = 1; j < Path.size(); ++j) {
			if (Matrix[Path[j - 1]][Path[j]] != pre_line) {
				if(pre_line != 0)
					printf("Take Line#%d from %04d to %4d.\n", pre_line, pre_Transfer, Path[j - 1]);
				pre_line = Matrix[Path[j - 1]][Path[j]];
				pre_Transfer = Path[j - 1];
			}
		}
		printf("Take Line#%d from %4d to %04d.\n", pre_line, pre_Transfer, end_station);
	}
	system("pause");
	return 0;
}