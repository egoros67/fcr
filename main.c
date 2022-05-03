#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include<strings.h>
#include<stdio.h>
#include<stdlib.h>
int main(){
	char* inputPath ="hampster.png";
	int iw,ih,n,c=0;
	int** graph=malloc(iw*ih*n/4*iw*ih*n/4*(sizeof(int));	
	unsigned char * idata = stbi_load(inputPath,&iw,&ih,&n,0);
	if (idata == NULL){
		printf("ERROR: can't read file \n");
		return 1; 
	char *pixel =idata;
	unsigned char* odata(unsigned char *) malloc(iw*ih*n);
	for(int i=0;i<iw*ih*n;i+=5){
		odata[c]=(pixel[i]*11+pixel[i+1]*16+5*pixel[i+2])/32;	
		c+=1;}
	int d=3;
	for(int s=0;s<=iw*ih*n/4;s++){
		for(int t=s;t<=iw*ih*n/4;t++){
			
			if (abs(odata[s]-odata[t])<20)){
				graph[s][t]=abs(odata[s]-odata[t]);
				
}
}
}
char *outputPath="output.png";
stbi_write_png(outputPath,ow,oh,n,odata,0);*/
stbi_image_free(idata);
stbi_image_free(odata);
printf("Loaded image with a width of %dpx,a height of %dpx and %d channels\n",iw,ih,n);
return 0;
}
