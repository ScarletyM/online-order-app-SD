#include"../react.h"
#include"string.h"
#include "app.h"
#include "stdlib.h"
#include <fstream>
#include<vector>
#include <stdio.h>
#include <time.h>
#include <limits>

#define MAX_MENU_ITEMS 100
#define MAX_ORDERS 20
int DEFAULT_SIZE=10;

void write_const_texts() {
    print_at(5,"Aesthetic Alpacas"); //app name
    print_at(30,"Snacks"); //home page
    print_at(40,"Pizza");
    print_at(50,"Sweets");
    print_at(60,"Drinks");
    print_at(100,"Settings"); //settings
    print_at(120,"Night Mode");
    print_at(135,"Version");
    print_at(147,"1.00");
    print_at(155,"Contact Us");
    print_at(170,"Default Settings");
    //print_at(190,"Default Payment");
    print_at(210,"Auto Warning");
    print_at(230,"On");
    print_at(240,"Off");
    print_at(300,"Order History"); //profile
    print_at(320,"Favorite Orders");
    print_at(350,"User Name"); //login page
    print_at(370,"Password");
    print_at(380,"Log in");
    print_at(390,"Sign Up");
    print_at(410,"St Olaf ID");
    print_at(430,"Summary");//shopping cart
    print_at(440,"Subtotal");
    print_at(450,"Shipping");
    print_at(460,"Estimated Tax");
    print_at(480,"Estimated Total");
    print_at(500,"Place Order");
    print_at(520,"Comments");
    print_at(540,"Your order has been placed successfully!");
    print_at(600, "My Cart (");
    print_at(760, "Please write down you delivery address");
    print_at(800, "Please choose you payment method");
    print_at(940, "Cash");
    print_at(950, "Ole Dollars");
    print_at(970, "Please write down you phone number");
    print_at(1170, "Current address: ");
    print_at(1190, "Current phone number: ");
      //picker
    print_at (1700, "1");
    print_at (1703, "2");
    print_at (1706, "3");
    print_at (1709, "4");
    print_at (1712, "5");
    print_at (1715, "6");
    print_at (1718, "7");
    print_at (1721, "8");
    print_at (1724, "9");
    print_at (1727, "10");
}
void initiate_inputs() {
  print_at(620, ""); //initialize inputs
  print_at(640, ""); 
  print_at(660, ""); 
  print_at(680, ""); 
  print_at(700, "");
  print_at(1010, "");
}
string ftos(float fVal){
  char cVal[8];
  sprintf(cVal,"%.2f",fVal); //float to string.
  return cVal;
  //itoa(int v) //change int to string.
}
inline bool exists_test (const std::string& name) {
    ifstream f(name.c_str());
    return f.good();
}
void display_food(int k, int num_food, bool nightmode) {
  if (nightmode==0) {
    if (k==1) {
      for(int i=0;i<num_food;i++) {
        add_yaml("u_buyfood.yaml",{{"fname_index", 2500+100*i},{"fprice_index",2500+80+100*i},{"image","pizza.png"},{"i", i},{"k",k},{"tc","black"},{"bgdc","white"},{"boc","black"}});
      }
  } else if (k==2) {
      for(int i=0;i<num_food;i++) {
        add_yaml("u_buyfood.yaml",{{"fname_index", 3500+100*i},{"fprice_index",3500+80+100*i},{"image","snacks.png"},{"i", i},{"k",k},{"tc","black"},{"bgdc","white"},{"boc","black"}});
      }
  } else if (k==3) {
      for(int i=0;i<num_food;i++) {
        add_yaml("u_buyfood.yaml",{{"fname_index", 4500+100*i},{"fprice_index",4500+80+100*i},{"image","drinks.png"},{"i", i},{"k",k},{"tc","black"},{"bgdc","white"},{"boc","black"}});
      }
  } else {
      for(int i=0;i<num_food;i++) {
        add_yaml("u_buyfood.yaml",{{"fname_index", 5500+100*i},{"fprice_index",5500+80+100*i},{"image","sweets.png"},{"i", i},{"k",k},{"tc","black"},{"bgdc","white"},{"boc","black"}});
      }
    }
  } else {
    if (k==1) {
      for(int i=0;i<num_food;i++) {
        add_yaml("u_buyfood.yaml",{{"fname_index", 2500+100*i},{"fprice_index",2500+80+100*i},{"image","pizza.png"},{"i", i},{"k",k},{"tc","white"},{"bgdc","black"},{"boc","white"}});
      }
    } else if (k==2) {
      for(int i=0;i<num_food;i++) {
        add_yaml("u_buyfood.yaml",{{"fname_index", 3500+100*i},{"fprice_index",3500+80+100*i},{"image","snacks.png"},{"i", i},{"k",k},{"tc","white"},{"bgdc","black"},{"boc","white"}});
      }
    } else if (k==3) {
      for(int i=0;i<num_food;i++) {
        add_yaml("u_buyfood.yaml",{{"fname_index", 4500+100*i},{"fprice_index",3500+80+100*i},{"image","drinks.png"},{"i", i},{"k",k},{"tc","white"},{"bgdc","black"},{"boc","white"}});
      }
    } else {
      for(int i=0;i<num_food;i++) {
        add_yaml("u_buyfood.yaml",{{"fname_index", 5500+100*i},{"fprice_index",4500+80+100*i},{"image","sweets.png"},{"i", i},{"k",k},{"tc","white"},{"bgdc","black"},{"boc","white"}});
      }
    }
  }
}
void display_items(int i, int k, bool nightmode, int pindex) {
  if (nightmode==0) {
    if (k==1) {
      add_yaml("sc_product.yaml",{{"fname", 2500+100*i},{"fprice",2500+80+100*i},{"image","pizza.png"},{"i", i},{"k",k},{"indexPos",pindex},{"tc","black"},{"bgdc","white"},{"boc","black"}});
    } else if (k==2) {  
      add_yaml("sc_product.yaml",{{"fname", 3500+100*i},{"fprice",3500+80+100*i},{"image","snacks.png"},{"i", i},{"k",k},{"indexPos",pindex},{"tc","black"},{"bgdc","white"},{"boc","black"}});
    } else if (k==3) {
      add_yaml("sc_product.yaml",{{"fname", 4500+100*i},{"fprice",4500+80+100*i},{"image","drinks.png"},{"i", i},{"k",k},{"indexPos",pindex},{"tc","black"},{"bgdc","white"},{"boc","black"}});
    } else {
      add_yaml("sc_product.yaml",{{"fname", 5500+100*i},{"fprice",5500+80+100*i},{"image","sweets.png"},{"i", i},{"k",k},{"indexPos",pindex},{"tc","black"},{"bgdc","white"},{"boc","black"}});
    }
  } else {
    if (k==1) {
      add_yaml("sc_product.yaml",{{"fname", 2500+100*i},{"fprice",2500+80+100*i},{"image","pizza.png"},{"i", i},{"k",k},{"indexPos",pindex},{"tc","white"},{"bgdc","black"},{"boc","white"}});
    } else if (k==2) {  
      add_yaml("sc_product.yaml",{{"fname", 3500+100*i},{"fprice",3500+80+100*i},{"image","snacks.png"},{"i", i},{"k",k},{"indexPos",pindex},{"tc","white"},{"bgdc","black"},{"boc","white"}});
    } else if (k==3) {
      add_yaml("sc_product.yaml",{{"fname", 4500+100*i},{"fprice",4500+80+100*i},{"image","drinks.png"},{"i", i},{"k",k},{"indexPos",pindex},{"tc","white"},{"bgdc","black"},{"boc","white"}});
    } else {
      add_yaml("sc_product.yaml",{{"fname", 5500+100*i},{"fprice",5500+80+100*i},{"image","sweets.png"},{"i", i},{"k",k},{"indexPos",pindex},{"tc","white"},{"bgdc","black"},{"boc","white"}});
    }
  }
}
void display_cartnum(int num_items) {
  if (num_items<10) {
    char num_char = num_items;
    print_at(609,"{}",{num_char});
    print_at(610,")");//print_at(611,0);
  } else {
    char num_char1= num_items/10;
    char num_char2= num_items%10;
    print_at(609,"{}",{num_char1});
    print_at(610,"{}",{num_char2});
    print_at(611,")");//print_at(612,0);
  }
}
void handle_input() {//unfinished
  char c0 = get_char_at(650);
  if (c0=='n' || c0 == 'N') {
    cerr << "No" << "\n";
  } else {
    cerr << "Yes" << "\n";
  }
}
void readfile() {
  string line;
  const char* cline;
  ifstream f ("userinfo.txt");
  getline(f,line); cline = line.c_str(); print_at(720,cline); //username
  getline(f,line); cline = line.c_str(); print_at(740,cline); //pwd
  getline(f,line); cline = line.c_str(); print_at(1160,cline); //id
  getline(f,line); cline = line.c_str(); print_at(1045,cline); //address
  getline(f,line); cline = line.c_str(); print_at(1030,cline); //payment
  getline(f,line); cline = line.c_str(); print_at(1140,cline); //phone num
  f.close();
}
void plus_summary(int j, int quantity, float subtotal,float tax,float shipping,float total){
  if (j/10==1) {
    string price = global_mem+2500+100*(j%10)+81;
    subtotal+=strtof(price.c_str(),NULL)*quantity;
    put_float_at(9000,subtotal);
  } else if (j/10==2) {
    string price = global_mem+3500+100*(j%10)+81;
    subtotal+=strtof(price.c_str(),NULL)*quantity;
    put_float_at(9000,subtotal);
  } else if (j/10==3) {
    string price = global_mem+4500+100*(j%10)+81;
    subtotal+=strtof(price.c_str(),NULL)*quantity;
    put_float_at(9000,subtotal);
  } else {
    string price = global_mem+5500+100*(j%10)+81;
    subtotal+=strtof(price.c_str(),NULL)*quantity;
    put_float_at(9000,subtotal);
  }
  tax=subtotal*0.0688;
  total=subtotal+shipping+tax;
  put_float_at(9100,tax);
  put_float_at(9150,total);
}
void minus_summary(int j, int quantity, float subtotal,float tax,float shipping,float total){
  if (j/10==1) {
    string price = global_mem+2500+100*(j%10)+81;
    subtotal-=strtof(price.c_str(),NULL)*quantity;
    put_float_at(9000,subtotal);
  } else if (j/10==2) {
    string price = global_mem+3500+100*(j%10)+81;
    subtotal-=strtof(price.c_str(),NULL)*quantity;
    put_float_at(9000,subtotal);
  } else if (j/10==3) {
    string price = global_mem+4500+100*(j%10)+81;
    subtotal-=strtof(price.c_str(),NULL)*quantity;
    put_float_at(9000,subtotal);
  } else {
    string price = global_mem+5500+100*(j%10)+81;
    subtotal-=strtof(price.c_str(),NULL)*quantity;
    put_float_at(9000,subtotal);
  }
  tax=subtotal*0.0688;
  total=subtotal+shipping+tax;
  put_float_at(9100,tax);
  put_float_at(9150,total);
}
const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    return buf;
}
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
/*class Order{
    string time;
    string totalnum;
    string totalp;
    public:
        Order(string t, string tn, string tp) : time(t), totalnum(tn), totalp(tp) { //constructor
            //cout << name << info << price << "\n";  
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
};*/
/*class OrderContent : public Order {
  string name;
public:
  OrderContent(string t, string tn, string tp, string name) : Order(t,tn,tp), name(name) { }
  void print_content() { 
    cout << "Nachos: "; 
    print_takeout(); 
  }
};*/

int main() {
  init();
//variables:
  int numP=0;
  int numD=0;
  int numSw=0;
  int numSn=0;
  vector<int> order;
  vector<int> orderquant;
  char page; //switch btw pages
  unsigned int numitems; // shopping cart dispaly
  int mapindex; //to add map and write order info
  float subtotal;
  float shipping;
  float tax;
  float total;
  bool login = get_char_at(0);
  bool nightmode;

//create objects
  Food * fArr[MAX_ORDERS];
  for(int i = 0; i < MAX_MENU_ITEMS; i++){
    fArr[i] = 0; //initializes all members of fArr to 0
  }
  ifstream file("fstream1.txt");
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
    Food * f = new Food(FoodInfo[0],FoodInfo[1], FoodInfo[2], FoodInfo[3]);
    fArr[i++] = f; 
    delete [] FoodInfo;
  }
  i = 0;
  while(fArr[i] != 0){
    Food f = *fArr[i];
    string x = f.getSub();
    const char *y = (f.getName()).c_str();
    const char *z = (f.getPrice()).c_str();
    i++;
    if (x=="Snacks") {print_at(3500+numSn*100,y);print_at(3500+numSn*100+80,z);numSn++;}
    if (x=="Pizza") {print_at(2500+numP*100,y);print_at(2500+numP*100+80,z);numP++;}
    if (x=="Drinks") {print_at(4500+numD*100,y);print_at(4500+numD*100+80,z);numD++;}
    if (x=="Sweets") {print_at(5500+numSw*100,y);print_at(5500+numSw*100+80,z);numSw++;}
  }

//consts:
  write_const_texts();
//interactions:
  if (just_starting()) {
    numitems=0;
    put_int_at(1800,0); // where total numitems is
    mapindex = 0;
    put_int_at(1820,0); //where mapindex is
    put_float_at(9000,0);
    subtotal=0;//subtotal
    put_float_at(9050,0);
    shipping=0;//shipping
    put_float_at(9100,0);
    tax=subtotal*0.0688;//tax
    put_float_at(9150,0);
    total=subtotal+shipping+tax;//total
    global_mem[0]=0; //login status
    login = 0;
    put_char_at(1,1); //page name
    page=1;
    global_mem[2]=0; //login status
    nightmode=0;
    global_mem[3] = 0;
    print_at(1250, "Search");//initiate search
    print_at(1500, "Write down your comments here");//initiate comments
    print_at(840, "Hall Name/Northfield Address");
    initiate_inputs();
    if (exists_test("userinfo.txt")) readfile();
    else {
      print_at(1045,"None");
      print_at(1140,"None");
      print_at(1030,"cash");
    }
  } else if (received_event()) {
    numitems=get_int_at(1800);//reload num
    login=global_mem[0];//reload login
    nightmode=global_mem[2];//reload night mode
    mapindex = get_int_at(1820);
    subtotal = get_float_at(9000);//reload the subtotal
    shipping = get_float_at(9050);//reload the shipping
    tax = get_float_at(9100);//reload the tax
    total = get_float_at(9150);//reload the total
    for (int i = 0; i<mapindex; i++) {
      if (get_char_at(8000+i*20+5)!='~') {
        order.insert(order.begin() + i, get_int_at(8000+i*20+5)); //get j
        orderquant.insert(orderquant.begin() + i, get_int_at(8000+i*20+10)); //get quant
      }
    }
//handling id's 
    for (int i=1; i<9; i++) {
      if (event_id_is("p",i)) {
        put_char_at(1,i);
        page = global_mem[1];
        display_cartnum(numitems);
      }
    }
  if (event_id_is("night_mode")) {
    if (nightmode==0) put_char_at(2,1); else put_char_at(2,0);
    nightmode=global_mem[2];
    page=global_mem[1];
  } else if (event_id_is("contact_us")) {//unfinished
    page=global_mem[1];
  } else if (event_id_is("default_delivery")) {
    put_char_at(1,'a');
    page=global_mem[1];
  } else if (event_id_is("input_ad")) {
    if (global_mem[1045]!='~') cerr<< "Address is changed sucessfully!" << endl;
    print_at(1045,global_mem+840);
    page=global_mem[1];
  } else if (event_id_is("input_phone")) {
    cerr<< "Phone number is changed sucessfully!" << endl;
    print_at(1140,global_mem+1010);
    page=global_mem[1];
  } else if (event_id_is("cash")) {
    cerr<< "Payment is changed sucessfully!" << endl;
    print_at(1030,"cash");
    page=global_mem[1];
  } else if (event_id_is("ole")) {
    cerr<< "Payment changed sucessfully!" << endl;
    print_at(1030,"ole dollar");
    page=global_mem[1];
  } else if (event_id_is("auto_warning")) {//unfinished
    page=global_mem[1];
  } else if (event_id_is("order_history")) {//unfinished
    page=global_mem[1];
  } else if (event_id_is("favorite_order")) {//unfinished
    page=global_mem[1];
  } else if (event_id_is("place_order")) {
    if (numitems==0) cerr << "Cart is empty!" << endl;
    else if (login == 0) put_char_at(1,4); // go to login
    else if (strcmp(global_mem+1045,"None")==0||strcmp(global_mem+1140,"None")==0) put_char_at(1,'a');
    else {//read the order, clear the cart
      fstream f;
      f.open("userinfo.txt",ios::out | ios::app);
      f<< currentDateTime(); f<<" ";
      f<<numitems;f<<" ";
      f<<total;f<<"\n";
      for (int i = 0; i<mapindex; i++) {
        int j = get_int_at(8000+i*20+5); //iterating food codes
        int quant = get_int_at(8000+i*20+10);
        int ks = j/10; //seperating k and i.
        int is = j%10;
        string fname;
        float fprice=0;
        if (ks==1) {
          fname = global_mem+2500+100*is;
          string p = global_mem+2500+80+100*is+1;
          fprice = strtof(p.c_str(),NULL);
        } else if (ks==2) {  
          fname = global_mem+3500+100*is;
          string p = global_mem+3500+80+100*is+1;
          fprice = strtof(p.c_str(),NULL);
        } else if (ks==3) {
          fname = global_mem+4500+100*is;
          string p = global_mem+4500+80+100*is+1;
          fprice = strtof(p.c_str(),NULL);
        } else {
          fname = global_mem+5500+100*is;
          string p = global_mem+5500+80+100*is+1;
          fprice = strtof(p.c_str(),NULL);
        }
        float itemtotal = fprice*quant;
        f<<fname; f<<" ";
        f<<itemtotal; f<<" ";
        f<<quant; f<<"\n";
      }
      f.close();
      //empty cart
      for (int m = 0; m<mapindex; m++) {
        for (int i=0; i<40; i++) put_char_at(8000+m*20+i,'~');
      }
      order.clear();
      orderquant.clear();
      numitems=0;
      put_int_at(1800,0); // where total numitems is
      mapindex = 0;
      put_int_at(1820,0); //where mapindex is
      put_float_at(9000,0);
      subtotal=0;//subtotal
      put_float_at(9050,0);
      shipping=0;//shipping
      put_float_at(9100,0);
      tax=subtotal*0.0688;//tax
      put_float_at(9150,0);
      total=subtotal+shipping+tax;//total
      put_char_at(1,0);
    }
    display_cartnum(numitems);
    page = global_mem[1];
  } else if (event_id_is("search")) {
    handle_input();//unfinished
  } else if (event_id_is("comment")) {
    handle_input();//unfinished
    //login button
  } else if (event_id_is("input_name")||event_id_is("input_pw")||event_id_is("login")) {
    if (exists_test("userinfo.txt")) {
      if (strcmp(global_mem+720,global_mem+680)==0&&strcmp(global_mem+740,global_mem+700)==0) {
        put_char_at(0,'1');login=global_mem[0];
        page=global_mem[1];
        display_cartnum(numitems);
      } else {cerr << "Username or Password is incorrect!" << endl; page=global_mem[1];}
    } else {cerr << "Unknown user!"; page=global_mem[1];}
     //fake sign up button -- redirect to signup page
  } else if (event_id_is("sign_up")) {put_char_at(1,9); page=global_mem[1];}
    //real sign up button
    else if (event_id_is("create")||event_id_is("create_pw")||event_id_is("create_name")||event_id_is("create_id")) {
      if (exists_test("userinfo.txt")) {
        cerr << "Existing account!" << endl;
        global_mem[1] = 4;
        page = global_mem[1];
      } else if (global_mem[620]!=0&&global_mem[640]!=0&&global_mem[660]!=0) {
        char *username = global_mem+620;
        char *pwd = global_mem+640;
        char *id = global_mem+660;
        if (strlen(username)>=6 && strlen(pwd)>=6 && strlen(id) == 6) {
          print_at(720,username);
          print_at(740,pwd);
          print_at(1160,id);
          fstream f;
          f.open("userinfo.txt");
          f<<global_mem+720; f<<"\n";//username
          f<<global_mem+740; f<<"\n";//pwd
          f<<global_mem+1160; f<<"\n";//id
          f<<global_mem+1045;f<<"\n";//add
          f<<global_mem+1030;f<<"\n";//phone num
          f<<global_mem+1140;f<<"\n";//payment
          f.close();
          put_char_at(0,'1');login=global_mem[0];
          put_char_at(1,4);
          page=global_mem[1];
        } else cerr << "Incorrect length! \nUsername needs at least 6 characters \nPassword needs at least 6 characters \nID has 6 characters" << endl; page=global_mem[1];
      } else cerr << "Fill in all blanks" << endl; page=global_mem[1];
    } else {
      //adding and removing items
      for (int j = 10; j<45; j++) {
        if (event_id_is("add",j)) {
          numitems++;
          put_int_at(1800,numitems);
          display_cartnum(numitems);
          int tempi=0;
          int tempnum;
          cerr << "Cart has " << numitems << endl;
          while (tempi<mapindex) {
            if (order[tempi]==j) {
              tempnum = get_int_at(8000+tempi*20+10);
              tempnum++;
              put_int_at(8000+tempi*20+10, tempnum); //print num of this item
              break;
            }
            tempi++;
          } if (tempi==mapindex) { // new item to be added into the cart.
            mapindex++;
            put_int_at(1820,mapindex);//update mapindex
            put_int_at(8000+(mapindex-1)*20, mapindex);
            put_int_at(8000+(mapindex-1)*20+5, j);
            put_int_at(8000+(mapindex-1)*20+10,1);
          }
          plus_summary(j, 1, subtotal,tax,shipping,total);
          page=global_mem[1];
        }//picker
        if (event_id_is("pick",j)) {
          display_cartnum(numitems);
          int quantity = get_event_item_index()+1;
          int tempi;
          for (int i = 0;i<mapindex;i++) {
            if (order[i]==j) {
              tempi = i;
              break;
            }
          }
          int ori_quan = get_int_at(8000+tempi*20+10);
          if (quantity>ori_quan) {
            int delta_q = quantity - ori_quan;
            numitems+=delta_q;
            put_int_at(1800,numitems);
            display_cartnum(numitems);
            put_int_at(8000+tempi*20+10, quantity); //print num of this item
            plus_summary(j, delta_q, subtotal,tax,shipping,total);
          } else if (quantity<ori_quan) {
            int delta_q = ori_quan - quantity;
            numitems-=delta_q;
            put_int_at(1800,numitems);
            display_cartnum(numitems);
            put_int_at(8000+tempi*20+10, quantity); //print num of this item
            minus_summary(j, delta_q, subtotal,tax,shipping,total);
          }
        }
        page=global_mem[1];
        if (event_id_is("remove",j)) {
          int tempi;
          for (int i = 0;i<mapindex;i++) {
            if (order[i]==j) {
              tempi = i;
              break;
            }
          }
          minus_summary(j, orderquant[tempi], subtotal,tax,shipping,total);
          numitems-=orderquant[tempi];
          put_int_at(1800,numitems);
          display_cartnum(numitems);
          order.erase (order.begin()+tempi);
          orderquant.erase (orderquant.begin()+tempi);
          int m = 0, n=0;
          for (auto it : order) { //reprint the map
            put_int_at(8000+m*20,(m+1)); //put j
            put_int_at(8000+m*20+5,it); //put j
            m++;
          }
          for (auto it : orderquant) { //reprint the map
            put_int_at(8000+n*20+10,it); //put j
            n++;
          }
          for (int i=0; i<40; i++) put_char_at(8000+m*20+i,'~');
          mapindex-=1;
          put_int_at(1820,mapindex);
          page=global_mem[1];
        }
      }
    }
  }
//adding yamls
  if (nightmode==0) add_yaml("bgdt.yaml",{{"bgdtc","white"},{"tc","black"},{"svc","\"#d0d7e1\""}});
  else add_yaml("bgdt.yaml",{{"bgdtc","black"},{"tc","white"},{"svc","\"#575757\""}});
  //after title
  if (1 == page) {
    add_yaml("search_bar.yaml");add_yaml("home.yaml");
  } else if (2== page) {
    if (nightmode==0) add_yaml("setting.yaml",{{"nightmode_index",240},{"tc","black"},{"bc","white"}});
    else add_yaml("setting.yaml",{{"nightmode_index",230},{"tc","white"},{"bc","black"}});
  }
  else if (3 == page) {
    if (nightmode==0) add_yaml("shopping.yaml",{{"tc","black"}});
    else add_yaml("shopping.yaml",{{"tc","white"}});
    for (int i = 0; i<mapindex; i++) {
      int j = get_int_at(8000+i*20+5); //iterating food codes
      char quan = get_int_at(8000+i*20+10)-1;
      print_at(8000+i*20+15,"{}",{quan});
      int pindex = 8000+i*20+15;
      int ks = j/10; //seperating k and i.
      int is = j%10;
      display_items(is,ks,nightmode,pindex);
    }
    subtotal = get_float_at(9000);
    shipping = get_float_at(9050);
    tax = get_float_at(9100);
    total = get_float_at(9150);
    print_at(9500,ftos(subtotal));
    print_at(9550,ftos(shipping));
    print_at(9600,ftos(tax));
    print_at(9650,ftos(total));
    if (nightmode==0) add_yaml("summary.yaml",{{"tc","black"},{"bgdc","white"},{"boc","black"}});
    else add_yaml("summary.yaml",{{"tc","white"},{"bgdc","black"},{"boc","white"}});
  } else if (4 == page) {
    if (login == 0) {
      if (nightmode==0) add_yaml("login.yaml",{{"tc","black"},{"bgdc","white"},{"boc","black"}});
      else add_yaml("login.yaml",{{"tc","white"},{"bgdc","black"},{"boc","white"}});
    } else {
      if (nightmode==0) add_yaml("profile.yaml",{{"tc","black"},{"bgdc","white"},{"boc","black"}});
      else add_yaml("profile.yaml",{{"tc","white"},{"bgdc","black"},{"boc","white"}});
    }
  } else if (5 == page) {
    add_yaml("search_bar.yaml");
    display_food(2,numSn,nightmode);
  } else if (6== page) {
    add_yaml("search_bar.yaml");
    display_food(1,numP,nightmode);
  } else if (7 == page) {
    add_yaml("search_bar.yaml");
    display_food(3,numD,nightmode);  
  } else if (8 == page) {
    add_yaml("search_bar.yaml");
    display_food(4,numSw,nightmode);
  } else if (9 == page) {
    if (nightmode==0) add_yaml("signup.yaml",{{"tc","black"},{"bgdc","white"},{"boc","black"}});
    else add_yaml("signup.yaml",{{"tc","white"},{"bgdc","black"},{"boc","white"}});
  } else if (0 == page) {
    if (login == 0) {
      if (nightmode==0) add_yaml("login.yaml",{{"tc","black"},{"bgdc","white"},{"boc","black"}});
      else add_yaml("login.yaml",{{"tc","white"},{"bgdc","black"},{"boc","white"}});
    } else {if (nightmode==0) add_yaml("orderplaced.yaml",{{"tc","black"},{"bgdc","white"}});
      else add_yaml("orderplaced.yaml",{{"tc","white"},{"bgdc","black"}});
    }
  } else if ('a' == page) {
    if (nightmode==0) {
      string payment = global_mem+1030;
      if (payment=="cash") add_yaml("default.yaml",{{"tc","black"},{"bgdc","white"},{"boc","black"},{"btc1","\"#B592A6\""},{"btc2","\"#c9abbc\""}});
      else add_yaml("default.yaml",{{"tc","black"},{"bgdc","white"},{"boc","black"},{"btc1","\"#c9abbc\""},{"btc2","\"#B592A6\""}});
    }
    else {
      string payment = global_mem+1030;
      if (payment=="cash") add_yaml("default.yaml",{{"tc","white"},{"bgdc","black"},{"boc","white"},{"btc1","\"#B592A6\""},{"btc2","\"#c9abbc\""}});
      else add_yaml("default.yaml",{{"tc","white"},{"bgdc","black"},{"boc","white"},{"btc1","\"#c9abbc\""},{"btc2","\"#B592A6\""}});
    }
  }
  
  if (nightmode==0) add_yaml("bgdb0.yaml");
  else add_yaml("bgdb1.yaml");

  if (login == 1) {//rewrite the userfile
    string *lines = new string[1000];
    string iterator;
    int i=0;
    fstream f;
    f.open("userinfo.txt",ios::in);
    while (getline(f,iterator)) {
      lines[i]=iterator;//read the lines into c++ strings for each line.
      i++;
    }
    f.close();
    f.open("userinfo.txt",ios::out);
    //updating the userinfo
    f<<global_mem+720; f<<"\n";//username
    f<<global_mem+740; f<<"\n";//pwd
    f<<global_mem+1160; f<<"\n";//id
    f<<global_mem+1045;f<<"\n"; //address
    f<<global_mem+1030;f<<"\n"; //payment
    f<<global_mem+1140;f<<"\n"; //phone num
    
    //rewrite the order in
    for (int t=6; t<i; t++) {
      f<<lines[t]; f<<"\n";
    }
    f.close();
  }
  quit();
}
