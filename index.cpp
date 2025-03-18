#include <iostream>
#include <stdio.h>
#include <ctime>
using namespace std;
struct data
{
    string tanggal;
    string kodeProduk;
    string namaProduk;
    string kategoriProduk;
    int stock;
    int hargaPerStock;
    bool input;
    bool output;
};
data produk;
int viewTransaksi();
int transaksi();
int viewStock();
int updateStock();
int updateHarga();
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
    cout << "belum ada";
    return 0;
}
int updateStock()
{
    system("cls");
    cout << "belum ada";

    return 0;
}
int updateHarga()
{
    system("cls");
    cout << "belum ada";
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
            break;
        case '2':
            viewTransaksi();
            break;
        case '3':
            menuAdmin('y');
            break;
        default:
            cout << "Pilihan tidak ada.";
            cout << endl;
            cout << "Kembali ke MENU [y/n] : ";
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
        cout << "-----------------------MENU ADMIN--------------------" << endl;
        cout << "1. Update Stock" << endl;
        cout << "2. Update Harga" << endl;
        cout << "3. Delete Produk" << endl;
        cout << "4. Lihat Stock Terkini" << endl;
        cout << "5. Exit" << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "Pilih : ";
        cin >> pilih;
        switch (pilih)
        {
        case '1':
            updateStock();
            break;
        case '2':
            updateHarga();
            break;
        case '3':
            deleteStock();
            break;
        case '4':
            viewStock();
            break;
        case '5':
            menuAdmin('y');
            break;
        default:
            cout << "Pilihan tidak ada.";
            cout << endl;
            cout << "Kembali ke MENU AWAL [y/n] : ";
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
