/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** my_runner
*/

#include "../include/my_runner.h"

sfRenderWindow *create_renderwindow(unsigned int x, unsigned int y,
    unsigned int bpp, char *title)
{
    sfVideoMode video_mode = {x, y, bpp};

    return (sfRenderWindow_create(video_mode, title, sfResize | sfClose, NULL));
}

void event_management(sfRenderWindow *window, sfEvent event, game_t *game)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtKeyReleased) {
        if ((event.key.code == sfKeySpace) && game->is_grounded == true) {
            game->jump = true;
            game->is_grounded = false;
            sfSound_play(game->sounds[e_jump]);
        }
    }
    if (event.key.code == sfKeyR && game->stop == 1) {
        game->score = 0;
        game->stop = 0;
        sfText_setString(game->text, "0");
        sfSound_play(game->sounds[e_music]);
        game->stop_sound = 0;
        sfText_setPosition(game->text, game->pos_text);
        sfText_setCharacterSize(game->text, 50);
        game->carapace_x = 4000;
    }
}