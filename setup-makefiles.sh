#!/bin/sh

set -e

export DEVICE=thea
export VENDOR=motorola
./../../$VENDOR/msm8226-common/setup-makefiles.sh $@
