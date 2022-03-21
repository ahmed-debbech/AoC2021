#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 10

char** file_reader(){
    FILE * f = fopen("input", "r");
    if(f != NULL){
        char ** g = malloc(sizeof(char*) * MAX);
        char * m = NULL;
        char line[256];
        
        int k=0;
        while (fgets(line, sizeof(line), f)) {
            //printf("1: %s", line);
            m = malloc(sizeof(char) * 256);
            strcpy(m, line);
            g[k] = m;
            k++;
        }
        fclose(f);   
        return g;
    }
    return NULL;
}

typedef struct node{
    char ch;
    struct node * next;
}node;

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

void show(node ** stack){
    node * holder = *stack;
    //printf("ras func %p\n", holder);
    if(holder == NULL){
        printf("THE STACK IS EMPTY");
    }else{
        int i=0;
        while(holder != NULL && i != 3){
            printf("-> %c : %p\n", holder->ch, holder);
            holder = holder->next;
            i++;
        }
    }
}
node* newNode(char data){
    node* stackNode = (node*) malloc(sizeof(node));
    stackNode->ch = data;
    stackNode->next = NULL;
    return stackNode;
}
 
int isEmpty(node* root)
{
    return !root;
}
 
void push(node*** root, char data)
{
    node* stackNode = newNode(data);
    if(**root != NULL){
        stackNode->next = **root;
        printf("node : %c | %p\n", (**root)->ch, (**root)->next);
        **root = stackNode;
    }else{
        *root = &stackNode;
    }
    printf("%d pushed to stack\n", data);
}
 
char pop(node** root)
{
    if (isEmpty(*root)) return 0;
    node* temp = *root;
    *root = (*root)->next;
    char popped = temp->ch;
    free(temp);
 
    return popped;
}
int main(){
    printf("Hello World!");

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

    char** lines;

    lines = file_reader();
    if(lines != NULL){
        int i=0;
        /*for(i=0; i<98; i++){
            printf("%d: %s\n",i+1, lines[i]);
        }*/
        int j=0;
        for(i=0; i<MAX; i++){
            printf("\n\n");
            printf("A NEW LINEEEE\n");
            node ** stack_head = NULL;
            node * m= NULL;
            node ** holder = NULL;
            for(j=0; j<=strlen(lines[i])-2; j++){
                if(stack_head != NULL) printf("TOP STACK: %c\n", (*stack_head)->ch );
                if(oneOfClosings(lines[i][j], possible_chars) == 1){
                    printf("%c is one of the closings\n", lines[i][j]);
                    if(stack_head == NULL){
                        printf("started with null :(");
                        return 0;
                    }else{
                        if(isEqual(lines[i][j], (*stack_head)->ch, possible_chars) == 1){
                            printf("+ a chunk has been closed\n");
                            /*node * holder1 = *stack_head;
                            stack_head = &(holder1->next);
                            free(holder1);*/
                            pop(stack_head);
                        }else{
                            printf("*** ERR FOUND ***\n");
                        }
                    }
                }else{
                    printf("%c is one of the opennings\n", lines[i][j]);
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
                    push(&stack_head, lines[i][j]);
                }
                printf("&&&&&&&&&&&&&\n\n");
            }
            break;
        }

    }

    return 0;
}