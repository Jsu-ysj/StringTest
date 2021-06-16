/**题目简介：
对于一个长n的字符串s，可以进行左移操作，即将前1位移至串尾，进行n次左移操作，可以得到n个与原串循环同构的字符串，
现在要求出这字符串s中最小表示的位置和最大表示的位置，以及在n个循环同构的字符串中分别出现了多少次。
例如：字符串"SKYLONG"
SKYLONG 1
KYLONGS 2
YLONGSK 3
LONGSKY 4
ONGSKYL 5
NGSKYLO 6
GSKYLON 7
最小表示是GSKYLON，最大表示是YLONGSK，都只出现了一次。
Input
每一行包含一个字符串s(|s| <= 1000000)。（用EOF作为结束输入标志）
Output
每一行对应一个字符串的输出，每行包含四个整数并用空格隔开，第一个整数代表最小表示的位置，第二个整数代表最小表示出现的次数，
第三个整数代表最大表示的位置，第四个整数代表最大表示出现的次数。
Sample Input
abcder
aaaaaa
ababab
Sample Output
1 1 6 1
1 6 1 6
1 3 2 3
**/

/** 思路:
要学一个新的东西 最小最大表示, 其他的就是循环节+next；
蛮简单的 但是我时间超限了好多次， 后面发现要优化getNext()才可以过Z；
void getNext() {
	int j=-1;
	for(int i=0; str[i]; i++) {
		while(str[i]!=str[j+1]&&j!=-1)j=nxt[j];
		if(str[i]==str[j+1]&&i!=0)j++;
		nxt[i]=j;
	}
}
 
还是没有过， 就是因为要交C++ , G++ 过不了
**/

// 具体代码:

#include<iostream>
#include <algorithm>
#include<cstring>
using namespace std;
const int N = 1000000 + 10;
int nxt[N];
char str[N], str2[N];
int len;
void getNext() {
	int j=-1;
	for(int i=0; str[i]; i++) {
		while(str[i]!=str[j+1]&&j!=-1)j=nxt[j];
		if(str[i]==str[j+1]&&i!=0)j++;
		nxt[i]=j;
	}
}


int express(int flag) {
	int i=0,j=1,k=0;
	while (i<len && j<len && k<len) {
		int t = str[(j+k)%len]-str[(i+k)%len];
		if (t==0) k++;
		else {
			if (flag) {
				if (t>0) j+=k+1;
				else i+=k+1;
			} else {
				if (t>0) i+=k+1;
				else j+=k+1;
			}
			if (i==j) j++;
			k=0;
		}
	}
	return min(i,j);
}

int main() {
	while(~scanf("%s", str)) {
		len = strlen(str);
		getNext();
		int ans ;
		if(len % (len-nxt[len-1]-1) == 0){
			ans = len/(len-nxt[len-1]-1);
		} else ans=1;
		printf ("%d %d %d %d\n", express(1)+1, ans, express(0)+1, ans);
	}
	return 0;
}
