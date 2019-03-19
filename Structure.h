#define MAX_ART 20
#define BOOK_MAX 15
enum choice {TRUE,FALSE};
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
