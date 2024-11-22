#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE* store_data;
    
    store_data = fopen("inventory.txt", "r"); //Membuka txt file untuk dibaca

    int N, i = 0;
    char N_string[11], c;

    while (( c = getc(store_data) ) !='\n' && c != EOF && i < 10){
        N_string[i] = c; //Dapetin jumlah barang yang ada dengan mendapatkan string
        i++;
    }
    N_string[i] = '\0';
    N = atoi(N_string); /*(Number of items (Baris Pertama)*/


    /*----------------------------------------------------DIVIDER-----------------------------------------------------------*/


    if (N > 0){
        printf("List barang yang ada di toko :\n");
        
        for (int j = 0; j < N; j++){

            /*Proses untuk mendapatkan angka untuk harga dengan cara seperti ini*/ 
            char hargaItem_arr[11], c_price, c_name;
            int i_harga = 0;

            while (( c_price = getc(store_data) ) != ' ' && c_price != EOF && i_harga < 10){ /*Akan disimpan char dari string sampai ketemu spasi(karena angka gamungkin dipisah spasi)*/
                hargaItem_arr[i_harga] = c_price;
                i_harga++;
            }

            hargaItem_arr[i_harga] = '\0'; /*Menutup string dengan NULL agar string valid!*/
            int hargaItem = atoi(hargaItem_arr);


            /*----------------------------------------------------DIVIDER-----------------------------------------------------------*/


            /*Dengan proses yang sama untuk melanjutkan mendaptkan string nama item*/

            int i_name = 0;
            char itemName[51];

            while (( c_name = getc(store_data) ) != '\n' && c_name != EOF && i_name < 50){
                itemName[i_name] = c_name;
                i_name++;
            }
            itemName[i_name] = '\0';


            /*----------------------------------------------------DIVIDER-----------------------------------------------------------*/
            

            printf("- %d %s\n", hargaItem, itemName);
        }
    }

    else{
        printf("TOKO KOSONG\n");
    }
    fclose(store_data);
    return 0;
}