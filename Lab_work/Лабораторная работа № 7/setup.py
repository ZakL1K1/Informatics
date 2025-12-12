from setuptools import setup, Extension

setup(
    name='Sub',
    version='1.0',
    ext_modules=[Extension('Sub', ['subtract_arrays.cpp'])]
)