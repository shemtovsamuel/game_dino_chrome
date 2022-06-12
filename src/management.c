/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** management.c
*/

#include "../include/my_runner.h"

void management_jump(game_t *game)
{
    if (game->jump == true)
        game->pos_y -= 4;
    else
        game->pos_y += 4;
    if (game->pos_y <= 500) {
        game->pos_y = 500;
        game->test_jump++;
        if ((game->test_jump) == 37)
            game->jump = false;
    }
    if (game->pos_y >= 680 && game->jump == false) {
        game->pos_y = 680;
        game->test_jump = 0;
        game->is_grounded = true;
    }
}

void management_end_game(sfRenderWindow *window, game_t *game)
{
    if (game->carapace_x == 800 && game->pos_y >= 630)
        game->stop = 1;
    if (game->stop == 1) {
        game_over(window, game);
        sfText_setCharacterSize(game->text, 100);
        sfText_setPosition(game->text, (sfVector2f){940, 80});
        game->stop_sound++;
        if (game->stop_sound == 2) {
            sfSound_play(game->sounds[e_end]);
            sfSound_stop(game->sounds[e_music]);
        }
    }
    if (game->carapace_x == 800 && game->pos_y < 630 && !game->stop) {
        game->score++;
        sfSound_play(game->sounds[e_score]);
        sfText_setString(game->text, int_to_string(game->score));
    }
}

void management_sprite_x(game_t *game)
{
    game->carapace_x = algo(game->carapace_x, 5);
    game->sprite_x[1] = algo(game->sprite_x[1], 1);
    game->sprite_x[2] = algo(game->sprite_x[2], 1);
    game->sprite_x[3] = algo(game->sprite_x[3], 2);
    game->sprite_x[4] = algo(game->sprite_x[4], 2);
    game->sprite_x[5] = algo(game->sprite_x[5], 3);
    game->sprite_x[6] = algo(game->sprite_x[6], 3);
    game->sprite_x[7] = algo(game->sprite_x[7], 4);
    game->sprite_x[8] = algo(game->sprite_x[8], 4);
}

void management_free(game_t *game)
{
    for (int i = 0; i < e_nb_sounds; i++) {
        sfSound_destroy(game->sounds[i]);
        sfSoundBuffer_destroy(game->sound_buffers[i]);
    }
    free(game->sounds);
    free(game->sound_buffers);
    free(game->sprite_x);
    free(game->sprites);
    free(game);
}

void management_h (void)
{
    my_putstr("\tMY RUNNER\n");
    my_putstr("The goal of the game is to avoid the red shells, ");
    my_putstr("\nfor that you have to jump\n\n");
    my_putstr("The keys :\n");
    my_putstr("\tSPACE : to JUMP\n");
    my_putstr("\tR : To RESTART the game if you are dead\n\n");
    my_putstr("Have a good time\n");
    my_putstr("The game was created in December 2020 ");
    my_putstr("by Samuel Shemtov, for an Epitech project.\n");
}