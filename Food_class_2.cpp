#include<iostream>
using namespace std;

class Food {
    public:
    float price;
    char* name;
    int id;
    int calories;
    bool availability;
    int catagory; // for displaying on menue
    int name_len;
    char *request;
    int request_len;


//constructor
    Food(float p, char *n, int i, int c, bool a, int t, char *r = "1"){ 
        price = p;
        id = i;
        calories = c;
        availability = a;
        catagory = t;
        name_len = 0;
        while(n[name_len] != 0) {
            name_len++;
        }
        name_len++;
        name = new char[name_len];
        for(int i = 0; i < name_len; i++){
            name[i] = n[i];
        }
        request_len = 0;
        while(r[request_len] != 0) {request_len++;}
        request_len++;
        request = new char[request_len];
        for(int i = 0; i <request_len; i++) {
            request[i] = r[i];
        }
    }
    // copy constructor
    Food(const Food &f) {
        price = f.price;
        id = f.id;
        calories = f.calories;
        availability = f.availability;
        catagory = f.catagory;
        name_len = f.name_len;
        request_len = f.request_len;
        name = new char[name_len]; 
        for(int i = 0; i < name_len; i++) {
            name[i] = f.name[i];
        }
        request = new char[request_len];
        for(int i = 0; i < request_len; i++) {
            request[i] = f.request[i];
        }
    }
    // destructor
    ~Food() {
        cout << "food destroyed" << endl;
        delete[] name;
        delete[] request; 
    }

    // accesor methods
    void food_display(){
        cout << price << ' ' << id << ' ' << name << ' ' << calories << ' ' << availability << ' ';
        cout << catagory << ' ' << name_len << ' ' << request << endl;
    }
    //I made all the variables public so that we do not need lots of mutators and accesors 
    // mutator methods  
    void change_availability(bool a){
        availability = a;
    }

    void change_price(float p) {
        price = p;
    }
    
    void add_request(char *r) {
        delete [] request;
        request_len = 0;
        while(r[request_len] != 0) {request_len++;}
        request_len++;
        request = new char[request_len];
        for(int i = 0; i <request_len; i++) {
            request[i] = r[i];
        }
        
    }

};
class Pizza: public Food {
public:
    bool is_large;
    char *toppings;
    int toppings_size;
    


// constructor
    Pizza(float p, char *n, int i, int c, bool a, int t, bool l, char *top): Food(p, n, i, c, a, t){
        is_large = l;
        toppings_size = 0;
        while(top[toppings_size] != 0) {toppings_size++;}
        toppings_size++;
        toppings = new char[toppings_size];
        for(int i = 0; i < toppings_size; i++) {
            toppings[i] = top[i];
        }
     } 
// copy constructor 
    Pizza(const Pizza &p):Food(p) {
        is_large = p.is_large;
        toppings_size = p.toppings_size;
        toppings = new char[toppings_size];
        for(int i = 0; i < toppings_size; i++) {
            toppings[i] = p.toppings[i];
        }
        
    }
// destructor
    ~Pizza() {
        cout << "pizza destroyed." << endl;
        delete [] toppings;
    }
    void make_small() {
        is_large = false;
    }
    void make_large() {
        is_large = true;
    }

    char* get_toppings() {
        return toppings;
    }

    void display_toppings(){
        cout << is_large << endl;
        cout << toppings << endl;
        cout << toppings_size << endl;
    }
    void add_topping(char *top){
        int len = 0;
        while(top[len] != 0) {len++;}
        char *temp = new char[toppings_size];
        for(int i = 0; i < toppings_size; i++) {
            temp[i] = toppings[i];
        }
        delete [] toppings; 
        toppings = new char[len+toppings_size-1];// the -1 is for the null space
        for(int i = 0; i < toppings_size -1; i++){
            toppings[i] = temp[i];
        }
        for(int i = 0; i < len; i++) {
            toppings[i+toppings_size-1] = top[i];
        }
        toppings_size = toppings_size + len -1;
    }
    void clear_toppings() {
        delete [] toppings;
        toppings_size = 1;
        toppings = new char[1];
        toppings[0] = 0;
    }
        


};

int main() {
    float price = 9.99;
    char *name;
    name = new char[3];
    name[0] = 'Z';
    name[1] = 'a';
    name[2] = 0; 
    int id = 937;
    int calories = 99;
    bool availability = true;
    int catagory = 1;
    bool is_large = true;
    char *toppings;
    toppings = new char[4];
    toppings[0] = 'C';
    toppings[1] = 'h';
    toppings[2] = 'z';
    toppings[3] = 0;
    Pizza P1{price, name, id, calories, availability, catagory, is_large, toppings};
    P1.food_display();
    P1.display_toppings();
    Pizza P2 = P1;
    P2.food_display();
    P2.display_toppings();
    cout << P2.id << endl;
    P2.id = 709;
    cout << P2.id << endl;
    P2.clear_toppings();
    P2.add_request("no cheese");
    P2.add_topping("pep and sausage");
    cout << P2.request << ' ' << P2.toppings << endl;

}