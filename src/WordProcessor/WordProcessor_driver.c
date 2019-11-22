#include <stdio.h>
#include "WordProcessor/WordProcessor.h"

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

    printf("Driver WordProcessor (Mesin Kata)\n\n");

    // --------------------------------------------------------------------------------

    // void CreateEmpty(Word* w);
    
    // --------------------------------------------------------------------------------

    start_test("Bikin Word kosong.");
    // Isi parameter:
    // w = &w

    Word w;
    CreateEmpty(&w);
    printf("Berhasil buat Word kosong!\n");

    end_test();

    // --------------------------------------------------------------------------------

    // bool STARTWORD(char* path);
    /* I.S. : CC sembarang
    F.S. : Jika gagal membaca file pada path, mengembalikan false.
            Jika berhasil, mengembalikan true dan:
                EndWord = true, dan CC = MARK;
                atau EndWord = false, CWord adalah kata yang sudah diakuisisi,
                CC karakter pertama sesudah karakter terakhir kata */

    // --------------------------------------------------------------------------------

    start_test("Mulai baca kata dari pengguna.");
    // Isi parameter:
    // path = NULL

    printf("Masukkan input dengan lebih dari satu kata: ");
    STARTWORD(NULL);
    printf("Berhasil mulai baca kata dari pengguna!\n");

    end_test();

    // --------------------------------------------------------------------------------

    // void IgnoreBlank();
    /* Mengabaikan satu atau beberapa BLANK
    I.S. : CC sembarang
    F.S. : CC ≠ BLANK atau CC = MARK */
    
    // --------------------------------------------------------------------------------

    start_test("Pengujian IgnoreBlank.");

    printf("Karakter yang sedang dibaca: '%c'\n", CC);
    IgnoreBlank();
    printf("Karakter yang sedang dibaca setelah IgnoreBlank: '%c'\n", CC);

    end_test();

    // --------------------------------------------------------------------------------

    // void SalinWord();
    /* Mengakuisisi kata, menyimpan dalam CWord
    I.S. : CC adalah karakter pertama dari kata
    F.S. : CWord berisi kata yang sudah diakuisisi;
            CC = BLANK atau CC = MARK;
            CC adalah karakter sesudah karakter terakhir yang diakuisisi.
            Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

    // void ADVWORD();
    /* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
    F.S. : CWord adalah kata terakhir yang sudah diakuisisi,
            CC adalah karakter pertama dari kata berikutnya, mungkin MARK
            Jika CC = MARK, EndKata = true.
    Proses : Akuisisi kata menggunakan procedure SalinKata */

    // Diuji bersamaan karena SalinWord dijalankan dengan aman dalam fungsi ADVWORD()
                
    // --------------------------------------------------------------------------------

    start_test("Lihat kata yang sedang dibaca, kemudian kata selanjutnya");

    printf("Kata yang sedang dibaca: '"); WriteWord(CWord); printf("'\n");
    ADVWORD();
    printf("Kata yang sedang dibaca setelah ADVWORD: '"); WriteWord(CWord); printf("'\n");

    end_test();

    // --------------------------------------------------------------------------------

    // void WriteWord(Word w);
    /* Mencetak suatu Word w ke layar.
    I.S. : w terdefinisi
    F.S. : w tercetak di layar */
                
    // --------------------------------------------------------------------------------

    start_test("Tulis kata yang sedang dibaca.");
    // Isi parameter:
    // w = CWord

    printf("Kata yang sedang dibaca: '"); WriteWord(CWord); printf("'\n");

    end_test();

    // --------------------------------------------------------------------------------

    // void PrintWord(Word w);
    /* Mencetak suatu Word w ke layar diakhiri dengan simbol \n.
    I.S. : w terdefinisi
    F.S. : w tercetak di layar diakhiri simbol \n */
                
    // --------------------------------------------------------------------------------

    start_test("Print kata yang sedang dibaca.");
    // Isi parameter:
    // w = CWord

    printf("Kata yang sedang dibaca: "); PrintWord(CWord);

    end_test();

    // --------------------------------------------------------------------------------

    // void ScanString(char* to, int limit);
    /* Menerima suatu string dari pengguna dengan batasan panjang limit-1.
    Batasannya limit-1 karena satu char digunakan untuk simbol \0 sebagai penanda akhir string.
    I.S. : to terdefinisi sebagai array of char dengan ukuran >= limit
    F.S. : to diisi karakter sebanyak limit (termasuk penanda \0) */
                
    // --------------------------------------------------------------------------------

    start_test("Baca string masukan pengguna dengan panjang maksimal 49 karakter.");
    // Isi parameter:
    // to = inway
    // limit = 50

    printf("Masukkan string maksimal 49 karakter: ");
    char inway[50];
    ScanString(inway, 50);
    printf("Hasil bacaan: %s\n", inway);

    end_test();

    // --------------------------------------------------------------------------------

    // void ScanWord(Word* to);
    /* Menerima masukan satu kata (berhenti pada spasi atau newline).
    I.S. : to sembarang
    F.S. : to terdefinisi, berisi satu kata masukan pengguna */
                
    // --------------------------------------------------------------------------------

    start_test("Baca suatu kata, simpan ke variabel A.");
    // Isi parameter:
    // to = &A;

    printf("Masukkan satu kata: ");
    Word A;
    ScanWord(&A);
    printf("Kata yang terbaca: '"); WriteWord(A); printf("'\n");

    end_test();

    // --------------------------------------------------------------------------------

    // bool ScanInt(int* to);
    /* Menerima masukan suatu angka integer yang ditulis pengguna.
    Mengembalikan true jika berhasil membaca suatu integer, mengembalikan false jika tidak.
    I.S. : to sembarang
    F.S. : to menjadi angka yang ditulis pengguna */
                
    // --------------------------------------------------------------------------------

    start_test("Baca suatu kata yang memiliki nilai.");
    // Isi parameter:
    // to = &a

    printf("Masukkan suatu angka: ");
    int a;
    ScanInt(&a);
    printf("Dua kali angka tersebut: %d\n", a*2);

    end_test();

    // --------------------------------------------------------------------------------

    // bool WordToInt(Word w, int* i);
    /* Mengubah suatu Word w menjadi nilai integer pada i.
    Mengembalikan true jika konversi berhasil, false jika gagal.
    I.S. : w terdefinisi, i sembarang
    F.S. : Jika berhasil:
                i menjadi nilai yang tersimpan pada w,
                Fungsi mengembalikan true
            Jika gagal:
                i tidak berubah
                Fungsi mengembalikan false */
                
    // --------------------------------------------------------------------------------

    start_test("Ubah Word menjadi integer.");
    // Isi parameter:
    // w = A
    // i = &a

    printf("Masukkan suatu angka: ");
    ScanWord(&A);
    WordToInt(A, &a);
    printf("Lima kali nilai tersebut: %d\n", 5*a);

    end_test();

    // --------------------------------------------------------------------------------

    // void CopyWord(Word from, Word* to);
    /* Menyamakan tiap karakter pada to dengan tiap karakter pada from.
    I.S. : from terdefinisi, to sembarang
    F.S. : to berisi karakter yang sama dengan pada from */
                
    // --------------------------------------------------------------------------------

    start_test("Salin sebuah Word ke variabel Word lain.");
    // Isi parameter:
    // from = A
    // to = &B

    printf("Masukkan satu kata: ");
    ScanWord(&A);
    Word B;
    CopyWord(A, &B);
    printf("Isi B: '"); WriteWord(B); printf("'\n");

    end_test();

    // --------------------------------------------------------------------------------

    // bool WordEquals(Word a, Word b);
    /* Mengembalikan true jika tiap karakter a sama dengan tiap karakter b, false jika tidak.
    I.S. : a dan b terdefinisi.
    F.S. : Mengembalikan true jika tiap karakter a sama dengan tiap karakter b, false jika tidak. */
                
    // --------------------------------------------------------------------------------

    start_test("Cek apakah suatu Word kontennya sama dengan suatu Word lain.");
    // Isi parameter:
    // a = A
    // b = B

    printf("Masukkan \"skuy\": ");
    ScanWord(&A);
    printf("Masukkan \"skuy\" lagi: ");
    ScanWord(&B);
    if (WordEquals(A, B)) {
        printf("skuybrader\n");
    } else {
        printf("Input anda tidak sesuai, tapi yaudahlayah\n");
    }

    end_test();

    // --------------------------------------------------------------------------------

    // bool WordEqualsString(Word a, char* s);
    /* Mengembalikan true jika tiap karakter a sama dengan tiap karakter pada string s, false jika tidak.
    I.S. : a dan b terdefinisi.
    F.S. : Mengembalikan true jika tiap karakter a sama dengan tiap karakter pada string s, false jika tidak. */
                
    // --------------------------------------------------------------------------------

    start_test("Cek apakah suatu Word kontennya sama dengan suatu string.");
    // Isi parameter:
    // a = A
    // b = "skuy"

    printf("Masukkan \"skuy\" lagi: ");
    ScanWord(&A);
    if (WordEqualsString(A, "skuy")) {
        printf("skuybrader\n");
    } else {
        printf("Input anda tidak sesuai, tapi yaudahlayah\n");
    }

    end_test();

    // --------------------------------------------------------------------------------

    // bool ReadStart(char* path);
    /* Mulai membaca dari suatu file. WAJIB DIGUNAKAN SEBELUM MEMAKAI FUNGSI-FUNGSI READ.
    Mengembalikan true jika berhasil membaca dari file tersebut, mengembalikan false jika gagal.
    I.S. : path terdefinisi sebagai alamat file yang ingin dibaca
    F.S. : WordProcessor terkonfigurasi untuk membaca file dari alamat tersebut */
                
    // --------------------------------------------------------------------------------

    start_test("Mulai membaca dari config.txt.");
    // Isi parameter:
    // 

    ReadStart("config.txt");
    printf("Berhasil mulai membaca dari 'config.txt'!\n");

    end_test();

    // --------------------------------------------------------------------------------

    // void ReadWord(Word* to);
    /* Membaca satu kata dari file yang sedang dibaca (berhenti pada spasi atau newline).
    I.S. : to sembarang
    F.S. : to terdefinisi, berisi satu kata masukan pengguna */
                
    // --------------------------------------------------------------------------------

    start_test("Baca kata atau angka dari config.txt.");
    // Isi parameter:
    // to = &A

    ReadWord(&A);
    printf("Yang terbaca: '"); WriteWord(A); printf("'\n");

    end_test();

    // --------------------------------------------------------------------------------

    // bool ReadInt(int* to);
    /* Membaca satu integer dari file yang sedang dibaca.
    Mengembalikan true jika berhasil membaca suatu integer, mengembalikan false jika tidak.
    I.S. : to sembarang
    F.S. : to menjadi angka yang ditulis pengguna */
                
    // --------------------------------------------------------------------------------

    start_test("Baca suatu angka dari config.txt.");
    // Isi parameter:
    // to = &a

    ReadInt(&a);
    printf("Yang terbaca: %d\n", a);
    printf("Dua kali yang terbaca: %d\n", 2*a);

    end_test();

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

    start_test("Baca suatu angka lagi dari config.txt.");
    // Isi parameter:
    // to = &a

    ReadInt(&a);
    printf("Yang terbaca: %d\n", a);
    printf("Tiga kali yang terbaca: %d\n", 3*a);

    end_test();

    // --------------------------------------------------------------------------------

    // void ReadLine(char* to, int limit);
    /* Membaca satu baris dari file yang sedang dibaca dengan batasan panjang limit-1.
    Batasannya limit-1 karena satu char digunakan untuk simbol \0 sebagai penanda akhir suatu string.
    I.S. : to terdefinisi sebagai array of char dengan ukuran >= limit
    F.S. : to diisi karakter sebanyak limit (termasuk penanda \0) */

    // --------------------------------------------------------------------------------

    start_test("Baca suatu baris maksimal 49 karakter.");
    // Isi parameter:
    // to = inway
    // limit = 50

    ReadStart("config.txt");
    ReadLine(inway, 50);
    printf("Yang terbaca: %s\n", inway);

    end_test();

    // --------------------------------------------------------------------------------

    print_result();
}