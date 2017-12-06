# Hooks
+ Add ssh key to ec2 instance :
`cat ~/.ssh/id_rsa.pub | ssh -i <path-to-pem file>/file.pem <user>@<host> "cat >> .ssh/authorized_keys"`

+ Create hooks directory: `mkdir <directory-name>.git`
+ Change to hooks directory and make git hooks:`<directory-name>.git && sudo git init --bare`

+ Create `post-receive` shell script in hooks directory.
```
#!/bin/sh
GIT_WORK_TREE=<where source should store directory>
export GIT_WORK_TREE
echo "Checking out to the working directory"
    git checkout dev -f
    cd <where source should store directory>
    export NVM_DIR="$HOME/.nvm"
    [ -s "$NVM_DIR/nvm.sh" ] && . "$NVM_DIR/nvm.sh" # This loads nvm
    npm -v
    node -v
    npm install
    pm2 restart 6
    echo "All Done!"
```
