#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include<strings.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void dfs(int v,int c,int* color,int** graph,int b){
	int k;
	color[v]=c;
	k++;
	for(int j=0;j<b;j++){
		if(graph[v][j]&&color[v]==0) dfs(j,c,color,graph,b);}
 	return;}

int main(){
	char* inputPath ="hampster.png";
	int iw,ih,n,c=0,s,t,b;
	unsigned char * idata = stbi_load(inputPath,&iw,&ih,&n,0);
	int** graph =malloc(iw*ih*iw*ih*(sizeof(int)));
	int* color=malloc(iw*ih*(sizeof(int)));
	if (idata == NULL){
		printf("ERROR: can't read file \n");
		return 1;} 
	char *pixel =idata;
	unsigned char* odata=malloc(iw*ih*(sizeof(unsigned char)));
	for(int i=0;i<iw*ih*n;i+=4){
		odata[c]=(pixel[i]*11+pixel[i+1]*16+5*pixel[i+2])/32;	
		c+=1;}
	b=iw*ih;
	for(s=0;s<=iw*ih;s++){
		color[s]=0;
		for(t=0;t<=iw*ih;t++){
			if(abs(odata[s]-odata[t])<20){
				graph[s][t]=1;}
			else{	graph[s][t]=0;}	
}
}

	for(s=0;s<iw*ih;s++){
		if(color[s]==0){
			dfs(s,odata[s],color,graph,b);}}
		 
	for(s=0;s<iw*ih;s++){
		for(t=s;t<iw*ih;t++){
			if(color[s]==color[t]){
				odata[t]+=1;}
}
}
				
char *outputPath="output.png";
stbi_write_png(outputPath,iw,ih,1,odata,0);
stbi_image_free(idata);
stbi_image_free(odata);
printf("Loaded image with a width of %dpx,a height of %dpx and %d channels\n",iw,ih,n);
return 0;
}
