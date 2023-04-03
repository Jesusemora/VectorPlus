#ifndef __TEXTURE_PLUS_H_INCLUDED__
#define __TEXTURE_PLUS_H_INCLUDED__

class Texture {
private:
	int twraps = 0;
	int twrapt = 0;
	/*
	 * GL_TEXTURE_WRAP_S
	 * 		GL_CLAMP_TO_EDGE
	 * 		GL_MIRRORED_REPEAT
	 * 		GL_REPEAT
	 * GL_TEXTURE_WRAP_T
	 * 		GL_CLAMP_TO_EDGE
	 * 		GL_MIRRORED_REPEAT
	 * 		GL_REPEAT
	 */
	int tfiltering_min = 1;
	/*
	 * GL_NEAREST
	 * GL_LINEAR
	 * GL_NEAREST_MIPMAP_NEAREST
	 * GL_LINEAR_MIPMAP_NEAREST
	 * GL_NEAREST_MIPMAP_LINEAR
	 * GL_LINEAR_MIPMAP_LINEAR
	 */
	int tfiltering_max = 1;
	/*
	 * GL_NEAREST
	 * GL_LINEAR
	 */
	
	bool mipMaps = true;
	int flags = 0;
	bool loaded = false;
	
	void setParams()
	{
		if(twraps == 1)
		{
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		}
		else if(twraps == 2)
		{
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
		}
		if(twrapt == 1)
		{
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		}
		else if(twrapt == 2)
		{
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
		}
		if(tfiltering_min == 0)
		{
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		}
		else if(tfiltering_min == 1)
		{
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		}
		else if(tfiltering_min == 2)
		{
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
		}
		else if(tfiltering_min == 3)
		{
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
		}
		else if(tfiltering_min == 4)
		{
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
		}
		else if(tfiltering_min == 5)
		{
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		}
		if(tfiltering_max == 0)
		{
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		}
		else
		{
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		}
	}
	
	void setMipmap()
	{
		if(mipMaps)
		{
			glGenerateMipmap(GL_TEXTURE_2D);
		}
	}
public:
	int width;
	int height;
	unsigned char* imageO;
	bool isAlpha = false;
// 	Texture(int sizex, int sizey, int mipmap)
// 	{
// 		
// 	}
	
	void SetFlags(int ws, int wt, int filtmin, int filtmax, bool mipmap = true)
	{
		twraps = ws;
		twrapt = wt;
		tfiltering_min = filtmin;
		tfiltering_max = filtmax;
		mipMaps = mipmap;
	}
	
	void createTex(const char *filePath)
	{
		imageO = SOIL_load_image(filePath, &width, &height, 0, SOIL_LOAD_RGB);
		isAlpha = false;
		//flags = 2;
		loaded = true;
	}
	
	void createTex(const char *filePath, bool alpha)
	{
		imageO = SOIL_load_image(filePath, &width, &height, 0, SOIL_LOAD_RGBA);
		isAlpha = alpha;
		//flags = 2;
		loaded = true;
	}
	
	void BindTexture(int id, GLuint *textureID)
	{
		if(imageO)
		{
			glActiveTexture(GL_TEXTURE0 + id);
			glBindTexture(GL_TEXTURE_2D, textureID[id]);
			
			//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			this->setParams();
			//std::cout << glGetError() << std::endl;
			
			if(isAlpha)
			{
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, this->width, this-> height, 0, GL_RGBA, GL_UNSIGNED_BYTE, this->imageO);
			}
			else
			{
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, this->width, this-> height, 0, GL_RGB, GL_UNSIGNED_BYTE, this->imageO);
			}
			
			//glGenerateMipmap(GL_TEXTURE_2D);
			this->setMipmap();
			//flags = 0;
			//loaded = false;
			//free(imageO);
		}
	}
	
	void SwapTexture(int id)//, GLuint *textureID)
	{
		if(imageO)
		{
			glActiveTexture(GL_TEXTURE0 + id);
			//glBindTexture(GL_TEXTURE_2D, textureID[id]);
			if(isAlpha)
			{
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, this->width, this-> height, 0, GL_RGBA, GL_UNSIGNED_BYTE, this->imageO);
			}
			else
			{
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, this->width, this->height, 0, GL_RGB, GL_UNSIGNED_BYTE, this->imageO);
			}
			//this->setMipmap();
			//glGenerateMipmap(GL_TEXTURE_2D);//TODO image is in CPU memory AND GPU memory (in theory)
			//we need a way to send ALL of the texture data into GPU memory and keep it there until program ends
		}
	}
	
	~Texture()
	{
		//glActiveTexture(GL_TEXTURE0);
		//delete textures
		if(loaded)//flags != 0)
		{
			free(imageO);
		}
	}
};

class Skybox {
public:
	std::vector<int> width;
	std::vector<int> height;
	unsigned char* imageO1;
	unsigned char* imageO2;
	unsigned char* imageO3;
	unsigned char* imageO4;
	unsigned char* imageO5;
	unsigned char* imageO6;
	GLuint textureID;
	
	void createTex(char *filePath[6])
	{
		width.push_back(0);
		height.push_back(0);
		imageO1 = SOIL_load_image(filePath[0], &this->width[0], &this->height[0], 0, SOIL_LOAD_RGB);
		width.push_back(0);
		height.push_back(0);
		imageO2 = SOIL_load_image(filePath[1], &this->width[1], &this->height[1], 0, SOIL_LOAD_RGB);
		width.push_back(0);
		height.push_back(0);
		imageO3 = SOIL_load_image(filePath[2], &this->width[2], &this->height[2], 0, SOIL_LOAD_RGB);
		width.push_back(0);
		height.push_back(0);
		imageO4 = SOIL_load_image(filePath[3], &this->width[3], &this->height[3], 0, SOIL_LOAD_RGB);
		width.push_back(0);
		height.push_back(0);
		imageO5 = SOIL_load_image(filePath[4], &this->width[4], &this->height[4], 0, SOIL_LOAD_RGB);
		width.push_back(0);
		height.push_back(0);
		imageO6 = SOIL_load_image(filePath[5], &this->width[5], &this->height[5], 0, SOIL_LOAD_RGB);
	}
	
	void BindTexture()
	{
		if(imageO1 && imageO2 && imageO3 && imageO4 && imageO5 && imageO6)
		{
			glGenTextures(1, &textureID);
			glActiveTexture(GL_TEXTURE2);//we'll see
			glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);
			
			glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X, 0, GL_RGB, width[0], height[0], 0, GL_RGB, GL_UNSIGNED_BYTE, this->imageO1);
			free(this->imageO1);
			
			glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + 1, 0, GL_RGB, width[1], height[1], 0, GL_RGB, GL_UNSIGNED_BYTE, this->imageO2);
			free(this->imageO2);
			
			glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + 2, 0, GL_RGB, width[2], height[2], 0, GL_RGB, GL_UNSIGNED_BYTE, this->imageO3);
			free(this->imageO3);
			
			glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + 3, 0, GL_RGB, width[3], height[3], 0, GL_RGB, GL_UNSIGNED_BYTE, this->imageO4);
			free(this->imageO4);
			
			glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + 4, 0, GL_RGB, width[4], height[4], 0, GL_RGB, GL_UNSIGNED_BYTE, this->imageO5);
			free(this->imageO5);
			
			glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + 5, 0, GL_RGB, width[5], height[5], 0, GL_RGB, GL_UNSIGNED_BYTE, this->imageO6);
			free(this->imageO6);
				
			glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		}
	}
};

#endif
