#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iterator>
#include <stack>
#include <vector>
#include <list>
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
        /*for(i=0; i<MAX; i++){
            cout << *it << endl;
            std::advance(it, 1);
        }*/
        int j=0;
        it = lines.begin();
        vector<int> errors = {0, 0, 0, 0};
        for(i=0; i<MAX; i++){
            printf("\n\n");
            printf("A NEW LINEEEE\n");
            std::stack<char> stack;
            for(j=0; j<=(*it).size()-1; j++){
                if(oneOfClosings((*it)[j], possible_chars) == 1){
                    printf("%c is one of the closings\n", (*it)[j]);
                    if(stack.empty()){
                        printf("started with null :(");
                        return 0;
                    }else{
                        if(isEqual((*it)[j], stack.top(), possible_chars) == 1){
                            printf("+ a chunk has been closed\n");
                            stack.pop();
                        }else{
                            printf("*** ERR FOUND ***\n");
                            switch((*it)[j]){
                                case ')':
                                    errors[0]++;
                                break;
                                case ']':
                                    errors[1]++;
                                break;
                                case '}':
                                    errors[2]++;
                                break;
                                case '>':
                                    errors[3]++;
                                break;
                            }
                            break;
                        }
                    }
                }else{
                    printf("%c is one of the opennings\n", (*it)[j]);
                    /*m = (node*) malloc(sizeof(node));
                    m->ch = lines[i][j];
                    if(stack_head == NULL){
                        m->next = NULL;
                    }else{
                        m->next = *stack_head;
                    }
                    stack_head = &m;
                    printf("node : %c | %p\n", (*stack_head)->ch, (*stack_head)->next);
                    show(stack_head);*/
                    stack.push((*it)[j]);
                }
                printf("&&&&&&&&&&&&&\n\n");
            }
            std::advance(it, 1);
        }

        //count the errors
        unsigned long int sum = 0;
        cout << errors[0] << " " << errors[1] << " " <<  errors[2] << " " << errors[3] << endl;
        sum += (errors[0] * 3);
        sum += (errors[1] * 57);
        sum += (errors[2] * 1197);
        sum += (errors[3] * 25137);

        cout << "THE RESULT: " << sum << endl;
    }
    return 0;
}