import trimesh
import matplotlib.pyplot as plt
from PIL import Image
import numpy as np

# 加载模型
obj_file = './assets/raw_model.obj'
mtl_file = './assets/model.mtl'
texture_file = './assets/texture.png'

mesh = trimesh.load(obj_file, process=False)
mesh.visual = trimesh.visual.material.SimpleMaterial(image=texture_file)
mesh.show()