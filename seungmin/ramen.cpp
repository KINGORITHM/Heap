//
// Created by 이승민 on 2019-10-30.
//

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int K) {

    int answer = 0;

    priority_queue <int> q;

    int index = -1;
    while (1) {

        if(stock >= K){
            return answer;
        }

        for (int i = index + 1; i < dates.size(); ++i) {
            if(dates[i] <= stock){
                q.push(supplies[i]);
                index = i;
            }
            else{
                break;
            }
        }

        answer++;
        stock += q.top();
        q.pop();

    }
}

int main(){

    int stock = 4;
    vector <int> dates = {4, 10, 15};
    vector <int> supplies = {20, 5, 10};
    int K = 30;

    cout << solution(stock, dates, supplies, K);

    return 0;
}