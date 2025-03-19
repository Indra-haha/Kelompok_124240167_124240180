#include <iostream>
#include <stdio.h>
#include <ctime>
#include <string.h>
#include <iomanip>
using namespace std;
struct data
{
    char tanggal[40];
    char kodeProduk[15];
    char namaProduk[20];
    char kategoriProduk[20];
    int stock;
    int hargaPerStock;
    char input[10];
    char output[10];
};
data produk;
int viewTransaksi();
int transaksi();
int viewStock();
int updateStock();
int updateHarga();
int insertProduk();
int deleteStock();
int stockTracking();
int menuKasir();
int menuStockKeeper();
int menuAdmin(char back);

int main()
{
    menuAdmin('n');
    return 0;
}
int viewTransaksi()
{
    system("cls");
    cout << "belum";
    return 0;
}
int transaksi()
{
    system("cls");
    cout << "belum";
    return 0;
}
int viewStock()
{
    system("cls");
    FILE *file = fopen("dataProduk.dat", "rb");
    if (file == NULL)
    {
        printf("File dataProduk.dat tidak ditemukan.\n");
        return 1;
    }
    data produk;
    cout << "                                                                             DAFTAR PRODUK TERKINI                                                                              " << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl; 
    cout << setw(20) << setiosflags(ios::left) << "Kode Produk" << setw(3) << setiosflags(ios::left) << "|";
    cout << setw(30) << setiosflags(ios::left) << "Nama Produk" << setw(3) << setiosflags(ios::left) << "|";
    cout << setw(30) << setiosflags(ios::left) << "Kategori Produk" << setw(3) << setiosflags(ios::left) << "|";
    cout << setw(7) << setiosflags(ios::left) << "Stock" << setw(3) << setiosflags(ios::left) << "|";
    cout << setw(15) << setiosflags(ios::left) << "Harga/Stock" << setw(3) << setiosflags(ios::left) << "|";
    cout << setw(10) << setiosflags(ios::left) << "Input" << setw(3) << setiosflags(ios::left) << "|";
    cout << setw(10) << setiosflags(ios::left) << "Output" << setw(3) << setiosflags(ios::left) << "|";
    cout << setw(40) << setiosflags(ios::left) << "Tanggal" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl; 
    while (fread(&produk, sizeof(data), 1, file) == 1)
    {
        cout << setw(20) << setiosflags(ios::left) << produk.kodeProduk << setw(3) << setiosflags(ios::left) << "|";
        cout << setw(30) << setiosflags(ios::left) << produk.namaProduk << setw(3) << setiosflags(ios::left) << "|";
        cout << setw(30) << setiosflags(ios::left) << produk.kategoriProduk << setw(3) << setiosflags(ios::left) << "|";
        cout << setw(7) << setiosflags(ios::left) << produk.stock << setw(3) << setiosflags(ios::left) << "|";
        cout << setw(15) << setiosflags(ios::left) << produk.hargaPerStock << setw(3) << setiosflags(ios::left) << "|";
        cout << setw(10) << setiosflags(ios::left) << produk.input << setw(3) << setiosflags(ios::left) << "|";
        cout << setw(10) << setiosflags(ios::left) << produk.output << setw(3) << setiosflags(ios::left) << "|";
        cout << setw(40) << setiosflags(ios::left) << produk.tanggal << endl;
    }
    fclose(file);
    return 0;
}
int updateStock()
{
    system("cls");
    FILE *file = fopen("dataProduk.dat", "r+b");
    if (file == NULL)
    {
        printf("File dataProduk.dat tidak ditemukan.\n");
        return 1;
    }
    data produk;
    char kodeProduk[15];
    cout << "Update Stock Barang" << endl;
    cout << "Masukkan kode produk : ";
    cin >> kodeProduk;
    while (fread(&produk, sizeof(data), 1, file) == 1)
    {
        if (strcmp(produk.kodeProduk, kodeProduk) == 0)
        {
            int tambahStock;
            cout << "Kode Produk : " << kodeProduk << endl;
            cout << "Nama Produk : " << produk.namaProduk << endl;
            cout << "Kategori Produk : " << produk.kategoriProduk << endl;
            cout << "Stock : " << produk.stock << endl;
            cout << "Masukkan jumlah stock : ";
            cin >> tambahStock;
            produk.stock += tambahStock;
            time_t timestamp;
            time(&timestamp);
            strcpy(produk.tanggal, ctime(&timestamp));
            fseek(file, -sizeof(data), SEEK_CUR);
            fwrite(&produk, sizeof(data), 1, file);
            cout << endl ;
            cout << "Produk berhasil diupdate." << endl;
            cout << "Stock barang sebelum diupdate : " << produk.stock << endl;
            fclose(file);
            return 0;
        }
        else
        {
            cout << "Produk tidak ditemukan." << endl;
            fclose(file);
            return 1;
        }
    }
    return 0;
}
int updateHarga()
{
    system("cls");
    FILE *file = fopen("dataProduk.dat", "r+b");
    if (file == NULL)
    {
        printf("File dataProduk.dat tidak ditemukan.\n");
        return 1;
    }
    data produk;
    char kodeProduk[15];
    cout << "Update Harga Barang" << endl;
    cout << "Masukkan kode produk : ";
    cin >> kodeProduk;
    while (fread(&produk, sizeof(data), 1, file) == 1)
    {
        if (strcmp(produk.kodeProduk, kodeProduk) == 0)
        {
            int hargaBaru;
            cout << "Kode Produk : " << kodeProduk << endl;
            cout << "Nama Produk : " << produk.namaProduk << endl;
            cout << "Kategori Produk : " << produk.kategoriProduk << endl;
            cout << "Harga/Stock : " << produk.hargaPerStock << endl;
            cout << "Masukkan harga baru : ";
            cin >> hargaBaru;
            produk.hargaPerStock = hargaBaru;
            time_t timestamp;
            time(&timestamp);
            strcpy(produk.tanggal, ctime(&timestamp));
            fseek(file, -sizeof(data), SEEK_CUR);
            fwrite(&produk, sizeof(data), 1, file);
            cout << endl ;
            cout << "Produk berhasil diupdate." << endl;
            cout << "Harga barang sebelum diupdate : " << produk.hargaPerStock << endl;
            fclose(file);
            return 0;
        }
        else
        {
            cout << "Produk tidak ditemukan." << endl;
            fclose(file);
            return 1;
        }
    }
    return 0;
}
int insertProduk()
{
    system("cls");
    FILE *file = fopen("dataProduk.dat", "ab");
    if (file == NULL)
    {
        printf("File dataProduk.dat tidak dapat dibuat.\n");
        return 1;
    }
    data produk;
    printf("File dataProduk.dat berhasil dibuat.\n");
    printf("Masukkan data produk.\n");
    printf("Kode Produk : ");
    cin >> produk.kodeProduk;
    printf("Nama Produk : ");
    cin.ignore();
    cin.getline(produk.namaProduk, sizeof(produk.namaProduk));
    printf("Kategori Produk : ");
    scanf("%s", produk.kategoriProduk);
    printf("Stock : ");
    scanf("%d", &produk.stock);
    printf("Harga/Stock : ");
    scanf("%d", &produk.hargaPerStock);
    strcpy(produk.input, "ya");
    strcpy(produk.output, "tidak");
    time_t timestamp;
    time(&timestamp);
    strcpy(produk.tanggal, ctime(&timestamp));
    fwrite(&produk, sizeof(data), 1, file);
    fclose(file);
    return 0;
}
int deleteStock()
{
    system("cls");
    cout << "belum ada";
    return 0;
}
int stockTracking()
{
    system("cls");
    cout << "belum ada";
    return 0;
}
int menuKasir()
{
    char pilih, kembali;
    do
    {
        system("cls");
        kembali = 'n';
        cout << "-----------------------MENU KASIR--------------------" << endl;
        cout << "1. Transaksi" << endl;
        cout << "2. Lihat Transaksi" << endl;
        cout << "3. Exit" << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "Pilih : ";
        cin >> pilih;
        switch (pilih)
        {
        case '1':
            transaksi();
            printf("\n");
            printf("Kembali ke MENU [y/n] : ");
            cin >> kembali;
            break;
        case '2':
            viewTransaksi();
            printf("\n");
            printf("Kembali ke MENU [y/n] : ");
            cin >> kembali;
            break;
        case '3':
            menuAdmin('y');
            break;
        default:
            printf("Pilihan tidak ada.");
            printf("\n");
            printf("Kembali ke MENU [y/n] : ");
            cin >> kembali;
            break;
        }
    } while (kembali == 'y');
    return 0;
}
int menuStockKeeper()
{
    char pilih, kembali;
    do
    {
        system("cls");
        kembali = 'n';
        printf("-----------------------MENU ADMIN--------------------\n");
        printf("1. Update Stock\n");
        printf("2. Update Harga\n");
        printf("3. Insert Produk\n");
        printf("4. Delete Produk\n");
        printf("5. Lihat Stock Terkini\n");
        printf("6. Exit\n");
        printf("-----------------------------------------------------\n");
        cout << "Pilih : ";
        cin >> pilih;
        switch (pilih)
        {
        case '1':
            updateStock();
            printf("\n");
            printf("Kembali ke MENU [y/n] : ");
            cin >> kembali;
            break;
        case '2':
            updateHarga();
            printf("\n");
            printf("Kembali ke MENU [y/n] : ");
            cin >> kembali;
            break;
        case '3':
            insertProduk();
            printf("\n");
            printf("Kembali ke MENU [y/n] : ");
            cin >> kembali;
            break;
        case '4':
            deleteStock();
            printf("\n");
            printf("Kembali ke MENU [y/n] : ");
            cin >> kembali;
            break;
        case '5':
            viewStock();
            printf("\n");
            printf("Kembali ke MENU [y/n] : ");
            cin >> kembali;
            break;
        case '6':
            menuAdmin('y');
            break;
        default:
            printf("Pilihan tidak ada.");
            printf("\n");
            printf("Kembali ke MENU [y/n] : ");
            cin >> kembali;
            break;
        }
    } while (kembali == 'y');
    return 0;
}
int menuAdmin(char back)
{
    char pilih, kembali;
    do
    {
        system("cls");
        kembali = 'n';
        back = 'n';
        cout << "--------------------MANAJEMEN STOCK------------------" << endl;
        cout << "1. Manajemen Barang" << endl;
        cout << "2. Manajemen Kasir" << endl;
        cout << "3. Stock Tracking" << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "Pilih : ";
        cin >> pilih;
        switch (pilih)
        {
        case '1':
            menuStockKeeper();
            break;
        case '2':
            menuKasir();
            break;
        case '3':
            stockTracking();
            break;
        default:
            cout << "Pilihan tidak ada.";
            cout << endl;
            cout << "Kembali ke MENU [y/n] : ";
            cin >> kembali;
            break;
        }
    } while (kembali == 'y' || back == 'y');
    return 0;
}
