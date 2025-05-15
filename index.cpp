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
    data *next;
    data *prev;
    
};


data *head = NULL;
data *tail = NULL;

int viewStock();
int updateStock();
int updateHarga();
int insertProduk();
int deleteStock();
int menuStockKeeper();

int main()
{
    menuStockKeeper();
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
    cout << "                                                                             DAFTAR PRODUK TERKINI                                                                              " << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(20) << setiosflags(ios::left) << "Kode Produk" << setw(3) << setiosflags(ios::left) << "|";
    cout << setw(20) << setiosflags(ios::left) << "Nama Produk" << setw(3) << setiosflags(ios::left) << "|";
    cout << setw(20) << setiosflags(ios::left) << "Kategori Produk" << setw(3) << setiosflags(ios::left) << "|";
    cout << setw(7) << setiosflags(ios::left) << "Stock" << setw(3) << setiosflags(ios::left) << "|";
    cout << setw(15) << setiosflags(ios::left) << "Harga/Stock" << setw(3) << setiosflags(ios::left) << "|";
    cout << setw(10) << setiosflags(ios::left) << "Input" << setw(3) << setiosflags(ios::left) << "|";
    cout << setw(10) << setiosflags(ios::left) << "Output" << setw(3) << setiosflags(ios::left) << "|";
    cout << setw(40) << setiosflags(ios::left) << "Tanggal" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    
    data* current = head;
    while (current != NULL)
    {
        cout << setw(20) << setiosflags(ios::left) << current->kodeProduk << setw(3) << setiosflags(ios::left) << "|";
        cout << setw(20) << setiosflags(ios::left) << current->namaProduk << setw(3) << setiosflags(ios::left) << "|";
        cout << setw(20) << setiosflags(ios::left) << current->kategoriProduk << setw(3) << setiosflags(ios::left) << "|";
        cout << setw(7) << setiosflags(ios::left) << current->stock << setw(3) << setiosflags(ios::left) << "|";
        cout << setw(15) << setiosflags(ios::left) << current->hargaPerStock << setw(3) << setiosflags(ios::left) << "|";
        cout << setw(40) << setiosflags(ios::left) << current->tanggal << endl;
        current = current->next;
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
    char kodeProduk[15];
    cout << "Update Stock Barang" << endl;
    cout << "Masukkan kode produk : ";
    cin >> kodeProduk;
    data* current = head;
    while (current != NULL)
    {
        if (strcmp(current->kodeProduk, kodeProduk) == 1)
        {
            int tambahStock;
            cout << "Kode Produk : " << current->kodeProduk << endl;
            cout << "Nama Produk : " << current->namaProduk << endl;
            cout << "Kategori Produk : " << current->kategoriProduk << endl;
            cout << "Stock : " << current->stock << endl;
            cout << "Masukkan jumlah stock : ";
            cin >> tambahStock;
            current->stock += tambahStock;
            time_t timestamp;
            time(&timestamp);
            strcpy(current->tanggal, ctime(&timestamp));
            fseek(file, -sizeof(data), SEEK_CUR);
            fwrite(current, sizeof(data), 1, file);
            cout << endl;
            cout << "Produk berhasil diupdate." << endl;
            cout << "Stock barang sebelum diupdate : " << current->stock << endl;
            fclose(file);
            return 0;
        }
        else
        {
            cout << "Produk tidak ditemukan." << endl;
            fclose(file);
            return 1;
        }
        current = current->next;
    }
    return 0;
}
int updateHarga()
{
    system("cls");
    data* current = head;
    FILE *file = fopen("dataProduk.dat", "r+b");
    if (file == NULL)
    {
        printf("File dataProduk.dat tidak ditemukan.\n");
        return 1;
    }

    char kodeProduk[15];
    cout << "Update Harga Barang" << endl;
    cout << "Masukkan kode produk : ";
    cin >> kodeProduk;
    while (current != NULL) 
    {
        if (strcmp(current->kodeProduk, kodeProduk) == 1)
        {
            int hargaPerStock;
            cout << "Kode Produk : " << current->kodeProduk << endl;
            cout << "Nama Produk : " << current->namaProduk << endl;
            cout << "Kategori Produk : " << current->kategoriProduk << endl;
            cout << "Harga/Stock : " << current->hargaPerStock << endl;
            cout << "Masukkan harga baru : ";
            cin >> hargaPerStock;
            current->hargaPerStock = hargaPerStock;
            time_t timestamp;
            time(&timestamp);
            strcpy(current->tanggal, ctime(&timestamp));
            fseek(file, -sizeof(data), SEEK_CUR);
            fwrite(current, sizeof(data), 1, file);
            cout << endl;
            cout << "Produk berhasil diupdate." << endl;
            cout << "Harga barang sebelum diupdate : " << current->hargaPerStock << endl;
            fclose(file);
            return 0;
        }
        else
        {
            cout << "Produk tidak ditemukan." << endl;
            fclose(file);
            return 1;
        }
        current = current->next;
    }
    {
        if (strcmp(current->kodeProduk, kodeProduk) == 1)
        {
            int hargaBaru;
            cout << "Kode Produk : " << current->kodeProduk << endl;
            cout << "Nama Produk : " << current->namaProduk << endl;
            cout << "Kategori Produk : " << current->kategoriProduk << endl;
            cout << "Harga/Stock : " << current->hargaPerStock << endl;
            cout << "Masukkan harga baru : ";
            cin >> hargaBaru;
            current->hargaPerStock = hargaBaru;
            time_t timestamp;
            time(&timestamp);
            strcpy(current->tanggal, ctime(&timestamp));
            fseek(file, -sizeof(data), SEEK_CUR);
            fwrite(&current, sizeof(data), 1, file);
            cout << endl;
            cout << "Produk berhasil diupdate." << endl;
            cout << "Harga barang sebelum diupdate : " << current->hargaPerStock << endl;
            fclose(file);
            return 0;
        }
        else
        {
            cout << "Produk tidak ditemukan." << endl;
            fclose(file);
            return 1;
        }
        current = current->next;
    }
    return 0;
}
int insertProduk()
{
    system("cls");
    char cari[15];
    data* newNode = new data;
    FILE *file = fopen("dataProduk.dat", "ab");
    FILE *file2 = fopen("dataProduk.dat", "rb");
    if (file == NULL)
    {
        printf("File dataProduk.dat tidak ditemukan.\n");
        return 1;
    }
    if (file2 == NULL)
    {
        printf("File dataProduk.dat tidak ditemukan.\n");
        fclose(file);
        return 1;
    }
    data* current = head;
    printf("Masukkan data produk.\n");
    printf("Kode Produk : ");
    cin >> cari;
    while(current != NULL)
    {
        if (strcmp(current->kodeProduk, cari) == 0)
        {
            cout << "Kode Produk sudah ada." << endl;
            cout << "Silahkan masukkan kode produk yang lain." << endl;
            fclose(file2);
            fclose(file);

            return 1;
        }
        current = current->next;
    }
    printf("Nama Produk : ");
    cin.ignore();
    cin.getline(current->namaProduk, sizeof(current));
    printf("Kategori Produk : ");
    cin.ignore();
    scanf("%s", current->kategoriProduk);
    printf("Stock : ");
    scanf("%d", &current->stock);
    printf("Harga/Stock : ");
    scanf("%d", &current->hargaPerStock);
    time_t timestamp;
    time(&timestamp);
    strcpy(current->tanggal, ctime(&timestamp));
    
    fwrite(&current, sizeof(data), 1, file);
    fclose(file);
    return 0;
}
int deleteStock()
{
    system("cls");
    FILE *file = fopen("dataProduk.dat", "r+b");
    FILE *tempFile = fopen("temp.dat", "wb");
    if (!file)
    {
        cout << "Produk tidak ditemukan" << endl;
        return 1;
    }
data* current = head;
    char kodeProduk[15];
    bool found = false;

    cout << "Masukkan kode produk :";
    cin >> kodeProduk;

    while (current != NULL)
    {
        if (strcmp(current->kodeProduk, kodeProduk) == 0)
        {
            found = true;
            cout << "Produk berhasil dihapus!" << endl;
            
        }
        else
        {
            fwrite(&current, sizeof(data), 1, tempFile);
        }
        current = current->next;
    }

    fclose(file);
    fclose(tempFile);

    if (found)
    {
        remove("dataProduk.dat");
        rename("temp.dat", "dataProduk.dat");
    }
    else
    {
        remove("temp.dat");
        cout << "Produk tidak ditemukan." << endl;
    }
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
            printf("Terima kasih telah menggunakan program ini.\n");
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

