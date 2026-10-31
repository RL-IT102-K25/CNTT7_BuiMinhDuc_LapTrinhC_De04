#include <stdio.h>
#include <string.h>

struct TapHoa{
    int maHang;
    char tenHang[50];
    int soLuong;
    float donGia;
};

void xoaxuongdong(char str[]){
    int len = strlen(str);
    if(len > 0 && str[len - 1] == '\n'){
        str[len - 1] = '\0';
    }
}

int timbangma(struct TapHoa ds[], int soLuong, int ma){
    for(int i = 0 ; i < soLuong; i++){
        if(ds[i].maHang == ma){
            return i;
        }
    }
    return -1;
}

const char* thanhtien(float thanhtien){
    struct TapHoa th;
    th.soLuong * th.donGia;
}

int themmathang(struct TapHoa ds[], int soLuong){
    struct TapHoa th;
    if(soLuong == 50){
        printf("Tap hoa da day khong the them\n");
        return soLuong;
    }
    printf("Nhap ma mat hang can them: ");
    scanf("%d",&th.maHang);
    if(timbangma(ds, soLuong, th.maHang) != -1){
        printf("Ma da ton tai khong the them\n");
        return soLuong;
    }
    printf("Nhap ten hang: ");
    getchar();
    fgets(th.tenHang, sizeof(th.tenHang), stdin);
    xoaxuongdong(th.tenHang);
    
    do{
        printf("Nhap so luong: ");
        scanf("%d",&th.soLuong);
        if(th.soLuong < 0){
            printf("So luong khong hop le\n");
        }
    }while(th.soLuong < 0);

    do{
        printf("Nhap don gia: ");
        scanf("%f",&th.donGia);
        if(th.donGia <= 0){
            printf("So luong khong hop le\n");
        }
    }while(th.donGia <= 0);

    ds[soLuong] = th;
    printf("Them mat hang thanh cong\n");
    return soLuong + 1;
}

void hienthidanhsach(struct TapHoa ds[], int soLuong){
    if(soLuong == 0){
        printf("Rong khong the hien thi\n");
        return;
    }
    printf("%-15s|%-15s|%-15s|%-15s|%-15s\n", "Ma", "Ten","SL","DG","TT\n");
    for(int i = 0 ; i < soLuong; i++){
        printf("%-15d|%-15s|%-15d|%-15f|%-15d\n",
        ds[i].maHang, ds[i].tenHang,ds[i].soLuong,ds[i].donGia,thanhtien(soLuong));
    }
}

void capnhatmathang(struct TapHoa ds[], int soLuong){
    int ma;
    if(soLuong == 0){
        printf("Rong khong the cap nhat\n");
        return;
    }
    printf("Nhap ma can cap nhat: ");
    scanf("%d", &ma);
    int vitri = timbangma(ds, soLuong, ma);
    if(vitri == -1){
        printf("Khong tim thay ma can cap nhat");
        return;
    }
    printf("Nhap ten hang can cap nhat: ");
    getchar();
    fgets(ds[vitri].tenHang, sizeof(ds[vitri].tenHang), stdin);
    xoaxuongdong(ds[vitri].tenHang);
    
    do{
        printf("Nhap so luong: ");
        scanf("%d",&ds[vitri].soLuong);
        if(ds[vitri].soLuong < 0){
            printf("So luong khong hop le\n");
        }
    }while(ds[vitri].soLuong < 0);

    do{
        printf("Nhap don gia: ");
        scanf("%f",&ds[vitri].donGia);
        if(ds[vitri].donGia <= 0){
            printf("So luong khong hop le\n");
        }
    }while(ds[vitri].donGia <= 0);
    printf("Cap nhat thanh cong\n");
}

int xoamathang(struct TapHoa ds[], int soLuong){
    int ma;
    if(soLuong == 50){
        printf("Tap hoa da day khong the them\n");
        return soLuong;
    }
    printf("Nhap ma hang can xoa: ");
    scanf("%d", &ma);

    int vitri = timbangma(ds, soLuong, ma);
    if(vitri == -1){
        printf("Khong tim thay ma can cap nhat\n");
        return soLuong;
    }

    for( int i = vitri; i < soLuong - 1; i++){
        ds[i] = ds[i+1];
    }
    printf("Xoa thanh cong\n");
    return soLuong - 1;
}

void timmathang(struct TapHoa ds[], int soLuong){
    char timmathang[50];
    int timthay = 0;
    printf("Nhap ten can tim: ");
    getchar();
    fgets(timmathang, sizeof(timmathang), stdin);
    xoaxuongdong(timmathang);
    for( int i = 0 ; i < soLuong; i++){
        if(strstr(ds[i].tenHang, timmathang) != NULL){
            hienthidanhsach(&ds[i], 1);
            timthay == 1;
        }
    }
    if(timthay = 0){
        printf("Khong tim thay\n");
    }
}

void thongke(struct TapHoa ds[], int soLuong){
    if(soLuong == 0){
        printf("Danh sach rong\n");
        return;
    }
    float tongkho;
    for(int i = 0 ; i < soLuong; i++){
        tongkho += ds[i].soLuong;
        if(ds[i].soLuong < 5){
           hienthidanhsach(&ds[i], 1);
        }
    }
}

int main(){
    int soLuong = 0;
    struct TapHoa danhsach[50];
    int luachon;
    do{
        printf("=====QUAN LY MAT HANG=====\n");
        printf("1.THEM MAT HANG\n");
        printf("2.HIEN THI DANH SACH MAT HANG\n");
        printf("3.CAP NHAT MAT HANG THEO MA\n");
        printf("4.XOA MAT HANG THEO MA\n");
        printf("5.TIM MAT HANG THEO TEN\n");
        printf("6.THONG KE KHO HANG\n");
        printf("0.THOAT\n");
        printf("CHON CHUC NANG: ");
        scanf("%d",&luachon);
        switch (luachon)
        {
        case 1:
            soLuong = themmathang(danhsach, soLuong);
            break;
        case 2:
            hienthidanhsach(danhsach, soLuong);
            break;
        case 3:
            capnhatmathang(danhsach, soLuong);
            break;
        case 4:
            soLuong = xoamathang(danhsach, soLuong);
            break;
        case 5:
            timmathang(danhsach, soLuong);
            break;
        case 6:
            thongke(danhsach, soLuong);
            break;
        case 0:
            printf("Tam biet");
            break;    
        default:
        printf("Lua chon khong hop le");
            break;
        }
    }while(luachon != 0);
    return 0;
}
