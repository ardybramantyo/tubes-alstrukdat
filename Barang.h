#ifndef BARANG_H
#define BARANG_H

#define MAX_BARANG_LEN 100

typedef struct
{
    char name[MAX_BARANG_LEN];
    int price;
} Barang;

void setBarangName(Barang* barang, const char* name);
void setBarangPrice(Barang* barang, int price);

Barang createBarang(const char* name, int price);

#endif
