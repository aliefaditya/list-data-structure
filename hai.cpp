#include "hai.h"


void identitas()
{
    string  nama;
    int     nim;

    system("color 06");
    cout << "\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\tTugas Data Bimbingan Akhir\n";
    nama = "Alief Aditya Rachman";
    nim  = 1301174055;
    cout << "\t\t\t\t\t Nama : " << nama << endl;
    cout << "\t\t\t\t\t NIM  : " << nim  << endl;
    cout << "\t\t\t\t\t" << system("pause");
}

void loadingbar()
{
    system("color 2f");
    system("color 0e");
    char a = 177, b = 219;
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tLoading...";
    cout << "\n";
    cout << "\t\t\t\t\t";
    for (int i=0;i<=25;i++)
    {
        cout << a;
        Sleep(150);
    }
    cout << "\r";
    cout << "\t\t\t\t\t";
    for (int i = 0;i <= 25;i++)
    {
        cout << b;
        Sleep(200);
    }
    system("pause>0");
    system("cls");
}

void menu(ListDosen &LD ,ListMhs &LM, ListRelasi &LR, ListRecycle &LC)
{
    int         angka, NIM, NIK, umurDsn, umurMhs, pilihan, i, iDsn, counter, banyakKelas, kelas;
    string      namaMhs, namaDsn;
    char        konfirmasi, out;
    adr_dosen   P, PrecDsn;
    adr_mhs     Prec, Q;
    adr_relasi  r, R;
    bool        cekMhs, cekDsn, cekNIK, cekNIM;
    char        input, ulang, conf;

    system("color 07");
    //assign
    iDsn        = 1;
    banyakKelas = 01;
    ulang       = 'y';

    cout << endl;
    while ((ulang == 'y')||(ulang == 'Y'))
    {
        cout << endl;
        cout << "\t\t\t\t\t Program Data Bimbingan Tugas Akhir  \n";
        cout << "\t\t\t\t\t  S1 Teknik Informatika 2018/2019\n";
        cout << "\t\t\t\t\t  1. Insert Data\n";
        cout << "\t\t\t\t\t  2. Delete Data\n";
        cout << "\t\t\t\t\t  3. Print Info\n";
        cout << "\t\t\t\t\t  4. Exit\n";
        cout << "\t\t\t\t\t Pilihan [1/2/3/4] : ";
        cin  >> pilihan;
        switch(pilihan)
        {
            case 1 :
                      cout << "\t\t\t\t\t ========================================\n";
                      cout << "\t\t\t\t\t You have choosen Insert Data to Program\n";
                      cout << "\t\t\t\t\t 1. Insert Data to Dosen List\n";
                      cout << "\t\t\t\t\t 2. Insert Data to Mahasiswa List\n";
                      cout << "\t\t\t\t\t 3. Create the Relation\n";
                      cout << "\t\t\t\t\t Pilihan[1/2/3]: ";
                      cin  >> angka;
                      cout << "\t\t\t\t\t ==================================\n";
                      switch(angka)
                      {
                          case 1 :
                              cout << "\t\t\t\t\t Banyak Data Dosen yang Diinput: ";
                              cin  >> counter;
                              cout << endl;
                              while (iDsn <= counter)
                              {
                                    cout << "\t\t\t\t\t [NIK BERUPA ANGKA & 3 DIGIT]\n";
                                    cout << "\t\t\t\t\t NIK data ke "<<iDsn<<" : ";
                                    cin  >> NIK;
                                    while ((NIK < 100) || (NIK > 999))
                                    {
                                        system("color 04");
                                        cout << "\t\t\t\t\t 3 DIGIT UNTUK NIK" << endl;
                                        system("color 07");
                                        cout << "\t\t\t\t\t Silahkan input kembali untuk data NIK"<<endl;
                                        cout << "\t\t\t\t\t NIK data ke  "<<iDsn<<": ";
                                        cin  >> NIK;
                                    }
                                    cout << "\t\t\t\t\t Nama data ke "<<iDsn<<": ";
                                    cin.ignore();
                                    getline(cin, namaDsn);
                                    cout << "\t\t\t\t\t Umur "<<namaDsn<<"   : ";
                                    cin  >> umurDsn;
                                    cekDsn = foundDosen(LD, NIK);
                                    if (cekDsn == false)
                                    {
                                        //NIK tidak ada yang sama, lakukan proses Insert
                                        P = AlokasiDosen(NIK, namaDsn, umurDsn);
                                        InsertFirst(LD, P);
                                    }
                                    else
                                    {
                                        system("color 04");
                                        cout << "\t\t\t\t\t NIK tersebut sudah tersedia dalam list\n";
                                        system("color 07");
                                        cout << "\t\t\t\t\t Apakah anda akan melanjutkan proses pengisian data[y/t]: ";
                                        cin  >> konfirmasi;
                                        if ((konfirmasi == 'y')||(konfirmasi == 'Y'))
                                        {
                                           while (cekDsn == true)
                                           {
                                               cout << "\t\t\t\t\t NIK data ke "<<iDsn<<": ";
                                               cin  >> NIK;
                                               while ((NIK < 100) || (NIK > 999))
                                               {
                                                  system("color 04");
                                                  cout << "\t\t\t\t\t 3 DIGIT UNTUK NIK" << endl;
                                                  system("color 07");
                                                  cout << "\t\t\t\t\t Silahkan input kembali untuk data NIK"<<endl;
                                                  cout << "\t\t\t\t\t NIK data ke  "<<iDsn<<" : ";
                                                  cin  >> NIK;
                                               }
                                               cout << "\t\t\t\t\t Nama data ke "<<iDsn<<": ";
                                               cin.ignore();
                                               getline(cin, namaDsn);
                                               cout << "\t\t\t\t\t Umur "<<namaDsn<<"     : ";
                                               cin  >> umurDsn;
                                               cekDsn = foundDosen(LD, NIK);
                                               if (cekDsn == true)
                                               {
                                                   system("color 04");
                                                   cout << "\t\t\t\t\t NIK tersebut sudah ada dalam list";
                                                   system("color 07");
                                               }
                                           }
                                           P = AlokasiDosen(NIK, namaDsn, umurDsn);
                                           InsertFirst(LD, P);
                                        }
                                    }
                                    iDsn++;
                              }
                              iDsn = 1;
                              cout << endl;
                              ulang = 'Y';
                              break;
                          case 2 :
                              cout << "\t\t\t\t\t ==================================\n";
                              cout << "\t\t\t\t\t Banyak Data Mahasiswa/i yang Diinput: ";
                              cin  >> counter;
                              cout << endl;
                              i = 1;
                                    while (i <= counter)
                                    {
                                        system("color 04");
                                        cout << "\t\t\t\t\t INFO [NIM BERISI 4 DIGIT]\n";
                                        system("color 07");
                                        cout << "\t\t\t\t\t NIM data ke  "<<i<<": ";
                                        cin  >> NIM;
                                        while ((NIM < 1000) || (NIM > 9999))
                                        {
                                            system("color 04");
                                            cout << "\t\t\t\t\t 4 DIGIT UNTUK NIM" << endl;
                                            system("color 07");
                                            cout << "\t\t\t\t\t Silahkan input kembali untuk data NIM"<<endl;
                                            cout << "\t\t\t\t\t NIM data ke  "<<i<<": ";
                                            cin  >> NIM;
                                        }
                                        cekMhs = foundMhs(LM, NIM);
                                        if((i > 40)&&(banyakKelas <= 12))
                                        {
                                            banyakKelas++;
                                            i = 1;
                                        }
                                        kelas = banyakKelas;
                                        if (cekMhs == false)
                                        {
                                            //NIM tidak ada yang sama, lakukan proses insert
                                            cout << "\t\t\t\t\t Nama data ke  "<<i<<": ";
                                            cin.ignore();
                                            getline(cin, namaMhs);
                                            cout << "\t\t\t\t\t Umur "<<namaMhs<<": ";
                                            cin  >> umurMhs;
                                            cout << "\t\t\t\t\t Kelas IF - 38 - ..."<<" : "<<kelas;
                                            cout << endl;
                                            Q = AlokasiMhs(NIM, namaMhs, umurMhs, kelas);
                                            InsertSort(LM, Q);
                                        }
                                        else
                                        {
                                            system("color 04");
                                            cout << "\t\t\t\t\t NIM tersebut sudah tersedia dalam list\n";
                                            system("color 07");
                                            cout << "\t\t\t\t\t Apakah anda akan melanjutkan proses pengisian data[y/t]: ";
                                            cin  >> konfirmasi;
                                            if ((konfirmasi == 'y')||(konfirmasi == 'Y'))
                                            {
                                               while (cekMhs == true)
                                               {
                                                   cout << "\t\t\t\t\t NIM data ke "<<i<<": ";
                                                   cin  >> NIM;
                                                   while ((NIM < 1000) || (NIM > 9999))
                                                   {
                                                      system("color 04");
                                                      cout << "\t\t\t\t\t 4 DIGIT UNTUK NIK" << endl;
                                                      system("color 07");
                                                      cout << "\t\t\t\t\t Silahkan input kembali untuk data NIM"<<endl;
                                                      cout << "\t\t\t\t\t NIM data ke  "<<i<<": ";
                                                      cin  >> NIM;
                                                   }
                                                   cekMhs = foundMhs(LM, NIM);
                                                   if ((i > 40)&&(banyakKelas<=12))
                                                   {
                                                       banyakKelas++;
                                                       i = 1;
                                                   }
                                                   kelas = banyakKelas;
                                                   if (cekMhs == true)
                                                   {
                                                       system("color 04");
                                                       cout << "\t\t\t\t\t NIM tersebut sudah tersedia dalam list\n";
                                                       system("color 07");
                                                   }
                                                   else
                                                   {
                                                        cout << "\t\t\t\t\t Nama data ke "<<i<<": ";
                                                        cin.ignore();
                                                        getline(cin, namaMhs);
                                                        cout << "\t\t\t\t\t Umur "<<namaMhs<<"   : ";
                                                        cin  >> umurMhs;
                                                        cout << "\t\t\t\t\t Kelas IF - 38 - "<<" : "<<kelas;
                                                        cout << endl;
                                                   }
                                               }
                                               Q = AlokasiMhs(NIM, namaMhs, umurMhs, kelas);
                                               InsertSort(LM, Q);
                                            }
                                        }
                                        i++;
                                    }
                              counter = 0;
                              ulang = 'Y';
                              break;
                         case 3 :
                              cout << "\t\t\t\t\t ==================\n";
                              cout << "\t\t\t\t\t       RELASI      \n";
                              cout << "\t\t\t\t\t ==================\n";
                              PenentuanRelasi(LM, LD, LR);
                      }
                      cout << "\t\t\t\t\t Repeat Process [Y/N]: ";
                      cin  >> ulang;
                      system("cls");
                      break;
            case 2 : "\t\t\t\t\t You have choosen Delete Data to List\n";
                      cout << "\t\t\t\t\t 1. Delete Data from Dosen List\n";
                      cout << "\t\t\t\t\t 2. Delete Data from Mahasiswa List\n";
                      cout << "\t\t\t\t\t Pilihan[1/2] : ";
                      cin  >> angka;
                      switch(angka)
                      {
                          case 1 :
                              input = 'y';
                              while ((input == 'Y')||(input == 'y'))
                              {
                                  cout << "\t\t\t\t\t Search by NIK : ";
                                  cin  >> NIK;
                                  cekNIK = foundDosen(LD, NIK);
                                  if (cekNIK)
                                  {
                                      /// NIK Tersedia
                                      NIM = 0;
                                      DeleteRelasi(LM, LD, LR, LC, NIK, NIM, R);
                                      cout << "\t\t\t\t\t Data Dosen berhasil dihapus\n";
                                  }
                                  else
                                  {
                                      cout << "\t\t\t\t\t NIK Tersebut tidak tersedia untuk dihapus\n";
                                  }
                                  cout << "\t\t\t\t\t MENGHAPUS LAGI?[Y/N]: ";
                                  cin  >> input;
                              }
                              cout << "\t\t\t\t\t Repeat Process [Y/N]: ";
                              cin  >> ulang;
                              system("cls");
                              break;
                          case 2 :
                              input = 'y';
                              while ((input == 'Y')||(input == 'y'))
                              {
                                  cout << "\t\t\t\t\t Search by NIM : ";
                                  cin  >> NIM;
                                  cekNIM = foundMhs(LM, NIM);
                                  if (cekNIM)
                                  {
                                      NIK = 0;
                                      DeleteRelasi(LM, LD, LR, LC, NIK, NIM, R);
                                      cout << "\t\t\t\t\t Data Mahasiswa berhasil dihapus\n";
                                  }
                                  else
                                  {
                                      cout << "\t\t\t\t\t NIM Tersebut tidak tersedia untuk dihapus\n";
                                  }
                                  cout << "\t\t\t\t\t MENGHAPUS LAGI?[Y/N]: ";
                                  cin  >> input;
                              }
                              cout << "\t\t\t\t\t Repeat Process [Y/N]: ";
                              cin  >> ulang;
                              system("cls");
                              break;
                      }
                      break;
           case 3 : "\t\t\t\t\t Print Info";
                     cout << "\t\t\t\t\t 1. Data Mahasiswa beserta dosen Pembimbing\n";
                     cout << "\t\t\t\t\t 2. Data mahasiswa yang di bimbing oleh dosen tertentu(search dosen)\n";
                     cout << "\t\t\t\t\t 3. Data dosen yang membimbing mahasiswa tertentu (search mahasiswa)\n";
                     cout << "\t\t\t\t\t 4. Data dosen yang memiliki jumlah mahasiswa bimbingan paling banyak dan juga paling sedikit\n";
                     cout << "\t\t\t\t\t Pilihan[1/2/3/4]: ";
                     cin  >> angka;
                     switch (angka)
                     {
                        case 1 :
                                cout << endl;
                                cout << "\t\t\t\t\t ==================================\n";
                                cout << endl;
                                PrintInfoMhsDsn(LR, LD, LM);
                                cout << "\t\t\t\t\t Repeat Process [Y/N]: ";
                                cin  >> ulang;
                                system("cls");
                                break;
                        case 2 :
                                cout << "\t\t\t\t\t Input Data Dosen (NIK): ";
                                cin  >> NIK;
                                cout << endl;
                                cekDsn = foundDosen(LD, NIK);
                                if (cekDsn == true)
                                {
                                    cout << endl;
                                    cout << "\t\t\t\t\t ==================================\n";
                                    cout << endl;
                                    PrintInfoDosenMahasiswa(LR, LD, LM, NIK);
                                }
                                cout << "\t\t\t\t\t Repeat Process [Y/N]: ";
                                cin  >> ulang;
                                system("cls");
                                break;
                        case 3 :
                                cout << "\t\t\t\t\t Input Data Mahasiswa (NIM): ";
                                cin  >> NIM;
                                cout << endl;
                                cekMhs = foundMhs(LM, NIM);
                                if (cekMhs == true)
                                {
                                    cout << endl;
                                    cout << "\t\t\t\t\t ==================================\n";
                                    cout << endl;
                                    PrintInfoMahasiswaDosen(LR, LM, LD, NIM);
                                }
                                cout << "\t\t\t\t\t Repeat Process [Y/N]: ";
                                cin  >> ulang;
                                system("cls");
                                break;
                        case 4 :
                                cout << endl;
                                maximum_minimum(LR, LD, LM);
                                cout << "\t\t\t\t\t Repeat Process [Y/N]: ";
                                cin  >> ulang;
                                system("cls");
                                break;
                     }
                     break;
           case 4 :
                    cout << "\t\t\t\t\t ==================================\n";
                    cout << "\t\t\t\t\t Apakah anda yakin untuk exit[y/n]: ";
                    cin  >> conf;
                    if (conf == 'y')
                    {
                        ulang = 'n';
                    }
                    break;
        }
    }
}

void PenentuanRelasi(ListMhs &LM, ListDosen &LD, ListRelasi &LR)
{
    /** MENENTUKAN RELASI ANTAR MAHASISWA DENGAN DOSEN **/

    int              NIM, NIK, n, counter;
    adr_relasi       R;
    char             pilihan, input;
    adr_dosen        refDsn, P, p;
    adr_mhs          refMhs, Q;
    bool             cekMhs, cekDsn;

    n = 1;
    counter = 1;
    pilihan = 'c';
    input   = 'Y';

    if((isEmpty(LD) == false) && (isEmpty(LM) == false))
    {
        //Ada Elemen List
        while ((input == 'Y')||(input == 'y'))
        {
            cout << "\t\t\t\t\t Data Mahasiswa "<<counter<<"\n";
            cout << "\t\t\t\t\t NIM    : ";
            cin  >> NIM;
            cekMhs = foundMhs(LM, NIM);
            if (cekMhs == true)
            {
                Q = first(LM);
                while (infoMhs(Q).NIM != NIM)
                {
                    Q = next(Q);
                }
                cout << "\t\t\t\t\t Input Data Dosen Pembimbing[E/C]: ";
                cin  >> pilihan;
                while ((n<=2)&&((pilihan == 'c')||(pilihan == 'C')))
                {
                    cout << "\t\t\t\t\t Data Dosen Pembimbing " <<n<<endl;
                    cout << "\t\t\t\t\t NIK    : ";
                    cin  >> NIK;
                    cekDsn = foundDosen(LD, NIK);
                    if (cekDsn == true)
                    {
                        if ((n<=1)||((n==2)&&(infoDosen(p).NIK != NIK)))
                        {
                            P = first(LD);
                            while (infoDosen(P).NIK != NIK)
                            {
                                P = next(P);
                            }
                            refMhs = Q;
                            refDsn = P;
                            p = refDsn;
                            R = AlokasiRelasi(refDsn,refMhs);
                            InsertLast(LR, R);
                            if (n == 1)
                            {
                                cout << "\t\t\t\t\t Exit or Continue[E/C]: ";
                                cin  >> pilihan;
                            }
                            n++;
                        }
                        else if ((n==2)&&(infoDosen(p).NIK == NIK))
                        {
                            system("color 04");
                            cout << "\t\t\t\t\t Data dosen "<<n-1<<" sama dengan data dosen "<<n<<"\n";
                            cout << "\t\t\t\t\t Anda tidak dapat memilih data dosen pembimbing "<<n<<"\n";
                            system("color 07");
                            cout << "\t\t\t\t\t Exit or Continue[E/C]: ";
                            cin  >> pilihan;
                            if ((pilihan == 'C')||(pilihan == 'c'))
                            {
                                while (infoDosen(p).NIK == NIK)
                                {
                                    cout << "\t\t\t\t\t Data Dosen Pembimbing " <<n<<endl;
                                    cout << "\t\t\t\t\t NIK    : ";
                                    cin  >> NIK;
                                }
                                    cekDsn = foundDosen(LD, NIK);
                                    if ((cekDsn == true)&&(infoDosen(p).NIK != NIK))
                                    {
                                        P = first(LD);
                                        while (infoDosen(P).NIK != NIK)
                                        {
                                            P = next(P);
                                        }
                                        refMhs = Q;
                                        refDsn = P;
                                        p = NULL;
                                        R = AlokasiRelasi(refDsn,refMhs);
                                        InsertLast(LR, R);
                                    }
                                n=3;
                            }
                        }
                    }
                    else
                    {
                        system("color 04");
                        cout << "\t\t\t\t\t NIM tersebut tidak ada di list\n";
                        system("color 07");
                        cout << "\t\t\t\t\t Exit or Continue[E/C]: ";
                        cin  >> pilihan;
                    }
                }
            }
            else
            {
                system("color 04");
                cout << "\t\t\t\t\t Data NIM tidak ditemukan\n";
                cout << "\t\t\t\t\t List Dosen dan Mahasiswa tidak bisa direlasikan\n";
                system("color 07");
            }
            cout << endl;
            cout << "\t\t\t\t\t Input NIM kembali[Y/N]: ";
            cin  >> input;
            counter++;
            n=1;
        }
    }
    else
    {
        cout << "\t\t\t\t\t List Kosong\n";
    }
}

void DeleteRelasi(ListMhs &LM, ListDosen &LD, ListRelasi &LR,
    ListRecycle &LC, int NIK, int NIM, adr_relasi &R )
{
    /** DELETE RELASI, JIKA ADA **/

    adr_dosen P, refDsn, p;
    adr_mhs   Q, refMhs, q;
    adr_relasi r, r_belakang;
    char repeat;

    if (isEmpty(LR) == false)
    {
        R = first(LR);
        //r = first(LR);
        r_belakang = NULL;
        if ((NIK >= 100)&&(NIK <= 999)&&(NIM == 0))
        {
            ///HAPUS BERDASARKAN DATA DOSEN
            P = first(LD);
            while ((next(P)!=first(LD))&&(infoDosen(P).NIK != NIK))
            {
                P = next(P);
            }
            if (infoDosen(P).NIK != NIK)
            {
                P = NULL;
            }
            ///jika NULL artinya data tidak ada
            do{
                r_belakang = NULL;
                R = first(LR);
                while ((P != NULL) && (R != NULL) && (refDsn(R) != P))
                {
                    r_belakang = R;
                    R = nextR(R);
                }
                if((P != NULL) && (R != NULL)){
                    DelRelasi(LR , r_belakang , R);
                    R = first(LR);
                }
            }while((R != NULL) && (P != NULL));

            DeleteAfterDosen(LM, LD, LR, NIK, P);
        }
        if ((NIM >= 1000)&&(NIM <= 9999)&&(NIK == 0))
        {
            ///HAPUS BERDASARKAN DATA MAHASISWA
            Q = first(LM);
            while ((next(Q)!=NULL)&&(infoMhs(Q).NIM != NIM))
            {
                Q = next(Q);
            }
            if (infoMhs(Q).NIM != NIM)
            {
                Q = NULL;
            }
            ///jika NULL artinya data tidak ada
            do{
                r_belakang = NULL;
                R = first(LR);
                while ((Q != NULL) && (R != NULL) && (refMhs(R) != Q))
                {
                    r_belakang = R;
                    R = nextR(R);
                }
                if((R != NULL) && (Q != NULL)){
                    DelRelasi(LR , r_belakang , R);
                    R = first(LR);
                }
            }while((R != NULL) && (Q != NULL));

            DeleteAfterMhs(LM, LD, LR, NIM, Q);
            }
        }
    }

void DelRelasi(ListRelasi &L , adr_relasi &previous , adr_relasi &P){

    if(nextR(first(L)) == NULL)
    {
        first(L) = NULL;
    }
    else if(previous == NULL)
    {
        first(L) = nextR(P);
    }
    else
    {
        nextR(previous) = nextR(P);
    }
    DeAllocate(P);

}

void DeAllocate(adr_relasi &P){
    nextR(P) = NULL;
    delete(P);
    P = NULL;
}

void CreateListDosen(ListDosen &LD)
{
    first(LD) = NULL;
    last(LD)  = NULL;
}

void CreateListMhs(ListMhs &LM)
{
    first(LM)   = NULL;
    last(LM)    = NULL;
}

void CreateListRelasi(ListRelasi &LR)
{
    first(LR)   = NULL;
}

void CreateListRecycle(ListRecycle &LC)
{
    first(LC)   = NULL;
}

adr_dosen AlokasiDosen(int NIK, string namaDsn, int umurDsn)
{
    adr_dosen P;

    P                    = new elmDosen;
    infoDosen(P).NIK     = NIK;
    infoDosen(P).namaDsn = namaDsn;
    infoDosen(P).umurDsn = umurDsn;
    next(P)              = NULL;
    prev(P)              = NULL;

    return P;
}

adr_mhs AlokasiMhs(int NIM, string namaMhs, int umurMhs, int kelas)
{
    adr_mhs Q;

    Q                   = new elmMhs;
    next(Q)             = NULL;
    prev(Q)             = NULL;
    infoMhs(Q).NIM      = NIM;
    infoMhs(Q).namaMhs  = namaMhs;
    infoMhs(Q).umurMhs  = umurMhs;
    infoMhs(Q).kelas    = kelas;

    return Q;
}

adr_relasi AlokasiRelasi(adr_dosen refDsn, adr_mhs refMhs)
{
    adr_relasi R;

    R         = new elmRelasi;
    refMhs(R) = refMhs;
    refDsn(R) = refDsn;
    nextR(R)  = NULL;

    return R;
}

void DealokasiRelasi(adr_relasi &R)
{
    delete R;
}

bool isEmpty(ListDosen LD)
{
    return ((first(LD) == NULL) && (last(LD) == NULL));
}

bool isEmpty(ListRelasi LR)
{
    return (first(LR)== NULL);
}

bool isEmpty(ListMhs LM)
{
    return ((first(LM)== NULL) && (last(LM) == NULL));
}

/** COUNT KELAS **/
int foundKelas(ListMhs LM, int kelas)
{
    adr_mhs Q, q;
    int     i = 0;

    if (isEmpty(LM) == false)
    {
        Q = first(LM);
        while (Q != NULL)
        {
            if (infoMhs(Q).kelas == kelas)
            {
                i++;
            }
            Q = next(Q);
        }
    }
    return i;
}

/** SEARCH DOSEN **/
bool foundDosen(ListDosen LD, int NIK)
{
    adr_dosen P, PrecDsn;

    bool cekDosen = false;

    if (isEmpty(LD) == false)
    {
        ///ada elemen
        P = first(LD);
        while ((next(P) != first(LD)) && ((infoDosen(P).NIK != NIK)))
        {
            P = next(P);
        }
        ///cout<<cekDosen;
        if (infoDosen(P).NIK == NIK)
        {
            PrecDsn = prev(P);
            cekDosen = true;
        }
    }
    return cekDosen;
}

/** SEARCH MAHASISWA **/
bool foundMhs(ListMhs LM, int NIM)
{
    adr_mhs Q, Prec;
    bool cekMhs = false;

    if (isEmpty(LM) == false)
    {
        Q = first(LM);
        while ((Q != NULL) && (infoMhs(Q).NIM != NIM))
        {
            Q = next(Q);
        }
        if (Q != NULL)
        {
            cekMhs = true;
        }
    }
    return cekMhs;
}


void DeleteAfterDosen(ListMhs &LM, ListDosen &LD, ListRelasi &LR, int NIK, adr_dosen &P)
{
    adr_dosen  PrecDsn;
    adr_relasi R, r;
    adr_mhs    Q;

    if ((isEmpty(LD) == false))
    {
        PrecDsn = prev(P);

        if (infoDosen(P).NIK == NIK)
        {
            if ((P == first(LD))&&(P == last(LD)))
            {
                /** 1 ELEMEN **/
                ///POINTER P DI AWAL DAN AKHIR
                first(LD)   = NULL;
                last(LD)    = NULL;
                next(P)     = NULL;
                prev(P)     = NULL;
            }
            else if (P == first(LD))
            {
                ///PREC DI AKHIR
                first(LD)          = next(P);
                next(PrecDsn)      = first(LD);
                prev(first(LD))    = PrecDsn;
                next(P)            = NULL;
                prev(P)            = NULL;
            }
            else if (P == last(LD))
            {
                ///P DI AKHIR
                last(LD)            = PrecDsn;
                next(last(LD))      = first(LD);
                prev(first(LD))     = last(LD);
                next(P)             = NULL;
                prev(P)             = NULL;
            }
            else
            {
                /** ELEMEN DI TENGAH **/
                ///   P DI TENGAH
                next(PrecDsn)       = next(P);
                prev(next(P))       = PrecDsn;
                next(P)             = NULL;
                prev(P)             = NULL;
            }
        }
        ///PRINT INFO BERDASARKAN DATA MAHASISWA
        PrintInfoMhsDsn(LR, LD, LM);
    }
}


void DeleteAfterMhs(ListMhs &LM,ListDosen &LD, ListRelasi &LR, int NIM, adr_mhs &Q)
{
    adr_mhs    Prec;
    adr_relasi R, r;
    adr_dosen  P;

    if (isEmpty(LM) == false)
    {
        Q = first(LM);
        while ((next(Q) != NULL)&&(infoMhs(Q).NIM != NIM))
        {
            ///CEK ELEMEN
            Prec = Q;
            Q = next(Q);
        }
        if (infoMhs(Q).NIM == NIM)
        {
            if ((Q == first(LM)) && (Q == last(LM)))
            {
                /** 1 ELEMEN **/
                first(LM)   = NULL;
                last(LM)    = NULL;
                next(Q)     = NULL;
                prev(Q)     = NULL;
            }
            else
            {
                if (Q == first(LM))
                {
                    first(LM)                = next(Q);
                    prev(first(LM))          = NULL;
                    next(Q)                  = NULL;
                    prev(Q)                  = NULL;
                }
                else if (Q == last(LM))
                {
                    last(LM)            = Prec;
                    next(last(LM))      = NULL;
                    prev(first(LM))     = NULL;
                    next(Q)             = NULL;
                    prev(Q)             = NULL;
                }
                else
                {
                    next(Prec)          = next(Q);
                    prev(next(Q))       = Prec;
                    next(Q)             = NULL;
                    prev(Q)             = NULL;
                }
            }
        }
        ///PRINT INFO BERDASARKAN DATA DOSEN
        PrintInfoDsnMhs(LR, LD, LM);
    }
}

void InsertFirst(ListDosen &LD, adr_dosen P)
{
    if (isEmpty(LD))
    {
        first(LD) = P;
        last(LD)  = P;
        next(P)  = P;
        prev(P)  = P;
    }
    else
    {
        next(P)         = first(LD);
        prev(first(LD)) = P;
        next(last(LD))  = P;
        prev(P)         = last(LD);
        first(LD)       = P;
    }
}

void InsertFirstRecycle(ListRecycle &LC, adr_relasi R)
{
    if (first(LC) == NULL)
    {
        first(LC) = R;
        nextR(R)  = NULL;
        //agar tidak bug atau menunjuk suatu alamat lain.
        refMhs(R) = NULL;
        refDsn(R) = NULL;
    }
    else
    {
        nextR(R)         = first(LC);
        first(LC)        = R;
        //agar tidak bug atau menunjuk suatu alamat lain.
        refMhs(R)        = NULL;
        refDsn(R)        = NULL;
    }
}

void InsertSort(ListMhs &LM, adr_mhs Q)
{
    /** INSERTION SORT BY NIM **/

    adr_mhs Prec;

    if (isEmpty(LM) == true)
    {
        first(LM)       = Q;
        last(LM)        = Q;
        next(Q)         = NULL;
        prev(Q)         = NULL;
    }
    else
    {
        if (infoMhs(Q).NIM <= infoMhs(first(LM)).NIM)
        {
            next(Q)         = first(LM);
            prev(first(LM)) = Q;
            first(LM)       = Q;
        }
        else if (infoMhs(Q).NIM >= infoMhs(last(LM)).NIM)
        {
            prev(Q)        = last(LM);
            next(last(LM)) = Q;
            last(LM)       = Q;

        }
        else
        {
            Prec = first(LM);
            while (infoMhs(Q).NIM > infoMhs(next(Prec)).NIM)
            {
                Prec = next(Prec);
            }
            next(Q)          = next(Prec);
            prev(Q)          = Prec;
            prev(next(Prec)) = Q;
            next(Prec)       = Q;
        }
    }
}

void InsertLast(ListRelasi &LR, adr_relasi R)
{
    adr_relasi PrecR;

    if (isEmpty(LR))
    {
        first(LR)        = R;
        nextR(R)         = NULL;
    }
    else
    {
        PrecR = first(LR);
        while (nextR(PrecR) != NULL)
        {
            PrecR = nextR(PrecR);
        }
        nextR(PrecR) = R;
        nextR(R)     = NULL;
    }
}

void PrintInfoDosen(ListDosen LD)
{
    adr_dosen P;
    int i = 0;

    if (isEmpty(LD) == false)
    {
        //List tidak kosong
        P = first(LD);
        i = 1;
        while ((P != NULL) && (next(P) != first(LD)))
        {
            cout << "\t\t\t\t\t Data (" <<i<< ") NIK Dosen  : " << infoDosen(P).NIK << " " << endl;
            cout << "\t\t\t\t\t Data (" <<i<< ") Nama Dosen : " << infoDosen(P).namaDsn << " " << endl;
            cout << "\t\t\t\t\t Data (" <<i<< ") Umur Dosen : " << infoDosen(P).umurDsn << " " << endl;
            P = next(P);
            i++;
        }
        cout << "\t\t\t\t\t Data (" <<i<< ") NIK Dosen  : " << infoDosen(P).NIK << " " << endl;
        cout << "\t\t\t\t\t Data (" <<i<< ") Nama Dosen : " << infoDosen(P).namaDsn << " " << endl;
        cout << "\t\t\t\t\t Data (" <<i<< ") Umur Dosen : " << infoDosen(P).umurDsn << " " << endl;
        i = 0;
    }
    else
    {
        cout << "List kosong";
    }
}

void PrintInfoMhs(ListMhs LM)
{
    adr_mhs Q;
    int i = 1;

    if (isEmpty(LM)== false)
    {
        Q = first(LM);
        while (Q != NULL)
        {

            cout << "\t\t\t\t\t Data (" <<i<< ") NIM Mahasiswa  : " << infoMhs(Q).NIM << " " << endl;
            cout << "\t\t\t\t\t Data (" <<i<< ") Nama Mahasiswa : " << infoMhs(Q).namaMhs << " " << endl;
            cout << "\t\t\t\t\t Data (" <<i<< ") Umur Mahasiswa : " << infoMhs(Q).umurMhs << " " << endl;
            cout << "\t\t\t\t\t Data (" <<i<< ") Kelas Mahasiswa: " << infoMhs(Q).kelas << " " << endl;
            Q = next(Q);
            i++;
        }
        i = 0;
    }
}

void PrintInfoMhsDsn(ListRelasi LR, ListDosen LD, ListMhs LM)
{
    /**
    CEK HANYA DI LIST RELASI UNTUK MELIHAT RELASI DATA ANTAR KEDUA LIST DOSEN & MAHASISWA
    LALU, DIOUTPUTKAN
    **/


    adr_dosen  P, refDsn;
    adr_relasi R;
    adr_mhs    Q;
    int        iMhs, iDosen;

    iMhs = 1;
    iDosen = 1;

    if(first(LR) != NULL)
    {
        R = first(LR);
        Q = first(LM);
        while (( R != NULL ) && ( Q != NULL ))
        {
            cout << "\t\t\t\t\t DATA MAHASISWA "    << infoMhs(Q).namaMhs << endl;
            cout << "\t\t\t\t\t NIM Mahasiswa   : " << infoMhs(Q).NIM << endl;
            cout << "\t\t\t\t\t Nama Mahasiswa  : " << infoMhs(Q).namaMhs << endl;
            cout << "\t\t\t\t\t Umur Mahasiswa  : " << infoMhs(Q).umurMhs << endl;
            cout << "\t\t\t\t\t Kelas Mahasiswa : " << infoMhs(Q).kelas << endl;

            while (R != NULL)
            {
                if (refMhs(R) == Q)
                {
                    cout << "\t\t\t\t\t DOSEN PEMBIMBING "  << infoMhs(Q).namaMhs << endl;
                    cout << "\t\t\t\t\t NIK Dosen       : " << infoDosen(refDsn(R)).NIK << endl;
                    cout << "\t\t\t\t\t Nama Dosen      : " << infoDosen(refDsn(R)).namaDsn << endl;
                    cout << "\t\t\t\t\t Umur Dosen      : " << infoDosen(refDsn(R)).umurDsn << endl;
                }
                R = nextR(R);
            }
            Q = next(Q);
            R = first(LR);
            cout << endl;
        }
        iMhs = 0;
        iDosen = 0;
    }
    else
    {
        Q = first(LM);
        while (Q != NULL )
        {
            cout << "\t\t\t\t\t DATA MAHASISWA "    << infoMhs(Q).namaMhs  << endl;
            cout << "\t\t\t\t\t NIM Mahasiswa   : " << infoMhs(Q).NIM      << endl;
            cout << "\t\t\t\t\t Nama Mahasiswa  : " << infoMhs(Q).namaMhs  << endl;
            cout << "\t\t\t\t\t Umur Mahasiswa  : " << infoMhs(Q).umurMhs  << endl;
            cout << "\t\t\t\t\t Kelas Mahasiswa : " << infoMhs(Q).kelas    << endl;
            Q = next(Q);
        }
    }
}

void PrintInfoDsnMhs(ListRelasi LR, ListDosen LD, ListMhs LM)
{
    /**
    CEK HANYA DI LIST RELASI UNTUK MELIHAT RELASI DATA ANTAR KEDUA LIST DOSEN & MAHASISWA
    LALU, DIOUTPUTKAN
    **/


    adr_dosen  P, refDsn;
    adr_relasi R;
    adr_mhs    Q;
    int        iMhs, iDosen;

    iMhs = 1;
    iDosen = 1;

    if(first(LR) != NULL)
    {
        R = first(LR);
        P = first(LD);
        while (( R != NULL ) && (next(P) != first(LD)))
        {
            cout << "\t\t\t\t\t DATA DOSEN "    << infoDosen(P).namaDsn << endl;
            cout << "\t\t\t\t\t NIM Dosen   : " << infoDosen(P).NIK     << endl;
            cout << "\t\t\t\t\t Nama Dosen  : " << infoDosen(P).namaDsn << endl;
            cout << "\t\t\t\t\t Umur Dosen  : " << infoDosen(P).umurDsn << endl;

            while (R != NULL)
            {
                if (refDsn(R) == P)
                {
                    cout << "\t\t\t\t\t MAHASISWA YANG DIBIMBING OLEH " << infoDosen(P).namaDsn       << endl;
                    cout << "\t\t\t\t\t NIM  Mahasiswa      : "         << infoMhs(refMhs(R)).NIM     << endl;
                    cout << "\t\t\t\t\t Nama Mahasiswa      : "         << infoMhs(refMhs(R)).namaMhs << endl;
                    cout << "\t\t\t\t\t Umur Mahasiswa      : "         << infoMhs(refMhs(R)).umurMhs << endl;
                    cout << "\t\t\t\t\t Kelas Mahasiswa     : "         << infoMhs(refMhs(R)).kelas   << endl;
                }
                R = nextR(R);
            }
            P = next(P);
            R = first(LR);
            cout << endl;
        }
        ///ELEMEN TERAKHIR DARI LIST DOSEN
        cout << "\t\t\t\t\t DATA DOSEN "    << infoDosen(P).namaDsn << endl;
        cout << "\t\t\t\t\t NIM Dosen   : " << infoDosen(P).NIK     << endl;
        cout << "\t\t\t\t\t Nama Dosen  : " << infoDosen(P).namaDsn << endl;
        cout << "\t\t\t\t\t Umur Dosen  : " << infoDosen(P).umurDsn << endl;

        while (R != NULL)
        {
            if (refDsn(R) == P)
            {
                cout << "\t\t\t\t\t MAHASISWA YANG DIBIMBING OLEH " << infoDosen(P).namaDsn       << endl;
                cout << "\t\t\t\t\t NIM  Mahasiswa      : "         << infoMhs(refMhs(R)).NIM     << endl;
                cout << "\t\t\t\t\t Nama Mahasiswa      : "         << infoMhs(refMhs(R)).namaMhs << endl;
                cout << "\t\t\t\t\t Umur Mahasiswa      : "         << infoMhs(refMhs(R)).umurMhs << endl;
                cout << "\t\t\t\t\t Kelas Mahasiswa     : "         << infoMhs(refMhs(R)).kelas   << endl;
            }
            R = nextR(R);
        }
        R = first(LR);
        iMhs = 0;
        iDosen = 0;
    }
    else
    {
        P = first(LD);
        while (next(P) != first(LD) )
        {
            cout << "\t\t\t\t\t DATA DOSEN "    << infoDosen(P).namaDsn << endl;
            cout << "\t\t\t\t\t NIK Dosen   : " << infoDosen(P).NIK     << endl;
            cout << "\t\t\t\t\t Nama Dosen  : " << infoDosen(P).namaDsn << endl;
            cout << "\t\t\t\t\t Umur Dosen  : " << infoDosen(P).umurDsn << endl;
            P = next(P);
        }
        cout << "\t\t\t\t\t DATA DOSEN "    << infoDosen(P).namaDsn << endl;
        cout << "\t\t\t\t\t NIK Dosen   : " << infoDosen(P).NIK     << endl;
        cout << "\t\t\t\t\t Nama Dosen  : " << infoDosen(P).namaDsn << endl;
        cout << "\t\t\t\t\t Umur Dosen  : " << infoDosen(P).umurDsn << endl;
    }
}

void PrintInfoDosenMahasiswa(ListRelasi LR, ListDosen LD, ListMhs LM, int NIK)
{
    /** PRINT DATA MAHASISWA YANG DIBIMBING DOSEN TERTENTU **/

    adr_dosen  P, refDsn;
    adr_mhs    refMhs;
    adr_relasi R;
    int        i = 0;

    if((isEmpty(LD) == false)&&(isEmpty(LR)== false))
    {
        P = first(LD);
        R = first(LR);
        while ((next(P)!=first(LD)) && (infoDosen(P).NIK != NIK))
        {
            P = next(P);
        }
        if (infoDosen(P).NIK == NIK)
        {
            while(R!=NULL)
            {
                if (refDsn(R) == P)
                {
                    cout << "\t\t\t\t\t Mahasiswa ke- " << ++i;
                    cout << endl;
                    cout << "\t\t\t\t\t NIM   : " << infoMhs(refMhs(R)).NIM     << endl;
                    cout << "\t\t\t\t\t Nama  : " << infoMhs(refMhs(R)).namaMhs << endl;
                    cout << "\t\t\t\t\t Umur  : " << infoMhs(refMhs(R)).umurMhs << endl;
                    cout << "\t\t\t\t\t Kelas : " << infoMhs(refMhs(R)).kelas   << endl;
                    cout << "\t\t\t\t\t =================================" << endl;
                }
                R = nextR(R);
            }
        }
        else
        {
            cout << "\t\t\t\t\t Dosen tidak memiliki mahasiswa untuk dibimbing";
            P = NULL;
        }
    }
}

void PrintInfoMahasiswaDosen(ListRelasi LR, ListMhs LM, ListDosen LD, int NIM)
{
    /** PRINT DATA DOSEN YANG MEMBIMBING MAHASISWA TERTENTU **/

    adr_dosen  refDsn;
    adr_mhs    Q, refMhs;
    adr_relasi R;
    int        i = 0;

    if((isEmpty(LM) == false)&&(isEmpty(LR)== false))
    {
        Q = first(LM);
        R = first(LR);
        while ((Q != NULL) && (infoMhs(Q).NIM != NIM))
        {
            Q = next(Q);
        }
        if (Q != NULL)
        {
            while(R!=NULL)
            {
                if (refMhs(R) == Q)
                {
                    cout << "\t\t\t\t\t Dosen ke- " << ++i;
                    cout << endl;
                    cout << "\t\t\t\t\t NIK  : " << infoDosen(refDsn(R)).NIK     << endl;
                    cout << "\t\t\t\t\t Nama : " << infoDosen(refDsn(R)).namaDsn << endl;
                    cout << "\t\t\t\t\t Umur : " << infoDosen(refDsn(R)).umurDsn << endl;
                    cout << "\t\t\t\t\t =================================" << endl;
                }
                R = nextR(R);
            }
        }
        else
        {
            cout << "\t\t\t\t\t Dosen tidak memiliki mahasiswa untuk dibimbing";
        }
    }
}

void maximum_minimum(ListRelasi &LR, ListDosen &LD, ListMhs &LM)
{
    adr_dosen  P, p1, p2;
    adr_relasi R;
    int        i, max, min;

    max = 0;
    min = 1000;
    i   = 0;

    if ((isEmpty(LD) == false)&&(isEmpty(LM) == false)&&(isEmpty(LR) == false))
    {
        P = first(LD);
        R = first(LR);

        /** CARI MAXIMUM DAN MINIMUM **/
        while (next(P) != first(LD))
        {
            while (R != NULL)
            {
                if(refDsn(R) == P)
                {
                    ++i;
                }
                R = nextR(R);
            }
            if (max < i)
            {
                max = i;
                p1   = P;
            }
            if (min > i)
            {
                min = i;
                p2   = P;
            }
            P = next(P);
            R = first(LR);
            i = 0;
        }
        ///CEK ELEMEN TERAKHIR
        R = first(LR);
        while (R != NULL)
        {
            ++i;
            R = nextR(R);
        }
        if (max < i)
        {
            max = i;
            p1   = P;
        }
        if (min > i)
        {
            min = i;
            p2   = P;
        }
        if (max == min)
        {
            cout << "\t\t\t\t\t ============================================================================\n";
            cout << "\t\t\t\t\t Berikut data dosen yang memiliki jumlah Mahasiswa bimbingan paling banyak dan paling sedikit: "<<endl;
            cout << "\t\t\t\t\t " << infoDosen(p1).NIK << endl;
            cout << "\t\t\t\t\t " << infoDosen(p1).namaDsn << endl;
            cout << "\t\t\t\t\t " << infoDosen(p1).umurDsn << endl;
        }
        else
        {
            cout << "\t\t\t\t\t ============================================================================\n";
            cout << "\t\t\t\t\t Berikut data dosen yang memiliki jumlah Mahasiswa bimbingan paling banyak: "<<endl;
            cout << "\t\t\t\t\t " << infoDosen(p1).NIK << endl;
            cout << "\t\t\t\t\t " << infoDosen(p1).namaDsn << endl;
            cout << "\t\t\t\t\t " << infoDosen(p1).umurDsn << endl;
            cout << "\t\t\t\t\t ============================================================================\n";
            cout << "\t\t\t\t\t Berikut data dosen yang memiliki jumlah Mahasiswa bimbingan paling sedikit: "<<endl;
            cout << "\t\t\t\t\t " << infoDosen(p2).NIK << endl;
            cout << "\t\t\t\t\t " << infoDosen(p2).namaDsn << endl;
            cout << "\t\t\t\t\t " << infoDosen(p2).umurDsn << endl;
        }
    }
}
