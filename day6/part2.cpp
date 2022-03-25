#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

int main(){

    ifstream file("input");
    string st;
    getline(file, st);
    file.close();
    //cout << st << endl;
    map<int, int> arr;
    arr.insert(pair<int, int>(0, 0));
    arr.insert(pair<int, int>(1, 0));
    arr.insert(pair<int, int>(2, 0));
    arr.insert(pair<int, int>(3, 0));
    arr.insert(pair<int, int>(4, 0));
    arr.insert(pair<int, int>(5, 0));
    arr.insert(pair<int, int>(6, 0));
    arr.insert(pair<int, int>(7, 0));
    arr.insert(pair<int, int>(8, 0));

    for(int i=0; i<=8; i++) cout << arr.find(i)->first << "," << arr.find(i)->second << "|"; cout << endl;

    for(int i=0; i<=st.size()-1; i++){
        if((st[i] >= '0') && (st[i] <= '9')){
            int ff = st[i] - '0';
            arr.find(ff)->second++;     
        }
    }
    cout << "Initial state: " ;
    for(int i=0; i<=8; i++) cout << arr.find(i)->first << "," << arr.find(i)->second << "|"; cout << endl;
   
    for(int u=1; u<=3; u++){
        if(arr.find(8)->second != 0){
            arr.find(6)->second = arr.find(6)->second + arr.find(0)->second;
        }
        for(int i=1; i<=8; i++){
            //int sum = arr.find(i-1)->second + arr.find(i)->second;
            if(i==6 && arr.find(0)->second != 0){
                i++;
            }
            arr.find(i-1)->second = arr.find(i)->second;
            cout << arr.find(i)->first << "," << arr.find(i)->second << "|";
        }    
        if(arr.find(0)->second != 0){
            arr.find(8)->second = arr.find(8)->second + arr.find(0)->second;
        }
    
        cout << endl;
        cout << endl;
    }
    //cout << "RESULT: " << arr.size() << endl; 
        for(int i=0; i<=8; i++) cout << arr.find(i)->first << "," << arr.find(i)->second << "|"; cout << endl;

    return 0;
}