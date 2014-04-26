#!/bin/sh
SERVICE='python ./run_p2pool.py --net virtualcoin'

if ps ax | grep -v grep | grep "$SERVICE" > /dev/null
then
        echo "$SERVICE is already running!"
else
        screen -d -m -S P2P_DRK_DIFF python ./run_p2pool.py --net virtualcoin --give-author 0 --disable-upnp -f 0.5 -a VDBNjNjUznaw6HJ9Txd38j2tdCuZStwUwC

	wait
fi
