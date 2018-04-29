#ifndef HAI_H_INCLUDED
#define HAI_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstdio>
#include <istream>
#include <windows.h>
#include <conio.h>

#define next(P) (P)->next
#define prev(P) (P)->prev
#define infoDosen(P) (P)->infoDosen

#define next(Q) (Q)->next
#define prev(Q) (Q)->prev
#define infoMhs(Q) (Q)->infoMhs

#define prev(PrecDsn) (PrecDsn)->prev
#define next(PrecDsn) (PrecDsn)->next

#define nextR(R) (R)->nextR
#define prevR(R) (R)->prevR

#define refMhs(R) (R)->refMhs
#define refDsn(R) (R)->refDsn

#define next(Prec) (Prec)->next
#define prev(Prec) (Prec)->prev
#define infoMhs(Prec) (Prec)->infoMhs

#define nextR(PrecR) (PrecR)->nextR
#define prevR(PrecR) (PrecR)->prevR

#define first(LD) ((LD).first)
#define last(LD)  ((LD).last)

#define first(LM) ((LM).first)
#define last(LM)  ((LM).last)

#define first(LC) ((LC).first)

#define first(LR)  ((LR).first)


using namespace std;

typedef struct elmDosen  *adr_dosen;
typedef struct elmMhs    *adr_mhs;
typedef struct elmRelasi *adr_relasi;

struct dosen
{
    /**
    NIK terdiri 3 digit
    Jumlah dosen 504 orang
    **/
    int NIK,umurDsn;
    string namaDsn;
};

struct mhs
{
    /**
    NIM terdiri 4 digit
    Jumlah mahasiswa 3.024 orang
    **/
    int NIM, umurMhs, kelas;
    string namaMhs;
};

/**
    (Additional Information)
    Berdasarkan perhitungan kombinatorika,
    maka setiap dosen membimbing mahasiswa maksimal 6 orang.
**/

struct elmRelasi
{
    /** List ini akan berbentuk single list **/
    adr_relasi nextR;
    adr_mhs    refMhs;
    adr_dosen  refDsn;
};

struct elmDosen
{
    /** List ini akan berbentuk  double circular list **/
    dosen       infoDosen;
    adr_dosen   next,prev;
};

struct elmMhs
{
    /** List ini akan berbentuk double list **/
    mhs     infoMhs;
    adr_mhs next, prev;
};

struct ListDosen
{
    adr_dosen first;
    adr_dosen last;
};

struct ListMhs
{
    adr_mhs first;
    adr_mhs last;
};

struct ListRelasi
{
    adr_relasi first;
};

struct ListRecycle
{
    adr_relasi first;
};

void identitas();
void loadingbar();

void menu(ListDosen &LD ,ListMhs &LM, ListRelasi &LR, ListRecycle &LC);
void PenentuanRelasi(ListMhs &LM, ListDosen &LD, ListRelasi &LR);

void CreateListMhs(ListMhs &LM);
void CreateListRelasi(ListRelasi &LR);
void CreateListDosen(ListDosen &LD);
void CreateListRecycle(ListRecycle &LC);

adr_mhs AlokasiMhs(int NIM, string namaMhs, int umurMhs, int kelas);
adr_relasi AlokasiRelasi(adr_dosen refDsn, adr_mhs refMhs);
adr_dosen AlokasiDosen(int NIK, string namaDsn, int umurDsn);

void DealokasiRelasi(adr_relasi &R);
void DeleteRelasi(ListMhs &LM, ListDosen &LD, ListRelasi &LR,
    ListRecycle &LC, int NIK, int NIM, adr_relasi &R );

bool isEmpty(ListDosen LD);
bool isEmpty(ListRelasi LR);
bool isEmpty(ListMhs LM);

bool foundDosen(ListDosen LD, int NIK);
bool foundMhs(ListMhs LM, int NIM);
int  foundKelas(ListMhs LM, int kelas);

void InsertSort(ListMhs &LM, adr_mhs Q);
void InsertLast(ListRelasi &LR, adr_relasi R);
void InsertFirst(ListDosen &LD, adr_dosen P);
void InsertFirstRecycle(ListRecycle &LC, adr_relasi R);

void DeleteAfterDosen(ListMhs &LM, ListDosen &LD, ListRelasi &LR, int NIK, adr_dosen &P);
void DeleteAfterMhs(ListMhs &LM,ListDosen &LD, ListRelasi &LR, int NIM, adr_mhs &Q);

void PrintInfoDosen(ListDosen LD);
void PrintInfoMhs(ListMhs LM);

void PrintInfoMhsDsn(ListRelasi LR, ListDosen LD, ListMhs LM);
void PrintInfoDsnMhs(ListRelasi LR, ListDosen LD, ListMhs LM);

void PrintInfoDosenMahasiswa(ListRelasi LR, ListDosen LD, ListMhs LM, int NIK);
void PrintInfoMahasiswaDosen(ListRelasi LR, ListMhs LM, ListDosen LD, int NIM);

void maximum_minimum(ListRelasi &LR, ListDosen &LD, ListMhs &LM);

void DelRelasi(ListRelasi &L , adr_relasi &previous , adr_relasi &P);
void DeAllocate(adr_relasi &P);

//void DeleteAfterDosen(ListDosen &LD, adr_dosen Prec, adr_dosen &P);
//void DeleteAfterMhs(ListMhs &LM, adr_mhs Prec, adr_mhs &Q);


#endif // HAI_H_INCLUDED
