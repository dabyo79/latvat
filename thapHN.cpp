#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void setTextColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void hienThiCot(int chieuCao, int dia, int x, int y, int color) {
	gotoxy(x+chieuCao, 1);	
	setTextColor(240);
	cout << " ";
	setTextColor(7);
    gotoxy(x, y);
    setTextColor(color); 

    for (int i = 0; i < chieuCao - dia; i++) {
        cout << " ";
    }

    for (int i = 0; i < dia; i++) {
        printf("%c",219); 
    }
	setTextColor(240);
    cout << " "; 
	setTextColor(color);
    for (int i = 0; i < dia; i++) {
        printf("%c",219);
    }

    cout << "   ";
    setTextColor(7);
}

void hienThiThap(int **thap, int soDia, int chieuCao) {
    system("cls");
	
    int x = 2; 
    for (int j = 0; j < 3; j++) {
        int y = 2; 
        for (int i = 0; i < chieuCao; i++) {
            if (thap[j][i] != 0) {
                
                int color = thap[j][i] % 15 + 1;
                //cot chua dia
                hienThiCot(chieuCao, thap[j][i], x, y, color);
            } else {
            	// cot khong chua dia
                hienThiCot(chieuCao, 0, x, y, 7); 
            }
            y += 1; 
        }
        x += 20; 
    }

    getch(); 
}

void diChuyenDia(int nguon, int dich, int **thap, int soDia, int &chieuCao) {
    
    int dia = 0;
    for (int i = 0; i < chieuCao; i++) {
        if (thap[nguon][i] != 0) {
            dia = thap[nguon][i];
            thap[nguon][i] = 0;
            break;
        }
    }

    for (int i = chieuCao - 1; i >= 0; i--) {
        if (thap[dich][i] == 0) {
            thap[dich][i] = dia;
            break;
        }
    }

    hienThiThap(thap, soDia, chieuCao);
}

void thapHN(int m, int nguon, int dich, int trungGian, int **thap, int soDia, int &chieuCao) {
    if (m > 0) {
    	// di chuyen dia tu cot nguon sang cot trung gian 
    	
        thapHN(m - 1, nguon, trungGian, dich, thap, soDia, chieuCao);
		
		// di chuyen dia con lai tu cot nguon sang cot dich
        diChuyenDia(nguon, dich, thap, soDia, chieuCao);

		//di chuyen dia tu cot trung gian sang cot dich
        thapHN(m - 1, trungGian, dich, nguon, thap, soDia, chieuCao);
    }
}

void thapHaNoi(int soDia, int cotNguon, int cotDich, int cotTrungGian) {
    int **thap = new int *[3];
    for (int i = 0; i < 3; i++) {
        thap[i] = new int[soDia];
        for (int j = 0; j < soDia; j++) {
            thap[i][j] = 0;
        }
    }

    for (int i = soDia - 1; i >= 0; i--) {
        thap[cotNguon][i] = i + 1;
    }

    int chieuCao = soDia;

    hienThiThap(thap, soDia, chieuCao);
    thapHN(soDia, cotNguon, cotDich, cotTrungGian, thap, soDia, chieuCao);

    for (int i = 0; i < 3; i++) {
        delete[] thap[i];
    }
    delete[] thap;
}

int main() {
    int soDia;
    int viTriNguon, viTriDich;
    cout << "Nhap so dia: ";
    cin >> soDia;
    cout << "Chon cot nguon (1, 2, 3): ";
    cin >> viTriNguon;
    cout << "Chon cot dich (1, 2, 3, khac cot nguon): ";
    cin >> viTriDich;

    thapHaNoi(soDia, viTriNguon - 1, viTriDich - 1, 6 - viTriNguon - viTriDich - 1);

    return 0;
}

