#include <iostream>
#include <stdio.h>
#include <ctime>
using namespace std;

struct data
{
    string tanggal;
    string namaProduk;
    string kategoriProduk;
    int stock;
    int hargaPerStock;
    bool input;
    bool output;
};
data produk;
char kembaliMenu;

int lihatStock()
{
    cout << "belum ada";
    return 0;
}

int updateStock()
{
    string namaProdukCari;
    char pilihUpdate;
    time_t timestamp;
    time(&timestamp);
    cout << ctime(&timestamp);
    cout << "----------------------UPDATE Barang------------------" << endl;
    cout << "1. Update Stock" << endl;
    cout << "2. Update Harga" << endl;
    cout << "3. Delete Produk" << endl;
    cout << "4. Exit" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "Pilih : ";
    cin >> pilihUpdate;
    cout << "Masukkan nama produk : ";
    cin >> namaProdukCari;

    return 0;
}
int MS(int pilihan)
{
    switch (pilihan)
    {
    case 1:
        updateStock();
        break;
    case 2:
        lihatStock();
        break;
    default:
        break;
    }
    cout << "Pilihan tidak tersedia" << endl;
    cout << "Kembali ke menu [y/n] : " << endl;
    cin >> kembaliMenu;
    return 0;
}

int stockTracking()
{
    cout << "belum ada";
    return 0;
}

int menuKasir()
{
    int pilih;
    cout << "-----------------------MENU KASIR--------------------" << endl;
    cout << "1. Transaksi" << endl;
    cout << "2. Lihat Transaksi" << endl;
    cout << "3. Exit" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "Pilih : ";
    cin >> pilih;
    return 0;
}

int menuStockKeeper()
{
    int pilih;
    cout << "-----------------------MENU ADMIN--------------------" << endl;
    cout << "1. Update Barang" << endl;
    cout << "2. Lihat Stock Terkini" << endl;
    cout << "3. Exit" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "Pilih : ";
    cin >> pilih;
    return 0;
}

int menuAdmin()
{
    char pilih, kembali;
    do
    {
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
            break;
        }
        cout << endl;
        cout << "Kembali ke MENU [y/n] : ";
        cin >> kembali;
    } while (kembali == 'y' || 'Y');
    return 0;
}

int main()
{
    menuAdmin();
    return 0;
}