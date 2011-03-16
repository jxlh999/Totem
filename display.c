#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

static GLint    ImageWidth = 480;
static GLint    ImageHeight = 320;
static GLint    PixelLength;
static GLubyte* PixelData;

void display(void)
{
    // 清除屏幕并不必要
    // 每次绘制时，画面都覆盖整个屏幕
    // 因此无论是否清除屏幕，结果都一样
    // glClear(GL_COLOR_BUFFER_BIT);

    // 绘制像素
    glDrawPixels(ImageWidth, ImageHeight,
        GL_BGR_EXT, GL_UNSIGNED_BYTE, PixelData);

    // 完成绘制
    glutSwapBuffers();
}

int main(int argc, char* argv[])
{
    // 打开文件
    FILE* pFile = fopen("data.dat", "rb");
    if( pFile == 0 )
        exit(0);

    // 读取图象的大小信息
    // fseek(pFile, 0x0012, SEEK_SET);
    // fread(&ImageWidth, sizeof(ImageWidth), 1, pFile);
    // fread(&ImageHeight, sizeof(ImageHeight), 1, pFile);

    // 计算像素数据长度
    PixelLength = ImageWidth * 3;
    while( PixelLength % 4 != 0 )
        ++PixelLength;
    PixelLength *= ImageHeight;

    // 读取像素数据
    PixelData = (GLubyte*)malloc(PixelLength);
    if( PixelData == 0 )
        exit(0);

    // fseek(pFile, 54, SEEK_SET);
    fread(PixelData, PixelLength, 1, pFile);

    // 关闭文件
    fclose(pFile);

    // 初始化GLUT并运行
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(ImageWidth, ImageHeight);
    glutCreateWindow("data.dat");
    glutDisplayFunc(&display);
    glutMainLoop();

    // 释放内存
    // 实际上，glutMainLoop函数永远不会返回，这里也永远不会到达
    // 这里写释放内存只是出于一种个人习惯
    // 不用担心内存无法释放。在程序结束时操作系统会自动回收所有内存
    free(PixelData);

    return 0;
}
