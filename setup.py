import os
from setuptools import setup
from distutils.core import setup, Extension
from Cython.Distutils import build_ext

setup(
    name='bpo46451',
    py_modules=["bpo46451", "bpo46451.mod"],
    cmdclass={"build_ext": build_ext},
    ext_modules=[
        Extension('bpo46451.test', ['bpo46451/test.c']),
        Extension('bpo46451.cytest', ['bpo46451/cytest.pyx'])],
    )

