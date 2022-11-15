#include <conio.h>
#include <stdio.h>

void input(int a[], int& n) //nhap so mang
{
	printf("nhap tong so phan tu that su: ");
	scanf_s("%d", &n);
	for (int i = 0;i < n; i++)
	{
		printf("nhap gia tri phan tu thu %d ", i);
		scanf_s("%d", &a[i]);
	}
}

void output(int a[], int& n) //kiem tra mang
{
	printf("mang co %d phan tu, gom: ",n );
	for (int i = 0;i < n;i++)
	{
		printf("%3d",a[i]);
	}
}

void output2(int a[], int& n) //sap xep mang
{
	printf("\n mang sau khi duoc sap sep ",n);
	for (int i = 0;i < n;i++)
	{
		printf("%3d", a[i]);
	}
}

void output3(int a[], int& n) //them 
{
	printf(" ", n);
	for (int i = 0;i < n-1;i++)
	{
		printf("%d \t", a[i]);
	}
}

int find(int a[], int n, int x) //tim gia tri co trong mang
{
	int i;
	for (i = 0; i < n;i++)
		if (a[i] == x)
			break;
	if (i < n)
		return i;
	return -1;
}

void swap(int& x, int& y) //khai bao dang tham chieu (them &) moi thay doi gia tri.
{
	int temp = x;
	x = y;
	y = temp;
}

void sortlow(int a[], int n) //sort giam dan
{
	for (int i = 0;i < n - 1;i++)
		for (int j = i;j < n;j++)
			if (a[i] < a[j])
				swap(a[i], a[j]);
}
void sorthight(int a[], int n) //sort tang dan
{
	for (int i = 0;i < n - 1;i++)
		for (int j = i;j < n;j++)
			if (a[i] > a[j])
				swap(a[i], a[j]);
}
void apend(int a[], int &n, int x)
{
	n = n + 1;
	a[n - 1] = x;
}
void removeAt(int a[], int &n, int x) 
{
	if (x < 0) {
		x = 0;
	}
	if (x >= n) {
		x = n - 1;
	}
	for (int i = x; i < n - 1; i++) {
		a[i] = a[i + 1];
	}
	//n--;
}
//removeend
//removeat
//insert
void main()
{
	int m[100];
	int n,x;
	// nhap tong so phan tu that su (n), sao do nhap gia tri cho n phan tu 
	input(m, n);
	output(m, n);

	
	sortlow(m, n);
	output2(m, n);

	sorthight(m, n);
	output2(m, n);

	//apend(m, n, 10000);


	printf("\nNHAP VI TRI CAN XOA: ");
	scanf_s("%d", &x);
	removeAt(m, n, x);
	printf("\nMANG SAU KHI XOA TAI A[%d]\n", x);
	output3(m, n);

	printf("nhap gia tri can tim: ");
	scanf_s("%d", &x);
	if (find(m, n, x) == -1)
	{
		printf(" khong tim thay %d trong mang\n", x);
	}
	else
		printf("tim thay %d tai vi tri %d trong mang", x, find(m, n, x));
		
	_getch();
}
