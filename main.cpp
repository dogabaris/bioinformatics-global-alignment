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
  vector<vector<char> > matrix;
  vector<vector<char> > yonler;

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
          break;
        }

        sayac++;
      }
      oku.close();
    }
  else{
    cout << "input.txt is missing."<<endl;
  }
  oku.close();

  matrix.resize(dna2.size()+2);//yukseklik dna2 genişlik dna1
    for (int i = 0; i < dna2.size()+2; ++i)
      matrix[i].resize(dna1.size()+1);

  yonler.resize(dna2.size()+2);//yukseklik dna2 genişlik dna1
    for (int i = 0; i < dna2.size()+2; ++i)
      yonler[i].resize(dna1.size()+1);

  for(int i=2;i<dna1.size()+2;i++){
      matrix[0][i]=dna1[i-2];
  }

  for(int k=2;k<dna2.size()+2;k++){
      matrix[k][0]=dna2[k-2];
  }

  for(int i = 0; i < dna2.size()+2; i++){
        for(int j = 0; j < dna1.size()+2; j++){
           //matrix[i][j]  = (iFile >> value,value);
           cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

  return 0;
}

/*int matrixOlustur(dna1,dna2){

}*/
