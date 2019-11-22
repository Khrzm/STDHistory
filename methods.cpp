#include "header.h"

adrWebsite allocateWebsite(string URL){ //allokasi elmtWebsite
    adrWebsite W=new elmtWebsite;
    URL(W)=URL;
    prev(W)=NULL;
    next(W)=NULL;
    firstAkses(W)=NULL;
    return W;
}

adrAkses allocateAkses(){ //alokasi elmtAkses
    adrAkses A=new elmtAkses;
    next(A)=NULL;
    waktu(A)=NULL;
    return A;
}

adrDate allocateDate(Waktu waktu){ //alokasi elmtDate
    adrDate D=new elmtDate;
    waktu(D)=waktu;
    prev(D)=NULL;
    next(D)=NULL;
    return D;
}

adrBookmark allocateBookmark(adrWebsite URL){//alokasi elmtBookmark
    adrBookmark B=new elmtBookmark;
    adrURL(B)=URL;
    prev(B)=NULL;
    next(B)=NULL;
    return B;
}

void insertURL(listWebsite &LWebsite, string URL){//insert first elmtWebsite
    if ( first(LWebsite)==NULL ){
        first(LWebsite)=allocateWebsite(URL);
    }else{
        adrWebsite W=allocateWebsite(URL);
        next(W)=first(LWebsite);
        first(LWebsite)=W;
    }
}

adrWebsite getWebsite(listWebsite LWebsite, string URL){ //mge-return elmtWebsite, dengan mencocokan string dengan info/URL dari elmtWebsite di list website
    adrWebsite cek=first(LWebsite);
    while ( (URL(cek)!=URL) && (cek!=NULL)) {//sini
        cek=next(cek);
    }
    return cek;
}

void addBookmark(listBookmark &LBookmark, adrWebsite URL){ //insertfirst bookmark di list bookmark
    adrBookmark B=allocateBookmark(URL);
    if(first(LBookmark)==NULL){
        first(LBookmark)=B;
    }else{
        next(B)=first(LBookmark);
        first(LBookmark)=B;
    }
}

adrBookmark getBookmark(listBookmark LBookmark, string URLS){//return alamat/address alamat elmtBookmark dengan mencocokan string URL yang dicari
    adrBookmark B=first(LBookmark);
    while ( (B!=NULL) && (URL(adrURL(B))!=URLS) ){
            B=next(B);
    }
    return B;
}

void openTab( listWebsite &LWebsite,listBookmark &LBookmark ){
    //INPUT URL
    string URL;
    cout<<"http://";
    cin>>URL;
    insertURL(LWebsite, URL);

    adrBookmark B;
    char key;
    do{
        //WEBSITE DIBUKA
        cout<<"*anda sedang membuka website "<<URL<<"*\n\n";
        cout<<"Tekan '1' untuk save URL ke bookmark\n";
        cout<<"Tekan '2' untuk membuka website lain";
        cout<<"\n\n"<<"Tekan '0' untuk exit dari tab\n\n";
        key=_getch();
        switch (key){
            case '1': //MENAMBAHKAN BOOKMARK ke list
                system("cls");
                B=getBookmark(LBookmark,URL);
                if (B==NULL){
                    addBookmark(LBookmark, getWebsite(LWebsite,URL));
                    cout<<"URL have been added\n";
                }else{
                    cout<<"It's already exist\n" ;
                }
                system("PAUSE");
                system("cls");
                break;
            case '2': //OPEN TAB/WEBSITE BARU
                system("cls");
                openTab(LWebsite,LBookmark);
                break;
            case '0': //KEMBALI KE PROGRAM UTAMA
                system("cls");
                break;
            default:
                system("cls");
                break;
    }
      }while(key!='0');
    cout<<"exit...\n";
    system("PAUSE");
    system("cls");
}

void openBookmark(listBookmark LBookmark){//menampilkan website yang dibookmark
    adrBookmark cek = first(LBookmark);
    if(cek==NULL){
        cout<<"Tidak ada website yang di-bookmark\n";
        system("PAUSE");
        system("cls");
    }else{
        cout<<"List bookmark : \n";
        do{
            cout<<URL(adrURL(cek))<<endl;
            cek=next(cek);
        }while(cek!=NULL);
    }
}

void viewHistory(listWebsite LWebsite){ //belum jadi
    char key=' ';
    do{
        cout<<"History: \n";
        cout<<"Sort by time (Press T)\n";
        cout<<"Sort by the frequency the URL openned (Press F)\n";
        cout<<"Ketik 0 untuk mengakhiri prosedur\n";
        key=_getch();
        cout<<key;
        system("cls");
        switch (key){
            case 'T':
                    getch();

                    break;
            case 'F':
                    getch();
                    break;
            case '0':
                    break;
        }
        system("cls");
    }while(key!='0');

}

void HistoryBySite(){ // blm jadi

};
