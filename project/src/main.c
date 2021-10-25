#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "utils.h"
#include "client_data.h"
#include "transaction.h"
#include "blackrecord.h"

Data client_data, transfer;

int main() {
  int choice = 0;
  FILE *Ptr, *Ptr_2, *blackrecord;
  printf("%s", "please enter action\n1 enter data client:\n2 enter data transaction:\n3 update base\n");
  while (scanf("%d", &choice) != EOF) {
      switch (choice) {
         case 1:
           Ptr = fopen("record.dat", "r+");
           if (Ptr == NULL) {
              puts("Not acess");
           } else {
              masterWrite(Ptr, client_data);
              fclose(Ptr);
           }
           break;
         case 2:
           Ptr = fopen("transaction.dat", "r+");
           if (Ptr == NULL) {
              puts("Not acess");
           } else {
              transactionWrite(Ptr, transfer);
              fclose(Ptr);
           }
           break;
         case 3:
           Ptr = fopen("record.dat", "r+");
           Ptr_2 = fopen("transaction.dat", "r+");
           blackrecord = fopen("blackrecord.dat", "w");
           if (Ptr == NULL || Ptr_2 == NULL || blackrecord == NULL) {
              puts("exit");
           } else {
              blackRecord(Ptr, Ptr_2, blackrecord, client_data, transfer);
              fclose(Ptr);
              fclose(Ptr_2);
              fclose(blackrecord);
           }
           break;
         default:
           puts("error");
           break;
      }
      printf("%s", "please enter action\n1 enter data client:\n2 enter data transaction:\n3 update base\n");
  }
  return 0;
}
