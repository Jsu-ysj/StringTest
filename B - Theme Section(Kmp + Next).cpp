/**
It's time for music! A lot of popular musicians are invited to join us in the music festival. 
Each of them will play one of their representative songs. To make the programs more interesting
and challenging, the hosts are going to add some constraints to the rhythm of the songs, i.e.,
each song is required to have a 'theme section'. The theme section shall be played at the beginning,
the middle, and the end of each song. More specifically, given a theme section E, the song will be 
in the format of ' EAEBE', where section A and section B could have arbitrary number of notes. Note 
that there are 26 types of notes, denoted by lower case letters 'a' - 'z'.

To get well prepared for the festival, the hosts want to know the maximum possible length of the 
theme section of each song. Can you help us?
Input
The integer N in the first line denotes the total number of songs in the festival. Each of the 
following N lines consists of one string, indicating the notes of the i-th (1 <= i <= N) song. 
The length of the string will not exceed 10^6.

Output
There will be N lines in the output, where the i-th line denotes the maximum possible length of 
the theme section of the i-th song.
 

Sample Input
6
xy
abc
aaa
aaaaba
aaxoaaaaa
aaaaabaaa
Sample Output
0
0
1
1
2
2
**/

/**思路：
这个题要的是EAEBE类型的
其中A, B 随便， E越大越好
及前面一段， 后面一段，中间一段 ；
前缀， 中间， 后缀；
所以想到用next数组， Kmp
注意中间不可重叠， 所以要	for(int j = i+i; j <= len-i; j ++)规定遍历区间

//具体代码：
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int Next[N];
string str;
void GetNext(){
	int i = 0, j = -1;
	Next[0] = -1;
	int len = str.length();
	while(i < len){
		if(j == -1 || str[i] == str[j]){
			Next[++ i] = ++j;
		}else{
			j = Next[j];
		}
	}
}

void Kmp(){
	int ans = 0;
	int len = str.length();
	for(int i = Next[len]; i; i = Next[i]){
		for(int j = i+i; j <= len-i; j ++){
			if(Next[j] >= i){
				ans = max(ans, i);
			}
		}
	}
	cout << ans << endl;
}
int main(){
	int T; cin >> T;
	while(T --){
		cin >> str;
		GetNext();
		Kmp();
	}
	return 0;
}
