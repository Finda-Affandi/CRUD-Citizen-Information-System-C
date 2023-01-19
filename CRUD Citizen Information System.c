#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
// Variable Declaration
 
struct date {
    int d;
    char m[30];
    int y;
};
 
 
struct data {
    char nik[30];
    char nama[30];
    char marga[30];
    struct date tl;
    char hp[30];
    char email[30];
} pub;


struct get {
    int nik;
    char nama[100];
    char marga[100];
    char tl[100];
    char hp[100];
    char email[100];
} dataSort[100];


struct curr {
    int nik;
    char nama[100];
    char marga[100];
    char tl[100];
    char hp[100];
    char email[100];
} key;
 
 
char line[200], temp[200][10][200], check[200][10][200],  srch[100];
char delim[] = ";";
int compare[100], cmpr, select, intSrch, a, b, i, j, x, y, z;
 
void add() {
 
    //ambil data
    FILE *ck;
    ck = fopen("database.txt","r");
    a = 0;
    b = 0;
 
   
    x = 0;
    while (fgets(line, sizeof(line), ck) != NULL) {
        char *token = strtok(line, delim);
        y = 0;
        while (token != NULL) {
            strcpy(check[x][y], token);
            token = strtok(NULL, delim);
            b++;
            y++;
        }
        a++;
        x++;
    }
    fclose(ck);
 
 
    //Inputan
    printf("\tMenu Tambah Data Warga\n");
    printf("========================================");
    printf("\nNIK\t\t: ");
    scanf("%s", &pub.nik);
 
    //crosscheck data
    for (i = 0; i < a; i++) {
        compare[i] = strcmp(pub.nik, check[i][0]);
    }
 
    i = 0;
    while (i < a){
        if (compare[i] == 0) {
            printf("\nNIK %s sudah ada di dalam database!\n\n", pub.nik);
            system("pause");
            system("cls");
            add();
        }
        i++;
    }
       
    printf("Nama\t\t: ");
    scanf("%s", &pub.nama);
    printf("Marga\t\t: ");
    scanf("%s", &pub.marga);
    printf("Tanggal Lahir\t: ");
    scanf("%i", &pub.tl.d);
    scanf("%s", &pub.tl.m);
    scanf("%i", &pub.tl.y);
    printf("No HP\t\t: ");
    scanf("%s", &pub.hp);
    printf("Email\t\t: ");
    scanf("%s", &pub.email);
 
 
    //Simpan Data
    FILE *op;
    op = fopen("database.txt", "a+");
    fputs(pub.nik, op);
    fputs(";",op);
    fputs(pub.nama, op);
    fputs(";",op);
    fputs(pub.marga, op);
    fputs(";",op);
    fprintf(op, "%i", pub.tl.d);
    fputs(" ",op);
    fputs(pub.tl.m, op);
    fputs(" ",op);
    fprintf(op, "%i", pub.tl.y);
    fputs(";",op);
    fputs(pub.hp, op);
    fputs(";",op);
    fputs(pub.email, op);
    fputs("\n", op);
    fclose(op);
 
    printf("\n\nData berhasil ditambahkan!\n");
    system("pause>nul | echo Klik Enter untuk kembali ke menu utama");
    system("cls");
    main();
}
 
void see() {
    printf("\t\t\t\t\t\t== Daftar Penduduk Desa Konoha ==\n");
    //Membaca file
    FILE *op;
    op = fopen("database.txt","r");
    a = 0;
    b = 0;
 
   
    x = 0;
    while (fgets(line, sizeof(line), op) != NULL) {
        char *token = strtok(line, delim);
        y = 0;
        while (token != NULL) {
            strcpy(temp[x][y], token);
            token = strtok(NULL, delim);
            b++;
            y++;
        }
        a++;
        x++;
    }
    fclose(op);
 
    //Menampilkan Data
    printf("===================================================================================================================================\n");
    printf(" No\tNIK\t\tNama\t\tMarga\t\tTanggal Lahir\t\tNo Handphone\t\tEmail\n");
    printf("===================================================================================================================================\n");
    for (x = 0; x < a; x++) {
        printf(" %d", x+1);
        printf("\t%s\t%s\t\t%s\t\t%s\t\t%s\t\t%s", temp[x][0], temp[x][1], temp[x][2], temp[x][3], temp[x][4], temp[x][5]);
    }
 
    printf("\n\n");
    system("pause>nul | echo Klik Enter untuk kembali ke menu utama");
    system("cls");
    main();
}


void sortByNikDesc() {
    printf("\t\t\t\t\t\t== Urutkan Data Penduduk Desa Konoha ==\n");
    printf("\nUrutkan Data > Berdasarkan NIK > Descending\n");
    FILE *op;
    op = fopen("database.txt","r");
    a = 0;
    b = 0;
 
    x = 0;
    while (fgets(line, sizeof(line), op) != NULL) {
        char *token = strtok(line, delim);
        y = 0;
        while (token != NULL) {
            strcpy(temp[x][y], token);
            token = strtok(NULL, delim);
            b++;
            y++;
        }
        a++;
        x++;
    }
    fclose(op);


    for (i = 0; i < a; i++) {
        dataSort[i].nik = atoi(temp[i][0]);
        strcpy(dataSort[i].nama, temp[i][1]);
        strcpy(dataSort[i].marga, temp[i][2]);
        strcpy(dataSort[i].tl, temp[i][3]);
        strcpy(dataSort[i].hp, temp[i][4]);
        strcpy(dataSort[i].email, temp[i][5]);
    }


    for (i = 1; i < a; i++) {
        key.nik = dataSort[i].nik;
        strcpy(key.nama, dataSort[i].nama);
        strcpy(key.marga, dataSort[i].marga);
        strcpy(key.tl, dataSort[i].tl);
        strcpy(key.hp, dataSort[i].hp);
        strcpy(key.email, dataSort[i].email);
        j = i - 1;
        while (j >= 0 && dataSort[j].nik > key.nik) {
            dataSort[j + 1].nik = dataSort[j].nik;
            strcpy(dataSort[j + 1].nama, dataSort[j].nama);
            strcpy(dataSort[j + 1].marga, dataSort[j].marga);
            strcpy(dataSort[j + 1].tl, dataSort[j].tl);
            strcpy(dataSort[j + 1].hp, dataSort[j].hp);
            strcpy(dataSort[j + 1].email, dataSort[j].email);
            j = j - 1;
        }
        dataSort[j + 1].nik = key.nik;
        strcpy(dataSort[j + 1].nama, key.nama);
        strcpy(dataSort[j + 1].marga, key.marga);
        strcpy(dataSort[j + 1].tl, key.tl);
        strcpy(dataSort[j + 1].hp, key.hp);
        strcpy(dataSort[j + 1].email, key.email);
    }


    printf("===================================================================================================================================\n");
    printf(" No\tNIK\t\tNama\t\tMarga\t\tTanggal Lahir\t\tNo Handphone\t\tEmail\n");
    printf("===================================================================================================================================\n");
    for (i = 0; i < a; i++) {
        printf(" %d", i + 1);
        printf("\t%d\t%s\t\t%s\t\t%s\t\t%s\t\t%s", dataSort[i].nik, dataSort[i].nama, dataSort[i].marga, dataSort[i].tl, dataSort[i].hp, dataSort[i].email);
    }


    printf("\n\n");
    system("pause>nul | echo Klik Enter untuk kembali ke menu utama");
    system("cls");
    main();
}


void sortByNikAsc() {
    printf("\t\t\t\t\t\t== Urutkan Data Penduduk Desa Konoha ==\n");
    printf("\nUrutkan Data > Berdasarkan NIK > Ascending\n");
    FILE *op;
    op = fopen("database.txt","r");
    a = 0;
    b = 0;
 
    x = 0;
    while (fgets(line, sizeof(line), op) != NULL) {
        char *token = strtok(line, delim);
        y = 0;
        while (token != NULL) {
            strcpy(temp[x][y], token);
            token = strtok(NULL, delim);
            b++;
            y++;
        }
        a++;
        x++;
    }
    fclose(op);


    for (i = 0; i < a; i++) {
        dataSort[i].nik = atoi(temp[i][0]);
        strcpy(dataSort[i].nama, temp[i][1]);
        strcpy(dataSort[i].marga, temp[i][2]);
        strcpy(dataSort[i].tl, temp[i][3]);
        strcpy(dataSort[i].hp, temp[i][4]);
        strcpy(dataSort[i].email, temp[i][5]);
    }


    for (i = 1; i < a; i++) {
        key.nik = dataSort[i].nik;
        strcpy(key.nama, dataSort[i].nama);
        strcpy(key.marga, dataSort[i].marga);
        strcpy(key.tl, dataSort[i].tl);
        strcpy(key.hp, dataSort[i].hp);
        strcpy(key.email, dataSort[i].email);
        j = i - 1;
        while (j >= 0 && dataSort[j].nik < key.nik) {
            dataSort[j + 1].nik = dataSort[j].nik;
            strcpy(dataSort[j + 1].nama, dataSort[j].nama);
            strcpy(dataSort[j + 1].marga, dataSort[j].marga);
            strcpy(dataSort[j + 1].tl, dataSort[j].tl);
            strcpy(dataSort[j + 1].hp, dataSort[j].hp);
            strcpy(dataSort[j + 1].email, dataSort[j].email);
            j = j - 1;
        }
        dataSort[j + 1].nik = key.nik;
        strcpy(dataSort[j + 1].nama, key.nama);
        strcpy(dataSort[j + 1].marga, key.marga);
        strcpy(dataSort[j + 1].tl, key.tl);
        strcpy(dataSort[j + 1].hp, key.hp);
        strcpy(dataSort[j + 1].email, key.email);
    }


    printf("===================================================================================================================================\n");
    printf(" No\tNIK\t\tNama\t\tMarga\t\tTanggal Lahir\t\tNo Handphone\t\tEmail\n");
    printf("===================================================================================================================================\n");
    for (i = 0; i < a; i++) {
        printf(" %d", i + 1);
        printf("\t%d\t%s\t\t%s\t\t%s\t\t%s\t\t%s", dataSort[i].nik, dataSort[i].nama, dataSort[i].marga, dataSort[i].tl, dataSort[i].hp, dataSort[i].email);
    }
   
    printf("\n\n");
    system("pause>nul | echo Klik Enter untuk kembali ke menu utama");
    system("cls");
    main();
}


void sortByNameDesc() {
    printf("\t\t\t\t\t\t== Urutkan Data Penduduk Desa Konoha ==\n");
    printf("\nUrutkan Data > Berdasarkan Nama > Descending\n");
    FILE *op;
    op = fopen("database.txt","r");
    a = 0;
    b = 0;
 
    x = 0;
    while (fgets(line, sizeof(line), op) != NULL) {
        char *token = strtok(line, delim);
        y = 0;
        while (token != NULL) {
            strcpy(temp[x][y], token);
            token = strtok(NULL, delim);
            b++;
            y++;
        }
        a++;
        x++;
    }
    fclose(op);


    for (i = 0; i < a; i++) {
        dataSort[i].nik = atoi(temp[i][0]);
        strcpy(dataSort[i].nama, temp[i][1]);
        strcpy(dataSort[i].marga, temp[i][2]);
        strcpy(dataSort[i].tl, temp[i][3]);
        strcpy(dataSort[i].hp, temp[i][4]);
        strcpy(dataSort[i].email, temp[i][5]);
    }


    for (i = 1; i < a; i++) {
        key.nik = dataSort[i].nik;
        strcpy(key.nama, dataSort[i].nama);
        strcpy(key.marga, dataSort[i].marga);
        strcpy(key.tl, dataSort[i].tl);
        strcpy(key.hp, dataSort[i].hp);
        strcpy(key.email, dataSort[i].email);
        j = i - 1;
        while (j >= 0 && dataSort[j].nama[0] > key.nama[0]) {
            dataSort[j + 1].nik = dataSort[j].nik;
            strcpy(dataSort[j + 1].nama, dataSort[j].nama);
            strcpy(dataSort[j + 1].marga, dataSort[j].marga);
            strcpy(dataSort[j + 1].tl, dataSort[j].tl);
            strcpy(dataSort[j + 1].hp, dataSort[j].hp);
            strcpy(dataSort[j + 1].email, dataSort[j].email);
            j = j - 1;
        }
        dataSort[j + 1].nik = key.nik;
        strcpy(dataSort[j + 1].nama, key.nama);
        strcpy(dataSort[j + 1].marga, key.marga);
        strcpy(dataSort[j + 1].tl, key.tl);
        strcpy(dataSort[j + 1].hp, key.hp);
        strcpy(dataSort[j + 1].email, key.email);
    }


    printf("===================================================================================================================================\n");
    printf(" No\tNIK\t\tNama\t\tMarga\t\tTanggal Lahir\t\tNo Handphone\t\tEmail\n");
    printf("===================================================================================================================================\n");
    for (i = 0; i < a; i++) {
        printf(" %d", i + 1);
        printf("\t%d\t%s\t\t%s\t\t%s\t\t%s\t\t%s", dataSort[i].nik, dataSort[i].nama, dataSort[i].marga, dataSort[i].tl, dataSort[i].hp, dataSort[i].email);
    }
   
    printf("\n\n");
    system("pause>nul | echo Klik Enter untuk kembali ke menu utama");
    system("cls");
    main();
}


void sortByNameAsc() {
    printf("\t\t\t\t\t\t== Urutkan Data Penduduk Desa Konoha ==\n");
    printf("\nUrutkan Data > Berdasarkan Nama > Ascending\n");
    FILE *op;
    op = fopen("database.txt","r");
    a = 0;
    b = 0;
 
    x = 0;
    while (fgets(line, sizeof(line), op) != NULL) {
        char *token = strtok(line, delim);
        y = 0;
        while (token != NULL) {
            strcpy(temp[x][y], token);
            token = strtok(NULL, delim);
            b++;
            y++;
        }
        a++;
        x++;
    }
    fclose(op);


    for (i = 0; i < a; i++) {
        dataSort[i].nik = atoi(temp[i][0]);
        strcpy(dataSort[i].nama, temp[i][1]);
        strcpy(dataSort[i].marga, temp[i][2]);
        strcpy(dataSort[i].tl, temp[i][3]);
        strcpy(dataSort[i].hp, temp[i][4]);
        strcpy(dataSort[i].email, temp[i][5]);
    }


    for (i = 1; i < a; i++) {
        key.nik = dataSort[i].nik;
        strcpy(key.nama, dataSort[i].nama);
        strcpy(key.marga, dataSort[i].marga);
        strcpy(key.tl, dataSort[i].tl);
        strcpy(key.hp, dataSort[i].hp);
        strcpy(key.email, dataSort[i].email);
        j = i - 1;
        while (j >= 0 && dataSort[j].nama[0] < key.nama[0]) {
            dataSort[j + 1].nik = dataSort[j].nik;
            strcpy(dataSort[j + 1].nama, dataSort[j].nama);
            strcpy(dataSort[j + 1].marga, dataSort[j].marga);
            strcpy(dataSort[j + 1].tl, dataSort[j].tl);
            strcpy(dataSort[j + 1].hp, dataSort[j].hp);
            strcpy(dataSort[j + 1].email, dataSort[j].email);
            j = j - 1;
        }
        dataSort[j + 1].nik = key.nik;
        strcpy(dataSort[j + 1].nama, key.nama);
        strcpy(dataSort[j + 1].marga, key.marga);
        strcpy(dataSort[j + 1].tl, key.tl);
        strcpy(dataSort[j + 1].hp, key.hp);
        strcpy(dataSort[j + 1].email, key.email);
    }


    printf("===================================================================================================================================\n");
    printf(" No\tNIK\t\tNama\t\tMarga\t\tTanggal Lahir\t\tNo Handphone\t\tEmail\n");
    printf("===================================================================================================================================\n");
    for (i = 0; i < a; i++) {
        printf(" %d", i + 1);
        printf("\t%d\t%s\t\t%s\t\t%s\t\t%s\t\t%s", dataSort[i].nik, dataSort[i].nama, dataSort[i].marga, dataSort[i].tl, dataSort[i].hp, dataSort[i].email);
    }
   
    printf("\n\n");
    system("pause>nul | echo Klik Enter untuk kembali ke menu utama");
    system("cls");
    main();
}


void sortByClanDesc() {
    printf("\t\t\t\t\t\t== Urutkan Data Penduduk Desa Konoha ==\n");
    printf("\nUrutkan Data > Berdasarkan Marga > Descending\n");
    FILE *op;
    op = fopen("database.txt","r");
    a = 0;
    b = 0;
 
    x = 0;
    while (fgets(line, sizeof(line), op) != NULL) {
        char *token = strtok(line, delim);
        y = 0;
        while (token != NULL) {
            strcpy(temp[x][y], token);
            token = strtok(NULL, delim);
            b++;
            y++;
        }
        a++;
        x++;
    }
    fclose(op);


    for (i = 0; i < a; i++) {
        dataSort[i].nik = atoi(temp[i][0]);
        strcpy(dataSort[i].nama, temp[i][1]);
        strcpy(dataSort[i].marga, temp[i][2]);
        strcpy(dataSort[i].tl, temp[i][3]);
        strcpy(dataSort[i].hp, temp[i][4]);
        strcpy(dataSort[i].email, temp[i][5]);
    }


    for (i = 1; i < a; i++) {
        key.nik = dataSort[i].nik;
        strcpy(key.nama, dataSort[i].nama);
        strcpy(key.marga, dataSort[i].marga);
        strcpy(key.tl, dataSort[i].tl);
        strcpy(key.hp, dataSort[i].hp);
        strcpy(key.email, dataSort[i].email);
        j = i - 1;
        while (j >= 0 && dataSort[j].marga[0] > key.marga[0]) {
            dataSort[j + 1].nik = dataSort[j].nik;
            strcpy(dataSort[j + 1].nama, dataSort[j].nama);
            strcpy(dataSort[j + 1].marga, dataSort[j].marga);
            strcpy(dataSort[j + 1].tl, dataSort[j].tl);
            strcpy(dataSort[j + 1].hp, dataSort[j].hp);
            strcpy(dataSort[j + 1].email, dataSort[j].email);
            j = j - 1;
        }
        dataSort[j + 1].nik = key.nik;
        strcpy(dataSort[j + 1].nama, key.nama);
        strcpy(dataSort[j + 1].marga, key.marga);
        strcpy(dataSort[j + 1].tl, key.tl);
        strcpy(dataSort[j + 1].hp, key.hp);
        strcpy(dataSort[j + 1].email, key.email);
    }


    printf("===================================================================================================================================\n");
    printf(" No\tNIK\t\tNama\t\tMarga\t\tTanggal Lahir\t\tNo Handphone\t\tEmail\n");
    printf("===================================================================================================================================\n");
    for (i = 0; i < a; i++) {
        printf(" %d", i + 1);
        printf("\t%d\t%s\t\t%s\t\t%s\t\t%s\t\t%s", dataSort[i].nik, dataSort[i].nama, dataSort[i].marga, dataSort[i].tl, dataSort[i].hp, dataSort[i].email);
    }
   
    printf("\n\n");
    system("pause>nul | echo Klik Enter untuk kembali ke menu utama");
    system("cls");
    main();
}


void sortByClanAsc() {
    printf("\t\t\t\t\t\t== Urutkan Data Penduduk Desa Konoha ==\n");
    printf("\nUrutkan Data > Berdasarkan Marga > Descending\n");
    FILE *op;
    op = fopen("database.txt","r");
    a = 0;
    b = 0;
 
    x = 0;
    while (fgets(line, sizeof(line), op) != NULL) {
        char *token = strtok(line, delim);
        y = 0;
        while (token != NULL) {
            strcpy(temp[x][y], token);
            token = strtok(NULL, delim);
            b++;
            y++;
        }
        a++;
        x++;
    }
    fclose(op);


    for (i = 0; i < a; i++) {
        dataSort[i].nik = atoi(temp[i][0]);
        strcpy(dataSort[i].nama, temp[i][1]);
        strcpy(dataSort[i].marga, temp[i][2]);
        strcpy(dataSort[i].tl, temp[i][3]);
        strcpy(dataSort[i].hp, temp[i][4]);
        strcpy(dataSort[i].email, temp[i][5]);
    }


    for (i = 1; i < a; i++) {
        key.nik = dataSort[i].nik;
        strcpy(key.nama, dataSort[i].nama);
        strcpy(key.marga, dataSort[i].marga);
        strcpy(key.tl, dataSort[i].tl);
        strcpy(key.hp, dataSort[i].hp);
        strcpy(key.email, dataSort[i].email);
        j = i - 1;
        while (j >= 0 && dataSort[j].marga[0] < key.marga[0]) {
            dataSort[j + 1].nik = dataSort[j].nik;
            strcpy(dataSort[j + 1].nama, dataSort[j].nama);
            strcpy(dataSort[j + 1].marga, dataSort[j].marga);
            strcpy(dataSort[j + 1].tl, dataSort[j].tl);
            strcpy(dataSort[j + 1].hp, dataSort[j].hp);
            strcpy(dataSort[j + 1].email, dataSort[j].email);
            j = j - 1;
        }
        dataSort[j + 1].nik = key.nik;
        strcpy(dataSort[j + 1].nama, key.nama);
        strcpy(dataSort[j + 1].marga, key.marga);
        strcpy(dataSort[j + 1].tl, key.tl);
        strcpy(dataSort[j + 1].hp, key.hp);
        strcpy(dataSort[j + 1].email, key.email);
    }


    printf("===================================================================================================================================\n");
    printf(" No\tNIK\t\tNama\t\tMarga\t\tTanggal Lahir\t\tNo Handphone\t\tEmail\n");
    printf("===================================================================================================================================\n");
    for (i = 0; i < a; i++) {
        printf(" %d", i + 1);
        printf("\t%d\t%s\t\t%s\t\t%s\t\t%s\t\t%s", dataSort[i].nik, dataSort[i].nama, dataSort[i].marga, dataSort[i].tl, dataSort[i].hp, dataSort[i].email);
    }
   
    printf("\n\n");
    system("pause>nul | echo Klik Enter untuk kembali ke menu utama");
    system("cls");
    main();
}


void ascdesc1() {
    printf("\t\t\t\t\t\t== Urutkan Data Penduduk Desa Konoha ==\n");
    printf("\nUrutkan Data > Berdasarkan NIK\n");
    printf("1. Descending\n2. Ascending\nPilihan : ");
    scanf("%d", &select);
    switch(select) {
        case 1 :
            system("cls");
            sortByNikDesc();
            break;
        case 2 :
            system("cls");
            sortByNikAsc();
            break;
    }


}


void ascdesc2() {
    printf("\t\t\t\t\t\t== Urutkan Data Penduduk Desa Konoha ==\n");
    printf("\nUrutkan Data > Berdasarkan Nama\n");
    printf("1. Descending\n2. Ascending\nPilihan : ");
    scanf("%d", &select);
    switch(select) {
        case 1 :
            system("cls");
            sortByNameDesc();
            break;
        case 2 :
            system("cls");
            sortByNameAsc();
            break;
    }


}


void ascdesc3() {
    printf("\t\t\t\t\t\t== Urutkan Data Penduduk Desa Konoha ==\n");
    printf("\nUrutkan Data > Berdasarkan Marga\n");
    printf("1. Descending\n2. Ascending\nPilihan : ");
    scanf("%d", &select);
    switch(select) {
        case 1 :
            system("cls");
            sortByClanDesc();
            break;
        case 2 :
            system("cls");
            sortByClanAsc();
            break;
    }


}


void sort() {
     printf("\t\t\t\t\t\t== Urutkan Data Penduduk Desa Konoha ==\n");
     printf("\nUrutkan Data\n");
     printf("1. Berdasarkan NIK\n2. Berdasarkan Nama\n3. Berdasarkan Marga\nPilihan : ");
     scanf("%d", &select);
     switch(select) {
        case 1 :
            system("cls");
            ascdesc1();
            break;
        case 2 :
            system("cls");
            ascdesc2();
            break;
        case 3 :
            system("cls");
            ascdesc3();
            break;
     }
}


void searchByNik() {
    FILE *op;
    op = fopen("database.txt","r");
    a = 0;
    b = 0;
 
    x = 0;
    while (fgets(line, sizeof(line), op) != NULL) {
        char *token = strtok(line, delim);
        y = 0;
        while (token != NULL) {
            strcpy(temp[x][y], token);
            token = strtok(NULL, delim);
            b++;
            y++;
        }
        a++;
        x++;
    }
    fclose(op);


    for (i = 0; i < a; i++) {
        dataSort[i].nik = atoi(temp[i][0]);
        strcpy(dataSort[i].nama, temp[i][1]);
        strcpy(dataSort[i].marga, temp[i][2]);
        strcpy(dataSort[i].tl, temp[i][3]);
        strcpy(dataSort[i].hp, temp[i][4]);
        strcpy(dataSort[i].email, temp[i][5]);
    }


    printf("\t\t\t\t\t\t== Cari Data Penduduk Desa Konoha ==\n");
    printf("\nCari data > Berdasarkan NIK\n");
    printf("==============================\n");
    printf("Masukan NIK yang di cari : ");
    scanf("%s", &srch);
    intSrch = atoi(srch);


    z = -1;


    for (i = 0; i < a; i++) {
        if (intSrch == dataSort[i].nik) {
            z = i + 1;
        }
    }


    if (z == -1) {
        printf("\nMaaf data yang anda cari tidak ditemukan di Database!");
    }
    else {
        printf("Data yang anda cari ditemukan di indeks %d pada Database", z-1);
    }


    printf("\n\n");
   
    if (z != -1) {
        system("pause>nul | echo Klik Enter untuk menampilkan data");
        printf("\n===================================================================================================================================\n");
        printf(" Idx\tNIK\t\tNama\t\tMarga\t\tTanggal Lahir\t\tNo Handphone\t\tEmail\n");
        printf("===================================================================================================================================\n");
        printf(" %d\t%d\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", z-1, dataSort[z-1].nik, dataSort[z-1].nama, dataSort[z-1].marga, dataSort[z-1].tl, dataSort[z-1].hp, dataSort[z-1].email);
    }
   
    system("pause>nul | echo Klik Enter untuk kembali ke menu utama");
    system("cls");
    main();
}


void searchByName() {
    FILE *op;
    op = fopen("database.txt","r");
    a = 0;
    b = 0;
 
    x = 0;
    while (fgets(line, sizeof(line), op) != NULL) {
        char *token = strtok(line, delim);
        y = 0;
        while (token != NULL) {
            strcpy(temp[x][y], token);
            token = strtok(NULL, delim);
            b++;
            y++;
        }
        a++;
        x++;
    }
    fclose(op);


    for (i = 0; i < a; i++) {
        dataSort[i].nik = atoi(temp[i][0]);
        strcpy(dataSort[i].nama, temp[i][1]);
        strcpy(dataSort[i].marga, temp[i][2]);
        strcpy(dataSort[i].tl, temp[i][3]);
        strcpy(dataSort[i].hp, temp[i][4]);
        strcpy(dataSort[i].email, temp[i][5]);
    }


    printf("\t\t\t\t\t\t== Cari Data Penduduk Desa Konoha ==\n");
    printf("\nCari data > Berdasarkan Nama\n");
    printf("==============================\n");
    printf("Masukan Nama yang di cari : ");
    scanf("%s", &srch);


    z = -1;


    for (i = 0; i < a; i++) {
        cmpr = strcmp(srch, dataSort[i].nama);
        if (cmpr == 0) {
            z = i + 1;
        }
    }


    if (z == -1) {
        printf("\nMaaf data yang anda cari tidak ditemukan di Database!");
    }
    else {
        printf("Data yang anda cari ditemukan di indeks %d pada Database", z-1);
    }


    printf("\n\n");
   
    if (z != -1) {
        system("pause>nul | echo Klik Enter untuk menampilkan data");
        printf("\n===================================================================================================================================\n");
        printf(" Idx\tNIK\t\tNama\t\tMarga\t\tTanggal Lahir\t\tNo Handphone\t\tEmail\n");
        printf("===================================================================================================================================\n");
        printf(" %d\t%d\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", z-1, dataSort[z-1].nik, dataSort[z-1].nama, dataSort[z-1].marga, dataSort[z-1].tl, dataSort[z-1].hp, dataSort[z-1].email);
    }
   
    system("pause>nul | echo Klik Enter untuk kembali ke menu utama");
    system("cls");
    main();
}




void search() {
    printf("\t\t\t\t\t\t== Cari Data Penduduk Desa Konoha ==\n");
    printf("\nCari data \n");
    printf("1. Berdasarkan NIK\n2. Berdasarkan Nama\nPilihan : ");
    scanf("%d", &select);
    switch (select) {
        case 1 :
            system("cls");
            searchByNik();
            break;
        case 2 :
            system("cls");
            searchByName();
            break;
    }
}


 
void mainMenu() {
    printf("Sistem Informasi Kependudukan Desa Konoha\n");
    printf("=========================================\n");
    printf("1. Tambah Data Penduduk\n2. Lihat Data Penduduk\n3. Urutkan Data\n4. Cari data\n5. Exit");
    printf("\nMasukan Pilihan : ");
    scanf("%d", &select);
}
 
void main() {
    mainMenu();
    switch (select) {
    case 1 :
        system("cls");
        add();
        break;
    case 2 :
        system("cls");
        see();
        break;
    case 3 :
        system("cls");
        sort();
        break;
    case 4 :
        system("cls");
        search();
        break;
    case 5 :
        exit(0);
    default:
        printf("Maaf inputan salah!\n");
        system("pause");
        system("cls");
        main();
        break;
    }
}
