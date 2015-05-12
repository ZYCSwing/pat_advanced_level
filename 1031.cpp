//1031. Hello World for U
/*
Given any string of N (>=5) characters, you are asked to form the characters into the shape of U. For example, "helloworld" can be printed as:

h  d
e  l
l  r
lowo
That is, the characters must be printed in the original order, starting top-down from the left vertical line with n1 characters, then left to right along the bottom line with n2 characters, and finally bottom-up along the vertical line with n3 characters. And more, we would like U to be as squared as possible -- that is, it must be satisfied that n1 = n3 = max { k| k <= n2 for all 3 <= n2 <= N } with n1 + n2 + n3 - 2 = N.
Input Specification:

Each input file contains one test case. Each case contains one string with no less than 5 and no more than 80 characters in a line. The string contains no white space.

Output Specification:

For each test case, print the input string in the shape of U as specified in the description.

Sample Input:
helloworld!
Sample Output:
h   !
e   d
l   l
lowor
*/
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	string str;
	int len,n1,n2;

	cin >> str;
	len = str.length();
	n1 = (len+2)/3;
	n2 = len+2-2*n1;

	for(int i=0; i<n1-1; i++){
		cout << str[i];
		for(int j=0; j<n2-2; j++){
			cout << " ";
		}
		cout << str[len-i-1] << endl;
	}
	for(int i=n1-1; i<len-n1+1; i++){
		cout << str[i];
	}

	system("pause");
	return 0;
}