#include <stdio.h>
#include <string.h>

int main() {

	char line[512];
	
    FILE *input  = fopen("debug.log", "r");
    FILE *output = fopen("error_only.txt", "w");

    if (!input || !output)
    {
        printf("请在程序目录放入 debug.log 测试文件\n");
        return 1;
    }

    while (fgets(line, sizeof(line), input))
    {
        if (strstr(line, "error") || strstr(line, "ERROR"))
        {
            fputs(line, output);
        }
    }

    fclose(input);
    fclose(output);
    printf("筛选完毕：error_only.txt\n");
    return 0;
}
