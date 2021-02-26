#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int main(int argc, char** argv){
    if(argc != 4){
        clog << "Usage: " << argv[0] << " InputVideo OutputVideo granularity" << endl;
        return EXIT_FAILURE; //如果命令行不匹配，就直接退出
    }
    srand(time(0)); //设置随机数种子
    int q = atoi(argv[3]); //字符串转数字
    char* buffer = new char [q]; //动态分配缓冲区
    ifstream input(argv[1], ios_base::binary); //打开输入文件
    ofstream output(argv[2], ios_base::binary); //打开输出文件
    while(input.read(buffer, q)){
        buffer[q - 1] = rand() % 255;
        output.write(buffer, q);
    }
    output.write(buffer, q);
    input.close(); //关闭
    output.close(); //关闭
    return EXIT_SUCCESS;
}