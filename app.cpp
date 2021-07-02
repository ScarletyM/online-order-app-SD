#include<iostream>
#include <fstream>
//#include <string>
using namespace std;

#define MAX_MENU_ITEMS 100
class Food{
    string subclass;
    string name;
    string info;
    string price;
    public:
        Food(string s, string n, string i, string p) : subclass(s), name(n), info(i), price(p) { //constructor
            //cout << name << info << price << "\n";  
        }
        Food(string n, string i, string p) : name(n), info(i), price(p){ //constructor for subclasses

        }
        void display(){ //prints out info
            cout << subclass << " " << name << " " << info << " " << price << "\n";
        }
        string getSub(){
            return subclass;
        }
        string getName(){
            return name;
        }
        string getInfo(){
            return info;
        }
        string getPrice(){
            return price;
        }
};

int main() {
    Food * fArr[MAX_MENU_ITEMS]; //10 is the number of items on our list
    for(int i = 0; i < MAX_MENU_ITEMS; i++){
        fArr[i] = 0; //initializes all members of fArr to 0
    }
    ifstream file("filestreamtest.txt");
    string str;
    int i = 0;
    while(true){
        string * FoodInfo = new string[4]; //4 is number of items within each Food
        getline(file, FoodInfo[0]); //read info from file into FoodInfo Array; subclass
        if(FoodInfo[0] == "EOF"){ // If the end of file is reached, exit the while loop
            delete [] FoodInfo;
            break;
        }
        getline(file, FoodInfo[1]); //food name
        getline(file, FoodInfo[2]); //description
        getline(file, FoodInfo[3]); //price
        //cout << FoodInfo[0] << FoodInfo[1] << FoodInfo[2] << FoodInfo[3] << "\n";
        Food * f = new Food(FoodInfo[0],FoodInfo[1], FoodInfo[2], FoodInfo[3]);
        fArr[i++] = f; 

        delete [] FoodInfo;
    }
    i = 0;
    while(fArr[i] != 0){
        Food f = *fArr[i];
        f.display();
        i++;
    }
    Food f = *fArr[2];
    string x = f.getName();
    cout << x << endl;
}
