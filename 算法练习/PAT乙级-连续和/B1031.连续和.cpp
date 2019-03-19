#include<cstdio>
int main(){
	int n;
	int mem_num[100000];
	scanf("%d", &n);
    for(int i = 1; i <= n;scanf("%d", &mem_num[i++]));
    mem_num[0] = 0;
    int max_sum = mem_num[1];
    for(int i = 1; i <= n; i++) {
        if(mem_num[i-1] > 0) mem_num[i] += mem_num[i - 1];
        else mem_num[i] += 0;
        if(mem_num[i] > max_sum) max_sum = mem_num[i];
    }
    printf("%d\n", max_sum);
    return 0;
}
