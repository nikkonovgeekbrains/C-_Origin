#include <iostream>
#include <random>
#include <algorithm>

using namespace std;

#define CHK_DOT(x, sz) ((x) >= 0 && (x) < (sz))
#define POINT_ITEM(a, r, c) (*((*(a + r)) + c))

enum PLAYER {HUMAN='X', AI='O', EMPTY='_'};

typedef struct {
   int szY;
   int szX;
   PLAYER** map;
   int towin;
} Field;

char getval(PLAYER** array, const int row, const int col) {
   return POINT_ITEM(array, row, col);
}
void setval(PLAYER** array, const int row, const int col, PLAYER value) {
   POINT_ITEM(array, row, col) = value;
}
int isvalid(Field &field, int x, int y) {
   return CHK_DOT(x, field.szX) && CHK_DOT(y, field.szY);
}
int isempty(Field &field, int x, int y) {
   return getval(field.map, y, x) == EMPTY;
}




void init(Field &field, int x_size, int y_size, int count) {
   field.towin = count;
   field.szY = y_size;
   field.szX = x_size;
   field.map = (PLAYER **) calloc(sizeof(PLAYER *), field.szY);
   for (int y = 0; y < field.szY; ++y) {
       *(field.map + y) = (PLAYER *) calloc(sizeof(PLAYER), field.szX);
       for (int x = 0; x < field.szX; ++x) {
           setval(field.map, y, x, EMPTY);
       }
   }
}

void print(Field &field) {
   //#include <windows.h>
   system("cls");
   //system("clear");
   printf("-------\n");
   for (int i = 0; i < field.szY; ++i) {
       cout << "|";
       for (int j = 0; j < field.szX; ++j) {
           printf("%c|", getval(field.map, i, j));
       }
       cout << endl;
   }
}

void human(Field &field) {
   int x;
   int y;
   do {
       //printf("Введите координаты хода X и Y (от 1 до %d) через пробел >>", field.szY);
       printf("Input coordinats X and Y (X from 1 to %d, Y from 1 to %d) with spacing >>", field.szX, field.szY);
       cin >> x >> y;
       // need to check if numbers are entered
       x--; y--;
   } while (!isvalid(field, x, y) || !isempty(field, x, y));
   setval(field.map, y, x, HUMAN);
}



int linechk(Field &field, int y, int x, int vx, int vy, int len, PLAYER c) {
   const int endx = x + (len - 1) * vx;
   const int endy = y + (len - 1) * vy;
   if (!isvalid(field, endx, endy))
       return 0;
   for (int i = 0; i < len; i++)
       if (getval(field.map, (y + i * vy), (x + i * vx)) != c)
           return 0;
   return 1;
}


int winchk(Field &field, PLAYER c) {
   for (int y = 0; y < field.szX; y++) {
       for (int x = 0; x < field.szY; x++) {
           if (linechk(field, y, x, 1, 0, field.towin, c)) return 1;
           if (linechk(field, y, x, 1, 1, field.towin, c)) return 1;
           if (linechk(field, y, x, 0, 1, field.towin, c)) return 1;
           if (linechk(field, y, x, 1, -1, field.towin, c)) return 1;
       }
   }
   return 0;
}

int isdraw(Field &field) {
   for (int y = 0; y < field.szY; y++)
       for (int x = 0; x < field.szX; x++)
           if (isempty(field, x, y))
               return 0;
   return 1;
}

int gamechk(Field &field, PLAYER dot, const string &winString) {
   if (winchk(field, dot)) {
       cout << winString << endl;
       return 1;
   }
   if (isdraw(field)) {
          cout << "draw" << endl;
          return 1;
   }
   return 0;
}

int aiwinchk(Field &field) {
   for (int y = 0; y < field.szY; y++) {
       for (int x = 0; x < field.szX; x++) {
           if (isempty(field, x, y)) {
               setval(field.map, y, x, AI);
               if (winchk(field, AI))
                   return 1;
               setval(field.map, y, x, EMPTY);
           }
       }
   }
   return 0;
}

int humwinchk(Field &field) {
   for (int y = 0; y < field.szY; y++) {
       for (int x = 0; x < field.szX; x++) {
           if (isempty(field, x, y)) {
               setval(field.map, y, x, HUMAN);
               if (winchk(field, HUMAN)) {
                   setval(field.map, y, x, AI);
                   return 1;
               }
               setval(field.map, y, x, EMPTY);
           }
       }
   }
   return 0;
}

void ai(Field &field, int x_size, int y_size) {
    if (!(aiwinchk(field))){
        if(!(humwinchk(field))){
            int x, y;
            //C++11 <random>
            random_device rd;
            mt19937 mt(rd());
            uniform_real_distribution<double> dist_x(0, x_size);
            uniform_real_distribution<double> dist_y(0, y_size);
            do {
                // C-style
                // x = rand() % field->szX;
                // y = rand() % field->szY;
                x = dist_x(mt);
                y = dist_y(mt);
                cout << "dsaf";
            } while (!isempty(field, x, y));
            setval(field.map, y, x, AI);
        }
    }
}

void tictactoe(int size_x, int size_y, int count) {
   Field field;
   // C-style
   // while (1) {
   while (true) {
       init(field, size_x, size_y, count);
       print(field);
       while (true) {
           human(field);
           print(field);
           if (gamechk(field, HUMAN, "Human win!")) break;
           ai(field, size_x, size_y);
           print(field);
           if (gamechk(field, AI, "AI win!")) break;
       }

       string answer;
       cout << "Play again? ";
       // one word to separator
       cin >> answer;


       // STL <algorithm>
       transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
       // only "y"
       // if (answer != "y")


       if (answer.find('y') != 0) // consider y, yo, ya, yes, yeah, yep, yay, etc
           break;
   }
}




int main()
{
    int x_size;
    int y_size;
    int count_to_win;
    cout << "Input size of field" << endl;
    cout << "size_x= " << endl;
    cin >> x_size;
    cout << "size_y= " << endl;
    cin >> y_size;


    do{
        cout << "count to win= " << endl;
        cin >> count_to_win;
    } while((count_to_win < 2)||(count_to_win > x_size)||(count_to_win > y_size));

    cout << count_to_win;


    tictactoe(x_size, y_size, count_to_win);

    return 0;
}
