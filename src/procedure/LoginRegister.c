#include <stdio.h>
#include "../boolean.h"
#include "../adt/Mesin Kata/MesinKata.h"
#include "../adt/Mesin Karakter/MesinKarakter.h"
#include "../adt/User/User.h"

ListUser USERS;

boolean BandingString(const char *String1, const char *String2){
    int Indeks;
    while (String1[Indeks] != '\0' && String2[Indeks] != '\0'){
        if (String1[Indeks] != String2[Indeks]){
            return false;
        }
        Indeks++;
    }

    return (String1[Indeks] == '\0' && String2[Indeks] == '\0');
}

void CopyString(char *Hasil, const char *Input, int Panjang){
    int Indeks;
    for (Indeks = 0; Indeks < Panjang; Indeks++){
        Hasil[Indeks] = Input[Indeks];
    }
    Hasil[Panjang] = '\0';
}

int UsernameAda(const char *Input){
    int Indeks;
    int Ada = 0;
    for (Indeks = 0; Indeks < USERS.lengthEff; Indeks++){
        if (BandingString(USERS.ElUser[Indeks].name, Input)){
            Ada = 1;
            return (Indeks);
        }
    }
    return (Ada);
}

void Login(){
    char Username[MAX_USER_NAME];
    char Password[MAX_USER_PASS];
    int Money;
    int indeksUser;

    printf("== Login ==\n");
    printf("Masukkan Username: \n");
    startKata();
    salinKata();
    CopyString(Username, currentKata.buffer, currentKata.length);    

    printf("Masukkan Password: \n");
    startKata();
    salinKata();
    CopyString(Password, currentKata.buffer, currentKata.length); 

    if (UsernameAda(Username) == 0){
        printf("Username tidak ditemukan\n");
    }

    else if (UsernameAda(Username) != 0){
        indeksUser = UsernameAda(Username);
        if (BandingString(USERS.ElUser[indeksUser].password, Password)){
            printf("Login Berhasil!, Selamat Datang Kembali! %s\n", Username);
        }
        else {
            printf("Password salah\n");
        }
    }
}

void Register(){
    char Username[MAX_USER_NAME];
    char Password[MAX_USER_PASS];
    int Money = 1000;
    User userBaru;

    printf("== Register ==\n");
    printf("Masukkan Username: \n");
    startKata();
    salinKata();
    CopyString(Username, currentKata.buffer, currentKata.length);

    if (UsernameAda(Username) == 0){
        printf("Masukkan Password: \n");
        startKata();
        salinKata();
        CopyString(Password, currentKata.buffer, currentKata.length);
        userBaru = createUser(Username, Password, Money);
        addUser(&USERS,userBaru);
        printf("Registrasi Selesai!\n");
    }

    else if (UsernameAda(Username) != 0){
        printf("Username sudah digunakan, coba lagi\n");
    }
}