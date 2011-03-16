#include <stdio.h>

unsigned char bmp_file_header[] = {
// 424D 4690 0000 0000 0000 4600 0000 2800 0000 8000 0000 9000 0000 0100
    0x42 /*'B'*/, 0x4d /*'M'*/, 0x36, 0x70, 0x17, 0x00 /*3-6 size of file*/, 0x00, 0x00, 0x00, 0x00 /*7-10 reserved*/,
    0x36, 0x00, 0x00, 0x00 /*11-14 offset to data*/, 0x28, 0x00, 0x00, 0x00 /*15-18 size of info*/,
    0xE0, 0x01, 0x00, 0x00 /*19-22 width*/, 0x20, 0x03, 0x00,0x00 /*23-26 height*/, 0x01, 0x00 /*dimesion always 1*/
};
// 0xe0, 0x01, 0x00, 0x00  0x40, 0x01, 0x00,0x00
unsigned char bmp_info_header[] = {
    0x20, 0x00 /*29-30 pixel bit*/, 0x00, 0x00, 0x00, 0x00 /*31-34 compress*/, 0x00, 0x70, 0x17, 0x00/*35-38 size of data*/,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 /*39-42 dpi of hori 43-46 dpi of vert*/, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00
};

void SaveBMPFile(char *file_name, char *buf, int size)
{
    FILE *file = fopen(file_name, "w");
    if (!file)
    {
	printf ("open file error.\n");
	return;
    }
    fseek(file, 0, SEEK_SET);
    int nread = fwrite(bmp_file_header, sizeof(bmp_file_header), sizeof(bmp_file_header), file);
    printf ("write bmp file\n");
    printf ("nread = %d\n", nread);
    printf ("sizeof(bmp_file_header) = %ld\n", sizeof(bmp_file_header));
    if (nread != sizeof(bmp_file_header))
    {
	printf ("write bmp_file_header error.\n");
	return;
    }
    fseek(file, sizeof(bmp_file_header), SEEK_SET);
    nread = fwrite(bmp_info_header, sizeof(bmp_info_header), sizeof(bmp_info_header), file);
    printf ("write bmp info\n");
    printf ("nread = %d\n", nread);
    printf ("sizeof(bmp_info_header) = %ld\n", sizeof(bmp_info_header));
    if (nread != sizeof(bmp_info_header))
    {
	printf ("write bmp_info_header error.\n");
	return;
    }
    fseek(file, sizeof(bmp_file_header) + sizeof(bmp_info_header), SEEK_SET);
    printf ("pos = %ld\n", ftell(file));
    int nwrite = fwrite(buf, 1, size, file);
    printf ("nwrite = %d\n", nwrite);
    //printf ("nread = %d\n", nread);
    //printf ("size = %d\n", size);
    /*if (nread != size)
    {
	printf ("write buf error.\n");
	return;
	}*/
    printf ("write successfully.\n");
    fclose(file);
}

int main(int argc, char *argv[])
{
    unsigned char buf[480 * 800 * 4];
    memset(buf, 0, sizeof(buf));
    FILE *fp = fopen("./data", "r");
    if (!fp)
    {
	printf ("open file error.\n");
	return 1;
    }
    int nread = fread(buf, 1, sizeof(buf), fp);
    printf ("nread = %d\n", nread);
    printf ("sizeof(buf) = %ld\n", sizeof(buf));
    if (nread != sizeof(buf))
    {
	printf ("read file error.\n");
	return 1;
    }
    fclose(fp);
    SaveBMPFile("screen.bmp", buf, sizeof(buf));
    return 0;
}
