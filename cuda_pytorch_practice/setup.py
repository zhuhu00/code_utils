from setuptools import setup, find_packages
from torch.utils.cpp_extension import BuildExtension, CUDAExtension, CppExtension

setup(
    name='cudacpp_tutorial',
    version='0.1',
    ext_modules=[
        CppExtension(
            name='cudacpp_tutorial',
            sources=['interpolation.cpp']
        )
    ],
    cmdclass={
        'build_ext': BuildExtension
    }
)