#include<vector>

class CustomVector{
  std::vector<int> a;
  std::vector<int> b;

public:
  CustomVector(){
    a = {1,2,3,5,6};
    b = {1,2,4,5,7};
  }

  std::vector<int> getA(){ return a;};
  std::vector<int> getB(){ return b;};

};