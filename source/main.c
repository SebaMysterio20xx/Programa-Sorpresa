/*
	Colored Text example made by Aurelio Mannara for ctrulib
	This code was modified for the last time on: 12/12/2014 23:00 UTC+1

*/

#include <3ds.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	// Initialize services
	gfxInitDefault();

	//Initialize console on top screen. Using NULL as the second argument tells the console library to use the internal console structure as current one
	consoleInit(GFX_TOP, NULL);

	//Move the cursor to row 15 and column 19 and then prints "Hello World!" 
	//To move the cursor you have tu print "\x1b[r;cH", where r and c are respectively
	//the row and column where you want your cursor to move
	//The top screen has 30 rows and 50 columns
	//The bottom screen has 30 rows and 40 columns
	

	//Move the cursor to the top left corner of the screen
	printf("\x1b[0;0H");

	//Print a REALLY crappy poeam with colored text
	//\x1b[cm set a SGR (Select Graphic Rendition) parameter, where c is the parameter that you want to set
	//Please refer to http://en.wikipedia.org/wiki/ANSI_escape_code#CSI_codes to see all the possible SGR parameters
	//As of now ctrulib support only these parameters:
	//Reset (0), Half bright colors (2), Reverse (7), Text color (30-37) and Background color (40-47)
	printf("Hola \x1b[31mAmi\x1b[0m\n");
	printf("Quiero que \x1b[34msepas\x1b[0m\n");
	printf("Que eres la \x1b[35mmejor\x1b[0m\n");
	printf("Y te voy a prometer \x1b[34malgo\x1b[0m\n");
	printf("Yo, Sebastian prometo \x1b[36msiempre\x1b[0m\n");
	printf("Poder ayudarte en lo que \x1b[32mpueda\x1b[0m\n");
	printf("Y si no \x1b[31mpuedo ayudarte\x1b[0m\n");
	printf("Hare lo \x1b[35mimposible por ayudarte\x1b[0m\n");
	printf("Porque eres la \x1b[2m\x1b[33mMejor\x1b[0m\n");
	//Black text on white background
	//In this example we set two parameter in a single escape sequence by separating them by a semicolon
	//\x1b[47;30m means that it will set a white background (47) and it will print white characters (30)
	//In this we also could have used the 
	printf("\x1b[47;30mNuestras almas se encontraron\x1b[0m\n");
	printf("\x1b[47;30mPor la razon menos esperada y en el momento justo\x1b[0m");


	printf("\x1b[29;15HPresione start para salir, o presione X para ver algo.");
	// Main loop
	while (aptMainLoop())
	{
		//Scan all the inputs. This should be done once for each frame
		hidScanInput();

		//hidKeysDown returns information about which buttons have been just pressed (and they weren't in the previous frame)
		u32 kDown = hidKeysDown();
		if (kDown & KEY_X) printf("Te quiero mucho");
		if (kDown & KEY_START) break; // break in order to return to hbmenu

		// Flush and swap framebuffers
		gfxFlushBuffers();
		gfxSwapBuffers();

		//Wait for VBlank
		gspWaitForVBlank();
	}

	// Exit services
	gfxExit();
	
	return 0;
}
