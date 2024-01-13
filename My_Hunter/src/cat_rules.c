/*
** EPITECH PROJECT, 2023
** My_hunter
** File description:
** cat sprite
*/

#include "../includes/my.h"

void cat_rules(struct va *disp)
{
    sfVector2f scale;
    sfVector2f pos;
    sfFloatRect textureSize;

    disp->cat1 = sfTexture_createFromFile("texture/cat_rules.png", NULL);
    disp->cat = sfSprite_create();
    sfSprite_setTexture(disp->cat, disp->cat1, sfTrue);
    scale.x = 0.50f;
    scale.y = 0.50f;
    sfSprite_setScale(disp->cat, scale);
    textureSize = sfSprite_getGlobalBounds(disp->cat);
    pos.x = (200 - textureSize.width) / 2;
    pos.y = (1630 - textureSize.height) / 2;
    sfSprite_setPosition(disp->cat, pos);
}

void render_cat(struct va *disp)
{
    disp->texte2 =
    "\t\t\t\t\t\tRULES:\nYou have to shoot the duck to win points.\n\
    \t\t\tto pause press echap\n\t\tto return on menu press echap\n";
    sfRenderWindow_clear(disp->window, sfBlack);
    sfRenderWindow_drawSprite(disp->window, disp->sp_me, NULL);
    sfText_setString(disp->text2, disp->texte2);
    sfRenderWindow_drawText(disp->window, disp->text2, NULL);
    sfRenderWindow_display(disp->window);
}

void destroy2(struct va *disp, struct mouse *move, struct move *duck)
{
    sfSound_destroy(disp->sound);
    sfSoundBuffer_destroy(disp->buffer);
    sfTexture_destroy(disp->cat1);
    sfSprite_destroy(disp->cat);
    sfText_destroy(disp->text2);
    sfFont_destroy(disp->font2);
    my_putstr("score = ");
    my_put_nbr(disp->score);
    my_putstr("\n");
    free(disp);
    free(move);
    free(duck);
}

void destroy(struct va *disp, struct mouse *move, struct move *duck)
{
    sfRenderWindow_destroy(disp->window);
    sfSprite_destroy(move->sprite);
    sfSprite_destroy(duck->sprite);
    sfTexture_destroy(duck->duck);
    sfTexture_destroy(move->mouse);
    sfSprite_destroy(disp->sprite);
    sfTexture_destroy(disp->backg);
    sfClock_destroy(duck->clock);
    sfSprite_destroy(disp->start);
    sfTexture_destroy(disp->start1);
    sfSprite_destroy(disp->titre);
    sfTexture_destroy(disp->titre1);
    destroy2(disp, move, duck);
}

void clock_duck(sfIntRect *duck1, struct move *duck)
{
    duck->elapsed_time = sfClock_getElapsedTime(duck->clock);
    duck->seconds = sfTime_asSeconds(duck->elapsed_time);
    if (duck->seconds >= 0.1) {
        duck1->left += 110;
        duck1->height = 110;
        duck1->width = 110;
        if (duck1->left >= duck1->width * 3)
            duck1->left = 0;
    sfClock_restart(duck->clock);
    sfSprite_setTextureRect(duck->sprite, *duck1);
    }
}
