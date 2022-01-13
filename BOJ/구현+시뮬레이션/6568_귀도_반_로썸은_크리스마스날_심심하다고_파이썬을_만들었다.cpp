// 6568_귀도_반_로썸은_크리스마스날_심심하다고_파이썬을_만들었다.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main() {
	while (true) {
		int mem[32] = { 0, }; // 주소값(10진수)
		for (int i = 0; i < 32; i++) { // 32개 주소값 입력
			for (int j = 0; j < 8; j++) { // 비트 입력
				int bit;
				if (scanf("%1d", &bit) == -1) return 0; // EOF면 종료
				mem[i] = mem[i] * 2 + bit; // 2진수 -> 10진수
			}
		}

		int pc = 0; // 5 bit
		int adder = 0; // 8 bit
		while (true) { // 프로그램이 종료될 때까지 반복
			int instruction = mem[pc];
			int op = instruction / 32; // 상위 3 bit
			int val = instruction % 32; // 하위 5 bit

			if (op == 7) break; // HLT (프로그램 종료)

			// 명령어를 실행하기 전 PC +1 증가
			pc = (pc + 1) % 32;
			
			switch (op) {
				case 0: // STA (val에 가산기 값 저장)
					mem[val] = adder;
					break;
				case 1: // LDA (val의 값을 가산기로 불러오기
					adder = mem[val];
					break;
				case 2: // BEQ (가산기의 값이 0이면 PC값을 val로 바꾸기)
					if (adder == 0) pc = val;
					break;
				case 3: // NOP (아무것도 안함)
					break;
				case 4: // DEC (가산기 -1)
					adder = (adder + 255) % 256; // 8 bit 형태
					break;
				case 5: // INC (가산기 +1)
					adder = (adder + 1) % 256; // 8 bit 형태
					break;
				case 6: // JMP (PC 값을 val로 바꾸기)
					pc = val;
					break;
			}
		}

		// 가산기 값을 8 bit로 출력
		for (int i = 7; i >= 0; i--) {
			printf("%1d", (adder >> i) & 1);
		}
		printf("\n");
	}
	return 0;
}
