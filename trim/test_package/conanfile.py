from conans import ConanFile, CMake

class TrimPackageTestConan(ConanFile):
    name = "trim_package_test"
    generators = "cmake", "cmake_find_package"
    requires = "trim/1.0.0@nasir/wip"

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def test(self):
        self.run('./bin/trim_package_test', env="conanrun")
