#include "graphicsdisplay.h"

using namespace std;

GraphicsDisplay::GraphicsDisplay(int width, int height):GameDisplay(width, height)
							,window{Xwindow()}{}
void GraphicsDisplay::render(){
	int colour = 0;
	char content;
	int cellHeight = 20;
	int cellWidth = 20;
	for(int i = 0; i < 2; i++){	
	//print levels and scores
		window.drawBigString(10+250*i,20,"Level: "+
				to_string(theDisplay[i]->getLevel()));
		window.drawBigString(10 + 250*i,40,"Score: "+
				to_string(theDisplay[i]->getScore()));

		for(int c = 0; c < width; c++){
			
			int x = 10+i*250 + cellWidth*c;	
		
			for(int r = 0; r < height; r++){
				content = theDisplay[i]->getCell(r,c);
				int y = 50 + r*cellHeight;
				if(content == 'I'){
					colour = 5;
				}
				else if(content == 'J'){
					colour = 8;
				}
				else if(content == 'L'){
					colour = 4;
				}
				else if(content == 'S'){
					colour = 3;
				}
				else if(content == 'Z'){
					colour = 2;
				}
				else if(content == 'O'){
					colour = 6;
				}
				else if(content == 'T'){
					colour = 7;
				}
				else{
					colour = 1;
				}
				window.fillRectangle(x, y, cellWidth, cellHeight, colour);
			}
			window.drawBigString(10+250*i, 430, "Next: ");
			int nextBlock = getColourSeq(theDisplay[i]->getNext());
			for(int j = 0; j < 4; j++){
				 window.fillRectangle(10+250*i + j*cellWidth, 440, 
					cellWidth, cellHeight, 
					GraphicsDisplay::blockColours[nextBlock][j]);
				 window.fillRectangle(10+250*i +j*cellWidth, 440+cellHeight, 
					cellWidth, cellHeight,  
					GraphicsDisplay::blockColours[nextBlock][4 + j]);
			}
			
		}	
	}
}

int GraphicsDisplay::getColourSeq(char c){
	if(c == 'I'){
                return 0;
        }else if(c == 'J'){
                return 1;
        }else if(c == 'L'){
                return  2;
        }else if(c == 'O'){
                return  3;
        }else if(c == 'S'){
                return  4;
        }else if(c == 'Z'){
                return  5;
        }else{
                return  6;
        }
}
