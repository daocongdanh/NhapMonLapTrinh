#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
int n;
int a[1000];
void nhap(int a[], int n);
void xuat(int a[], int n);
int Timmax(int a[], int n);
int Timmin(int a[],int n);
int binarysearch(int a[], int n, int x);
void bosung(int a[], int n, int x);
void chen(int a[], int n, int x, int k);
void xoa(int a[], int n, int k);
void merge(int a[], int l, int m, int r);
void mergeSort(int a[], int l, int r);
void selectionSort(int a[], int n);
int nt(int n);
int ntdigit(int n);
int checknt(int n);
void xuatchan(int a[], int n);
void xuatle(int a[], int n);
int cp(int n);
int tn(int n);
int Sphenic(int n);
int Smith(int n);
int sumdigit(int n);
int sodep(int n);
int fibonacci(int n);
int tongarray(int a[], int n);
void speak(int n);
int sumchan(int a[], int n);
int sumle(int a[], int n);
int sumnguyento(int a[], int n);
int sumthuannt(int a[], int n);
int sumcp(int a[], int n);
int sumtn(int a[], int n);
int sumSphenic(int a[], int n);
int sumSmith(int a[], int n);
int sumsodep(int a[], int n);
int sumfibonacci(int a[], int n);
int arraytangdan(int a[], int n);
int arraygiamdan(int a[], int n);
int arraydx(int a[], int n);
void arraylatnguoc(int a[], int n);
int binarysearch1(int a[], int n, int x);
int binarysearch2(int a[], int n, int x);
int binarysearch3(int a[], int n, int x);
int binarysearch4(int a[], int n, int x);
//----------------game con ran------------//
void Nocursortype()//an con tro
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void gotoxy(int x, int y)
{
    static HANDLE h = NULL;  
    if(!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };  
    SetConsoleCursorPosition(h,c);
}
void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}
//------------------1 nguoi choi-------------//
typedef struct Snake Snake;
enum Trangthai{//trang thai cua con ran
	UP,RIGHT,DOWN,LEFT
};
struct Toado{
	int x,y;//toa do cua con ran
};
struct Hoaqua{
	int x,y;//toa do hoa qua
};
struct kitu{
	int x,y;
};
struct Snake{
	Toado dot[30];//con ran co toi da 30 dot
	int n;// n dot
	Trangthai tt;
};
void khoi_tao(Snake &snake,Hoaqua &hq,int &diem,kitu &kt);
void xoa_kitu(kitu &kt, Snake &snake);//luu ki tu cuoi xoa de len(k can dung lenh xoa man hinh);
void hien_thi(Snake snake,Hoaqua hq, int diem);
void dieu_khien(Snake &snake);
void xu_ly(Snake &snake,Hoaqua &hq,int &diem,kitu &kt, int &thoigian);
int game_over(Snake snake);
void ve_tuong();
void play();
//-----------------------2 nguoi choi--------------------//
typedef struct Snake1 snake1;
typedef struct Snake2 snake2;
struct Hoaqua12{
	int x,y;//toa do hoa qua
};
enum Trangthai1{
	len,phai,xuong,trai
};
struct Toado1{
	int x,y;//toa do con ran
};
struct kitu1{
	int x,y;
};
struct Snake1{
	Toado1 dot[30];//Con ran co toi da 30 dot
	int n;//con ran co n dot
	Trangthai1 tt;
};
enum Trangthai2{
	LEN,PHAI,XUONG,TRAI
};
struct Toado2{
	int x,y;
};
struct kitu2{
	int x,y;
};
struct Snake2{
	Toado2 dot[30];
	int m;
	Trangthai2 tt;
};
void ve_tuong12();
void khoi_tao_snake12(Snake1 &snake1,Snake2 &snake2,Hoaqua12 &hq,int &diem1, int &diem2,kitu1 &kt1, kitu2 &kt2);
void xoa_kitu12(kitu1 &kt1, kitu2 &kt2,Snake1 &snake1,Snake2 &snake2);
void hien_thi_snake12(Snake1 snake1, Snake2 snake2,Hoaqua12 hq,int diem1, int diem2);
void dieu_khien_snake12(Snake1 &snake1, Snake2 &snake2);
void xu_ly_snake12(Snake1 &snake1,Snake2 &snake2,Hoaqua12 &hq, int &diem1, int &diem2,kitu1 &kt1, kitu2 &kt2);
int game_over_snake12(Snake1 snake1,Snake2 snake2,int diem1, int diem2);//tra ve 1 gia tri khi thua
void play12();
//--------------------------------------------------//
int main(){
	int lua_chon;
	do{
		printf("\n");
		printf("1.Nhap cac phan tu cua mang\n");
		printf("2.Xuat cac phan tu cua mang\n");
		printf("3.Tim Max\n");
		printf("4.Tim Min\n");
		printf("5.Tim phan tu X\n");
		printf("6.Bo sung phan tu\n");
		printf("7.Chen phan tu vao vi tri k\n");
		printf("8.Xoa phan tu thu k\n");
		printf("9.Sap xep day so tang dan\n");
		printf("10.Sap xep day so giam dan\n");
		printf("11.Xuat tat ca cac so nguyen to co trong mang\n");
		printf("12.Xuat tat ca cac so nguyen to co tat ca cac chu so la so nguyen to\n");
		printf("13.Xuat tat ca cac so thuan nguyen to (no la so nguyen to, tat ca chu so la so nguyen to, tong cac chu so la so nguyen to)\n");
		printf("14.Xuat tat ca so chan\n");
		printf("15.Xuat tat ca so le\n");
		printf("16.Xuat tat ca so chinh phuong\n");
		printf("17.Xuat tat ca so thuan nghich\n");
		printf("18.Xuat tat ca so Sphenic(la so duoc phan tich duy nhat duoi dang cua tich 3 so khac nhau)\n");
		printf("19.Xuat tat ca so Smith(khong phai la so nguyen to va tong cac chu so cua N bang tong cac chu so cua cac uoc so nguyen to N)\n");
		printf("20.Xuat tat ca so dep(la so co tong cac uoc that su k tinh no bang chinh no)\n");
		printf("21.Xuat tat ca so fibonacci\n");
		printf("22.Tinh tong cac so trong mang\n");
		printf("23.Doc tat ca so trong mang(toi da 5 chu so)\n");
		printf("24.Tong cac so chan\n");
		printf("25.Tong cac so le\n");
		printf("26.Tong cac so nguyen to\n");
		printf("27.Tong cac so thuan nguyen to\n");
		printf("28.Tong cac so chinh phuong\n");
		printf("29.Tong cac so thuan nghich\n");
		printf("30.Tong cac so Sphenic\n");
		printf("31.Tong cac so Smith\n");
		printf("32.Tong cac so dep\n");
		printf("33.Tong cac so fibonacci\n");
		printf("34.Kiem tra mang tang dan\n");
		printf("35.Kiem tra mang giam dan\n");
		printf("36.Kiem tra mang doi xung\n");
		printf("37.Lat nguoc mang\n");
		printf("38.Tim vi tri xuat hien dau tien cua phan tu X trong mang\n");
		printf("39.Tim vi tri xuat hien cuoi cung cua phan tu X trong mang\n");
		printf("40.Tim vi tri xuat hien dau tien cua phan tu >= X trong mang\n");
		printf("41.Tim vi tri xuat hien dau tien cua phan tu > X trong mang\n");
		printf("42.Giai tri nao =))\n");
		printf("43.Ket thuc chuong trinh!!!\n");
		printf("Nhap lua chon cua ban:");
		scanf("%d",&lua_chon);
		switch(lua_chon){
			case 1:{
				printf("Nhap so phan tu cua mang:\n");
				scanf("%d",&n);
				nhap(a,n);
				break;
			}
			case 2:{
				xuat(a,n);
				break;
			}
			case 3:{
				printf("Gia tri lon nhat la: %d\n",Timmax(a,n));
				break;
			}
			case 4:{
				printf("Gia tri nho nhat la: %d\n",Timmin(a,n));
				break;
			}
			case 5:{
				int x;
				printf("Nhap phan tu can tim: ");
				scanf("%d",&x);
				if(binarysearch(a,n,x)==1){
					printf("Da tim thay !!!\n");
				}
				else{
					printf("Khong tim thay !!!\n");
				}
				break;
			}
			case 6:{
				int x;
				printf("Nhap phan tu can bo sung: ");
				scanf("%d",&x);
				bosung(a,n,x);
				n++;
				break;
			}
			case 7:{
				int x,k;
				printf("Nhap phan tu x va vi tri can chen: ");
				scanf("%d%d",&x,&k);
				chen(a,n,x,k);
				n++;
				break;
			}
			case 8:{
				int k;
				printf("Nhap vi tri can xoa: ");
				scanf("%d",&k);
				xoa(a,n,k);
				n--;
				break;
			}
			case 9:{
				mergeSort(a,0,n-1);
				break;
			}
			case 10:{
				selectionSort(a,n);
				break;
			}
			case 11:{
				for(int i=0;i<n;i++){
					if(nt(a[i])){
						printf("%d ",a[i]);
					}
				}
				printf("\n");
				break;
			}
			case 12:{
				for(int i=0;i<n;i++){
					if(ntdigit(a[i])){
						printf("%d ",a[i]);
					}
				}
				printf("\n");
				break;
			}
			case 13:{
				for(int i=0;i<n;i++){
					if(nt(a[i])&&ntdigit(a[i]) && checknt(a[i])){
						printf("%d ",a[i]);
					}
				}
				printf("\n");
				break;
			}
			case 14:{
				xuatchan(a,n);
				break;
			}
			case 15:{
				xuatle(a,n);
				break;
			}
			case 16:{
				for(int i=0;i<n;i++){
					if(cp(a[i])){
						printf("%d ",a[i]);
					}
				}
				printf("\n");
				break;
			}
			case 17:{
				for(int i=0;i<n;i++){
					if(tn(a[i])){
						printf("%d ",a[i]);
					}
				}
				printf("\n");
				break;
			}
			case 18:{
				for(int i=0;i<n;i++){
					if(Sphenic(a[i])){
						printf("%d ",a[i]);
					}
				}
				printf("\n");
				break;
			}
			case 19:{
				for(int i=0;i<n;i++){
					if(Smith(a[i])){
						printf("%d ",a[i]);
					}
				}
				printf("\n");
				break;
			}
			case 20:{
				for(int i=0;i<n;i++){
					if(sodep(a[i])){
						printf("%d ",a[i]);
					}
				}
				printf("\n");
				break;
			}
			case 21:{
				for(int i=0;i<n;i++){
					if(fibonacci(a[i])){
						printf("%d ",a[i]);
					}
				}
				printf("\n");
				break;
			}
			case 22:{
				printf("%d",tongarray(a,n));
				printf("\n");
				break;
			}
			case 23:{
				for(int i=0;i<n;i++){
					if(a[i]>99999){
						printf("%d khong doc duoc\n",a[i]);
					}
					else{
						printf("%d ",a[i]);
						speak(a[i]);
						printf("\n");
					}
				}
				printf("\n");
				break;
			}
			case 24:{
				printf("%d",sumchan(a,n));
				printf("\n");
				break;
			}
			case 25:{
				printf("%d",sumle(a,n));
				printf("\n");
				break;
			}
			case 26:{
				printf("%d",sumnguyento(a,n));
				printf("\n");
				break;
			}
			case 27:{
				printf("%d",sumthuannt(a,n));
				printf("\n");
				break;
			}
			case 28:{
				printf("%d",sumcp(a,n));
				printf("\n");
				break;
			}
			case 29:{
				printf("%d",sumtn(a,n));
				printf("\n");
				break;
			}
			case 30:{
				printf("%d",sumSphenic(a,n));
				printf("\n");
				break;
			}
			case 31:{
				printf("%d",sumSmith(a,n));
				printf("\n");
				break;
			}
			case 32:{
				printf("%d",sumsodep(a,n));
				printf("\n");
				break;
			}
			case 33:{
				printf("%d",sumfibonacci(a,n));
				printf("\n");
				break;
			}
			case 34:{
				if(arraytangdan(a,n)) printf("YES");
    			else printf("NO");
				break;
			}
			case 35:{
				if(arraygiamdan(a,n)){
					printf("YES\n");
				}
				else{
					printf("NO\n");
				}
				break;
			}
			case 36:{
				if(arraydx(a,n)){
					printf("YES\n");
				}
				else{
					printf("NO\n");
				}
				break;
			}
			case 37:{
				arraylatnguoc(a,n);
				break;
			}
			case 38:{
				int x;
				printf("Nhap phan tu can tim: ");
				scanf("%d",&x);
				printf("%d\n",binarysearch1(a,n,x));
				break;
			}
			case 39:{
				int x;
				printf("Nhap phan tu can tim: ");
				scanf("%d",&x);
				printf("%d\n",binarysearch2(a,n,x));
				break;
			}
			case 40:{
				int x;
				printf("Nhap phan tu can tim: ");
				scanf("%d",&x);
				printf("%d\n",binarysearch3(a,n,x));
				break;
			}
			case 41:{
				int x;
				printf("Nhap phan tu can tim: ");
				scanf("%d",&x);
				printf("%d\n",binarysearch4(a,n,x));
				break;
			}
			case 42:{
				int lua_chon;
				do{
					system("cls");
					printf("\n\n\n\n\n\n");
					printf("\t\t\t\tCHAO MUNG CAC BAN DEN VOI GAME RAN SAN MOI\n");
					printf("\t\t\t\t1.Choi 1 minh\n");
					printf("\t\t\t\t2.Choi 2 minh\n");
					printf("\t\t\t\t3.Khong choi nua :v\n");
					printf("\t\t\t\tChon dai 1 cai di nao: ");
					scanf("%d",&lua_chon);
					system("cls");
					switch(lua_chon){
						case 1:{
							play();
							break;
						}
						case 2:{
							play12();
							break;
						}
					}
				}while(lua_chon<3);
				break;
			}
		}
	}while(lua_chon<43);
}
void nhap(int a[], int n){
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
}
void xuat(int a[], int n){
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}
int Timmax(int a[], int n){
	int max=-1e9;
	for(int i=0;i<n;i++){
		if(a[i]>max){
			max=a[i];
		}
	}
	return max;
}
int Timmin(int a[],int n){
	int min=1e9;
	for(int i=0;i<n;i++){
		if(a[i]<min){
			min=a[i];
		}
	}
	return min;
}
int binarysearch(int a[], int n, int x){
	int l=0,r=n-1;
	while(l<=r){
		int m=(l+r)/2;
		if(a[m]==x){
			return 1;
		}
		else if(a[m]<x){
			l=m+1;
		}
		else{
			r=m-1;
		}
	}
	return 0;
}
void bosung(int a[], int n, int x){
	a[n]=x;	
}
void chen(int a[], int n, int x, int k){
	for(int i=n-1;i>=k;i--){
		a[i+1]=a[i];
	}
	a[k]=x;
}
void xoa(int a[], int n, int k){
	for(int i=k;i<n;i++){
		a[i]=a[i+1];
	}
}
void merge(int a[],int l, int m, int r){
	int n1 = m - l +1;
	int n2 = r-m;
	int x[n1], y[n2];
	for(int i=0;i<n1;i++){
		x[i] = a[i+l];
	}
	for(int i=0;i<n2;i++){
		y[i] = a[m+1+i];
	}
	int index=l;
	int i=0, j=0;
	while(i<n1 && j<n2){
		if(x[i]<=y[j]){
			a[index++] = x[i++];
		}
		else{
			a[index++] = y[j++];
		}
	}
	while(i<n1){
		a[index++] = x[i++];
	}
	while(j<n2){
		a[index++] = y[j++];
	}
}
void mergeSort(int a[], int l, int r){
	if(l<r){
		int m=(l+r)/2;
		mergeSort(a,l,m);
		mergeSort(a,m+1,r);
		merge(a,l,m,r);
	}
}
void selectionSort(int a[], int n){
	for(int i=0;i<n-1;i++){
		int min_pos=i;
		for(int j=i+1;j<n;j++){
			if(a[j]>a[min_pos]){
				min_pos=j;
			}
		}
		int tmp=a[i];
		a[i]=a[min_pos];
		a[min_pos]=tmp;
	}
}
int nt(int n){
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			return 0;
		}
	}
	return n>1;
}
int ntdigit(int n){
	while(n){
		int div = n%10;
		if(nt(div)==0) return 0;
		n/=10;
	}
	return 1;
}
int checknt(int n){
	int sum=0;
	while(n){
		sum+=n%10;
		n/=10;
	}
	return nt(sum);
}
void xuatchan(int a[], int n){
	for(int i=0;i<n;i++){
		if(a[i]%2==0){
			printf("%d ",a[i]);
		}
	}
	printf("\n");
}
void xuatle(int a[], int n){
	for(int i=0;i<n;i++){
		if(a[i]%2!=0){
			printf("%d ",a[i]);
		}
	}
	printf("\n");
}
int cp(int n){
	int can=sqrt(n);
	if(can*can==n){
		return 1;
	}
	else{
		return 0;
	}
}
int tn(int n){
	int tmp=n;
	int cnt=0;
	while(n){
		cnt = cnt*10+n%10;
		n/=10;
	}
	return tmp==cnt;
}
int Sphenic(int n){
	int dem=0;//dem cac uoc
	for(int i=2;i<=sqrt(n);i++){
		int cnt=0;//dem so mu
		while(n%i==0){
			cnt++;
			n/=i;
		}
		if(cnt>=2) return 0;
		if(cnt==1){
			dem++;
		}
	}
	if(n!=1) dem++;
	if(dem==3){
		return 1;
	}
	else{
		return 0;
	}
}
int sumdigit(int n){
	int sum=0;
	while(n){
		sum+=n%10;
		n/=10;
	}
	return sum;
}
int Smith(int n){
	int tmp=n;
	int sum1 = sumdigit(n);
	int sum2=0;
	for(int i=2;i<=sqrt(n);i++){
		while(n%i==0){
			sum2+=sumdigit(i);
			n/=i;
		}
	}
	if(tmp==n) return 0;
	if(n!=1){
		sum2+=sumdigit(n);
	}
	return sum1==sum2;
}
int sodep(int n){
	int sum=0;
	for(int i=1;i<sqrt(n);i++){
		if(n%i==0){
			if(i!=n/i){
				sum+=i + n/i;
			}
			else{
				sum+=i;
			}
		}
	}
	if(sum-n==n){
		return 1;
	}
	else{
		return 0;
	}
}
int fibonacci(int n){
	if(n==1) return 1;
	int f1=0, f2=1, fn;
	for(int i=2;i<=92;i++){
		fn=f1+f2;
		if(fn==n) return 1;
		f1=f2;
		f2=fn;
	}
	return 0;
}
int tongarray(int a[], int n){
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=a[i];
	}
	return sum;
}
void speak(int n){
	if(n>=0 && n<=9){
		switch(n){
			case 0: printf("Khong"); break;
			case 1: printf("Mot"); break;
			case 2: printf("Hai"); break;
			case 3: printf("Ba"); break;
			case 4: printf("Bon"); break;
			case 5: printf("Nam"); break;
			case 6: printf("Sau"); break;
			case 7: printf("Bay"); break;
			case 8: printf("Tam"); break;
			case 9: printf("Chin"); break;
		}
	}
	else if(n>=10 && n<=99){
		switch(n/10){
			case 1: printf("Muoi "); break;
			case 2: printf("Hai muoi "); break;
			case 3: printf("Ba muoi "); break;
			case 4: printf("Bon muoi "); break;
			case 5: printf("Nam muoi "); break;
			case 6: printf("Sau muoi "); break;
			case 7: printf("Bay muoi "); break;
			case 8: printf("Tam muoi "); break;
			case 9: printf("Chin muoi "); break;
		}
		switch(n%10){
			case 1: printf("mot"); break;
			case 2: printf("hai"); break;
			case 3: printf("ba"); break;
			case 4: printf("bon"); break;
			case 5: printf("nam"); break;
			case 6: printf("sau"); break;
			case 7: printf("bay"); break;
			case 8: printf("tam"); break;
			case 9: printf("chin"); break;
		}
	}
	else if(n>=100 && n<=999){
		switch(n/100){
			case 1: printf("Mot tram "); break;
			case 2: printf("Hai tram "); break;
			case 3: printf("Ba tram "); break;
			case 4: printf("Bon tram "); break;
			case 5: printf("Nam tram "); break;
			case 6: printf("Sau tram "); break;
			case 7: printf("Bay tram "); break;
			case 8: printf("Tam tram "); break;
			case 9: printf("Chin tram "); break;
		}
		switch((n%100)/10){
			case 0:
				if((n%100)%10!=0) printf("le "); break;
			case 1: printf("muoi "); break;
			case 2: printf("hai muoi "); break;
			case 3: printf("ba muoi "); break;
			case 4: printf("bon muoi "); break;
			case 5: printf("nam muoi "); break;
			case 6: printf("sau muoi "); break;
			case 7: printf("bay muoi "); break;
			case 8: printf("tam muoi "); break;
			case 9: printf("chin muoi "); break;
		}
		switch((n%100)%10){
			case 1: printf("mot"); break;
			case 2: printf("hai"); break;
			case 3: printf("ba"); break;
			case 4: printf("bon"); break;
			case 5: printf("nam"); break;
			case 6: printf("sau"); break;
			case 7: printf("bay"); break;
			case 8: printf("tam"); break;
			case 9: printf("chin"); break;
		}
	}
	else if(n>=1000 && n<=9999){
		switch(n/1000){
			case 1: printf("Mot ngan "); break;
			case 2: printf("Hai ngan "); break;
			case 3: printf("Ba ngan "); break;
			case 4: printf("Bon ngan "); break;
			case 5: printf("Nam ngan "); break;
			case 6: printf("Sau ngan "); break;
			case 7: printf("Bay ngan "); break;
			case 8: printf("Tam ngan "); break;
			case 9: printf("Chin ngan "); break;
		}
		switch((n%1000)/100){
			case 0: 
			if((n%1000)%100!=0) printf("khong tram "); break;
			case 1: printf("mot tram "); break;
			case 2: printf("hai tram "); break;
			case 3: printf("ba tram "); break;
			case 4: printf("bon tram "); break;
			case 5: printf("nam tram "); break;
			case 6: printf("sau tram "); break;
			case 7: printf("bay tram "); break;
			case 8: printf("tam tram "); break;
			case 9: printf("chin tram "); break;
		}
		switch(((n%1000)%100)/10){
			case 0: 
			if(((n%1000)%100)%10!=0)printf("le "); break;
			case 1: printf("muoi "); break;
			case 2: printf("hai muoi "); break;
			case 3: printf("ba muoi "); break;
			case 4: printf("bon muoi "); break;
			case 5: printf("nam muoi "); break;
			case 6: printf("sau muoi "); break;
			case 7: printf("bay muoi "); break;
			case 8: printf("tam muoi "); break;
			case 9: printf("chin muoi "); break;
		}
		switch(((n%1000)%100)%10){
			case 1: printf("mot"); break;
			case 2: printf("hai"); break;
			case 3: printf("ba"); break;
			case 4: printf("bon"); break;
			case 5: printf("nam"); break;
			case 6: printf("sau"); break;
			case 7: printf("bay"); break;
			case 8: printf("tam"); break;
			case 9: printf("chin"); break;
		}
	}
	else if(n>=10000 && n<=99999){
		switch(n/10000){
			case 1: printf("Muoi "); break;
			case 2: printf("Hai muoi "); break;
			case 3: printf("Ba muoi "); break;
			case 4: printf("Bon muoi "); break;
			case 5: printf("Nam muoi "); break;
			case 6: printf("Sau muoi "); break;
			case 7: printf("Bay muoi "); break;
			case 8: printf("Tam muoi "); break;
			case 9: printf("Chin muoi "); break;
		}
		switch((n%10000)/1000){
			case 0: printf("ngan ");break;
			case 1: printf("mot ngan "); break;
			case 2: printf("hai ngan "); break;
			case 3: printf("ba ngan "); break;
			case 4: printf("bon ngan "); break;
			case 5: printf("nam ngan "); break;
			case 6: printf("sau ngan "); break;
			case 7: printf("bay ngan "); break;
			case 8: printf("tam ngan "); break;
			case 9: printf("chin ngan "); break;
		}
		switch(((n%10000)%1000)/100){
			case 0: 
			if(((n%10000)%1000)%100!=0)printf("khong tram "); break;
			case 1: printf("mot tram "); break;
			case 2: printf("hai tram "); break;
			case 3: printf("ba tram "); break;
			case 4: printf("bon tram "); break;
			case 5: printf("nam tram "); break;
			case 6: printf("sau tram "); break;
			case 7: printf("bay tram "); break;
			case 8: printf("tam tram "); break;
			case 9: printf("chin tram "); break;
		}
		switch((((n%10000)%1000)%100)/10){
			case 0: 
			if(((n%10000)%1000)%100%10!=0)printf("le "); break;
			case 1: printf("muoi "); break;
			case 2: printf("hai muoi "); break;
			case 3: printf("ba muoi "); break;
			case 4: printf("bon muoi "); break;
			case 5: printf("nam muoi "); break;
			case 6: printf("sau muoi "); break;
			case 7: printf("bay muoi "); break;
			case 8: printf("tam muoi "); break;
			case 9: printf("chin muoi "); break;
		}
		switch((((n%10000)%1000)%100)%10){
			case 1: printf("mot"); break;
			case 2: printf("hai"); break;
			case 3: printf("ba"); break;
			case 4: printf("bon"); break;
			case 5: printf("nam"); break;
			case 6: printf("sau"); break;
			case 7: printf("bay"); break;
			case 8: printf("tam"); break;
			case 9: printf("chin"); break;
		}
	}
}
int sumchan(int a[], int n){
	int sum=0;
	for(int i=0;i<n;i++){
		if(a[i]%2==0){
			sum+=a[i];
		}
	}
	return sum;
}
int sumle(int a[], int n){
	int sum=0;
	for(int i=0;i<n;i++){
		if(a[i]%2!=0){
			sum+=a[i];
		}
	}
	return sum;
}
int sumnguyento(int a[], int n){
	int sum=0;
	for(int i=0;i<n;i++){
		if(nt(a[i])){
			sum+=a[i];
		}
	}
	return sum;
}
int sumthuannt(int a[], int n){
	int sum=0;
	for(int i=0;i<n;i++){
		if(nt(a[i]) && ntdigit(a[i]) && checknt(a[i])){
			sum+=a[i];
		}
	}
	return sum;
}
int sumcp(int a[], int n){
	int sum=0;
	for(int i=0;i<n;i++){
		if(cp(a[i])){
			sum+=a[i];
		}
	}
	return sum;
}
int sumtn(int a[], int n){
	int sum=0;
	for(int i=0;i<n;i++){
		if(tn(a[i])){
			sum+=a[i];
		}
	}
	return sum;
}
int sumSphenic(int a[], int n){
	int sum=0;
	for(int i=0;i<n;i++){
		if(Sphenic(a[i])){
			sum+=a[i];
		}
	}
	return sum;
}
int sumSmith(int a[], int n){
	int sum=0;
	for(int i=0;i<n;i++){
		if(Smith(a[i])){
			sum+=a[i];
		}
	}
	return sum;
}
int sumsodep(int a[], int n){
	int sum=0;
	for(int i=0;i<n;i++){
		if(sodep(a[i])){
			sum+=a[i];
		}
	}
	return sum;
}
int sumfibonacci(int a[], int n){
	int sum=0;
	for(int i=0;i<n;i++){
		if(fibonacci(a[i])){
			sum+=a[i];
		}
	}
	return sum;
}
int arraytangdan(int a[], int n){
	for(int i=0;i<n-1;i++){
        if(a[i]>=a[i+1]) return 0;
    }
    return 1;
}
int arraygiamdan(int a[], int n){
	for(int i=0;i<n-1;i++){
        if(a[i]<=a[i+1]) return 0;
    }
    return 1;
}
int arraydx(int a[], int n){
	int l=0, r=n-1;
	while(l<=r){
		if(a[l]!=a[r]){
			return 0;
		}
		l++,r--;
	}
	return 1;
}
void arraylatnguoc(int a[], int n){
	int l=0, r=n-1;
	while(l<=r){
		int tmp=a[l];
		a[l]=a[r];
		a[r]=tmp;
		l++,r--;
	}
}
int binarysearch1(int a[], int n, int x){
	int res=-1;
	int l=0, r=n-1;
	while(l<=r){
		int m=(l+r)/2;
		if(a[m]==x){
			res=m;
			r=m-1;//tim them ben trai
		}
		else if(a[m]>x){
			r = m-1;
		}
		else{
			l=m+1;
		}
	}
	return res;
}
int binarysearch2(int a[], int n, int x){
	int res=-1;
	int l=0, r=n-1;
	while(l<=r){
		int m=(l+r)/2;
		if(a[m]==x){
			res=m;
			l=m+1;//tim them ben phai
		}
		else if(a[m]>x){
			r = m-1;
		}
		else{
			l=m+1;
		}
	}
	return res;
}
int binarysearch3(int a[], int n, int x){
	int res=-1;
	int l=0, r=n-1;
	while(l<=r){
		int m=(l+r)/2;
		if(a[m]>=x){
			res=m;
			r=m-1;
		}
		else{
			l=m+1;
		}
	}
	return res;
}
int binarysearch4(int a[], int n, int x){
	int res=-1;
	int l=0, r=n-1;
	while(l<=r){
		int m=(l+r)/2;
		if(a[m]>x){
			res=m;
			r=m-1;
		}
		else{
			l=m+1;
		}
	}
	return res;
}
//----------------------1 nguoi choi-------------------//
void play(){
	Nocursortype();
	Snake snake;
	Hoaqua hq;
	kitu kt;
	int diem;
	int thoigian=220;
	khoi_tao(snake,hq,diem,kt);
	srand(time(NULL));
	ve_tuong();
	while(1){
		xoa_kitu(kt,snake);
		//hien thi
		hien_thi(snake,hq,diem);
		//dieu khien
		dieu_khien(snake);
		//xu ly an qua
		xu_ly(snake,hq,diem,kt,thoigian);
		//thua game
		if(game_over(snake)==-1){
			gotoxy(38,10);
			printf("BAN GA` VAI !!!");
			while(getch()!=13);
			break;
		}
		Sleep(thoigian);
	}
}
void khoi_tao(Snake &snake,Hoaqua &hq, int &diem,kitu &kt){
	snake.n=1;//ban dau con ran co 1 dot
	snake.dot[0].x=1;//Cai dau con ran
	snake.dot[0].y=3;
	snake.tt=RIGHT;//Ban dau con ran di sang ben phai
	kt.x=snake.dot[snake.n - 1].x;//luu ki tu duoi
	kt.y=snake.dot[snake.n - 1].y;//luu ki tu duoi
	hq.x=20, hq.y=10;
	diem=0;
}
void xoa_kitu(kitu &kt, Snake &snake){
	gotoxy(kt.x,kt.y);
	printf(" ");
	kt.x=snake.dot[snake.n - 1].x;
	kt.y=snake.dot[snake.n - 1].y;
}
void ve_tuong(){
	textcolor(8);
	for(int i=0;i<=93;i++){
		gotoxy(i,20);
		printf("%c",219);
	}
	for(int i=0;i<=93;i++){
		gotoxy(i,2);
		printf("%c",219);
	}
	for(int i=0;i<=20;i++){
		gotoxy(0,i);
		printf("%c",219);
	}
	for(int i=2;i<=20;i++){
		gotoxy(93,i);
		printf("%c",219);
	}
	for(int i=0;i<=9;i++){
		gotoxy(i,0);
		printf("%c",219);
	}
	gotoxy(9,1);
	printf("%c",219);
}
void hien_thi(Snake snake,Hoaqua hq, int diem){
	textcolor(9);
	gotoxy(hq.x,hq.y);
	printf("%c",254);
	textcolor(13);
	gotoxy(snake.dot[0].x,snake.dot[0].y);
	printf("%c",153);
	for(int i=1;i<snake.n;i++){
		gotoxy(snake.dot[i].x,snake.dot[i].y);
		printf("%c",233);
	}
	gotoxy(1,1);
	printf("SCORE:%d",diem);
	gotoxy(0,0);
}
void dieu_khien(Snake &snake){
	for(int i=snake.n - 1;i>0;i--){
		snake.dot[i]=snake.dot[i-1];
	}
	if(kbhit()){
		char key = getch();
		switch(key){
			case 'w':{
				if(snake.tt!=DOWN)
					snake.tt=UP;
				break;
			}
			case 'd':{
				if(snake.tt!=LEFT)
					snake.tt=RIGHT;
				break;
			}
			case 's':{
				if(snake.tt!=UP)
					snake.tt=DOWN;
				break;
			}
			case 'a':{
				if(snake.tt!=RIGHT)
					snake.tt=LEFT;
				break;
			}
		}
	}
	if(snake.tt==UP){
		snake.dot[0].y--;
	}
	else if(snake.tt==RIGHT){
		snake.dot[0].x++;
	}
	else if(snake.tt==DOWN){
		snake.dot[0].y++;
	}
	else if(snake.tt==LEFT){
		snake.dot[0].x--;
	}
	
}
void xu_ly(Snake &snake,Hoaqua &hq,int &diem,kitu &kt,int &thoigian){//rand()%(max-min+1) +min
	if(snake.dot[0].x==hq.x && snake.dot[0].y == hq.y){
		hq.x=1 + rand()%92;//max =92
		hq.y=3 + rand()%17;//max =19
		snake.n++;
		snake.dot[snake.n - 1].x=kt.x;//them 1 dot o duoi
		snake.dot[snake.n - 1].y=kt.y;//them 1 dot o duoi
		diem++;
		if(thoigian>40){
			thoigian-=30;
		}
	}
}
int game_over(Snake snake){//tra ve -1 khi thua
	if(snake.dot[0].x==0 || snake.dot[0].x==93 || snake.dot[0].y==2 || snake.dot[0].y==20){
		return -1;
	}
	for(int i=1;i<snake.n;i++){
		if(snake.dot[0].x==snake.dot[i].x && snake.dot[0].y==snake.dot[i].y ){
			return -1;
		}
	}
	return 0;
}
//--------------------------2 nguoi choi------------------------//
void play12(){
	Nocursortype();
	Snake1 snake1;
	Snake2 snake2;
	kitu1 kt1;
	kitu2 kt2;
	Hoaqua12 hq;
	int diem1, diem2;
	khoi_tao_snake12(snake1, snake2,hq,diem1,diem2,kt1,kt2);
	ve_tuong12();
	while(1){
		xoa_kitu12(kt1,kt2,snake1,snake2);
		//hien thi
		hien_thi_snake12(snake1,snake2,hq,diem1,diem2);
		//dieu khien
		dieu_khien_snake12(snake1,snake2);
		//xu ly
		xu_ly_snake12(snake1,snake2,hq,diem1,diem2,kt1,kt2);
		//thua game
		int over = game_over_snake12(snake1,snake2,diem1,diem2);
		if(over==-1){
			gotoxy(38,10);
			printf("NGUOI CHOI THU 2 THANG!!!");
			while(getch()!=13);
			break;
		}
		else if(over==-2){
			gotoxy(38,10);
			printf("NGUOI CHOI THU 1 THANG!!!");
			while(getch()!=13);
			break;
		}
		else if(over==-3){
			gotoxy(38,10);
			printf("NGUOI CHOI THU 1 THANG!!!");
			while(getch()!=13);
			break;
		}
		else if(over==-4){
			gotoxy(38,10);
			printf("NGUOI CHOI THU 2 THANG!!!");
			while(getch()!=13);
			break;
		}
		else if(over==-5){
			gotoxy(38,10);
			printf("HAI NGUOI CHOI HOA NHAU!!!");
			while(getch()!=13);
			break;
		}
		Sleep(150);
	}
}
void ve_tuong12(){
	textcolor(8);
	for(int i=0;i<=93;i++){
		gotoxy(i,20);
		printf("%c",219);
	}
	for(int i=0;i<=93;i++){
		gotoxy(i,2);
		printf("%c",219);
	}
	for(int i=0;i<=20;i++){
		gotoxy(0,i);
		printf("%c",219);
	}
	for(int i=0;i<=20;i++){
		gotoxy(93,i);
		printf("%c",219);
	}
	for(int i=0;i<=9;i++){
		gotoxy(i,0);
		printf("%c",219);
	}
	gotoxy(9,1);
	printf("%c",219);
	for(int i=84;i<=93;i++){
		gotoxy(i,0);
		printf("%c",219);
	}
	gotoxy(84,1);
	printf("%c",219);
}
void khoi_tao_snake12(Snake1 &snake1,Snake2 &snake2,Hoaqua12 &hq,int &diem1, int &diem2,kitu1 &kt1, kitu2 &kt2){
	//ran 1
	snake1.n=1;
	snake1.dot[0].x=1;
	snake1.dot[0].y=3;
	snake1.tt = phai;
	kt1.x=snake1.dot[snake1.n - 1].x;
	kt1.y=snake1.dot[snake1.n - 1].y;
	//ran 2
	snake2.m=1;
	snake2.dot[0].x=1;
	snake2.dot[0].y=19;
	snake2.tt = PHAI;
	kt2.x=snake2.dot[snake2.m - 1].x;
	kt2.y=snake2.dot[snake2.m - 1].y;
	hq.x=35,hq.y=10;
	diem1=0, diem2=0;
}
void xoa_kitu12(kitu1 &kt1, kitu2 &kt2,Snake1 &snake1,Snake2 &snake2){
	gotoxy(kt1.x,kt1.y);
	printf(" ");
	kt1.x=snake1.dot[snake1.n - 1].x;
	kt1.y=snake1.dot[snake1.n - 1].y;
	gotoxy(kt2.x,kt2.y);
	printf(" ");
	kt2.x=snake2.dot[snake2.m - 1].x;
	kt2.y=snake2.dot[snake2.m - 1].y;
}
void hien_thi_snake12(Snake1 snake1, Snake2 snake2,Hoaqua12 hq,int diem1, int diem2){
	textcolor(13);
	gotoxy(snake1.dot[0].x,snake1.dot[0].y);
	printf("%c",153);
	for(int i=1;i<snake1.n;i++){
		gotoxy(snake1.dot[i].x,snake1.dot[i].y);
		printf("%c",233);
	}
	gotoxy(1,1);
	printf("SCORE:%d",diem1);
	textcolor(2);
	gotoxy(snake2.dot[0].x,snake2.dot[0].y);
	printf("%c",232);
	for(int i=1;i<snake2.m;i++){
		gotoxy(snake2.dot[i].x,snake2.dot[i].y);
		printf("%c",233);
	}
	gotoxy(85,1);
	printf("SCORE:%d",diem2);
	textcolor(9);
	gotoxy(hq.x,hq.y);
	printf("%c",254);
	
	
}
void dieu_khien_snake12(Snake1 &snake1, Snake2 &snake2){
	for(int i=snake1.n - 1;i>0;i--){
		snake1.dot[i]=snake1.dot[i-1];
	}
	if(kbhit()){
		char key = getch();
		switch(key){
			case 'w':{
				if(snake1.tt!=xuong)
					snake1.tt=len;
				break;
			}
			case 'd':{
				if(snake1.tt!=trai)
					snake1.tt=phai;
				break;
			}
			case 's':{
				if(snake1.tt!=len)
					snake1.tt=xuong;
				break;
			}
			case 'a':{
				if(snake1.tt!=phai)
					snake1.tt=trai;
				break;
			}
		}
	}
	if(snake1.tt==len){
		snake1.dot[0].y--;
	}
	else if(snake1.tt==phai){
		snake1.dot[0].x++;
	}
	else if(snake1.tt==xuong){
		snake1.dot[0].y++;
	}
	else if(snake1.tt==trai){
		snake1.dot[0].x--;
	}
	//ran 2
	for(int i=snake2.m - 1;i>0;i--){
		snake2.dot[i]=snake2.dot[i-1];
	}
	if(kbhit()){
		char key = getch();
		switch(key){
			case 72:{//len
				if(snake2.tt!=XUONG)
					snake2.tt=LEN;
				break;
			}
			case 77:{//phai
				if(snake2.tt!=TRAI)
					snake2.tt=PHAI;
				break;
			}
			case 80:{//xuong
				if(snake2.tt!=LEN)
					snake2.tt=XUONG;
				break;
			}
			case 75:{//trai
				if(snake2.tt!=PHAI)
					snake2.tt=TRAI;
				break;
			}
		}
	}
	if(snake2.tt==LEN){
		snake2.dot[0].y--;
	}
	else if(snake2.tt==PHAI){
		snake2.dot[0].x++;
	}
	else if(snake2.tt==XUONG){
		snake2.dot[0].y++;
	}
	else if(snake2.tt==TRAI){
		snake2.dot[0].x--;
	}
}
void xu_ly_snake12(Snake1 &snake1,Snake2 &snake2,Hoaqua12 &hq,int &diem1, int &diem2, kitu1 &kt1, kitu2 &kt2){
	for(int i=1;i<snake1.n;i++){
		if(snake2.dot[0].x==snake1.dot[i].x && snake2.dot[0].y==snake1.dot[i].y){
			snake1.n--;
			for(int j=i;j<snake1.n;j++){
				snake1.dot[j]=snake1.dot[j+1];
			}
			snake2.m++;
			snake2.dot[snake2.m - 1].x=kt2.x;//them 1 dot o duoi
			snake2.dot[snake2.m - 1].y=kt2.y;//them 1 dot o duoi
			diem1--;
			diem2++;
		}
	}
	for(int i=1;i<snake2.m;i++){
		if(snake1.dot[0].x==snake2.dot[i].x && snake1.dot[0].y==snake2.dot[i].y){
			snake2.m--;
			for(int j=i;j<snake2.m;j++){
				snake2.dot[j]=snake2.dot[j+1];
			}
			snake1.n++;
			snake1.dot[snake1.n - 1].x=kt1.x;//them 1 dot o duoi
			snake1.dot[snake1.n - 1].y=kt1.y;//them 1 dot o duoi
			diem2--;
			diem1++;
		}
	}
	if(snake1.dot[0].x==hq.x && snake1.dot[0].y==hq.y){
		hq.x=1 + rand()%92;//max =92, minx=1;
		hq.y=3 + rand()%17;//max =19, miny=3;
		snake1.n++;
		snake1.dot[snake1.n - 1].x=kt1.x;//them 1 dot o duoi
		snake1.dot[snake1.n - 1].y=kt1.y;//them 1 dot o duoi
		diem1++;
	}
	if(snake2.dot[0].x==hq.x && snake2.dot[0].y==hq.y){
		hq.x=1 + rand()%92;//max =92, minx=1;
		hq.y=3 + rand()%17;//max =19, miny=3;
		snake2.m++;
		snake2.dot[snake2.m - 1].x=kt2.x;//them 1 dot o duoi
		snake2.dot[snake2.m - 1].y=kt2.y;//them 1 dot o duoi
		diem2++;
	}
	
}
int game_over_snake12(Snake1 snake1,Snake2 snake2,int diem1, int diem2){
	if(snake1.dot[0].x==0 || snake1.dot[0].x==93 || snake1.dot[0].y==2 || snake1.dot[0].y==20){
		return -1;
	}
	for(int i=1;i<snake1.n;i++){
		if(snake1.dot[0].x==snake1.dot[i].x && snake1.dot[0].y==snake1.dot[i].y ){
			return -1;
		}
	}//ran 2 win
	if(snake2.dot[0].x==0 || snake2.dot[0].x==93 || snake2.dot[0].y==2 || snake2.dot[0].y==20){
		return -2;
	}
	for(int i=1;i<snake2.m;i++){
		if(snake2.dot[0].x==snake2.dot[i].x && snake2.dot[0].y==snake2.dot[i].y ){
			return -2;
		}
	}//ran 1 win
	if(snake1.dot[0].x==snake2.dot[0].x && snake1.dot[0].y==snake2.dot[0].y){
		if(diem1>diem2){
			return -3;//ran 1 win
		}
		else if(diem1<diem2){
			return -4;//ran 2 win
		}
		else return-5;//hoa
	}
}
