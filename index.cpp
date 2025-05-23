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
        tail->next = newNode;
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
void insertionSort(char pilihan);
void loadListFromFile(Node **head, Node **tail);
void saveListToFile(Node *head);
void resetList();
int viewStock(char methodUrut);
int updateStock();
int updateHarga();
int insertProduk();
int deleteStock();

int main()
{
    loadListFromFile(&head, &tail);
    char pilih, kembali;
    if (head == NULL)
    {
        system("cls");
        printf("Upss... List Kamu Kosong\n");
        printf("Isi Dulu List Kamu\n");
        system("pause");
        insertProduk();
        printf("\n");
        printf("Berhasil!!!");
    }
    else
    {
        cout << "Yeah....List Kamu Terisi" << endl;
    }
    do
    {
        system("cls");
        kembali = 'n';
        printf("-------------------MANAJEMEN STOCK--------------------\n");
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
            printf("Lihat Stock Terkini\n");
            printf("1. Urutkan berdasarkan harga\n");
            printf("2. Urutkan berdasarkan stock\n");
            printf("Pilih : ");
            char pilihanUrut;
            cin >> pilihanUrut;
            insertionSort(pilihanUrut);
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
void insertionSort(char pilihan)
{
    if (head == nullptr || head->next == nullptr)
        return;

    Node *current = head->next;
    if (pilihan == '1')
    {
        while (current != nullptr)
        {
            Node *temp = current;
            Node *prev = current->prev;

            while (prev != nullptr && temp->hargaPerStock < prev->hargaPerStock)
            {
                prev = prev->prev;
            }

            if (prev != current->prev)
            {
                temp->prev->next = temp->next;
                if (temp->next != nullptr)
                {
                    temp->next->prev = temp->prev;
                }

                if (prev == nullptr)
                {
                    temp->next = head;
                    head->prev = temp;
                    head = temp;
                    temp->prev = nullptr;
                }
                else
                {
                    temp->next = prev->next;
                    if (prev->next != nullptr)
                    {
                        prev->next->prev = temp;
                        prev->next = temp;
                        temp->prev = prev;
                    }
                }
            }

            // Move to the next node to sort
            current = current->next;
            if (temp->next == nullptr)
            {
                tail = temp;
            }
            else
            {
                tail = temp->next;
            }
        }
    }
    else if (pilihan == '2')
    {
        while (current != nullptr)
        {
            Node *temp = current;
            Node *prev = current->prev;

            while (prev != nullptr && temp->stock < prev->stock)
            {
                prev = prev->prev;
            }

            if (prev != current->prev)
            {
                temp->prev->next = temp->next;
                if (temp->next != nullptr)
                {
                    temp->next->prev = temp->prev;
                }

                if (prev == nullptr)
                {
                    temp->next = head;
                    head->prev = temp;
                    head = temp;
                    temp->prev = nullptr;
                }
                else
                {
                    temp->next = prev->next;
                    if (prev->next != nullptr)
                    {
                        prev->next->prev = temp;
                        prev->next = temp;
                        temp->prev = prev;
                    }
                }
            }

            // Move to the next node to sort
            current = current->next;
            if (temp->next == nullptr)
            {
                tail = temp;
            }
            else
            {
                tail = temp->next;
            }
        }
    }
}
int viewStock(char methodUrut)
{
    system("cls");
    if (head == nullptr)
    {
        cout << "List kosong." << endl;
        return 0;
    }
    cout << "                                                         DAFTAR PRODUK TERKINI                                                               " << endl;
    cout << "---------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(20) << setiosflags(ios::left) << "Kode Produk" << setw(3) << setiosflags(ios::left) << "|";
    cout << setw(20) << setiosflags(ios::left) << "Nama Produk" << setw(3) << setiosflags(ios::left) << "|";
    cout << setw(20) << setiosflags(ios::left) << "Kategori Produk" << setw(3) << setiosflags(ios::left) << "|";
    cout << setw(7) << setiosflags(ios::left) << "Stock" << setw(3) << setiosflags(ios::left) << "|";
    cout << setw(15) << setiosflags(ios::left) << "Harga/Stock" << setw(3) << setiosflags(ios::left) << "|";
    cout << setw(40) << setiosflags(ios::left) << "Tanggal" << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    if (methodUrut == 'A')
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
    else if (methodUrut == 'B')
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

void loadListFromFile(Node **head, Node **tail)
{
    FILE *file = fopen("dataProduk.dat", "rb");
    if (!file)
    {
        cout << "File dataProduk.dat tidak ditemukan! Buat file baru!" << endl;
        return;
    }

    Node temp;
    while (fread(&temp, sizeof(Node), 1, file))
    {
        Node *newNode = new Node;
        *newNode = temp;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        if (*head == nullptr)
        {
            *head = newNode;
            *tail = newNode;
        }
        else
        {
            newNode->prev = *tail;
            (*tail)->next = newNode;
            *tail = newNode;
        }
    }
    fclose(file);
}
void saveListToFile(Node *head)
{
    FILE *file = fopen("dataProduk.dat", "wb");
    if (!file)
    {
        cout << "Gagal membuka file untuk menyimpan data!" << endl;
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

    cout << "Linked list telah direset!" << endl;
}

void tampilkanKodeProduk() {
    cout << "\nDaftar Produk yang Tersedia:\n";
    cout << "-------------------------------------------\n";
    cout << left << setw(15) << "Kode Produk" << setw(20) << "Nama Produk" << endl;
    cout << "-------------------------------------------\n";

    Node* current = head;
    while (current != nullptr) {
        cout << left << setw(15) << current->kodeProduk
             << setw(20) << current->namaProduk << endl;
        current = current->next;
    }
    cout << "-------------------------------------------\n";
}

int updateStock()
{
    system("cls");
    FILE *file = fopen("dataProduk.dat", "r+b");
    if (file == NULL)
    {
        printf("File dataProduk.dat tidak ditemukan!\n");
        return 1;
    }

    tampilkanKodeProduk();

    char kodeProduk[15];
    cout << "Update Stock Barang" << endl;
    cout << "Masukkan kode produk : ";
    cin >> kodeProduk;

    Node *current = head;
    while (current != NULL)
    {
        if (strcmp(current->kodeProduk, kodeProduk) == 0)
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
            fseek(file, -sizeof(Node), SEEK_CUR);
            fwrite(current, sizeof(Node), 1, file);
            cout << endl;
            cout << "Produk berhasil diupdate." << endl;
            cout << "Stock barang sebelum diupdate : " << current->stock << endl;
            fclose(file);
            return 0;
        }
        current = current->next;
    }
    // Jika tidak ditemukan
    cout << "Produk tidak ditemukan!" << endl;
    fclose(file);
    return 1;
}
int updateHarga()
{
    system("cls");
    Node *current = head;
    FILE *file = fopen("dataProduk.dat", "r+b");
    if (file == NULL)
    {
        printf("File dataProduk.dat tidak ditemukan!\n");
        return 1;
    }
    tampilkanKodeProduk();
    char kodeProduk[15];
    cout << "Update Harga Barang" << endl;
    cout << "Masukkan kode produk : ";
    cin >> kodeProduk;

    while (current != NULL)
    {
        if (strcmp(current->kodeProduk, kodeProduk) == 0)
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
            fseek(file, -sizeof(Node), SEEK_CUR);
            fwrite(current, sizeof(Node), 1, file);
            cout << endl;
            cout << "Produk berhasil diupdate" << endl;
            cout << "Harga barang setelah diupdate : " << current->hargaPerStock << endl;
            fclose(file);
            return 0;
        }
        current = current->next;
    }
    // Jika tidak ditemukan
    cout << "Produk tidak ditemukan!" << endl;
    fclose(file);
    return 1;
}
int insertProduk()
{
    system("cls");
    char cari[15];
    Node *newNode = new Node;
    FILE *file = fopen("dataProduk.dat", "ab");
    if (file == NULL)
    {
        printf("File dataProduk.dat tidak ditemukan\n");
        return 1;
    }
    Node *current = head;
    printf("Masukkan data produk\n");
    printf("Kode Produk : ");
    cin >> cari;
    while (current != NULL)
    {
        if (strcmp(current->kodeProduk, cari) == 0)
        {
            cout << "Kode Produk sudah ada" << endl;
            cout << "Masukkan kode produk yang lain!" << endl;
            cout << "Kode Produk     : " << current->kodeProduk << endl;
            cout << "Nama Produk     : " << current->namaProduk << endl;
            cout << "Kategori Produk : " << current->kategoriProduk << endl;
            cout << "Harga/stock     : " << current->hargaPerStock << endl;
            cout << "Stock           : " << current->stock << endl;
            cout << "Diperbarui      : " << current->tanggal << endl;
            fclose(file);
            return 1;
        }
        current = current->next;
    }
    strcpy(newNode->kodeProduk, cari);
    printf("Nama Produk : ");
    cin.ignore();
    cin.getline(newNode->namaProduk, sizeof(newNode->namaProduk));
    printf("Kategori Produk : ");
    cin.getline(newNode->kategoriProduk, sizeof(newNode->kategoriProduk));
    printf("Stock : ");
    cin >> newNode->stock;
    printf("Harga/Stock : ");
    cin >> newNode->hargaPerStock;
    time_t timestamp;
    time(&timestamp);
    strcpy(newNode->tanggal, ctime(&timestamp));

    fwrite(newNode, sizeof(Node), 1, file);
    fclose(file);
    insertNodeBack(newNode->tanggal, newNode->kodeProduk, newNode->namaProduk, newNode->kategoriProduk, newNode->stock, newNode->hargaPerStock);
    return 0;
}
int deleteStock()
{
    system("cls");
    FILE *file = fopen("dataProduk.dat", "rb");
    FILE *tempFile = fopen("temp.dat", "wb");
    if (!file)
    {
        cout << "Produk tidak ditemukan!" << endl;
        return 1;
    }
    tampilkanKodeProduk();

    Node *current = head;
    char kodeProduk[15];
    bool found = false;

    cout << "Masukkan kode produk :";
    cin >> kodeProduk;

    // Hapus dari linked list
    Node *prev = nullptr;
    current = head;
    while (current != nullptr)
    {
        if (strcmp(current->kodeProduk, kodeProduk) == 0)
        {
            found = true;
            if (current == head)
                head = current->next;
            if (current == tail)
                tail = current->prev;
            if (current->prev)
                current->prev->next = current->next;
            if (current->next)
                current->next->prev = current->prev;
            Node *toDelete = current;
            current = current->next;
            delete toDelete;
            cout << "Produk berhasil dihapus!" << endl;
        }
        else
        {
            fwrite(current, sizeof(Node), 1, tempFile);
            current = current->next;
        }
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
        cout << "Produk tidak ditemukan!" << endl;
    }
    return 0;
}
