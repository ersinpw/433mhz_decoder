#!/bin/bash

TODAY=$(TZ=":Europe/Amsterdam" date "+%Y/%m/%d %H:%M:%S")

echo $(curl --header "Access-Token: TOKEN" --header "Content-Type: application/json" \
     --data-binary "{ \"body\":\" Some text \", \"title\":\"$TODAY - $1\", \"type\":\"note\" }" \
     --request POST \
     https://api.pushbullet.com/v2/pushes)
