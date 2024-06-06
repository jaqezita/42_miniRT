FROM ubuntu:20.04

# Install dependencies

ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update && \
    # apt-get upgrade -y && \
    apt-get install -y \
    build-essential \
    clang-12 \
    make \
    git \
    curl \
    cmake \
    pkg-config \
    libffi-dev \
    libgit2-dev \
    meson python3-pip \
    nano vim \
    zsh \
    libxext-dev \
    libxmu-dev \
    libxi-dev \
    libgl1-mesa-dev \
    libx11-dev \
    libglfw3-dev \
    libglfw3 \
    xorg-dev \
    wget

# Install criterion.h

RUN pip3 install meson==0.55.0 && git clone https://github.com/Snaipe/Criterion.git
WORKDIR /Criterion
RUN mkdir build
WORKDIR /Criterion/build
RUN meson ..
RUN ninja
RUN ninja install
RUN ldconfig

WORKDIR /

# install zsh and oh-my-zsh

RUN sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)" && \
    sed -i 's/plugins=(git)/plugins=(git zsh-autosuggestions zsh-syntax-highlighting)/g' ~/.zshrc && \
    git clone https://github.com/zsh-users/zsh-autosuggestions ${ZSH_CUSTOM:-~/.oh-my-zsh/custom}/plugins/zsh-autosuggestions && \
    git clone https://github.com/zsh-users/zsh-syntax-highlighting.git ${ZSH_CUSTOM:-~/.oh-my-zsh/custom}/plugins/zsh-syntax-highlighting
RUN echo "alias gcc='clang'" >> ~/.bashrc
RUN echo "alias gcc='clang'" >> ~/.zshrc
RUN chsh -s $(which zsh)

# Copy the files

RUN mkdir /minirt
WORKDIR /minirt

# Run the project

ENTRYPOINT [ "zsh" ]