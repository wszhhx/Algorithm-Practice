/*
˼·�����Ⲣ��һ��Ҫ������㶨��ֻҪ������׼ȷ��ԭ��һ�����м��ɡ����ñ������������ݵ�ӳ�䣬�ص��������ת������
     1.��ĩβ��ͷ���������ڸ��������ڵ���������Ų���ײ���
	 2.��ĩβ��ͷ��������С��0�����ƶ����ײ���
	 ������ӳ�����������
*/
#include<iostream>
#include<map>
#include<vector>
#include<iomanip>

using namespace std;

map<int, int> ADDR_MAP;
map<int, int> RADDR_MAP;  //ADDR_MAP�ķ���ӳ��
map<int, int> NADDR_MAP;
vector<int> List;
int addr_head;
int data_head;
int N, K;

void process() {
	int i = List.size() - 1;
	int next_i = 0;
	int rec;
	int firs_proc = 10000000;
	while (List[i] != firs_proc) {                          //��ʵ�����Ѿ�����ά��NADDR_MAP�ˣ������ʱ��ֱ������һ������ַ����next_addr
		if (List[i] >= 0 && List[i] <= K) {
			if (firs_proc == 10000000)
				firs_proc = List[i];
			rec = List[i];
			List.erase(List.begin()+i);
			List.insert(List.begin(), rec);
			++next_i;
			continue;
		}
		--i;
	}
	i = List.size() - 1;
	while (List[i] != firs_proc) {
		if (List[i] < 0) {
			rec = List[i];
			List.erase(List.begin() + i);
			List.insert(List.begin(), rec);
			++next_i;
			continue;
		}
		--i;
	}
	return;
}

void output() {
	for (int i = 0; i < List.size() - 1; ++i) {
		cout << setw(5) << setfill('0') << ADDR_MAP[List[i]] << ' ' << List[i] << ' ' << setw(5) << setfill('0') << ADDR_MAP[List[i + 1]] <<endl;
	}
	cout << setw(5) << setfill('0') << ADDR_MAP[List[List.size() - 1]] << ' ' << List[List.size() - 1] << ' ' << "-1" << endl;
	return;
}

int main() {
	int addr_now, addr_next;
	int data;
	while (cin >> addr_head >> N >> K) {
		List.clear();
		ADDR_MAP.clear();
		NADDR_MAP.clear();
		for (int i = 0; i < N; ++i) {
			cin >> addr_now >> data >> addr_next;
			if (addr_now == addr_head)
				data_head = data;
			ADDR_MAP[data] = addr_now;
			NADDR_MAP[data] = addr_next;
			RADDR_MAP[addr_now] = data;
			
		}
		map<int, int>::iterator its = RADDR_MAP.find(addr_head);   //�ҵ��׽�㣻
		data_head = its->second;
		addr_next = NADDR_MAP[its->second];
		List.push_back(its->second);
		while (addr_next != -1) {                                 //�齨����
			its = RADDR_MAP.find(addr_next);
			data = its->second;
			List.push_back(data);
			addr_next = NADDR_MAP[data];
		}
		process();
		output();
	}
	return 0;
}