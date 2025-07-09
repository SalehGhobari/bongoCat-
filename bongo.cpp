#include <iostream>
#include "raylib.h"

#define ASSETSPATH "./assets/test/" 

void goofyDelay()
{
    double delay = 1000;
    while(true)
    {
        delay-= 10 * GetFrameTime();; // convert frame time to ms
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
    SetConfigFlags(FLAG_WINDOW_TRANSPARENT); 
    InitWindow(screenWidth, screenHeight, "bongo cat ?");
    SetWindowState(FLAG_WINDOW_UNDECORATED);
    SetWindowPosition(0, 0);  
    SetTargetFPS(60);
    Image bongoCatImg =  LoadImage(ASSETSPATH "idle.png"); 
    Texture2D bongoCatIdle = LoadTextureFromImage(bongoCatImg);
    UnloadImage(bongoCatImg);

    bongoCatImg = LoadImage(ASSETSPATH "afteridle.png");
    Texture2D bongoCatAfterIdle = LoadTextureFromImage(bongoCatImg);
    UnloadImage(bongoCatImg);

    bongoCatImg = LoadImage(ASSETSPATH "lefthit.png");
    Texture2D bongoCatLeftHit = LoadTextureFromImage(bongoCatImg);
    UnloadImage(bongoCatImg);

    bongoCatImg = LoadImage(ASSETSPATH "afterlefthit.png");
    Texture2D bongoCatAfterLeftHit = LoadTextureFromImage(bongoCatImg);
    UnloadImage(bongoCatImg);

    bongoCatImg = LoadImage(ASSETSPATH "righthit.png");
    Texture2D bongoCatRightHit = LoadTextureFromImage(bongoCatImg);
    UnloadImage(bongoCatImg);

    bongoCatImg = LoadImage(ASSETSPATH "afterrighthit.png");
    Texture2D bongoCatAfterRightHit = LoadTextureFromImage(bongoCatImg);
    UnloadImage(bongoCatImg);

    bongoCatImg = LoadImage(ASSETSPATH "doublehit.png");
    Texture2D bongoCatDoubleHit = LoadTextureFromImage(bongoCatImg);
    UnloadImage(bongoCatImg);

    bongoCatImg = LoadImage(ASSETSPATH "afterdoublehit.png");
    Texture2D bongoCatAfterDoubleHit = LoadTextureFromImage(bongoCatImg);
    UnloadImage(bongoCatImg);

    InitAudioDevice();
    Sound bongo1 = LoadSound(ASSETSPATH "bongo1.mp3");
    Sound bongo2 = LoadSound(ASSETSPATH "bongo2.mp3");
    Sound bongo3 = LoadSound(ASSETSPATH "bongo3.mp3");
    
    // to animate left hit animate the following : idle->afteridle->lefthit>afterlefthit->idle
    // to animate right hit animate the following : idle->afteridle->righthit>afterrighthit->idle
    //
    
    while(!WindowShouldClose())
    {

        BeginDrawing();




        ClearBackground(WHITE);  // Fully transparent if using alpha blending

        DrawTexture(bongoCatIdle, 0, 0, WHITE); 
        if(IsKeyPressed(KEY_A))
        {
            PlaySound(bongo1);
            DrawTexture(bongoCatAfterIdle, 0, 0, WHITE);
            goofyDelay();
            DrawTexture(bongoCatLeftHit, 0, 0, WHITE);
            goofyDelay();
            DrawTexture(bongoCatAfterLeftHit, 0, 0, WHITE);
            goofyDelay();
        }
        if(IsKeyPressed(KEY_D))
        {

            PlaySound(bongo2);
            DrawTexture(bongoCatAfterIdle, 0, 0, WHITE);
            goofyDelay();
            DrawTexture(bongoCatRightHit, 0, 0, WHITE);
            goofyDelay();
            DrawTexture(bongoCatAfterRightHit, 0, 0, WHITE);
            goofyDelay();
        }
        if(IsKeyPressed(KEY_D) && IsKeyPressed(KEY_A))
        {

            PlaySound(bongo3);
            DrawTexture(bongoCatAfterIdle, 0, 0, WHITE);
            goofyDelay();
            DrawTexture(bongoCatDoubleHit, 0, 0, WHITE);
            goofyDelay();
            DrawTexture(bongoCatAfterDoubleHit, 0, 0, WHITE);
            goofyDelay();
        }
        // std::cout << GetFrameTime() * 1000 << "\n";



        EndDrawing();
    }


    return 0;
}