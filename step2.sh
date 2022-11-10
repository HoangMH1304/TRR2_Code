for BRANCH in $(svn ls https://svn.riouxsvn.com/test_svn_hoang/branches/); do
    git branch $BRANCH remotes/svn/$BRANCH
done