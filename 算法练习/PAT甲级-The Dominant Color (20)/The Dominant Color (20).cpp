//Ã‚ƒø√Ë ˆ
//Behind the scenes in the computer's memory, color is always talked about as a series of 24 bits of information for each pixel.  
//In an image, the color with the largest proportional area is called the dominant color.  A strictly dominant color takes more 
//than half of the total area.  Now given an image of resolution M by N (for example, 800x600), you are supposed to point out the 
//strictly dominant color.

// ‰»Î√Ë ˆ:
//Each input file contains one test case.  For each case, the first line contains 2 positive numbers: M (<=800) and N (<=600) which 
//are the resolutions of the image.  Then N lines follow, each contains M digital colors in the range [0, 224).  It is guaranteed 
//that the strictly dominant color exists for each input image.  All the numbers in a line are separated by a space.

// ‰≥ˆ√Ë ˆ:
//For each test case, simply print the dominant color in a line.
/*#include<iostream>
#include<vector>
using namespace std;
typedef struct node{
	int sum;
	int value;
}Node;
int Find(int x,vector<Node> v){
	for(int i=0;i<v.size();i++){
		if(v[i].value==x)
			return i;
	}
		return -1;
}
int main(){
	vector <Node> v;
	Node V={0,0};
	int c,r;
	int x;
	int temp;
	cin>>c>>r;
	for(int i=0;i<c*r;i++){
		cin>>x;
		temp=Find(x,v);
		if(temp==-1){
			V.value=x;
			V.sum=0;
			v.push_back(V);
		}
		else
			v[temp].sum++;
	}
	x=0;
	int j=0;
	for(int i=0;i<v.size();i++){
		if(x<v[i].sum){
			x=v[i].sum;
			j=i;
		}
	}
	cout<<v[j].value<<endl;
	return 0;
}*/
#include <iostream>  
int main(){  
    int m, n, x, times = 0, candidate;  
    scanf("%d%d", &m, &n);  
    for (int i = 0; i < n; ++i){  
        for (int j = 0; j < m; ++j){  
            scanf("%d", &x);  
            if (times == 0){  
                candidate = x;  
                ++times;  
            }  
            else{  
                if (x == candidate)  
                    ++times;  
                else  
                    --times;  
            }  
        }  
    }  
    printf("%d\n", candidate);  
    return 0;  
}  

