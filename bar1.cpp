#include"../react.h"
  
int main() {
  init();
  print_at(1, "Aesthetic Alpacas");
  print_at(20, "Search");
  print_at(100, "food_name");
  print_at (200, "price");
  print_at (300, "pre-made");
  print_at (400, "delivery");
  add_yaml("bgdt.yaml");
  add_yaml("u_buyfood.yaml",{{"fname_index", 100},{"fprice_index", 200}});
  add_yaml("bgdb.yaml");
  quit();
}
