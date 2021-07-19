// 1713_후보_추천하기.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 101

typedef struct {
	int student; // 학생 번호
	int rec; // 추천 횟수
	int time; // 처음 게시된 시간
} Photo;

bool comp(Photo a, Photo b) {
	// 추천수가 같으면
	if (a.rec == b.rec) {
		// 시간 내림차순 정렬 (뒤로 갈수록 오래됨)
		return a.time > b.time;
	}
	// 추천수 내림차순 정렬 (뒤로 갈수록 적어짐)
	return a.rec > b.rec;
}

// 최종 결과 출력시 학생 번호 오름차순 정렬
bool compRes(Photo a, Photo b) {
	return a.student < b.student;
}

int n; // 사진틀 개수
int k; // 총 추천 횟수

int recommand[MAX]; // 각 학생의 추천 횟수

int main() {
	scanf("%d", &n);
	scanf("%d", &k);
	
	vector<Photo> posted(n, { 0, 0, 0 });
	for(int t = 1; t <= k; t++) {
		int student;
		scanf("%d", &student);
		recommand[student]++; // 해당 학생의 추천수 증가

		bool replace = true; // 사진틀 바꿔야하면 true
		for (int i = 0; i < n; i++) {
			// 빈 사진틀이 있는 경우
			if (posted[i].student == 0) {
				posted[i].student = student;
				posted[i].rec = recommand[student];
				posted[i].time = t;

				replace = false;
				break;
			}
			// 해당 학생이 이미 게시된 경우
			else if (posted[i].student == student) {
				posted[i].rec = recommand[student];
				replace = false;
				break;
			}
		}

		// 사진 바꿔야하는 경우
		if (replace) {
			sort(posted.begin(), posted.end(), comp);
			int removed = posted.back().student;
			recommand[removed] = 0; // 제외된 학생의 추천수 초기화
			posted.pop_back(); // 사진 빼기
			posted.push_back({ student, recommand[student], t }); // 사진 추가
		}
	}

	sort(posted.begin(), posted.end(), compRes);
	for (auto p : posted) {
		if (p.student == 0) continue;
		printf("%d ", p.student);
	}
	printf("\n");
	return 0;
}
