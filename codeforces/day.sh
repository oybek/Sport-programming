#!/bin/bash
n=$(find . -daystart -ctime 0 -print | grep -c -e "[A-Z].cpp$")
echo "(~˘▾˘)~ today you solved ${n} problems ~(˘▾˘~)"

