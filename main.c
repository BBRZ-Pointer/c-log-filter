#include <stdio.h>
#include <string.h>

// argc 参数个数
// argv 字符串数组：argv[1] 就是你输入的自定义文件名

int main(int argc, char *argv[]) {
	
	// 如果用户没输入日志文件名（参数小于2个）
	if (argc < 2) {
	    // 打印标准用法提示
        printf("用法：你的日志文件名.exe \n");
        return 1; // 直接退出程序，用户重新使用程序
    }
	
	// 打开用户输入的任意日志文件：argv[1] 只读模式
	FILE* input = fopen(argv[1], "r");
	 // 固定输出筛选后的错误日志 写入模式 "w"，自动新建/覆盖error_only.txt
	FILE* output = fopen("error_only.txt", "w");
	
	//任意文件打开失败直接退出
	if(!input || !output) {
	    printf("文件打开失败\n");
	    return 1;
	}
	
	// 每行最多读 512 字符缓冲区完全足够
	 char line[512];
	
	// 循环逐行读取日志
	while (fgets(line, sizeof(line), input)) {
	     // 判断当前行是否包含 error 或 ERROR
	    if(strstr(line, "error") || strstr(line, "ERROR")) {
	        // 命中出现错误行写入结果文件
	        fputs(line, output);
	    }
	}
	
	fclose(input);// 关闭原始日志文件，释放资源
	fclose(output); // 关闭结果输出文件，确保数据全部保存
	printf("筛选完毕：error_only.txt\n");// 提示用户任务完成生成error_only.txt文件或者重新error_only.txt文件
	return 0;

}

