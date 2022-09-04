// 2457_공주님의_정원.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

typedef struct Blooming {
	int start;
	int end;
};

int n;
vector<Blooming> flowers;

bool comp(Blooming a, Blooming b) {
	if (a.start == b.start) return a.end < b.end;
	return a.start < b.start;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int sm, sd, em, ed;
		scanf("%d %d %d %d", &sm, &sd, &em, &ed);
		// 3월 1일 -> 301, 11월 30일 -> 1130
		int start = 100 * sm + sd;
		int end = 100 * em + ed;
		flowers.push_back({ start, end });
	}

	// 시작시간 기준 오름차순 정렬
	sort(flowers.begin(), flowers.end(), comp);

	int endTime = 301; // 모든 꽃이 지는 시간
	// 가장 빨리 피는 꽃이 3월 2일부터면 불가능
	if (flowers[0].start > endTime) {
		printf("0\n");
		return 0;
	}

	int answer = 0; // 필요한 꽃 개수
	int idx = 0; // 꽃 번호
	while (endTime <= 1130) {
		int new_endTime = 0; // 갱신할 endTime
		while (idx < n) {
			// 당일에 피고 당일에 지는 꽃은 패스
			if (flowers[idx].start >= flowers[idx].end) {
				idx++;
				continue;
			}
			if (flowers[idx].start <= endTime) {
				// 꽃이 지는 시간이 최대인 꽃 선택
				if (new_endTime < flowers[idx].end) new_endTime = flowers[idx].end;
				idx++;
			}
			else break;
		}
		
		// endTime이 갱신이 안되면 종료
		if (new_endTime == 0) break;
		else {
			// endTime 갱신 후 꽃 개수 추가
			endTime = new_endTime;
			answer++;
		}
	}

	// endtime이 11월 30일 이후면 정답 출력
	if (endTime > 1130) printf("%d\n", answer);
	else printf("0\n");
	return 0;
}
