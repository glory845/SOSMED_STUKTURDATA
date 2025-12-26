#include "sosmed.h"

int main() {
    ListGroup LG; 
    ListNetizen LN;
    ListRelasi LR;

    createListGroup(LG);
    createListNetizen(LN);
    createListRelasi(LR);

    int pilihan;
    do {
        cout << "\n===== MENU SOSIAL MEDIA =====" << endl;
        cout << "1. Tambah Group" << endl;
        cout << "2. Tambah Netizen" << endl;
        cout << "3. Tambah Relasi (Group - Netizen)" << endl;
        cout << "4. Tampilkan Semua Group" << endl;
        cout << "5. Tampilkan Semua Netizen" << endl;
        cout << "6. Cari Group berdasarkan ID" << endl;
        cout << "7. Cari Netizen berdasarkan ID" << endl;
        cout << "8. Tampilkan Semua Group & Member" << endl;
        cout << "9. Tampilkan Group dari Netizen tertentu" << endl;
        cout << "10. Tampilkan Netizen di Group tertentu" << endl;
        cout << "11. Hapus Group" << endl;
        cout << "12. Hapus Netizen" << endl;
        cout << "13. Hitung Member pada Group" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {

        case 1: {
            int id;
            string nama;
            cout << "ID Group: ";
            cin >> id;

            // CEK APAKAH ID SUDAH ADA
            if (findGroup(LG, id) != NULL) {
                cout << "Gagal! ID Group sudah ada.\n";
            } else {
                cout << "Nama Group: ";
                cin.ignore();
                getline(cin, nama);
                insertFirstGroup(LG, id, nama);
                cout << "Group berhasil ditambahkan.\n";
            }
            break;
        }


        case 2: {
            int id;
            string nama;
            cout << "ID Netizen: ";
            cin >> id;

            // CEK APAKAH ID SUDAH ADA
            if (findNetizen(LN, id) != NULL) {
                cout << "Gagal! ID Netizen sudah ada.\n";
            } else {
                cout << "Nama: ";
                cin.ignore();
                getline(cin, nama);
                insertLastNetizen(LN, id, nama);
                cout << "Netizen berhasil ditambahkan.\n";
            }
            break;
        }


        case 3: {
            int idG, idN;
            cout << "ID Group: ";
            cin >> idG;
            cout << "ID Netizen: ";
            cin >> idN;

            Group *g = findGroup(LG, idG);
            Netizen *n = findNetizen(LN, idN);

            if (g != NULL && n != NULL) {
                addRelasi(LR, g, n);
                cout << "Relasi berhasil ditambahkan" << endl;
            } else {
                cout << "Group atau Netizen tidak ditemukan" << endl;
            }
            break;
        }

        case 4:
            showGroup(LG);
            break;

        case 5:
            showNetizen(LN);
            break;
        
        case 6: {
            int id;
            cout << "ID Group: ";
            cin >> id;
            Group *g = findGroup(LG, id);
            if (g != NULL) {
                cout << "Group Ditemukan: " << g->namaGroup << endl;
            } else {
                cout << "Group tidak ditemukan." << endl;
            }
            break;
        }

        case 7: {
            int id;
            cout << "ID Netizen: ";
            cin >> id;
            Netizen *n = findNetizen(LN, id);
            if (n != NULL) {
                cout << "Netizen Ditemukan: " << n->nama << endl;
            } else {
                cout << "Netizen tidak ditemukan." << endl;
            }
            break;
        }

        case 8:
            showAllGroupWithMember(LG, LR);
            break;

        case 9: {
            int id;
            cout << "ID Netizen: ";
            cin >> id;
            showGroupByNetizen(LR, id);
            break;
        }

        case 10: {
            int id;
            cout << "ID Group: ";
            cin >> id;
            showNetizenInGroup(LR, id);
            break;
        }

        case 11: {
            int id;
            cout << "ID Group yang dihapus: ";
            cin >> id;
            cout << "Group dan relasinya berhasil dihapus." << endl;
            deleteGroup(LG, LR, id);
            break;
        }

        case 12: {
            int id;
            cout << "ID Netizen yang dihapus: ";
            cin >> id;
            cout << "Netizen dan relasinya berhasil dihapus." << endl;
            deleteNetizen(LN, LR, id);
            break;
        }

        case 13: {
            int id;
            cout << "ID Group: ";
            cin >> id;
            cout << "Jumlah Member: "
                 << countMember(LR, id) << endl;
            break;
        }

        case 0:
            cout << "Program selesai." << endl;
            break;

        default:
            cout << "Pilihan tidak valid!" << endl;
        }

    } while (pilihan != 0);

    return 0;
}
