echo "----------------"
echo "Starting installation for RIOT-OS tools, compiler, programmers ands files"
echo "----------------"

echo "----------------"
echo "Updating apt"
echo "----------------"
sudo apt update -y

echo "----------------"
echo "Installing git"
echo "----------------"
sudo apt-get install -y git

echo "----------------"
echo "Installing GNU-Make"
echo "----------------"
sudo apt install -y make

echo "----------------"
echo "Starting installation for arm-none-eabi-gcc compiler"
echo "----------------"
echo "Creating workdir /opt"
mkdir -p /opt 
echo "Installing 'curl'"
sudo apt-get install -y curl
echo "----------------"
echo "Fetching arm-none-eabi-gcc from web"
echo "----------------"
sudo curl -L -o /opt/gcc-arm-none-eabi.tar.bz2 https://developer.arm.com/-/media/Files/downloads/gnu-rm/9-2019q4/gcc-arm-none-eabi-9-2019-q4-major-x86_64-linux.tar.bz2
echo "fe0029de4f4ec43cf7008944e34ff8cc /opt/gcc-arm-none-eabi.tar.bz2" | md5sum -c 
echo "Extracting archive"
sudo tar -C /opt -jxf /opt/gcc-arm-none-eabi.tar.bz2
sudo rm -f /opt/gcc-arm-none-eabi.tar.bz2
echo 'Removing documentation' >&2
sudo rm -rf /opt/gcc-arm-none-eabi-*/share/doc

echo "----------------"
echo "Adding arm-none-eabi-gcc to path"
# checking if PATH exists in ~/.bashrc
if grep -q "export PATH=\"\${PATH}:/opt/gcc-arm-none-eabi-9-2019-q4-major/bin\"" ~/.bashrc; then
	echo "PATH is already up to date"
else
	echo "export PATH=\"\${PATH}:/opt/gcc-arm-none-eabi-9-2019-q4-major/bin\"">>~/.bashrc
	export PATH="$PATH:/opt/gcc-arm-none-eabi-9-2019-q4-major/bin"
fi
#source /etc/environment && export PATH
#source <(sudo cat /etc/environment)
echo "----------------"

# for make flash to work with 64bits
echo "Installing 'gcc-multilib'"
sudo apt install -y gcc-multilib
echo "----------------"
echo "arm-none-eabi-gcc installation finished"
echo "----------------"

echo "----------------"
echo "Installing pyserial"
echo "----------------"
need pyserial of python3:
sudo apt install -y python3-pip
pip3 install pyserial
pip3 install intelhex

echo "----------------"
echo "Installing openocd for flashing STM32"
echo "----------------"
sudo apt-get install -y openocd

echo "----------------"
echo "Installing unzip"
echo "----------------"
sudo apt install unzip


echo "----------------"
echo "RIOT tools installation finished"
echo "----------------"