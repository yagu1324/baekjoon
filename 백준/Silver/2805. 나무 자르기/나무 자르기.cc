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
// 문제발생) 근데 이렇게 하니까 무한루프가 발생함 11/10 -> 0 이런느낌으로
// 
// 그렇다면? 상한선을 1개가 아닌 2개로 바꿈 -> 맨위와 맨 아래
// -> 100 0 이렇게 있으면 50 0 -> 50 25 이런식으로
// 문제 발생 ) 11/10 -> 이렇게 되면 0이 나옴 -> 해결) 강제로 -1, +1 을 실행
// 높은곳에서는 -1. 낮은곳에서는 +1/ 대신 while 문을 true 에서 shortest<=longest로 변경
// (이부분은 ai에게 도움받음)
// 
//
//int main() {
//	//시간초과용
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	int tree_case; // 입력받을 나무의 갯수
//	int need;// 필요한 나무 길이
//	int a,longest=0,shortest=0,cut=0;// a = 대충 입력받을 값, longest = 가장 긴 나무길이, sum=자를 나무길이의 총 합
//	long long sum = 0,ans;
//	vector<int> tree;
//	//입력들
//	cin >> tree_case;
//	cin >> need;
//	for (int i = 0; i < tree_case; i++) {
//		cin >> a;
//		if (longest < a)	longest = a;
//		tree.push_back(a);
//	}
//	cut = longest;
//
//	
//	while (shortest<=longest) {
//
//		sum = 0;
//		for (int i = 0; i < tree_case; i++) { // sum 값
//			if (tree[i] > cut)	sum += tree[i] - cut;
//		}
//
//		if (sum<need) { // 자른 나무량이 적을 경우
//			longest = cut-1; // 이전값 저장
//			cut = (cut + shortest) / 2;
//		}
//		else if (sum >= need) {//자른 나무양이 많을 경우
//			ans = cut;
//			shortest = cut+1;
//			cut = (longest + cut) / 2;
//		}	
//	}
//	cout << ans;
//
//	return 0;
//}


#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 빠른 입출력 (필수)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tree_case;
    long long need;
    cin >> tree_case >> need;

    // 💡 핵심 최적화: 미리 필요한 만큼 벡터의 크기를 할당해 둠 (push_back 제거)
    vector<int> tree(tree_case);
    long long longest = 0;

    for (int i = 0; i < tree_case; i++) {
        cin >> tree[i]; // push_back 대신 인덱스로 바로 접근
        if (longest < tree[i]) longest = tree[i];
    }

    long long shortest = 0;
    long long ans = 0;

    // 이분 탐색 뼈대 (무한루프 원천 차단)
    while (shortest <= longest) {
        long long cut = (shortest + longest) / 2;
        long long sum = 0;

        for (int i = 0; i < tree_case; i++) {
            if (tree[i] > cut) {
                sum += tree[i] - cut;
            }
        }

        if (sum < need) {
            longest = cut - 1;
        }
        else {
            ans = cut;
            shortest = cut + 1;
        }
    }

    cout << ans << "\n";
    return 0;
}