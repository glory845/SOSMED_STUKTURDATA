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
    Group *g = new Group;
    g->idGroup = id; 
    g->namaGroup = nama; 
    g->next = LG.first; 
    LG.first = g; 
}

// mencari group berdasarkan id
Group* findGroup(ListGroup LG, int id) {
    Group *p = LG.first; 
    while (p != NULL) { 
        if (p->idGroup == id)  
            return p;
        p = p->next; 
    }
    return NULL; 
}

// menghapus group berdasarkan id
void deleteGroup(ListGroup &LG, ListRelasi &LR, int id) {
    //mencari group yang akan dihapus
    Group *p = LG.first, *prev = NULL; 

    while (p != NULL && p->idGroup != id) { 
        prev = p; 
        p = p->next; 
    }
    //hapus node group jika ketemu
    if (p != NULL) {
        if (prev == NULL)
            LG.first = p->next; 
        else
            prev->next = p->next; 

        // hapus relasi
        Relasi *r = LR.first, *pr = NULL; 
        while (r != NULL) { 
            if (r->group == p) { 
                if (pr == NULL) 
                    LR.first = r->next; 
                else
                    pr->next = r->next; 
            } else { 
                pr = r;
            }
            r = r->next; 
        }
        delete p; 
    }
}

// menampilkan semua group
void showGroup(ListGroup LG) {
    Group *p = LG.first; 
    while (p != NULL) { 
        cout << "ID: " << p->idGroup 
             << " | Nama Group: " << p->namaGroup << endl;
        p = p->next;
    }
}


//NETIZEN 
// menambahkan netizen di akhir list
void insertLastNetizen(ListNetizen &LN, int id, string nama) {
    Netizen *n = new Netizen; 
    n->idNetizen = id; 
    n->nama = nama; 
    n->next = NULL; 

    if (LN.first == NULL) { 
        LN.first = n; 
    } else {
        Netizen *p = LN.first;
        while (p->next != NULL) 
            p = p->next; 
        p->next = n;
    }
}

// mencari netizen berdasarkan id
Netizen* findNetizen(ListNetizen LN, int id) { 
    Netizen *p = LN.first; 
    while (p != NULL) { 
        if (p->idNetizen == id)
            return p; 
        p = p->next;
    }
    return NULL; 
}

// menghapus netizen berdasarkan id
void deleteNetizen(ListNetizen &LN, ListRelasi &LR, int id) {
    //mencari netizen yang akan dihapus
    Netizen *p = LN.first, *prev = NULL; 
    while (p != NULL && p->idNetizen != id) { 
        prev = p; 
        p = p->next; 
    }
    //hapus node netizen jika ketemu
    if (p != NULL) {
        if (prev == NULL) 
            LN.first = p->next; 
        else
            prev->next = p->next; 

        // hapus relasi
        Relasi *r = LR.first, *pr = NULL; 
        while (r != NULL) { 
            if (r->netizen == p) {
                if (pr == NULL) 
                    LR.first = r->next;
                else
                    pr->next = r->next; 
            } else {
                pr = r; 
            }
            r = r->next; 
        }
        delete p; 
    }
}

// menampilkan semua netizen
void showNetizen(ListNetizen LN) { 
    Netizen *p = LN.first; 
    while (p != NULL) { 
        cout << "ID: " << p->idNetizen 
             << " | Nama: " << p->nama << endl; 
        p = p->next;
    }
}

// RELASI 
// menambahkan relasi antara netizen dan group
void addRelasi(ListRelasi &LR, Group *g, Netizen *n) {
    Relasi *r = new Relasi; 
    r->group = g; 
    r->netizen = n; 
    r->next = LR.first; 
    LR.first = r; 
}

// menampilkan semua group beserta anggotanya
void showAllGroupWithMember(ListGroup LG, ListRelasi LR) {
    Group *g = LG.first; 
    while (g != NULL) {
        cout << g->namaGroup << " : ";
        Relasi *r = LR.first; 
        while (r != NULL) { 
            if (r->group == g) 
                cout << r->netizen->nama << ", "; 
            r = r->next; 
        }
        cout << endl;
        g = g->next; 
    }
}

// menampilkan semua group yang berelasi dengan netizen
void showGroupByNetizen(ListRelasi LR, int idNetizen) {
    Relasi *r = LR.first;
    while (r != NULL) { 
        if (r->netizen->idNetizen == idNetizen) 
            cout << r->group->namaGroup << endl; 
        r = r->next; 
    }
}

// menampilkan semua netizen yang berelasi dengan group
void showNetizenInGroup(ListRelasi LR, int idGroup) {
    Relasi *r = LR.first; 
    while (r != NULL) { 
        if (r->group->idGroup == idGroup) 
            cout << r->netizen->nama << endl;
        r = r->next; 
    }
}

// menghitung jumlah anggota dalam sebuah group
int countMember(ListRelasi LR, int idGroup) {
    int count = 0;
    Relasi *r = LR.first;
    while (r != NULL) { 
        if (r->group->idGroup == idGroup) 
            count++; 
        r = r->next; 
    }
    return count;
}
