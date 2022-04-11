#include <string>
#include <vector>

using namespace std;

int coins[] = {1, 5, 10, 50, 100, 500};

// money: 생산해내야하는 금액, costs: 생성 단가
// answer: 단가의 최소 비용

// money: 4578원, costs: [1, 4, 99, 35, 50, 1000] --> 2308
// money: 1999원, costs: [2, 11, 20, 100, 200, 600] --> 2798
int solution(int money, vector<int> costs) {
    int answer = 0;

    // coins의 조합으로 money의 값을 만들 수 있는 모든 경우 찾기
    // 1 --> 1, 5 --> 1, 5, 10 --> 1, 5, 10, 50 --> 1, 5, 10, 50, 100 --> 1, 5, 10, 50, 100, 500
    int idx = 1;

    for(int i = 0; i < idx; i++){
        int sum = 0;

        if(sum == money){

        }
    }

    return answer;
}