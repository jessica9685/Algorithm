// 11279_최대_힙.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 100001

int n;
int heap[MAX];
int s = 0; // 힙 크기

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void push(int x) {
	int idx = ++s;
	while ((idx > 1) && (x > heap[idx / 2])) { // 삽입 원소가 부모보다 크면
		swap(&heap[idx], &heap[idx / 2]); // swap
		idx /= 2;
	}
	heap[idx] = x;
}

int pop() {
	// 비어있는 경우
	if (s == 0) return 0;

	int result = heap[1]; // root 꺼내기
	heap[1] = heap[s--]; // 맨 마지막 원소 root로

	int parent = 1; // root부터 탐색
	while (true) {
		int child = parent * 2;
		if ((child + 1 <= s) && (heap[child] < heap[child + 1])) {
			child++;
		}
		if (child > s || heap[child] < heap[parent]) break; // 자식이 부모보다 작으면 끝
		swap(&heap[child], &heap[parent]);
		parent = child;
	}

	return result;
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		if (num == 0) {
			printf("%d\n", pop());
		}
		else {
			push(num);
		}
	}
}
