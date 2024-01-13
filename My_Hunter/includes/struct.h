/*
** EPITECH PROJECT, 2023
** Header
** File description:
** Hunter
*/

#pragma once
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <time.h>

struct va {
    sfRenderWindow *window;
    sfTexture *backg;
    sfSprite *sprite;
    sfTexture *menu;
    sfSprite *sp_me;
    sfTexture *start1;
    sfSprite *start;
    sfTexture *quit1;
    sfSprite *quit;
    sfTexture *titre1;
    sfSprite *titre;
    sfBool show;
    sfBool show2;
    sfBool show3;
    int score;
    sfSound* sound;
    sfSoundBuffer* buffer;
    sfText* text;
    sfFont* font2;
    sfText* text2;
    char *texte2;
    sfTexture *cat1;
    sfSprite *cat;
    int i;
};

struct mouse {
    sfTexture *mouse;
    sfSprite *sprite;
};

struct move {
    sfTexture *duck;
    sfSprite *sprite;
    sfTime elapsed_time;
    sfClock *clock;
    double seconds;
    sfVector2f pos;
    sfFloatRect Bounds;
    sfVector2i mouse;
};
