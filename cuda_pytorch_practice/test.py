import torch
import cudacpp_tutorial
import time

def trilinear_interpolation_py(feats, points):
    """
    Inputs:
        feats: (N, 8, F)
        points: (N, 3) local coordinates in [-1, 1]
    
    Outputs:
        feats_interp: (N, F)
    """
    u = (points[:,0:1]+1)/2
    v = (points[:,1:2]+1)/2
    w = (points[:,2:3]+1)/2
    a = (1-v)*(1-w)
    b = (1-v)*w
    c = v*(1-w)
    d = 1-a-b-c

    feats_interp = (1-u)* (a*feats[:,0,:] + b*feats[:,1,:] + c*feats[:,2,:] + d*feats[:,3,:]) + \
            u * (a*feats[:,4,:] + b*feats[:,5,:] + c*feats[:,6,:] + d*feats[:,7,:])
    return feats_interp


class TrilinearInterpolation(torch.autograd.Function):
    @staticmethod
    def forward(ctx, feats, points):
        """
        Inputs:
            feats: (N, 8, F)
            points: (N, 3) local coordinates in [-1, 1]
        
        Outputs:
            feats_interp: (N, F)
        """
        feats_interp = cudacpp_tutorial.trilinear_interpolation_fw(feats, points)
        ctx.save_for_backward(feats, points)
        return feats_interp

    @staticmethod
    def backward(ctx, grad_output):
        feats, points = ctx.saved_tensors
        grad_feats = cudacpp_tutorial.trilinear_interpolation_bw(grad_output.contiguous(), feats, points)
        return grad_feats, None


def main():
    N = 35566; F = 256
    rand = torch.rand(N,8,F, device='cuda')

    feats1 = rand.clone().requires_grad_()
    feats2 = rand.clone().requires_grad_()
    points = torch.rand(N, 3, device='cuda')*2-1

    t =time.time()
    out_cuda = TrilinearInterpolation.apply(feats1, points)
    torch.cuda.synchronize()
    print('cuda time: ', time.time()-t)

    t =time.time()
    out_torch = trilinear_interpolation_py(feats2, points)
    torch.cuda.synchronize()
    print('torch time: ', time.time()-t)

    print("fw all close: ", torch.allclose(out_cuda, out_torch))

    t =time.time()
    loss2 = out_cuda.sum()
    loss2.backward()
    torch.cuda.synchronize()
    print('cuda time: ', time.time()-t)

    t =time.time()
    loss1 = out_torch.sum()
    loss1.backward()
    torch.cuda.synchronize()
    print('torch time: ', time.time()-t)

    print("bw all close: ", torch.allclose(feats1.grad, feats2.grad))


main()