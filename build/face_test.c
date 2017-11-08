#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include "lib_fd.h"
int main()
{
   Face_Info face_info;
   lib_dana_fd_init(30,100,4);
    FILE *video;
    FILE  *video_out;
    unsigned char  *image_data=( unsigned char *)malloc(sizeof( unsigned char)*720*1280);
   video=fopen("face1.yuv","rb");
    video_out=fopen("face_out.yuv","wb");
  if(video==NULL)
   {
    printf("\t\topen file failed!\n");
    return 0;
   }   
  while(1){ 
    if(video==NULL)
    break;
    fread(image_data,352*288,1,video);
    lib_dana_fd_proc(352,288,image_data,face_info);
   
   }
   return 0;

}
