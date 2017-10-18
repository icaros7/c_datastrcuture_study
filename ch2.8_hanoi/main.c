#include <stdio.h>

void hanoi(int num, char orig, char tmp, char to) {
	if (num == 1) printf("1��°���� %c���� %c�� �ű��.\n", orig, to);
	else {
		hanoi(num - 1, orig, to, tmp);
		printf("%d��°���� %c���� %c�� �ű��.\n", num, orig, to);
		hanoi(num - 1, tmp, orig, to);
	}
}

int main() {
	hanoi(4, 'A', 'B', 'C');
}