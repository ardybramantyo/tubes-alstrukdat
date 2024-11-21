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

void StoreSupply(){
    
    if (!isEmpty(requestQueue)){
        char input[51], c_input;
        int i = 0;

        ElType val;
        dequeue(&requestQueue, &val);
        
        printf("Apakah kamu ingin menambahkan barang %s:", val);
        while ((c_input = getc(stdin)) != '\n' && i < 50){
            input[i] = c_input;
            i++;
        }
        input[i] ='\0';

        if (is_same_string(input, "Terima")){
            i = 0;
            char inputHarga_String[11], c_inputHarga;

            while ((c_inputHarga = getc(stdin)) != '\n' && i < 11){
                inputHarga_String[i] = c_inputHarga;
                i++;
            }
            inputHarga_String[i] = '\0';
            int inputHarga = atoi(inputHarga_String);


                if (inputHarga <= 0){
                    printf("Harga barang tidak valid, silahkan mengulang kembali!");
                }

                else{   
                    /*LANJUTKAN NANTI .... --> Pengen di loop untuk nerima getc(stdin), tapi untuk sekarang ini dlu :D, biar bisa mulai*/
                }

            /*------------------------------------------------------DIVIDER--------------------------------------------------------*/
            FILE* store_data;
            store_data = fopen("inventory.txt", "r");

            int N_Store;
            i = 0;
            char N_Store_String[11], c;
        
            while ( (c = getc(store_data)) != '\n'  &&  c != EOF  &&  i < 11){
                N_Store_String[i] = c;
                i++;
            }
            N_Store_String[i] = '\0';
            N_Store = atoi(N_Store_String);

            /*------------------------------------------------------DIVIDER--------------------------------------------------------*/


            FILE* store_data_temp;
            store_data_temp = fopen("inventory.txt", "w");

            char arrTxt[1024];
            int c_arrTxt;
            i = 0;
            while ( (c_arrTxt = getc(store_data)) != EOF){
                arrTxt[i] = c_arrTxt;
                i++; 
            }
            arrTxt[i] = '\0';
            
            closef(store_data);
            
            int line_number = 0, index = 0;
            while (arrTxt[index] != '\0'){
                line_number++;

                int index_line_first = index;
                while (arrTxt[index] != '\n' && arrTxt[index] != '\0'){
                    index++;
                }
                int index_line_last = index;

                /*------------------------------------------------------DIVIDER--------------------------------------------------------*/


                char arrTxt_line[1024];
                int index_line_length = index_line_last - index_line_first;
                for (int j = 0; j < (index_line_length); j++){
                    arrTxt_line[j] = arrTxt[index_line_first + j];
                }
                arrTxt_line[index_line_length] = '\0';

                /*------------------------------------------------------DIVIDER--------------------------------------------------------*/

                
                if (line_number == 1){
                    fprintf(store_data_temp, "%d\n", (N_Store + 1));
                }

                else if (line_number == N_Store){
                    fprintf(store_data_temp, "%s\n", arrTxt_line);
                    fprintf(store_data_temp, "%d %s\n", inputHarga, val);
                }

                else{
                    fprintf(store_data_temp,"%s\n", arrTxt_line);
                }
            }

            closef(store_data_temp);

            remove("inventory.txt");
            rename("temp.txt", "inventory.txt");  
            }


            /*------------------------------------------------------DIVIDER--------------------------------------------------------*/



        else if (is_same_string(input, "Tunda")){
            enqueue(&requestQueue, val);
            printf("%s dikembalikan ke antrean", val);
        }

        else if (is_same_string(input, "Tolak")){

        }

        else{

        }
    }

}