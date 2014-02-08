oneripo
=======
#include "DxLib.h"
#include <time.h>


// グローバル変数
int pics[16];
int pic_all;
int panel[16];
enum { TITLE, MAIN, CLEAR } status = TITLE;
int mp3_s;
// キー入力
char key_buf[256];
int key[256]; // 0:入力されていない 1:入力された瞬間 2:入力されている
void inputKey() {
	GetHitKeyStateAll(key_buf);
	for (int i = 0; i < 256; i++) {
		if (key_buf[i]) {
			if (key[i] == 0) key[i] = 1;
			else if (key[i] == 1) key[i] = 2;
		}
		else key[i] = 0;
	}
}

// 選択したパネルと空白を入れ替える
void change(int x, int y) {
	int p1 = y * 4 + x;
	int p2 = -1;
	if (x > 0 && panel[p1 - 1] == 15) p2 = p1 - 1;
	if (x < 3 && panel[p1 + 1] == 15) p2 = p1 + 1;
	if (y > 0 && panel[p1 - 4] == 15) p2 = p1 - 4;
	if (y < 3 && panel[p1 + 4] == 15) p2 = p1 + 4;
	if (p2 != -1) {
		panel[p2] = panel[p1];
		panel[p1] = 15;
	}
	PlaySoundMem(mp3_s, DX_PLAYTYPE_BACK, TRUE);
}

void getPic() {
	int r;
	r = rand() % 10;
	if (r == 0){
		LoadDivGraph("pic.png", 16, 4, 4, 80, 80, pics);
		pic_all = LoadGraph("pic.png");
	}
	if (r == 1){
		LoadDivGraph("pic2.png", 16, 4, 4, 80, 80, pics);
		pic_all = LoadGraph("pic2.png");
	}
	if (r == 2){
		LoadDivGraph("pic3.png", 16, 4, 4, 80, 80, pics);
		pic_all = LoadGraph("pic3.png");
	}
	if (r == 3){
		LoadDivGraph("pic4.png", 16, 4, 4, 80, 80, pics);
		pic_all = LoadGraph("pic4.png");
	}
	if (r == 4){
		LoadDivGraph("pic5.png", 16, 4, 4, 80, 80, pics);
		pic_all = LoadGraph("pic5.png");
	}
	if (r == 5){
		LoadDivGraph("pic6.png", 16, 4, 4, 80, 80, pics);
		pic_all = LoadGraph("pic6.png");
	}
	if (r == 6){
		LoadDivGraph("pic7.png", 16, 4, 4, 80, 80, pics);
		pic_all = LoadGraph("pic7.png");
	}
	if (r == 7){
		LoadDivGraph("pic8.png", 16, 4, 4, 80, 80, pics);
		pic_all = LoadGraph("pic8.png");
	}
	if (r == 8){
		LoadDivGraph("pic9.png", 16, 4, 4, 80, 80, pics);
		pic_all = LoadGraph("pic9.png");
	}
	if (r == 9){
		LoadDivGraph("pic10.png", 16, 4, 4, 80, 80, pics);
		pic_all = LoadGraph("pic10.png");
	}
}

// タイトル画面
void gameTitle() {
	if (GetMouseInput() & MOUSE_INPUT_LEFT) {
		// 初期パネルのシャッフル
		for (int i = 0; i < 16; i++) panel[i] = i;
		for (int i = 0; i < 1000; i++) {
			change(GetRand(3), GetRand(3));
		}
		status = MAIN;
		PlaySoundFile("bgm.mp3", DX_PLAYTYPE_LOOP);
	}
	if (key[KEY_INPUT_C] == 1) getPic();
	DrawGraph(0, 0, pic_all, FALSE);
	DrawString(102, 142, "CLICK TO START", GetColor(255, 0, 0));
	DrawString(72, 200, "PUSH C PICTURE CANGE", GetColor(255, 0, 0));
}
	// メイン画面
void gameMain() {

	if (GetMouseInput() & MOUSE_INPUT_LEFT) {
		int x, y;
		GetMousePoint(&x, &y);
		change(x / 80, y / 80);

		// パネルが全部揃ったか判定
		bool clear = true;
		for (int i = 0; i < 16; i++) {
			if (panel[i] != i) clear = false;
		}
		if (clear) {
			status = CLEAR;
			PlaySoundFile("bgm2.mp3", DX_PLAYTYPE_LOOP);
		}
	}

	// パネルの描画
	for (int i = 0; i < 16; i++) {
		if (panel[i] < 15) {
			DrawGraph((i % 4) * 80, (i / 4) * 80, pics[panel[i]], FALSE);
		}
	}
}
	// 終了画面
	void gameClear() {
		DrawGraph(0, 0, pic_all, FALSE);
		DrawString(115, 142, "GAME CLEAR!", GetColor(255, 0, 0));
		DrawString(92, 200, "PUSH SPACE TO TITLE", GetColor(255, 0, 0));
		if (key[KEY_INPUT_SPACE]) status = TITLE;

	}

	int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
		SetGraphMode(320, 320, 32);
		ChangeWindowMode(TRUE);
		SetWindowSizeExtendRate(2);
		DxLib_Init();
		SetDrawScreen(DX_SCREEN_BACK);
		srand((unsigned)time(NULL));
		getPic();

		mp3_s = LoadSoundMem("s.mp3");

		while (!ProcessMessage()) {
			ClearDrawScreen();
			inputKey();
			switch (status) {
			case TITLE: gameTitle(); break;
			case MAIN: gameMain(); break;
			case CLEAR: gameClear(); break;
			}
			ScreenFlip();
		}
		DxLib_End();
		return 0;
	}
	
