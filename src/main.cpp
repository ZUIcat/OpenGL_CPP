#include "MyRenderWindow.h"

int main() {
    MyRenderWindow *myRenderWindow = new MyRenderWindow("LearnOpenGL", 800, 600); // const char*
    myRenderWindow->InitWindow();
    myRenderWindow->StartDraw();
    delete(myRenderWindow);
    return 0;
}
