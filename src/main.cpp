#include <iostream>
#include <raylib.h>

static float posX;
static float posY;

int main(){
    std::cout<<"Doodle Game!"<<std::endl;

    InitWindow(400, 600, "Doodle Game!");

    Texture2D platform = LoadTexture("assets/platform.png");
    Texture2D doodle = LoadTexture("assets/doodle.png");

    posX = 200;
    posY = 300;
    float timer = 0.0f;
    float delay = 3.0f;

    Camera2D camera = {0};
    // camera.target = (Vector2){posX, posY};
    camera.offset  = (Vector2){(float)GetScreenHeight()/2, (float)GetScreenWidth()/2};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    SetTargetFPS(60);

    while(!WindowShouldClose()){
        float delta = GetFrameTime();
        timer += delta;

        if((IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) && posX > 0){
            posX -= 10;
        }

        if((IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) && posX < 330){
            posX += 10;
        }

        // if(IsKeyDown(KEY_SPACE) || IsKeyDown(KEY_UP)){
        //     posY -= 20;
        // }
        // else if(timer == 0 && IsKeyUp(KEY_SPACE)){
        //     posY += 5;
        // }

        if(timer > delay){
            timer = 0.0f;
            posY -= 100;
        }else{
            posY += 100;
        }
        
        camera.target.y = posY;
        camera.target.x = 300;

        BeginDrawing();
        
        BeginMode2D(camera);
        ClearBackground(WHITE);
        DrawTexture(doodle, posX, posY, WHITE);
        DrawTexture(platform, 200, 400, WHITE);

        EndMode2D();
        EndDrawing();

    }

    UnloadTexture(doodle);
    UnloadTexture(platform);
    CloseWindow();
    return 0;
}