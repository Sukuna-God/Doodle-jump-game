#include <iostream>
#include <raylib.h>

int main(){
    std::cout<<"Doodle Game!"<<std::endl;

    InitWindow(800, 600, "Doodle Game!");

    SetTargetFPS(60);

    while(!WindowShouldClose()){
        BeginDrawing();

        ClearBackground(BLUE);

        EndDrawing();

    }


    CloseWindow();
    return 0;
}