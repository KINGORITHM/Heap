#include <iostream>
#include <string>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	
	priority_queue <int,vector<int>,greater<int>> q;

	for (int i = 0; i < scoville.size(); i++)
	{
		q.push(scoville[i]);
	}

	int taste = 0;

	while (1) {

		if (q.size() == 0) {
			return -1;
		}
		
		if (q.top() > K) {
			return answer;
		}

		if (q.size() > 1) {
			answer++;
			int first = q.top();
			q.pop();
			int second = q.top();
			q.pop();
			taste = second * 2 + first;
			q.push(taste);
		}
		else {
			return -1;
		}
	}

	return answer;
}

int main() {

	vector <int> scoville = { 1, 2, 3, 9, 10, 12 };
	int K = 7;
	cout << solution(scoville, K);
	return 0;
}
