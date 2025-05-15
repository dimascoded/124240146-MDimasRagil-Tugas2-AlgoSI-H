#include <iostream>
using namespace std;

struct node
{
    int no;
    string nama, keluhan;
    node *next;
    node *prev;
};
node *head, *tail, *temp, *newNode;

bool isEmpty()
{
    return head == nullptr;
}

void tambahAkhir(int no, string nama, string keluhan)
{
    newNode = new node;
    newNode->nama = nama;
    newNode->keluhan = keluhan;
    newNode->no = no;
    newNode->prev = newNode->next = nullptr;

    if (isEmpty())
    {
        head = tail = newNode;
    }
    else if (no < head->no)
    {
        // Sisip depan
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    else if (no > tail->no)
    {
        // Sisip belakang
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    else
    {
        // Sisip tengah
        temp = head;
        while (temp != nullptr && no > temp->no)
        {
            temp = temp->next;
        }
        newNode->next = temp;
        newNode->prev = temp->prev;
        temp->prev->next = newNode;
        temp->prev = newNode;
    }
    system("pause");
}

void cetakPasien()
{
    if (isEmpty())
    {
        cout << "Antrian kosong.\n";
    }
    else
    {
        cout << "Daftar pasien dalam antrian:\n";
        temp = head;
        cout << "======================================" << endl;
        while (temp != nullptr)
        {
            cout << "No Antrian  : " << temp->no << endl;
            cout << "Nama Pasien : " << temp->nama << endl;
            cout << "Keluhan     : " << temp->keluhan << endl;
            cout << "--------------------------------------" << endl;
            temp = temp->next;
        }
    }
    system("pause");
}
void cetakPasienr()
{
    if (isEmpty())
    {
        cout << "Antrian kosong.\n";
    }
    else
    {
        cout << "Daftar pasien dalam antrian:\n";
        temp = tail;
        cout << "======================================" << endl;
        while (temp != nullptr)
        {
            cout << "No Antrian  : " << temp->no << endl;
            cout << "Nama Pasien : " << temp->nama << endl;
            cout << "Keluhan     : " << temp->keluhan << endl;
            cout << "--------------------------------------" << endl;
            temp = temp->prev;
        }
    }
    system("pause");
}
void cariPasien(int no)
{
    if (isEmpty())
    {
        cout << "Antrian kosong.\n";
    }
    else
    {
        bool found = false;
        temp = head;
        while (temp != nullptr)
        {
            if (temp->no == no)
            {
                cout << "--------------------------------------" << endl;
                cout << "No Antrian  : " << temp->no << endl;
                cout << "Nama Pasien : " << temp->nama << endl;
                cout << "Keluhan     : " << temp->keluhan << endl;
                cout << "--------------------------------------" << endl;
                found = true;
                break;
            }
            temp = temp->next;
        }
        if (!found)
        {
            cout << "Pasien dengan no antrean " << no << "tidak ditemukan";
        }
    }
    system("pause");
}
void hapusPasien(int no)
{
    if (isEmpty())
    {
        cout << "Antrian kosong.\n";
    }
    else
    {
        bool found = false;
        temp = head;
        while (temp != nullptr)
        {
            if (temp->no == no)
            {
                // Kasus: node adalah HEAD
                if (temp == head)
                {
                    head = head->next;
                    if (head != nullptr)
                        head->prev = nullptr;
                    else
                        tail = nullptr; // Jika hanya 1 node
                }
                // Kasus: node adalah TAIL
                else if (temp == tail)
                {
                    tail = tail->prev;
                    if (tail != nullptr)
                        tail->next = nullptr;
                }
                // Kasus: node di tengah
                else
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                }

                delete temp;
                cout << "Data pasien dengan No. " << no << " berhasil dihapus.\n";
                system("pause");
                return;
            }
            temp = temp->next;
        }
        if (!found)
        {
            cout << "Pasien dengan no antrean " << no << "tidak ditemukan";
            system("pause");
        }
    }
}
int main()
{
    string nama, keluhan;
    int menu, no;

    do
    {
        system("cls");
        cout << "\n===== Menu ANTREAN KLINIK SEHAT SELALU =====" << endl;
        cout << "1. Tambah data pasien" << endl;
        cout << "2. Tampilkan antrean dari awal" << endl;
        cout << "3. Tampilkan antrean dari akhir" << endl;
        cout << "4. Cari data pasien" << endl;
        cout << "5. Hapus data pasien" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> menu;
        cin.ignore();

        switch (menu)
        {
        case 1:
            cout << "Masukkan No antrian     : ";
            cin >> no;
            cin.ignore();
            cout << "Masukkan nama pasien    : ";
            getline(cin, nama);
            cout << "Masukkan keluhan pasien : ";
            getline(cin, keluhan);
            tambahAkhir(no, nama, keluhan);
            cin.ignore();
            break;

        case 2:
            cetakPasien();
            break;

        case 3:
            cetakPasienr();
            break;

        case 4:
            cout << " Masukkan No antrean yang ingin dicari : ";
            cin >> no;
            cariPasien(no);
            break;
        case 5:
            cout << " Masukkan No antrean yang ingin dihapus : ";
            cin >> no;
            hapusPasien(no);
            break;
        case 6:
            break;
        default:
            cout << "Menu tidak valid, coba lagi.\n";
        }

    } while (menu != 6);
}
