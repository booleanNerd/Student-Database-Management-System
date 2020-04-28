#include <stdio.h>
#include <conio.h>
#include <string.h>

struct Stud {
    char dno[50], clas[50], name[50], father[50], mother[50], email[50], mobileNo[50], homeNo[50], are[50], place[50], district[50];
} addStudS, searchStudS, updateStudS, deleteStudS, viewAllStudS, viewSingleStudS, roughStudS;

    // Header for the project
    void header() {
        printf("\n\n \t\t St. Joseph's College Student Database Management System \n");
        printf("\t\t\t\t MCA 2018-2021 \n");
        printf("\t\t\t   Developed by GANESHKUMAR \n\n\n");
    }

    // Footer for the project
    void footer() {
        system("cls");
        printf("\n \n Bi !!!!!!!!!!!!!!!!!!! \n \n");
        exit(0);
    }

    // Add student Record
    void addStud() {
        system("cls");
        header();
        char dnoCheck[50], dnoUpr[50];
        int flag = 0, cmp;
        FILE *f;
        E:
        printf("\nEnter Student DNO:         ");
        scanf("%s", addStudS.dno);
        f = fopen("sdm.txt", "a+");
        while (fscanf(f, "%s %s %s %s %s %s %s %s %s %s %s", dnoCheck, addStudS.clas, addStudS.name, addStudS.father, addStudS.mother, addStudS.email, addStudS.mobileNo, addStudS.homeNo, addStudS.are, addStudS.place, addStudS.district) != EOF) {
            cmp = strcmp(dnoCheck, strupr(addStudS.dno));
            if (cmp == 0){
                printf("Dno Already Found In Database !!!!!!!!!!!!! \n");
                goto E;
            } else {
                //fprintf(f, "%s %s %s %s %s %s %s \n", addStudS.dno, addStudS.clas, addStudS.name, addStudS.father, addStudS.mother, addStudS.email, addStudS.mobileNo);
                //printf("else");
            }
        }
        if(flag == 1) {
            printf("exist");
        }


        printf("Enter Student Class:       ");
        scanf("%s", addStudS.clas);
        printf("Enter Student Name:        ");
        scanf("%s", addStudS.name);
        printf("Enter Student Father Name: ");
        scanf("%s", addStudS.father);
        printf("Enter Student Mother Name: ");
        scanf("%s", addStudS.mother);
        printf("Enter Student Email:       ");
        scanf("%s", addStudS.email);
        printf("Enter Student Mobile No:   ");
        scanf("%s", addStudS.mobileNo);
        printf("Enter Student Home No:     ");
        scanf("%s", addStudS.homeNo);
        printf("Enter Student Area:        ");
        scanf("%s", addStudS.are);
        printf("Enter Student Place:       ");
        scanf("%s", addStudS.place);
        printf("Enter Student District:    ");
        scanf("%s", addStudS.district);

        //addStudS.dno = strupr(addStudS.dno);

        fprintf(f, "%s %s %s %s %s %s %s %s %s %s %s\n", strupr(addStudS.dno), addStudS.clas, addStudS.name, addStudS.father, addStudS.mother, addStudS.email, addStudS.mobileNo, addStudS.homeNo, addStudS.are, addStudS.place, addStudS.district);
        fclose(f);

        int s;
    printf("\nEnter 1 to go Main Menu \n");
    printf("Enter 2 to go Add Next Record \n");
    printf("Enter 3 to go Exit \n");
    RE:
    scanf("%d", &s);
    switch (s) {
    case 1:
        main();
        break;
    case 2:
        addStud();
        break;
    case 3:
        footer();
        break;

    default:
        printf("You Choice Not In The List \n");
        goto RE;
    }

    }

void searchStud() {
    system("cls");
    header();
    char search[50];
    int cmp, flag = 0;
    FILE *f;
    printf("Enter the Dno you want to search: ");
    scanf("%s", search);
    f = fopen("sdm.txt", "r");
    while (fscanf(f, "%s %s %s %s %s %s %s %s %s %s %s", searchStudS.dno, searchStudS.clas, searchStudS.name, searchStudS.father, searchStudS.mother, searchStudS.email, searchStudS.mobileNo, searchStudS.homeNo, searchStudS.are, searchStudS.place, searchStudS.district) != EOF) {
        cmp = strcmp(strupr(search), searchStudS.dno);
        if (cmp == 0) {
            printf("\nRecord Found In Database \n\n");
            printf("Student Dno:           %s \n", searchStudS.dno);
            printf("Student class:         %s \n", searchStudS.clas);
            printf("Student Name:          %s \n", searchStudS.name);
            printf("Student Father's Name: %s \n", searchStudS.father);
            printf("Student Mother's Name: %s \n", searchStudS.mother);
            printf("Student Email:         %s \n", searchStudS.email);
            printf("Student Mobile No:     %s \n", searchStudS.mobileNo);
            printf("Student Home No:       %s \n", searchStudS.homeNo);
            printf("Student Area:          %s \n", searchStudS.are);
            printf("Student Place:         %s \n", searchStudS.place);
            printf("Student District:      %s \n", searchStudS.district);
            flag = 1;
        } else {
            //printf("Record Not Found In Database");

        }
    }
    if (flag == 0) {
        printf("\nRecord Not Found In Database \n");
    }

    int s;
    printf("\nEnter 1 to go Main Menu \n");
    printf("Enter 2 to go Search Next Record \n");
    printf("Enter 3 to go Exit \n");
    RE:
    scanf("%d", &s);
    switch (s) {
    case 1:
        main();
        break;
    case 2:
        searchStud();
        break;
    case 3:
        footer();
        break;

    default:
        printf("You Choice Not In The List \n");
        goto RE;
    }
}

void updateStud() {
    system("cls");
    header();
    FILE *f, *fp;
    char checkDno[50];
    int cmp , flag = 0;
    f = fopen("SDM.txt", "r");
    fp = fopen("UPDATESDM.txt", "a+");
    printf("Enter The Dno To Update:   ");
    scanf("%s", checkDno);
    while (fscanf(f, "%s %s %s %s %s %s %s %s %s %s %s", updateStudS.dno, updateStudS.clas, updateStudS.name, updateStudS.father, updateStudS.mother, updateStudS.email, updateStudS.mobileNo, updateStudS.homeNo, updateStudS.are, updateStudS.place, updateStudS.district) != EOF) {
        cmp = strcmp(strupr(checkDno), updateStudS.dno);
        if (cmp == 0) {
            printf("Enter Student Class:       ");
            scanf("%s", addStudS.clas);
            printf("Enter Student Name:        ");
            scanf("%s", addStudS.name);
            printf("Enter Student Father Name: ");
            scanf("%s", addStudS.father);
            printf("Enter Student Mother Name: ");
            scanf("%s", addStudS.mother);
            printf("Enter Student Email:       ");
            scanf("%s", addStudS.email);
            printf("Enter Student Mobile No:   ");
            scanf("%s", addStudS.mobileNo);
            printf("Enter Student Home No:     ");
            scanf("%s", addStudS.homeNo);
            printf("Enter Student Area:        ");
            scanf("%s", addStudS.are);
            printf("Enter Student Place:       ");
            scanf("%s", addStudS.place);
            printf("Enter Student District:    ");
            scanf("%s", addStudS.district);
            fprintf(fp, "%s %s %s %s %s %s %s %s %s %s %s \n", strupr(updateStudS.dno), addStudS.clas, addStudS.name, addStudS.father, addStudS.mother, addStudS.email, addStudS.mobileNo, addStudS.homeNo, addStudS.are, addStudS.place, addStudS.district);
            flag = 1;
        } else {
            fprintf(fp, "%s %s %s %s %s %s %s %s %s %s %s \n", updateStudS.dno, updateStudS.clas, updateStudS.name, updateStudS.father, updateStudS.mother, updateStudS.email, updateStudS.mobileNo, updateStudS.homeNo, updateStudS.are, updateStudS.place, updateStudS.district);
        }
    }
    if (flag == 0) {
        printf("\nRecord Not Found !!!!!!!!!!!\n");
    } else {
        printf("\nRecord Successfully Updated !!!!!!!!!!!\n");
    }
    fclose(f);
    fclose(fp);

    f = fopen("SDM.txt", "w");
    fclose(f);

    f = fopen("SDM.txt", "a+");
    fp = fopen("UPDATESDM.txt", "r");

    while (fscanf(fp, "%s %s %s %s %s %s %s %s %s %s %s", roughStudS.dno, roughStudS.clas, roughStudS.name, roughStudS.father, roughStudS.mother, roughStudS.email, roughStudS.mobileNo, roughStudS.homeNo, roughStudS.are, roughStudS.place, roughStudS.district) != EOF) {
        fprintf(f, "%s %s %s %s %s %s %s %s %s %s %s \n", strupr(roughStudS.dno), roughStudS.clas, roughStudS.name, roughStudS.father, roughStudS.mother, roughStudS.email, roughStudS.mobileNo, roughStudS.homeNo, roughStudS.are, roughStudS.place, roughStudS.district);
    }
    fclose(f);
    fclose(fp);

    fp = fopen("UPDATESDM.txt", "w");
    fclose(fp);

    int s;
    printf("\nEnter 1 to go Main Menu \n");
    printf("Enter 2 to go Update Next Record \n");
    printf("Enter 3 to go Exit \n");
    RE:
    scanf("%d", &s);
    switch (s) {
    case 1:
        main();
        break;
    case 2:
        updateStud();
        break;
    case 3:
        footer();
        break;

    default:
        printf("You Choice Not In The List \n");
        goto RE;
    }
}

void deleteStud() {
    system("cls");
    header();
    FILE *f, *fp;
    int flag = 0;
    char checkDno[50];
    int cmp;
    f = fopen("SDM.txt", "r");
    fp = fopen("UPDATESDM.txt", "a+");
    printf("Enter The Dno To Delete: ");
    scanf("%s", checkDno);
    while (fscanf(f, "%s %s %s %s %s %s %s %s %s %s %s", deleteStudS.dno, deleteStudS.clas, deleteStudS.name, deleteStudS.father, deleteStudS.mother, deleteStudS.email, deleteStudS.mobileNo, deleteStudS.homeNo, deleteStudS.are, deleteStudS.place, deleteStudS.district) != EOF) {
        cmp = strcmp(strupr(checkDno), deleteStudS.dno);
        if (cmp == 0) {
            flag = 1;
        } else {
            fprintf(fp, "%s %s %s %s %s %s %s %s %s %s %s \n", deleteStudS.dno, deleteStudS.clas, deleteStudS.name, deleteStudS.father, deleteStudS.mother, deleteStudS.email, deleteStudS.mobileNo, deleteStudS.homeNo, deleteStudS.are, deleteStudS.place, deleteStudS.district);
        }
    }
    if (flag == 1) {
        printf("\nRecord Delete !!!!!!!! \n");
    } else {
        printf("\nRecord Not Found !!!!!!!!! \n");
    }
    fclose(f);
    fclose(fp);

    f = fopen("SDM.txt", "w");
    fclose(f);

    f = fopen("SDM.txt", "a+");
    fp = fopen("UPDATESDM.txt", "r");

    while (fscanf(fp, "%s %s %s %s %s %s %s %s %s %s %s", roughStudS.dno, roughStudS.clas, roughStudS.name, roughStudS.father, roughStudS.mother, roughStudS.email, roughStudS.mobileNo, roughStudS.homeNo, roughStudS.are, roughStudS.place, roughStudS.district) != EOF) {
        fprintf(f, "%s %s %s %s %s %s %s %s %s %s %s \n", strupr(roughStudS.dno), roughStudS.clas, roughStudS.name, roughStudS.father, roughStudS.mother, roughStudS.email, roughStudS.mobileNo, roughStudS.homeNo, roughStudS.are, roughStudS.place, roughStudS.district);
    }
    fclose(f);
    fclose(fp);

    fp = fopen("UPDATESDM.txt", "w");
    fclose(fp);

    int s;
    printf("\nEnter 1 to go Main Menu \n");
    printf("Enter 2 to go Delete Next Record \n");
    printf("Enter 3 to go Exit \n");
    RE:
    scanf("%d", &s);
    switch (s) {
    case 1:
        main();
        break;
    case 2:
        deleteStud();
        break;
    case 3:
        footer();
        break;

    default:
        printf("You Choice Not In The List \n");
        goto RE;
    }
}

void main() {
    system("cls");
    int choice;
    header();
    printf("\t\t\t 1. Add New Student Record \n");
    printf("\t\t\t 2. Search Student Record \n");
    printf("\t\t\t 3. Update Student Record \n");
    printf("\t\t\t 4. Delete Student Record \n");
    printf("\t\t\t 5. Exit \n");
    //printf("\t\t\t 5. View All Student Record \n");
    //printf("\t\t\t 6. View Single Student Record \n");
    E:
    printf("Enter the choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1 :
        addStud();
        break;
    case 2 :
        searchStud();
        break;
    case 3 :
        updateStud();
        break;
    case 4 :
        deleteStud();
        break;
    case 5 :
        footer();
        break;
    /*case 6 :
        //viewSingleStud();
        break; */
    default :
        printf("You choice is not in the menu \n");
        goto E;
    }
    getch();
}
