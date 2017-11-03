##嵌入式人脸检测

####特点:
        1.不依赖第三方库,采用seetaface人脸检测器
        2.我已经将其他部分去掉，留下核心,只要按照我的步骤,很简单移植
        3.效果是不错，但在一般的嵌入式设备上达不到实时，需要根据场景，下调精度，可以结合移动检测。
  
####步骤：
  1.修改CMakeList.txt中的交叉编译链,加上需要的flag，如果设备有硬件加速最好
  2.在build目录下,cmake.. && make 会生成动态库与静态库
  3.build目录下,face_test.c是我写的调用库文件的demo,arm-liunx-gcc face_test.c -o face_test  -L./ -lseeta_facedet_lib -lstdc++(注意，一定要加-lstdc++,否则有可能找不到c++库)
  
  
####文件说明：
    1.test.cpp:封装的一层可以由c语言调用的接口,各位可以自己设计，我只提供参考。
    2.face_test.c:C语言调用接口，各位可以类似的在各个嵌入式设备上取出yuv数据(y分量)调用接口。
    3.cpu_use.c:是查看嵌入式设备的cpu占有率，跑程序的时候可以开个线程监控cpu
   
由于这种开源项目都是抽空做的,时间有限可能考虑不周。如有问题，可以联系我。

####参考效果：
 海思3516cv300，输入：352x288
                                    最小窗口：30
                                    步长：4
                                     时间 2~3秒.
可以调步长在结合移动侦测也可以落地使用
![](./data/face.png)
  