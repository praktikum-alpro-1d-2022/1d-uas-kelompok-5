#include <iostream> // Di gunakan untuk menjalankan perintah input dan output. seperti cin, cout.
using namespace std;

//deklarasi fungsi
void login();
void menu();
void inputbuku();
void daftarbuku();
void peminjaman();
void pengembalian();
void laporan();
void exit();

struct buku{ //membuat struktur buku
    int kode,stock;
    char judul[20];
}buku[25]; //deklarasikan

struct pinjam{ //membuat struktur pinjam
    int kodepin,d,kode,tglpin,stock;
    char tglbalik[25];
    char namap[40];
    char alamat[40];
    char status;
}pinjam[25]; //deklarasikan

//deklarasi variabel global
int jmlbuk,a,c,f,g,h,i,j,jmlpin,kodepin,stock;
int b =-1;
int d =-1;
int e = 0;
char yn;

int main(){//body
    login();
}
void login(){
    system("cls");
    string user; //membuat var user dan pass bertipe string
    string pass;
	string* userPtr;  //membuat var pointer user dan pass
    string* passPtr;
    userPtr = &user; //var pointer sama dengan alamat memori var string
    passPtr = &pass;
    cout << "\n\n\n\n";
	cout << "\t\t ------- Program Sederhana Perpustakaan --------\n\n";
	cout << "\t\t\t Username : "; cin >> *userPtr; //input user dan pass kedalam pointer
	cout << "\t\t\t Password : "; cin >> *passPtr;
    if(user=="malik" && pass=="1234"){ //pengecekan user dan pass
        system("cls");
		cout << "\n\n\t\t Anda Berhasil Login. \n\n";
		system("pause");
		menu();
	}
    else{ //output berikut ketika user atau pass yang di input salah
        system("cls");
		cout << "\t\t Username atau Password Anda Salah \n";
   	    system("pause");
	 	login();
	}
}
void menu(){ //fungsi menu
    int pil; //var untuk input angka yang digunakan untuk memilih menu
    system("cls"); 
    cout << "\n\t---------- Menu ----------\n"; //cout tampilan menu utama
    cout << "\t 1. Input Buku              \n";
    cout << "\t 2. Daftar Buku             \n";
    cout << "\t 3. Peminjaman              \n";
    cout << "\t 4. Pengembalian            \n";
    cout << "\t 5. Laporan                 \n";
    cout << "\t 6. Exit                    \n";
    cout << "\t--------------------------  \n";
    cout << "\tMasukan Pilihan Anda[1 - 6] = "; cin >> pil; //input angka untuk memilih menu 
    switch (pil){
        case 1:
            inputbuku();
        case 2:
            daftarbuku();
        case 3:
            peminjaman();
        case 4:
            pengembalian();
        case 5:
            laporan();
        case 6:
            exit();
        default:
            system("cls");
            cout << "\n\n\t\tInput Yang Anda Masukkan, Tidak Ada Di Menu\n\n";
            system("pause");
            menu();
    }
}
void inputbuku(){ //fungsi input buku
    system("cls");
    cout << "\n\n\t\t\tInput Buku\n"; //input buku berdasarkan jumlah  buku yang mau di input
    cout << "\t\t\t__________\n\n\n";
    b++;
    cout << " Masukan Data Buku Ke \t\t: " << b+1;
    buku[b].kode = b+1; 
    cout << "\n Kode Buku \t\t\t: " << buku[b].kode;
    cout << "\n Judul Buku Contoh(BukuSaya)\t: ";   cin >> buku[b].judul;
    cout << " Jumlah Buku\t\t\t: ";                 cin >> buku[b].stock;
    cout << "\n Apakah Anda Ingin Menambahkan Data Lagi ? (y/n) : "; cin >> yn;
    if(yn=='y' || yn=='Y'){
        inputbuku();
    }
    else{
        system("cls");
        cout << "\n\n Data Berhasil Disimpan \n\n";
        system("pause");
        menu();
    }	
}
void daftarbuku(){ //fungsi daftar buku
    system("cls");
    cout << "\n\n\t\t\tDaftar Buku\n";
    cout << "\t\t\t___________\n\n\n";
    cout << "-----------------------------------------------------\n";
    cout << "No     Kode Buku        Judul Buku        Jumlah Buku\n";
    cout << "-----------------------------------------------------\n";
    for(c=0; c<=b; c++){
        buku[c].stock;
        cout << c+1 << "\t" << buku[c].kode << "\t" << buku[c].judul << "\t" << buku[c].stock << endl;
    }
    cout << endl;
    system("pause");
    menu();
}
void peminjaman(){ //fungsi peminjaman
    d++;
    system("cls");
    cout << "\n\n\t\t\tPeminjaman Buku : ";
    cout << "\n\t\t\t_________________\n\n\n";
    cout << " Masukan Data Pinjaman Ke \t: " << d+1;
    pinjam[d].kodepin = d+1;
    cout << "\n Kode Pinjaman \t\t\t: "      << pinjam[d].kodepin;
    cout << "\n Masukkan Kode Buku \t\t: "; cin >> pinjam[d].kode;
    for(c=0; c<=b; c++){
        if(buku[c].kode==pinjam[d].kode){
            cout << " Judul Buku \t\t\t: "    << buku[c].judul;
            cout << "\n Jumlah Buku \t\t\t: " << buku[c].stock;
            cout << "\n\n Nama Peminjam buku \t\t: ";   cin >> pinjam[d].namap;
            cout << " Alamat Peminjam \t\t: "       ;   cin >> pinjam[d].alamat;
            cout << " Tanggal Pinjam (DDMMYYYY)\t: ";   cin >> pinjam[d].tglpin;
            cout << " Berapa Hari? \t\t\t: "        ;   cin >> pinjam[d].tglbalik;
            cout << "\n Note: Maksimal Buku Yang Di Pinjam Adalah 1 Buku Perjudul\n";
            pinjam[d].stock=1;
            if(buku[c].stock - pinjam[d].stock >= 1){
                stock = 0;
                buku[c].stock=buku[c].stock-pinjam[d].stock;
                pinjam[d].status = 'y';
                cout << " Apakah Anda Ingin Menambahkan Data Lagi ? (y/n) : "; cin >> yn;
                if(yn=='y' || yn=='Y'){
                    peminjaman();
                }
                else{
                    system("cls");
                    cout << "\n\n Data Berhasil Disimpan \n\n";
                    system("pause");
                    menu();
                }
            }
            else{
                cout << " Maaf stock Buku Yang Ingin Anda Pinjam Itu Kurang\n";
                cout << " Silahkan Mencoba Beminjam Buku Yang Lain\n";
                cout << " Apakah Anda Ingin Mencoba Meminjam Buku Yang Lain? (y/n) : ";
                cin >> yn;
                if(yn=='y' || yn=='Y'){
                    peminjaman();
                }
                else{
                    menu();
                }
            }
        }
        else{
            d--;
            system("cls");
            cout << "\n\n Data Buku Tidak Ditemukan \n\n";
            system("pause");
            peminjaman();
        }
    }
}
void pengembalian(){ //fungsi pengembalian
    system("cls");
    cout << "\n\n\t\t\tPengembalian Buku\n";
    cout << "\t\t\t_________________\n\n\n";
    cout << "\n Masukan Kode Peminjaman : "; cin >> kodepin; //memasukan kode peminjaman
    for(f=0; f<=d; f++){
        if(kodepin==pinjam[f].kodepin){
            cout << " Nama Penyewa Buku \t\t: "<< pinjam[f].namap;
            cout << "\n Alamat Penyewa \t\t: " << pinjam[f].alamat << endl;
            for(e=0; e<=d; e++){
                if(pinjam[f].kode==buku[e].kode){
                    cout << " Judul Buku \t\t\t: " << buku[e].judul << endl;
                }
            }
            cout << " Tanggal Pinjam (DDMMYYYY)\t: "      << pinjam[f].tglpin;
            cout << "\n Lama Pinjam \t\t\t: "             << pinjam[f].tglbalik;
            cout << "\n Banyak Buku Yang Di Pinjam  \t: " << pinjam[f].stock;
            cout << "\n Status \t\t\t: "                  << pinjam[f].status;
            if((pinjam[f].status=='y') || (pinjam[f].status=='Y')){
                cout << " (di Pinjam) \n";
            }
            else{
                cout << " (di kembalikan) \n";
            }
            cout << "\n Sudah di kembalikan ? (y/n) \t: "; cin >> yn;
            if((yn=='y') || (yn=='Y')){
                pinjam[f].status='n';
                for(e=0; e<=d; e++){
                    if(pinjam[f].kode==buku[e].kode){
                        buku[e].stock=buku[e].stock+pinjam[f].stock;
                        pinjam[f].stock = 0;
                        cout << "\n\n Data Berhasil Disimpan \n\n";
                        system("pause");
                        menu();
                    }
                }
            }
            else{
                cout << "\n\n Data Berhasil Disimpan \n\n";
                system("pause");
                menu();
            }
        }
        else{
            cout << "\n\n Data Tidak Di temukan \n\n";
            cout << " Apakah ingin mengulang kembali ? (y/n) : "; cin >> yn;
            if(yn=='y' || yn=='Y'){
                pengembalian();	
            }
            else{
                menu();	
            }
        }
    }
}
void laporan(){ //fungsi laporan
    system("cls");
    cout << "\n\n\t\t\t laporan Perpustakaan\n";
    cout << "\t\t\t____________________\n\n";
    cout << "-----------------------------------------------------------------------------------------------------------------------\n";
    cout << " No  Kode Peminjam  Judul Buku  Nama Peminjam    Alamat        Tanggal Pinjam  Lama Peminjaman   Status   Buku Dipinjam\n";
    cout << "-----------------------------------------------------------------------------------------------------------------------\n";
    g=0;
    while(g<=d){
        for(i=0; i<=d; i++){
            if(pinjam[g].kode==buku[i].kode){
                cout << g+1 << "\t" << pinjam[g].kodepin << "\t" << buku[i].judul << "\t"
                << pinjam[g].namap << "\t" << pinjam[g].alamat << "\t\t" << pinjam[g].tglpin << "\t"
                << pinjam[g].tglbalik << "\t" << pinjam[g].status;
                if((pinjam[g].status=='y') || (pinjam[g].status=='Y')){
                    cout << " (di Pinjam) " << "\t" << pinjam[g].stock;
                }
                else{
                    cout << " (di kembalikan) " << "\t" << pinjam[g].stock;
                }
                cout << endl;
            }
        }
        g++;
    }
    system("pause");
    menu();
}
void exit(){ //fungsi exit
    system("cls");
    cout << "\n\n\n\t\t\t-- Anda Telah Logout -- \n";
    cout << "\t\t\t-- Program Aplikasi Perpustakaan Sederhana berbasis bahasa C++\n";
    system("pause");
    login();
}