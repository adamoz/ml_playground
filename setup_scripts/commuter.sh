echo "$(tput setaf 2)Adding yarn to apt source list.."
curl -sS https://dl.yarnpkg.com/debian/pubkey.gpg | sudo apt-key add -
echo "deb https://dl.yarnpkg.com/debian/ stable main" | sudo tee /etc/apt/sources.list.d/yarn.list
sudo apt update
sudo apt install yarn
echo "$(tput setaf 2)Exporting path to yarn binary into the basrc.."
echo 'export PATH="$(yarn global bin --offline):$PATH"' | sudo tee -a ~/.bashrc
source ~/.bashrc
echo "$(tput setaf 2)Installing commuter"
yarn global add @nteract/commuter

echo -e "\n\n$(tput setab 0)$(tput setaf 2)Usage: \nCOMMUTER_LOCAL_STORAGE_BASEDIRECTORY=./ commuter\nCOMMUTER_BUCKET=bb-experiments COMMUTER_STORAGE_BACKEND=s3 commuter"
