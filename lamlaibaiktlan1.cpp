#include <stdio.h>
#include <stdlib.h>
struct chuyenbay
{
	char ma[6];
	int timebay;
	char noidi[21], noiden[21];
	int ngay, thang, nam;
};

//1.	Viết hàm nhập một chuyến bay và xuất chuyến bay
void nhapthongtinbay(chuyenbay& mb)
{
	printf("\nNhap ma chuyen bay (toi da 5 ki tu):");
	fgets(mb.ma, sizeof(mb.ma), stdin);
	while (getchar() != '\n');//xoa ki tu xuong dong
	printf("Nhap ngay bay :");
	scanf_s("%d", &mb.ngay);
	printf("\nNhap thang bay:");
	scanf_s("%d", &mb.thang);
	printf("\nNhap nam:");
	scanf_s("%d", &mb.nam);
	printf("\nNhap thoi luong bay du kien:");
	scanf_s("%d", &mb.timebay);
	printf("\nNhap noi di:");
	fgets(mb.noidi, sizeof(mb.noidi), stdin);
	while (getchar() != '\n');//xoa ki tu xuong dong
	printf("\nNhap noi den:");
	fgets(mb.noiden, sizeof(mb.noiden), stdin);
	while (getchar() != '\n');//xoa ki tu xuong dong
}
//3.	Nhập danh sách các chuyến bay gồm n chuyến bay.
void Nhapmang(chuyenbay mb[], int n)
{

	for (int i = 0; i < n; i++)
		nhapthongtinbay(mb[i]);
}

void xuatchuyenbay(chuyenbay mb)
{
	printf("\nMa chuyen bay: %s", mb.ma);
	printf("\nNgay bay: %d/%d/%d", mb.ngay, mb.thang, mb.nam);
	printf("\nThoi luong bay (phut): %d", mb.timebay);
	printf("\nNoi di:%s", mb.noidi);
	printf("\nNoi den:%s", mb.noiden);
}
void xuatmang(chuyenbay mb[], int n)
{

	printf("Cac chuyen bay da nhap:");
	for (int i = 0; i < n; i++)
		xuatchuyenbay(mb[i]);
}
//2.	Hãy cho biết chuyến bay đó là chuyến bay dài hay chuyến bay ngắn dựa vào thông tin thời lượng bay. Nếu thời lượng bay>600 phút thì chuyến bay dài, ngược lại là chuyến bay ngắn.
void kiemtra(chuyenbay mb[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (mb[i].timebay > 600)
			printf("\nDay la mot chuyen bay dai");
		else
			printf("\nDay la mot chuyen bay ngan");
	}
}
//4.	Đếm trong danh sách các chuyến bay có bao nhiêu chuyến bay xuất phát từ Hà Nội
void demHaNoi(chuyenbay mb[], int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
		if (mb[i].noidi == "Ha Noi")
			count++;
	printf("\nTong co %d chuyen bay xuat phat tu Ha Noi", count);
}
//5.	Xuất các Mã chuyến bay trong danh sách chuyến bay có ngày bay là ngày 25/09/2024
void timchuyenbay(chuyenbay mb[], int n)
{
	for (int i = 0; i < n; i++) {
		if (mb[i].ngay == 25 && mb[i].thang == 9 && mb[i].nam == 2024)
			printf("\nMa chuyen bay xuat phat ngay 25/09/2024: %s", mb[i].ma);
	}

}

//6.	Sắp xếp danh sách chuyến bay tăng dần theo thời lượng bay theo thuật toán Interchange Sort
//void interchangesortdoitructiep(chuyenbay mb[], int n)
//{
//	for (int i = 0; i < n - 1; i++)
//		for (int j = i + 1; j < n; j++)
//			if (mb[i].timebay > mb[j].timebay)
//				swap(mb[i], mb[j]);
//}
//
//void swap(int* a, int* b)
//{
//	int* tmep = a;
//	a = b;
//	b = tmep;
//}
void main()
{
	chuyenbay mb[50];
	int luachon, n;
	do {
		printf("1.Nhap cac chuyen bay");
		printf("\n2.Kiem tra chuyen bay dai ngan");
		printf("\n3.Danh sach gom n chuyen bay");
		printf("\n4.Dem trong chuyen bay co bao nhieu chuyen xuat phat tu Ha Noi");
		printf("\n5.Nhung chuyen bay co ngay bay la ngay 25/9/2024");
		printf("\n6.Sap xep cac chuyen bay bang Interchange Sort");
		printf("\n7.Nhap vao danh sach co noi den duoc uu tien khuyen mai. Liet ke nhung chuyen bay co dich den nam trong danh sach khuyen mai do");
		printf("\n0.Thoat chuong trinh");
		printf("\nNhap so luong chuyen bay:");
		scanf_s("%d", &n);
		printf("\nChon chuc nang");
		scanf_s("%d", &luachon);
		switch (luachon)
		{
		case 1:
			Nhapmang(mb, n);
			xuatmang(mb, n); break;
		case 2:
			kiemtra(mb, n); break;
		case 3:
			xuatmang(mb, n); break;
		case 4:
			demHaNoi(mb, n);
			break;
		case 5:
			timchuyenbay(mb, n);
			break;
		case 6:
			break;
		case 7:
			break;
		default:
			printf("\nHay chon hop le!");
		case 0:
			return;
			break;
		}
	} while (luachon <= 0 && luachon > 7);
}
