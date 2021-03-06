#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#include "setting.h"

#include "function.c"

#include "letter.c"
#include "display.c"
#include "snake/game.c"
#include "tetris/game.c"
#include "tetris/init_tetris.c"
void init() 
{
	display_set_fullscreen();
	display_set_screen_size(DISPLAY_SIZE_X,DISPLAY_SIZE_Y);
	cursor(FALSE);
	return;
}

void de_init()
{
	return;
}

int quit_program()
{
	de_init();
	gotoxy(0,0);
	exit(0);
	return 0;
}

int main(int argc, char **argv)
{	
	init();
	display_menu();
	
	int user_input = 0;
	int user_selection = 0;

	while(1)
	{
		if( kbhit() )
		{
			user_input = getch();
			switch( user_input )
			{
				case ASCII_ESC:
				{
					quit_program();
				}
				case ASCII_ENTER:
				{
					switch( user_selection )
					{
						case 0:
						{
							// START GAME
//							init_snake();
							init_tetris();
							block_drop();
							quit_program();
							break;
						}
						case 1:
						{
							// END GAME
							quit_program();
							break;
						}
					}
				} 
				// SELECTIONS
				case 'w':
				case 'W':
				case ASCII_ARROW_UP:
				{
					user_selection = 0;
					display_selection_change(0);
					break;
				}
				/*
				case ASCII_A:
				case ASCII_a:
				case ASCII_ARROW_LEFT:
				{
					display_select_left();
					break;
				} */				
				case 's':
				case 'S':
				case ASCII_ARROW_DOWN:
				{
					user_selection = 1;
				    display_selection_change(1);
					break;
				} 
		/*		case ASCII_D:
				case ASCII_d:
				case ASCII_ARROW_RIGHT:
				{
					display_select_right();
					break;
				}	*/	
			}
		}
	}

	de_init();
	return 0;
}
