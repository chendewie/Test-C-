#include<iostream>
using namespace std;
/*
*˼·��
* 1. ͨ��ö��ÿ���µ�1������һ��ĵڼ��죬�Ӷ������ۼ���ͼ��ɣ�����ע������Ĵ���
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
//*˼·��
//* 1. �ֱ����ÿһ��������0000��0��1�վ��������
//* 2. ������������������ɵõ�����������������
//*/
////ƽ���1�µ�n�µ�����
//int mon[12] = { 0,31,59,90,120,151,181,212,243,273,304,334 };
////���������գ��������0000��0��1�յ�������
//int CountDay(int y, int m, int d)
//{
//    // ����0-y�������
//    int yearDay = y * 365 + y / 4 - y / 100 + y / 400;
//    // ���㵽0-m�µ�����
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


//void printDate(int year, int month, int day)//�������m��һ���еĵ�n�죬�����n���Ǽ��¼���
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
////�ж�����
//bool IsReapYear(int year) {
//    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
//}
////������
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


//����N����Ǽ���
//bool isLeapYear(int year) { //ƽ��ÿ����һ�����꣬����400�ı���Ҳ������
//    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
//        return true;
//    }return false;
//}
//int daytab[2][13] = { //���ڱ���¼ÿ�����ж����죨��ʵֻ�ж����б仯������29��ƽ��28��
//        {0,31,28,31,30,31,30,31,31,30,31,30,31},
//        {0,31,29,31,30,31,30,31,31,30,31,30,31}
//};
//int main() {
//    int m, year, month, day, n;
//    cin >> m;
//    while (m--) {
//        cin >> year >> month >> day >> n;
//        n += day;
//        day = 0;//����2008 2 3 100-->2008 2 0 103��������㣩
//        while (n >= daytab[isLeapYear(year)][month]) {//����Ϊ��λ��֪�������һ����
//            n -= daytab[isLeapYear(year)][month];
//            day = 0;
//            if (month == 12) {//���monthΪ12���ˣ���Ҫ��λһ��
//                month = 1; year++;
//            }
//            else {
//                month++;
//            }
//        }day += n;
//        if (day == 0) {//��Ϊ�����ô�0��ʼ�ģ����Ա���2008 6 30�������2008 7 0��Ҫת��һ��
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