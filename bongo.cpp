#include <iostream>
#include "raylib.h"

#define IMGSPATH "./assets/" 

void goofyDelay()
{
    double delay = 500000;
    while(true)
    {
        delay-= GetFrameTime() * 1000; // convert frame time to ms
        if (delay <= 0)
        {
            break;
        }
    }
}

int main() 
{
    const int screenWidth = 394;
    const int screenHeight = 400;
    InitWindow(screenWidth, screenHeight, "bongo cat ?");
    SetTargetFPS(60);
    Image bongoCatImg =  LoadImage(IMGSPATH "/idle.png"); 
    Texture2D bongoCatIdle = LoadTextureFromImage(bongoCatImg);
    UnloadImage(bongoCatImg);

    bongoCatImg = LoadImage(IMGSPATH "/afteridle.png");
    Texture2D bongoCatAfterIdle = LoadTextureFromImage(bongoCatImg);
    UnloadImage(bongoCatImg);

    bongoCatImg = LoadImage(IMGSPATH "/lefthit.png");
    Texture2D bongoCatLeftHit = LoadTextureFromImage(bongoCatImg);
    UnloadImage(bongoCatImg);

    bongoCatImg = LoadImage(IMGSPATH "/afterlefthit.png");
    Texture2D bongoCatAfterLeftHit = LoadTextureFromImage(bongoCatImg);
    UnloadImage(bongoCatImg);

    bongoCatImg = LoadImage(IMGSPATH "/righthit.png");
    Texture2D bongoCatRightHit = LoadTextureFromImage(bongoCatImg);
    UnloadImage(bongoCatImg);

    bongoCatImg = LoadImage(IMGSPATH "/afterrighthit.png");
    Texture2D bongoCatAfterRightHit = LoadTextureFromImage(bongoCatImg);
    UnloadImage(bongoCatImg);
    // to animate left hit animate the following : idle->afteridle->lefthit>afterlefthit->idle
    // to animate right hit animate the following : idle->afteridle->righthit>afterrighthit->idle
    //
    while(!WindowShouldClose())
    {

        BeginDrawing();




        ClearBackground(RAYWHITE);
        DrawTexture(bongoCatIdle, 0, 0, WHITE); 
        if(IsKeyPressed(KEY_A))
        {
            DrawTexture(bongoCatAfterIdle, 0, 0, WHITE);
            goofyDelay();
            DrawTexture(bongoCatLeftHit, 0, 0, WHITE);
            goofyDelay();
            DrawTexture(bongoCatAfterLeftHit, 0, 0, WHITE);
            goofyDelay();
        }
        if(IsKeyPressed(KEY_D))
        {
            DrawTexture(bongoCatAfterIdle, 0, 0, WHITE);
            goofyDelay();
            DrawTexture(bongoCatRightHit, 0, 0, WHITE);
            goofyDelay();
            DrawTexture(bongoCatAfterRightHit, 0, 0, WHITE);
            goofyDelay();
        }
        // std::cout << GetFrameTime() * 1000 << "\n";



        EndDrawing();
    }


    return 0;
}