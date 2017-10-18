#include <stdio.h>

void hanoi(int num, char orig, char tmp, char to) {
	if (num == 1) printf("1번째판을 %c에서 %c로 옮긴다.\n", orig, to);
	else {
		hanoi(num - 1, orig, to, tmp);
		printf("%d번째판을 %c에서 %c로 옮긴다.\n", num, orig, to);
		hanoi(num - 1, tmp, orig, to);
	}
}

int main() {
	hanoi(4, 'A', 'B', 'C');
}