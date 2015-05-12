//1076. Forwards on Weibo
/*
Weibo is known as the Chinese version of Twitter. One user on Weibo may have many followers, and may follow many other users as well. Hence a social network is formed with followers relations. When a user makes a post on Weibo, all his/her followers can view and forward his/her post, which can then be forwarded again by their followers. Now given a social network, you are supposed to calculate the maximum potential amount of forwards for any specific user, assuming that only L levels of indirect followers are counted.

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive integers: N (<=1000), the number of users; and L (<=6), the number of levels of indirect followers that are counted. Hence it is assumed that all the users are numbered from 1 to N. Then N lines follow, each in the format:

M[i] user_list[i]

where M[i] (<=100) is the total number of people that user[i] follows; and user_list[i] is a list of the M[i] users that are followed by user[i]. It is guaranteed that no one can follow oneself. All the numbers are separated by a space.

Then finally a positive K is given, followed by K UserID's for query.

Output Specification:

For each UserID, you are supposed to print in one line the maximum potential amount of forwards this user can triger, assuming that everyone who can view the initial post will forward it once, and that only L levels of indirect followers are counted.

Sample Input:
7 3
3 2 3 4
0
2 5 6
2 3 1
2 3 4
1 4
1 5
2 2 6
Sample Output:
4
5
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	int n,l,k;
	vector<vector<int>> users;

	cin >> n >> l;
	users.resize(n);
	for(int i=0; i<n; i++){
		int m;
		cin >> m;
		for(int j=0; j<m; j++){
			int uid;
			cin >> uid;
			users[--uid].push_back(i);
		}
	}

	//BFS
	cin >> k;
	for(int i=0; i<k; i++){
		int uid;
		cin >> uid;
		uid--;
		vector<bool> visited(n,0);
		queue<pair<int,int>> qq;
		qq.push(pair<int,int>(uid,0));
		visited[uid] = 1;
		int cnt = -1;
		while(!qq.empty()){
			int id = qq.front().first;
			int level = qq.front().second;
			cnt++;
			if(level!=l){
				for(int j=0; j<users[id].size(); j++){
					if(!visited[users[id][j]]){
						qq.push(pair<int,int>(users[id][j],level+1));
						visited[users[id][j]] = 1;
					}
				}
			}
			qq.pop();
		}
		cout << cnt << endl;
	}

	system("pause");
	return 0;
}