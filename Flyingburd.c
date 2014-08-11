#define MAX_TIME 200 //Max Spawntime
#define MIN_TIME 150//Min spawntime
#define BISPEED 1.5  //Birds vertical speed
#define BLSPEED 1 //Blocks horizontal speed
#define RIGHT_END 640
#define BIWIDTH 50
#define BIHEIGHT 50
#define BLWIDTH 60
#include <allegro.h>
#include <stdlib.h>

BITMAP *create_random_background(BITMAP *background) { //Bg generator
	// Create random background 
	int i, bg_red, bg_green, bg_blue, bg_size, bg_x, bg_y;

	for (i = 0; i<10; i++) {
		bg_red = rand() % 128;
		bg_green = rand() % 128;
		bg_blue = rand() % 128;
		bg_size = rand() % 200 + 20;
		bg_x = rand() % 620 + 10;
		bg_y = rand() % 460 + 10;
		circlefill(background, bg_x, bg_y, bg_size, makecol(bg_red, bg_green, bg_blue));
	}
	return background;
}

int create_box(int time) {

	if (time >= MAX_TIME){ //  If the longest allowed time has passed
		return 1; //Create box
	}
		
	else if (time >= MIN_TIME){ //If the min time has passed
		return rand() % 1;	//Check if a box shall be created
	}

	else {
		return 0;
	}
}
/*
int main(void) {
	BITMAP *buffer;
	BITMAP *background;	BITMAP *birdimg[3];	BITMAP *block;

	int birdv, timepast, blocknr, i, speed;  //birdversion, timer, blocknumber, integer
	int startpos[3] = { 0, 160, 320 }; //Block starting positions

	struct bird {
		int birdx;
		int birdy;
	};
	struct block {
		int blockx;
		int blocky;
	};
	
	allegro_init();
	set_color_depth(16);
	set_gfx_mode(GFX_SAFE, 640, 480, 0, 0);
	install_keyboard();
	install_timer();
	srand(time(NULL));
	buffer = create_bitmap(640, 480);
	background = create_bitmap(640, 480);
	create_random_background(background);
	birdimg[0] = load_bitmap("bird1.bmp", NULL);
	birdimg[1] = load_bitmap("bird2.bmp", NULL);
	birdimg[2] = load_bitmap("bird3.bmp", NULL);
	block = load_bitmap("block.bmp", NULL);
	birdv = 0;
	timepast = 0;
	blocknr = -1;
	speed = 1;
	struct bird tbird = {120, 240};
	struct block blocks[20];
	
	while (!key[KEY_ESC]) {


		//Moves the bird and coll box
		if (key[KEY_SPACE]) {
			if (tbird.birdy - BISPEED < 0){
										// If bird y reaches upper end of the frame, suspend it
			}
			else{
				tbird.birdy -= BISPEED;
				birdv = 0;	//Bird glides
			}
		}

		else {
			if (tbird.birdy + BISPEED > 400){
												// If bird y reaches lower end of the frame, suspend it
			}
			else{
				tbird.birdy += BISPEED;
				birdv = 0;	//Bird glides
			}
		}

		timepast += 1;

		if (create_box(timepast) == 1){ //Creates 1-2 blocks
			blocknr = (blocknr + 2) % 20; //Reset the count if it hits 20
			blocks[blocknr-1].blockx = RIGHT_END+20;   //X is slightly outside the far right end of screen
			blocks[blocknr-1].blocky = startpos[rand() % 3]; //picks one of the random start positions
			blocks[blocknr].blockx = RIGHT_END+20;   
			blocks[blocknr].blocky = startpos[rand() % 3];
			timepast = 0;
		}
		for(i = 0; i < 20; ++i){ //Moves all 10 blocks left
			blocks[i].blockx -= BLSPEED; //Move the block left
			if (bounding_box_collision(tbird.birdx, tbird.birdy, BIWIDTH, BIHEIGHT, blocks[i].blockx, blocks[i].blocky, BLWIDTH, 180) == 1){
				return 0;
			}

		}

		



		//Collchk

		// Draw into buffer
		blit(background, buffer, 0, 0, 0, 0, 640, 480);
		//stretch_sprite(buffer, shipimg[riktning], posx, posy, 200, 200);
		draw_sprite(buffer, birdimg[birdv], tbird.birdx, tbird.birdy);
		for(i = 0; i < 10; ++i){
			draw_sprite(buffer, block, blocks[i].blockx, blocks[i].blocky);
		}



		// Draw buffer on screen 
		acquire_screen();
		blit(buffer, screen, 0, 0, 0, 0, 640, 480);
		release_screen();

		// Wait 
		rest(10);



	};
	destroy_bitmap(buffer);
	destroy_bitmap(background);
	destroy_bitmap(birdimg[0]);
	destroy_bitmap(birdimg[1]);
	destroy_bitmap(birdimg[2]);
	destroy_bitmap(block);
	allegro_exit();
	return 0;
}
END_OF_MAIN() */