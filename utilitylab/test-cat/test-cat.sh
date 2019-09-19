#! /bin/bash

if ! [[ -x ../my-cat ]]; then
    echo "my-cat executable does not exist"
    exit 1
fi

../run-tests.sh $*


