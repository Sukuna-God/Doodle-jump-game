#include <iostream>
#include <raylib.h>

static int posX;
static int posY;

int main(){
    std::cout<<"Doodle Game!"<<std::endl;

    InitWindow(400, 600, "Doodle Game!");

    Texture2D doodle = LoadTexture("assets/doodle.png");

    SetTargetFPS(60);

    posX = 400;
    posY = 300;
    while(!WindowShouldClose()){

        

        BeginDrawing();

        ClearBackground(BLUE);

        DrawTexture(doodle, 200, 300, WHITE);

        EndDrawing();

    }


    CloseWindow();
    return 0;
}