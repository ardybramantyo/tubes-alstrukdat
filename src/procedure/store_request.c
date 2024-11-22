#include <stdio.h>
#include <stdlib.h>
#include <string.h> /*DIPERTANYAKAN*/
#include "boolean.h"
#include "Queue.h"
#include "ArrayDin.h"
#include "Barang.h"
#include "MesinKata.h"

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


void StoreRequest(ArrayDin arr){
    printf("Masukkan nama item:\n");

    startKata(NULL);

    char item_name_request[currentKata.length +1];
    strcpy(item_name_request, currentKata.buffer); /*DIPERTANYAKAN*/

    /*----------------------------------------------------DIVIDER-----------------------------------------------------------*/

    if (isEmpty(requestQueue)){
        enqueue(&requestQueue, &item_name_request);
    }

    /*----------------------------------------------------DIVIDER-----------------------------------------------------------*/

    else{
        Queue temp;
        initQueue(&temp);
        char* val;

        int Mark_Antrean = 0, Mark_Supply = 0;
        while (!isEmpty(requestQueue)){
            val = dequeue(&requestQueue);
            enqueue(&temp, val);
        }

        while (!isEmpty(temp)){
            val = dequeue(&temp);
            if (is_same_string(item_name_request, val)){
                Mark_Antrean++;
            }
            enqueue(&requestQueue, val);
        }
        
        /*Mengecek apakah nama tersebut ada pada queue*/

        /*----------------------------------------------------DIVIDER-----------------------------------------------------------*/
        int N = getArrayDinLength(arr);

        if (N > 0){
            for (int j = 0; j < N; j++){
                Barang storelist = getArrayDinElmt(arr,i);
                
                if (is_same_string(item_name_request, storelist.name)){
                    Mark_Supply++;
                }
            }
            /*Meskipun hanya memakai item_name, tetap perlu diambil harga_item untuk memisahkannya*/  
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
            enqueue(&requestQueue, &item_name_request);
            printf("Barang berhasil ditambahkan di antrean\n");
        }
    }
}
