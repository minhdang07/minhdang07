#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct sinhvien
{
    int MSSV; //ma so sinh vien
    char HOTEN[50]; //ho ten lay theo kieu du lieu char
    int NGAYSINH; //ngay sinh 
    float DTB; //diem trung binh
 
};

int menu()
{
    printf("************************MENU***********************");
    printf("\n* [1] In danh sach sinh vien                      *");
    printf("\n* [2] Sap xep giam dan theo diem trung binh       *");
    printf("\n* [3] Lay ra sinh vien co diem trung binh cao nhat*");
    printf("\n* [4] Them sinh vien tu MSSV                      *");
    printf("\n* [5] Xoa sinh vien theo MSSV                     *");
    printf("\n* [6] Tim sinh vien theo ten Sinh Vien            *");
    printf("\n* [7] THOAT                                       *");
    printf("\n***************************************************");
    printf("\nLUA CHON [1-7]:");
    int cn;
    scanf_s("%d", &cn);
    return cn;
}
//NHAP THONG TIN SV
void Input(sinhvien sv[], int n)
{
    /*for (int i = 0; i < n; i++)
    {
        cout << "====================";
        //cout << "Nhap sinh vien thu", i;
        cout << "\nNhap ma sinh vien: ";
        cin >> sv[i].MSSV;
        cout << "Nhap ho va ten sinh vien: ";
        cin >> sv[i].HOTEN;
        cout << "Nhap ngay sinh: ";
        cin >> sv[i].NGAYSINH;
        cout << "Nhap diem trung binh: ";
        cin >> sv[i].DTB;
        cout << "\n====================";
    }*/
    for (int i = 0; i < n; i++)
    {
        printf("****************************************************************\n");
        printf("\nNhap sinh vien thu %d", i + 1);

        printf("\nNhap ma sinh vien: ");
        scanf_s("%d", &sv[i].MSSV);
        //fgets(sv[i].MSSV, sizeof(sv[i].MSSV), stdin);
        //gets(sv[i].MSSV);
        printf("\nNhap ho ten sinh vien: ");
        fgets(sv[i].HOTEN, sizeof(sv[i].HOTEN), stdin);
        gets_s(sv[i].HOTEN);
        printf("\nNhap ngay sinh: ");
        scanf_s("%d", &sv[i].NGAYSINH);

        printf("\nNhap diem trung binh: ");
        scanf_s("%f", &sv[i].DTB);
        printf("\n****************************************************************\n");
    }
}
//XUAT RA THONG TIN SV + TU DONG SAP XEP THEO MSSV
void Output(sinhvien sv[], int n)
{
    for (int i = 0; i < n;i++)
    {
        for (int j = i + 1;j < n;j++)
        {
            if (sv[i].MSSV > sv[j].MSSV)
            {
                sinhvien temp = sv[i];
                sv[i] = sv[j];
                sv[j] = temp;
            }
        }
    }
    //cout << "MaSV \t Ho va ten \t Ngay sinh \t Diem trung binh \n";
    /*for (int i = 0; i<n; i++)
    {
        //cout << sv[i].MSSV, sv[i].HOTEN,  sv[i].NGAYSINH,  sv[i].DTB;
        cout << "MaSV: " << sv[i].MSSV << endl;
        cout << "Ho va ten: " << sv[i].HOTEN << endl;
        cout << "Ngay sinh: " << sv[i].NGAYSINH << endl;
        cout << "Diem trung binh: " << sv[i].DTB << endl;

    }*/
    printf("\nDANH SACH SINH VIEN:\n");
    printf("\nMaSV \t Ho va Ten \t Ngay Sinh \t Diem trung binh\n");
    for (int i = 0; i < n; i++)
    {
        /*printf("MaSV: %d \n", sv[i].MSSV);
        printf("Ho va ten: %s", sv[i].HOTEN);
        printf("Ngay sinh: %d \n", sv[i].NGAYSINH);
        printf("Diem trung binh: %0.2f \n", sv[i].DTB);*/
        //printf("%s", sv[i].MSSV);
        //printf("%s\t",sv[i].MSSV,"%s\t",sv[i].HOTEN,"%d\t",sv[i].NGAYSINH,"%0.2f",sv[i].DTB);
        printf("%d \t %s \t \t %d \t\t %0.2f \n", sv[i].MSSV, sv[i].HOTEN, sv[i].NGAYSINH, sv[i].DTB);
        //printf("%-10s %-10s %-20s %-10s %-10s %-10s %-10s %-10s %-10s %-10s\n",
            //"Ma SV", "Ho", "Dem", "Ten", "Tuoi", "Gioi Tinh",
            //"Diem Toan", "Diem Van", "Diem Anh", "Diem TBC");
    }
}
//SAP XEP THEO DIEM TRUNG BINH GIAM DAN
void sortPAVG(sinhvien sv[], int n)
{
    for (int i = 0;i < n - 1;i++)
    {
        for (int j = i + 1;j < n;j++)
        {
            if (sv[i].DTB < sv[j].DTB)
            {
                sinhvien temp = sv[i];
                sv[i] = sv[j];
                sv[j] = temp;
            }

        }
    }
    printf("\nDANH SACH SINH VIEN SAU KHI DUOC SAP XEP GIAM DAN\n");
    printf("MaSV \t Ho va Ten \t Ngay Sinh \t Diem trung binh\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d \t %s \t \t %d \t\t %0.2f \n", sv[i].MSSV, sv[i].HOTEN, sv[i].NGAYSINH, sv[i].DTB);
    }
}
//CHON RA TOP SINH VIEN CO DIEM TRUNG BINH CAO
void Top(sinhvien sv[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (sv[i].DTB < sv[j].DTB)
            {
                sinhvien temp = sv[i];
                sv[i] = sv[j];
                sv[j] = temp;
            }
    for (int i = 0; i < n;i++)
    {
        for (int j = i + 1;j < n;j++)
        {
            if (sv[i].DTB < sv[i].DTB)
            {
                sinhvien temp = sv[i];
                sv[i] = sv[j];
                sv[j] = temp;
            }
        }
    }
    printf("So TOP can lay: ");
    scanf_s("%d", &n);
    printf("TOP \t MaSV \t Ho va Ten \t Ngay Sinh \t Diem trung binh\n");
    for (int i = 0; i < n;i++)
    {
        printf("%d \t %d \t %s \t \t %d \t\t %0.2f \n",i+1, sv[i].MSSV, sv[i].HOTEN, sv[i].NGAYSINH, sv[i].DTB);
    }
}
void AddSV(sinhvien sv[], int n)
{

    int add;
    cout << "SO SINH VIEN BAN MUON THEM:" << endl;
    cin >> add;
    int j = n;
    n += add;
    for (int i = j;i < n;i++)
    {
        cout << "SINH VIEN THU " << i << endl;
        Input(sv, n);
        for (int i = 0; i < n; i++)
        {
            /*printf("MaSV: %d \n", sv[i].MSSV);
            printf("Ho va ten: %s", sv[i].HOTEN);
            printf("Ngay sinh: %d \n", sv[i].NGAYSINH);
            printf("Diem trung binh: %0.2f \n", sv[i].DTB);*/
            //printf("%s", sv[i].MSSV);
            //printf("%s\t",sv[i].MSSV,"%s\t",sv[i].HOTEN,"%d\t",sv[i].NGAYSINH,"%0.2f",sv[i].DTB);
            printf("%d \t %s \t \t %d \t\t %0.2f \n", sv[i].MSSV, sv[i].HOTEN, sv[i].NGAYSINH, sv[i].DTB);
            //printf("%-10s %-10s %-20s %-10s %-10s %-10s %-10s %-10s %-10s %-10s\n",
                //"Ma SV", "Ho", "Dem", "Ten", "Tuoi", "Gioi Tinh",
                //"Diem Toan", "Diem Van", "Diem Anh", "Diem TBC");
        }
    }
}
int xoaTheoID(sinhvien sv[], int id, int n) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (sv[i].MSSV == id) {
            found = 1;
          
            //printLine(40);
            for (int j = i; j < n; j++) {
                sv[j] = sv[j + 1];
            }
            cout << "\n Da xoa SV co ID = " << id;
            //printLine(40);
            break;
        }
    }
    if (found == 0) {
        printf("\n Sinh vien co ID = %d khong ton tai.", id);
        return 0;
    }
    else {
        return 1;
    }
}
int main()
{
    sinhvien sv[50];
    int n;
    char c;
    char cc;
    
    printf("\t \t \t \t \tCHUONG TRINH QUAN LY SINH VIEN\n \n");
    neww://DUNG DE NHAP LAI DANH SACH MOI
    do
    {
        printf("Nhap so sinh vien: ");
        scanf_s("%d", &n);
        if (n < 1 || n>50)
        {
            printf("\n============================================================\n\n");
            printf("Vui long nhap lai so sinh vien (KHONG DUOC QUA 50 SINH VIEN)\n\n");
            printf("============================================================\n\n");
        }
    } while (n < 1 || n>50);
    {
        Input(sv, n);//THONG TIN 
        tryagain://DUNG DE LAP LAI DANH SACH
        int cn = menu();//MENU
        switch (cn)
        {
        case 1://IN RA DANH SACH SINH VIEN
            Output(sv, n);
            break;
        case 2: //SAP XEP THEO DIEM TRUNG BINH GIAM DAN
            sortPAVG(sv, n);
            break;
        case 3: //LAY RA TOP
            Top(sv, n);
            break;
        case 4://THEM SINH VIEN
            AddSV(sv, n);
            //xoaTheoID(sv,n);
            break;
        case 5://XOA SINH VIEN
            //xoaTheoID(sv,id, n);
            break;
        case 6://TIM SINH VIEN
            break;
        case 7://THOAT
            exit(0);
            break;
        }
        cout << "BAN CO MUON TIEP TUC? [Y/N]: " << endl;
        cin >> c;
        if (c == 'y')
        {
            cout << "**************************************************" << endl;
            cout << "BAN CO MUON DUNG LAI DANH SACH CU KHONG? [Y/N]: " << endl;
            cin >> cc;
            if (cc == 'y')
            {
                cout << "**************************************************" << endl;
                goto tryagain;
            }
            else
            {
                cout << "**************************************************" << endl;
                goto neww;
            }
        }
        else
        {
            exit(0);
        }
  
    }
}
