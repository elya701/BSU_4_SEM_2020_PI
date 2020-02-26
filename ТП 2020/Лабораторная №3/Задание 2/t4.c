#include <stdio.h>
#include <string.h>

int mounth[] = {31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
int highMounth[] = {31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366};
char namesOfMounts[100][100] = {
                                                {'J','a','n','u','a','r','y'},
                                                {'F','e','b','r','u','a','r','y'},
                                                {'M','a','r','c','h'},
                                                {'A','p','r','i','l'},
                                                {'M','a','y'},
                                                {'J','u','n','e'},
                                                {'J','u','l','y'},
                                                {'A','u','g','u','s','t'},
                                                {'S','e','p','t','e','m','b','e','r'},
                                                {'O','c','t','o','b','e','r'},
                                                {'N','o','v','e','m','b','e','r'},
                                                {'D','e','c','e','m','b','e','r'}
                            };
                        
char namesOfMountsShort[100][100] = {
                                                {'J','a','n'},
                                                {'F','e','b'},
                                                {'M','a','r'},
                                                {'A','p','r'},
                                                {'M','a','y'},
                                                {'J','u','n'},
                                                {'J','u','l'},
                                                {'A','u','g'},
                                                {'S','e','p'},
                                                {'O','c','t'},
                                                {'N','o','v'},
                                                {'D','e','c'}
                            };

typedef struct Date_
{
        int day;
        int mounth;
        int year;
}Date, *pDate;

int main() {
        Date d;
        char ch;
        printf("Please, choose format of typing data!\n");
        printf("Available formats: f, a, c\n");
        printf("f - data using Full name of Mounths\n");
        printf("a - data using Short name of Mounths\n");
        printf("c - data using common format of typing data (dd.mm.yyyy)\n");
        printf("Enter number: ");
        scanf("%c", &ch);

        char nameOfMounth[20];

        if (ch == 'f') {

        printf("Enter current day(dd):\n");
        scanf("%d", &d.day);


        printf("Enter fullName of mounth(October, November and etc):\n");
        scanf("%s", nameOfMounth);

        if (strcmp (nameOfMounth, namesOfMounts[0])==0) {
        d.mounth = 1;
        } else if (strcmp (nameOfMounth, namesOfMounts[1])==0) {
        d.mounth = 2;
        } else if (strcmp (nameOfMounth, namesOfMounts[2])==0) {
        d.mounth = 3;
        } else if (strcmp (nameOfMounth, namesOfMounts[3])==0) {
        d.mounth = 4;
        } else if (strcmp (nameOfMounth, namesOfMounts[4])==0) {
        d.mounth = 5;
        } else if (strcmp (nameOfMounth, namesOfMounts[5])==0) {
        d.mounth = 6;
        } else if (strcmp (nameOfMounth, namesOfMounts[6])==0) {
        d.mounth = 7;
        } else if (strcmp (nameOfMounth, namesOfMounts[7])==0) {
        d.mounth = 8;
        } else if (strcmp (nameOfMounth, namesOfMounts[8])==0) {
        d.mounth = 9;
        } else if (strcmp (nameOfMounth, namesOfMounts[9])==0) {
        d.mounth = 10;
        } else if (strcmp (nameOfMounth, namesOfMounts[10])==0) {
        d.mounth = 11;
        } else if (strcmp (nameOfMounth, namesOfMounts[11])==0) {
        d.mounth = 12;
        }








        printf("Enter current year(yyyy):\n");
        scanf("%d", &d.year);
        }
        
        if (ch == 'a') {

        printf("Enter current day(dd):\n");
        scanf("%d", &d.day);


        printf("Enter short name of mounth(Oct, Nov and etc):\n");
        scanf("%s", nameOfMounth);

        if (strcmp (nameOfMounth, namesOfMountsShort[0])==0) {
        d.mounth = 1;
        } else if (strcmp (nameOfMounth, namesOfMountsShort[1])==0) {
        d.mounth = 2;
        } else if (strcmp (nameOfMounth, namesOfMountsShort[2])==0) {
        d.mounth = 3;
        } else if (strcmp (nameOfMounth, namesOfMountsShort[3])==0) {
        d.mounth = 4;
        } else if (strcmp (nameOfMounth, namesOfMountsShort[4])==0) {
        d.mounth = 5;
        } else if (strcmp (nameOfMounth, namesOfMountsShort[5])==0) {
        d.mounth = 6;
        } else if (strcmp (nameOfMounth, namesOfMountsShort[6])==0) {
        d.mounth = 7;
        } else if (strcmp (nameOfMounth, namesOfMountsShort[7])==0) {
        d.mounth = 8;
        } else if (strcmp (nameOfMounth, namesOfMountsShort[8])==0) {
        d.mounth = 9;
        } else if (strcmp (nameOfMounth, namesOfMountsShort[9])==0) {
        d.mounth = 10;
        } else if (strcmp (nameOfMounth, namesOfMountsShort[10])==0) {
        d.mounth = 11;
        } else if (strcmp (nameOfMounth, namesOfMountsShort[11])==0) {
        d.mounth = 12;
        }








        printf("Enter current year(yyyy):\n");
        scanf("%d", &d.year);
        }
        
        if ( ch == 'c' ) {
        printf("Enter the date(dd.mm.yyyy):\n");
        scanf("%d.%d.%d", &d.day, &d.mounth, &d.year);
        }

        int days;

        if (d.year % 4 != 0) {
        days = mounth[d.mounth-1] + d.day;
        } else {
        days = highMounth[d.mounth-1] + d.day;
        }

        if (d.mounth >= 2 && ((d.year % 400) || ((d.year & 4) && !(d.year % 100))))
                days += 1;

        printf("Days since the beginning of the year: %d\n", days);


}
