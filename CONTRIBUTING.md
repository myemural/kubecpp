# Contributing Guidelines

## Welcome!

First of all, I would like to welcome and thank everyone who wants to contribute to this project. Kubernetes is a technology that is widely used today and continues to be widespread. In my opinion, not being able to communicate with such technology directly using modern C++ is a deficiency. With this motivation, I decided to do the **kubecpp** project. If you are ready, let me give you the details on how you can contribute to the project.

## Prerequisites

Before you start contributing, I recommend completing a few steps.

### Create a GitHub Account

Before you get started, you will need to [sign up](http://github.com/signup) for a GitHub user account. It doesn't matter whether it's a free or paid account.

### Code of Conduct

Since community rules are as important here as they are everywhere, I recommend you review the [Code of Conduct](/CODE_OF_CONDUCT.md) section.

### Fork the Repo

I recommend that you fork the main repo and clone this fork to your local environment. Detailed information about using Git and GitHub will not be given here. You can research and learn how to do it on the internet.

## Roles and Responsibilities

| Role         | Responsibilities                                       | Requirements                                                                                      |
| ------------ | ------------------------------------------------------ | ------------------------------------------------------------------------------------------------- |
| Contributor  | Active contributor in the community                    | There is no limitation to become contributor for now                                              |
| Collaborator | Review contributions from other members and accept PRs | This role can be assigned by the maintainer to people who contribute a lot to the project         |
| Maintainer   | Lead whole repo and can directly commit to the repo    | Experienced active reviewer and contributor to the project, also can be chosen from collaborators |

## Version Scheme

In this project, versioning is done according to the [Semantic Versioning 2.0](https://semver.org/) standard.

## How to Contribute?

### Committing Your Changes

In this project, the commit message format will be kept very simple. First, let me give the general format:

```
[action]: [message]
```

Action keywords:
- **Added:** This action is used when a new feature, functionality, class, function, or type is added.
- **Updated:** This action is used when a piece of code or feature is updated.
- **Deleted:** This action is used when a piece of code or feature is deleted.
- **Fixed:** This action is used when an existing error in a piece of code is fixed.

Examples:

```
Added: New PodTemplate model class to the project
```

```
Deleted: String utils implementation
```

```
Fixed: Localization problems about xyz module
```

The message should be clear and concise. It should not be too general or too specific. It should briefly state exactly what was done in that task. There is no specific length for the message (for now). It is also recommended that each task you do be divided into smaller commits.

### Opening a PR

I recommend you follow GitHub's [Creating a pull request](https://docs.github.com/en/pull-requests/collaborating-with-pull-requests/proposing-changes-to-your-work-with-pull-requests/creating-a-pull-request) guide on this subject. Detailed information on this subject will come later. When opening a PR from your own personal forks, be careful to open it in the `dev` branch of the repo.

### CI/CD

There is currently no CI/CD process in the project, but GitHub Actions integration will be added very soon.

## How to Ask a Question?

You can ask your questions in the Issues section in English or Turkish. Issues you open here may include questions or suggestions regarding the project. Tags and issue format will be decided later.

## Code Style Guides

This project is based largely on the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html). It also tries to follow the [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines). The project also includes a defined `.clang-format` file. You can use this file to automatically format source codes. Detailed style document will be written later.

## How to Test a New Implementation

This project requires Kubernetes for testing. There are many ways and tools to install Kubernetes in your local environment. I'll leave the links to some of them below:

- [MicroK8s](https://microk8s.io/#install-microk8s)
- [minikube](https://minikube.sigs.k8s.io/docs/start/?arch=%2Fwindows%2Fx86-64%2Fstable%2F.exe+download)
- [kind](https://kind.sigs.k8s.io/docs/user/quick-start/)