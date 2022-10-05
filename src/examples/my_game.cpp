
struct MyData {
    Sprite sprite;
    Sprite sprite2;
    Sprite sprite3;

    SoundClip sound;
    int32 scaleNumber;
    int32 currentPhase;
};

MyData *Data = NULL;

Sprite lemonSprite;

void MyInit() {
    Game->myData = malloc(sizeof(MyData));
    memset(Game->myData, 0, sizeof(MyData));

    Data = (MyData *)Game->myData;

    Data->currentPhase = 1;
    Data->scaleNumber = 3;

    // All sprites must be png files
    // You provide the path to the png like "directory/to/my/file/file_name.png"
    // In this case I have put the pngs inside the "data" directory.
    LoadSprite(&Data->sprite, "data/galaga_ship.png");
    LoadSprite(&Data->sprite2, "data/RPGpack_sheet_2X.png");

    LoadSprite(&Data->sprite3, "data/rothko.png");

    LoadSprite(&lemonSprite, "data/bad_lemon.png");

    LoadSoundClip("data/sfx/flute_breathy_c4.wav", &Data->sound);
}


vec2 position = V2(4, 0);

vec2 scale = V2(1, 1);

void MyGameUpdate() {
    // This sets the background color. 
    ClearColor(RGB(0.0f, 0.0f, 0.0f));
    /**/
    if (InputHeld(Keyboard, Input_UpArrow)) {
        position.y += 2 * Game->deltaTime;
    }

    // position in pixels
    vec2 mousePos = Input->mousePosNormSigned;
    mousePos.x = mousePos.x * 8;
    mousePos.y = mousePos.y * 4.5f;

    //DrawRect(V2(-2, -2), scale, RGB(0, 1, 1));

    //DrawRect(V2(-2, -2), scale, V4(0.0f, 1.0f, 1.0f, 0.5f));

    //DrawCoolRect(V2(0, 0), V2(1, 1), 0, RGB(0.0f, 0.3f, 0.3f));


    if (InputPressed(Keyboard, Input_Space)) {
        PlaySound(&Game->audioPlayer, Data->sound, 1.0f, true);
        Data->currentPhase++;
    }

   

    switch (Data->currentPhase) {
        case 1: 
        {
            SpriteSheetShader(V2(0), V2(4,4), 0, &Data->sprite2, V2(0,0), V2(0));
            break; 
        }
        case 4:
        {
            
            if (InputPressed(Keyboard, Input_F)) {
                Data->scaleNumber = RandiRange(1, 20);
            }
            ScaleSpriteByNumber(V2(0), V2(4, 4), 0, &Data->sprite2, Data->scaleNumber);
            DrawTextScreenPixel(&Game->monoFont, V2(30, 110), 23.0f, RGB(0.99f, 0.1f, 0.2f), "Press F to Change number of Scale");
            break;
        }
        case 2:
        {
            DrawSpriteBlendTwo(V2(0), V2(4, 4), 0, &Data->sprite2, &Data->sprite3);
            break;
        }
        case 3:
        {
            DrawSpriteInvertedColors(V2(0), V2(4, 4), 0, &Data->sprite2);

            break;
        }
        default:
        {
            Data->currentPhase = 1;
            break;
        }
    }
    
    
    // scale.x -= 0.2f * Game->deltaTime;
    // scale.y -= 0.2f * Game->deltaTime;
    // once scale goes negative we will have inverted the shape,
    // it will continue to grow.

    //position.y -= 2 * Game->deltaTime;

    // things are drawn in the order you call the functions.
    // The latest draw call will be on top of all previous, and so on.

    // (0, 0) is center of the screen
    // increasing values of y move up
    // We have negative coordinates
    // The width of our screen is 16 (-8 to 8) (left to right)
    // The height of our screen is 9 (-4.5 to 4.5) (bottom to top)

    // version that doesnt take an angle.
    //DrawSprite(V2(0), V2(4, 4), DegToRad(90), &Data->sprite2);

   // DrawSprite(V2(0), V2(4, 4), 0, &Data->sprite2);

    DrawSprite(mousePos, V2(0.5f, 0.5f), &lemonSprite);
    //DrawSpriteInvertedColors(V2(0), V2(4, 4), 0, &Data->sprite2);
   // if (currentPhase)
   // DrawRect(V2(0), V2(1, 1),0,  RGB(1.0f, 0.3f, 0.3f));
   // DrawSprite(position, V2(0.5f, 0.5f), &Data->sprite);
    DrawTextScreenPixel(&Game->monoFont, V2(30, 80), 13.0f, RGB(0.1f, 0.1f, 0.99f), "Press Spacebar to advance Shader Example");

    // TODO: Write a custom shader that draws a sprite with inverted colors. You'll need to write the shader, load it, and write a function to draw a sprite that uses it.

}
