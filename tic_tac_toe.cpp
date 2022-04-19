#include <iostream>
#include <vector>
#include <limits>


std::vector <char> XAndO{' ',' ',' ',' ',' ',' ',' ',' ',' '};

bool turns = false; // true = O false = X
int choice;
int count;
void update(){
    std::cout << XAndO[0] << "||" << XAndO[1] << "||" << XAndO[2] <<std::endl;
    std::cout << XAndO[3] << "||" << XAndO[4] << "||" << XAndO[5] <<std::endl;
    std::cout << XAndO[6] << "||" << XAndO[7] << "||" << XAndO[8] <<std::endl;
}
void showCase(){
    std::string result;
    std::cout << "Please choice a number between 0 and 10\n";
    update();
    result = (turns == true) ? " it is o's turn"  :  " it is x's turn";
    std::cout << result <<std::endl; 
}

void checkInput(){
    std::cin >> choice;
    if(std::cin.fail()){
        std::cin.clear();
        std::cout << "Please make sure you input a number.\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    else if(choice < 1||choice > 10){
        std::cout << "You didn't choice a number between 0 and 10\n";

    }
    else if(XAndO[choice - 1] == 'O' || XAndO[choice - 1] == 'X'){
        std::cout << "You need to choose another place because there is already a spot.\n";

    }
    else{
        if(turns == true){
            XAndO[choice - 1] = 'O';
            turns = false;
            count++;
        }
        else{
            XAndO[choice - 1] = 'X';
            turns = true;
            count++;
        }
    }
    
    
}
bool winCondtion(char shape){
        return 
        //OOO 
        XAndO[0] == shape && XAndO[1] == shape && XAndO[2] == shape || 
        XAndO[3] == shape && XAndO[4] == shape && XAndO[5] == shape || 
        XAndO[6] == shape && XAndO[7] == shape && XAndO[8] == shape ||

        /*O
          O
          O*/

        XAndO[0] == shape && XAndO[3] == shape && XAndO[6] == shape || 
        XAndO[1] == shape && XAndO[4] == shape && XAndO[7] == shape ||
        XAndO[2] == shape && XAndO[5] == shape && XAndO[8] == shape ||

        /*
          O
          XOX
          XXO
        */
       XAndO[0] == shape && XAndO[4] == shape && XAndO[8] == shape ||
       XAndO[2] == shape && XAndO[4] == shape && XAndO[6] == shape;
}
bool winner(){
    if(winCondtion('X')){
        update();
    
        std::cout << "X wins\n";
        return false;
    }
    else if(winCondtion('O')){
        update();
    
        std::cout << "O wins\n";
        return false;
    }
    else if(count == 9){
        update();
        std::cout << "no one won\n";
        return false;
    }
    else{
        return true;
    }
}
int main(){
    
    // std::cout << "X||X||X" << std::endl;

    // std::cout << "X||X||X" << std::endl;
    // std::cout << "X||X||X";
    do{
        
        showCase();
        checkInput();
        
    }while(winner());
    
    
}