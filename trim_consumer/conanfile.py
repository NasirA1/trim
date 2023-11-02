from conans import ConanFile, CMake, tools
from pprint import pprint

class TrimConsumer(ConanFile):
    name = "trim_consumer"
    generators = "cmake", "cmake_find_package"
    requires = "trim/1.0.0@nasir/wip"
