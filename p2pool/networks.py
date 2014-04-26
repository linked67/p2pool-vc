from p2pool.bitcoin import networks
from p2pool.util import math

# CHAIN_LENGTH = number of shares back client keeps
# REAL_CHAIN_LENGTH = maximum number of shares back client uses to compute payout
# REAL_CHAIN_LENGTH must always be <= CHAIN_LENGTH
# REAL_CHAIN_LENGTH must be changed in sync with all other clients
# changes can be done by changing one, then the other

nets = dict(


virtualcoin=math.Object(                                             
        PARENT=networks.nets['virtualcoin'],                             
        SHARE_PERIOD=15, # seconds                                       
        NEW_SHARE_PERIOD=15, # seconds                                   
        CHAIN_LENGTH=24*60*60//10, # shares
        REAL_CHAIN_LENGTH=24*60*60//10, # shares                         
        TARGET_LOOKBEHIND=60, # shares  //with that the pools share diff is adjusting faster, important if huge hashing power comes to the pool
        SPREAD=30, # blocks                                              
        NEW_SPREAD=30, # blocks
        IDENTIFIER='2c6e67d44ab0c712'.decode('hex'),                     
        PREFIX='76e5a2b380aa75d3'.decode('hex'),
        P2P_PORT=3095, 
        MIN_TARGET=4,                                                    
        MAX_TARGET=2**256//2**20 - 1,
        PERSIST=False,
        WORKER_PORT=3094,
        BOOTSTRAP_ADDRS='vc.altmine.net p2poolcoin.com'.split(' '),                     
        ANNOUNCE_CHANNEL='#p2pool-vc',
        VERSION_CHECK=lambda v: True,                                    
    ),

)
for net_name, net in nets.iteritems():
    net.NAME = net_name
