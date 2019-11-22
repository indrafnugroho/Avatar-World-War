#include <stdio.h>
#include "CharProcessor/CharProcessor.h"

int test;
int succeedCounter;

void start_test(const char* name) {
    test++;
    printf("Memulai tes %d: %s\n", test, name);
    printf("--------------------------------------------\n");
}

void end_test() {
    printf("--------------------------------------------\n");
    printf("Tes %d berhasil diselesaikan.\n", test);
    printf("\n");
    succeedCounter++;
}

void print_result() {
    printf("Telah dilaksanakan %d tes, semuanya berhasil!\n", test);
}

int main() {

    test = 0;
    succeedCounter = 0;

    printf("Driver CharProcessor (Mesin Karakter)\n\n");

    // --------------------------------------------------------------------------------

    // bool START(char* path);
    /* Mesin siap dioperasikan. Pita disiapkan untuk membaca dari file atau dari stdin.
    Jika path = NULL, mesin membaca dari stdin.
    Karakter pertama yang ada pada pita posisinya adalah pada jendela.
    Mengembalikan false jika file pada path gagal dibaca, true jika berhasil.
    I.S. : sembarang
    F.S. : CC adalah karakter pertama pada pita
            Jika EOF maka EOP akan bernilai true 
            Jika tidak maka EOP akan bernilai false */

    // --------------------------------------------------------------------------------

    start_test("Mulai mesin karakter dari file.");
    // Isi Parameter Fungsi:
    // path = "config.txt"

    bool res = START("config.txt");
    if (res) {
        printf("Berhasil membaca dari file.\n");
    } else {
        printf("Gagal membaca dari file.\n");
    }

    end_test();
    
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

    start_test("Mulai mesin karakter dari stdin.");
    // Isi Parameter Fungsi:
    // path = NULL

    printf("Masukkan input: ");
    res = START(NULL);
    if (res) {
        printf("Berhasil membaca dari stdin.\n");
    } else {
        printf("Gagal membaca dari stdin.\n");
    }

    end_test();

    // --------------------------------------------------------------------------------

    // void ADV();
    /* Pita dimajukan satu karakter.
    I.S. : Karakter pada jendela = CC, !EOP
    F.S. : CC adalah karakter berikutnya dari CC yang lama,
            Jika EOF maka EOP akan bernilai true*/

    // --------------------------------------------------------------------------------

    start_test("Lihat karakter yang sedang dibaca lalu karakter berikutnya");
    // Mesin karakter dalam mode membaca masukan pengguna.

    printf("Karakter yang sedang dibaca: '%c'\n", CC);
    ADV();
    printf("Karakter yang sedang dibaca setelah ADV: '%c'\n", CC);

    end_test();

    // --------------------------------------------------------------------------------

    print_result();
}