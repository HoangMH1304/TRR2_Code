cat .git/hooks/svn-rebase-all
 
    #!/bin/sh
 
    date >> .git/svn-rebase.log
    git reset --quiet --hard
    for REF in .git/refs/heads/*
    do
        BRANCH=${REF##*/}
        echo Updating $BRANCH
        git checkout --quiet --force $BRANCH
        git svn rebase
    done 2>&1 | tee -a .git/svn-rebase.log
    git checkout --quiet --force master
 
chmod +x .git/hooks/svn-rebase-alls