#ifndef PROJECT_INCLUDE_UTILS_H_
#define PROJECT_INCLUDE_UTILS_H_
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

struct masterRecord {
        int Number;
        char Name[20];
        char Surname[20];
        char addres[30];
        char TelNumber[15];
        double indebtedness;
        double credit_limit;
        double cash_payments;
};
typedef struct masterRecord Data;

void masterWrite(FILE *ofPTR, Data Client);
void transactionWrite(FILE *ofPtr, Data transfer);

#endif //PROJECT_INCLUDE_UTILS_H_
