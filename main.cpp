#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h> 

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score; // variables for the coordinates
enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

void setup();
void initialPosition();
void draw();
void input();
void logic();

int main() {
    setup();
    while (!gameOver) {
        draw();
        input();
        logic();
    }
    return 0;
}

void setup() {
    gameOver = false;
    dir = STOP;
    initialPosition();
    srand(time(NULL)); // Seed for random number generation
}

void initialPosition() {
    x = width/2;
    y = height/2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}

void draw() {
    system("cls");
    std::cout << "Score: " << score << std::endl;

    for (int i = 0; i < width; i++) {
        std::cout << '#';
    }
    std::cout << std::endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
                std::cout << '#';
            else if (i == y && j == x)
                std::cout << 'O';
            else if (i == fruitY && j == fruitX)
                std::cout << 'F';
            else
                std::cout << ' ';
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < width; i++) {
        std::cout << '#';
    }
}

void input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'x':
                gameOver = true;
                break;
        }
    }
}

void logic() {
    switch(dir) {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;
    }
    if (x > width - 1 || x < 0 || y > height - 1 || y < 0)
        gameOver = true;
    if (x == fruitX && y == fruitY) {
        score++;
        fruitX = rand() % width;
        fruitY = rand() % height;
    }
}