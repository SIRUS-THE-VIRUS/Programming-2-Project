#include <stdio.h>
#include <stdlib.h>
#define MAX_ART 20
#define BOOK_MAX 15

typedef union{
    float localRate;
    float foreignRate;
}Rate;

typedef struct{
    int day;
    int month;
    int year;
}Date;

typedef struct{
    int bookingNum;
    char type;
    Date theDate;
    Rate rate;
    char hotel[20];
    char location[20];
    char guide[20];
    char flightInfo[20];
}Bookings;

typedef struct{
    int fAccountNum;
    float balance;
    char majorCurCharity[20];
}Foundation;


typedef struct{
    char stageName[20];
    char realName[20];
    int accountNum;
    float accountBal;
    long int telephone;
    float earningPerYr;
    Bookings booking[BOOK_MAX];
    Foundation foundation;
}Artists;
Artists artist[MAX_ART];

enum response {TRUE,FALSE};
FILE *unamePtr;
FILE *PnamePtr;
int whoami;
int acount=0;
int bcount[MAX_ART];
int main()
{
    char uname[20];
    char pname[20];
    int choice;
    int login_attempts = 0;
    printf("1)Manager\n2)Clerk\n=======>>>");
    scanf("%d",&whoami);
    while(login_attempts!=3){
    printf("Enter the Username: ");
    scanf("%s",uname);
    printf("Enter the Password: ");
    scanf("%s",pname);
    fflush(stdin);
    if(validate_login(uname,pname,whoami)== 0){
        while(choice != 7){
        choice = full_menu();
        run(choice);
        }
        exit(TRUE);
    }else{
        login_attempts+=1;
        if(login_attempts==3){
            printf("You tried to login too many times\nConnection terminated\n");
            exit(TRUE);
        }
    }
    }

    return 0;
}
int validate_login(char *uname, char *passwd,int a){
    char uname2[20];
    char pname2[20];
    if(a==1){
        PnamePtr = fopen("Manager_Password.bin","rb");
    }else if(a==2){
        PnamePtr = fopen("Clerk_Password.bin","rb");
    }
    while(!feof(PnamePtr)){
        fscanf(PnamePtr,"%s %s",uname2,pname2);
        if(strcmp(uname2,uname)==0 && strcmp(pname2,passwd)==0){
                printf("hi\n");
            return TRUE;
        }else{
            printf("no\n");
            return FALSE;
        }
    }
};
int full_menu(){
    int a;
    system("cls");
    printf(" \n");printf(" ");printf(" ");printf(" ");printf(" ");printf(" ");printf(" ");printf(" ");
    printf("\t\t\t\t    Company\n");
    printf("\t\t\tArtist Management System\n");
    printf(" ");
    printf("\t\t\t+=============================+\n");
    printf("\t\t\t|                             |\n");
    printf("\t\t\t|   1. Add   Artist           |\n");
    printf("\t\t\t|   2. Update  Artist         |\n");
    printf("\t\t\t|   3. Display All Artist     |\n");
    if(whoami == 1)
        printf("\t\t\t|   4. Delete Artist          |\n");
    printf("\t\t\t|   5. Search Artist          |\n");
    printf("\t\t\t|   6. Generate Report        |\n");
    printf("\t\t\t|   7. Exit                   |\n");
    printf("\t\t\t|                             |\n");
    printf("\t\t\t+=============================+\n");
    printf("\t\t\t|   Select an Option [1..7]   |\n");
    printf("\t\t\t+=============================+\n");
    printf("=====================>>> ");
    scanf("%d",&a);
    return a;
};


void run(int a){
    switch(a){
    case 1:
        add_artist();
        break;
    case 2:
        update_artist();
        break;
    case 3:
        display_artist();
        break;
    case 4:
        delete_artist();
        break;
    case 5:
        search_artist();
        break;
    case 6:
        generate_report();
        break;
    case 7:
        break;

    }

};

void add_artist(){
    int a;
    int t;
    printf("*****ARTISTS INFORMATION*****\n");
    printf("Enter Artist's StageName:");
    scanf(" %[^\n]s",artist[acount].stageName);
    printf("Enter Artist's RealName: ");
    scanf(" %[^\n]s",artist[acount].realName);
    printf("Enter Artist's accountNum: ");
    scanf("%d",&artist[acount].accountNum);
    printf("Enter Artist's accountBal: ");
    scanf("%f",&artist[acount].accountBal);
    printf("Enter Artist's telephone #: ");
    scanf("%ld",&artist[acount].telephone);
    //printf("Enter Artist's earningPerYr: $"); going to calculate this from the rate of all bookings
    //scanf("%f",&artist[acount].earningPerYr);
    printf("*****ARTIST'S BOOKING INFO*****\n");
    printf("How many bookings for this artist: ");
    scanf("%d",&a);
    if(bcount[acount]< 15){
    while(bcount[acount]<a){
        printf("Enter Artist's bookingNum:");
        scanf("%d",&artist[acount].booking[bcount[acount]].bookingNum);
        printf("Enter Artist's booking type (O)versea or (L)ocal: ");
        scanf(" %c",&artist[acount].booking[bcount[acount]].type);
        int date = FALSE;
        while(date == FALSE && bcount[acount]>=0 ){
        printf("Enter Artist's booking Date (Day month year): ");
        scanf("%d %d %d",&artist[acount].booking[bcount[acount]].theDate.day,&artist[acount].booking[bcount[acount]].theDate.month,&artist[acount].booking[bcount[acount]].theDate.year);
        for(t=0;t<bcount[acount];t++){
            if(artist[acount].booking[bcount[acount]].theDate.day == artist[acount].booking[t].theDate.day &&
               artist[acount].booking[bcount[acount]].theDate.month == artist[acount].booking[t].theDate.month &&
               artist[acount].booking[bcount[acount]].theDate.year == artist[acount].booking[t].theDate.year){
               printf("That date is already taken");
               date = FALSE;
               }else if(artist[acount].booking[bcount[acount]].theDate.day == (artist[acount].booking[t].theDate.day - 2) ||
               artist[acount].booking[bcount[acount]].theDate.day == (artist[acount].booking[t].theDate.day - 1) ||
               artist[acount].booking[bcount[acount]].theDate.day == (artist[acount].booking[t].theDate.day + 1) ||
               artist[acount].booking[bcount[acount]].theDate.day == (artist[acount].booking[t].theDate.day + 2) &&
               artist[acount].booking[bcount[acount]].theDate.month == artist[acount].booking[t].theDate.month &&
               artist[acount].booking[bcount[acount]].theDate.year == artist[acount].booking[t].theDate.year){
               printf("That date is too close to another booking date");
               date = FALSE;
               }else{date = TRUE;break;}

        }
        if (bcount[acount]==0)
            date = TRUE;
        }
        printf("Enter Artist's booking hotel: ");
        scanf(" %[^\n]s",artist[acount].booking[bcount[acount]].hotel);
        printf("Enter Artist's booking location(address): ");
        scanf(" %[^\n]s",artist[acount].booking[bcount[acount]].location);
        printf("Enter Artist's booking guide: ");
        scanf(" %[^\n]s",artist[acount].booking[bcount[acount]].guide);
        printf("Enter Artist's Booking flightInfo: ");
        scanf(" %[^\n]s",artist[acount].booking[bcount[acount]].flightInfo);
        if(artist[acount].booking[bcount[acount]].type == 'L'){
            printf("Enter Artist's Booking localRate (enter zero for voluntary): ");
            scanf("%f",&artist[acount].booking[bcount[acount]].rate.localRate);
            artist[acount].earningPerYr+=artist[acount].booking[bcount[acount]].rate.localRate;
        }else if(artist[acount].booking[bcount[acount]].type == 'O'){
            printf("Enter Artist's Booking foreignRate(including hotel,plane fair for all members): ");
            scanf("%f",&artist[acount].booking[bcount[acount]].rate.foreignRate);
            artist[acount].earningPerYr+=artist[acount].booking[bcount[acount]].rate.foreignRate;
        }
        bcount[acount]+=1;
    }
    }else{
        printf("This artist can only have a maximum of 15 bookings\n");
    }
    printf("*****ARTIST'S FOUNDATION INFO*****\n");
    printf("Enter Artist's Foundation Account Number: ");
    scanf("%d",&artist[acount].foundation.fAccountNum);
    printf("Enter Artist's Foundation Account Balance: ");
    scanf("%f",&artist[acount].foundation.balance);
    printf("Enter Artist's Foundation majorCurCharity: ");
    scanf("%d",&artist[acount].foundation.majorCurCharity);
    acount+=1;
};
void update_artist(){


};

void display_artist(){

};

void delete_artist(){

};
void search_artist(){

};
void generate_report(){


};



