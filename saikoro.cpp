#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <vector>

using namespace std;

class game {
public:
    virtual void select() = 0;
    virtual void introduce() = 0;
    game() {}
};

class dice : public game {
public:
    dice() {}
    virtual void select() {
        int i;
        system("cls");
        srand((unsigned int)time(NULL));
        cout << "サイコロゲームを開始します。(サイコロ1個)" << "\n";
        i = rand() % 6 + 1;

        if (i == 1) {
            cout << "　　　" << "\n";
            cout << "　●　" << "\n";
            cout << "　　　" << "\n";
            cout << "\n";
            cout << "出た目は1です。" << "\n";
        }
        else if (i == 2) {
            cout << "●　　" << "\n";
            cout << "　　　" << "\n";
            cout << "　　●" << "\n";
            cout << "\n";
            cout << "出た目は2です。" << "\n";
        }
        else if (i == 3) {
            cout << "●　　" << "\n";
            cout << "　●　" << "\n";
            cout << "　　●" << "\n";
            cout << "\n";
            cout << "出た目は3です。" << "\n";
        }
        else if (i == 4) {
            cout << "●　●" << "\n";
            cout << "　　　" << "\n";
            cout << "●　●" << "\n";
            cout << "\n";
            cout << "出た目は4です。" << "\n";
        }
        else if (i == 5) {
            cout << "●　●" << "\n";
            cout << "　●　" << "\n";
            cout << "●　●" << "\n";
            cout << "\n";
            cout << "出た目は5です。" << "\n";
        }
        else if (i == 6) {
            cout << "●　●" << "\n";
            cout << "●　●" << "\n";
            cout << "●　●" << "\n";
            cout << "\n";
            cout << "出た目は6です。" << "\n";
        }
    }
    virtual void introduce() {
        cout << "あなたはサイコロゲームを選びました。" << "\n";
    }
};

class twodice : public dice {
public:
    twodice() {}
    void select() {
        int j, k;
        system("cls");
        srand((unsigned int)time(NULL));
        cout << "サイコロゲームを開始します。(サイコロ2個)" << "\n";
        j = rand() % 6 + 1;
        k = rand() % 6 + 1;
        cout << "出た目は" << j + k << "です。";
        cout << "\n";
    }
    void introduce() {
        cout << "あなたは2個のサイコロゲームを選びました。" << "\n";
    }
};

class twelvenumber : public dice {
public:
    twelvenumber() {}
    void select() {
        int l;
        system("cls");
        srand((unsigned int)time(NULL));
        cout << "12面サイコロゲームを開始します。(サイコロ1個)" << "\n";
        l = rand() % 12 + 1;
        cout << "選ばれた数字は" << l << "です。" << "\n";
    }
    void introduce() {
        cout << "あなたは12面サイコロゲームを選びました。" << "\n";
    }
};

// メイン関数を追加
int main() {
    // ゲーム選択
    cout << "ゲームを選んでください。\n";
    cout << "1: サイコロ (1個)\n";
    cout << "2: サイコロ (2個)\n";
    cout << "3: 12面サイコロ\n";

    int choice;
    cin >> choice;

    game* selectedGame = nullptr;

    // ゲームインスタンスの作成
    switch (choice) {
    case 1:
        selectedGame = new dice();
        break;
    case 2:
        selectedGame = new twodice();
        break;
    case 3:
        selectedGame = new twelvenumber();
        break;
    default:
        cout << "無効な選択です。\n";
        return 0;
    }

    // ゲームの紹介とプレイ
    selectedGame->introduce();
    cout << "\n";
    selectedGame->select();

    // メモリ解放
    delete selectedGame;

    return 0;
}
