#! /bin/bash

if ! [[ -x ../my-unzip ]]; then
    echo "my-unzip executable does not exist"
    exit 1
fi

../run-tests.sh $*


