#define UTILS_H
#ifndef UTILS_H

#include "client_data.c"
#include "transaction.c"
#include "blackrecord.c"

void masterWrite(FILE *ofPTR, Data Client);
void transactionWrite(FILE *ofPtr, Data transfer);
void blackRecord(FILE *ofPTR, FILE  *ofPTR_2, FILE *blackrecord, Data client_data, Data transfer);

#endif //UTILS_H
