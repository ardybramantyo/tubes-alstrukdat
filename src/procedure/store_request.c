#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "circular_queue.h"

int Uppercased_Char(int num){
    if (num >= 'a' && num <= 'z'){
        return (num - 32);
    }

    return num;
}

boolean is_same_string(const char str1[], const char str2[]){
    int i = 0;
        
    while (str1[i] != '\0' && str2[i] != '\0'){
        if (Uppercased_Char(str1[i]) != Uppercased_Char(str2[i])){
            return false;
        }
        i++;
    }
    return (str1[i] == '\0' && str2[i] == '\0');
}
/*----------------------------------------------------DIVIDER-----------------------------------------------------------*/


void StoreRequest(){
    char item_name_request[51], c_item_name_req;
    int i = 0;

    printf("Masukkan nama item:\n");
    while ((c_item_name_req = getc(stdin)) != '\n' && i < 50){
        item_name_request[i] = c_item_name_req;
        i++;
    }
    item_name_request[i] ='\0';

    /*----------------------------------------------------DIVIDER-----------------------------------------------------------*/

    if (isEmpty(requestQueue)){
        enqueue(&requestQueue, item_name_request);
    }

    /*----------------------------------------------------DIVIDER-----------------------------------------------------------*/

    else{
        Queue temp;
        CreateQueue(&temp);
        ElType val;

        int Mark_Antrean = 0, Mark_Supply = 0;
        while (!isEmpty(requestQueue)){
            dequeue(&requestQueue, &val);
            enqueue(&temp, val);
        }

        while (!isEmpty(temp)){
            dequeue(&temp, &val);
            if (is_same_string(item_name_request, val)){
                Mark_Antrean++;
            }
            enqueue(&requestQueue, val);
        }
        
        /*Mengecek apakah nama tersebut ada pada queue*/

        /*----------------------------------------------------DIVIDER-----------------------------------------------------------*/

        FILE* store_data;
        store_data = fopen("inventory.txt", "r");

        int N;
        i = 0;
        char N_String[11], c;
        
        while ( (c = getc(store_data)) != '\n'  &&  c != EOF  &&  i < 11){
            N_String[i] = c;
            i++;
        }
        N_String[i] = '\0';
        N = atoi(N_String);

        if (N > 0){
            for (int j = 0; j < N; j++){
                i = 0;
                char hargaItem_Arr[11], c_hargaItem;

                while ( (c_hargaItem = getc(store_data)) != ' '  &&  c_hargaItem != EOF && i < 11){
                    hargaItem_Arr[i] = c;
                    i++;
                }
                hargaItem_Arr[i] = '\0';
                int hargaItem = atoi(hargaItem_Arr);

                /*-----------------------------------------------DIVIDER------------------------------------------------------*/
                i = 0;
                char item_name_store[51], c_item_name_store;

                while ( (c_item_name_store = getc(store_data)) != '\n'  &&  c_item_name_store != EOF && i < 51){
                    item_name_store[i] = c_item_name_store;
                    i++;
                }
                item_name_store[i] = '\0';

                /*Meskipun hanya memakai item_name, tetap perlu diambil harga_item untuk memisahkannya*/
        
                if (is_same_string(item_name_request, item_name_store)){
                    Mark_Supply++;
                }
            }
        }

        /*Mengecek apakah nama tersebut ada pada store*/

        /*----------------------------------------------------DIVIDER-----------------------------------------------------------*/


        if (Mark_Supply != 0){
            printf("Barang dengan nama yang sama sudah ada di toko!\n");
        }

        else if (Mark_Antrean != 0){
            printf("Barang dengan nama yang sama sudah ada di antrean!\n");
        }

        else{
            enqueue(&requestQueue, item_name_request);
            printf("Barang berhasil ditambahkan di antrean\n");
        }
    }
}