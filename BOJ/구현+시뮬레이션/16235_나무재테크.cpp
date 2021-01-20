// 16235_나무재테크.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 11

int n, m, k; // n: 크기, m: 나무 개수
int a[MAX][MAX]; // S2D2가 추가할 양분
int nutrient[MAX][MAX]; // 현재 양분 상태
int deadTree[MAX][MAX]; // 죽은 나무가 만든 양분
int dir[8][2] = { {1, 0}, {1, 1}, {1, -1}, {0, -1}, {0, 1}, {-1, -1}, {-1, 0}, {-1, 1} };
vector<int> tree[MAX][MAX];


int main() {
	scanf("%d %d %d", &n, &m, &k); // n x n, 나무 m개, k년
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]); // 각 칸의 양분
			nutrient[i][j] = 5; // 전역에서 초기화하면 안됨. 여기서 초기화
		}
	}

	/* 나무 정보 입력 */
	for (int i = 0; i < m; i++) {
		int x, y, z; // (x, y) 나무의 나이 z
		scanf("%d %d %d", &x, &y, &z);
		tree[x][y].push_back(z);
	}

	for (int year = 1; year <= k; year++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				/* 초기화 */
				nutrient[i][j] += deadTree[i][j];
				deadTree[i][j] = 0;
				/* 한칸에 나무가 여러 개 있을 경우 어린 나무부터 */
				sort(tree[i][j].begin(), tree[i][j].end());
			}
		}

		// 봄 + 여름
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int cnt = 0; cnt < tree[i][j].size(); cnt++) {
					// 양분이 나이보다 많을 경우
					if (nutrient[i][j] >= tree[i][j][cnt]) {
						nutrient[i][j] -= tree[i][j][cnt]; // 나무 나이만큼 양분 감소
						tree[i][j][cnt] += 1; // 나무 나이 증가
					}
					else { // 양분이 나이보다 적을 경우
						int idx = cnt;
						int size = tree[i][j].size();
						for (int l = size - 1; l >= idx; l--) {
							deadTree[i][j] += (tree[i][j][l] / 2); // 죽은 나무 양분 추가
							tree[i][j].pop_back(); // 나무 죽음
						}
						break;
					}
				}
			}
		}

		// 가을
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int cnt = 0; cnt < tree[i][j].size(); cnt++) {
					if (tree[i][j][cnt] % 5 == 0) {
						/* 인접한 8개 칸에 나이가 1인 나무 추가 */
						for (int l = 0; l < 8; l++) {
							int nx = i + dir[l][0];
							int ny = j + dir[l][1];
							if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
							tree[nx][ny].push_back(1); // 나이 1인 나무 추가
						}
					}
					else continue;
				}
			}
		}

		// 겨울
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				nutrient[i][j] += a[i][j];
			}
		}
	}

	int answer = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (tree[i][j].size() != 0) {
				answer += tree[i][j].size();
			}
		}
	}

	printf("%d\n", answer);
}
