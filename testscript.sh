#!/bin/bash

for i in {1..10000};
do
    echo "<172> May 18 14:10:05 tgr02.dal13 255330: 10.0.13.40 RP/0/RSP0/CPU0:Apr  4 19:39:33.710 UTC: ipv4_rib[1268]: %ROUTING-RIB-4-PREFIXES_BELOW_THRESHOLD : The previously full route prefix table (0xe0000880), VRF: HUB-463-SPOKE-1273 is no longer full and can accept more routes. " | nc localhost 1026
done
