#include<iostream>
#include<vector>
using namespace std;
//첫번 째 해결방안
int main() {
	int c, w, n; // c = case의 갯수 w = 쓰레기차의 용량, n = 지점의 갯수
	cin >> c;// 케이스 갯수 입력
	vector<pair<int, int>> trash; // 케이스 갯수 만큼의 벡터 생성
	for (int i = 0; i < c; i++) { //케이스 값 만큼 반복
		trash.clear(); // 벡터 초기화
		cin >> w >> n; // 쓰레기차의 용량과 지점의 갯수 입력
		for (int j = 0; j < n; j++) { // 지점의 갯수 만큼 반복
			int t, nn; // 쓰레기의 양 , nn= 지점의 번호 (근데 안씀) 무조건 순서대로 들어오기 때문
			cin >> nn >> t; // 쓰레기의 양 입력
			trash.push_back({ nn,t }); // 벡터에 쓰레기의 양 추가
		}

		// sum=쓰레기차 거리용(처음부터 움직이는걸 가정), i_w=현재 차용량, i_n=현재 지점 번호
		int sum = 0, i_w = 0, i_n = 0;

		while (i_n < n) {//이동한 지점이 n까지 일 경우 (0부터 시작하니까 -1) (조건3)

			if (i_w + trash[i_n].second <= w) {// 현재 쓰레기용량 + 현재 지점쓰레기 <= 최대용량일경우
				i_w += trash[i_n].second; // 현재 쓰레기용량에 현재 지점쓰레기 추가

				if (i_n == 0)	sum += trash[i_n].first; // 처음 이동할 때는 현재 지점 번호만큼 이동거리 증가
				else
				{
					sum += trash[i_n].first - trash[i_n - 1].first; // 이동거리 증가
				}

				if (i_w == w && i_n<n-1) { // 조건 2 (쓰레기가 가득 찼을 떄 집으로 간다) / i_n<n-1 확인하는 순서가 바로 집으로 돌아가는 n-1 번째가 아닐경우
					sum += (trash[i_n].first * 2); // 이동거리 + 현재 지점 번호 * 2 (왕복)
					i_w = 0; // 쓰레기차 용량 초기화
				}

				i_n++; // 다음 지점으로 이동
			}
			else {//용량 초과 (조건1,2)
				sum += (trash[i_n].first * 2); // 이동거리 + 현재 지점 번호 * 2 (왕복)
				i_w = 0; // 쓰레기차 용량 초기화
			}
		}
		sum += trash[i_n - 1].first; // 마지막 지점에서 출발지까지 이동거리 추가
		cout << sum << endl; // 결과 출력
	}
	return 0;
}