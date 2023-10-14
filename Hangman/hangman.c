#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<string.h>

char words[100][100] = {"apple","banana","table","chair","pen","jackfruit"};
int tries = 0;
int foundword = 0;
int gameOver = 0;
int v[26];


void print(char *msg, int topBorder,int border);
void drawMan();
void drawGuessWord();
void drawAvailableAlphabets();
void input();

void charcat(char *msg,char *alphabet);

int main(){
    srand(time(0));
    char *word = words[rand()%6];
    while(!gameOver){
        system("cls");
        print("HangMan",1,1);
        drawMan();
        print("Available Alphabets",1,0);
        drawAvailableAlphabets();
        drawGuessWord(word);

        if(tries == 5){
            gameOver = 1;
            print("Man Hanged!",0,1);
            printf("The Word Was %s\n",word);
        }
        else if(foundword == strlen(word)){
            print("YOU HAVE WON!",0,1);
            gameOver = 1;
        }
        if(!gameOver){
            printf("Make Sure to Turn CapsLock off\n");
            input(word);
        }
    }
    return 0;
}

void print(char *msg, int Topborder,int border){
    int center_msg_index = (31-strlen(msg))/2 +1;
    if(Topborder)
        printf("+------------------------------+\n");
    for(int i = 0; i < 33; i++){
        if(i == 0 || i == 32)
            printf("|");
        else{
            if(i >= center_msg_index && i <= center_msg_index+strlen(msg))
                printf("%c",msg[i-center_msg_index]);
            else
                printf(" ");
        }
    }
    printf("\n");
    if(border)
        printf("+------------------------------+\n");
}
void drawMan() {
    if (tries == 0) {
        print("", 0, 0);
        print("", 0, 0);
        print("", 0, 0);
        print("", 0, 0);
        print("", 0, 0);
    } else if (tries == 1) {
        print("|", 0, 0);
        print("|", 0, 0);
        print("", 0, 0);
        print("", 0, 0);
        print("", 0, 0);
    } else if (tries == 2) {
        print("|", 0, 0);
        print("|", 0, 0);
        print("O", 0, 0);
        print("", 0, 0);
        print("", 0, 0);
    } else if (tries == 3) {
        print("|", 0, 0);
        print("|", 0, 0);
        print("O", 0, 0);
        print("|", 0, 0);
        print("", 0, 0);
    } else if (tries == 4) {
        print("|", 0, 0);
        print("|", 0, 0);
        print("O", 0, 0);
        print("/|\\", 0,0);
        print("", 0,0);
    } else if (tries ==5){
        print("|", 0,0);
        print("|", 0,0);
        print("O", 0,0);
        print("/|\\", 0,0);
        print("/ \\", 0,0);
    }
}
void drawGuessWord(char *word){
    char msg[100] = "";
    for(int i = 0;i < strlen(word); i++){
        if(v[word[i]-'a'] == 0)
            strcat(msg, "_");
        else{
            char temp[2] = {word[i],'\0'};
            strcat(msg,temp);
        }
        if(i != (strlen(word)-1))
            strcat(msg, " ");
    }
    print(msg,0,1);

}


void drawAvailableAlphabets(){
    char msg[100] = "";
    for(int i = 0; i < 26; i++){
        char alphabet = i+97;
        if(!v[i]){
            charcat(msg, alphabet);
            if(i != 12 && i != 25){
                strcat(msg, " ");
            }
        }
        else{
            strcat(msg, " ");
            if(i != 12 && i != 25){
                strcat(msg, " ");
            }
        }
        if(i == 12){
            print(msg,1,0);
            strcpy(msg, "");
        }
        else if(i == 25){
            print(msg,0,1);
            strcpy(msg,"");

        }
    }
}

void input(char* word) {
    char input = getch();
    int found = 0;
    for(int i = 0; i < strlen(word); i++) {
        if (word[i] == input) {
            found = 1;
            if (v[word[i] - 'A'] == 0)
                foundword++;
        }
    }
    if (found == 0)
        tries++;
    v[input - 'a'] = 1;
}

void charcat(char *msg,char *alphabet){
    char temp[2] = {alphabet,'\0'};
    strcat(msg,temp);
}
