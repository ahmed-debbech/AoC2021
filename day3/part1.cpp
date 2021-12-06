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

string getGamma(vector<string> array){
    string gamma = "";
    for(int j=0; j<=11; j++){
        int occ1 = 0;
        int occ0 = 0;
        for (auto i = array.cbegin(); i != array.cend(); ++i){
            if((*i)[j] == '1') occ1++; 
            else occ0++;
        }
        cout << occ1 << " " << occ0 << endl;
        if(occ1 > occ0){
            gamma = gamma + "1";
        }else{      
            gamma = gamma + "0";
        }
    }
    return gamma;
}

string getEpsilon(string gamma){
    string epsilon = "";
    for(int i=0; i<= gamma.length()-1; i++){
        if(gamma[i] == '1'){
            epsilon = epsilon + "0";
        }else{
            epsilon = epsilon + "1";
        }
    }
    return epsilon;
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
    vector<string> array = readFile();
    
    string gamma = getGamma(array);
    cout << gamma << endl;

    string epsilon = getEpsilon(gamma);
    cout << epsilon << endl;

    int gammadec = binaryToDecimal(gamma);
    int epsilondec = binaryToDecimal(epsilon);
    cout << gammadec << " " << epsilondec << endl;

    cout << "RESULT: " << epsilondec * gammadec << endl;
    return 0;
}
