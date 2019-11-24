#ifndef _ART_H
#define _ART_H

void clrscr();
    /*
    Melakukan clear pada layar sehingga layar kosong 
    I.S.
        Sembarang
    F.S.
        Layar kosong
    */

void AddWarning(const char* w);
    /*
    Memasukkan pesan peringatan untuk ditampilkan oleh DisplayWarning()
    I.S.
        Kondisi Sembarang
    F.S.
        string pesan disalin ke variabel dan dapat ditampilkan
    */

void DisplayWarning();
    /*
    Menampilkan pesan peringatan yang telah diatur oleh AddWarning()
    I.S.
        pesan peringatan sudah diatur menggunakan prosedur AddWarning
    F.S.
        pesan peringatan ditampilkan di layar
    */

void DisplayTitle();
    /*
    I.S.
        Kondisi sembarang
    F.S.
        Judul program ukuran besar ditampilkan di layar
    */

void DisplayTitleMini();
    /*
    I.S.
        Kondisi sembarang
    F.S.
        Judul program ukuran kecil ditampilkan di layar
    */

void DisplayMainMenu();
    /*
    I.S.
        Kondisi sembarang
    F.S.
        Main menu ditampilkan di layar
    */

void DisplayPrompt(const char* info);
    /*
    I.S.
        Kondisi sembarang
    F.S.
        Menampilkan prompt (pesan dengan background kuning) pada layar
    */

void SetPlayerPrompt(int p);
    /*
    I.S.
        Kondisi sembarang
    F.S.
        nilai p disimpan untuk digunakan dalam pemanggilan DisplayPrompt2, 1 untuk player 1, dan 2 untuk player 2
    */

void DisplayPrompt2(const char* info);
    /*
    I.S.
        Kondisi sembarang, telah dipanggil prosedur SetPlayerPrompt
    F.S.
        Menampilkan prompt biru jika sebelumnya dipanggil SetPlayerPrompt(1), 
        Menampilkan prompt merah jika sebelumnya dipanggil SetPlayerPrompt(2). 
    */

#endif
