#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>

using namespace std;

string condition(vector<string> board, vector<int> remains, string player){
    string state = "none";
    for(int i = 0; i < 3; i++){
        if(board.at(i*3) != " " && board.at(i*3)== board.at(i*3+1) && board.at(i*3+1) == board.at(i*3+2)){
            cout<<player<<" has won!\n";
            return "Win";
        }
        if(board.at(i)!= " " && board.at(i) == board.at(i+3) && board.at(i+3) == board.at(i+6)){
            cout<<player<<" has won!\n";
            return "Win";
        }
        if(board.at(4) != " " && ((board.at(0) == board.at(4) && board.at(4) == board.at(8)) || (board.at(2) == board.at(4) && board.at(4) == board.at(6)))){
            cout<<player<<" has won!\n";
            return "Win";
        }
        if(size(remains) == 0){
            cout<<"Draw!\n";
            return "Draw";
        }
    }
    return state;
}

int main()
{
    srand(time(nullptr));
    int choice1, choice2;
    string player1icon, player2icon, gamemode;
    vector<string> ticgrid = {" ", " ", " ", " ", " ", " ", " ", " ", " ", " "};
    vector<int> ticremaining {1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout<<"   1 | 2 | 3\n ------------\n   4 | 5 | 6\n ------------\n   7 | 8 | 9\nSingleplayer or Multiplayer?\n";

    getline(cin, gamemode);

    int start= rand() % 2;
    if (start == 0){
        player1icon = "O";
        player2icon = "X";
    }
    else{
        player2icon = "O";
        player1icon = "X";
    }

    while (condition(ticgrid, ticremaining, "player 2") == "none"){
        cout<<"\nplayer 1's turn (choose 1-9): ";
        cin>>choice1;

        if(count(ticremaining.begin(), ticremaining.end(), choice1) == 0){
            cout<<"spot already taken, retry\n";
            continue;
        }

        ticgrid.at(choice1-1) = player1icon;
        ticremaining.erase(find(ticremaining.begin(), ticremaining.end(), choice1));

        cout<<"   "<<ticgrid.at(0)<<" | "<<ticgrid.at(1)<<" | "<<ticgrid.at(2)<<"\n ------------\n   "<<ticgrid.at(3)<<" | "<<ticgrid.at(4)<<" | "<<ticgrid.at(5)<<"\n ------------\n   "<<ticgrid.at(6)<<" | "<<ticgrid.at(7)<<" | "<<ticgrid.at(8)<<"\n";

        if (condition(ticgrid, ticremaining, "player 1") != "none") break;

        cout<<"\nplayer 2's turn: ";
        if(gamemode == "Singleplayer"){
            choice2 = ticremaining.at(rand() % size(ticremaining));
            cout<<choice2<<"\n";
        }
        else{
            cin>>choice2;
            cout<<choice2<<"\n";
            while(count(ticremaining.begin(), ticremaining.end(), choice2) == 0){
                cout<<"spot already taken, retry\n";
                cin>>choice2;
                cout<<"\n";
                continue;
            }


        }
        ticremaining.erase(find(ticremaining.begin(), ticremaining.end(), choice2));
        ticgrid.at(choice2-1) = player2icon;

        cout<<"   "<<ticgrid.at(0)<<" | "<<ticgrid.at(1)<<" | "<<ticgrid.at(2)<<"\n ------------\n   "<<ticgrid.at(3)<<" | "<<ticgrid.at(4)<<" | "<<ticgrid.at(5)<<"\n ------------\n   "<<ticgrid.at(6)<<" | "<<ticgrid.at(7)<<" | "<<ticgrid.at(8)<<"\n";


    }



    return 0;
}
