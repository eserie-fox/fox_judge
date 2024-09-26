#!/bin/python

import sys
import os
import shutil
import subprocess

def process_subfolder(subfolder):
    # 定义文件夹路径
    program_folder = os.path.join(subfolder, '程序')
    input_folder = os.path.join(subfolder, '输入')
    output_folder = os.path.join(subfolder, '输出')
    tmp_folder = os.path.join(subfolder, 'tmp')
    original_directory = os.getcwd()
    # 检查文件夹是否存在
    if os.path.exists(program_folder) and os.path.exists(input_folder) and os.path.exists(output_folder):
        print('Test in ' + subfolder)
        # 创建 tmp 文件夹
        os.makedirs(tmp_folder, exist_ok=True)
        # 复制 fox_judge_for_checking 到 tmp 文件夹
        shutil.copy('./fox_judge_for_checking', tmp_folder)

        # 复制 std.cpp 和 sol.cpp 到 tmp
        for filename in ['std.cpp', 'sol.cpp']:
            src = os.path.join(program_folder, filename)
            if os.path.exists(src):
                shutil.copy(src, tmp_folder)

        # 复制输入文件到 tmp
        for file in os.listdir(input_folder):
            shutil.copy(os.path.join(input_folder, file), tmp_folder)

        # 复制输出文件到 tmp
        for file in os.listdir(output_folder):
            shutil.copy(os.path.join(output_folder, file), tmp_folder)

        # 进入 tmp 文件夹进行编译和运行
        os.chdir(tmp_folder)
        try:
            # 编译 std.cpp 和 sol.cpp
            subprocess.run(['g++', '-g', 'std.cpp', '-o', 'std'], check=True)
            subprocess.run(['g++', '-g', 'sol.cpp', '-o', 'sol'], check=True)



            # 运行 fox_judge_for_checking
            subprocess.run(['./fox_judge_for_checking', 'std', '1', '10', '.in', '.out'], check=True)
            subprocess.run(['./fox_judge_for_checking', 'sol', '1', '10', '.in', '.out'], check=True)

        except subprocess.CalledProcessError as e:
            print(f"Error processing {subfolder}: {e}")
            raise e

        # 返回根目录
        os.chdir(original_directory)
        shutil.rmtree(tmp_folder)

def main():
    # 获取用户输入的路径

    path = sys.argv[1]

    # 遍历子文件夹
    for root, dirs, files in os.walk(path):
        for dir_name in dirs:
            subfolder_path = os.path.join(root, dir_name)
            process_subfolder(subfolder_path)

if __name__ == "__main__":
    main()


