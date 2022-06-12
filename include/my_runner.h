/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** my_hunter.h
*/

#ifndef MY_HUNTER_H_
#define MY_HUNTER_H_

#include <unistd.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdarg.h>
#include <SFML/Audio.h>
#include <stdbool.h>

typedef struct game_s {
    sfSprite **sprites;
    sfSoundBuffer **sound_buffers;
    sfSound **sounds;
    sfFont *font;
    sfText *text;
    sfVector2f pos_text;
    int score;
    int stop;
    int stop_sound;
    int pos_y;
    int carapace_x;
    int *sprite_x;
    int test_jump;
    bool jump;
    bool is_grounded;
} game_t;

enum sounds_name {
    e_music,
    e_jump,
    e_score,
    e_end,
    e_nb_sounds
};

sfRenderWindow * create_renderwindow(unsigned int x, unsigned int y,
    unsigned int bpp, char *title);
void event_management(sfRenderWindow *window, sfEvent event, game_t *game);
void my_putchar(char c);
int my_putstr(char const *str);
int my_put_nbr(int nb);
void animation_sprite(sfRenderWindow *window,
int pos_x, game_t *game, int index);
void animation_carapace(sfRenderWindow *window, game_t *game);
void game_over(sfRenderWindow *window, game_t *game);
char *int_to_string(int num);
void init_sound(game_t *game);
void init_font(game_t *game);
void init_sprites(game_t *game);
void init_sprite_x(game_t *game);
void init_game(game_t *game);
void animation_duck(sfRenderWindow *window,
sfIntRect *rect, sfClock *clock, game_t *game);
int algo(int nb, int speed);
void management_jump(game_t *game);
void management_end_game(sfRenderWindow *window, game_t *game);
void management_sprite_x(game_t *game);
void management_free(game_t *game);
void move_rect(sfIntRect *rect, int shifft, int max_value, sfClock *clock);
void management_h (void);

#endif