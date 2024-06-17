#include<iostream>
#include<conio.h>
#include<string>
#include<stack>
#include<windows.h>
#define MAX 100
using namespace std;

bool ktraPhepTinh(char x) {
    return (x == '+' || x == '-' || x == '*' || x == '/');
}

bool ktraSo(char x) {
    return (x >= '0' && x <= '9');
}

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void chuyen(string nhap, string &luu) {
    stack<char> s;

    cout <<"Nhap vao: " << nhap << endl;
	getch();
    for (int i = 0; i < nhap.length(); i++) {
        char c = nhap[i];

        if (ktraSo(c)) { // Kiem tra co phai la so khong
            luu += c;
            setColor(11); 
            cout <<endl<< "\t    Xet " << c << ", ";
            getch();
        } else if (ktraPhepTinh(c)) { //Kiem tra các phep toan
            setColor(11); 
            cout <<endl<< "\t    Xet " << c << ", ";
			getch();
            while (!s.empty() && ktraPhepTinh(s.top()) && ((c != '*' && c != '/') || (s.top() != '+' && s.top() != '-'))) 
			//ktra stack s có rong khong
			//ktra dinh cua stack co phai la phep tinh khong
			//nhân chia truoc cong tru sau nen neu dinh ngan xep la + - thi chi duoc them vào chu khong lay + - ra dc
			// neu dinh ngan xep la + - thì lay cai nao ra cung dc
			{
                luu += s.top();
                cout << "Pop " << s.top() << ", ";
                s.pop();
            }
            s.push(c);

            cout << "Push " << c ;
        } else if (c == '(') {
        	setColor(11); 
            cout <<endl<< "\t    Xet " << c << ", ";
            getch();
            s.push(c); cout << "Push " << c ;
        } else if (c == ')') {
            setColor(11);
			cout <<endl<< "\t    Xet " << c << ", ";
            getch(); 
            while (!s.empty() && s.top() != '(') {
                luu += s.top();
                
                cout << "Pop " << s.top() << ", ";
                s.pop();
            }
            s.pop(); 
            
            cout << "Pop (" << endl;
        }
		getch();
        setColor(7); 
        cout <<endl<< "Stack: ";
        stack<char> t = s;
        while (!t.empty()) {
        	setColor(240);
            cout <<" "<< t.top() << " ";
            t.pop();
        }
        setColor(15);
        getch();

        
        cout << "\t |"<<"     Chuoi luu: " ;
        
		setColor(240);
		cout<<" "<< luu<<" " << endl;
		setColor(0);
        cout<<" ";
		
        setColor(7);
        getch();
    }

  	while (!s.empty()) {
        luu += s.top();
        setColor(11);
        cout << "\t  Pop " << s.top() << ", ";
        s.pop();
    }

   
    cout << "Ket thuc" << endl;
    
}


float tinh(string luu) {
    stack<float> s;

    for (int i = 0; i < luu.length(); i++) {
        char c = luu[i];

        if (ktraSo(c)) {
            s.push(c -'0');
        } else if (ktraPhepTinh(c)) {
            setColor(14); 
            float b = s.top(); s.pop();
            float a = s.top(); s.pop();

            switch (c) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
            }
            setColor(7); 
        }
    }

    return s.top();
}

int main() {
    string nhap, luu;
    cout << "Nhap bieu thuc: ";
    cin >> nhap;

    chuyen(nhap, luu);
    setColor(12);
    cout << "Bieu thuc hau to: ";
	setColor(240);
	cout << luu << endl;

    float kq = tinh(luu);
    setColor(10);
    cout << "Gia tri bieu thuc: " << kq << endl;
    setColor(7);

    return 0;
}

