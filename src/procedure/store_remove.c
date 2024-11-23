#include <stdio.h>
#include "ArrayDin.h"
#include "Barang.h"
#include "mesinkata.h"

void store_remove(ArrayDin *arr) {
    char hapusItem[MAX_BARANG_LEN];

    printf("Nama barang yang akan dihapus: ");
    startKata(); 
    salinKata();
    CopyString(hapusItem, currentKata.buffer, currentKata.length);

    int found = -1; // Indeks barang dalam array
    for (int i = 0; i < getArrayDinLength(*arr); i++) {
        Barang currentBarang = getArrayDinElmt(*arr, i);
        if (BandingString(currentBarang.name, hapusItem)) {
            found = i;
            break;
        }
    }

    if (found != -1) {
        ArrayDinDeleteElem(arr, found);
        printf("%s telah berhasil dihapus.\n", hapusItem);
    } else {
        printf("Toko tidak menjual %s\n", hapusItem);
    }
}
