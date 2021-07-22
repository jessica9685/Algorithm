// 9202_Boggle.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000

struct TrieNode {
	TrieNode* child[26];
	bool isEnd; // 마지막 문자이면 true
	bool isHit;

	// 생성자
	TrieNode() {
		isEnd = false;
		for (int i = 0; i < 26; i++) child[i] = NULL;
	}

	// 한 문자열에 대해 root에서 end까지 가면 end에서 hit flag를 표시함
	// 다음 문자열을 받아 새로운 트리를 만들기 위해서는 hit flag 초기화 필요
	void clearHit() {
		isHit = false;
		for (int i = 0; i < 26; i++) {
			if (child[i] != NULL) {
				child[i]->clearHit();
			}
		}
	}

	// 문자열에 해당 문자가 있으면 true
	bool hasChild(char c) {
		return child[c - 'A'] != NULL;
	}

	// 해당 문자의 자식 노드 반환
	TrieNode* getChild(char c) {
		return child[c - 'A'];
	}
};

struct Trie{
	TrieNode* root = new TrieNode();

	// 단어 삽입
	void insert(string word) {
		TrieNode* cur = root;
		// 문자열 길이만큼 순회
		for (char c : word) { 
			int idx = c - 'A';
			if (cur->hasChild(c) == false) {
				cur->child[idx] = new TrieNode();
			}
			cur = cur->getChild(c);
		}
		// 마지막 문자에 대해 end 표시
		cur->isEnd = true;
	}

	// 단어 찾기
	bool find(string word) {
		TrieNode* cur = root;
		for (char c : word) {
			if (cur->hasChild(c)) {
				cur = cur->getChild(c);
			}
			else return false;
		}
		// 마지막 문자까지 돌면 isEnd 반환
		return cur->isEnd;
	}
};

int w; // 단어 수
int b; // 보드의 개수
char board[4][4];
bool visited[4][4];
int score[9] = { 0, 0, 0, 1, 1, 2, 3, 5, 11 }; // 단어 길이에 따른 점수
int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
string answer; // 찾은 가장 긴 단어
string temp; // 찾은 단어
int sum; // 최대 점수 합
int cnt; // 찾은 단어의 수

// Boggle 보드 초기화
void clearBoard() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			board[i][j] = 0;
			visited[i][j] = false;
		}
	}
}

bool comp(string a, string b) {
	// a와 b의 길이가 같은 경우
	if (a.size() == b.size()) {
		int result = a.compare(b);
		if (result > 0) return true; // b가 사전적으로 더 앞에 있으면
		else return false; // b가 더 뒤에 있으면
	}
	else {
		return a.size() < b.size(); // b가 더 길면 true
	}
}

void dfs(int y, int x, int len, TrieNode *node) { // node: 현재 이동중인 노드
	// 1. 체크인
	visited[y][x] = true;
	temp.push_back(board[y][x]);
	// 2. 목적지에 도달했는지?
	// 목적지 = 단어 끝에 도달할 수 있고 && 아직 발견한 적 없는 단어
	if (node->isEnd == true && node->isHit == false) {
		node->isHit = true;
		sum += score[len]; // 점수 계산
		cnt++; // 찾은 단어 수 증가
		if (comp(answer, temp)) {
			answer = temp;
		}
	}
	// 3. 연결된 곳을 순회
	for (int i = 0; i < 8; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		// 4. 갈 수 있는가?
		if (ny >= 0 && nx >= 0 && ny < 4 && nx < 4) {
			// 아직 방문 안했고, Trie에 해당 문자가 존재하면
			if (!visited[ny][nx] && node->hasChild(board[ny][nx])) {
				// 5. 간다
				dfs(ny, nx, len + 1, node->getChild(board[ny][nx]));
			}			
		}
	}
	// 6. 체크아웃
	visited[y][x] = false;
	temp.pop_back();
}

int main() {
	scanf("%d", &w);
	Trie trie;
	for (int i = 0; i < w; i++) {
		string word;
		cin >> word;
		trie.insert(word);
	}

	scanf("%d", &b);
	trie.root->clearHit();
	while (b--) {
		clearBoard();
		answer.clear();
		cnt = 0;
		sum = 0;

		// board 입력
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++ ) {
				scanf(" %c", &board[i][j]);
			}
		}

		// 단어 찾기
		for (int y = 0; y < 4; y++) {
			for (int x = 0; x < 4; x++) {
				if (trie.root->hasChild(board[y][x])) {
					dfs(y, x, 1, trie.root->getChild(board[y][x]));
				}
			}
		}
		trie.root->clearHit();
		cout << sum << " " << answer << " " << cnt << "\n";
	}
}
