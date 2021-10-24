#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"


void transactionWrite(FILE *ofPtr, Data transfer) {
	printf("%s\n%s\n",
			"1 Number account: ",
			"2 Client cash payments: ");
	while(scanf("%d %lf", &transfer.Number, &transfer.cash_payments) != 0) {
		fprintf(ofPtr, "%-3d%-6.2f\n", transfer.Number, transfer.cash_payments);
		printf("%s\n%s\n",
				"1 Number account:",
				"2 Client cash payments: ");
	}
}
