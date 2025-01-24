#include "echequier.h"


void echequier::makeCheckImage() {


	int i, j, c;

	for (i = 0; i < width; i++) {
		for (j = 0; j < height; j++) {
			c = ((((i & 0x8) == 0) ^ ((j & 0x8)) == 0)) * 255;
			checkImage[i][j][0] = (GLubyte) c;
			checkImage[i][j][1] = (GLubyte) c;
			checkImage[i][j][2] = (GLubyte) c;

		}
	}

}


void echequier::init() {

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	makeCheckImage();
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1),
	glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height,0, GL_RGB, GL_UNSIGNED_BYTE, & checkImage[0][0][0]);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
		GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
		GL_NEAREST);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glEnable(GL_TEXTURE_2D);
	glShadeModel(GL_FLAT);
		
}



