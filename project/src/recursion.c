#include <stdio.h>
#include "recursion.h"

int recursion(int my_num, int current_stage) {
	if (current_stage < my_num) {
		printf("%d ", current_stage);
		curren_stage++;
		recursion(my_num, current_stage);
	}
	else {
		printf("%d", current_stage);
		return 0;
	}
}
