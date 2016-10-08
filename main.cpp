#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

//yollar matrisi
//tablo matrisi
//tablo doldurulurken yollar matrisine olası yollar eklenecek
//sağ en alttan başlanıp olası yollara göre high road low road ve

int main() {
  ifstream oku;
  oku.open("input.txt");
  string satir,match,mismatch,gap,road,dna1,dna2;
  int sayac=0;

  if (oku.is_open())
    {
      while ( getline(oku, satir) )
      {
        istringstream ss(satir);

        if(sayac==0){
            ss >> match >> mismatch >> gap >> road;
            cout << match << " " << mismatch << " " << gap << " " << road <<endl;

        }else if(sayac==1){
          ss >> dna1;
          cout<< dna1 <<endl;

        }else if(sayac==2){
          ss >> dna2;
          cout<< dna2 <<endl;
        }

        sayac++;
      }
      oku.close();
    }
  else{
    cout << "input.txt is missing."<<endl;
  }
  oku.close();

  return 0;
}

/*int matrixOlustur(dna1,dna2){

}*/
