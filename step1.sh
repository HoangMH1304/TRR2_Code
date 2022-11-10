git config svn-remote.svn.fetch trunk:refs/remotes/svn/trunk
git config svn-remote.svn.branches branches/*:refs/remotes/svn/*
git config svn-remote.svn.tags tags/*:refs/remotes/svn/tags/*

rm .git/refs/remotes/*
git svn fetch