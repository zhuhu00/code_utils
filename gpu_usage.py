# Description: 通过SSH连接到多台服务器，获取GPU使用情况

import paramiko
import time

# 定义服务器信息
servers = [
    {"hostname": "10.21.4.15", "port": 22, "username": "hzhu"},
    {"hostname": "10.21.4.16", "port": 22, "username": "hzhu"},
    # 添加更多服务器信息
]

# 定义本地私钥文件的路径
private_key_path = "/Users/hu/.ssh/id_rsa"

# 获取 GPU 使用情况的命令
gpu_command = "source ~/.zshrc && conda activate base && gpustat"

def get_gpu_usage(server):
    hostname = server['hostname']
    port = server['port']
    username = server['username']

    # 创建SSH客户端
    ssh = paramiko.SSHClient()
    ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())

    try:
        # 加载本地SSH私钥
        private_key = paramiko.RSAKey.from_private_key_file(private_key_path)

        # 连接到服务器
        ssh.connect(hostname, port, username, pkey=private_key, timeout=10)

        # 执行GPU使用情况命令
        stdin, stdout, stderr = ssh.exec_command(gpu_command)
        output = stdout.read().decode()

        # 打印服务器名称和输出
        print(f"Server: {hostname}")
        print(output)

    except Exception as e:
        print(f"Failed to connect to {hostname}: {e}")

    finally:
        # 关闭SSH连接
        ssh.close()

# 检查每台服务器的GPU使用情况
for server in servers:
    get_gpu_usage(server)
    time.sleep(1)  # 可选：为避免过多连接，添加延迟
