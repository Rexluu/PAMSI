#include <iostream>
#include <algorithm>
using namespace std;

struct move_xy 
{
    int i = 0;
    int j = 0;
    int value = 0;
};


void draw_game(int size, int **board, char alphabet[])
{

    cout << "\n\n- - - - - - - - - - - - - -\n\n";
    cout << "    ";

    for (int i = 0; i < size; i++)
        cout << alphabet[i] << ".  ";

    for (int i = 0; i < size; i++){
        cout << "\n";
        cout << i << ".| ";
        for (int j = 0; j < size; j++) {
            if (board[i][j] == 0) cout << " ";
            if (board[i][j] == 1) cout << "O";
            if (board[i][j] == 2) cout << "X";
            cout << " | ";
        }
    }

    cout <<"\n";
}

void move(int size, int **board, char alphabet[])
{
    string mv;
    char c1;
    char c2;
    int l1;
    int l2;

    cout << "\n\nTwoj ruch [np. A0]: ";
    cin >> c1;
    cin >> c2;

    l1 = c1 - 65;
    l2 = c2 - 48;

    if (l1 >= size || l2 >= size || l1 < 0 || l2 < 0) {
        cerr << "Podano zly ruch! \n";
        move (size, board, alphabet);
    } else {
        if (board[l2][l1] == 1 || board[l2][l1] == 2) {
            cerr << "Nie mozesz wykonac tego ruchu! \n";
            move (size, board, alphabet);
        } else {
            board[l2][l1] = 2;
        }
    }
    
}

bool win_check(int size, int win_size, int &winner, int **board)
{
    int count = 1;
    int c = 0;
    int iteri;
    int iterj;
    winner = 0;

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++) {
            if (board[i][j] != 0) {
                c = board[i][j];

                // horizontal
                for (iterj = j+1; iterj < size; iterj++){
                    if (board[i][iterj] == c) count++;
                    if (count == win_size) { winner = c; return true; }
                }

                count = 1;

                // vertical
                for (iteri = i+1; iteri < size; iteri++){
                    if (board[iteri][j] == c) count++;
                    if (count == win_size) { winner = c; return true; }
                }

                count = 1;

                // diagonal "\"
                if (i < size-1 ) { 
                    iteri = i + 1;
                    for (iterj = j+1; iterj < size; iterj++){
                        if (board[iteri][iterj] == c) count++;
                        if (count == win_size) { winner = c; return true; }
                        if (iteri < size-1 ) 
                           iteri++;
                        else break;
                    }
                }

                count = 1;

                // diagonal "/"
                if (i < size-1 ) {
                    iteri = i + 1;
                    for (iterj = j-1; iterj >= 0; iterj--){
                        if (board[iteri][iterj] == c) count++;
                        if (count == win_size) { winner = c; return true; }
                        if (iteri < size-1 ) 
                            iteri++;
                        else break;
                    }
                }
                
                count = 1;

            }
        }


    return false;
}

bool no_move(int **board_copy, int size)
{
    for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                if (board_copy[i][j] == 0) return false;

    return true;
}

int minmax(int h, int size, int win_size, int player, int **board_copy, int alpha, int beta, int H_MAX) //h for future, player = 1 - computer, player = 2 - player
{
    int winner = 0; // null level, nobody
    if (win_check(size, win_size, winner, board_copy)) { // if somebody win, function win_check return true
        if (winner == 1) return 1; // if copmputer win, winner == 1;
        if (winner == 2) return -1; //if player win, winner == 2;
    }

    if (no_move(board_copy, size)) // IT HAS TO BE !
         return 0;

    if (h > H_MAX) {
        if(player == 1) return 1;
        if(player == 2) return -1;
    }

    if (player == 1) { //computer
        int score = -1000;
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                if (board_copy[i][j] == 0) {
                    board_copy[i][j] = 1;
                    score = max(score, minmax(h+1, size, win_size, 2, board_copy, alpha, beta, H_MAX)); // 2 - player
                    board_copy[i][j] = 0;
                    alpha = max (alpha, score);
                    if (beta <= alpha) break;
                }
        return score;
    } 

    if (player == 2) { // player
        int score = 1000;
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                if (board_copy[i][j] == 0) {
                    board_copy[i][j] = 2;
                    score = min(score, minmax(h+1, size, win_size, 1, board_copy, alpha, beta, H_MAX)); // 1 - computer
                    board_copy[i][j] = 0;
                    beta = min(beta, score);
                    if (beta <= alpha) break;
                }
        return score;
    }

    return 0;
}

void ai_move(int size, int win_size, int **board)
{
    int **board_copy = new int*[size]; // copy for safety to not operate on original one
    for (int i = 0; i < size; i++)
        board_copy[i] = new int[size];

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            board_copy[i][j] = board[i][j];

    move_xy best_mv;
    best_mv.value = -10;
    best_mv.i = -1;
    best_mv.j = -1;

    int H_MAX = 12-size; // for shorter times;

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (board_copy[i][j] == 0) {
                board_copy[i][j] = 1;  // computer == 1, player == 2
                int tempscore = minmax(0, size, win_size, 2, board_copy, -1000, 1000, H_MAX);  // computer == 1, player == 2
                board_copy[i][j] = 0;
                if (tempscore > best_mv.value) {
                    best_mv.value = tempscore;
                    best_mv.i = i;
                    best_mv.j = j;
                }
            }

    board[best_mv.i][best_mv.j] = 1;  // computer == 1, player == 2

    for (int i = 0; i < size; i++) // delete temp copy
        delete [] board_copy[i];

    delete [] board_copy;
}

void game(int size, int win_size, int **board, char alphabet[])
{
    bool flag_end = false;
    int winner = 0; // 1 - O ; 2 - X;
    int max_moves = size*size;
    int iter = 0; // count moves 

    while(!flag_end) {
        draw_game(size, board, alphabet);
        move(size, board, alphabet);
        iter++;
        flag_end = win_check(size, win_size, winner, board);
        if(flag_end || iter == max_moves) { draw_game(size, board, alphabet); break; }
        ai_move(size, win_size, board);
        iter++;
        flag_end = win_check(size, win_size, winner, board);
        if(flag_end || iter == max_moves) { draw_game(size, board, alphabet); break; }
    }

    if (winner != 0) {
        if (winner == 1) cout << "\nNiestety, przegrales!\n\n";
        if (winner == 2) cout << "\nGratulacje, wygrales!\n\n";
    } else {
        cout << "\nR-E-M-I-S !\n\n";
    }
}

void init()
{
    char alphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'}; // 0...9 game, no problem to do n x n
    int size;
    int win_size;

    cout << "- - - - - - - - - - - - - -\n";
    cout << "     Kolko i krzyzyk\n";
    cout << "- - - - - - - - - - - - - -\n";
    cout << "\nWprowadz rozmiar planszy: ";
    cin >> size;
    cout << "Wprowadz ilosc znakow wygrywajacych: ";
    cin >> win_size;

    if (size < 3 || size > 9) {
        cerr << "\n\nRozmiar planszy musi zawierać się w przedziale 3-9!\n";
        init();
    } else {
        if (win_size > size || win_size < 3) { 
            cerr << "\n\nLiczba znakow wygrywajacych nie moze byc wieksza od rozmiaru planszy i musi byc wieksza od 2!\n";
            init();
        } else {

            int **board = new int*[size]; // 0 - null , 1 - o, 2 - x
            for (int i = 0; i < size; i++)
                board[i] = new int[size];

            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++)
                    board[i][j] = 0;

            game(size, win_size, board, alphabet);

            for (int i = 0; i < size; i++)
                delete [] board[i];

            delete [] board;
        }
    }
}

int main()
{
    init();
    return 0;
}