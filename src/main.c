/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** my_runner
*/

#include "../include/my_runner.h"

void move_rect(sfIntRect *rect, int shifft, int max_value, sfClock *clock)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000.0;
    if (seconds > 50) {
        rect->left += shifft;
        if (rect->left > max_value)
            rect->left = 0;
        sfClock_restart(clock);
    }
}

void gameloop(sfRenderWindow *window, sfIntRect *rect,
sfEvent event, game_t *game)
{
    sfClock *clock = sfClock_create();
    game->test_jump = 0;
    sfSound_play(game->sounds[e_music]);
    while (sfRenderWindow_isOpen(window)) {
        management_sprite_x(game);
        while (sfRenderWindow_pollEvent(window, &event))
            event_management(window, event, game);
        sfRenderWindow_clear(window, sfBlack);
        for (int i = 1; i < 9; i++)
            animation_sprite(window, game->sprite_x[i], game, i);
        animation_carapace(window, game);
        management_jump(game);
        animation_duck(window, rect, clock, game);
        management_end_game(window, game);
        sfRenderWindow_drawText(window, game->text, NULL);
        sfRenderWindow_display(window);
    }
    management_free(game);
}

void start_game(void)
{
    game_t *game = malloc(sizeof(game_t));
    sfRenderWindow *window = create_renderwindow(1920, 1080, 32, "My HUNTER");
    sfEvent event;
    sfIntRect rect;

    init_game(game);
    rect.top = 0;
    rect.left = 0;
    rect.width = 500;
    rect.height = 1080;
    gameloop(window, &rect, event, game);
}

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h')  {
        management_h();
        return (0);
    }
    start_game();
    return (0);
}