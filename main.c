
#include <stdio.h>
#include <stdlib.h>

#define MAX_ART 20
#define BOOK_MAX 15


typedef union
{
    float localRate;
    float foreignRate;
}Rate;


typedef struct
{
    int day;
    int month;
    int year;
}Date;

typedef struct
{
    int bookingNum;
    char type;
    Date theDate;
    Rate rate;
    char hotel[20];
    char location[20];
    char guide[20];
    char flightInfo[20];
}Bookings;


typedef struct
{
    int fAccountNum;
    float balance;
    char majorCurCharity[20];
}Foundation;


typedef struct
{
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
    printf("0)Manager\n1)Clerk\n=======>>>");
    scanf("%d",&whoami);
    fflush(stdin);
    system("cls");
    while(login_attempts!=3)
    {
        printf("\t\t_+_+_+_+_+_+_+_Welcome to Bigworm Music and Record Label Company_+_+_+_+_+_+_+_\t\t\n\n");
    printf("Please enter the Username you wish to login with: ");
    gets(uname);
    printf("\nPlease enter the Password for the username entered above: ");
    gets(pname);

    printf("\nPlease wait...\n");
    system("pause");
    system("cls");

    //if(validate_login(uname,pname,whoami)== TRUE){

        while(choice != 7){

        choice = full_menu();

        run(choice);

        }

        exit(TRUE);

    //}else{

        //login_attempts+=1;

        //if(login_attempts==3){

          //  printf("You tried to login too many times\nConnection terminated\n");

            //exit(TRUE);

        //}

    }

    //}



    return 0;

}

int validate_login(char *uname, char *passwd,int a){

    char uname2[20];

    char pname2[20];

    if(a==0){

        LogindataPtr = fopen("C:/Users/Nsia Mckenzie/Documents/project2/Manager_Password","r");
        printf("reach\n");
        if(LogindataPtr==NULL){
            printf("error");
        }
    }else if(a==1){

        LogindataPtr = fopen("Clerk_Password","r");

    }

    while(!feof(LogindataPtr)){
        printf("reach2\n");
        fscanf(LogindataPtr,"%s %s",uname2,pname2);

        if(strcmp(uname2,uname)==0 && strcmp(pname2,passwd)==TRUE){

                printf("Hello there\n_+_+_+_+_+_+_+_Welcome to Bigworm Music and Record Label Company_+_+_+_+_+_+_+_\n");

            return TRUE;

        }else{

            printf("Am sorry,the username entered above is invalid\n");

            return FALSE;

        }

    }

};

int full_menu(){

    int a;

    fflush(stdin);

    //system("cls");

    printf(" \n");printf(" ");printf(" ");printf(" ");printf(" ");printf(" ");printf(" ");printf(" ");

    printf("\t\t_+_+_+_+_+_+_+_Bigworm Music and Record Label Company_+_+_+_+_+_+_+_\n\n\n");
    printf("\t\t\t    Artist Management System\n");

    printf(" ");

    printf("\t\t\t+=============================+\n");

    printf("\t\t\t|                             |\n");

    printf("\t\t\t|   1. Add Artist             |\n");

    printf("\t\t\t|   2. Update Artist          |\n");

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
        system("cls");
        add_artist();

        break;

    case 2:
        system("cls");
        update_artist();

        break;

    case 3:
        system("cls");
        display_all_artist();

        break;

    case 4:
        system("cls");
        if(whoami==TRUE){

            delete_artist();

        }else if(whoami==FALSE){

            printf("You have entered a restricted area");

            system("pause");

        }

        break;

    case 5:
        system("cls");
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
    printf("\t\t_+_+_+_+_+_+_+_Bigworm Music and Record Label Company_+_+_+_+_+_+_+_\n\n\n");
    printf("\n\t\t\t_+_+_+_+_+_+_+_ADD ARTIST INFORMATION_+_+_+_+_+_+_+_\t\n\n");

    printf("Enter Artist's StageName:");

    gets(artist[acount].stageName);

    printf("Please enter the Artist's Real name: ");

    gets(artist[acount].realName);

    printf("Please enter the Artist's accountNum: ");

    scanf("%d",&artist[acount].accountNum);

    printf("Please enter the Artist's accountBal: ");

    scanf("%f",&artist[acount].accountBal);

    printf("Please enter the Artist's telephone #: ");

    scanf("%ld",&artist[acount].telephone);

    //printf("Enter Artist's earningPerYr: $"); going to calculate this from the rate of all bookings

    //scanf("%f",&artist[acount].earningPerYr);

    printf("\n\n\t\t_+_+_+_+_+_+_+_ARTIST'S BOOKING INFO_+_+_+_+_+_+_+_\n");

    printf("How many bookings for this artist?\n====>>> ");

    scanf("%d",&a);

    if(bcount[acount]< BOOK_MAX){

    for(counter=0;counter<a;counter++){

        printf("Please enter the Artist's bookingNum:");

        scanf("%d",&artist[acount].booking[counter].bookingNum);

        printf("PLease enter the Artist's booking type (O)versea or (L)ocal: ");

        scanf(" %c",&artist[acount].booking[counter].type);

        int date = FALSE;

        while(date == FALSE && bcount[acount]>=0){

        printf("Please enter the Artist's booking Date (Day month year): ");

        scanf("%d %d %d",&artist[acount].booking[counter].theDate.day,&artist[acount].booking[counter].theDate.month,&artist[acount].booking[counter].theDate.year);

        if(artist[acount].booking[counter].type == 'O'){

            for(t=0;t<bcount[acount];t++){

                if(artist[acount].booking[counter].theDate.day == artist[acount].booking[t].theDate.day &&

                   artist[acount].booking[counter].theDate.month == artist[acount].booking[t].theDate.month &&

                   artist[acount].booking[counter].theDate.year == artist[acount].booking[t].theDate.year){

                   printf("\n\nAm Sorry\nThat date is already taken");

                   date = FALSE;

                   }else if(artist[acount].booking[counter].theDate.day == (artist[acount].booking[t].theDate.day - 2) ||

                   artist[acount].booking[counter].theDate.day == (artist[acount].booking[t].theDate.day - 1) ||

                   artist[acount].booking[counter].theDate.day == (artist[acount].booking[t].theDate.day + 1) ||

                   artist[acount].booking[counter].theDate.day == (artist[acount].booking[t].theDate.day + 2) &&

                   artist[acount].booking[counter].theDate.month == artist[acount].booking[t].theDate.month &&

                   artist[acount].booking[counter].theDate.year == artist[acount].booking[t].theDate.year){

                   printf("Am sorry but that date is too close to another booking date");

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

        printf("PLease enter the Artist's booking location(address): ");

        gets(artist[acount].booking[counter].location);

        printf("Please enter the Artist's booking guide: ");

        gets(artist[acount].booking[counter].guide);

        printf("PLease enter the Artist's Booking flightInfo: ");

        gets(artist[acount].booking[counter].flightInfo);

        if(artist[acount].booking[counter].type == 'L'){

            printf("Please enter the Artist's Booking localRate (enter zero for voluntary): ");

            scanf("%f",&artist[acount].booking[counter].rate.localRate);

            artist[acount].earningPerYr+=artist[acount].booking[counter].rate.localRate;

        }else if(artist[acount].booking[counter].type == 'O'){

            printf("PLease enter the Artist's Booking foreignRate(including hotel,plane fair for all members): ");

            scanf("%f",&artist[acount].booking[counter].rate.foreignRate);

            artist[acount].earningPerYr+=artist[acount].booking[counter].rate.foreignRate;

        }

        bcount[acount]+=1;

    }

    }else{

        printf("This artist can only have a maximum of 15 bookings\n");

    }

    printf("_+_+_+_+_+_+_+_ARTIST'S FOUNDATION INFO_+_+_+_+_+_+_+_\n");

    printf("Please enter the Artist's Foundation Account Number: ");

    scanf("%d",&artist[acount].foundation.fAccountNum);

    printf("PLease enter the Artist's Foundation Account Balance: ");

    scanf("%f",&artist[acount].foundation.balance);

    printf("\nPlease enter the Artist's Foundation majorCurCharity: ");

    scanf("%d",&artist[acount].foundation.majorCurCharity);

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
    printf("\t\t_+_+_+_+_+_+_+_Bigworm Music and Record Label Company_+_+_+_+_+_+_+_\n\n\n");
    printf("\n\t\t\t_+_+_+_+_+_+_+_UPDATE ARTIST INFORMATION_+_+_+_+_+_+_+_\t\n\n");

    printf("Please enter the stage name of the artist would you like to update: \n====>>>>");

    gets(temp_artist);

    pos = find_artist(temp_artist);

    if(pos == -1){

        printf("\nAm sorry\n No artist found with that artist name");

    }else{

        printf("What would you like to update for this artist?\n (A)- Artist basic information\n(B)- Booking information\n(F)- Foundation information\n====>>> ");

        scanf(" %c",&choice2);

        if(choice2 == 'A'){

            fflush(stdin);

            printf("*****ARTISTS INFORMATION*****\n");

            printf("Please enter Artist's StageName:");

            gets(artist[pos].stageName);

            printf("Please enter Artist's RealName: ");

            gets(artist[pos].realName);

            printf("Please enter Artist's accountNum: ");

            scanf("%d",&artist[pos].accountNum);

            printf("Please enter Artist's accountBal: ");

            scanf("%f",&artist[pos].accountBal);

            printf("Please enter Artist's telephone #: ");

            scanf("%ld",&artist[pos].telephone);

        }else if(choice2 == 'B'){

            printf("Please enter the booking number for booking you want to update: \n====>>>>");

            scanf("%d",&temp_bnum);

            temp_bnum = find_booking(temp_bnum);

            if(temp_bnum == -1){

                printf("\nAm sorry\nThat booking number does not exist:\n");

            }else if(temp_bnum< 15){

                printf("Please enter Artist's booking type (O)versea or (L)ocal: ");

                scanf(" %c",&artist[pos].booking[temp_bnum].type);

                int date = FALSE;

                while(date == FALSE && bcount[pos]>=0){

                    printf("Please enter Artist's booking Date (Day month year): ");

                    scanf("%d %d %d",&artist[pos].booking[temp_bnum].theDate.day,&artist[pos].booking[temp_bnum].theDate.month,&artist[pos].booking[temp_bnum].theDate.year);

                    if(artist[pos].booking[temp_bnum].type == 'O'){

                        for(t=0;t<temp_bnum;t++){

                            if(artist[pos].booking[temp_bnum].theDate.day == artist[pos].booking[t].theDate.day &&

                               artist[pos].booking[temp_bnum].theDate.month == artist[pos].booking[t].theDate.month &&

                               artist[pos].booking[temp_bnum].theDate.year == artist[pos].booking[t].theDate.year){

                               printf("\n Am sorry but that date is already taken");

                               date = FALSE;

                               }else if(artist[pos].booking[temp_bnum].theDate.day == (artist[pos].booking[t].theDate.day - 2) ||

                               artist[pos].booking[temp_bnum].theDate.day == (artist[pos].booking[t].theDate.day - 1) ||

                               artist[pos].booking[temp_bnum].theDate.day == (artist[pos].booking[t].theDate.day + 1) ||

                               artist[pos].booking[temp_bnum].theDate.day == (artist[pos].booking[t].theDate.day + 2) &&

                               artist[pos].booking[temp_bnum].theDate.month == artist[pos].booking[t].theDate.month &&

                               artist[pos].booking[temp_bnum].theDate.year == artist[pos].booking[t].theDate.year){

                               printf("Am sorry but that date is too close to another booking date");

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

                printf("This artist can only have a maximum of 15 bookings\n");

            }



        }

    }



};



void display_all_artist(){

    int a;

    int counter;

    fflush(stdin);
    printf("\t\t_+_+_+_+_+_+_+_Bigworm Music and Record Label Company_+_+_+_+_+_+_+_\n\n\n");
    printf("\n\t\t\t_+_+_+_+_+_+_+_DELETE ARTIST INFORMATION_+_+_+_+_+_+_+_\t\n\n");


    for(a=0;a<acount;a++){

        printf("Artist StageName:%s\nArtist RealName:%s\nArtist Tele#:%d\n",artist[a].stageName,artist[a].realName,artist[a].telephone);

        printf("Artist Account #:%d\nArtist Acc Balance:%.f\nArtist earning per year:%.f\n",artist[a].accountNum,artist[a].accountBal,artist[a].earningPerYr);

        printf("*****BOOKING INFORMATION*****\n");

        for(counter=0;counter<bcount[a];counter++){

            printf("Artist Booking #:%d\nArtist Booking location%s\n",artist[a].booking[counter].bookingNum,artist[a].booking[counter].location);

            printf("Artist Hotel:%s\nArtist flight info:%s\n",artist[a].booking[counter].hotel,artist[a].booking[counter].flightInfo);

            printf("Artist Booking date(day month year): %d %d %d\n",artist[a].booking[counter].theDate.day,artist[a].booking[counter].theDate.month,artist[a].booking[counter].theDate.year);

            printf("Artist Booking type-(L)ocal or (O)verseas: %c\nArtist Booking Guide:%s\n",artist[a].booking[counter].type,artist[a].booking[counter].guide);

            if(artist[acount].booking[bcount[acount]].type == 'L')

                printf("Artist Booking Rate: %.f\n",artist[a].booking[counter].rate.localRate);

            if(artist[acount].booking[bcount[acount]].type == 'O')

                printf("Artist Booking Rate: %.f\n",artist[a].booking[counter].rate.foreignRate);

        }

        printf("\t\t_+_+_+_+_+_+_+_Foundation Information_+_+_+_+_+_+_+_\t\t\n");

        printf("Artist Foundation Acc #:%d\n",artist[a].foundation.fAccountNum);

        printf("Artist Foundation Balance:%.f\n",artist[a].foundation.balance);

        printf("Artist Foundation Major Charity:%s\n",artist[a].foundation.majorCurCharity);

    }



};



void delete_artist(){

    int a;

    int counter;

    char temp_artist[20];
    printf("\t\t_+_+_+_+_+_+_+_Bigworm Music and Record Label Company_+_+_+_+_+_+_+_\n\n\n");
    printf("\n\t\t\t_+_+_+_+_+_+_+_DELETE ARTIST INFORMATION_+_+_+_+_+_+_+_\t\n\n");

    printf("\n\nPlease enter the Artist(stagename) you want to delete: ");

    gets(temp_artist);

    pos = find_artist(temp_artist);

    if(pos == -1){

        printf("\nAm sorry \nNo artist found with that artist name");

    }else{

        for(a = pos;a<=acount;a++){

            strcpy(artist[a].stageName,artist[a+1].stageName);

            strcpy(artist[a].realName,artist[a+1].realName);

            artist[a].telephone=artist[a].telephone=artist[a].telephone=artist[a+1].telephone;

            artist[a].accountNum=artist[a+1].accountNum;

            artist[a].accountBal=artist[a+1].accountBal;

            artist[a].earningPerYr=artist[a+1].earningPerYr;

            //check which one larger so to know which to set the upper bound for the for loop

            printf("\t\t_+_+_+_+_+_+_+_BOOKING INFORMATION_+_+_+_+_+_+_+_\t\t\n");

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

                }

            }

        printf("\t\t_+_+_+_+_+_+_+_Foundation Information_+_+_+_+_+_+_+_\t\t\n");

            artist[a].foundation.fAccountNum=artist[a+1].foundation.fAccountNum;

            artist[a].foundation.balance=artist[a+1].foundation.balance;

            strcpy(artist[a].foundation.majorCurCharity,artist[a+1].foundation.majorCurCharity);

        }

    }



};

void search_artist(){
printf("\t\t_+_+_+_+_+_+_+_Bigworm Music and Record Label Company_+_+_+_+_+_+_+_\n\n\n");
    printf("\n\t\t\t_+_+_+_+_+_+_+_SEARCH ARTIST INFORMATION_+_+_+_+_+_+_+_\t\n\n");



};

void generate_report(){

printf("\t\t_+_+_+_+_+_+_+_Bigworm Music and Record Label Company_+_+_+_+_+_+_+_\n\n\n");
    printf("\n\t\t\t_+_+_+_+_+_+_+_REPORT GENERATION FOR ARTIST INFORMATION_+_+_+_+_+_+_+_\t\n\n");




};



void storeRec(){

    int i,b;

    ArtistfilePtr=fopen("artist_data.txt","w");

	if(ArtistfilePtr==NULL){

		printf("The file is not opened.\n");

	}

	else{

        for(i=0;i<acount;i++){

            fprintf(ArtistfilePtr,"%s= %s= %d %f %ld %f ",artist[i].stageName,artist[i].realName,artist[i].accountNum,

                    artist[i].accountBal,artist[i].telephone,artist[i].earningPerYr);

            printf("Writing data to file\n");

            for(b=0;b<bcount[i];b++){

                fprintf(ArtistfilePtr,"%d %c %d %d %d %s= %s= %s= %s= ",artist[i].booking[b].bookingNum,artist[i].booking[b].type,

                        artist[i].booking[b].theDate.day,artist[i].booking[b].theDate.month,artist[i].booking[b].theDate.year,

                        artist[i].booking[b].hotel,artist[i].booking[b].location,

                        artist[i].booking[b].guide,artist[i].booking[b].flightInfo);

                if(artist[i].booking[b].type == 'L')

                    fprintf(ArtistfilePtr,"%f\n",artist[i].booking[b].rate.localRate);

                else if(artist[i].booking[b].type == 'O')

                    fprintf(ArtistfilePtr,"%f\n",artist[i].booking[b].rate.foreignRate);

            }

        }

    }

    fclose(ArtistfilePtr);

}

//READING FROM FILES NOT WORKING

void readRec(){

    printf("HI\n");

    ArtistfilePtr=fopen("artist_data.txt","r");

    printf("HI\n");

    if(ArtistfilePtr==NULL){

        printf("The file is not opened yet.\n");

    }else{

        printf("HI\n");

        while(!feof(ArtistfilePtr)){

            fscanf(ArtistfilePtr,"%[^=]s= %[^=]s= %d %f %ld %f ",artist[acount].stageName,artist[acount].realName,

                   artist[acount].accountNum,artist[acount].accountBal,artist[acount].telephone,artist[acount].earningPerYr);

            while(fgetc(ArtistfilePtr)!= '\n'){

            fscanf(ArtistfilePtr,"%d %c %d %d %d %[^=]s= %[^=]s= %[^=]s= %[^=]s=",

                   artist[acount].booking[bcount[acount]].bookingNum,artist[acount].booking[bcount[acount]].type,

                    artist[acount].booking[bcount[acount]].theDate.day,artist[acount].booking[bcount[acount]].theDate.month,artist[acount].booking[bcount[acount]].theDate.year,

                    artist[acount].booking[bcount[acount]].hotel,artist[acount].booking[bcount[acount]].location,

                    artist[acount].booking[bcount[acount]].guide,artist[acount].booking[bcount[acount]].flightInfo);

                    bcount[acount]++;

            }

            acount++;

            printf("Reading data into structure\n");

        }

        printf("HIdone\n");

    }

    fclose(ArtistfilePtr);



}
