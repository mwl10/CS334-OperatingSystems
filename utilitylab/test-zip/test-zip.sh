#! /bin/bash

if ! [[ -x ../my-zip ]]; then
    echo "my-zip executable does not exist"
    exit 1
fi

../run-tests.sh $*


