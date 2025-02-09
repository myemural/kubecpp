import os

from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout, CMakeDeps
from conan.tools.files import copy

class kubecppRecipe(ConanFile):
    name = "kubecpp"
    version = "0.1.0"

    # Optional metadata
    license = "Apache-2.0"
    author = "Mustafa Yemural (myemural)"
    url = "https://github.com/myemural/kubecpp/tree/master"
    description = "Kubernetes Client Library for Modern C++"
    topics = ("kubernetes", "kubernetes-client", "k8s", "k8s-client")

    # Binary configuration
    settings = "os", "compiler", "build_type", "arch"

    options = {
        "shared": [True, False],
        "fPIC": [True, False],
        "build_examples": [True, False],
    }

    default_options = {
        "shared": False,
        "fPIC": True,
        "build_examples": True,
    }

    exports_sources = "CMakeLists.txt", "main.cpp", "src/*", "include/*"

    def config_options(self):
        if self.settings.os == "Windows":
            del self.options.fPIC

    def configure(self):
        if self.options.shared:
            del self.options.fPIC

    def layout(self):
        cmake_layout(self)

    def generate(self):
        deps = CMakeDeps(self)
        deps.generate()
        tc = CMakeToolchain(self)
        tc.cache_variables["BUILD_EXAMPLES"] = self.options.build_examples
        tc.generate()

    def requirements(self):
        self.requires("cpr/1.11.1")
        self.requires("rapidyaml/0.7.1")
        self.requires("rapidjson/cci.20230929")
        self.requires("gtest/1.15.0")

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        copy(self, "*.h", src=os.path.join(self.source_folder, "include"), dst=os.path.join(self.package_folder, "include"), keep_path=True)
        if self.settings.build_type == "Debug":
            copy(self, "*.lib", src=os.path.join(self.source_folder, "build/Debug"), dst=os.path.join(self.package_folder, "lib"), keep_path=False)
        elif self.settings.build_type == "Release":
            copy(self, "*.lib", src=os.path.join(self.source_folder, "build/Release"), dst=os.path.join(self.package_folder, "lib"), keep_path=False)
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ["kubecpp"]