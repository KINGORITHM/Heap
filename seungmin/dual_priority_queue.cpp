//
// Created by 이승민 on 2019-10-30.
//

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

priority_queue <int> change(priority_queue <int> q){


    if(q.size() < 0){
        return q;
    }
    else if(q.size() == 1){
        q.pop();
        return q;
    }

    stack <int> s;
    while(q.size() != 0) {
        s.push(q.top());
        q.pop();
    }

    s.pop();

    priority_queue <int> result;

   while(s.size() != 0) {
        result.push(s.top());
        s.pop();
    }

   return result;
}

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue <int> q;
    int count = 0;

    for (int i = 0; i < operations.size(); i++)
    {
        string temp = operations[i].substr(2, operations[i].length());
        int num = stoi(temp);

        if (operations[i][0] == 'I') {
            q.push(num);
        }
        else {
            if(q.size() > 0){      //이게 문제
                if (num < 0) {
                    q = change(q);
                }
                else {
                    if(q.size() > 0){
                        q.pop();
                    }
                }
            }

        }

    }

    if(q.size() > 1){
        answer.push_back(q.top());
        stack <int> s;

        while(q.size() != 0){
            s.push(q.top());
            q.pop();
        }

        answer.push_back(s.top());
    }
    else if(q.size() == 1){
        answer.push_back(q.top());
        answer.push_back(q.top());
    }
    else{
        answer.push_back(0);
        answer.push_back(0);
    }

    return answer;
}

int main() {

    //vector <string> operations = { "I 16", "D 1" };
    //vector <string> operations = { "I 7", "I 5", "I -5", "D -1" };
    vector <string> operations = {"I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"};

    vector <int> result = solution(operations);
    cout << result[0] << " " << result[1];
    return 0;
}