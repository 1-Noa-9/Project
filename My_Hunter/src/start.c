/*
** EPITECH PROJECT, 2023
** My_Hunter
** File description:
** bs
*/

#include "../includes/my.h"

static void reset(struct va *disp, struct move *duck)
{
    disp->show = sfTrue;
    duck->pos.y = rand() % ((sfRenderWindow_getSize(disp->window).y - 110)+ 1);
    duck->pos.x = 0;
    sfSprite_setPosition(duck->sprite, duck->pos);
}

static void click_bis(struct va *disp)
{
    sfFloatRect Bounds;
    sfFloatRect Bounds2;
    sfFloatRect Bounds3;
    sfVector2i mouse;

    mouse = sfMouse_getPositionRenderWindow(disp->window);
    Bounds2 = sfSprite_getGlobalBounds(disp->quit);
    Bounds = sfSprite_getGlobalBounds(disp->start);
    Bounds3 = sfSprite_getGlobalBounds(disp->cat);
    if (sfFloatRect_contains(&Bounds, mouse.x, mouse.y) && !disp->show2) {
            disp->show2 = sfTrue;
            disp->show3 = sfTrue;
    }
    if (sfFloatRect_contains(&Bounds2, mouse.x, mouse.y) && !disp->show2) {
        sfRenderWindow_close(disp->window);
    }
    if (sfFloatRect_contains(&Bounds3, mouse.x, mouse.y)) {
        sfSound_play(disp->sound);
        disp->show2 = sfTrue;
    }
}

void menu_click(struct va *disp, sfEvent *event)
{
    if (event->type == sfEvtMouseButtonPressed &&
    event->mouseButton.button == sfMouseLeft) {
        click_bis(disp);
        }
    if (event->type == sfEvtKeyPressed && event->key.code == sfKeyEscape) {
        if (disp->show2) {
            disp->show2 = sfFalse;
        }
    }
}

void mouse_click_game(struct va *disp, struct move *duck, sfEvent *event)
{
    if (event->type == sfEvtMouseButtonPressed &&
    event->mouseButton.button == sfMouseLeft) {
        duck->mouse = sfMouse_getPositionRenderWindow(disp->window);
        duck->Bounds = sfSprite_getGlobalBounds(duck->sprite);
            if (sfFloatRect_contains
            (&duck->Bounds, duck->mouse.x, duck->mouse.y)) {
                disp->show = !disp->show;
                disp->score += 1;
        }
    }
    if (event->type == sfEvtKeyPressed && event->key.code == sfKeyEscape) {
        disp->show2 = sfFalse;
        disp->show3 = sfFalse;
    }
}

void mouse_click(struct va *disp, struct move *duck, sfEvent *event)
{
    if (!disp->show3)
        menu_click(disp, event);
    if (disp->show3)
        mouse_click_game(disp, duck, event);
}

void event(struct va *disp, struct mouse *move, struct move *duck)
{
    sfEvent event;
    sfVector2f pos;
    sfFloatRect spriteBounds;

    while (sfRenderWindow_pollEvent(disp->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(disp->window);
        if (event.type == sfEvtMouseMoved) {
            spriteBounds = sfSprite_getGlobalBounds(move->sprite);
            pos.x = event.mouseMove.x - spriteBounds.width / 2;
            pos.y = event.mouseMove.y - spriteBounds.height / 2;
            sfSprite_setPosition(move->sprite, pos);
        }
        mouse_click(disp, duck, &event);
    }
}

static void duck_move(struct move *duck, sfVideoMode *mode, struct va *disp)
{
    duck->pos.x += 1;
    sfSprite_setPosition(duck->sprite, duck->pos);
    if (duck->pos.x == mode->width) {
        duck->pos.y = rand() %
        ((sfRenderWindow_getSize(disp->window).y - 110)+ 1);
        duck->pos.x = 0;
        sfSprite_setPosition(duck->sprite, duck->pos);
    }
    if (duck->pos.y == mode->width) {
        duck->pos.y = 0;
        duck->pos.x = 0;
        sfSprite_setPosition(duck->sprite, duck->pos);
    }
}

static int start(void)
{
    struct va *disp = malloc(sizeof(struct va));
    struct mouse *move = malloc(sizeof(struct mouse));
    struct move *duck = malloc(sizeof(struct move));
    sfIntRect duck1;
    sfVideoMode mode = {1920, 1080, 60};

    disp->score = 0;
    initialization(disp, mode, move);
    initialization_duck(duck, &duck1, disp);
    while (sfRenderWindow_isOpen(disp->window)) {
        render_back(disp, move, duck);
        clock_duck(&duck1, duck);
        duck_move(duck, &mode, disp);
        if (!disp->show)
            reset(disp, duck);
        event(disp, move, duck);
    }
    destroy(disp, move, duck);
    return 0;
}

static void disp_rules(char *str)
{
    if (str[0] == '-' && str[1] == 'h') {
        my_putstr("USAGE:\n");
        my_putstr("\t./my_hunter\n\n");
        my_putstr("DESCRIPTION:\n");
        my_putstr("\tYou have to shoot the duck to win points.\n");
    } else {
        my_putstr("for list rules use ./my_hunter -h\n");
        return;
    }
}

int main(int argc, char *argv[])
{
    if (argc == 2)
        disp_rules(argv[1]);
    else
        start();
    return 0;
}
