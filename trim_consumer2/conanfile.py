from conans import ConanFile, CMake, tools
from pprint import pprint

class TrimConsumer2(ConanFile):
    name = "trim_consumer2"
    generators = "cmake", "cmake_find_package"
    requires = "trim/1.0.0@nasir/wip"

    def requirements(self):
        print('deps_cpp_info:')
        pprint(vars(self.deps_cpp_info))

    def package_info(self):
        self.cpp_info.requires = ["trim::ai"]
