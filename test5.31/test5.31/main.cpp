#include<iostream>
using namespace std;
/*
*思路：
* 1. 通过枚举每个月的1号是这一年的第几天，从而进行累加求和即可，其中注意闰年的处理
*/
int main()
{
    int year, month, day;
    while (cin >> year >> month >> day)
    {
        int monthDays[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
        int nday = monthDays[month - 1] + day;
        if (month > 2 &&
            ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
        {
            nday += 1;
        }
        cout << nday << endl;
    }
    return 0;
}


//#include <iostream>
//using namespace std;
//#define _CRT_SECURE_NO_WARNINGS 1
//#pragma warning(disable : 4996)
///*
//*思路：
//* 1. 分别求出每一个日期与0000年0月1日距离的天数
//* 2. 两个距离天数相减即可得到两个日期相差的天数
//*/
////平年从1月到n月的天数
//int mon[12] = { 0,31,59,90,120,151,181,212,243,273,304,334 };
////给出年月日，计算距离0000年0月1日的天数和
//int CountDay(int y, int m, int d)
//{
//    // 计算0-y年的天数
//    int yearDay = y * 365 + y / 4 - y / 100 + y / 400;
//    // 计算到0-m月的天数
//    int monthDay = mon[m - 1];
//    if (m > 2 && ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0))
//        monthDay += 1;
//    return yearDay + monthDay + d;
//}
//
//int main()
//{
//    int year1, month1, day1;
//    scanf("%4d%2d%2d", &year1, &month1, &day1);
//    int n1 = CountDay(year1, month1, day1);
//    int year2, month2, day2;
//    scanf("%4d%2d%2d", &year2, &month2, &day2);
//    int n2 = CountDay(year2, month2, day2);
//    cout << abs(n1 - n2) + 1 << endl;
//}


//void printDate(int year, int month, int day)//给出年分m和一年中的第n天，算出第n天是几月几号
//{
//    cout << year << '-';
//    if (month < 10)
//    {
//        cout << '0' << month << '-';
//    }
//    else cout << month << '-';
//
//    if (day < 10)
//    {
//        cout << '0' << day << endl;
//    }
//    else cout << day << endl;
//}
//
//int main()
//{
//    static char daytab[2][13] = {
//        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
//        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
//    };
//    int year, day_of_year, leap, i;
//    while (cin >> year >> day_of_year)
//    {
//        leap = ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0));
//        for (i = 0; i < 13; i++)
//        {
//            if (day_of_year > daytab[leap][i])
//            {
//                day_of_year -= daytab[leap][i];
//            }
//            else break;
//        }
//        if (i == 13) i -= 12;
//        printDate(year, i, day_of_year);
//    }
//    return 0;
//}
//int daytab[2][13] = {
//    {0,31,28,31,30,31,30,31,31,30,31,30,31},
//    {0,31,29,31,30,31,30,31,31,30,31,30,31}
//};
////判断闰年
//bool IsReapYear(int year) {
//    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
//}
////主函数
//int main() {
//    int year, month, day;
//    int number;
//    while (cin >> year >> number) {
//        month = 0;
//        int row = IsReapYear(year);
//        while (number > daytab[row][month]) {
//            number -= daytab[row][month];
//            month++;
//        }
//        day = number;
//        printf("%04d-%02d-%02d\n", year, month, day);
//    }
//    return 0;
//}


//日期N天后是几号
//bool isLeapYear(int year) { //平均每四年一次闰年，但是400的倍数也是闰年
//    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
//        return true;
//    }return false;
//}
//int daytab[2][13] = { //日期表，记录每个月有多少天（其实只有二月有变化，闰年29，平年28）
//        {0,31,28,31,30,31,30,31,31,30,31,30,31},
//        {0,31,29,31,30,31,30,31,31,30,31,30,31}
//};
//int main() {
//    int m, year, month, day, n;
//    cin >> m;
//    while (m--) {
//        cin >> year >> month >> day >> n;
//        n += day;
//        day = 0;//例如2008 2 3 100-->2008 2 0 103（方便计算）
//        while (n >= daytab[isLeapYear(year)][month]) {//以月为单位，知道最后不满一个月
//            n -= daytab[isLeapYear(year)][month];
//            day = 0;
//            if (month == 12) {//如果month为12月了，则要进位一年
//                month = 1; year++;
//            }
//            else {
//                month++;
//            }
//        }day += n;
//        if (day == 0) {//因为是设置从0开始的，所以比如2008 6 30会输出成2008 7 0，要转换一下
//            month--;
//            day = daytab[isLeapYear(year)][month];
//        }
//        printf("%04d-%02d-%02d\n", year, month, day);
//    }
//    return 0;
//}


//class Date
//{
//public:
//	Date()
//	{
//		_year = 1900;
//		_month = 1;
//		_day = 1;
//	}
//	//Date(int year = 1900, int month = 1, int day = 1)
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//void Test()
//{
//	Date d1;
//}
//void main()
//{
//	void Test();
//}