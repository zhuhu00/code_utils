# Reference:
# https://github.com/cvpaperchallenge/Ascender
# https://github.com/nerfstudio-project/nerfstudio

# FROM nvidia/cuda:11.8.0-devel-ubuntu22.04
FROM nvidia/cuda:11.8.0-devel-ubuntu20.04
# FROM nvidia/cuda:11.7.1-devel-ubuntu20.04

ENV docker_name=temp


# # Set compute capability for nerfacc and tiny-cuda-nn
# # See https://developer.nvidia.com/cuda-gpus and limit number to speed-up build
# ENV TORCH_CUDA_ARCH_LIST="6.0 6.1 7.0 7.5 8.0 8.6 8.9 9.0+PTX"
# ENV TCNN_CUDA_ARCHITECTURES=90;89;86;80;75;70;61;60
# # Speed-up build for RTX 30xx
ENV TORCH_CUDA_ARCH_LIST="8.6"
ENV TCNN_CUDA_ARCHITECTURES=86
# # Speed-up build for RTX 40xx
# # ENV TORCH_CUDA_ARCH_LIST="8.9"
# # ENV TCNN_CUDA_ARCHITECTURES=89

ENV CUDA_HOME=/usr/local/cuda
ENV PATH=${CUDA_HOME}/bin:/home/${USER_NAME}/.local/bin:${PATH}
ENV LD_LIBRARY_PATH=${CUDA_HOME}/lib64:${LD_LIBRARY_PATH}
ENV LIBRARY_PATH=${CUDA_HOME}/lib64/stubs:${LIBRARY_PATH}

# # apt install by root user
RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends \
    build-essential \
    curl \
    git \
    libegl1-mesa-dev \
    libgl1-mesa-dev \
    libgles2-mesa-dev \
    libglib2.0-0 \
    libsm6 \
    libxext6 \
    libxrender1 \
    wget \
    tmux \
    vim \
    && rm -rf /var/lib/apt/lists/*

RUN mkdir -p ~/miniconda3
RUN wget https://repo.anaconda.com/miniconda/Miniconda3-py310_23.11.0-2-Linux-x86_64.sh -O ~/miniconda3/miniconda.sh
RUN bash ~/miniconda3/miniconda.sh -b -u -p ~/miniconda3
RUN rm -rf ~/miniconda3/miniconda.sh
RUN ~/miniconda3/bin/conda init bash

RUN echo "\nPS1='\[\e[1;35m\]\u@${docker_name}:\[\e[0m\]\[\e[1;33m\]\w\[\e[1;35m\]\[\e[0m\]\[\e[1;34m\]\$ \[\e[0m\]'" >> /root/.bashrc

WORKDIR /root/code