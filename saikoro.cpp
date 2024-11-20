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
        cout << "�T�C�R���Q�[�����J�n���܂��B(�T�C�R��1��)" << "\n";
        i = rand() % 6 + 1;

        if (i == 1) {
            cout << "�@�@�@" << "\n";
            cout << "�@���@" << "\n";
            cout << "�@�@�@" << "\n";
            cout << "\n";
            cout << "�o���ڂ�1�ł��B" << "\n";
        }
        else if (i == 2) {
            cout << "���@�@" << "\n";
            cout << "�@�@�@" << "\n";
            cout << "�@�@��" << "\n";
            cout << "\n";
            cout << "�o���ڂ�2�ł��B" << "\n";
        }
        else if (i == 3) {
            cout << "���@�@" << "\n";
            cout << "�@���@" << "\n";
            cout << "�@�@��" << "\n";
            cout << "\n";
            cout << "�o���ڂ�3�ł��B" << "\n";
        }
        else if (i == 4) {
            cout << "���@��" << "\n";
            cout << "�@�@�@" << "\n";
            cout << "���@��" << "\n";
            cout << "\n";
            cout << "�o���ڂ�4�ł��B" << "\n";
        }
        else if (i == 5) {
            cout << "���@��" << "\n";
            cout << "�@���@" << "\n";
            cout << "���@��" << "\n";
            cout << "\n";
            cout << "�o���ڂ�5�ł��B" << "\n";
        }
        else if (i == 6) {
            cout << "���@��" << "\n";
            cout << "���@��" << "\n";
            cout << "���@��" << "\n";
            cout << "\n";
            cout << "�o���ڂ�6�ł��B" << "\n";
        }
    }
    virtual void introduce() {
        cout << "���Ȃ��̓T�C�R���Q�[����I�т܂����B" << "\n";
    }
};

class twodice : public dice {
public:
    twodice() {}
    void select() {
        int j, k;
        system("cls");
        srand((unsigned int)time(NULL));
        cout << "�T�C�R���Q�[�����J�n���܂��B(�T�C�R��2��)" << "\n";
        j = rand() % 6 + 1;
        k = rand() % 6 + 1;
        cout << "�o���ڂ�" << j + k << "�ł��B";
        cout << "\n";
    }
    void introduce() {
        cout << "���Ȃ���2�̃T�C�R���Q�[����I�т܂����B" << "\n";
    }
};

class twelvenumber : public dice {
public:
    twelvenumber() {}
    void select() {
        int l;
        system("cls");
        srand((unsigned int)time(NULL));
        cout << "12�ʃT�C�R���Q�[�����J�n���܂��B(�T�C�R��1��)" << "\n";
        l = rand() % 12 + 1;
        cout << "�I�΂ꂽ������" << l << "�ł��B" << "\n";
    }
    void introduce() {
        cout << "���Ȃ���12�ʃT�C�R���Q�[����I�т܂����B" << "\n";
    }
};

// ���C���֐���ǉ�
int main() {
    // �Q�[���I��
    cout << "�Q�[����I��ł��������B\n";
    cout << "1: �T�C�R�� (1��)\n";
    cout << "2: �T�C�R�� (2��)\n";
    cout << "3: 12�ʃT�C�R��\n";

    int choice;
    cin >> choice;

    game* selectedGame = nullptr;

    // �Q�[���C���X�^���X�̍쐬
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
        cout << "�����ȑI���ł��B\n";
        return 0;
    }

    // �Q�[���̏Љ�ƃv���C
    selectedGame->introduce();
    cout << "\n";
    selectedGame->select();

    // ���������
    delete selectedGame;

    return 0;
}
