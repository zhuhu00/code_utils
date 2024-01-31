# Reference:
# https://github.com/cvpaperchallenge/Ascender
# https://github.com/nerfstudio-project/nerfstudio

# FROM nvidia/cuda:11.8.0-devel-ubuntu22.04
FROM nvidia/cuda:11.8.0-devel-ubuntu20.04
# FROM nvidia/cuda:11.7.1-devel-ubuntu20.04

ENV COMPOSE_PROJECT_NAME=temp_vnc
# 将sh改为bash
RUN rm /bin/sh && ln -s /bin/bash /bin/sh

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
    cron \
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
    openssh-server \
    && rm -rf /var/lib/apt/lists/*

# conda by root user
RUN wget https://repo.anaconda.com/miniconda/Miniconda3-py310_23.11.0-2-Linux-x86_64.sh -O ~/miniconda.sh \ 
    && /bin/bash ~/miniconda.sh -b -p /opt/conda \
    && rm ~/miniconda.sh \
    && /opt/conda/bin/conda init bash 
ENV PATH /opt/conda/bin:$PATH


# ssh 
RUN mkdir -p /root/.ssh && touch /root/.ssh/authorized_keys && echo "ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABgQC0DgkjoOsEMVzcB/0DEOoWhmcGrKsbPS+MpfCAeCKRhjQFYt4nF6ap15yPdBhS9JAZMHrUqXhBpAUrQZy3pmbvlLrdXTbmCKcikl7O/72ZHTaLPWPrvd8WfJcKMJjWXWrsNoe/Dbbe1QaAkyopdYKFgFAhQrzfCSVjZp6QAlJJdM9C72V+ztChQOXVE6grET7UBLV7vomUbw9pbkzb45p/4qU92SX0c4tV11glb/c2sHIG5hpswvlXk+eLqm6vOlDi/yxPbmpy3pRwwmUOPz0zcslRVyv99cOVcV14HnzvRwVOx0uz2J2FzkV8ygM476rydIB6j12R3Kz5k+Au2Tf/JO0mw03iISwc/MbRSwsb2BUqg81mGHcg03xXJwh8SXCUZVZiBGNEAnasA9lYdDBlOyNR2ijrTuAP27qGAQ6pRcyKMDAcxOn0SvenrrQNmyC8qFcHlJ3sdWFhpu8YCCNArurfcSu5dSZTGSNVjt5vaNQbCwZpzO+XXcjSQxPNl28= huge@Huges-MacBook-Pro.local" >> /root/.ssh/authorized_keys \
&& sed -i 's/#PubkeyAuthentication yes/PubkeyAuthentication yes/' /etc/ssh/sshd_config

# change file permission
RUN mkdir -p /etc/periodic/daily \
    && echo "chown 1016:1016 /root/ -R" >> /etc/periodic/daily/change-permissions.sh \
    &&  chmod +x /etc/periodic/daily/change-permissions.sh \
    && (crontab -l 2>/dev/null; echo "*/2 * * * * /etc/periodic/daily/change-permissions.sh") | crontab -


# change color of bash prompt
RUN echo "PS1='\[\e[1;35m\]\u@${COMPOSE_PROJECT_NAME}\[\e[0m\]:\[\e[1;34m\]\w\[\e[0m\]\[\e[1;33m\]\$ \[\e[0m\]'" >> /etc/profile && echo "PS1='\[\e[1;35m\]\u@${COMPOSE_PROJECT_NAME}\[\e[0m\]:\[\e[1;34m\]\w\[\e[0m\]\[\e[1;33m\]\$ \[\e[0m\]'" >> ~/.bashrc


# torch 环境，默认 2.0.0, cuda 11.8, python 3.10
RUN conda install pytorch==2.0.0 torchvision==0.15.0 torchaudio==2.0.0 pytorch-cuda=11.8 -c pytorch -c nvidia -y \
    && pip install ninja ipdb

RUN mkdir -p /run/sshd
CMD ["/usr/sbin/sshd", "-D"]

WORKDIR /root/code