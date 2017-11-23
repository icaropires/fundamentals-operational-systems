# -*- mode: ruby -*-
# vi: set ft=ruby :

# All Vagrant configuration is done below. The "2" in Vagrant.configure
# configures the configuration version (we support older styles for
# backwards compatibility). Please don't change it unless you know what
# you're doing.
Vagrant.configure(2) do |config|
  # The most common configuration options are documented and commented below.
  # For a complete reference, please see the online documentation at
  # https://docs.vagrantup.com.

  # Every Vagrant development environment requires a box. You can search for
  # boxes at https://atlas.hashicorp.com/search.
  config.vm.box = "gbarbieru/xenial"

  # Disable automatic box update checking. If you disable this, then
  # boxes will only be checked for updates when the user runs
  # `vagrant box outdated`. This is not recommended.
  # config.vm.box_check_update = false

  # Create a forwarded port mapping which allows access to a specific port
  # within the machine from a port on the host machine. In the example below,
  # accessing "localhost:8080" will access port 80 on the guest machine.
  # config.vm.network "forwarded_port", guest: 80, host: 8080

  # Create a private network, which allows host-only access to the machine
  # using a specific IP.
  # config.vm.network "private_network", ip: "192.168.33.10"

  # Create a public network, which generally matched to bridged network.
  # Bridged networks make the machine appear as another physical device on
  # your network.
  config.vm.network "public_network", bridge: ["wlan0", "wlp2s0"]

  # Share an additional folder to the guest VM. The first argument is
  # the path on the host to the actual folder. The second argument is
  # the path on the guest to mount the folder. And the optional third
  # argument is a set of non-required options.
  config.vm.synced_folder ".", "/home/distributed/FSO"

  # Provider-specific configuration so you can fine-tune various
  # backing providers for Vagrant. These expose provider-specific options.
  # Example for VirtualBox:
  #
  # config.vm.provider "virtualbox" do |vb|
  #   # Display the VirtualBox GUI when booting the machine
  #   vb.gui = true
  #
  #   # Customize the amount of memory on the VM:
  #   vb.memory = "1024"
  # end
  #
  # View the documentation for the provider you are using for more
  # information on available options.

  # Define a Vagrant Push strategy for pushing to Atlas. Other push strategies
  # such as FTP and Heroku are also available. See the documentation at
  # https://docs.vagrantup.com/v2/push/atlas.html for more information.
  # config.push.define "atlas" do |push|
  #   push.app = "YOUR_ATLAS_USERNAME/YOUR_APPLICATION_NAME"
  # end

  # Enable provisioning with a shell script. Additional provisioners such as
  # Puppet, Chef, Ansible, Salt, and Docker are also available. Please see the
  # documentation for more information about their specific syntax and use.
  config.vm.provision "shell", inline: <<-SHELL
	# Install general things
	
	# sudo apt-get update
	sudo apt-get install vim -y
	sudo apt-get install libcr-dev mpich mpich-doc -y
	sudo apt-get install openssh-server -y
	sudo apt-get install nfs-kernel-server -y # master
	sudo apt-get install nfs-common -y # slave
	sudo apt-get install scala -y

	sudo apt-get install apt-transport-https -y

	# Install sbt
	echo "deb https://dl.bintray.com/sbt/debian /" | sudo tee -a /etc/apt/sources.list.d/sbt.list
	sudo apt-key adv --keyserver hkp://keyserver.ubuntu.com:80 --recv 2EE0EA64E40A89B84B2DF73499E82A75642AC823
	sudo apt-get update
	sudo apt-get install gc -y
	sudo apt-get install sbt -y

	# Add distributed user
	sudo adduser distributed --gecos "" --disabled-password
	sudo adduser distributed sudo
	echo "distributed:dist" | sudo chpasswd
	sudo chown -R distributed:distributed /home/distributed

	sudo su distributed -c "ssh-keygen -t rsa -N '' -f /home/distributed/.ssh/id_rsa"

	# Spark
	
	# To be able do add ppa's
	sudo apt-get install software-properties-common -y
	sudo apt-get install python3-software-properties -y
	sudo apt-get install python-software-properties -y

	wget http://javadl.oracle.com/webapps/download/AutoDL?BundleId=227542_e758a0de34e24606bca991d704f6dcbf

	# Install jdk
	sudo add-apt-repository ppa:webupd8team/java
	sudo apt-get update
	echo debconf shared/accepted-oracle-license-v1-1 select true | sudo debconf-set-selections
	echo debconf shared/accepted-oracle-license-v1-1 seen true | sudo debconf-set-selections
	sudo apt-get install oracle-java8-installer -y

	# Install hadoop
	wget http://ftp.unicamp.br/pub/apache/hadoop/common/hadoop-2.8.2/hadoop-2.8.2.tar.gz
	tar -zxvf hadoop-2.8.2.tar.gz

	sudo apt-get upgrade
  SHELL
end
