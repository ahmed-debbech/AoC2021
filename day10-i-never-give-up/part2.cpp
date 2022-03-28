#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iterator>
#include <stack>
#include <vector>
#include <list>
#include <bits/stdc++.h>
#define MAX 98

using namespace std;

list<string> file_reader(){
    FILE * f = fopen("input", "r");
    if(f != NULL){
        list<string> lines;
    
        char line[1000];
        while (feof(f) == 0) {
            //printf("1: %s", line);
            fgets(line, 1000, f);
            string s(line);
            lines.push_back(s);
        }
        fclose(f);   
        return lines;
    }
    return list<string>();
}
int oneOfClosings(char c, char poss[]){
    if((poss[1] == c) || (poss[3] == c) || (poss[5] == c) ||
    (poss[7] == c)){
        return 1;
    }
    return 0;
}
int isEqual(char c, char j, char poss[]){
    for(int i=1; i<=7; i+=2){
        if(poss[i] == c){
            if(poss[i-1] == j){
                return 1;
            }
        }
    }
    return 0;
}
unsigned long int closeCharScore(char openning){
    unsigned long int sc = 0;
    switch(openning){
        case '(':
        sc = 1;
        break;
        case '[':
        sc = 2;
        break;
        case '{':
        sc = 3;
        break;
        case '<':
        sc = 4;
        break;
    }
    return sc;
}
int main(){    
    std::cout << "Hello world!" << std::endl;
    
    char possible_chars[8];
    possible_chars[0] = '(';
    possible_chars[1] = ')';
    possible_chars[2] = '[';
    possible_chars[3] = ']';
    possible_chars[4] = '{';
    possible_chars[5] = '}';
    possible_chars[6] = '<';
    possible_chars[7] = '>'; 

    int times_errors[4];
    times_errors[0] = 0;
    times_errors[1] = 0;
    times_errors[2] = 0;
    times_errors[3] = 0;

    list<string> lines;

    lines = file_reader();

    if(!lines.empty()){
        int i=0;
        std::list<std::string>::iterator it = lines.begin();
        int j=0;
        it = lines.begin();
        vector<unsigned long int> scores;
        for(i=0; i<MAX; i++){
            std::stack<char> stack;
            bool hasError = false;
            for(j=0; j<=(*it).size()-1; j++){
                if(oneOfClosings((*it)[j], possible_chars) == 1){
                    if(stack.empty()){
                        return 0;
                    }else{
                        if(isEqual((*it)[j], stack.top(), possible_chars) == 1){
                            stack.pop();
                        }else{
                            printf("*** ERR FOUND ***\n");
                            hasError = true;
                            break;
                        }
                    }
                }else{
                    stack.push((*it)[j]);
                }
            }
            if(!hasError){
                cout << "no error" << endl;
                unsigned long int sco = 0;
                while(!stack.empty()){
                    sco = (sco * 5) + closeCharScore(stack.top());
                    stack.pop();
                }
                cout << "final score: " << sco << endl; 
                scores.push_back(sco);
            }
            std::advance(it, 1);
        }
        sort(scores.begin(), scores.end());
    
        cout << "THE RESULT: " << scores[scores.size()/2] << endl;
    }
    return 0;
}