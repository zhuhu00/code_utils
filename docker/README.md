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


安装openssh: `apt-get update；apt-get install openssh-server`

设置sshroot登录：`echo "PermitRootLogin yes" >> /etc/ssh/sshd_config`

重启ssh服务：`service ssh restart`

设置root密码：`passwd root`

也可以不设置密码，传入 `ssh_pub`

过程如下
```shell
ssh-keygen -t rsa -b 4096
# 将生成为的 ~/.ssh/id_rsa.pub，内容贴到 .ssh/authorized_keys中，再重启一下服务器 ssh 服务
service ssh restart
```

# VNC 设置
```bash
apt install tigervnc-standalone-server tigervnc-common -y

apt install xfce4 xfce4-goodies xorg dbus-x11 x11-xserver-utils -y

git clone https://github.com/novnc/noVNC.git

# 创建启动脚本
mkdir $HOME/.vnc
touch $HOME/.vnc/xstartup
 
# 执行此命令之前在容器内安装了vim
vim $HOME/.vnc/xstartup
 
## 添加以下脚本(如果有乱码，删除脚本中的中文配置)

#!/bin/bash
 
unset SESSION_MANAGER 
unset DBUS_SESSION_BUS_ADDRESS 
startxfce4 &    # launch xface4
[ -x /etc/vnc/xstartup ] && exec /etc/vnc/xstartup 
[ -r $HOME/.Xresources ] && xrdb $HOME/.Xresources 
xsetroot -solid grey    # set background color
 
# 保存并关闭文件。无论何时启动或者重启TigerVNC服务器，都将会自动执行上述命令

# 使用chmod
chmod +x ~/.vnc/xstartup

vncserver :107 -localhost no

vncserver -localhost novncserver -list


./utils/novnc_proxy --vnc localhost:5902 --web /home/noVNC
```