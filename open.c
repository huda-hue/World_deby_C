#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "kalkulator.h"

int* cariFaktor(int n, int *count) {
   int *faktor = NULL; // belum ada memori yang dialokasikan
   *count = 0; // banyak faktor yang sudah ditemukan

   for (int i = 1; i <= n; i++) {
      if (n%i == 0) {
         // jumlah faktor bertambah 1
         (*count)++;
         // perbesar ukuran array
         faktor = realloc(faktor, (*count) * sizeof(int));
         // kondisi gagal realokasi
         if (faktor == NULL) {
            printf("Gagal alokasi memori\n");
            exit(0);
         }
         // simpan faktor baru ke array di posisi terakhir
         faktor[*count-1] = i;
      }
   }
   return faktor; // mengembalikan pointer ke array
}

bool bilangan_prima(int n) {
   if (n < 2) {
      return false;
   } else if (n == 2) {
      return true;
   } else {
      int m = 2;
      while (m<n) {
         if (n%m == 0) {
            return false;
            break;
         } else {
            if (m == n-1) {
               return true;
            }
         }
         m++;
      }
   }
}

double kalkulator() {
   char operators[][50] = {
      "Jumlah (+)",
      "Kurang (-)",
      "Selisih (| |)",
      "Kali (*)",
      "Bagi (/)"
   };
   short pilih1_1;
   double a, b, hasil1_1;

   printf("\n### SELAMAT DATANG DI KALKULATOR C ###\n");
   printf("Berikut pilihan operator matematika:\n");
   for (int i = 0; i < 5; i++) {
      printf("%d. %s\n", i+1, operators[i]);
   }

   printf("Pilihanmu: ");
   scanf("%d", &pilih1_1);

   printf("a: ");
   scanf("%lf", &a);
   printf("b: ");
   scanf("%lf", &b);

   if (pilih1_1 == 1) {
      hasil1_1 = jumlah(a, b);
   } else if (pilih1_1 == 2) {
      hasil1_1 = jumlah(a, -b);
   } else if (pilih1_1 == 3) {
      if (a >= b) {
         hasil1_1 = jumlah(a, -b);
      } else {
         hasil1_1 = jumlah(b, -a);
      }
   } else if (pilih1_1 == 4) {
      hasil1_1 = kali(a, b);
   } else if (pilih1_1 == 5) {
      if (b != 0) {
         hasil1_1 = bagi(a, b);
      } else {
         printf("Undefined!\n");
         return 1;
      }
   }

   printf("%s antara %.2lf dan %.2lf: %.2lf\n", operators[pilih1_1-1], a, b, hasil1_1);
}

void matematika() {
   char Menu1[][50] = {
      "Kalkulator",
      "Bilangan Prima",
      "Faktor Bilangan Bulat"
   };
   short pilih1;

   printf("\n** MENU MATEMATIKA **\n");
   for (int i = 0; i < 3; i++) {
      printf("%d. %s\n", i+1, Menu1[i]);
   }

   printf("Pilihanmu: ");
   scanf("%d", &pilih1);

   if (pilih1 == 1) {
      kalkulator();
      printf("\n");
   } else if (pilih1 == 2) {
      int n;
      printf("\n%% BILANGAN PRIMA %%\n");
      printf("n: ");
      scanf("%d", &n);
      if (bilangan_prima(n)) {
         printf("%d adalah bilangan prima\n", n);
      } else {
         printf("%d bukan bilangan prima\n", n);
      }
      printf("\n");
   } else if (pilih1 == 3) {
      int n, banyak_faktor;
      printf("n: "); // masukkan bilangan
      scanf("%d", &n);

      int* hasil = cariFaktor(n, &banyak_faktor);

      printf("Faktor dari %d: ", n);
      for (int i = 0; i < banyak_faktor; i++) {
         printf("%d ", hasil[i]);
      }
      printf("\n");

      // bebaskan memori
      free(hasil);
   }
}

void games() {
   char Menu2[][50] = {
      "Rock-Scissor-Paper Game",
      "Finger Game"
   };
   short pilih2;

   printf("\n** MENU GAMES **\n");
   for (int i = 1; i <= 2; i++) {
      printf("%d. %s\n", i, Menu2[i]);
   }

   printf("Pilihanmu: ");
   scanf("%d", &pilih2);

   if (pilih2 == 1) {
      //rsp_game();
   } else if (pilih2 == 2) {
      //finger_game();
   }
}

int main(void) {
   char menu[][20] = {
      "Matematika",
      "Games"
   };
   short pilih;

   printf("\n$$$ SELAMAT DATANG DI DUNIA DEBY $$$\n");
   printf("-- Menu --\n");
   for (int i = 1; i <= 2; i++) {
      printf("%d. %s\n", i, menu[i-1]);
   }

   printf("Pilihanmu: ");
   scanf("%d", &pilih);

   if (pilih == 1) {
      matematika();
   } else if (pilih == 2) {
      games();
   }


   return 0;
}
