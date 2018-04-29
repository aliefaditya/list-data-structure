#include "hai.h"
//TUBES DATA BIMBINGAN TUGAS AKHIR

int main()
{
    /** Tipe Data **/
    ListDosen   LD;
    ListMhs     LM;
    ListRelasi  LR;
    ListRecycle LC;

    /** Identitas Program **/
    identitas();

    /**Pembuatan List**/
    CreateListDosen(LD);
    CreateListRelasi(LR);
    CreateListMhs(LM);
    CreateListRecycle(LC);

    /** Main Program **/
    system("cls");
    menu(LD, LM, LR, LC);

    return 0;
}
