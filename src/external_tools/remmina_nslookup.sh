#!/bin/sh

. $(dirname $0)/functions.sh
settitle

nslookup $server

pause
