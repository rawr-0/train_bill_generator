#include <iostream>
#include "OpenXLSX.hpp"
#include "random"
#include "string"
#include "windows.h"
#include "Train.cpp"

using namespace OpenXLSX;
using namespace std;

auto fill1(const XLWorksheet& wks){
    wks.cell("A1").value() = "Имя"; wks.cell("B1").value() = "Фамилия";
    wks.cell("C1").value() = "Отчество"; wks.cell("D1").value() = "Паспортные данные";
    wks.cell("E1").value() = "Откуда"; wks.cell("F1").value() = "Куда";
    wks.cell("G1").value() = "Дата отъезда";
    wks.cell("H1").value() = "Дата приезда";
    wks.cell("I1").value() = "Рейс";
    wks.cell("J1").value() = "Выбор вагона и места";
    wks.cell("K1").value() = "Стоимость";
    wks.cell("L1").value() = "Карта оплаты";
}

Train make_train(int pos){
    minstd_rand random(pos*5);
    unsigned int y = random.operator()();
    y %= 12;
    if(y == 0){
        return Lastochka("Москва", "Курск", 0,5,45,{715,721},{{16,10},{10,35}},0);;
    }
    if(y == 1){
        return Sapsan("Москва", "Санкт-Петербург", 0,3,30,{754, 756, 760, 762, 768, 770, 772, 774, 778, 780, 784},
                      {{5,55},{6,50},{9,10},{9,40},{13,30},{13,40},{15,30},{15,40},{17,30},{17,40},{19,30},{20,50}},0);;
    }
    if(y == 2){
        return Lastochka("Москва", "Нижний Новгород", 0,4,10,{701, 703, 705, 707, 709, 727, 729, 731, 733},{{6,10},{7,30},{9,10},{10,50},{12,3},{14,15},{15,10},{17,50},{18,30}},0);;
    }
    if(y == 3){
        return Lastochka("Москва", "Смоленск", 0,4,5,{715,731,753},{{7,15},{9,10},{12,10},{15,40}},0);
    }
    if(y == 4){
        return Lastochka("Москва", "Белгород", 0,7,30,{719,741,743},{{11,47},{14,18},{15,48}},0);
    }
    if(y == 5){
        return Classical("Москва","Воронеж",0,11,26,{25,},{{21,4}},0);
    }
    if(y == 6){
        return Lastochka("Москва", "Курск", 0,5,45,{715,721},{{13,10},{16,35}},1);
    }
    if(y == 7){
        return Sapsan("Москва", "Санкт-Петербург", 0,3,30,{754, 756, 760, 762, 768, 770, 772, 774, 778, 780, 784},
                      {{5,45},{6,50},{9,10},{9,40},{13,30},{13,40},{15,30},{17,30},{17,40},{19,30},{20,50}},1);
    }
    if(y == 8){
        return Lastochka("Москва", "Нижний Новгород", 0,4,10,{701, 703, 705, 707, 709, 727, 729, 731, 733},{{2,10},{3,30},{5,10},{6,50},{8,3},{10,15},{11,10},{13,50},{14,30}},1);
    }
    if(y == 9){
        return Lastochka("Москва", "Смоленск", 0,4,5,{715,731,753},{{12,15},{14,10},{17,10},{20,40}},1);
    }
    if(y == 10){
        return Lastochka("Москва", "Белгород", 0,7,30,{719,741,743},{{19,47},{22,18},{23,48}},1);
    }
    if(y == 11){
        return Classical("Москва","Воронеж",0,11,26,{25,},{{9,4}},1);
    }
};

void take_seats(XLWorksheet wks,Train tr,int pos){
    if(pos > 10)
        pos = (pos-pos%40) * 5 + pos%40;
    minstd_rand random(pos*5);
    unsigned int y = random.operator()();
    string date_s = to_string(y%28+1)+"."+ to_string(y%13+1)+"."+ to_string((y/10)%10+2010);
    time1 t1 = tr.timer[y%tr.num.size()];
    time1 t2(t1.a + tr.hours,t1.b + tr.minutes);
    t2.a += t2.b/60; t2.b = t2.b%60; int days = t2.a/24; t2.a = t2.a%24;
    string date_se = to_string(y%28+1+days)+"."+ to_string(y%13+1)+"."+ to_string((y/10)%10+2010);
    int q = 0;
    for(int i = 0;i<=200;i++){
        wks.cell("E" + to_string(i*5+pos)).value() = tr.start;
        wks.cell("F" + to_string(i*5+pos)).value() = tr.end;
        wks.cell("G" + to_string(i*5+pos)).value() = date_s+" T "+ to_string(t1.a)+":"+ to_string(t1.b);
        wks.cell("H" + to_string(i*5+pos)).value() = date_se+" T "+ to_string(t2.a)+":"+ to_string(t2.b);
        wks.cell("I" + to_string(i*5+pos)).value() = tr.num[y%tr.num.size()];
        if(tr.train[q]->seats > 0) {
            wks.cell("J" + to_string(i*5+pos)).value() = to_string(q+1) +" - "+ to_string(tr.train[q]->seats);
            tr.train[q]->seats--;
            wks.cell("K" + to_string(i*5+pos)).value() = tr.train[q]->def_price;
        }
        else{
            q++;
            wks.cell("J" + to_string(i*5+pos)).value() = to_string(q+1) +" - "+ to_string(tr.train[q]->seats);
            tr.train[q]->seats--;
            wks.cell("K" + to_string(i*5+pos)).value() = tr.train[q]->def_price;
        }
    }
}


void make_person(XLWorksheet wks, int i,string s1, string s2, string s3){
    int id = i;
    int chance_visa = 50, chance_mir = 30, chance_mastercard = 20;
    minstd_rand random(i*5);
    unsigned int y = random.operator()();
    int card = (y%101>=100-chance_visa)?4: (y%101>= 100 - chance_visa - chance_mir) ? 2 : (y % 101 >= 100 - chance_visa - chance_mir - chance_mastercard) ? 5 : 5;
    unsigned long long cardout = card*1000000000000000 + (random.operator()()%1000)*1000000000000
                                 + (random.operator()()%10000)*100000000 + (random.operator()()%10000)*10000 + (random.operator()()%10000);
    for(int o = (i == 0)?2:1;o<=5;o++) {
        wks.cell("A" + to_string(i*5+o)).value() = s1; wks.cell("B"+ to_string(i*5+o)).value() = s2;
        wks.cell("C" + to_string(i*5+o)).value() = s3 + ((id%2==0)?"ов":"ович");
        wks.cell("D" + to_string(i*5+o)).value() = 11111111+id;
        wks.cell("L" + to_string(i*5+o)).value() = to_string(cardout);
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    XLDocument doc;
    ifstream in1("../../names.csv");
    ifstream in2("../../surnames.csv");
    ifstream in3("../../fam.csv");
    doc.create("../../Spreadsheet.xlsx");
    auto wks = doc.workbook().worksheet("Sheet1");
    fill1(wks);
    string s1,s2,s3;
    for(int i = 0;i<10000;i++){
        s1 = "";s2="";s3="";
        in1>>s1;in2>>s2;in3>>s3;
        make_person(wks,i,s1,s2,s3);
        if((i % 200 == 0 or i % 200 == 1 or i % 200 == 2 or i % 200 == 3 or i % 200 == 4) and i < 9840)
            take_seats(wks, make_train(i),i+2),cout<<"progress: "<<i<<endl;
    }
    doc.save();
    return 0;
}
