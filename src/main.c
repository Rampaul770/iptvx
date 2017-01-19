#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include "args.h"
#include "window.h"
#include "video.h"
#include "webkit.h"

/* main application code */
int main (int argc, char *argv[]){
	/* parse input arguments first */
	struct arguments arguments = iptvx_parse_args(argc,argv);

	/* ensure sufficient parameters where provided */
	if(arguments.sufficient == true){
		/* create the thread for the main window */
		iptvx_create_window_thread(1280,720);

		/* start the webkit thread */
		//iptvx_webkit_start_thread(arguments.input_html_file);

		iptvx_video_play(arguments.input_video_file);
	}

	return 0;
}