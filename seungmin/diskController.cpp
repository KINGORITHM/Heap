//
// Created by 이승민 on 2019-10-30.
//

//시간초과!!!!!!!!!!!!!!!!!!!
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct cmp {
    bool operator()(pair<int, int> t, pair <int,int> u) {
        return t.second > u.second;
    }
};

int solution(vector<vector<int>> jobs) {

    priority_queue <pair<int,int>, vector <pair<int, int>>, cmp> q;

    sort(jobs.begin(), jobs.end());

    int in = 0;
    int end = 0;
    int index = 0;


    int answer = jobs[0][1];
    int time = jobs[0][0] + jobs[0][1];
    int count = 1;

    while(1){

        if(count == jobs.size()){
            return answer/count;
        }

        for (int i = index + 1; i < jobs.size(); ++i) {
            if(jobs[i][0] <= time){
                q.push(make_pair(jobs[i][0], jobs[i][1]));
                index = i;
            }
            else{
                break;
            }
        }

        if(q.size() != 0) {
            in = q.top().first;
            end = q.top().second;
            q.pop();
            answer += (end + (time - in));
            time += end;
            count++;
        }
        else{
            if((index + 1) < jobs.size()){
                time = jobs[index + 1][0];
            }
        }
    }
}

int main() {

    vector<vector <int>> jobs = { {0,5}, {1,2}, {5,5} };
    //vector <vector<int>> jobs = { {0,3}, {1,9}, {2,6} };
    //vector <vector<int>> jobs = {{0,3}, {4,4}, {5,3}, {4,1}};

    cout << solution(jobs);

    return 0;
}

//[[24, 10], [18, 39], [34, 20], [37, 5], [47, 22], [20, 47], [15, 2], [15, 34], [35, 43], [26, 1]]
//[[24, 10], [18, 39], [34, 20], [37, 5], [47, 22], [20, 47], [15, 34], [15, 2], [35, 43], [26, 1]]