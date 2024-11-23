#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "MesinKata.h"
#include "MesinKarakter.h"
#include "boolean.h"

// https://www.tutorialspoint.com/c_standard_library/time_h.htm
// MAKRO time.h
// NULL - Indef

// ASCII A - Z : 65 - 90
// ASCII a - z : 97 - 122

// Function Buat Waktu Tunggu
void Jeda(int Detik){
    time_t Waktu;
    Waktu = time(NULL);
    
    while (time(NULL) - Waktu < Detik){
        // Loop sampe detik
    }
}

// Function Ngebanding Karakter/Huruf
boolean BandingHuruf(Kata Inp, char *String){
    int Counter = 0;
    char CharInput;
    char CharString;
    while (Counter < Inp.length && String[Counter] != '\0'){
        CharInput = Inp.buffer[Counter];
        CharString = String[Counter];

        if (CharInput >= 'A' && CharInput <= 'Z'){
            CharInput = CharInput + 32;
        }
        if (CharString >= 'A' && CharString <= 'Z'){
            CharString = CharString + 32;
        }

        if (CharInput != CharString){
            return false;
        }
        Counter++;
    }
    return (Counter == Inp.length && String[Counter] == '\0');
}

// Function NgebandingKata
// boolean BandingKata(Kata Inp){
//     return (BandingHuruf(Inp, "Evil Lab Assistant") || 
//             BandingHuruf(Inp, "OWCA Hiring Manager") || 
//             BandingHuruf(Inp, "Cikapundunginator Caretaker") || 
//             BandingHuruf(Inp, "Mewing Specialist") || 
//             BandingHuruf(Inp, "Inator Connoisseur")
//             );
// }

// Temporary, Buat Keluar Work
// boolean CekSelesai(Kata Inp){
//     return (BandingHuruf(Inp, "Selesai"));
// }

// Belom gua tes programnya

void Work(){
    FILE* asdf;
    asdf = fopen("aa.txt","r");
    //
    printf("Daftar Pekerjaan:\n");
    printf("1. Evil Lab Assistant (pendapatan=100, durasi=14s)\n");
    printf("2. OWCA Hiring Manager (pendapatan=4200, durasi=21s)\n");
    printf("3. Cikapundunginator Caretaker (pendapatan=7000, durasi=30s)\n");
    printf("4. Mewing Specialist (pendapatan=10000, durasi=22s)\n");
    printf("5. Inator Connoisseur (pendapatan=997, durasi=15s)\n");
    printf("\n");
    printf("Masukkan pekerjaan yang dipilih: ");

    startKata(*asdf);    
    printf("\n");
    // misal program selesai pake "Selesai"
    while (!BandingHuruf(currentKata, "Selesai")){
        if (BandingHuruf(currentKata, "Evil Lab Assistant")){
            printf("Anda bekerja sebagai Evil Lab Assistant, Menunggu gaji turun :3...\n");
            Jeda(14);
            printf("Horee gaji sudah turun! 100 Rupiah sudah ditambahkan ke akun anda :D\n");
        }
        else if (BandingHuruf(currentKata, "OWCA Hiring Manager")){
            printf("Anda bekerja sebagai OWCA Hiring Manager, Menunggu gaji turun :3...\n");
            Jeda(21);
            printf("Horee gaji sudah turun! 4200 Rupiah sudah ditambahkan ke akun anda :D\n");
        }
        else if (BandingHuruf(currentKata, "Cikapundunginator Caretaker")){
            printf("Anda bekerja sebagai Cikapundunginator Caretaker, Menunggu gaji turun :3...\n");
            Jeda(30);
            printf("Horee gaji sudah turun! 7000 Rupiah sudah ditambahkan ke akun anda :D\n");
        }
        else if (BandingHuruf(currentKata, "Mewing Specialist")){
            printf("Anda bekerja sebagai Mewing Specialist, Menunggu gaji turun :3...\n");
            Jeda(22);
            printf("Horee gaji sudah turun! 10000 Rupiah sudah ditambahkan ke akun anda :D\n");
        }
        else if (BandingHuruf(currentKata, "Inator Connoisseur")){
            printf("Anda bekerja sebagai Inator Connoisseur, Menunggu gaji turun :3...\n");
            Jeda(15);
            printf("Horee gaji sudah turun! 997 Rupiah sudah ditambahkan ke akun anda :D\n");
        }
        else {
            printf("Tolong input sesuai yang ada di daftar, gausah ngadi-ngadi soalnya emang itu doang :(\n");
        }
        startKata(*asdf);
    }

    printf("Sampai Jumpa :D\n");

}

int main(){
    Work();
    return 0;
}