from setuptools import setup, Extension, find_packages
import numpy

extensions = Extension('factsumpy',  # name of our extension module
                        sources = ['src/cfactorial.c', 'src/_cfactorial.c'] )

setup(
    name='factsumpy', # A name show on Pypi.
    version='0.1', 
    ext_modules = [extensions],
    license='MIT',
    description='A Python pacakge to calculate the factorial of a natural number',
    long_description=open('README.md').read(),
    install_requires=[],
    url='https://github.com/',
    author='Xu Liu',
    author_email='liu.xu@sufe.edu.cn',
    include_dirs = [numpy.get_include()]
)
