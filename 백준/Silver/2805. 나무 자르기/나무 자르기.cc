#include<iostream>
#include<vector>
using namespace std;

//설명
// 이 문제는 가장 위에서 1씩 자르면서 잘린 값의 총합을 더하는 간단한 문제입니다.
// 가장 긴나무의 길이 longest 에서 1씩 내려가며 줄어든 longest 값보다 길이가 긴
// 나무들이 longest의 차이 만큼 다 더해서 필요한 나무길이를 구하면 됩니다.
// 
// @@위의 방법은 틀렸습니다! 시간 초과입니다!
// 
// 이건 위의처럼 무식한 방법이 아닌 이분 탐색을 해야합니다
// 2번째 방법 -> 원래는 하나의 상한선을 통하여 값들을 줄이고 올리고 할 생각이었습.
// 문제발생) 근데 이렇게 하니까 뭔가 저장해야될 값들이 많아 짐 past 하나로는 부족하다고 느낌
// 막상 해보니까 상한선이 만약 위에서 아래로 내려왔을 경우 올라가는건 막겠지만 내려가는건 결국 shortest가 제일밑임
// 만약 밑에서 위로 cut가 올라간다고 가정했을 경우, 밑에서 올라오는 past가 없다면 결국 cut는 또 내려감
// 
// 그렇다면? 상한선을 1개가 아닌 2개로 바꿈 -> 맨위와 맨 아래
// -> 100 0 이렇게 있으면 50 0 -> 50 25 이런식으로
// 문제 발생 ) 11/10 -> 이렇게 되면 0이 나옴(무한루프에 빠짐) -> 해결) 강제로 -1, +1 을 실행
// 높은곳에서는 -1. 낮은곳에서는 +1/ 대신 while 문을 true 에서 shortest<=longest로 변경
//									-> 이렇게 한 이유는 longest가 need 값을 찍었을 경우 49+49 / 2 = cut 이라는 공식으로 결국 값을 저장
// (이부분은 ai에게 도움받음)
//

int main() {
	//시간초과용
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int tree_case; // 입력받을 나무의 갯수
	int need;// 필요한 나무 길이
	int a,longest=0,shortest=0,cut=0;// a = 대충 입력받을 값, longest = 가장 긴 나무길이
	long long sum = 0,ans; //sum = 자른 나무의 총 길이, ans = 답을 저장할 값
	vector<int> tree;

	//입력들
	cin >> tree_case;
	cin >> need;
	for (int i = 0; i < tree_case; i++) {
		cin >> a;
		if (longest < a)	longest = a;
		tree.push_back(a);
	}
	cut = longest;

	
	while (shortest<=longest) { 

		sum = 0;
		for (int i = 0; i < tree_case; i++) { // sum 값
			if (tree[i] > cut)	sum += tree[i] - cut;
		}

		if (sum<need) { // 자른 나무량이 적을 경우
			longest = cut-1; // 이전값 저장
			cut = (longest + shortest) / 2;
		}
		else if (sum >= need) {//자른 나무양이 많을 경우
			ans = cut;
			shortest = cut+1;
			cut = (longest + longest) / 2;
		}	
	}
	cout << ans;

	return 0;
}

