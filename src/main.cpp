#include <iostream>
#include <raylib.h>

static float posX;
static float posY;

int main(){
    std::cout<<"Doodle Game!"<<std::endl;

    InitWindow(400, 600, "Doodle Game!");

    Texture2D platform = LoadTexture("assets/platform.png");
    Texture2D doodle = LoadTexture("assets/doodle.png");

    Camera2D camera = {0};
    camera.target = {posX, posY};
    camera.offset  = {200.0f, 300.0f};
    camera.rotation = 0.0f;
    camera.zoom = 0.0f;

    SetTargetFPS(60);

    posX = 200;
    posY = 300;

    while(!WindowShouldClose()){

        if((IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) && posX > 0){
            posX -= 10;
        }

        if((IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) && posX < 330){
            posX += 10;
        }

        if(IsKeyDown(KEY_SPACE) || IsKeyDown(KEY_UP)){
            posY -= 20;
        }
        else{
            posY += 5;
        }
        
        camera.target = {posX + 20, posY + 20};

        BeginMode2D(camera);
            DrawRectangle(-6000, 320, 13000, 8000, DARKGRAY);
        EndMode2D();

        BeginDrawing();

        ClearBackground(WHITE);

        DrawTextureEx(doodle, {posX, posY},  0, 1, WHITE);
        DrawTexture(platform, 200, 400, WHITE);

        EndDrawing();

    }

    UnloadTexture(doodle);
    UnloadTexture(platform);
    CloseWindow();
    return 0;
}