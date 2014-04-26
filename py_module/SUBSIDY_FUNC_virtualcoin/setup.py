from distutils.core import setup
from distutils.extension import Extension

setup(name="virtualcoin_subsidys",
    ext_modules=[
        Extension("virtualcoin_subsidy", ["virtualcoin_GetBlockBaseValue.cpp"],
        libraries = ["boost_python"])
    ])
