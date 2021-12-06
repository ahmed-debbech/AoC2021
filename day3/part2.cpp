#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


vector<string> readFile(){
    ifstream file("input");
    string text;
    vector<string> array;
    int i=0;
    while(getline(file, text)){
        //cout << text << endl;
        array.push_back(text);
    }
    file.close();
    return array;
}

void remove(vector<string> & arr, char str, int pos){
  for (auto i = arr.cbegin(); i != arr.cend(); ++i){
      if((*i)[pos] == str){
        arr.erase(i);
        i--;
      }
  }
}
string getLife(vector<string> arr, int position, int mode){
    int occ1 = 0; int occ0 = 0;
    if(arr.size() == 1){
      return arr[0];
    }
    for (auto i = arr.cbegin(); i != arr.cend(); ++i){
        if((*i)[position] == '1') occ1++; 
        else occ0++;
    }
    if(mode == 1){
      if(occ1 >= occ0){
        remove(arr, '0', position);
      }else{      
        remove(arr, '1', position);
      }
    }else{
      if(occ1 >= occ0){
        remove(arr, '1', position);
      }else{      
        remove(arr, '0', position);
      }

    }
    position++;
    return getLife(arr, position, mode);
}

int binaryToDecimal(string n)
{
    string num = n;
    int dec_value = 0;
 
    // Initializing base value to 1, i.e 2^0
    int base = 1;
 
    int len = num.length();
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
 
    return dec_value;
}

int main(){
    std::cout << "Hello AoC2021" << endl;
    vector<string> arr = readFile();

    string oxy = getLife(arr, 0, 1);
    cout <<"OXY: " <<  oxy << endl;

    string co = getLife(arr, 0, 0);
    cout <<"CO2: " <<  co << endl;

    cout << "RESULT: " << binaryToDecimal(co) * binaryToDecimal(oxy) << endl;
    return 0;
}

