#include "GameState.h"

/******** GAME STATE ********/
void CaptureFirstGameState(GameState* G) {
    /* Mengakuisisi game state pertama setelah memulai turn */
}

void CaptureGameState(GameState* G, Player* P) {
    /* Mengakuisisi game state saat prosedur dijalankan */
}

/******** GAME STACK ********/
void CreateGameStack(GameStack* GS) {
    /* IS: Kondisi GameStack sembarang */
    /* FS: Terbentuk GameStack kosong */
}

bool GameStackIsEmpty(GameStack GS) {
    /* Mengecek kondisi stack */
}

void PushGameState(GameStack* GS, GameState G) {
    /* Push game state ke stack setiap command selesai dijalankan */
}

void PopGameState(GameStack* GS, GameState* G) {
    /* Pop game state terakhir yang disimpan di stack (Top) */
    /* IS: G berisi GameState Terakhir */
}
