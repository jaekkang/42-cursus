#!/bin/bash

ifconfig | grep 'ether ' | tr -d '\t''' | sed 's/ether //g' | sed 's/ //g'
