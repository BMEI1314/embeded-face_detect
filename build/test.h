#ifndef _TEST_H
#define _TEST_H
extern "C" typedef struct Point_Info{
  int x;
  int y;
  int width;
  int height;
}Point_Info;
extern "C" typedef struct Face_Info{
 int face_num;
 Point_Info point_Info[10];
}Face_Info;
extern "C" void lib_dana_fd_init(int minFace,int MaxFace,int Win_step);
extern "C" void lib_dana_fd_proc(int width,int height,unsigned char* img,Face_Info face_info);
 


#endif
