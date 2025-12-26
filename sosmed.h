#ifndef SOSMED_H
#define SOSMED_H

#include <iostream>
using namespace std;

//STRUKTUR DATA 
struct Group {
    int idGroup;
    string namaGroup;
    Group *next;
};

struct Netizen {
    int idNetizen;
    string nama;
    Netizen *next;
};

struct Relasi {
    Group *group;
    Netizen *netizen;
    Relasi *next;
};

// LIST DATA
struct ListGroup {
    Group *first;
};

struct ListNetizen {
    Netizen *first;
};

struct ListRelasi {
    Relasi *first;
};

// CREATE LIST 
void createListGroup(ListGroup &LG);
void createListNetizen(ListNetizen &LN);
void createListRelasi(ListRelasi &LR);

// GROUP 
void insertFirstGroup(ListGroup &LG, int id, string nama);
void deleteGroup(ListGroup &LG, ListRelasi &LR, int id);
Group* findGroup(ListGroup LG, int id);
void showGroup(ListGroup LG);

// NETIZEN 
void insertLastNetizen(ListNetizen &LN, int id, string nama);
void deleteNetizen(ListNetizen &LN, ListRelasi &LR, int id);
Netizen* findNetizen(ListNetizen LN, int id);
void showNetizen(ListNetizen LN);

// RELASI 
void addRelasi(ListRelasi &LR, Group *g, Netizen *n);
void showAllGroupWithMember(ListGroup LG, ListRelasi LR);
void showGroupByNetizen(ListRelasi LR, int idNetizen);
void showNetizenInGroup(ListRelasi LR, int idGroup);
int countMember(ListRelasi LR, int idGroup);

#endif
