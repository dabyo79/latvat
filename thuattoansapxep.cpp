#include <iostream>
#include <conio.h>
#include <windows.h>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits>
bool daxet[100]={false};
using namespace std;


void setConsoleColor(int colorCode) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, colorCode);
}

void resetConsoleColor() {
    setConsoleColor(15); 
}
void gotoxy(int x, int y)
{
  HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}
struct Toado{
    int x, y;
};
void hienthimenu(int &thoat);
void hienthide();
void nhapmang(int n, int a[]);
void xuatmang(int n, int a[]);
void landoicho(int n, int a[]);
void hienthimenu(int &thoat)
{
	hienthide();
 	printf("\n");
 	printf("______________________________________________________________________________________________________________________");
    setConsoleColor(14);
    setConsoleColor(55);
    gotoxy(33, 17); printf("%c Doi cho truc tiep (Interchange Sort)  ", 16);
    setConsoleColor(14);
    gotoxy(35, 18); printf("Chon truc tiep (Selection Sort)");
    gotoxy(35, 19); printf("Chen (Insertion Sort)");
    gotoxy(35, 20); printf("Noi bot (Bubble Sort)");
    gotoxy(35, 21); printf("Nhanh (Quick Sort)");
    int chon = 0;
    int toado = 17;
    do{
        char a = getch();
        if(a == 80 ) chon = 1;
        else if(a == 72 ) chon = 2;
        else if(a == 13 ) chon = 3;
        else chon = 0;
        if(chon == 1 && toado < 21) toado++;
        else if(chon == 2 && toado >17) toado--;
        if(toado == 17)
        {
            setConsoleColor(63);
            gotoxy(33, 17); printf("%c Doi cho truc tiep (Interchange Sort)  ", 16);
            setConsoleColor(14);
            gotoxy(33, 18); printf("  Chon truc tiep (Selection Sort)         ");
            gotoxy(33, 19); printf("  Chen (Insertion Sort)        ");
            gotoxy(33, 20); printf("  Noi bot (Bubble Sort)         ");
            gotoxy(33, 21); printf("  Nhanh (Quick Sort)			");
            setConsoleColor(0);
        }
        if(toado == 18)
        {
            setConsoleColor(14);
            gotoxy(33, 17); printf("  Doi cho truc tiep (Interchange Sort)   ");
            setConsoleColor(63);
            gotoxy(33, 18); printf("%c Chon truc tiep (Selection Sort)       ", 16);
            setConsoleColor(14);
            gotoxy(33, 19); printf("  Chen (Insertion Sort)        ");
            gotoxy(33, 20); printf("  Noi bot (Bubble Sort)         ");
            gotoxy(33, 21); printf("  Nhanh (Quick Sort)			");
            setConsoleColor(0);
        }
        if(toado == 19)
        {
            setConsoleColor(14); 
            gotoxy(33, 17); printf("  Doi cho truc tiep (Interchange Sort)  ", 16);
            gotoxy(33, 18); printf("  Chon truc tiep (Selection Sort)       ");
            setConsoleColor(63);
            gotoxy(33, 19); printf("%c Chen (Insertion Sort)      ", 16);
            setConsoleColor(14);
            gotoxy(33, 20); printf("  Noi bot (Bubble Sort)       ");
            gotoxy(33, 21); printf("  Nhanh (Quick Sort)			");
            setConsoleColor(0);
        }
            if(toado == 20)
        {
           setConsoleColor(14);
            gotoxy(33, 17); printf("  Doi cho truc tiep (Interchange Sort)    ", 16);
            gotoxy(33, 18); printf("  Chon truc tiep (Selection Sort)         ");
            gotoxy(33, 19); printf("  Chen (Insertion Sort)        ");
            setConsoleColor(63);
            gotoxy(33, 20); printf("%c Noi bot (Bubble Sort)       ", 16);
            setConsoleColor(14);
            gotoxy(33, 21); printf("  Nhanh (Quick Sort)			");
            setConsoleColor(0);
        }
        if(toado == 21)
        {
            setConsoleColor(14);
            gotoxy(33, 17); printf("  Doi cho truc tiep (Interchange Sort)    ", 16);
            gotoxy(33, 18); printf("  Chon truc tiep (Selection Sort)         ");
            gotoxy(33, 19); printf("  Chen (Insertion Sort)        ");
            gotoxy(33, 20); printf("  Noi bot (Bubble Sort)       ", 16);
            setConsoleColor(63);
            gotoxy(33, 21); printf("%c Nhanh (Quick Sort)			", 16);
            setConsoleColor(0);
        }
    }while(chon != 3);
    system("cls");
    if(toado == 18) thoat=1 ;
    else if(toado == 19) thoat=2; //chen(thoat);
    else if(toado == 20) thoat=3; //noibot(thoat); 
    else if(toado == 21) thoat=4 ;//nhanh
}
void hienthide()
{

    setConsoleColor(8);
    gotoxy(3,3); printf("\t	$$$$$$$ $$$   $$$  $$$    $$$   $$$$$$  $$$$$$$    $$$$$$$$  $$$$$$$$$   $$$$$$   $$$$  $$$\n"); Sleep(40);
    gotoxy(3,4); printf("\t	  $$$   $$$   $$$  $$$    $$$  $$$  $$$   $$$        $$$     $$$   $$$  $$$  $$$  $$$$$ $$$\n"); Sleep(40); setConsoleColor(7);
    gotoxy(3,5); printf("\t	  $$$   $$$$$$$$$  $$$    $$$  $$$$$$$$   $$$        $$$     $$$   $$$  $$$$$$$$  $$$ $$$$$\n"); Sleep(40);
    gotoxy(3,6); printf("\t	  $$$   $$$   $$$  $$$    $$$  $$$  $$$   $$$        $$$     $$$   $$$  $$$  $$$  $$$  $$$$\n"); Sleep(40); setConsoleColor(7);
    gotoxy(3,7); printf("\t	  $$$   $$$   $$$  $$$$$$$$$$  $$$  $$$   $$$        $$$     $$$$$$$$$  $$$  $$$  $$$   $$$\n"); Sleep(40);
    setConsoleColor(8);
	gotoxy(3,8);printf("\t                                                                                             \n"); 
    gotoxy(3,9);printf("\t   	        	   $$$$$$$    $$$$$$   $$$$$$$     $$$     $$$  $$$$$$$  $$$$$$$            \n"); Sleep(40);
    gotoxy(3,10);printf("\t	                  $$$    $$  $$$  $$$  $$$  $$$      $$$  $$$   $$$      $$$  $$$           \n"); Sleep(40); setConsoleColor(7);
    gotoxy(3,11);printf("\t	                    $$$$     $$$$$$$$  $$$$$$$	       $$$      $$$$$$$  $$$$$$$            \n"); Sleep(40);
    gotoxy(3,12);printf("\t	                 $$    $$$   $$$  $$$  $$$           $$$ $$$    $$$      $$$                \n"); Sleep(40); setConsoleColor(7);
    gotoxy(3,13);printf("\t	                  $$$$$$$    $$$  $$$  $$$   	    $$$   $$$   $$$$$$$  $$$                \n"); Sleep(40);
}

void xuatmangsx(int n, int a[]){
    setConsoleColor(15);
	cout<<endl<<endl<<"< Ket thuc qua trinh sap xep >"<<endl;
	setConsoleColor(11);
    cout<<setw(40)<<left << "\t "<<"________________________________"<<endl;
	cout<<setw(40)<<left <<"\t "<<"Mang da sap xep la: ";
	for(int i=0; i<=n-1; i++){
		setConsoleColor(0);
		cout<<" ";
		setConsoleColor(47);
		cout<<" "<<a[i]<<" ";}
	setConsoleColor(11);
	cout<<endl<<setw(40)<<left<<"\t "<<"________________________________"<<endl;	
 
	setConsoleColor(116); printf("  EXIT  ");
 
    setConsoleColor(0);
}
//doi cho truc tiep
void xuat(int a[], int n, int xet1, int xet2, int doi1, int doi2) {
   
	
	for (int i = 0; i < n; i++) {
        if (i == xet1 || i==xet2) {
            setConsoleColor(71);
		}		
        else if (i == doi1 || i==doi2 ) {
			setConsoleColor(63);}
		else if(xet1==i+1){
			setConsoleColor(47);
			daxet[i+1]=true;}
		else {
            setConsoleColor(240); 
        }
        if(daxet[i+1]){
        	setConsoleColor(47);}
        cout <<"\t"<< "  "<<a[i]<<"  ";        
    }
    resetConsoleColor();
    cout << endl;
}

//doi cho truc tiep
void landoicho(int n, int a[])//,int thoat)
{
	setConsoleColor(240);
	cout<<"\t"<<"   ";
	setConsoleColor(15);
	cout<<": Vi tri chua xet (hoac chua gia tri vua doi cho cho lan xet toi)"<<endl;
	setConsoleColor(63);
	cout<<"\t"<<"   ";
	setConsoleColor(15);
	cout<<": Vi tri da doi cho"<<endl;
	setConsoleColor(71);
	cout<<"\t"<<"   ";
	setConsoleColor(15);
	cout<<": Vi tri xet"<<endl;
	setConsoleColor(47);
	cout<<"\t"<<"   ";
	setConsoleColor(15);
	cout<<": Vi tri da xet"<<endl;
	
	setConsoleColor(15);
	int ss, i, j;
	for(int x=0; x<=n-1;x++){
		cout<<endl<<"\t"<<"[ Voi i="<<x<<" ]";
		int i=x;
		if(x==n-1){
			xuat(a, n, i, j, -1, -1);
			getch();
			cout<<"\t \t ==> ";
			for(int i=0; i<=n-1; i++){
			setConsoleColor(47);
        	cout <<"\t"<< "  "<<a[i]<<"  ";   
			}
		}
		for( j=i+1; j<=n-1; j++){
			cout<<endl<<"Kiem tra voi j="<<j<<":";
			xuat(a, n, i, j, -1, -1);
        	getch();
					
			if(a[i]<=a[j]){
				cout<<"\t \t ==> ";
				xuat(a, n, -1, -1, i , j);
        		getch();}
			else if(a[i]>a[j]){
				ss=a[i];
				a[i]=a[j];
				a[j]=ss;
						
				cout<<"\t \t ==> ";
				xuat(a, n,-1,-1, i, j);
                getch();
					}
				
		} 
			
	}
	xuatmangsx(n,a);
    /*char b;
    do
    {
        b = getch();
    }while(b!=13 );
    system("cls");
    fflush(stdin);
    //hienthimenu(thoat);*/
}


//chon truc tiep
void xuatchon(int a[], int n, int chon,int thay, int doi1, int doi2) {

    for (int i = 0; i < n; i++) {
        if (i == chon) {
            setConsoleColor(63); 
        } else if (i == doi1 || i == doi2) {
            if(i==doi1){setConsoleColor(71);}
            if(i==doi2){setConsoleColor(63);}
        }else if(i==thay){
        	setConsoleColor(71);}
        else if(chon==i+1){
			setConsoleColor(47);
			daxet[i+1]=true;}
		 else {
            setConsoleColor(240); 
        }
		if(daxet[i+1]){
        	setConsoleColor(47);}
        cout <<"\t"<< " " << a[i] << " ";
    }

    resetConsoleColor();
    cout << endl;
}
//chon truc tiep
void selectionSort(int a[], int n){//, int thoat) {
    
    setConsoleColor(240);
	cout<<"\t"<<"   ";
	setConsoleColor(15);
	cout<<": Vi tri chua xet "<<endl;
	setConsoleColor(63);
	cout<<"\t"<<"   ";
	setConsoleColor(15);
	cout<<": Vi tri duoc chon (hoac doi cho cho vi tri can doi vua xet)"<<endl;
	setConsoleColor(71);
	cout<<"\t"<<"   ";
	setConsoleColor(15);
	cout<<": Vi tri phat hien gia tri can doi cho (hoac doi cho cho vi tri chon vua xet)"<<endl;
	setConsoleColor(47);
	cout<<"\t"<<"   ";
	setConsoleColor(15);
	cout<<": Vi tri da xet"<<endl;
	int min;
    for (int i = 0; i <= n-1; i++) {
    	
    	cout<<endl<<"[ Voi i = "<<i<<" ]: \t";
		min = i;
		xuatchon(a, n, i, -1, -1, -1);
		if(i==n-1){
    		cout<<"\t ==> \t";
    		for(int i=0; i<=n-1; i++){
			setConsoleColor(47);
			cout <<"\t"<< " "<<a[i]<<" ";}
			}
        for (int j = i + 1; j <= n-1; j++) {
            if (a[j] < a[min]) {
                min = j;
                cout<<"Bat dau kiem tra: ";
                xuatchon(a, n, i,min, -1, -1);
                getch();
            }
        }

        if (min != i) {
            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;

            
            cout<<"\t ==> \t";
            xuatchon(a, n, -1, -1, i, min);
            getch();
        }
    }
    xuatmangsx(n,a);
    /*char b;
    do
    {
        b = getch();
    }while(b!=13 );
    system("cls");
    fflush(stdin);
    //hienthimenu(thoat);*/
}

//chen
void xuatChen(int a[], int n, int k, int chon) {

    for (int i = 0; i < n; ++i) {
        if (i == k) {
            setConsoleColor(71);
        } else if(i==chon) {
            setConsoleColor(47);
        }else if(k==i+1){
        	setConsoleColor(47);
        	daxet[i+1]=true;
		}else if(daxet[i+1]){
			setConsoleColor(47);}
		else{
        	setConsoleColor(240);
		}

        cout <<"\t"<< " " << a[i] << " ";
    }

    setConsoleColor(15);
    cout << endl;
    
}

//chen

void Chen(int n, int a[]){//,int thoat) {
	setConsoleColor(240);
	cout<<"\t"<<"   ";
	setConsoleColor(15);
	cout<<": Vi tri chua xet "<<endl;
	setConsoleColor(71);
	cout<<"\t"<<"   ";
	setConsoleColor(15);
	cout<<": Vi tri xet)"<<endl;
	setConsoleColor(47);
	cout<<"\t"<<"   ";
	setConsoleColor(15);
	cout<<": Vi tri da xet ( hoac da thuc hien doi cho )"<<endl;
    for (int i = 0; i < n; ++i) {
        int key = a[i];
        int j = i - 1;
        cout<<endl<<"[ Voi i = "<<i<<" ]: ";
		xuatChen(a, n, i,-1);
		getch();
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            --j;   
        }
        a[j + 1] = key;
        cout<<"\t ==> ";
        xuatChen(a, n, -1,i);
        getch();
        
    } xuatmangsx(n,a);
    /*char b;
    do
    {
        b = getch();
    }while(b!=13 );
    system("cls");
    fflush(stdin);
    //hienthimenu(thoat);*/
}

//noi bot

void xuatnoibot(int n, int a[], int xet1, int xet2, int doi1, int doi2, int xetrui ) {

    for (int i = 0; i <n; i++) {
        if (i == xet1 || i == xet2) {
            setConsoleColor(71);
        } else if(i==doi1 || i==doi2){
        	setConsoleColor(63);}
        else if ( xetrui == i) {
            setConsoleColor(47);
			daxet[i]=true;}
		else if(daxet[i]){
        	setConsoleColor(47);}
        else{
        	setConsoleColor(240);
		}
        cout <<"\t"<< " " << a[i] << " ";
	}
    setConsoleColor(15);
    cout << endl;
}
//noi bot

void NoiBot(int n, int a[]){//,int thoat) {
	setConsoleColor(240);
	cout<<"\t"<<"   ";
	setConsoleColor(15);
	cout<<": Vi tri chua xet (hoac chua gia tri vua doi cho cho lan xet toi)"<<endl;
	setConsoleColor(63);
	cout<<"\t"<<"   ";
	setConsoleColor(15);
	cout<<": Vi tri da doi cho"<<endl;
	setConsoleColor(71);
	cout<<"\t"<<"   ";
	setConsoleColor(15);
	cout<<": Vi tri xet"<<endl;
	setConsoleColor(47);
	cout<<"\t"<<"   ";
	setConsoleColor(15);
	cout<<": Vi tri da xet"<<endl;
	
	setConsoleColor(15);
	int xetr=0;
    for (int i = 0; i <n-1; i++) {
    
    	cout<<endl<<"[ Voi lan lap thu "<<i+1<<"]: "<<endl;
    	
        for (int j = 0; j <n - i-1; j++) {
        	setConsoleColor(8);
    		cout<<"\t Xet: ";
 			xuatnoibot(n,a,j,j+1,-1,-1,xetr);
 			getch();
 			
            if (a[j] > a[j+1]) {
            	int tam=a[j];
                a[j]=a[j+1];
                a[j+1]=tam;
                
				cout <<"\t ==> ";
                xuatnoibot(n,a , -1,-1,j, j+1,xetr);
                getch();
                
            }else if (a[j] < a[j+1]) {
            	cout <<"\t ==> ";
            	xuatnoibot(n,a , -1,-1,j, j+1,xetr);
                getch();}
            if(i==n-2){
			cout<<"\t ==> ";
			for(int i=0; i<=n-1; i++){
			setConsoleColor(47);
        	cout <<"\t"<< " "<<a[i]<<" ";   
				}
			}    
			xetr = j + 1;
        }
    }xuatmangsx(n,a);
    /*char b;
    do
    {
        b = getch();
    }while(b!=13 );
    system("cls");
    fflush(stdin);
    //hienthimenu(thoat);*/
}    		
//nhanh
int partition(int arr[], int low, int high)
{
	int hv;
    int pivot = arr[high];
    int left = low;
    int right = high - 1;
    while (true)
    {
        while (left <= right && arr[left] < pivot)
            left++;
        while (right >= left && arr[right] > pivot)
            right--;
        if (left >= right)
            break;
        hv=arr[left];
		arr[left]= arr[right];
		arr[right]=hv;
        left++;
        right--;
    }
    hv=arr[left];
    arr[left]=arr[high];
    arr[high]=hv;
    return left;
}
void printArrayRange(int arr[], int start, int end)
{
    for (int i = start; i <= end; i++)
    {
    	setConsoleColor(240); 
        cout <<"\t"<<" "<< arr[i] << " ";
    }
    cout << "\n";
}
void quickSort(int arr[], int low, int high)
{
	setConsoleColor(240);
	cout<<"\t"<<"   ";
	setConsoleColor(15);
	cout<<": Vi tri chua xet (hoac chua gia tri vua doi cho cho lan xet toi)"<<endl;
	setConsoleColor(63);
	cout<<"\t"<<"   ";
	setConsoleColor(15);
	cout<<": Vi tri pivot"<<endl;
    if (low < high)
    {
        setConsoleColor(15); 
        cout << endl<<"\t [Xet] \t";
        printArrayRange(arr, low, high);

        int pivotIndex = partition(arr, low, high);
		getch();
      	setConsoleColor(15); 
        cout << "Chon pivot va sap xep: ";
       
        

        for (int i = low; i <= high; i++)
        {
            if (i == pivotIndex)
            {
                setConsoleColor(63); 
                cout <<"\t"<< " " << arr[i] << " ";
               
            }
            else
            {
            	setConsoleColor(240); 
                cout <<"\t"<<" "<< arr[i] <<" ";
                
            }
        }
        cout << "\n";

      	
        setConsoleColor(15); 
        cout << "Mang ben trai: ";
        printArrayRange(arr, low, pivotIndex - 1);
		setConsoleColor(15); 
        cout << "Mang ben phai: ";
        printArrayRange(arr, pivotIndex + 1, high);
		getch();
       
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);

        
    }
    
}
void nhapMang(int& n, int*& a) {
    while (true) {
    	setConsoleColor(15);
    	cout << "Nhap so phan tu cua mang: ";
        if (cin >> n) {
            break; 
        } else {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
			 setConsoleColor(207);
            cout << "\t Nhap khong hop le. Vui long nhap lai.\n";
        }
    }

    
    a = new int[n];

    for (int i = 0; i < n; i++) {
        while (true) {
        	setConsoleColor(15);
            cout << "Nhap phan tu thu a[" << i << "]: ";
            if (cin >> a[i]) {
                break; 
            } else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                setConsoleColor(207);
                cout << "\t Nhap khong hop le. Vui long nhap lai.\n";
            }
        }
    }
}

void xuatMang(int n, int* a){
    setConsoleColor(11);
    cout<<setw(40)<<left << "\t "<<"_____________________________"<<endl;
	cout<<setw(40)<<left <<"\t "<<"Mang vua nhap la: ";
	for(int i=0; i<n; i++){
		setConsoleColor(0);
		cout<<" ";
		setConsoleColor(240);
		cout<<" "<<a[i]<<" ";}
	setConsoleColor(11);
	cout<<endl<<setw(40)<<left<<"\t "<<"_____________________________"<<endl<<endl;
    resetConsoleColor();
	
}


void nhapLaiDuLieu(int*& a, int& n)
{
    
    while (true) {
    	setConsoleColor(15);
    	cout << "Nhap so phan tu cua mang: ";
        if (cin >> n) {
            break; 
        } else {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
			 setConsoleColor(207);
            cout << "\t Nhap khong hop le. Vui long nhap lai.\n";
        }
    }

    
    a = new int[n];

    for (int i = 0; i < n; i++) {
        while (true) {
        	setConsoleColor(15);
            cout << "Nhap phan tu thu a[" << i << "]: ";
            if (cin >> a[i]) {
                break; 
            } else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                setConsoleColor(207);
                cout << "\t Nhap khong hop le. Vui long nhap lai.\n";
            }
        }
    }
    xuatMang(n,a);
}

int main()
{
	int thoat=0;
    
    if(thoat>=0 && thoat<=4){//while
    setConsoleColor(15);
    hienthimenu(thoat);
    int* a;
	int n;
    system("cls");
		if(thoat == 0)
    {
    	nhapLaiDuLieu(a, n);
    	cout<<setw(35)<<left << "\t "; setConsoleColor(143);cout<<" Doi cho truc tiep (Interchange Sort) ";
    	cout<<endl<<endl;
		landoicho(n, a);//, 0);
		//delete[] a, thoat, n;
				
	}else if(thoat==1){
		nhapLaiDuLieu(a, n);
		cout<<setw(35)<<left << "\t "; setConsoleColor(143);cout<<" Chon truc tiep (Selection Sort) ";
    	cout<<endl<<endl;
		selectionSort(a, n);}//,1);}
	else if(thoat==2){
		nhapLaiDuLieu(a, n);
		cout<<setw(35)<<left << "\t "; setConsoleColor(143);cout<<" Chen (Insertion Sort) ";
    	cout<<endl<<endl;
		Chen(n,a);}//,2);}
	else if(thoat==3){
	
		nhapLaiDuLieu(a, n);
		cout<<setw(35)<<left << "\t "; setConsoleColor(143);cout<<" Noi bot (Bubble Sort) ";
    	cout<<endl<<endl;
    	NoiBot(n,a);//,3);
    	}
    else if(thoat==4){
    	nhapLaiDuLieu(a, n);
		cout<<setw(35)<<left << "\t "; setConsoleColor(143);cout<<" Nhanh (Quick Sort)  ";
    	cout<<endl<<endl;
    	setConsoleColor(15);
    	quickSort(a, 0, n - 1);
    	xuatmangsx(n,a);
    	/*char b;
    	do
    	{
        b = getch();
    	}while(b!=13 );
    	system("cls");
    	fflush(stdin);*/
    	
    	}	
	
	}
	
	
	return 0;
}
