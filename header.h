////open website dari bookmark belum
#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
#include <stdlib.h>
#include <conio.h>

#define adrURL(B) B->adrURL
#define first(L) L.first
#define URL(W) W->URL
#define prev(W) W->prev
#define next(W) W->next
#define firstAkses(W) W->firstAkses
#define waktu(A) A->waktu


using namespace std;

typedef struct elmtWebsite *adrWebsite; //POINTER KE ELEMENT DI LIST URL
typedef struct elmtAkses *adrAkses; //POINTER KE ELEMENT DI LIST TANGGAL SUATU WEBSITE DIAKSES
typedef struct elmtDate *adrDate; //POINTER KE ELEMENT DI LIST TANGGAL PENCARIAN WEBSITE YANG DIAKSES
typedef struct elmtBookmark *adrBookmark;//POINTER KE ELEMENT DI LIST BOOKMARK


struct listWebsite{
    adrWebsite first;
};

struct listAkses{
    adrAkses first;
};

struct listDate{
    adrDate first;
};

struct listBookmark{
    adrBookmark first;
};

struct Waktu{ //info waktu di listDate
    int jam, tanggal;
    string bulan, hari;
};

struct elmtWebsite{//list URL
    adrWebsite prev,next;
    string URL;
    adrAkses firstAkses;
};
struct elmtDate{//list tanggal
    adrDate prev,next;
    Waktu waktu;
};
struct elmtAkses{//list tanggal akses suatu website
    adrAkses next;
    adrDate waktu;
};

struct elmtBookmark{
    adrBookmark prev,next;
    adrWebsite adrURL;
};

adrWebsite allocateWebsite(string URL);
adrAkses allocateAkses();
adrDate allocateDate(Waktu waktu);
adrBookmark allocateBookmark(adrWebsite URL);
void insertURL(listWebsite &LWebsite, string URL);
adrWebsite searchWebsite(listWebsite LWebsite, string URL);
void openTab( listWebsite &LWebsite,listBookmark &LBookmark );
void viewHistory(listWebsite LWebsite);
void recentOpened();
void topSites();
void addBookmark(listBookmark &LBookmark, adrWebsite URL);
void openBookmark(listBookmark LBookmark);
adrBookmark searchBookmark(listWebsite LWebsite, listBookmark LBookmark, string URL);


void HistoryBySite();

#endif // HEADER_H_INCLUDED
