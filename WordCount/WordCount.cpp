// WordCount.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)；
#define MAX 100 // 最大长度


int count_characters(FILE* file) {
    int char_count = 0; // 字符个数
    char ch;

    while ((ch = fgetc(file)) != EOF) {
        char_count++;
    }

    return char_count;
}//统计字符数

int count_words(FILE* file) {
    int word_count = 0; // 单词个数
    int flag = 0; // 控制单词个数增加
    char ch;

    while ((ch = fgetc(file)) != EOF) {
        if (ch == ' ' || ch == '\n' || ch == '\t' || ch == ',') {
            flag = 0;
        }
        else if (flag == 0) {
            flag = 1;
            word_count++;
        }
    }

    return word_count;
}//统计单词数

int main() {
    char param[3]; // 参数
    char fileName[MAX]; // 文件名
    scanf("%s %s", param, fileName);

    //打开文件,方式为只读
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error: Unable to open the file\n");
        return 1;
    }
    else if (strcmp(param, "-c") == 0) {
        printf("字符数：%d\n", count_characters(file));//"-c"统计字符
    }
    else if (strcmp(param, "-w") == 0) {
        printf("单词数：%d\n", count_words(file));//"-w"统计单词
    }

    // 关闭文件
    fclose(file);

    return 0;
}



// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
