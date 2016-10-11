#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

//yollar matrisi
//tablo matrisi
//tablo doldurulurken yollar matrisine olası yollar eklenecek
//sağ en alttan başlanıp olası yollara göre high road low road ve
//diagonal giderken(çapraz) match-mismatch eklenir, sağdan ya da soldan giderken gap penalty eklenir. En büyük değer yazılır.

int StringToInt( const std::string& st)
{
    int retVal;
    for_each(st.begin(), st.end(), [&retVal] (const char& ch){ retVal = (retVal * 10) + (int)(ch-'0'); });
    return retVal;
}

int main() {
  ifstream oku;
  oku.open("input.txt");
  string satir,dna1,dna2;
  int match,mismatch,gap,road;
  int sayac=0;
  vector<vector<int>> matrix;
  vector<vector<int>> yonler;

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

  matrix[1][1]=0;

  for(int i=2;i<dna1.size()+2;i++){//satır - genişlik
      matrix[0][i]=dna1[i-2];
      matrix[1][i]=matrix[1][i-1]+gap;
  }
  for(int k=2;k<dna2.size()+2;k++){//sütun yükseklik
      matrix[k][0]=dna2[k-2];
      matrix[k][1]=matrix[k-1][1]+gap;
  }
//diagonal gel satir ve sütundan 1 er eksik.üstten columdan 1 eksik.yandan rowdan 1 eksik.
  int tmpdiag,tmpup,tmpright;
  for(int r=2;r<dna2.size()+2;r++){//row ,2
    for(int c=2;c<dna1.size()+2;c++){//column
      if(matrix[0][c]==matrix[r][0])
        tmpdiag=match+matrix[r-1][c-1];

      else
        tmpdiag=mismatch+matrix[r-1][c-1];

        tmpup=gap+matrix[r-1][c];
        tmpright=gap+matrix[r][c-1];

        int biggest = tmpdiag;

        if (tmpdiag <= tmpup)
              biggest = tmpup;
        if (biggest <= tmpright)
              biggest = tmpright;

        matrix[r][c]=biggest;
    }
  }

  for(int i = 0; i < dna2.size()+2; i++){//matrisi çizdiriyor
        for(int j = 0; j < dna1.size()+2; j++){
          //if(i==1 && j=1)
          //  cout << matrix[i][j] << " ";
          //else
            cout << matrix[i][j] << " ";
        }
        cout << endl;
  }

  return 0;
}

/*int matrixOlustur(dna1,dna2){

}*/
