/*
** EPITECH PROJECT, 2023
** MY_ISNEG
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#ifndef STRUCT
    #define STRUCT
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <SFML/Graphics/CircleShape.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/Graphics/Sprite.h>
    #include <SFML/Graphics/Texture.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/System/Time.h>
    #include <SFML/Window/Event.h>
    #include <SFML/Window/Mouse.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <stdarg.h>
    #include <math.h>
    #define SIZE ALL->settings.size
    #define MODE ALL->settings.mode
    #define WIN ALL->settings.window
    #define SPRITES ALL->sprites
    #define PLANES ALL->planes
    #define TOWERS ALL->towers
    #define TEXTS ALL->texts
    #define EVENT ALL->settings.event
    #define CLOCKS ALL->clocks
    #define SPRITEDATA ALL->spritedata
    #define SPRITES_COUNT ALL->local.sprites_count
    #define PLANES_COUNT ALL->local.planes_count
    #define TOWERS_COUNT ALL->local.towers_count
    #define TEXTS_COUNT ALL->local.texts_count
    #define DATA_COUNT ALL->local.data_count
    #define CLOCKS_COUNT ALL->local.clocks_count
    #define DEATH_COUNT ALL->local.death_count
    #define HITBOX ALL->local.hitbox
    #define TIMER ALL->local.timer
    #define FPS ALL->local.fps
typedef struct {
    int size[2];
    sfVideoMode mode;
    sfRenderWindow *window;
    sfEvent event;
} parameters_t;
typedef struct {
    sfCircleShape *shape;
    sfVector2f pos;
    sfVector2f scale;
    sfColor color;
    float radius;
} circle_t;
typedef struct {
    sfRectangleShape *shape;
    sfVector2f pos;
    sfVector2f scale;
    sfColor color;
    sfVector2f size;
} rect_t;
typedef struct {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2u size;
    sfVector2f scale;
    sfVector2f origin;
} sprites_t;
typedef struct {
    int is_alive;
    int is_in_tower;
    float distance_from_tower;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2u size;
    sfVector2f scale;
    sfVector2f origin;
    int speed;
    int altitude;
    int delay;
    int draw;
    sfVector2f start;
    sfVector2f end;
    rect_t rect;
} planes_t;
typedef struct {
    int is_alive;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2u size;
    sfVector2f scale;
    sfVector2f origin;
    circle_t circle;
} towers_t;
typedef struct {
    sfText *text;
    sfFont *font;
    sfVector2f pos;
    sfVector2f scale;
    sfColor color;
    int size;
    char *str;
} texts_t;
typedef struct {
    sfClock *clock;
    sfTime time;
    float seconds;
} clocks_t;
typedef struct {
    int death_count;
    int sprites_count;
    int planes_count;
    int towers_count;
    int texts_count;
    int clocks_count;
    int data_count;
    int hitbox;
    int draw;
    long long timer;
    long long fps;
    float speed;
    int display;
} local_t;
typedef struct {
    float leftX;
    float rightX;
    float topY;
    float bottomY;
} spritedata_t;
typedef struct {
    parameters_t settings;
    sprites_t *sprites;
    planes_t *planes;
    towers_t *towers;
    texts_t *texts;
    clocks_t *clocks;
    spritedata_t *spritedata;
    local_t local;
} global_t;
void init(global_t *ALL, int i);
int collision(global_t *ALL, int i);
int collisionclick(global_t *ALL, int i);
void start(global_t *ALL);
void close_all(global_t *ALL);
int my_rand(int min, int max);
void move_plane(global_t *ALL, int i);
void check_collision(global_t *ALL, int i);
void keys(global_t *ALL);
int parcing(char *filepath, global_t *ALL);
void load_towers(global_t *ALL, int i, char **map);
void load_planes(global_t *ALL, int i, char **map);
char **my_str_to_word_array1(char *str, char c1, char c2);
void move(sfTime *time, float *seconds, sfClock *clock, global_t *ALL);
void timer_fps(sfTime *time, float *seconds, sfClock *clock, global_t *ALL);
void death_plane(global_t *ALL);
void drawallsprites(global_t *ALL);
void drawallplanes(global_t *ALL);
void drawalltowers(global_t *ALL);
void resize(global_t *ALL);
#endif
