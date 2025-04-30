# 使用amd64架构的Ubuntu镜像（兼容32位库）
FROM --platform=linux/amd64 ubuntu:20.04

# 禁用交互提示
ENV DEBIAN_FRONTEND=noninteractive

# 添加 i386 架构支持，并安装必要的包
RUN apt-get update
RUN dpkg --add-architecture i386
RUN apt-get install -y \
        build-essential \
        make \
        vim \
        dos2unix \
        gdb \
        libc6-dev-i386 \
        valgrind \
        gcc-multilib \
        g++-multilib

RUN rm -rf /var/lib/apt/lists/*
