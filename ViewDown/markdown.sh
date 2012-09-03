#!/usr/bin/python
import sys, os

current_dir = os.path.split(os.path.realpath(__file__))[0]
zip_file = os.path.join(current_dir, "markdown.zip")

sys.path.append(zip_file)


import markdown
import markdown.__main__

markdown.__main__.run()
