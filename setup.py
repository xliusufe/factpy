from setuptools import setup, Extension, find_packages
import numpy

VERSION = '1.0'
extensions = Extension(name = 'fact._factpy',  # name of our extension module
                        sources = ['src/cfactorial.c', 'src/_cfactorial.c'],
                        include_dirs = ['src'],
                        language='c++' 
                        )


setup(
    name='factpy', # A name show on Pypi.
    version=VERSION, 
    packages = ['fact'],
    ext_modules = [extensions],
    license='MIT',
    description='A Python pacakge to calculate the factorial of a natural number',
    long_description=open('README.md').read(),
    install_requires=[],
    url='https://github.com/xliusufe/factpy/',
    author='Xu Liu',
    author_email='liu.xu@sufe.edu.cn',
    maintainer="Xu Liu",
    maintainer_email='liu.xu@sufe.edu.cn',  
    include_dirs = [numpy.get_include()],
    python_requires='>=3.5'
)
