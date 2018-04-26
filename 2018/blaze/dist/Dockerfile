FROM ubuntu:16.04

RUN apt-get -y update && \
    apt-get -y upgrade && \
    apt-get -y install libatk1.0-0 libc6 libcairo-gobject2 libcairo2 libdbus-1-3 libdbus-glib-1-2 libfontconfig1 libfreetype6 libgcc1 libgdk-pixbuf2.0-0 libglib2.0-0 libgtk-3-0 libpango-1.0-0 libpangocairo-1.0-0 libstartup-notification0 libstdc++6 libx11-6 libx11-xcb1 libxcb-shm0 libxcb1 libxcomposite1 libxdamage1 libxext6 libxfixes3 libxrender1 libxt6 software-properties-common && add-apt-repository ppa:ubuntu-toolchain-r/test -y && apt-get -y update && apt-get -y install gcc-6 g++-6

RUN groupadd -g 1000 sloth && useradd -g sloth -m -u 1000 sloth -s /bin/bash

ADD obj-x86_64-pc-linux-gnu-release.deb /tmp

RUN dpkg -i /tmp/obj-x86_64-pc-linux-gnu-release.deb

USER sloth

ADD --chown=sloth:sloth firefox /home/sloth/.mozilla/firefox

ADD flag /

CMD ["bash"]

