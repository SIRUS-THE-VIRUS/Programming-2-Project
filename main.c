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
    int telephone;
    float earningPerYr;
    Bookings booking[BOOK_MAX];
    Foundation foundation;
}Artists;
Artists artist[MAX_ART];

enum response {TRUE,FALSE};
FILE *ArtistfilePtr;
FILE *LogindataPtr;
int whoami;
int acount=0;
int bcount[MAX_ART];
int pos;
int main()
{
    readRec();
    char uname[20];
    char pname[20];
    int choice;
    int login_attempts = 0;
    printf("Welcome... 1)Create account 2)Continue");
    scanf("%d",&choice);
    if(choice == 1)
        create_account();
    printf("0)Manager\n1)Clerk\n=======>>>");
    scanf("%d",&whoami);
    fflush(stdin);
    while(login_attempts!=3){
    printf("Enter the Username: ");
    gets(uname);
    printf("Enter the Password: ");
    gets(pname);
    if(validate_login(uname,pname,whoami)== TRUE){
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
    if(a==0){
        LogindataPtr = fopen("Manager_Password.bin","rb");
    }else if(a==1){
        LogindataPtr = fopen("Clerk_Password.bin","rb");
    }
    while(!feof(LogindataPtr)){
        fscanf(LogindataPtr,"%s %s",uname2,pname2);
        if(strcmp(uname2,uname)==0 && strcmp(pname2,passwd)==TRUE){
            return TRUE;
        }else{
            return FALSE;
        }
    }
};
int full_menu(){
    int a;
    fflush(stdin);
    //system("cls");
    printf(" \n");printf(" ");printf(" ");printf(" ");printf(" ");printf(" ");printf(" ");printf(" ");
    printf("\t\t\t\t    Company\n");
    printf("\t\t\tArtist Management System\n");
    printf(" ");
    printf("\t\t\t+=============================+\n");
    printf("\t\t\t|                             |\n");
    printf("\t\t\t|   1. Add   Artist           |\n");
    printf("\t\t\t|   2. Update  Artist         |\n");
    printf("\t\t\t|   3. Display All Artist     |\n");
    if(whoami == TRUE)
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
        display_all_artist();
        break;
    case 4:
        if(whoami==TRUE){
            delete_artist();
        }else if(whoami==FALSE){
            printf("You have entered a restricted area");
            system("pause");
        }
        break;
    case 5:
        search_artist();
        break;
    case 6:
        generate_report();
        break;
    case 7:
        storeRec();
        break;

    }

};

void add_artist(){
    int a;
    int t;
    int counter;
    fflush(stdin);
    printf("*****ARTISTS INFORMATION*****\n");
    printf("Enter Artist's StageName:");
    gets(artist[acount].stageName);
    printf("Enter Artist's RealName: ");
    gets(artist[acount].realName);
    printf("Enter Artist's accountNum: ");
    scanf("%d",&artist[acount].accountNum);
    printf("Enter Artist's accountBal: ");
    scanf("%f",&artist[acount].accountBal);
    printf("Enter Artist's telephone #: ");
    scanf("%ld",&artist[acount].telephone);
    printf("*****ARTIST'S BOOKING INFO*****\n");
    printf("How many bookings for this artist: ");
    scanf("%d",&a);
    if(bcount[acount]< BOOK_MAX){
    for(counter=0;counter<a;counter++){
        printf("Enter Artist's bookingNum:");
        scanf("%d",&artist[acount].booking[counter].bookingNum);
        printf("Enter Artist's booking type (O)versea or (L)ocal: ");
        scanf(" %c",&artist[acount].booking[counter].type);
        int date = FALSE;
        while(date == FALSE && bcount[acount]>=0){
        printf("Enter Artist's booking Date (Day month year): ");
        scanf("%d %d %d",&artist[acount].booking[counter].theDate.day,&artist[acount].booking[counter].theDate.month,&artist[acount].booking[counter].theDate.year);
        if(artist[acount].booking[counter].type == 'O'){
            for(t=0;t<bcount[acount];t++){
                if(artist[acount].booking[counter].theDate.day == artist[acount].booking[t].theDate.day &&
                   artist[acount].booking[counter].theDate.month == artist[acount].booking[t].theDate.month &&
                   artist[acount].booking[counter].theDate.year == artist[acount].booking[t].theDate.year){
                   printf("That date is already taken");
                   date = FALSE;
                   }else if(artist[acount].booking[counter].theDate.day == (artist[acount].booking[t].theDate.day - 2) ||
                   artist[acount].booking[counter].theDate.day == (artist[acount].booking[t].theDate.day - 1) ||
                   artist[acount].booking[counter].theDate.day == (artist[acount].booking[t].theDate.day + 1) ||
                   artist[acount].booking[counter].theDate.day == (artist[acount].booking[t].theDate.day + 2) &&
                   artist[acount].booking[counter].theDate.month == artist[acount].booking[t].theDate.month &&
                   artist[acount].booking[counter].theDate.year == artist[acount].booking[t].theDate.year){
                   printf("That date is too close to another booking date");
                   date = FALSE;
                   }else{date = TRUE;break;}

            }
        }else{date = TRUE;}
        if (counter==TRUE)
            date = TRUE;
        }
        fflush(stdin);
        printf("Enter Artist's booking hotel: ");
        gets(artist[acount].booking[counter].hotel);
        printf("Enter Artist's booking location(address): ");
        gets(artist[acount].booking[counter].location);
        printf("Enter Artist's booking guide: ");
        gets(artist[acount].booking[counter].guide);
        printf("Enter Artist's Booking flightInfo: ");
        gets(artist[acount].booking[counter].flightInfo);
        if(artist[acount].booking[counter].type == 'L'){
            printf("Enter Artist's Booking localRate (enter zero for voluntary): ");
            scanf("%f",&artist[acount].booking[counter].rate.localRate);
            artist[acount].earningPerYr+=artist[acount].booking[counter].rate.localRate;
        }else if(artist[acount].booking[counter].type == 'O'){
            printf("Enter Artist's Booking foreignRate(including hotel,plane fair for all members): ");
            scanf("%f",&artist[acount].booking[counter].rate.foreignRate);
            artist[acount].earningPerYr+=artist[acount].booking[counter].rate.foreignRate;
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
    fflush(stdin);
    gets(artist[acount].foundation.majorCurCharity);
    acount+=1;
};
int find_artist(char a[30]){
    int b;
    for(b=0;b<acount;b++)
    if(strcmp(a,artist[b].stageName)==0)
        return b;
    return -1;
};
int find_booking(int temp_bnum){
    int j;
    for(j=0;j<BOOK_MAX;j++)
        if(temp_bnum == artist[pos].booking[j].bookingNum)
            return j;
    return -1;
};

void update_artist(){
    int temp_bnum,t;
    char temp_artist[20];
    char choice2;
    fflush(stdin);
    printf("Which Artist(stage name) would you like to update: ");
    gets(temp_artist);
    pos = find_artist(temp_artist);
    if(pos == -1){
        printf("No artist found with that artist name");
    }else{
        printf("What do you want to update: (A)rtist basic info , (B)ooking info , (F)oundation information====>>> ");
        scanf(" %c",&choice2);
        if(choice2 == 'A'){
            fflush(stdin);
            printf("*****ARTISTS INFORMATION*****\n");
            printf("Enter Artist's StageName:");
            gets(artist[pos].stageName);
            printf("Enter Artist's RealName: ");
            gets(artist[pos].realName);
            printf("Enter Artist's accountNum: ");
            scanf("%d",&artist[pos].accountNum);
            printf("Enter Artist's accountBal: ");
            scanf("%f",&artist[pos].accountBal);
            printf("Enter Artist's telephone #: ");
            scanf("%d",&artist[pos].telephone);
        }else if(choice2 == 'B'){
            printf("Enter Booking number for booking you want to update: ");
            scanf("%d",&temp_bnum);
            temp_bnum = find_booking(temp_bnum);
            if(temp_bnum == -1){
                printf("That booking number does not exist:\n");
            }else if(temp_bnum< 15){
                printf("Enter Artist's booking type (O)versea or (L)ocal: ");
                scanf(" %c",&artist[pos].booking[temp_bnum].type);
                int date = FALSE;
                while(date == FALSE && bcount[pos]>=0){
                    printf("Enter Artist's booking Date (Day month year): ");
                    scanf("%d %d %d",&artist[pos].booking[temp_bnum].theDate.day,&artist[pos].booking[temp_bnum].theDate.month,&artist[pos].booking[temp_bnum].theDate.year);
                    if(artist[pos].booking[temp_bnum].type == 'O'){
                        for(t=0;t<temp_bnum;t++){
                            if(artist[pos].booking[temp_bnum].theDate.day == artist[pos].booking[t].theDate.day &&
                               artist[pos].booking[temp_bnum].theDate.month == artist[pos].booking[t].theDate.month &&
                               artist[pos].booking[temp_bnum].theDate.year == artist[pos].booking[t].theDate.year){
                               printf("That date is already taken");
                               date = FALSE;
                               }else if(artist[pos].booking[temp_bnum].theDate.day == (artist[pos].booking[t].theDate.day - 2) ||
                               artist[pos].booking[temp_bnum].theDate.day == (artist[pos].booking[t].theDate.day - 1) ||
                               artist[pos].booking[temp_bnum].theDate.day == (artist[pos].booking[t].theDate.day + 1) ||
                               artist[pos].booking[temp_bnum].theDate.day == (artist[pos].booking[t].theDate.day + 2) &&
                               artist[pos].booking[temp_bnum].theDate.month == artist[pos].booking[t].theDate.month &&
                               artist[pos].booking[temp_bnum].theDate.year == artist[pos].booking[t].theDate.year){
                               printf("That date is too close to another booking date");
                               date = FALSE;
                               }else{date = TRUE;break;}

                        }
                    }else{date = TRUE;}
                    if (temp_bnum==0)
                        date = TRUE;
                }
                fflush(stdin);
                printf("Enter Artist's booking hotel: ");
                gets(artist[pos].booking[temp_bnum].hotel);
                printf("Enter Artist's booking location(address): ");
                gets(artist[pos].booking[temp_bnum].location);
                printf("Enter Artist's booking guide: ");
                gets(artist[pos].booking[temp_bnum].guide);
                printf("Enter Artist's Booking flightInfo: ");
                gets(artist[pos].booking[temp_bnum].flightInfo);
                if(artist[pos].booking[temp_bnum].type == 'L'){
                    printf("Enter Artist's Booking localRate (enter zero for voluntary): ");
                    scanf("%f",&artist[pos].booking[temp_bnum].rate.localRate);
                    artist[pos].earningPerYr+=artist[pos].booking[temp_bnum].rate.localRate;
                }else if(artist[pos].booking[temp_bnum].type == 'O'){
                    printf("Enter Artist's Booking foreignRate(including hotel,plane fair for all members): ");
                    scanf("%f",&artist[pos].booking[temp_bnum].rate.foreignRate);
                    artist[pos].earningPerYr+=artist[pos].booking[temp_bnum].rate.foreignRate;
                }
                temp_bnum+=1;
            }else{
                printf("This artist can only have a maximum of 15 bookings\n");
            }

        }
    }

};

void display_all_artist(){
    int a;
    int counter;
    fflush(stdin);
    for(a=0;a<acount;a++){
        printf("Artist StageName:%s\nArtist RealName:%s\nArtist Tele#:%d\n",artist[a].stageName,artist[a].realName,artist[a].telephone);
        printf("Artist Account #:%d\nArtist Acc Balance:%.f\nArtist earning per year:%.f\n",artist[a].accountNum,artist[a].accountBal,artist[a].earningPerYr);
        printf("*****BOOKING INFORMATION*****\n");
        for(counter=0;counter<bcount[a];counter++){
            printf("Artist Booking #:%d\nArtist Booking location:%s\n",artist[a].booking[counter].bookingNum,artist[a].booking[counter].location);
            printf("Artist Hotel:%s\nArtist flight info:%s\n",artist[a].booking[counter].hotel,artist[a].booking[counter].flightInfo);
            printf("Artist Booking date(day month year): %d %d %d\n",artist[a].booking[counter].theDate.day,artist[a].booking[counter].theDate.month,artist[a].booking[counter].theDate.year);
            printf("Artist Booking type-(L)ocal or (O)verseas: %c\nArtist Booking Guide:%s\n",artist[a].booking[counter].type,artist[a].booking[counter].guide);
            if(artist[acount].booking[bcount[acount]].type == 'L')
                printf("Artist Booking Rate: %.f\n",artist[a].booking[counter].rate.localRate);
            if(artist[acount].booking[bcount[acount]].type == 'O')
                printf("Artist Booking Rate: %.f\n",artist[a].booking[counter].rate.foreignRate);
        }
        printf("*****Foundation Information*****\n");
        printf("Artist Foundation Acc #:%d\n",artist[a].foundation.fAccountNum);
        printf("Artist Foundation Balance:%.f\n",artist[a].foundation.balance);
        printf("Artist Foundation Major Charity:%s\n",artist[a].foundation.majorCurCharity);
    }

};

void delete_artist(){
    fflush(stdin);
    int a;
    int counter;
    char temp_artist[20];
    printf("Enter the Artist(stagename) you want to delete: ");
    gets(temp_artist);
    pos = find_artist(temp_artist);
    if(pos == -1){
        printf("No artist found with that artist name");
    }else{
        for(a = pos;a<=acount;a++){
            strcpy(artist[a].stageName,artist[a+1].stageName);
            strcpy(artist[a].realName,artist[a+1].realName);
            artist[a].telephone=artist[a].telephone=artist[a].telephone=artist[a+1].telephone;
            artist[a].accountNum=artist[a+1].accountNum;
            artist[a].accountBal=artist[a+1].accountBal;
            artist[a].earningPerYr=artist[a+1].earningPerYr;
            //check which one larger so to know which to set the upper bound for the for loop
            printf("*****BOOKING INFORMATION*****\n");
            if(bcount[a]<=bcount[a+1]){
                for(counter=0;counter<bcount[a+1];counter++){
                    artist[a].booking[counter].bookingNum=artist[a+1].booking[counter].bookingNum;
                    strcpy(artist[a].booking[counter].location,artist[a+1].booking[counter].location);
                    strcpy(artist[a].booking[counter].hotel,artist[a+1].booking[counter].hotel);
                    strcpy(artist[a].booking[counter].flightInfo,artist[a+1].booking[counter].flightInfo);
                    artist[a].booking[counter].theDate.day=artist[a+1].booking[counter].theDate.day;
                    artist[a].booking[counter].theDate.month=artist[a+1].booking[counter].theDate.month;
                    artist[a].booking[counter].theDate.year=artist[a+1].booking[counter].theDate.year;
                    artist[a].booking[counter].type=artist[a+1].booking[counter].type;
                    strcpy(artist[a].booking[bcount[a]].guide,artist[a+1].booking[counter].guide);
                    artist[a].booking[counter].rate=artist[a+1].booking[counter].rate;
                bcount[acount]--;
                }
            }else if(bcount[a]>bcount[a+1]){
                for(counter=0;counter<bcount[a];counter++){
                    artist[a].booking[counter].bookingNum=artist[a+1].booking[counter].bookingNum;
                    strcpy(artist[a].booking[counter].location,artist[a+1].booking[counter].location);
                    strcpy(artist[a].booking[counter].hotel,artist[a+1].booking[counter].hotel);
                    strcpy(artist[a].booking[counter].flightInfo,artist[a+1].booking[counter].flightInfo);
                    artist[a].booking[counter].theDate.day=artist[a+1].booking[counter].theDate.day;
                    artist[a].booking[counter].theDate.month=artist[a+1].booking[counter].theDate.month;
                    artist[a].booking[counter].theDate.year=artist[a+1].booking[counter].theDate.year;
                    artist[a].booking[counter].type=artist[a+1].booking[counter].type;
                    strcpy(artist[a].booking[bcount[a]].guide,artist[a+1].booking[counter].guide);
                    artist[a].booking[counter].rate=artist[a+1].booking[counter].rate;
                bcount[acount]--;
                }

            }
        printf("*****Foundation Information*****\n");
            artist[a].foundation.fAccountNum=artist[a+1].foundation.fAccountNum;
            artist[a].foundation.balance=artist[a+1].foundation.balance;
            strcpy(artist[a].foundation.majorCurCharity,artist[a+1].foundation.majorCurCharity);
        }
    }
    acount--;

};
void search_artist(){
    char temp_artist[20];
    int counter;
    fflush(stdin);
    printf("Enter the Artist(stagename) you want to search: ");
    gets(temp_artist);
    pos = find_artist(temp_artist);
    if(pos == -1){
        printf("No artist found with that artist name");
    }else{
        fflush(stdin);
        printf("Artist StageName:%s\nArtist RealName:%s\nArtist Tele#:%d\n",artist[pos].stageName,artist[pos].realName,artist[pos].telephone);
        printf("Artist Account #:%d\nArtist Acc Balance:%.f\nArtist earning per year:%.f\n",artist[pos].accountNum,artist[pos].accountBal,artist[pos].earningPerYr);
        printf("*****BOOKING INFORMATION*****\n");
        for(counter=0;counter<bcount[pos];counter++){
            printf("Artist Booking #:%d\nArtist Booking location:%s\n",artist[pos].booking[counter].bookingNum,artist[pos].booking[counter].location);
            printf("Artist Hotel:%s\nArtist flight info:%s\n",artist[pos].booking[counter].hotel,artist[pos].booking[counter].flightInfo);
            printf("Artist Booking date(day month year): %d %d %d\n",artist[pos].booking[counter].theDate.day,artist[pos].booking[counter].theDate.month,artist[pos].booking[counter].theDate.year);
            printf("Artist Booking type-(L)ocal or (O)verseas: %c\nArtist Booking Guide:%s\n",artist[pos].booking[counter].type,artist[pos].booking[counter].guide);
            if(artist[pos].booking[counter].type == 'L')
                printf("Artist Booking Rate: %.f\n",artist[pos].booking[counter].rate.localRate);
            if(artist[pos].booking[counter].type == 'O')
                printf("Artist Booking Rate: %.f\n",artist[pos].booking[counter].rate.foreignRate);
        }
        printf("*****Foundation Information*****\n");
        printf("Artist Foundation Acc #:%d\n",artist[pos].foundation.fAccountNum);
        printf("Artist Foundation Balance:%.f\n",artist[pos].foundation.balance);
        printf("Artist Foundation Major Charity:%s\n",artist[pos].foundation.majorCurCharity);
    }
};
void generate_report(){
    printf("What type of report: 1)yearly earning for each artist 2)revenue in each foundation 3)");

};

void storeRec(){
    int i,b;
    ArtistfilePtr=fopen("artist_data.txt","w");
	if(ArtistfilePtr==NULL){
		printf("The file is not opened.\n");
	}
	else{
        for(i=0;i<acount;i++){
            fprintf(ArtistfilePtr,"%s= %s= %d %f %d %f ",artist[i].stageName,artist[i].realName,artist[i].accountNum,
                    artist[i].accountBal,artist[i].telephone,artist[i].earningPerYr);
            fprintf(ArtistfilePtr,"%d %f %s= ",artist[i].foundation.fAccountNum,artist[i].foundation.balance,artist[i].foundation.majorCurCharity);
            printf("Writing data to file\n");
            for(b=0;b<bcount[i];b++){
                fprintf(ArtistfilePtr,"%d %c %d %d %d %s= %s= %s= %s= ",artist[i].booking[b].bookingNum,artist[i].booking[b].type,
                        artist[i].booking[b].theDate.day,artist[i].booking[b].theDate.month,artist[i].booking[b].theDate.year,
                        artist[i].booking[b].hotel,artist[i].booking[b].location,
                        artist[i].booking[b].guide,artist[i].booking[b].flightInfo);
                if(artist[i].booking[b].type == 'L')
                    fprintf(ArtistfilePtr,"%f ",artist[i].booking[b].rate.localRate);
                else if(artist[i].booking[b].type == 'O')
                    fprintf(ArtistfilePtr,"%f ",artist[i].booking[b].rate.foreignRate);
            }
        }
    }
    fclose(ArtistfilePtr);
}

void readRec(){
    ArtistfilePtr=fopen("artist_data.txt","r");
    if(ArtistfilePtr==NULL){
        printf("The file is not opened yet.\n");
    }else{
        do{
            fscanf(ArtistfilePtr,"%[^=]= %[^=]= %d %f %ld %f ",&artist[acount].stageName,&artist[acount].realName,
                   &artist[acount].accountNum,&artist[acount].accountBal,&artist[acount].telephone,&artist[acount].earningPerYr);
            fscanf(ArtistfilePtr,"%d %f %[^=]= ",&artist[acount].foundation.fAccountNum,&artist[acount].foundation.balance,
                   &artist[acount].foundation.majorCurCharity);
            while(!feof(ArtistfilePtr)){
                    fscanf(ArtistfilePtr,"%d %c %d %d %d %[^=]= %[^=]= %[^=]= %[^=]= ",
                        &artist[acount].booking[bcount[acount]].bookingNum,&artist[acount].booking[bcount[acount]].type,
                        &artist[acount].booking[bcount[acount]].theDate.day,&artist[acount].booking[bcount[acount]].theDate.month,&artist[acount].booking[bcount[acount]].theDate.year,
                        &artist[acount].booking[bcount[acount]].hotel,&artist[acount].booking[bcount[acount]].location,
                        &artist[acount].booking[bcount[acount]].guide,&artist[acount].booking[bcount[acount]].flightInfo);
                    if(artist[acount].booking[bcount[acount]].type == 'L')
                        fscanf(ArtistfilePtr,"%f ",&artist[acount].booking[bcount[acount]].rate.localRate);
                    if(artist[acount].booking[bcount[acount]].type == 'O')
                        fscanf(ArtistfilePtr,"%f ",&artist[acount].booking[bcount[acount]].rate.foreignRate);
                    bcount[acount]++;
            }
            acount++;
            printf("Reading data into structure\n");
        }while(!feof(ArtistfilePtr));
    }
    fclose(ArtistfilePtr);

}
void create_account(){
    int pin;
    char whoami;
    char pname[10],pname2[10],uname[10];
    printf("Enter administrator PIN: ");
    scanf("%d",&pin);
    if(pin==6969){
        fflush(stdin);
        printf("Type of account (M)anager/(C)lerk: ");
        scanf("%c",&whoami);
        fflush(stdin);
        printf("Enter a username: ");
        gets(uname);
        printf("Enter password: ");
        gets(pname);
        printf("confirm Password: ");
        gets(pname2);
        if(strcmp(pname,pname2)==0){
            if(whoami == 'M'){
                LogindataPtr = fopen("Manager_Password.bin","wb");
                fprintf(LogindataPtr,"%s %s",uname,pname);
                fclose(LogindataPtr);
            }else if(whoami == 'C'){
                LogindataPtr = fopen("Clerk_Password.bin","rb");
                fprintf(LogindataPtr,"%s %s",uname,pname);
                fclose(LogindataPtr);
            }
        }
    }

}
