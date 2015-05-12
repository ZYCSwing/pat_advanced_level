//1024. Palindromic Number
/*
A number that will be the same when it is written forwards or backwards is known as a Palindromic Number. For example, 1234321 is a palindromic number. All single digit numbers are palindromic numbers.

Non-palindromic numbers can be paired with palindromic ones via a series of operations. First, the non-palindromic number is reversed and the result is added to the original number. If the result is not a palindromic number, this is repeated until it gives a palindromic number. For example, if we start from 67, we can obtain a palindromic number in 2 steps: 67 + 76 = 143, and 143 + 341 = 484.

Given any positive integer N, you are supposed to find its paired palindromic number and the number of steps taken to find it.

Input Specification:

Each input file contains one test case. Each case consists of two positive numbers N and K, where N (<= 1010) is the initial numer and K (<= 100) is the maximum number of steps. The numbers are separated by a space.

Output Specification:

For each test case, output two numbers, one in each line. The first number is the paired palindromic number of N, and the second number is the number of steps taken to find the palindromic number. If the palindromic number is not found after K steps, just output the number obtained at the Kth step and K instead.

Sample Input 1:
67 3
Sample Output 1:
484
2
Sample Input 2:
69 3
Sample Output 2:
1353
3
*/
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	string str[2];
	int k,cnt;

	cin >> str[0] >> k;
	str[1] = str[0];
	reverse(str[1].begin(),str[1].end());
	cnt = 0;
	while(str[0]!=str[1] && cnt<k){
		int up = 0,index = str[0].length()-1,digit;
		string tmp;
		while(index>=0){
			digit = str[0][index]+str[1][index]-2*'0'+up;
			tmp.insert(tmp.begin(), digit%10+'0');
			up = digit/10;
			index--;
		}
		if(up){
			tmp.insert(tmp.begin(),up+'0');
		}
		str[0] = str[1] = tmp;
		reverse(str[1].begin(),str[1].end());
		cnt++;
	}
	cout << str[0] << endl << cnt;

	system("pause");
	return 0;
}