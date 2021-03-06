#ifndef CAR_H
#define CAR_H

#include <QString>
#include <QDate>

class Car
{
public:
    QString PlateNum;
    QString Brand;
    QString Model;
    int Rate;
    bool isAvailable = false;
    QString PhotoPath;
    QDate DateRented;
    QDate DateToReturn;
    QDate DateReturned;
    QString phone_no;
    int Cost;
    int final_Cost;

    Car();
    int calculateCost();
    //int calculateDaysRented();
    static int calculateDaysRented(QDate d1, QDate d2);
    int finalCost(int daysreturned, int daystoreturn);
};

#endif // CAR_H
