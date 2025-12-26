#include "sosmed.h"

// BUAT LIST

// inisialisasi list group
void createListGroup(ListGroup &LG) {
    LG.first = NULL;
}

// inisialisasi list netizen
void createListNetizen(ListNetizen &LN) {
    LN.first = NULL;
}

// inisialisasi list relasi
void createListRelasi(ListRelasi &LR) {
    LR.first = NULL;
}

// GROUP 
// menambahkan group di awal list
void insertFirstGroup(ListGroup &LG, int id, string nama) {
    Group *g = new Group; // buat node baru
    g->idGroup = id; // isi data id
    g->namaGroup = nama; // isi data nama
    g->next = LG.first; // hubungkan node baru ke node first lama
    LG.first = g; // setel node baru sebagai node first
}

// mencari group berdasarkan id
Group* findGroup(ListGroup LG, int id) {
    Group *p = LG.first; // mulai dari node pertama
    while (p != NULL) { // akan berhenti jika p = NULL
        if (p->idGroup == id) // jika ketemu id yang dicari 
            return p; // maka akan mengembalikan alamat node 
        p = p->next; // lanjut ke node berikutnya
    }
    return NULL; // jika tidak ketemu, kembalikan NULL
}

// menghapus group berdasarkan id
void deleteGroup(ListGroup &LG, ListRelasi &LR, int id) {
    //mencari group yang akan dihapus
    Group *p = LG.first, *prev = NULL; // mulai dari node pertama dan node sebelumnya di set NULL

    while (p != NULL && p->idGroup != id) { // terus jalan jika p tidak NULL dan id tidak ketemu
        prev = p; // set prev ke p
        p = p->next; // lanjut ke node berikutnya
    }
    //hapus node group jika ketemu
    if (p != NULL) { // jika p tidak NULL (ketemu)
        if (prev == NULL) //jika prev NULL, berarti yang dihapus adalah node pertama
            LG.first = p->next; // set first ke node berikutnya
        else
            prev->next = p->next; // lewati node p

        // hapus relasi
        Relasi *r = LR.first, *pr = NULL; // mulai dari node pertama relasi dan node sebelumnya di set NULL
        while (r != NULL) { // selama r tidak NULL
            if (r->group == p) { // jika group pada relasi sama dengan group yang dihapus
                if (pr == NULL) // jika pr NULL, berarti yang dihapus adalah node pertama
                    LR.first = r->next; // set first ke node berikutnya
                else
                    pr->next = r->next; // lewati node r
            } else { // jika tidak sama, lanjutkan
                pr = r; // set pr ke r
            }
            r = r->next; // lanjut ke node berikutnya
        }
        delete p; // hapus node group
    }
}

// menampilkan semua group
void showGroup(ListGroup LG) {
    Group *p = LG.first; // mulai dari node pertama
    while (p != NULL) { // selama p tidak NULL akan terus berjalan
        cout << "ID: " << p->idGroup // tampilkan id group
             << " | Nama Group: " << p->namaGroup << endl; // tampilkan nama group
        p = p->next; // lanjut ke node berikutnya
    }
}


//NETIZEN 

// menambahkan netizen di akhir list
void insertLastNetizen(ListNetizen &LN, int id, string nama) {
    Netizen *n = new Netizen; // buat node baru
    n->idNetizen = id; // isi data id
    n->nama = nama; // isi data nama
    n->next = NULL; // karena di akhir, next di set NULL

    if (LN.first == NULL) { // jika list kosong
        LN.first = n; // node baru menjadi node pertama
    } else {
        Netizen *p = LN.first; // pointer p mulai dari node pertama
        while (p->next != NULL) // cari node terakhir
            p = p->next; // lanjut ke node berikutnya
        p->next = n; // hubungkan node terakhir ke node baru
    }
}

// mencari netizen berdasarkan id
Netizen* findNetizen(ListNetizen LN, int id) { 
    Netizen *p = LN.first; // mulai dari node pertama
    while (p != NULL) { // selama p tidak NULL
        if (p->idNetizen == id) // jika ketemu id yang dicari
            return p; // kembalikan p
        p = p->next; // lanjut ke node berikutnya
    }
    return NULL; // jika tidak ketemu, kembalikan NULL
}

// menghapus netizen berdasarkan id
void deleteNetizen(ListNetizen &LN, ListRelasi &LR, int id) {
    //mencari netizen yang akan dihapus
    Netizen *p = LN.first, *prev = NULL; // mulai dari node pertama dan node sebelumnya di set NULL
    while (p != NULL && p->idNetizen != id) { // terus jalan jika p tidak NULL dan id tidak ketemu
        prev = p; // set prev ke p
        p = p->next; // lanjut ke node berikutnya
    }
    //hapus node netizen jika ketemu
    if (p != NULL) { // jika p tidak NULL (ketemu)
        if (prev == NULL) //jika prev NULL, berarti yang dihapus adalah node pertama
            LN.first = p->next; // set first ke node berikutnya
        else
            prev->next = p->next; // lewati node p

        // hapus relasi
        Relasi *r = LR.first, *pr = NULL; // mulai dari node pertama relasi dan node sebelumnya di set NULL
        while (r != NULL) { // selama r tidak NULL
            if (r->netizen == p) { // jika netizen pada relasi sama dengan netizen yang dihapus
                if (pr == NULL) // jika pr NULL, berarti yang dihapus adalah node pertama
                    LR.first = r->next; // set first ke node berikutnya
                else
                    pr->next = r->next; // lewati node r
            } else {
                pr = r; // jika tidak sama, lanjutkan
            }
            r = r->next; // lanjut ke node berikutnya
        }
        delete p; // hapus node netizen
    }
}

// menampilkan semua netizen
void showNetizen(ListNetizen LN) { 
    Netizen *p = LN.first; // mulai dari node pertama
    while (p != NULL) { // selama p tidak NULL
        cout << "ID: " << p->idNetizen // tampilkan id netizen
             << " | Nama: " << p->nama << endl; // tampilkan nama netizen
        p = p->next; // lanjut ke node berikutnya
    }
}

// RELASI 
// menambahkan relasi antara netizen dan group
void addRelasi(ListRelasi &LR, Group *g, Netizen *n) {
    Relasi *r = new Relasi; // buat node relasi baru
    r->group = g; // isi data group
    r->netizen = n; // isi data netizen
    r->next = LR.first; // hubungkan node baru ke node first lama
    LR.first = r; // setel node baru sebagai node first
}

// menampilkan semua group beserta anggotanya
void showAllGroupWithMember(ListGroup LG, ListRelasi LR) {
    Group *g = LG.first; // mulai dari node pertama group
    while (g != NULL) { // selama g tidak NULL
        cout << g->namaGroup << " : "; // tampilkan nama group
        Relasi *r = LR.first; // mulai dari node pertama relasi
        while (r != NULL) { // selama r tidak NULL
            if (r->group == g) // jika group pada relasi sama dengan group saat ini
                cout << r->netizen->nama << ", "; // maka tampilkan nama netizen
            r = r->next; // lanjut ke node relasi berikutnya
        }
        cout << endl; // ganti baris setelah menampilkan semua anggota group
        g = g->next; // lanjut ke node group berikutnya
    }
}

// menampilkan semua group yang berelasi dengan netizen
void showGroupByNetizen(ListRelasi LR, int idNetizen) {
    Relasi *r = LR.first; // mulai dari node pertama relasi
    while (r != NULL) { // selama r tidak NULL
        if (r->netizen->idNetizen == idNetizen) // jika netizen pada relasi sama dengan idNetizen yang dicari
            cout << r->group->namaGroup << endl; // maka akan menampilkan nama group
        r = r->next; // lanjut ke node relasi berikutnya
    }
}

// menampilkan semua netizen yang berelasi dengan group
void showNetizenInGroup(ListRelasi LR, int idGroup) {
    Relasi *r = LR.first; // mulai dari node pertama relasi
    while (r != NULL) { // selama r tidak NULL
        if (r->group->idGroup == idGroup) // jika group pada relasi sama dengan idGroup yang dicari
            cout << r->netizen->nama << endl; // maka akan menampilkan nama netizen
        r = r->next; // lanjut ke node relasi berikutnya
    }
}

// menghitung jumlah anggota dalam sebuah group
int countMember(ListRelasi LR, int idGroup) {
    int count = 0; // inisialisasi penghitung
    Relasi *r = LR.first; // mulai dari node pertama relasi
    while (r != NULL) { // selama r tidak NULL
        if (r->group->idGroup == idGroup) // jika group pada relasi sama dengan idGroup yang dicari
            count++; // tambahkan penghitung
        r = r->next; // lanjut ke node relasi berikutnya
    }
    return count; // kembalikan jumlah anggota
}