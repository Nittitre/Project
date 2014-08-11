#define PADDLEL 60 //Paddle length
#define PADDLEH 5 //Paddle Height
#define BRAD 5//Ball Radius
#include <allegro.h>
#include <stdlib.h>
int main(void) {
	BITMAP *buffer;
	BITMAP *background;
	BITMAP *ball;
	BITMAP *paddle;

	int paddlex, paddley;
	double speed = 1;
	struct ball {
		double ballx;
		double bally;
		double dx;
		double dy;
	};
	
	struct ball tball{320, 420, 0, 1 };

	allegro_init();
	set_color_depth(16);
	set_gfx_mode(GFX_SAFE, 640, 480, 0, 0);
	install_keyboard();
	install_timer();
	srand(time(NULL));
	buffer = create_bitmap(640, 480);
	background = create_bitmap(640, 480);
	background = load_bitmap("bg.bmp", NULL);
	paddle = load_bitmap("paddle.bmp", NULL);
	ball = load_bitmap("ball.bmp", NULL);
	

	while (!key[KEY_ESC]) {


		if (key[KEY_LEFT]) {		//Check if the paddle is on the edge of the screen, otherwise move it left
			if (paddlex > 0){
				paddlex -= 1;
			}
			else{}
		}

		else if (key[KEY_RIGHT]) {	//Check if the paddle is on the edge of the screen, otherwise move it right
			if (paddlex+PADDLEL < 640){ 
				paddlex += 1;
			}
			else{}

		}

		else {}

		//tball.ballx += tball.dx*speed;  // The ball is moved and the speed is increased
		tball.bally += tball.dy*speed;
		
		//Collchk with walls and paddle
		if (bounding_box_collision(tball.ballx, tball.bally, BRAD, BRAD, 0, 0, 5, 480) == 1){
			tball.dx = -tball.dx;
		} //Left Wall

		if (bounding_box_collision(tball.ballx, tball.bally, BRAD, BRAD, 0, 0, 640, 5) == 1){
			tball.dy = -tball.dy;
		} //Top Wall

		if (bounding_box_collision(tball.ballx, tball.bally, BRAD, BRAD, 635, 0, 5, 480) == 1){
			tball.dx = -tball.dx;
		} //Right Wall

		if (bounding_box_collision(tball.ballx, tball.bally, BRAD, BRAD, 0, 480, 640, 30) == 1){
			return 0;
		} //Bottom, end the game

		else if (bounding_box_collision(tball.ballx, tball.bally, BRAD, BRAD, paddlex, paddley, PADDLEL, PADDLEH) == 1){
			 tball.dy = -tball.dy;
			 tball.dx = rand() % ((1000 + 1) + (-500)) / (float)100; //Give the ball a new random dx between -4,99 to 4,99
		} //Paddle





		// Draw into buffer
		blit(background, buffer, 0, 0, 0, 0, 640, 480);
		draw_sprite(buffer, paddle, paddlex, paddley);
		draw_sprite(buffer, ball, tball.ballx, tball.bally);



		// Draw buffer on screen 
		acquire_screen();
		blit(buffer, screen, 0, 0, 0, 0, 640, 480);
		release_screen();

		// Wait 
		rest(10);



	};
	destroy_bitmap(buffer);
	destroy_bitmap(background);
	destroy_bitmap(ball);
	destroy_bitmap(paddle);


	allegro_exit();
	return 0;
}
END_OF_MAIN() 
