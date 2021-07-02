#include"../react.h"
#include"string.h"
//#include "app.h"
#include "stdlib.h"
#include <fstream>
#include<vector>
#include <stdio.h>
#include <time.h>
#include <limits>
#include <math.h>



#define MAX_MENU_ITEMS 100
#define MAX_ORDERS 20
int DEFAULT_SIZE=10; // not sure if any of the classes use this so i kept it



// class definitions
class Food{
    public:
    string subclass;
    string name;
    string info;
    string price;
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
// class ListFood: public Food {
//     int startLine; // stores the place were that food starts 
// public:
//     // constructors
//     ListFood(string s, string n, string i, string p, int l):Food(s,n,i,p) {
//         startLine = l;
//     }
//     // acsesors
//     int getStartLine(){
//         return startLine;
//     } 
//     //mutators
//     void changeSubclass(string s) {
//         subclass = s;
//     }

//     void changeName(string n) {
//         name = n;
//     }

//     void changeInfo(string i) {
//         info = i;
//     }

//     void changePrice(string p) {
//         price = p;
//     }

// };

class Order {
  string name;
  string n_tp;
  string n_tn;
  public:
  Order(string name, string n_tp, string n_tn) : name(name), n_tp(n_tp), n_tn(n_tn) { }
  Order () : name("name"), n_tp("0"), n_tn("0") { }

  string getName(){
    return name;
  }
  string getNtp(){
    return n_tp;
  }
  string getNtn(){
    return n_tn;
  }
};
class OrderArr {
    string time;
    string totalnum;
    string totalp;
    Order **elt;
    string comments;
  public:
    //constructor
    OrderArr (int sz){
      init(sz);
    }

    OrderArr (string t, string n, string tot, Order **arr, string c):time(t), totalnum(n), totalp(tot), comments(c) {
        elt = new Order*[MAX_ORDERS];
        for(int i = 0; i < MAX_ORDERS; ++i) {
          elt[i] = arr[i];
        }

    }

    //destructor
    ~OrderArr(){
      for (int i=0; i<MAX_ORDERS; i++) {
        if (elt[i]!=0) delete elt[i];
      }
    delete [] elt;
    }

    //methods
    void init(int in) {
    totalnum = in;
    elt =  new Order *[MAX_ORDERS];
    for (int i=0; i<MAX_ORDERS; i++) {
        elt[i]=0;
      }
    }

    string getTime(){
      return time;
    }
    string getTn(){
      return totalnum;
    }
    string getTp(){
      return totalp;
    }
    OrderArr &operator= (OrderArr arr) {
      for (int i=0; i<MAX_ORDERS; i++) {
        if (elt[i]!=0) delete elt[i];
    }
    delete [] elt;
    totalnum = arr.totalnum;
    elt =  new Order *[MAX_ORDERS];
    for (int i=0; i<MAX_ORDERS; i++) {
      if (arr.elt[i]==0) elt[i]=0;
      else {
        elt[i] = new Order;
        *elt[i] = *arr.elt[i];
      }
    }
    return *this;
  }

    Order &operator[] (int index){
    if (index<=MAX_ORDERS-1 && index>=0) {
      if (elt[index]==0) {
        elt[index]= new Order;
      } 
      return *elt[index];
    } else if (index < 0) {
      cerr << "Error, bad index." << endl;
      return *elt[0];
    } else {
      cerr << "Error, bad index." << endl; 
      return *elt[MAX_ORDERS-1];
    }
  }
};

void readFoods(string fname, Food **fArr) {
    
    ifstream file(fname);
    string str;
    int n = 0;
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
    Food * f = new Food(FoodInfo[0],FoodInfo[1], FoodInfo[2], FoodInfo[3]);
    fArr[n++] = f; 
    delete [] FoodInfo;
  }
}

void readOrders(string fname, OrderArr **orderList) {
    ifstream file(fname);
    string skip; //for skipping 
    for(int i = 0; i<7; ++i) {getline(file, skip);}// skips first 7 lines of the file
    int orderStrSize = 4;
    int numOrders = 0; // number of orders
    string comments;
    while(!file.eof()) {
      string * orderStr = new string[orderStrSize]; // stores info needed fo OrderArr class
      for(int i = 0; i < orderStrSize; ++i) {
        getline(file, orderStr[i]);
      }
      Order **orderInfoArr = new Order*[MAX_ORDERS];//stores the order classes for the individule order

      for (size_t i = 0; i < 20; i++){ orderInfoArr[i] = NULL;}// sets the places were individule parts of the order are stored
      int n = 0;
      while(true){
        string * itemInfo = new string[3]; //for the order class
        getline(file, itemInfo[0]); //read info from file into itemInfo
        if(itemInfo[1] == "EOO"){ // If the end of order is reached, exit the while loop
          comments = itemInfo[0];
          delete [] itemInfo;
          break;
        }
        getline(file, itemInfo[1]);
        getline(file, itemInfo[2]); 
        Order * o = new Order(itemInfo[0],itemInfo[1], itemInfo[2]);
        orderInfoArr[n++] = *&o; 
        delete [] itemInfo;
      }
      OrderArr * oArr = new OrderArr(orderStr[0], orderStr[1], orderStr[2], orderInfoArr, comments);
      orderList[numOrders++] = oArr;
      delete [] orderInfoArr;
}
}


int main() {
    Food * foodArr[MAX_MENU_ITEMS];
  for(int i = 0; i < MAX_MENU_ITEMS; i++){
    foodArr[i] = NULL; //initializes all members of foodArr to NULL
  }
  readFoods("fstream1.txt", foodArr);
  // for(int i = 0; i < MAX_MENU_ITEMS; ++i) {
  //   Food f = *foodArr[i];
  //   f.display();
  // }

  OrderArr * orderList[MAX_ORDERS];
  for(int i = 0; i <MAX_ORDERS; ++i) {
    orderList[i] = NULL; //initializes all members of orderArr to NULL
  }

  readOrders("userinfo.txt",orderList);

}