#!/bin/bash

find . -type f -name '*.sh' | sed "s/.*\///; s/\.sh//"
