#include <cstdint>
#include <fstream>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream> 
#include <time.h>
#include <algorithm>
#include <unistd.h>
#include "face_detection.h"
#include "test.h"

seeta::FaceDetection detector("/home/seeta_fd_frontal_v1.0.bin");
void lib_dana_fd_init(int minFace,int MaxFace,int Win_step)
{
  
  detector.SetMinFaceSize(minFace);
  detector.SetMaxFaceSize(MaxFace);
  detector.SetScoreThresh(2.f);
  detector.SetImagePyramidScaleFactor(0.8f);
  detector.SetWindowStep(Win_step,Win_step);

}
void lib_dana_fd_proc(int width,int height,unsigned char* img,Face_Info face_info)
{
   seeta::ImageData img_data;
   img_data.data=img;
   img_data.width=width;
   img_data.height=height;
   img_data.num_channels=1;
   std::vector<seeta::FaceInfo> faces = detector.Detect(img_data);
   int32_t num_face = static_cast<int32_t>(faces.size());
   face_info.face_num=num_face;
   int i;
   for(i=0;i<num_face;i++)
   {
      face_info.point_Info[i].x=faces[i].bbox.x;
      face_info.point_Info[i].y=faces[i].bbox.y;
      face_info.point_Info[i].width=faces[i].bbox.width;
      face_info.point_Info[i].height=faces[i].bbox.height;
   }
}
