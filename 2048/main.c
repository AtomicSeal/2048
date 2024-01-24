//
//  main.c
//  2048
//
//  Created by AtomicSeal on 23/01/2024.
//


//Switch to curses

#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <time.h>

int GAME_STATE=1;

void playermove(char direction,int* board){
    switch (direction) {
        case 's':
            for (int j=0;j<3;j++){
                for (int i=15;i>=0;i--){
                    if(i+4<=15 && board[i+4]==0){
                        board[i+4]=board[i];
                        board[i]=0;
                    }
                    else if(i+4<=15 && board[i+4]==board[i]){
                        board[i+4]=board[i]*2;
                        board[i]=0;
                        
                    }
                }
            }
            break;
        case 'w':
            for(int i=0;i<3;i++){
                for(int j=0;j<16;j++){
                    if(j-4>=0 && board[j-4]==0){
                        board[j-4]=board[j];
                        board[j]=0;
                    }
                    else if(j-4>=0 && board[j-4]==board[j]){
                        board[j-4]=board[j]*2;
                        board[j]=0;
                    }
                }
            }
            break;
        case 'a':
            for(int j=0;j<3;j++){
                for(int i=0;i<16;i++){
                    if((i!=0 && i!=4 && i!=8 && i!=12) && board[i-1]==0){
                        board[i-1]=board[i];
                        board[i]=0;
                    }
                    else if((i!=0 && i!=4 && i!=8 && i!=12) && board[i-1]==board[i]){
                        board[i-1]=board[i]*2;
                        board[i]=0;
                    }
                }
            }
            break;
        case 'd':
            for(int j=0;j<3;j++){
                for(int i=15;i>=0;i--){
                    if((i!=3 && i!=7 && i!=11 && i!=15) && board[i+1]==0){
                        board[i+1]=board[i];
                        board[i]=0;
                    }
                    else if((i!=3 && i!=7 && i!=8 && i!=15) && board[i+1]==board[i]){
                        board[i+1]=board[i]*2;
                        board[i]=0;
                    }
                }
            }
            break;
            
        default:
            break;
            
    }
}

void win_condition(int* board){
    int counter=0;
    for(int i=0;i<16;i++){
        if(board[i]==2048){
            GAME_STATE=0;
            system("clear");
            printf("You won!\n");
            break;
        }
        else if(board[i]==0){
            ++counter;
        }
    }
    if (counter==16){
        GAME_STATE=0;
        system("clear");
        printf("You lose!\n");
    }
}

void display_board(int* board){
    system("clear");
    //system("cls");
    for(int i=0;i<16;i++){
        if(i%4==0){
            printf("\n");
            printf("%4d",board[i]);
            
        }
        else{
            printf("%4d",board[i]);
        }
        
    }
    printf("\n");
}
void generate_random(int* board){
    srand(time(0));
    int i=1;
    while(i){
        int rand_number=rand()%16;
        if(board[rand_number]==0){
            board[rand_number]=2;
            --i;
            break;
        }
    }
}

int main() {
    int* board=(int*)calloc(16,sizeof(int));
    char player_input;
    while(GAME_STATE){
        generate_random(board);
        display_board(board);
        scanf("\n%c",&player_input);
        playermove(player_input, board);
        display_board(board);
        win_condition(board);
    }
    return 0;
}

