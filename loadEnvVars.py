import os

with open("./credentials.txt", mode="r") as envFile:
    lines = envFile.read()
    env = os.linesep.join(
        [
            line for line in lines.splitlines()
            if line
        ]
    )

    for entry in env.splitlines():
        [key, value] = entry.split("=")
        if (key and value):
            print("-D {}='{}'".format(key, value))