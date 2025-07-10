#include <iostream>
#include <vector>
#include "raylib.h"

#define ASSETSPATH "./assets/test/" 



class bongoCat
{
    public:
        float speed = 0.1;
        float durationLeft = 0.1;
        bool idle = true;
        Texture2D bongoTextures[8];
        std::string imageNames [8] = {"idle.png", "afteridle.png", "lefthit.png", "afterlefthit.png", "righthit.png", "afterrighthit.png", "doublehit.png", "afterdoublehit.png"};
        std::string soundNames [3] = {"bongo1.mp3", "bongo2.mp3", "bongo3.mp3"};
        Sound bongoSounds[3];
        bool playedSound = false;

        void initBongoCat()
        {
            for (int i = 0 ; i < 8 ; i++)
            {
                Image bongoCatImg =  LoadImage((std::string(ASSETSPATH) + imageNames[i]).c_str());
                Texture2D bongoCatTexture = LoadTextureFromImage(bongoCatImg);
                bongoTextures[i] = bongoCatTexture;
                UnloadImage(bongoCatImg);
            }
            InitAudioDevice();
            for (int i = 0 ; i < 3; i++)
            {
                Sound bongoSound = LoadSound((std::string(ASSETSPATH) + soundNames[i]).c_str());
                bongoSounds[i] = bongoSound;
            }
            
        }
    
        void updateCat()
        {
            if (IsKeyDown(KEY_A) && IsKeyDown(KEY_D))
            {
                DrawTexture(bongoTextures[6], 0, 0, WHITE);
                if (!playedSound)
                {
                    PlaySound(bongoSounds[2]);
                    playedSound = true;
                }
            }
            else if (IsKeyDown(KEY_A))
            {
                DrawTexture(bongoTextures[2], 0 , 0, WHITE);
                if (!playedSound)
                {
                    PlaySound(bongoSounds[0]);
                    playedSound = true;
                }               
            }
            else if (IsKeyDown(KEY_D))
            {
                DrawTexture(bongoTextures[4], 0 , 0, WHITE);
                if (!playedSound)
                {
                    PlaySound(bongoSounds[1]);
                    playedSound = true;
                }  
            }
            else
            {
                DrawTexture(bongoTextures[0], 0, 0, WHITE);
                playedSound = false;
            }

        }


};



int main() 
{
    const int screenWidth = 394;
    const int screenHeight = 400;
    InitWindow(screenWidth, screenHeight, "bongo cat ?");
    SetWindowPosition(0, 0);  
    SetTargetFPS(60);

    
    bongoCat cat;
    cat.initBongoCat();

    while(!WindowShouldClose())
    {

        BeginDrawing();


        cat.updateCat();


        ClearBackground(WHITE);
        


        EndDrawing();
    }


    return 0;
}