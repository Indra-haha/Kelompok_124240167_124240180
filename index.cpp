#include <iostream>
#include <stdio.h>
#include <ctime>
#include <string.h>
#include <iomanip>
using namespace std;

struct Node
{
    char tanggal[40];
    char kodeProduk[15];
    char namaProduk[20];
    char kategoriProduk[20];
    int stock;
    int hargaPerStock;
    Node *next;
    Node *prev;
};
Node *createNode(char *tanggal, char *kodeProduk, char *namaProduk, char *kategoriProduk, int stock, int hargaPerStock)
{
    Node *newNode = new Node;
    strcpy(newNode->tanggal, tanggal);
    strcpy(newNode->kodeProduk, kodeProduk);
    strcpy(newNode->namaProduk, namaProduk);
    strcpy(newNode->kategoriProduk, kategoriProduk);
    newNode->stock = stock;
    newNode->hargaPerStock = hargaPerStock;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
Node *head = NULL;
Node *tail = NULL;
int emptyList()
{
    return (head == NULL);
}
void insertNodeFront(char *tanggal, char *kodeProduk, char *namaProduk, char *kategoriProduk, int stock, int hargaPerStock)
{
    Node *newNode = createNode(tanggal, kodeProduk, namaProduk, kategoriProduk, stock, hargaPerStock);
    if (emptyList())
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}
void insertNodeBack(char *tanggal, char *kodeProduk, char *namaProduk, char *kategoriProduk, int stock, int hargaPerStock)
{
    Node *newNode = createNode(tanggal, kodeProduk, namaProduk, kategoriProduk, stock, hargaPerStock);
    if (emptyList())
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->prev = tail;
        tail->prev = newNode;
        tail = newNode;
    }
}
void insertNodeMiddle(char *tanggal, char *kodeProduk, char *namaProduk, char *kategoriProduk, int stock, int hargaPerStock)
{
    Node *newNode = createNode(tanggal, kodeProduk, namaProduk, kategoriProduk, stock, hargaPerStock);
    Node *help = head;
    while (help->next != nullptr && help->next->hargaPerStock < hargaPerStock)
    {
        help = help->next;
    }
    newNode->next = help->next;
    newNode->prev = help;

    if (help->next != nullptr)
    {
        help->next->prev = newNode;
    }

    help->next = newNode;
}
void insertionSort();
void loadListFromFile();
void saveListToFile();
void resetList();
int viewStock(char methodUrut);
int updateStock();
int updateHarga();
int insertProduk();
int deleteStock();

int main()
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
            printf("Sort by Ascending [A] or Descending [B] : ");
            char methodUrut;
            cin >> methodUrut;
            viewStock(methodUrut);
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
void insertionSort()
{
    int i, j, n = 6, temp, x[6] = {7, 23, 4, 29, 11, 9};
    cout << "Data Sebelum diurutkan:\n";
    for (i = 0; i < n; i++)
    {
        cout << x[i] << " ";
    }
    Node *temp;
    Node *current = head;
    while (current != NULL)
    {
        x[i] = current->stock;
        current = current->next;
    }
    for (i = 1; i < n; i++)
    {
        temp = x[i];
        j = i - 1;
        while (j >= 0 && x[j] > temp)
        {
            x[j + 1] = x[j];
            j = j - 1;
        }
        x[j + 1] = temp;
    }
    cout << "\n\nData Setelah diurutkan:\n";
    for (i = 0; i < n; i++)
    {
        cout << x[i] << " ";
    }
    cout << "\n\n";
    system("pause");
}
int viewStock(char methodUrut)
{
    system("cls");
    if (head == nullptr)
    {
        cout << "List kosong." << endl;
        return;
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
    if (methodUrut = 'A')
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << setw(20) << setiosflags(ios::left) << current->kodeProduk << setw(3) << setiosflags(ios::left) << "|";
            cout << setw(20) << setiosflags(ios::left) << current->namaProduk << setw(3) << setiosflags(ios::left) << "|";
            cout << setw(20) << setiosflags(ios::left) << current->kategoriProduk << setw(3) << setiosflags(ios::left) << "|";
            cout << setw(7) << setiosflags(ios::left) << current->stock << setw(3) << setiosflags(ios::left) << "|";
            cout << setw(15) << setiosflags(ios::left) << current->hargaPerStock << setw(3) << setiosflags(ios::left) << "|";
            cout << setw(40) << setiosflags(ios::left) << current->tanggal << endl;
            current = current->next;
        }
    }
    else if (methodUrut = 'B')
    {
        Node *current = tail;
        while (current != nullptr)
        {
            cout << setw(20) << setiosflags(ios::left) << current->kodeProduk << setw(3) << setiosflags(ios::left) << "|";
            cout << setw(20) << setiosflags(ios::left) << current->namaProduk << setw(3) << setiosflags(ios::left) << "|";
            cout << setw(20) << setiosflags(ios::left) << current->kategoriProduk << setw(3) << setiosflags(ios::left) << "|";
            cout << setw(7) << setiosflags(ios::left) << current->stock << setw(3) << setiosflags(ios::left) << "|";
            cout << setw(15) << setiosflags(ios::left) << current->hargaPerStock << setw(3) << setiosflags(ios::left) << "|";
            cout << setw(40) << setiosflags(ios::left) << current->tanggal << endl;
            current = current->prev;
        }
    }
    else
    {
        cout << "Invalid methodUrut" << endl;
    }
    return 0;
}
void loadListFromFile()
{
    FILE *file = fopen("dataProduk.dat", "rb");
    if (!file)
    {
        cout << "File dataProduk.dat tidak ditemukan. Membuat file baru..." << endl;
        return;
    }

    Node temp;
    while (fread(&temp, sizeof(Node), 1, file))
    {
        insertNodeBack(temp.tanggal, temp.kodeProduk, temp.namaProduk, temp.kategoriProduk, temp.stock, temp.hargaPerStock);
    }
    fclose(file);
}
void saveListToFile()
{
    FILE *file = fopen("dataProduk.dat", "wb");
    if (!file)
    {
        cout << "Gagal membuka file untuk menyimpan data." << endl;
        return;
    }

    Node *current = head;
    while (current != NULL)
    {
        fwrite(current, sizeof(Node), 1, file);
        current = current->next;
    }
    fclose(file);
}
void resetList()
{
    Node *help = head;
    Node *temp;

    // Hapus semua node
    while (help != nullptr)
    {
        temp = help;
        help = help->next;
        free(temp); // Hapus node
    }

    // Reset pointer first dan last
    head = nullptr;
    tail = nullptr;

    cout << "Linked list telah direset." << endl;
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
    Node *current = head;
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
    N *current = head;
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
    Node *newNode = new Node;
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
    Node *current = head;
    printf("Masukkan data produk.\n");
    printf("Kode Produk : ");
    cin >> cari;
    while (current != NULL)
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

    fwrite(&current, sizeof(Node), 1, file);
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
    data *current = head;
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
            fwrite(&current, sizeof(Node), 1, tempFile);
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
