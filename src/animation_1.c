/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** animation.c
*/

#include "../include/my_runner.h"

void animation_sprite(sfRenderWindow *window,
int pos_x, game_t *game, int index)
{
    sfVector2f duck_pos = {pos_x, 0};
    sfVector2f duck_scale = {1, 1};

    sfSprite_setScale(game->sprites[index], duck_scale);
    sfSprite_setPosition(game->sprites[index], duck_pos);
    sfRenderWindow_drawSprite(window, game->sprites[index], NULL);
}

void animation_carapace(sfRenderWindow *window, game_t *game)
{
    sfVector2f duck_pos = {game->carapace_x, 852};
    sfVector2f duck_scale = {0.03, 0.03};

    sfSprite_setScale(game->sprites[9], duck_scale);
    sfSprite_setPosition(game->sprites[9], duck_pos);
    sfRenderWindow_drawSprite(window, game->sprites[9], NULL);
}

void game_over(sfRenderWindow *window, game_t *game)
{
    sfVector2f duck_pos = {0, 0};
    sfVector2f duck_scale = {1, 1};

    sfSprite_setScale(game->sprites[10], duck_scale);
    sfSprite_setPosition(game->sprites[10], duck_pos);
    sfRenderWindow_drawSprite(window, game->sprites[10], NULL);
}

void animation_duck(sfRenderWindow *window, sfIntRect *rect,
sfClock *clock, game_t *game)
{
    sfVector2f duck_pos = {800, game->pos_y};
    sfVector2f duck_scale = {0.2, 0.2};

    sfSprite_setScale(game->sprites[0], duck_scale);
    sfSprite_setPosition(game->sprites[0], duck_pos);
    move_rect(rect, 500, 2500, clock);
    sfSprite_setTextureRect(game->sprites[0], *rect);
    sfRenderWindow_drawSprite(window, game->sprites[0], NULL);
}

int algo(int nb, int speed)
{
    nb -= speed;
    if (nb <= -3840)
        nb = 1920 - speed;
    return (nb);
}