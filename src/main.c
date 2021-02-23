#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10

enum Direction{
    UP = 1,
    DOWN = -1,
    LEFT = -1,
    RIGHT = 1
};

typedef struct vec2{
    int x, y;
} vec2_t;

typedef struct ball{
    vec2_t pos;
    vec2_t direction;
    char logo;
} ball_t;

void init_ball(ball_t* ball){
    vec2_t pos = {.x = 2, .y = 8};
    ball->pos = pos;
    ball->logo = '#';
    vec2_t directions = {.x = RIGHT, .y = DOWN};
    ball->direction = directions;
}

int main(){
    int cornerHits = 0;
    system("clear");
    char wait = 0;
    clock_t lasttime = clock();
    ball_t ball;
    init_ball(&ball);
    while(1){
            if(!wait){
                printf("\n");
                printf("Position of the ball: x = %d, y = %d; Direction of the ball: x = %d, y = %d\n", ball.pos.x, ball.pos.y, ball.direction.x, ball.direction.y);
                printf("Corner hits: %d\n", cornerHits);
            for(int y = 0; y < HEIGHT; y++){
               for(int x = 0; x < WIDTH; x++){
                    if(y == ball.pos.y && x == ball.pos.x){
                        printf("%c", ball.logo);
                    }else{
                        printf(".");
                    }
                }
                printf("\n");
            }
        }
        clock_t currtime = clock();
        if(currtime - lasttime <= 1000000 / 80){
            wait = 1;
            continue;
        }
        wait = 0;
        lasttime = currtime;
        ball.pos.x += ball.direction.x;
        ball.pos.y += ball.direction.y;

        if((ball.pos.x == WIDTH - 1 && ball.pos.y == HEIGHT - 1) || (ball.pos.x == 0 && ball.pos.y == 0))cornerHits++;

        if(ball.pos.x == WIDTH - 1){
            ball.direction.x = LEFT;
        }else if(ball.pos.x == 0){
            ball.direction.x = RIGHT;
        }
        if(ball.pos.y == HEIGHT - 1){
            ball.direction.y = DOWN;
        }else if(ball.pos.y == 0){
            ball.direction.y = UP;
        }
        system("clear");
    }
    
}