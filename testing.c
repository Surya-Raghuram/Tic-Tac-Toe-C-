#include <stdio.h>

// functions that checks if someone has won the game
int win(int arr[3][3]){
    if( arr[0][0] == arr[1][1] && arr[1][1]==arr[2][2] || 
        arr[0][2] == arr[1][1] && arr[1][1]==arr[2][0] ||
        arr[0][2] == arr[1][2] && arr[1][2]==arr[2][2] ||
        arr[0][0] == arr[1][0] && arr[1][0]==arr[2][0] ||
        arr[0][1] == arr[1][1] && arr[1][1]==arr[2][1] ||
        arr[2][0] == arr[2][1] && arr[2][1]==arr[2][2] ||
        arr[1][0] == arr[1][1] && arr[1][1]==arr[1][2] ||
        arr[0][0] == arr[0][1] && arr[0][1]==arr[0][2]){
            return 1;
        } else {
            return 0;
        }
}
// function that checks if the game has ended in a draw
int draw(int arr[3][3]){
    if( arr[0][0] == 11 || arr[0][1] == 2 || arr[0][2] == 3 ||
        arr[1][0] == 4 || arr[1][1] == 5 || arr[1][2] == 6 ||
        arr[2][0] == 7 || arr[2][1] == 8 || arr[2][2] == 9){
            return 0;
        } else {
            return 1;
        }
}

int main(){
    // board
    int matrix[3][3] = {{11,2,3},
                        {4,5,6},
                        {7,8,9}};                  
    int turn = 1; //calculates whose turn it is
    int n; // dummy variable to store co-ordinates of user input

    //prints board intially
    for(int i =0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    //main loop to run which checks if any1 has won
    while(win(matrix) == 0){
        //for p-1
        if(turn == 1){
            //takes co-ordinate input
            printf("Player 1 turn: ");
            scanf("%d", &n);
            //matches co-ordinate and updates the array
            if(n ==1 && matrix[0][0] == 11){
                matrix[0][0] = 0;
            } else if(n==2 && matrix[0][1] == 2){
                matrix[0][1] = 0;
            } else if(n==3 && matrix[0][2] == 3){
                matrix[0][2] = 0;
            } else if(n==4 && matrix[1][0] == 4){
                matrix[1][0] = 0;
            } else if(n==5 && matrix[1][1] == 5){
                matrix[1][1] = 0;
            } else if(n==6 && matrix[1][2] == 6){
                matrix[1][2] = 0;
            } else if(n==7 && matrix[2][0] == 7){
                matrix[2][0] = 0;
            } else if(n==8 && matrix[2][1] == 8){
                matrix[2][1] = 0;
            } else if(n==9 && matrix[2][2] == 9){
                matrix[2][2] = 0;
            } else {
                printf("player 1 tried to overwrite. ");
                break;
            }
        // prints board after p-1 turn
        for(int i =0; i<3; i++){
            for(int j=0; j<3; j++){
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
        // checks if p-1 has won
        if(win(matrix) == 1){
                printf("Player 1 has won.");
                break;
            }
        // changes turn to p-2
        turn =0;
        } 
        // for p-2
        else{
            printf("player 2 turn: ");
            scanf("%d", &n); 

            if(n ==1 && matrix[0][0] == 11){
                matrix[0][0] = 1;
            } else if(n==2 && matrix[0][1] == 2){
                matrix[0][1] = 1;
            } else if(n==3 && matrix[0][2] == 3){
                matrix[0][2] = 1;
            } else if(n==4 && matrix[1][0] == 4){
                matrix[1][0] = 1;
            } else if(n==5 && matrix[1][1] == 5){
                matrix[1][1] = 1;
            } else if(n==6 && matrix[1][2] == 6){
                matrix[1][2] = 1;
            } else if(n==7 && matrix[2][0] == 7){
                matrix[2][0] = 1;
            } else if(n==8 && matrix[2][1] == 8){
                matrix[2][1] = 1;
            } else if(n==9 && matrix[2][2] == 9){
                matrix[2][2] = 1;
            } else {
                printf("player 2 tried to overwrite. ");
                break;
            }
            
            if(win(matrix) == 1){
                printf("Player 2 has won.");
                break;
            }
            
            for(int i =0; i<3; i++){
                for(int j=0; j<3; j++){
                    printf("%d ", matrix[i][j]);
                }
                printf("\n");
            }
            
            turn = 1;
        }
        //checks if game has ended in a draw
        if(draw(matrix) == 1){
            printf("Your game has ended in a draw");
            break;
        }
    }
}