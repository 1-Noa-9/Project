/*
** EPITECH PROJECT, 2023
** My_Hunter
** File description:
** bs
*/

#include "../includes/my.h"

static void quit_game(struct va *disp)
{
    sfVector2f scale;
    sfVector2f pos;
    sfFloatRect textureSize;

    sfSound_setBuffer(disp->sound, disp->buffer);
    disp->quit1 = sfTexture_createFromFile("texture/quit.png", NULL);
    disp->quit = sfSprite_create();
    sfSprite_setTexture(disp->quit, disp->quit1, sfTrue);
    scale.x = 0.50f;
    scale.y = 0.50f;
    sfSprite_setScale(disp->quit, scale);
    textureSize = sfSprite_getGlobalBounds(disp->quit);
    pos.x = (1920 - textureSize.width) / 2;
    pos.y = (800 - textureSize.height) / 2;
    sfSprite_setPosition(disp->quit, pos);
    cat_rules(disp);
}

static void menu(struct va *disp)
{
    sfVector2f scale;
    sfVector2f pos;
    sfFloatRect textureSize;

    disp->menu = sfTexture_createFromFile("texture/menu.jpg", NULL);
    disp->sp_me = sfSprite_create();
    disp->start1 = sfTexture_createFromFile("texture/start2.png", NULL);
    disp->start = sfSprite_create();
    sfSprite_setTexture(disp->sp_me, disp->menu, sfTrue);
    sfSprite_setTexture(disp->start, disp->start1, sfTrue);
    scale.x = 0.50f;
    scale.y = 0.50f;
    sfSprite_setScale(disp->start, scale);
    textureSize = sfSprite_getGlobalBounds(disp->start);
    pos.x = (1920 - textureSize.width) / 2;
    pos.y = (600 - textureSize.height) / 2;
    sfSprite_setPosition(disp->start, pos);
    disp->buffer = sfSoundBuffer_createFromFile("texture/Meow2.ogg");
    disp->sound = sfSound_create();
    quit_game(disp);
}

void texte(struct va *disp)
{
    sfVector2f pos;
    sfFloatRect textureSize;
    sfVector2f scale;

    textureSize = sfText_getGlobalBounds(disp->text2);
    pos.x = (1000 - textureSize.width) / 2;
    pos.y = (200 - textureSize.height) / 2;
    sfText_setPosition(disp->text2, pos);
    disp->titre1 = sfTexture_createFromFile("texture/image.png", NULL);
    disp->titre = sfSprite_create();
    sfSprite_setTexture(disp->titre, disp->titre1, sfTrue);
    scale.x = 1.2f;
    scale.y = 1.2f;
    sfSprite_setScale(disp->titre, scale);
    textureSize = sfSprite_getGlobalBounds(disp->titre);
    pos.x = (1920 - textureSize.width) / 2;
    pos.y = (200 - textureSize.height) / 2;
    sfSprite_setPosition(disp->titre, pos);
}

static void points(struct va *disp)
{
    disp->texte2 = malloc(sizeof(char) * 56);
    disp->text2 = sfText_create();
    disp->font2 = sfFont_createFromFile("texture/police.otf");
    sfText_setFont(disp->text2, disp->font2);
    sfText_setCharacterSize(disp->text2, 40);
    sfText_setColor(disp->text2, sfBlack);
    texte(disp);
}

void initialization(struct va *disp, sfVideoMode mode, struct mouse *move)
{
    sfVector2f scale;
    sfVector2f scale_back;

    menu(disp);
    disp->window = sfRenderWindow_create(mode, "My_Hunter",
    sfResize | sfClose, NULL);
    disp->backg = sfTexture_createFromFile("texture/font2.jpeg", NULL);
    disp->sprite = sfSprite_create();
    move->mouse = sfTexture_createFromFile("texture/curs.png", NULL);
    move->sprite = sfSprite_create();
    sfSprite_setTexture(disp->sprite, disp->backg, sfTrue);
    scale_back.x = 1.0f;
    scale_back.y = 0.879f;
    sfSprite_setScale(disp->sprite, scale_back);
    sfSprite_setTexture(move->sprite, move->mouse, sfTrue);
    scale.x = 0.25f;
    scale.y = 0.25f;
    sfSprite_setScale(move->sprite, scale);
    points(disp);
}

void render_duck(struct move *duck, sfIntRect *duck1)
{
    duck->clock = sfClock_create();
    duck1->left = 0;
    duck1->width = 110;
    duck1->top = 0;
    duck1->height = 110;
    sfSprite_setTextureRect(duck->sprite, *duck1);
}

void initialization_duck(struct move *duck, sfIntRect *duck1, struct va *disp)
{
    disp->show = sfTrue;
    disp->show2 = sfFalse;
    disp->show3 = sfFalse;
    duck->duck = sfTexture_createFromFile("texture/duck.png", NULL);
    duck->sprite = sfSprite_create();
    sfSprite_setTexture(duck->sprite, duck->duck, sfTrue);
    duck->pos.x = 0;
    duck->pos.y = rand() % ((sfRenderWindow_getSize(disp->window).y - 110)+ 1);
    render_duck(duck, duck1);
}

static void render_menu(struct va *disp)
{
    sfRenderWindow_clear(disp->window, sfBlack);
    sfRenderWindow_drawSprite(disp->window, disp->sp_me, NULL);
    sfRenderWindow_drawSprite(disp->window, disp->start, NULL);
    sfRenderWindow_drawSprite(disp->window, disp->quit, NULL);
    sfRenderWindow_drawSprite(disp->window, disp->cat, NULL);
    sfRenderWindow_drawSprite(disp->window, disp->titre, NULL);
    sfRenderWindow_setMouseCursorVisible(disp->window, sfTrue);
    sfRenderWindow_display(disp->window);
}

static void render_bis(struct va *disp, struct mouse *move, struct move *duck)
{
    sfRenderWindow_clear(disp->window, sfBlack);
    sfRenderWindow_drawSprite(disp->window, disp->sprite, NULL);
    sfRenderWindow_setMouseCursorVisible(disp->window, sfFalse);
    if (disp->show)
        sfRenderWindow_drawSprite(disp->window, duck->sprite, NULL);
    sfRenderWindow_drawSprite(disp->window, move->sprite, NULL);
    sfRenderWindow_display(disp->window);
}

void render_back(struct va *disp, struct mouse *move, struct move *duck)
{
    disp->i = 0;
    if (disp->show3)
        render_bis(disp, move, duck);
    if (disp->show3 == sfFalse && disp->show2 == sfTrue) {
        render_cat(disp);
    } else if (disp->show2 == sfFalse) {
        render_menu(disp);
    }
}
