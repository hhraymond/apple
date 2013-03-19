#!/bin/bash

if [ $# -ne 1 ]; then
    echo "usage: ./svnserve.sh start"
    echo "usage: ./svnserve.sh stop"
    exit 1
fi

# "ps ux" can find the process

if [ $1 = "start" ] ; then
    svnserve -d -r /home/huangz/projects/svn_server --listen-port 8999
elif [ $1 = "stop" ] ; then
    ret=$(pgrep -f "svnserve -d -r /home/huangz/projects/svn_server --listen-port 8999 --listen-port 8999")
    echo "kill svnserve pid: $ret"
    kill -9 $ret
else
    echo "usage: ./svnserve.sh start"
    echo "usage: ./svnserve.sh stop"
fi

