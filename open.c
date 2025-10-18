#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "kalkulator.h"

void games();
bool bilangan_prima(int n);
int* cariFaktor(int n, int *count);
double kalkulator();
void matematika();

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


// FUNGSI-FUNGSI

bool finger_game() {
   char komponen[][10] = {
      "Orang", // 0
      "Semut", // 1
      "Gajah" // 2
   };
   printf("Pilih salah satu di antara berikut ini:\n");
   for (int i = 0; i < 3; i++) {
      printf("%d. %s\n", i+1, komponen[i]);
   }
   srand(time(NULL)); // supaya hasil acak berbeda tiap kali program dijalankan
   int computer_choice;
   for (int i = 0; i < 3; i++) {
      computer_choice = (rand() % 10); // hasil antara 1-3
   }
   int user_choice;
   printf("Pilihanmu: ");
   scanf("%d", &user_choice);
   if (computer_choice == user_choice) {
      printf("Tie!, Anda dan komputer punya pilihan yang sama\n");
      exit(EXIT_FAILURE); // langsung keluar program
   } else {
      if (computer_choice < user_choice && (computer_choice != 0 || user_choice != 0)) {
         return false;
      } else if (computer_choice > user_choice && (computer_choice != 0 || user_choice != 0)) {
         return true;
      } else if (computer_choice == 0 && user_choice == 2) {
         return true;
      } else if (computer_choice == 2 && user_choice == 0) {
         return false;
      }
   }
}

bool rsp_game() {
   char komponen[][10] = {
      "Batu", // 0
      "Gunting", // 1
      "Kertas" // 2
   };
   printf("Pilih salah satu di antara berikut ini:\n");
   for (int i = 0; i < 3; i++) {
      printf("%d. %s\n", i+1, komponen[i]);
   }
   srand(time(NULL)); // supaya hasil acak berbeda tiap kali program dijalankan
   int computer_choice;
   for (int i = 0; i < 3; i++) {
      computer_choice = (rand() % 10); // hasil antara 1-3
   }
   int user_choice;
   printf("Pilihanmu: ");
   scanf("%d", &user_choice);
   if (computer_choice == user_choice) {
      printf("Tie!, Anda dan komputer punya pilihan yang sama\n");
      exit(EXIT_FAILURE); // langsung keluar program
   } else {
      if (computer_choice < user_choice && (computer_choice != 0 || user_choice != 0)) {
         return false;
      } else if (computer_choice > user_choice && (computer_choice != 0 || user_choice != 0)) {
         return true;
      } else if (computer_choice == 0 && user_choice == 2) {
         return true;
      } else if (computer_choice == 2 && user_choice == 0) {
         return false;
      }
   }
}


void games() {
   char Menu2[][50] = {
      "Rock-Scissor-Paper Game",
      "Finger Game"
   };
   short pilih2;

   printf("\n** MENU GAMES **\n");
   for (int i = 0; i < 2; i++) {
      printf("%d. %s\n", i+1, Menu2[i]);
   }

   printf("Pilihanmu: ");
   scanf("%d", &pilih2);

   if (pilih2 == 1) {
      bool hasil1 = rsp_game();
      if (hasil1 == true) {
         printf("Anda menang!\n");
      } else {
         printf("Komputer menang!\n");
      }
   } else if (pilih2 == 2) {
      bool hasil2 = finger_game();
      if (hasil2 == true) {
         printf("Anda menang!\n");
      } else {
         printf("Komputer menang!\n");
      }
   }
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
         } else {
            if (m == n-1) {
               return true;
            }
         }
         m++;
      }
   }
}


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
            exit(EXIT_FAILURE);
         }
         // simpan faktor baru ke array di posisi terakhir
         faktor[*count-1] = i;
      }
   }
   return faktor; // mengembalikan pointer ke array
}

double kalkulator() {
   double a, b;
   printf("a: ");
   scanf("%lf", &a);
   printf("b: ");
   scanf("%lf", &b);
   char operators[][20] = {
      "Penjumlahan",
      "Pengurangan",
      "Selisih",
      "Perkalian",
      "Pembagian"
   };
   printf("Pilih salah satu operator di bawah ini:\n");
   for (int i = 0; i < 5; i++) {
      printf("%d. %s\n", i+1, operators[i]);
   }
   printf("\n");
   short pilih3;
   printf("Pilihanmu: ");
   scanf("%d", &pilih3);
   if (pilih3 == 1) {
      printf("a + b = %lf\n", jumlah(a, b));
   } else if (pilih3 == 2) {
      printf("a - b = %lf\n", jumlah(a, -b));
   } else if (pilih3 == 3) {
      if (a >= b) {
         printf("|a - b| = %lf\n", jumlah(a, -b));
      } else {
         printf("|a - b| = %lf\n", jumlah(b, -a));
      }
   } else if (pilih3 == 4) {
      printf("a * b = %lf\n", kali(a, b));
   } else if (pilih3 == 5) {
      printf("a / b = %.2lf\n", bagi(a, b));
   }
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
