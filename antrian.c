#include <stdio.h>
#include<stdlib.h>
#include <stdio.h>

struct daerah {
char kel[50];
char kec[50];
char kota[50];
};

struct data {
int nomor;
char nama[50];
char agama[20];
char status[20];
char pekerjaan[20];
char tempat[20];
char tanggal[20];
char almt[20];
struct daerah alamat;
};

typedef struct {
int base[100];
char base1[100][20];
int depan;
int belakang;
}
queue; // Queue adalah antrian, dimana data yang datang pertama kali akan dipanggil pertama kali juga.
queue antrian;
queue nama;

char base1[20];
int base, i, j;

int isEmpty () {
if (antrian.belakang == -1)
return 1;
else
return 0;
}

int isFull () {
if (antrian.belakang == 100)
return 1;
else
return 0;
}

void enqueu (int base, char base1[20]) { //Menambahkan data dari queue

if(isEmpty() == 1) { // Mengecek apakah queue kosong atau tidak

 antrian.depan = antrian.belakang = 0;
 nama.depan = nama.belakang = 0;
 antrian.base[antrian.belakang] = base;

 for (i=0; i<20; i++) {
nama.base1[nama.belakang][i] = base1[i];
 }
 printf(" Silahkan menunggu pangilan");
 
 
}else if(isFull() == 0) {  // Mengecek apakah queue sudah penuh atau belum
 antrian.belakang++;
 nama.belakang++;
 antrian.base[antrian.belakang] = base;

 for (i=0; i<20; i++) {
 nama.base1[nama.belakang][i] = base1[i];
 }
printf(" Silahkan menunggu pangilan");
}
}

void dequeue () { //Mengambil data dari queue

if (isEmpty() == 0) {
 
int i, e;
char a[20];
e = antrian.base[antrian.depan];

for (i=0; i<20; i++) {
 a[i] = nama.base1[nama.depan][i];
}

for (i=antrian.depan; i<antrian.belakang; i++) {
antrian.base[i] = antrian.base[i+1];
for (j=0; j<20; j++) {
nama.base1[i][j] = nama.base1[i+1][j];
}
}
antrian.belakang--;
nama.belakang--;
printf (" Antrian dengan no %i dengan nama %s silahkan masuk", e, a);
}else {
printf (" Antrian kosong");
}
}


void baru() {

antrian.depan = antrian.belakang = -1;
nama.depan = nama.belakang = -1;
}


int main() {
int menu;
int nik=-1, x, y;
int n;
baru();
n=1;
int pilih;
int namedit;
struct data ktp[20];
struct daerah alamat;
char get[1];
bool ketemu; // membuat var dengan type data boolean
 


menuutama:
system("cls"); // membersihkan layar pada bahasa pemrogram c
 
printf(" ----------------Sistem Administrasi Kependudukan (2021) ---------------");
printf(" \nMENU UTAMA :\n\n");
printf(" 1. Registrasi Antrian\n\n");
printf(" 2. Panggil Antrian\n\n");
printf(" 3. Menambah Data Penduduk\n\n");
printf(" 4. Mencari Data Penduduk\n\n");
printf(" 5. Menghapus Data Penduduk\n\n");
printf(" 6. Menampilkan Data Penduduk\n\n");
printf(" 7. Keluar\n\n");
printf(" ___________\n\n");
printf(" Masukan Pilihan Anda (1-7) : ");
scanf("%d", &menu);

if(menu==1) {
system("cls");
 
printf("\n REGISTRASI ANTRIAN \n");
printf("__________\n\n");
printf("\nNomor antrian anda adalah : %d ", n);

base = n;
printf("\nMasukkan nama (*gunakan tanda (_) untuk spasi) : ");
scanf(" %s", base1);
printf("\n");
 
enqueu(base, base1);
 
n++;
printf("\n");
 
printf("_______________________\n\n");
printf(" 1.Kembali ke Menu Utama\n\n");
printf(" 2.Keluar dari program\n");
printf(" ___________\n\n");
printf(" Masukan Pilihan Anda : ");
scanf("%d", &pilih);
printf("\n");

if(pilih == 1) {
goto menuutama;
}
else if(pilih == 2) {
goto keluar;
}
}

else if(menu == 2) {
system("cls"); 
 
printf("\n PEMANGGILAN ANTRIAN \n");
printf("__________\n\n");
dequeue();
printf("\n");
printf("_______________________\n\n");
printf(" 1.Kembali ke Menu Utama\n\n");
printf(" 2.Keluar dari program\n");
printf("___________\n\n");
printf(" Masukan Pilihan Anda : ");
scanf("%d", &pilih);
 
if(pilih == 1) {
goto menuutama;
}
else if(pilih == 2) {
goto keluar;
}
}
if(menu == 3) {
system("cls");
 
nik++;
printf("\n PENAMBAHAN DATABASE DATA PENDUDUK\n");
printf("______________\n\n");
printf("**INGAAAT !!!gunakan tanda (_) untuk spasi !!!**\n\n");
printf(" NIK (max 5 karakter)  : ");
scanf("%d", &ktp[nik].nomor);
printf("\nNama Lengkap  : ");
scanf("%s", ktp[nik].nama);
printf(" \nAgama : ");
scanf("%s", ktp[nik].agama);
printf("\nStatus Perkawinan : ");
scanf(" %s", ktp[nik].status);
printf("\nPekerjaan : ");
scanf(" %s", ktp[nik].pekerjaan);
printf("\nTempat Lahir  : ");
scanf(" %s", ktp[nik].tempat);
printf("\nTanggal Lahir (DD MM YYYY) : ");
scanf(" %s", ktp[nik].tanggal);
printf("\nAlamat : ");
scanf(" %s", ktp[nik].almt);
printf("\nKelurahan : ");
scanf(" %s", ktp[nik].alamat.kel);
printf("\nKecamatan : ");
scanf(" %s", ktp[nik].alamat.kec);
printf("\nKota/Kabupaten : ");
scanf(" %s", ktp[nik].alamat.kota);
 
 

printf("_______________\n\n");
printf(" 1.Kembali ke menu awal\n\n");
printf(" 2.Keluar dari program\n");
printf("___________\n\n");
printf(" Masukan Pilihan Anda : ");
scanf("%d", &pilih);
if(pilih == 1) {
goto menuutama;
}
else if(pilih == 2) {
goto keluar;
}
}

else if(menu == 4) {
system ("cls");
printf("\n PENCARIAN DATA PENDUDUK\n");
printf("__________\n\n");
printf(" Masukan NIK : ");
scanf("%d", &namedit);
printf("\n");
 
for(x=0; x<=nik; x++) {
if(namedit==ktp[x].nomor) {
printf(" Database Data Penduduk ke-%d\n\n", x+1);
printf(" NIK : %d\n\n", ktp[x].nomor);
printf(" Nama : %s\n\n", ktp[x].nama);
printf(" Agama : %s\n\n", ktp[x].agama);
printf(" Status Perkawinan : %s\n\n", ktp[x].status);
printf(" Pekerjaan : %s\n\n", ktp[x].pekerjaan);
printf(" Tempat Lahir : %s\n\n", ktp[x].tempat);
printf(" Tanggal Lahir : %s\n\n", ktp[x].tanggal);
printf(" Alamat : %s\n\n", ktp[x].almt);
printf(" Kelurahan : %s\n\n", ktp[x].alamat.kel);
printf(" Kecamatan : %s\n\n", ktp[x].alamat.kec);
printf(" Kota/Kabupaten : %s\n\n\n\n", ktp[x].alamat.kota);
printf("___________________\n\n");
goto menu0;
 
}
}

printf(" DATA YANG ANDA CARI TIDAK DI TEMUKAN !!!\n\n");
printf(" ______________\n\n");
 
menu0:
printf(" 1.Kembali ke Menu Utama\n\n");
printf(" 2.Keluar dari program\n");
printf(" ___________\n\n");
printf(" Masukan Pilihan Anda : ");
scanf("%d", &pilih);
if(pilih == 1) {
goto menuutama;
}
else if(pilih == 2) {
goto keluar;
}
 }

else if(menu == 5) {
system ("cls");
printf("\n PENGHAPUSAN DATA PENDUDUK PADA DATABASE\n");
printf("_________________\n\n");
printf("NIK : ");
scanf("%d", &namedit);
printf("\n");
 
for(x=0; x<=nik; x++) {
if(namedit==ktp[x].nomor) {
ketemu = true;
 
if(ketemu) {
for(y=x; y<=nik+1; y++) {
ktp[y]=ktp[y+1];
}
printf(" DATA BERHASIL DI HAPUS\n\n");
nik--;
goto menu;
}
} 
}
printf("DATA YANG AKAN DI HAPUS TIDAK DITEMUKAN !!!\n");
printf("________________\n\n");
 
menu:
printf(" 1.Kembali ke Menu Utama\n\n");
printf(" 2.Keluar dari program\n");
printf(" ___________\n\n");
printf(" Masukan Pilihan Anda : ");
scanf("%d", &pilih);
 
if(pilih == 1) {
goto menuutama;
}
else if(pilih == 2) {
goto keluar;
}
}

else if(menu == 6) {
 system ("cls");
 printf ("\n MENAMPILKAN DATA PENDUDUK (KTP)\n");
 printf ("___________\n\n");
 for(x=0; x<=nik; x++) {

printf (" Database Data Penduduk ke-%d\n\n", x+1);
printf (" NIK : %d\n\n", ktp[x].nomor);
printf (" Nama : %s\n\n", ktp[x].nama);
printf (" Agama : %s\n\n", ktp[x].agama);
printf (" Status Perkawinan : %s\n\n", ktp[x].status);
printf (" Pekerjaan : %s\n\n", ktp[x].pekerjaan);
printf (" Tempat Lahir : %s\n\n", ktp[x].tempat);
printf (" Tanggal Lahir : %s\n\n", ktp[x].tanggal);
printf (" Alamat : %s\n\n", ktp[x].almt);
printf (" Kelurahan : %s\n\n", ktp[x].alamat.kel);
printf (" Kecamatan : %s\n\n", ktp[x].alamat.kec);
printf (" Kota/Kabupaten : %s\n\n\n\n", ktp[x].alamat.kota);
 }
 
printf ("_______________\n\n");
printf (" 1.Kembali ke menu awal\n\n");
printf (" 2.Keluar dari program\n");
printf (" ___________\n\n");
printf (" Masukan Pilihan Anda : ");
scanf("%d", &pilih);
if(pilih == 1) {
goto menuutama;
}
else if(pilih == 2) {
goto keluar;
}

keluar:
system("cls");
printf ("\n________ TERIMA KASIH ________\n");
return 0;
}

else if(menu == 7) {
system("cls");
printf ("\n________ TERIMA KASIH ________\n");
return 0;
}
}