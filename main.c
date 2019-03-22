/*
Names                ID Numbers
La-Shawn Reynolds    1800712
Nsia McKenzie        1802723
Kurt Jones           1803636

*/

//Calling the required system libraries
#include <stdio.h>
#include <stdlib.h>
#include "Structure.h"

//creating the main structure
Artists artist[MAX_ART];
//Declaration of files
FILE *ArtistfilePtr;
FILE *bookingPtr;
FILE *LogindataPtr;
//Declaration of global variables
int whoami;
int acount=0;
int bcount[MAX_ART];
int pos;
int choice;
//validate_login checks if the combination of username and password are correct
int validate_login(char *uname, char *passwd,int a){
    char uname2[20];
    char pname2[20];
    if(a==0){
        LogindataPtr = fopen("Manager_Password.bin","rb");
        //these checks will only be true if the user tries to login before creating a single account
        if(LogindataPtr==NULL){
            printf("Error: No file was found... If this is your first time...You would need to create an account\n\a");
            system("pause");
            system("cls");
            main();
        }
    }else if(a==1){
        LogindataPtr = fopen("Clerk_Password.bin","rb");
        if(LogindataPtr==NULL){
            printf("Error: No file was found... If this is your first time...You would need to create an account\n\a");
            system("pause");
            system("cls");
            main();
        }
    }
    //checks the entire file for the username and password combination
    while(!feof(LogindataPtr)){
        fscanf(LogindataPtr,"%s %s",&uname2,&pname2);
        if(strcmp(uname2,uname)==0 && strcmp(pname2,passwd)==TRUE)
            return TRUE;
    }
    return FALSE;
};
int full_menu(){
    int a;
    fflush(stdin);
    printf(" \n");printf(" ");printf(" ");printf(" ");printf(" ");printf(" ");printf(" ");printf(" ");
    printf("\t\t\t\t+_+_+_+_+_+_+BIGWORM MUSIC AND RECORD LABEL COMPANY+_+_+_+_+_+\n");
    printf("\t\t\t+_+_+_+_+_+_+BIGWORM Artist Management System+_+_+_+_+_+_+\n");
    printf(" ");
    printf("\t\t\t\t\t+=============================+\n");
    printf("\t\t\t\t\t|                             |\n");
    printf("\t\t\t\t\t|   1. Add Artist             |\n");
    printf("\t\t\t\t\t|   2. Update Artist          |\n");
    printf("\t\t\t\t\t|   3. Display All Artist     |\n");
    printf("\t\t\t\t\t|   4. Delete Artist          |\n");
    printf("\t\t\t\t\t|   5. Search Artist          |\n");
    printf("\t\t\t\t\t|   6. Generate Report        |\n");
    printf("\t\t\t\t\t|   7. Exit                   |\n");
    printf("\t\t\t\t\t|                             |\n");
    printf("\t\t\t\t\t+=============================+\n");
    printf("\t\t\t\t\t|   Select an Option [1..7]   |\n");
    printf("\t\t\t\t\t+=============================+\n");
    printf("=====================>>> ");
    scanf("%d",&a);
    return a;
}
int clerk_menu(){
    int a;
    fflush(stdin);
    printf(" \n");printf(" ");printf(" ");printf(" ");printf(" ");printf(" ");printf(" ");printf(" ");
    printf("\n\t\t\t\t+_+_+_+_+_+_+BIGWORM MUSIC AND RECORD LABEL COMPANY+_+_+_+_+_+\n\n");
    printf("\t\t\t+_+_+_+_+_+BIGWORM Artist information Gathering+_+_+_+_+_+\n");
    printf(" ");
    printf("\t\t\t\t\t\t\t+=============================+\n");
    printf("\t\t\t\t\t\t\t|                             |\n");
    printf("\t\t\t\t\t\t\t|   1. Add Artist Booking     |\n");
    printf("\t\t\t\t\t\t\t|   2. Update Artist Booking  |\n");
    printf("\t\t\t\t\t\t\t|   3. Search Artist info     |\n");
    printf("\t\t\t\t\t\t\t|   4. Search Artist Booking  |\n");
    printf("\t\t\t\t\t\t\t|   5. Generate Report        |\n");
    printf("\t\t\t\t\t\t\t|   6. Exit                   |\n");
    printf("\t\t\t\t\t\t\t|                             |\n");
    printf("\t\t\t\t\t\t\t+=============================+\n");
    printf("\t\t\t\t\t\t\t|   Select an Option [1..7]   |\n");
    printf("\t\t\t\t\t\t\t+=============================+\n");
    printf("=====================>>> ");
    scanf("%d",&a);
    return a;
}

//function to add an artist to the system
void add_artist(){
    int a,i;
    int t;
    int counter;
    char tempname[20];
    fflush(stdin);
    printf("\n\t\t\t\t+_+_+_+_+_+_+BIGWORM MUSIC AND RECORD LABEL COMPANY+_+_+_+_+_+\n\n");
    printf("\t\t\t\+_+_+_+BIGWORN ARTIST INFORMATION+_+_+_+\n");
    printf("Please enter the Artist's StageName:");
    gets(artist[acount].stageName);
    strcpy(tempname,artist[acount].stageName);
    for(i=0;i<acount;i++){
        if(strcmp(tempname,artist[i].stageName)==TRUE){
            printf("\n Am sorry but this stage name is already in the system\a\n");
            system("pause");
            system("cls");
            add_artist();
        }
    }
    printf("Please enter the Artist's RealName: ");
    gets(artist[acount].realName);
    printf("Please enter the Artist's accountNum: ");
    scanf("%d",&artist[acount].accountNum);
    printf("Please enter the Artist's accountBal: ");
    scanf("%f",&artist[acount].accountBal);
    printf("Please enter the Artist's telephone #:(876) ");
    scanf("%d",&artist[acount].telephone);
    printf("*****ARTIST'S BOOKING INFO*****\n");
    printf("How many bookings for this artist: ");
    scanf("%d",&a);
    if(bcount[acount]< BOOK_MAX){
    for(counter=0;counter<a;counter++){
        printf("Please enter the Artist's bookingNum:");
        scanf("%d",&artist[acount].booking[counter].bookingNum);
        printf("Please enter the Artist's booking type (O)versea or (L)ocal: ");
        scanf(" %c",&artist[acount].booking[counter].type);
        int date = FALSE;
        while(date == FALSE && bcount[acount]>=0){
        printf("Please enter the Artist's booking Date (Day month year): ");
        scanf("%d %d %d",&artist[acount].booking[counter].theDate.day,&artist[acount].booking[counter].theDate.month,&artist[acount].booking[counter].theDate.year);
        if(artist[acount].booking[counter].type == 'O'){
            //for loop testing if the date entered is already taken for an overseas booking
            for(t=0;t<bcount[acount];t++){
                if(artist[acount].booking[counter].theDate.day == artist[acount].booking[t].theDate.day &&
                   artist[acount].booking[counter].theDate.month == artist[acount].booking[t].theDate.month &&
                   artist[acount].booking[counter].theDate.year == artist[acount].booking[t].theDate.year){
                   printf("That date is already taken\n\a");
                   date = FALSE;
                   }else if(artist[acount].booking[counter].theDate.day == (artist[acount].booking[t].theDate.day - 2) ||
                   artist[acount].booking[counter].theDate.day == (artist[acount].booking[t].theDate.day - 1) ||
                   artist[acount].booking[counter].theDate.day == (artist[acount].booking[t].theDate.day + 1) ||
                   artist[acount].booking[counter].theDate.day == (artist[acount].booking[t].theDate.day + 2) &&
                   artist[acount].booking[counter].theDate.month == artist[acount].booking[t].theDate.month &&
                   artist[acount].booking[counter].theDate.year == artist[acount].booking[t].theDate.year){
                   printf("That date is too close to another booking date\n\a");
                   date = FALSE;
                   }else{date = TRUE;break;}

            }
        }else{date = TRUE;}
        if (counter==TRUE)
            date = TRUE;
        }
        fflush(stdin);
        printf("Please enter the Artist's booking hotel: ");
        gets(artist[acount].booking[counter].hotel);
        printf("Please enter the Artist's booking location(address): ");
        gets(artist[acount].booking[counter].location);
        printf("Please enter the Artist's booking guide: ");
        gets(artist[acount].booking[counter].guide);
        printf("Please enter the Artist's Booking flightInfo: ");
        gets(artist[acount].booking[counter].flightInfo);
        if(artist[acount].booking[counter].type == 'L'){
            printf("Please enter the Artist's Booking localRate (enter zero for voluntary): ");
            scanf("%f",&artist[acount].booking[counter].rate.localRate);
            artist[acount].earningPerYr+=artist[acount].booking[counter].rate.localRate;
        }else if(artist[acount].booking[counter].type == 'O'){
            printf("Please enter the Artist's Booking foreignRate(including hotel,plane fair for all members): ");
            scanf("%f",&artist[acount].booking[counter].rate.foreignRate);
            artist[acount].earningPerYr+=artist[acount].booking[counter].rate.foreignRate;
        }
        bcount[acount]+=1;
    }
    }else{
        printf("This artist can only have a maximum of 15 bookings\n");
        system("pause");
    }
    printf("*****ARTIST'S FOUNDATION INFO*****\n");
    printf("Please enter the Artist's Foundation Account Number: ");
    scanf("%d",&artist[acount].foundation.fAccountNum);
    printf("Please enter the Artist's Foundation Account Balance: ");
    scanf("%f",&artist[acount].foundation.balance);
    printf("Please enter the Artist's Foundation majorCurCharity: ");
    fflush(stdin);
    gets(artist[acount].foundation.majorCurCharity);
    acount+=1;
};
//function to locate the position of the artist in the structure array
int find_artist(char a[30]){
    int b;
    for(b=0;b<acount;b++)
    if(strcmp(a,artist[b].stageName)==0)
        return b;
    return -1;
}
//function to find the booking for a specific artist in the structure array
int find_booking(int temp_bnum){
    int j;
    for(j=0;j<BOOK_MAX;j++)
        if(temp_bnum == artist[pos].booking[j].bookingNum)
            return j;
    return -1;
}
void add_booking(){
    int a,t,counter;
    char temp_artist[20];
    fflush(stdin);
    printf("Please enter the Artist(stage name) you want to add booking for: ");
    gets(temp_artist);
    pos = find_artist(temp_artist);
    if(pos == -1){
        printf("No artist found with that artist name\n\a");
    }else{
        printf("*****ARTIST'S BOOKING INFO*****\n");
    if(bcount[pos]< BOOK_MAX){
        printf("Please enter the Artist's bookingNum:");
        scanf("%d",&artist[pos].booking[bcount[pos]].bookingNum);
        printf("Please enter the Artist's booking type (O)versea or (L)ocal: ");
        scanf(" %c",&artist[pos].booking[bcount[pos]].type);
        int date = FALSE;
        while(date == FALSE && bcount[pos]>=0){
        printf("Please enter the Artist's booking Date (Day month year): ");
        scanf("%d %d %d",&artist[pos].booking[bcount[pos]].theDate.day,&artist[pos].booking[bcount[pos]].theDate.month,&artist[pos].booking[bcount[pos]].theDate.year);
        if(artist[pos].booking[bcount[pos]].type == 'O'){
            //for loop testing if the date entered is already taken for an overseas booking
            for(t=0;t<bcount[pos];t++){
                if(artist[pos].booking[bcount[pos]].theDate.day == artist[pos].booking[t].theDate.day &&
                   artist[pos].booking[bcount[pos]].theDate.month == artist[pos].booking[t].theDate.month &&
                   artist[pos].booking[bcount[pos]].theDate.year == artist[pos].booking[t].theDate.year){
                   printf("That date is already taken\n\a");
                   date = FALSE;
                   }else if(artist[pos].booking[bcount[pos]].theDate.day == (artist[pos].booking[t].theDate.day - 2) ||
                   artist[pos].booking[bcount[pos]].theDate.day == (artist[pos].booking[t].theDate.day - 1) ||
                   artist[pos].booking[bcount[pos]].theDate.day == (artist[pos].booking[t].theDate.day + 1) ||
                   artist[pos].booking[bcount[pos]].theDate.day == (artist[pos].booking[t].theDate.day + 2) &&
                   artist[pos].booking[bcount[pos]].theDate.month == artist[pos].booking[t].theDate.month &&
                   artist[pos].booking[bcount[pos]].theDate.year == artist[pos].booking[t].theDate.year){
                   printf("That date is too close to another booking date\n\a");
                   date = FALSE;
                   }else{date = TRUE;break;}

            }
        }else{date = TRUE;}
        if (bcount[pos]==TRUE)
            date = TRUE;
        }
        fflush(stdin);
        printf("Please enter the Artist's booking hotel: ");
        gets(artist[pos].booking[bcount[pos]].hotel);
        printf("Please enter the Artist's booking location(address): ");
        gets(artist[pos].booking[bcount[pos]].location);
        printf("Please enter the Artist's booking guide: ");
        gets(artist[pos].booking[bcount[pos]].guide);
        printf("Please enter the Artist's Booking flightInfo: ");
        gets(artist[pos].booking[bcount[pos]].flightInfo);
        if(artist[pos].booking[bcount[pos]].type == 'L'){
            printf("Please enter the Artist's Booking localRate (enter zero for voluntary): ");
            scanf("%f",&artist[pos].booking[bcount[pos]].rate.localRate);
            artist[pos].earningPerYr+=artist[pos].booking[bcount[pos]].rate.localRate;
        }else if(artist[pos].booking[bcount[pos]].type == 'O'){
            printf("Please enter the Artist's Booking foreignRate(including hotel,plane fair for all members): ");
            scanf("%f",&artist[pos].booking[bcount[pos]].rate.foreignRate);
            artist[pos].earningPerYr+=artist[pos].booking[bcount[pos]].rate.foreignRate;
        }
        bcount[pos]+=1;
    }else{
        printf("This artist can only have a maximum of 15 bookings\n\a");
        system("pause");
    }
    }
}
//function to update artist info, their booking info or their foundation
void update_artist(){
    int temp_bnum,t;
    char temp_artist[20];
    char choice2;
    fflush(stdin);
    printf("Which Artist(stage name) would you like to update: ");
    gets(temp_artist);
    pos = find_artist(temp_artist);
    if(pos == -1){
        printf("No artist found with that artist name\a");
    }else{
        if(whoami==TRUE)
            printf("What do you want to update: (A)rtist basic info , (B)ooking info , (F)oundation information====>>> ");
        if(whoami==FALSE)
            printf("Please enter B to continue====>>> ");
        scanf(" %c",&choice2);
        if(choice2 == 'A' && whoami == TRUE){
            fflush(stdin);
            printf("*****ARTISTS INFORMATION*****\n");
            printf("Please enter the Artist's StageName:");
            gets(artist[pos].stageName);
            printf("Please enter the Artist's RealName: ");
            gets(artist[pos].realName);
            printf("Please enter the Artist's accountNum: ");
            scanf("%d",&artist[pos].accountNum);
            printf("Please enter the Artist's accountBal: ");
            scanf("%f",&artist[pos].accountBal);
            printf("Please enter the Artist's telephone #: ");
            scanf("%d",&artist[pos].telephone);
        }else if(choice2 == 'B'){
            printf("Please enter the Booking number for booking you want to update: ");
            scanf("%d",&temp_bnum);
            temp_bnum = find_booking(temp_bnum);
            if(temp_bnum == -1){
                printf("That booking number does not exist:\n\a");
            }else if(temp_bnum< 15){
                printf("Please enter the Artist's booking type (O)versea or (L)ocal: ");
                scanf(" %c",&artist[pos].booking[temp_bnum].type);
                int date = FALSE;
                while(date == FALSE && bcount[pos]>=0){
                    printf("Please enter the Artist's booking Date (Day month year): ");
                    scanf("%d %d %d",&artist[pos].booking[temp_bnum].theDate.day,&artist[pos].booking[temp_bnum].theDate.month,&artist[pos].booking[temp_bnum].theDate.year);
                    if(artist[pos].booking[temp_bnum].type == 'O'){
                        for(t=0;t<temp_bnum;t++){
                            if(artist[pos].booking[temp_bnum].theDate.day == artist[pos].booking[t].theDate.day &&
                               artist[pos].booking[temp_bnum].theDate.month == artist[pos].booking[t].theDate.month &&
                               artist[pos].booking[temp_bnum].theDate.year == artist[pos].booking[t].theDate.year){
                               printf("That date is already taken\n\a");
                               date = FALSE;
                               }else if(artist[pos].booking[temp_bnum].theDate.day == (artist[pos].booking[t].theDate.day - 2) ||
                               artist[pos].booking[temp_bnum].theDate.day == (artist[pos].booking[t].theDate.day - 1) ||
                               artist[pos].booking[temp_bnum].theDate.day == (artist[pos].booking[t].theDate.day + 1) ||
                               artist[pos].booking[temp_bnum].theDate.day == (artist[pos].booking[t].theDate.day + 2) &&
                               artist[pos].booking[temp_bnum].theDate.month == artist[pos].booking[t].theDate.month &&
                               artist[pos].booking[temp_bnum].theDate.year == artist[pos].booking[t].theDate.year){
                               printf("That date is too close to another booking date\n\a");
                               date = FALSE;
                               }else{date = TRUE;break;}

                        }
                    }else{date = TRUE;}
                    if (temp_bnum==0)
                        date = TRUE;
                }
                fflush(stdin);
                printf("Please enter the Artist's booking hotel: ");
                gets(artist[pos].booking[temp_bnum].hotel);
                printf("Please enter the Artist's booking location(address): ");
                gets(artist[pos].booking[temp_bnum].location);
                printf("Please enter the Artist's booking guide: ");
                gets(artist[pos].booking[temp_bnum].guide);
                printf("Please enter the Artist's Booking flightInfo: ");
                gets(artist[pos].booking[temp_bnum].flightInfo);
                if(artist[pos].booking[temp_bnum].type == 'L'){
                    printf("Please enter the Artist's Booking localRate (enter zero for voluntary): ");
                    scanf("%f",&artist[pos].booking[temp_bnum].rate.localRate);
                    artist[pos].earningPerYr+=artist[pos].booking[temp_bnum].rate.localRate;
                }else if(artist[pos].booking[temp_bnum].type == 'O'){
                    printf("Please enter the Artist's Booking foreignRate(including hotel,plane fair for all members): ");
                    scanf("%f",&artist[pos].booking[temp_bnum].rate.foreignRate);
                    artist[pos].earningPerYr+=artist[pos].booking[temp_bnum].rate.foreignRate;
                }
                temp_bnum+=1;
            }else{
                printf("\nAm sorry but this artist can only have a maximum of 15 bookings\n\a");
            }

        }else if(choice2 == 'F' && whoami==TRUE){
            printf("*****ARTIST'S FOUNDATION INFO*****\n");
            printf("Please enter the Artist's Foundation Account Number: ");
            scanf("%d",&artist[pos].foundation.fAccountNum);
            printf("Please enter the Artist's Foundation Account Balance: ");
            scanf("%f",&artist[pos].foundation.balance);
            printf("Please enter the Artist's Foundation majorCurCharity: ");
            fflush(stdin);
            gets(artist[pos].foundation.majorCurCharity);
        }else{
            printf("\nAm sorry but it seems you are trying to do something you don't have permission to do\n");
            printf("\nAre you a manager?\n\a");
            system("pause");

        }
    }

};

void display_all_artist(){
    int a;
    int counter;
    fflush(stdin);
    for(a=0;a<acount;a++){
        printf("************************************************************************************\n");
        printf("\n*****Basic Artist Information*****\n");
        printf("Artist StageName:%s\nArtist RealName:%s\nArtist Tele#:%d\n",artist[a].stageName,artist[a].realName,artist[a].telephone);
        printf("Artist Account #:%d\nArtist Acc Balance:%.f\nArtist earning per year:%.f\n",artist[a].accountNum,artist[a].accountBal,artist[a].earningPerYr);
        printf("\n*****BOOKING INFORMATION*****\n");
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
        printf("\n*****Foundation Information*****\n");
        printf("Artist Foundation Acc #:%d\n",artist[a].foundation.fAccountNum);
        printf("Artist Foundation Balance:%.f\n",artist[a].foundation.balance);
        printf("Artist Foundation Major Charity:%s\n",artist[a].foundation.majorCurCharity);
    printf("************************************************************************************\n");
    }

};

void delete_artist(){
    fflush(stdin);
    int a;
    int counter;
    char temp_artist[20];
    printf("Please enter the Artist(stagename) you want to delete: ");
    gets(temp_artist);
    pos = find_artist(temp_artist);
    if(pos == -1){
        printf("\n Am sorry but no artist was found with that artist name\a");
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
    printf("Please enter the the Artist(stagename) you want to search: ");
    gets(temp_artist);
    pos = find_artist(temp_artist);
    if(pos == -1){
        printf("\nAm sorry but no artist was found with that artist name\a");
    }else{
        fflush(stdin);
        if(whoami == TRUE || choice == 3){
        printf("Artist StageName:%s\nArtist RealName:%s\nArtist Tele#:%d\n",artist[pos].stageName,artist[pos].realName,artist[pos].telephone);
        printf("Artist Account #:%d\nArtist Acc Balance:%.f\nArtist earning per year:%.f\n",artist[pos].accountNum,artist[pos].accountBal,artist[pos].earningPerYr);
        printf("\n*****BOOKING INFORMATION*****\n");
        for(counter=0;counter<bcount[pos];counter++){
            printf("Artist Booking #:%d\nArtist Booking location:%s\n",artist[pos].booking[counter].bookingNum,artist[pos].booking[counter].location);
            printf("Artist Hotel:%s\nArtist flight info:%s\n",artist[pos].booking[counter].hotel,artist[pos].booking[counter].flightInfo);
            printf("Artist Booking date(day month year): %d %d %d\n",artist[pos].booking[counter].theDate.day,artist[pos].booking[counter].theDate.month,artist[pos].booking[counter].theDate.year);
            printf("Artist Booking type-(L)-local or (O)-overseas: %c\nArtist Booking Guide:%s\n",artist[pos].booking[counter].type,artist[pos].booking[counter].guide);
            if(artist[pos].booking[counter].type == 'L')
                printf("Artist Booking Rate: %.f\n",artist[pos].booking[counter].rate.localRate);
            if(artist[pos].booking[counter].type == 'O')
                printf("Artist Booking Rate: %.f\n",artist[pos].booking[counter].rate.foreignRate);
        }
        printf("\n*****Foundation Information*****\n");
        printf("Artist Foundation Acc #:%d\n",artist[pos].foundation.fAccountNum);
        printf("Artist Foundation Balance:%.f\n",artist[pos].foundation.balance);
        printf("Artist Foundation Major Charity:%s\n",artist[pos].foundation.majorCurCharity);
        }else if(whoami == FALSE){
            printf("\n*****BOOKING INFORMATION*****\n");
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
        }
    }
};
void generate_report(){
    int type,i;
    printf("What type of report would you like to generate? \n1)yearly earning for each artist \n2)revenue in each foundation and there Charity\n=====>>>>>");
    scanf("%d",&type);
    if(type == 1){
        FILE *earningPtr;
        earningPtr=fopen("earningreport.txt","w");
        if(earningPtr == NULL){
            printf("file was not opened \n\a");
        }else{
            for(i=0;i<acount;i++){
                printf("*********************************************\n");
                printf("Artist StageName: %s\nArtist RealName: %s\n",artist[i].stageName,artist[i].realName);
                printf("Artist earning per year:%.f\n",artist[i].earningPerYr);
                printf("*********************************************\n");
                fprintf(earningPtr,"\n*********************************************\n");
                fprintf(earningPtr,"Artist StageName: %s\nArtist RealName: %s\n",artist[i].stageName,artist[i].realName);
                fprintf(earningPtr,"Artist earning per year:%.f\n",artist[i].earningPerYr);
                fprintf(earningPtr,"*********************************************\n");
            }
            fclose(earningPtr);
        }
    }else if(type == 2){
        FILE *foundationRevPtr;
        foundationRevPtr = fopen("foundation_revenue.txt","w");
        if(foundationRevPtr == NULL){
            printf("Error: A File was not opened");
        }else{
            for(i=0;i<acount;i++){
                printf("*********************************************\n");
                printf("Artist Foundation Acc #:%d\n",artist[i].foundation.fAccountNum);
                printf("Artist Foundation Balance:%.f\n",artist[i].foundation.balance);
                printf("Artist Foundation Major Charity:%s\n",artist[i].foundation.majorCurCharity);
                printf("*********************************************\n");
                fprintf(foundationRevPtr,"*********************************************\n");
                fprintf(foundationRevPtr,"Artist Foundation Acc #:%d\n",artist[i].foundation.fAccountNum);
                fprintf(foundationRevPtr,"Artist Foundation Balance:%.f\n",artist[i].foundation.balance);
                fprintf(foundationRevPtr,"Artist Foundation Major Charity:%s\n",artist[i].foundation.majorCurCharity);
                fprintf(foundationRevPtr,"*********************************************\n");
            }
            fclose(foundationRevPtr);

        }

    }

};

void storeRec(){
    int i,b;
    ArtistfilePtr=fopen("artist_data.bin","wb");
    bookingPtr = fopen("Bcount.txt","w");
	if(ArtistfilePtr==NULL || bookingPtr==NULL){
		printf("The file is not opened.\n\a");
	}
	else{
            fwrite(&artist,sizeof(Artists),acount,ArtistfilePtr);
    }
    fclose(ArtistfilePtr);
    for(i=0;i<acount;i++)
        fprintf(bookingPtr,"%d\n",bcount[i]);
    fclose(bookingPtr);
}

void readRec(){
    int i;
    ArtistfilePtr=fopen("artist_data.bin","rb");
    bookingPtr = fopen("Bcount.txt","r");

    if(ArtistfilePtr==NULL || bookingPtr == NULL){
        printf("The file is not opened yet.\n\a");
    }else{

        while(!feof(ArtistfilePtr)){
                fread(&artist[acount],sizeof(Artists),1,ArtistfilePtr);

            acount++;
            //printf("Reading data into structure\n");
        };
        acount--;
    }
    for(i=0;i<acount;i++)
        fscanf(bookingPtr,"%d",&bcount[i]);
    fclose(ArtistfilePtr);

}
void create_account(){
    int pin,flag=FALSE;
    char whoami;
    char pname[10],pname2[10],uname[10],uname2[10];
    printf("Please enter administrator PIN: ");
    scanf("%d",&pin);
    if(pin==6969){
        fflush(stdin);
        printf("Type of account (M)anager/(C)lerk: ");
        scanf("%c",&whoami);
        fflush(stdin);
        do{
        printf("Please enter the a username you wish to login with: ");
        gets(uname);
            if(whoami=='M'){
                LogindataPtr = fopen("Manager_Password.bin","rb");
            }else if(whoami=='C'){
                LogindataPtr = fopen("Clerk_Password.bin","rb");
            }
            while(!feof(LogindataPtr)){
                fscanf(LogindataPtr,"%s",&uname2);
                if(strcmp(uname2,uname)==0){
                    printf("\nAm sorry but that username is already taken\n\a");
                    flag=TRUE;
                    break;
                }else{flag=FALSE;}
            }
        }while(flag ==TRUE);
        printf("Please enter the password: ");
        gets(pname);
        printf("Please confirm the Password: ");
        gets(pname2);
        if(strcmp(pname,pname2)==0){
            if(whoami == 'M'){
                LogindataPtr = fopen("Manager_Password.bin","ab");
                if(LogindataPtr==NULL){
                    printf("File was not opened\n\a");
                }else{
                fprintf(LogindataPtr,"%s %s",uname,pname);
                fprintf(LogindataPtr,"\n");
                fclose(LogindataPtr);
                }
            }else if(whoami == 'C'){
                LogindataPtr = fopen("Clerk_Password.bin","ab");
                if(LogindataPtr==NULL){
                    printf("File was not opened\n\a");
                }else{
                fprintf(LogindataPtr,"%s %s",uname,pname);
                fprintf(LogindataPtr,"\n");
                fclose(LogindataPtr);
                }
            }
        }
    }

}

void run2(int a){
    switch(a){
    case 1:
        add_booking();
        system("pause");
        system("cls");
        break;
    case 2:
        update_artist();
        system("pause");
        system("cls");
        break;
    case 3:
        search_artist();
        system("pause");
        system("cls");
        break;
    case 4:
        search_artist();
        system("pause");
        system("cls");
        break;
    case 5:
        generate_report();
        system("pause");
        system("cls");
    case 6:
        storeRec();
        break;
    }
}
void run(int a){
    switch(a){
    case 1:
        if(acount<MAX_ART)
            add_artist();
        else
            printf("\nAm sorry but you have reached the maximum artist\n\a");
        system("pause");
        system("cls");
        break;
    case 2:
        update_artist();
        system("pause");
        system("cls");
        break;
    case 3:
        display_all_artist();
        system("pause");
        system("cls");
        break;
    case 4:
            delete_artist();
            system("pause");
            system("cls");
        break;
    case 5:
        search_artist();
        system("pause");
        system("cls");
        break;
    case 6:
        generate_report();
        system("pause");
        system("cls");
        break;
    case 7:
        storeRec();
        break;

    }

}

int main()
{
    readRec();
    char uname[20];
    char pname[20];
    int login_attempts = 0;
    do{
    printf("\n\t\t\tWelcome\t\t\t\n 1)Create account\n 2)Continue : ");
    scanf("%d",&choice);
    if(choice == 1)
        create_account();
    }while(choice !=1 && choice!=2);
    printf("0)Manager\n1)Clerk\n=======>>> ");
    scanf("%d",&whoami);
    fflush(stdin);
    while(login_attempts!=3){
    printf("Please enter the Username you wish you login with: ");
    gets(uname);
    printf("Please enter the Password you entered above: ");
    gets(pname);
    if(validate_login(uname,pname,whoami)== TRUE){
        system("cls");
        while((choice != 7&&whoami == TRUE) || (choice != 6 && whoami==FALSE)){
            if(whoami == TRUE){
                choice = full_menu();
                run(choice);
            }else if(whoami == FALSE){
                choice = clerk_menu();
                run2(choice);

            }
        }
        exit(TRUE);
    }else{
        printf("\n Am sorry but you entered an incorrect Username or password\n\a");
        system("pause");
        login_attempts+=1;
        if(login_attempts==3){
            printf("You tried to login too many times\nConnection terminated\n\a");
            system("pause");
            exit(TRUE);
        }
        }
    }

    return 0;
}
