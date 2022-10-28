//
// Created by User on 17.10.2022.
//
#include "iostream"
#include "string"
#include "vector"

using namespace std;

struct time1{
    int a;int b; time1(int hours,int minutes){a=hours;b=minutes;}};

class Train {
public:
    string start;
    string end;
    int hours;
    int minutes;
    int move_days;
    struct carriage{
        string name;
        int seats;
        int def_price;
        carriage(string namec,int seats,int def_price){
            name = namec;
            this ->seats = seats; this -> def_price = def_price;
        }
    };
    vector<int> num;
    vector<time1> timer;
    vector<carriage*> train;
    Train(string start, string end, int move,int hours,int minutes);
    void addn(vector<int> number){
        for(int i = 0;i<number.size();i++)
            num.push_back(number[i]);
    }
    void addt(vector<time1> number){
        for(int i = 0;i<number.size();i++)
            timer.push_back(number[i]);
    }
    void addc(string nameset, int seats, int price){
        auto* a = new carriage(nameset,seats,price);
        train.push_back(a);
    }
    void rev(){
        string s; s = start; start = end; end = s;
        for(int i = 0;i<num.size();i++)
            num[i]++;
    }
};

Train::Train(string start, string end, int move,int hours,int minutes) {
    this ->start = start;this ->end = end; move_days = move; this->hours = hours; this->minutes = minutes;
}

Train Sapsan(string start,string end,int move,int hours,int minutes,vector<int> number,vector<time1> time,bool reverse){
    Train tr(start,end,move,hours,minutes);
        tr.addn(number);
        tr.addt(time);
    if(reverse)
        tr.rev();
        tr.addc("1P", 4, 30000);
        tr.addc("1B", 19, 3500);
        tr.addc("1C", 44, 2700);
        tr.addc("2C", 66, 1200);
        tr.addc("2B", 66, 1000);
        tr.addc("2E", 40, 2600);
    return tr;
    }

Train Lastochka(string start,string end,int move,int hours,int minutes,vector<int> number,vector<time1> time,bool reverse){
    Train tr(start,end,move,hours,minutes);
        tr.addn(number);
    tr.addt(time);
    if(reverse)
        tr.rev();
        tr.addc("2Р", 67, 1700);
        tr.addc("2C", 103, 1200);
        tr.addc("2C", 103, 1200);
        tr.addc("2C", 103, 1200);
        tr.addc("2Р", 67, 1700);
    return tr;
}

Train Classical(string start,string end,int move,int hours,int minutes,vector<int> number,vector<time1> time,bool reverse){
   Train tr(start,end,move,hours,minutes);
        tr.addn(number);
    tr.addt(time);
    if(reverse)
        tr.rev();
        tr.addc("3С",56,1000);
        tr.addc("2Л",56,1500);
        tr.addc("3У",56,700);
        tr.addc("2Е",56,2800);
    return tr;
}

