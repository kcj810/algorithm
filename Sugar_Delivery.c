#include <stdio.h>
/*설탕 무게를 입력해서 각 3kg, 5kg 봉지에 담아 배달하는 문제. 단 봉지 개수는 최소값이 되어야함.
단 각 봉지에 모두 담을 수 있어야함. 1kg 2kg가 남으면 안됨. 이렇게 나머지가 생기면 -1을 출력.*/

int main()
{
	int i, N; // N은 배달해야할 설탕 무게.
	char ex[4] = { 1,2,4,7 }; // 예외처리. -1이 나오는 값은 이 4개뿐.

	printf("배달할 설탕 무게를 입력하시오: ");
	scanf("%d", &N);
	printf("\n");

	/*1. 최소봉지를 구해야 하기 때문에 5kg 봉지를 최대한 많이 활용하는 것이 중요.
	  2. 42kg라면 5kg 봉지를 8개 사용가능. 근데 2kg가 남기 때문에 안됨.
	  3. 그래서 5kg 봉지를 하나씩 줄여 나가며 (전체 무게) - (5kg에 담은 무게)가 3으로 나눌때 나머지가 없으면 됨.*/

	int b = N / 5;
	int a = N / 3;

	for (i = 0; i < 4; i++) {
		if (N == ex[i])
			printf("-1\n");
	}


	for (i = 0; i < N; i++) {
		if (N - 5 * b == 0) {
			printf("5키로 봉지 %d개\n", b); break;
		}
		else if (N < 10) {
			if (N - 3 * a == 0) {
				printf("3키로 봉지 %d개\n", a); break;
			}
			else if (N % 8 == 0) {
				printf("3키로 봉지 %d개\n5키로 봉지 %d개\n총 %d개\n", b, b, 2 * b); break;
			}
		}
		else if (N - 5 * b != 0) {
			if ((N - b * 5) % 3 == 0) {
				a = (N - 5 * b) / 3;
				printf("3키로 봉지 %d개\n5키로 봉지 %d개\n총 %d개\n", a, b, a + b); break;
			}
			b--;
		}
	}
	return 0;
}
