# Kubernetes Client Library for Modern C++ (kubecpp)

![](/docs/images/kubecpp_logo.png?raw=true)

**kubecpp** is a community-maintained Kubernetes client API project written using C++17 standards (modern C++). The main goal of this project is to write a Kubernetes client API with modern C++ that has high usability. The main goal of the project is not performance and security. However, this may change in future versions.

## Getting Started

### Prerequisites

3rd party libraries that are dependent on:
- cpr 1.11.1
- nlohmann_json 3.11.3
- rapidyaml 0.7.1

For compiling and installation:
- CMake 3.24+
- Conan 2.4+
- MSVC 19.40+ (for Windows)
- Ninja 1.12+ (optional)

Optional dependencies:
- clang-format (LLVM)
- clang-tidy (LLVM)

### Build

This project currently uses the Conan package manager. It also resolves 3rd party dependencies via Conan. Before you start building the project with Conan, you need to create a profile. To do this, you can follow the [Introduction to profiles](https://docs.conan.io/2/reference/config_files/profiles.html) guide on the Conan website. The profile file you create will look like this:

```
[settings]
arch=x86_64
build_type=Debug
compiler=msvc
compiler.cppstd=17
compiler.runtime=dynamic
compiler.runtime_type=Debug
compiler.version=193
os=Windows
```

If you see a problem with the build type or the C++ standard, you can try changing the profile file manually. The second thing you should pay attention to is the default Conan remote server. After the Conan 2 version, the Conan 1 package server is no longer used. Therefore, you need to change your default Conan server to Conan 2. Now, you can use the following command to see the default Conan remote:

```bash
conan remote list
```

The output should be like this:

```
conancenter: https://center2.conan.io [Verify SSL: True, Enabled: True]
```

If it is not, you can see the [conan remote](https://docs.conan.io/1/reference/commands/misc/remote.html) reference page to change Conan remote. After everything is ready, you can install the `kubecpp` package to the system by running the `conan create` command in the main working directory.

For Debug:

```bash
conan install . -s build_type=Debug --build=missing
```

For Release:

```bash
conan install . -s build_type=Release --build=missing
```

After that you can configure and build very easily using CMake Presets:

```bash
cmake --preset conan-default
```

```bash
cmake --build --preset conan-debug
```

If the configure and build preset names here are different, you can check them respectively as follows:

```bash
cmake --list-presets
```

```bash
cmake --build --list-presets
```

Alternatively, after doing a `conan install`, you can use the traditional CMake build instead of CMake Presets like this:

```bash
cd build
cmake ..
cmake --build .
```

## Usage

Since the `BUILD_EXAMPLES` cache variable is `ON` by default, the examples will be compiled automatically when you perform the build steps. All you have to do after that is modify the example source code as you wish and compile using traditional CMake compilation or CMake Presets. You can find examples and their source codes in `examples` folder.

**Important Note:** Please don't forget to change `<PUT_YOUR_KUBECONFIG_PATH_HERE>` string in example code to execute it properly. This example requires a Kubernetes cluster to properly work. If you don't know how to install Kubernetes in your local, please check these links:

- [MicroK8s](https://microk8s.io/#install-microk8s)
- [minikube](https://minikube.sigs.k8s.io/docs/start/?arch=%2Fwindows%2Fx86-64%2Fstable%2F.exe+download)
- [kind](https://kind.sigs.k8s.io/docs/user/quick-start/)

## Environment Support

Currently, the following compilers are known to work:

- MSVC 19.42 (or later)

But we will test it on other compilers and versions as quickly as possible. We plan to increase this with local builds or using CI/CD.

## Roadmap

This project is in POC (Proof of Concept) phase currently. Only models and operations for `Pod v1` resource are supported for now (partially). The initial goal is to support all `Core v1` models and operations:

- [x] [Pod v1](https://kubernetes.io/docs/reference/kubernetes-api/workload-resources/pod-v1/)
- [ ] [Binding v1](https://kubernetes.io/docs/reference/kubernetes-api/workload-resources/binding-v1/)
- [ ] [PodTemplate v1](https://kubernetes.io/docs/reference/kubernetes-api/workload-resources/pod-template-v1/)
- [ ] [ReplicationController v1](https://kubernetes.io/docs/reference/kubernetes-api/workload-resources/replication-controller-v1/)
- [ ] [Service v1](https://kubernetes.io/docs/reference/kubernetes-api/service-resources/service-v1/)
- [ ] [Endpoints v1](https://kubernetes.io/docs/reference/kubernetes-api/service-resources/endpoints-v1/)
- [ ] [ConfigMap v1](https://kubernetes.io/docs/reference/kubernetes-api/config-and-storage-resources/config-map-v1/)
- [ ] [Secret v1](https://kubernetes.io/docs/reference/kubernetes-api/config-and-storage-resources/secret-v1/)
- [ ] [PersistentVolumeClaim v1](https://kubernetes.io/docs/reference/kubernetes-api/config-and-storage-resources/persistent-volume-claim-v1/)
- [ ] [PersistentVolume v1](https://kubernetes.io/docs/reference/kubernetes-api/config-and-storage-resources/persistent-volume-v1/)
- [ ] [ServiceAccount v1](https://kubernetes.io/docs/reference/kubernetes-api/authentication-resources/service-account-v1/)
- [ ] [LimitRange v1](https://kubernetes.io/docs/reference/kubernetes-api/policy-resources/limit-range-v1/)
- [ ] [ResourceQuota v1](https://kubernetes.io/docs/reference/kubernetes-api/policy-resources/resource-quota-v1/)
- [ ] [ComponentStatus v1](https://kubernetes.io/docs/reference/kubernetes-api/cluster-resources/component-status-v1/)
- [ ] [Namespace v1](https://kubernetes.io/docs/reference/kubernetes-api/cluster-resources/namespace-v1/)
- [ ] [Node v1](https://kubernetes.io/docs/reference/kubernetes-api/cluster-resources/node-v1/)

Additionally, GitHub Actions integration will be added very soon. Also the first phase of the project lacks:
- A proper error handling mechanism
- JSON to model conversion
- YAML to model conversion
- Model to YAML conversion
- Comprehensive Kubeconfig integration (environment variable, in-cluster support etc.)
- A proper Debug/Release scheme
- Multi-platform and compiler support (GNU/Linux, MacOS etc.)
- A proper versionun and release scheme
- Unit testing integration

## Contributing

### Code of Conduct

Before start, please review our `CODE_OF_CONDUCT.md` to learn community rules and agreements.

### How to Contribute?

Our door is open to all developers. Don't forget to read the [contribution guide](/CONTRIBUTING.md) before contributing!

### Current Contributors

Maintainers
- [myemural](https://github.com/myemural)

## License

Distributed under the Apache-2.0 License. See `LICENSE` file for more information.

## Contact

Mustafa Yemural
- [LinkedIn](https://www.linkedin.com/in/mustafa-yemural/)
- [GitHub](https://github.com/myemural)

Project Link: https://github.com/myemural/kubecpp