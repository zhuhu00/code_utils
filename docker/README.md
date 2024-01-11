# 使用 ssh 连接服务器上面的 docker 容器
而不是通过链接服务器，再链接 docker
通过 ssh 连接docker，这里使用了秘钥的方式，可以在 dockerfile 里面进行修改。

## 通过 ssh 连接
- 目前设定为默认端口，映射的端口为 `10022`，应该是没啥人用的端口，多个容器会改`10022`为`20022`，也就是只改变最前面
- 本地连接服务器的 docker 容器时，需要将本地的 pub的 key 上传到镜像中，在 dockerfile 中进行修改即可。
- 目前镜像构建默认为 `cuda11.8-ubuntu20`，也可以换成其他的
    ```dockerfile
    # FROM nvidia/cuda:11.8.0-devel-ubuntu22.04
    FROM nvidia/cuda:11.8.0-devel-ubuntu20.04
    # FROM nvidia/cuda:11.7.1-devel-ubuntu20.04
    ```
- 默认构建的是 python3.10 的 conda 基础环境，pytorch=2.0.0
    ```dockerfile
    # torch 环境，默认 2.0.0, cuda 11.8, python 3.10
    RUN conda install pytorch==2.0.0 torchvision==0.15.0 torchaudio==2.0.0 pytorch-cuda=11.8 -c pytorch -c nvidia -y \
    && pip install ninja ipdb
    ```