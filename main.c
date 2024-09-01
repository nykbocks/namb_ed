#include <ncurses.h>
#include <stdio.h>
#include <string.h>
#define BUF_SIZE 2048
#define DELETE 127

void init(void){
	initscr();
	raw();
	keypad(stdscr,TRUE);
	cbreak();
	noecho();
}

int main(int argc,char *argv[]){
    	uint8_t buffer[BUF_SIZE] = {0};
    	init();
        int c = 0;
    	int i = 0;
    	int pos[2] = {0,0};
    	uint8_t exit = 0;
    	int last_x[50] = {0};
    	int last_x_index = 0;	
    	while(exit == 0){
        	/*
		if(buffer[i] == 27){
                	endwin();
			break;
		}
		*/
		c = getch();
		switch(c){
    		case KEY_BACKSPACE:
        		if(pos[0] == 0 && pos[1] == 0){
				break;
        		}
        		if(pos[0] != 0){
        			c = ' ';
        			i--;
        			buffer[i] = c;
        			pos[0]--;
        			move(pos[1],pos[0]);
        			delch();
                		refresh();
        			break;
        		}else{
				pos[1]--;
				pos[0] = last_x[last_x_index];
				move(pos[1],pos[0]);
				last_x[last_x_index] = 0;
				last_x_index--;
				refresh();
				break;

        		}
		case KEY_LEFT:
    			exit = 1;	
    			break;
		default:
    			if(c == 10){
        			last_x_index++;
        			last_x[last_x_index] = pos[0];
                		pos[1]++;
                		pos[0] = 0;	
                		move(pos[1],pos[0]);
                		refresh();
                		buffer[i] == c;
        			i++;        		
        			break;
    			}else{
        		addch(c);
        		pos[0]++;
        		refresh();
        		buffer[i] == c;
        		i++;
        		break;
    			}
        	}
    	}
    	refresh();
    	endwin();
	return 0;
}
