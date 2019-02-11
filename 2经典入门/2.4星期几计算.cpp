#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#define ISYEAP(x) x % 100 != 0 && x % 4 == 0 || x % 400 == 0 ? 1 : 0

using namespace std;

int dayOfMonth[13][2] = {
    0, 0,
    31, 31,
    28, 29,
    31, 31,
    30, 30,
    31, 31,
    30, 30,
    31, 31,
    31, 31,
    30, 30,
    31, 31,
    30, 30,
    31, 31};

struct Date
{
    int Day;
    int Month;
    int Year;
    void nextDay()
    {
        Day++;
        if (Day > dayOfMonth[Month][ISYEAP(Year)])
        {
            Day = 1;
            Month++;
            if (Month > 12)
            {
                Month = 1;
                Year++;
            }
        }
    }
};

int buf[3001][13][32];
char monthName[13][20] = {
    "",
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"};

char weekName[7][20] = {
    "Sunday",
    "Monday",
    "Tuesday",
    "Thursday",
    "Friday",
    "Saturday"};

int main(int argc, char const *argv[])
{
    Date tmp;
    int cnt = 0;
    tmp.Day = 1;
    tmp.Month = 1;
    tmp.Year = 1;
    while (tmp.Year != 3001)
    {
        buf[tmp.Year][tmp.Month][tmp.Day] = cnt;
        tmp.nextDay();
        cnt++;
    }
    int d, m, y;
    char s[20];
    while (scanf("%d%s%d", &d, s, &y) != EOF)
    {
        for (m = 1; m <= 12; m++)
        {
            if (strcmp(s, monthName[m]) == 0)
            {
                break;
            }
        }
        int days = buf[y][m][d] - buf[2012][7][16];
        days += 1;
        puts(weekName[(days % 7 + 7) % 7]);
    }
    return 0;
}
