#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){

    ifstream file("input");
    string st;
    getline(file, st);
    file.close();
    //cout << st << endl;
    vector<int> arr;
    for(int i=0; i<=st.size()-1; i++){
        if((st[i] >= '0') && (st[i] <= '9')){
            int ff = st[i] - '0';
            arr.push_back(ff);
        }
    }
    cout << "Initial state: " ;
    for(int i=0; i<=arr.size()-1; i++) cout << arr[i] << ","; cout << endl;

    int d=0;
    for(int u=1; u<=80; u++){
    
        int siz = arr.size()-1;
        for(int i=0; i<=siz; i++){
            if(arr[i] == 0){
                arr[i] = 6;
                arr.push_back(8);
            }else{
                arr[i]--;
            }
        }        
        cout << "After " << u << " days" << endl;
        for(int i=0; i<=arr.size()-1; i++) cout << arr[i] << ","; cout << endl;
    }
    cout << "RESULT: " << arr.size() << endl; 
    return 0;
}