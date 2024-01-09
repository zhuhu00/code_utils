import torch
import cudacpp_tutorial

feats = torch.ones(3)
points = torch.zeros(3)

print(cudacpp_tutorial.trilinear_interpolation(feats, points))