/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** init.c
*/

#include "../include/my_runner.h"

void init_sound(game_t *game)
{
    game->sounds = malloc(sizeof(*game->sounds) * e_nb_sounds);
    for (int i = 0; i < e_nb_sounds; i++)
        game->sounds[i] = sfSound_create();
    game->sound_buffers = malloc(sizeof(*game->sound_buffers) * e_nb_sounds);
    game->sound_buffers[e_music] =
sfSoundBuffer_createFromFile("src/music.wav");
    game->sound_buffers[e_jump] = sfSoundBuffer_createFromFile("src/jump.wav");
    game->sound_buffers[e_score] =
sfSoundBuffer_createFromFile("src/score.wav");
    game->sound_buffers[e_end] = sfSoundBuffer_createFromFile("src/end.wav");
    sfSound_setBuffer(game->sounds[e_music], game->sound_buffers[e_music]);
    sfSound_setBuffer(game->sounds[e_jump], game->sound_buffers[e_jump]);
    sfSound_setBuffer(game->sounds[e_score], game->sound_buffers[e_score]);
    sfSound_setBuffer(game->sounds[e_end], game->sound_buffers[e_end]);
    sfSound_setVolume(game->sounds[e_music], 50);
    sfSound_setVolume(game->sounds[e_jump], 15);
}

void init_font(game_t *game)
{
    game->font = sfFont_createFromFile("./src/font.ttf");
    game->text = sfText_create();
    game->pos_text = (sfVector2f){1820, 10};
    game->score = 0;
    sfText_setString(game->text, "0");
    sfText_setFont(game->text, game->font);
    sfText_setCharacterSize(game->text, 50);
    sfText_setPosition(game->text, game->pos_text);
    sfText_setColor(game->text, sfWhite);
}

void init_sprites(game_t *game)
{
    sfTexture *duck = sfTexture_createFromFile("src/walk.png", NULL);
    sfTexture *ground = sfTexture_createFromFile("src/ground.png", NULL);
    sfTexture *tree = sfTexture_createFromFile("src/tree.png", NULL);
    sfTexture *building = sfTexture_createFromFile("src/building.png", NULL);
    sfTexture *sky = sfTexture_createFromFile("src/sky.png", NULL);
    sfTexture *carapace = sfTexture_createFromFile("src/carapace.png", NULL);
    sfTexture *game_over = sfTexture_createFromFile("src/game_over.png", NULL);

    sfSprite_setTexture(game->sprites[0], duck, sfFalse);
    sfSprite_setTexture(game->sprites[7], ground, sfFalse);
    sfSprite_setTexture(game->sprites[8], ground, sfFalse);
    sfSprite_setTexture(game->sprites[5], tree, sfFalse);
    sfSprite_setTexture(game->sprites[6], tree, sfFalse);
    sfSprite_setTexture(game->sprites[3], building, sfFalse);
    sfSprite_setTexture(game->sprites[4], building, sfFalse);
    sfSprite_setTexture(game->sprites[1], sky, sfFalse);
    sfSprite_setTexture(game->sprites[2], sky, sfFalse);
    sfSprite_setTexture(game->sprites[9], carapace, sfFalse);
    sfSprite_setTexture(game->sprites[10], game_over, sfFalse);
}

void init_sprite_x(game_t *game)
{
    game->sprite_x = malloc(sizeof(int) * 10);
    for (int i = 0; i < 9; i++)
        game->sprite_x[i] = 0;
    game->sprite_x[2] = 1920;
    game->sprite_x[4] = 1920;
    game->sprite_x[6] = 1920;
    game->sprite_x[8] = 1920;
}

void init_game(game_t *game)
{
    init_sprite_x(game);
    game->stop = 0;
    game->stop_sound = 0;
    game->pos_y = 680;
    game->carapace_x = 3500;
    game->jump = false;
    game->is_grounded = true;
    init_sound(game);
    game->sprites = malloc(sizeof(*game->sprites) * 11);
    for (int i = 0; i < 11; i++)
        game->sprites[i] = sfSprite_create();
    init_sprites(game);
    init_font(game);
}