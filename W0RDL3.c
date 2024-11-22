#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
      int panjangkata = 5;
      int prize = 1500;
      int chances = 5;
      char words[8][6] = {"TUGAS", "SUSAH", "TIDAK", "JELAS", "MABOK", "CUKUP", "LELAH", "KACAU"};
    
      char answer[6];
      srand(time(NULL));
      int randomIndex = rand() % 8;
      for (int i = 0; i < 6; i++) {
            answer[i] = words[randomIndex][i];
      }
      printf("%s", answer);
    
      printf("\n");
    
    

      printf("WELCOME TO W0RDL3, YOU HAVE 5 CHANCES TO ANSWER BEFORE YOU LOSE!\n");
    
    
      // deklarasi matriks
      char guess[2][chances][panjangkata];
      for (int i = 0; i < chances; i++) {
            for (int j = 0; j < panjangkata; j++) {
                  guess[0][i][j] = '_';
                  guess[1][i][j] = ' ';
                  for (int k = 0; k < 2; k++) {
                        printf("%c", guess[k][i][j]);
                  }
                  printf(" ");
            }
            printf("\n");
      }
    

    
      for (int try = 0; try < chances; try++) {
            char tebak[6];
            printf("Masukan kata tebakan Anda: \n");
            scanf("%s", tebak);
            printf("%s", tebak);
            printf("Hasil:\n");
        
        
            for (int i = 0; i < panjangkata; i++) {
                  guess[0][try][i] = tebak[i];
                  //anggep salah semua, tambah %
                  guess[1][try][i] ='%';
                  //kalo ada hurufnya tambah *
                  for (int j = 0; j < panjangkata; j++) {
                        if (tebak[i] == answer[j]) {
                              guess[1][try][i] = '*';
                        }
                  }
                  //kalo hurufnya bener tempat hilangin
                  if (tebak[i] == answer[i]) {
                        guess[1][try][i] =' ';
                  }
            }
        
        
            for (int i = 0; i < chances; i++) {
                  for (int j = 0; j < panjangkata; j++) {
                        for (int k = 0; k < 2; k++) {
                              printf("%c", guess[k][i][j]);
                        }
                        printf (" ");
                  }
                  printf("\n");
            }
            // jika menang
        
            int tebakBener = 1;
            for (int i = 0; i < panjangkata; i ++) {
                  if (guess[1][try][i] != ' ') {
                        tebakBener = 0;
                  }
            }
            if (tebakBener == 1) {
                  printf("Selamat, Anda menang!\n");
                  printf("+%d rupiah telah ditambahkan ke akun Anda.\n", prize);
                  return 0;
            }
      }
    
      printf("Boo! Anda kalah.");
      return 0;
}
