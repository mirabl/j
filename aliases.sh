alias gp='git push -u origin master'
alias gc='git commit --allow-empty-message -m ""'
alias ga='git add'
alias gd='git diff'
alias gs='git status'
alias g='git'
alias gg='ga LESSON_LEARNED TODO TMP aliases.sh *cpp anki/*; gc; gp'

alias ff='ls -l'
alias f='ls'
alias q='cd ..'
alias n='nano'
alias lrt='ls -lrt'
alias l=less

function co {
	g++ -Wall -std=c++11 -g $1
}

function coex {
	co $1 && ./a.out
}

function lce {
f=$1 
while inotifywait -qq $f -e close_write  ; do coex $1 ; done
}

function lc {
f=$1 
while inotifywait -qq $f -e close_write  ; do co $1 ; done
}

function nf {
f=$1
touch $f ; subl $f ; lce $f
}

alias md='make demo'
alias ms='make sys'
alias msv='make sysv'
alias msv='make sysv'
function msvc {
 make sysv case=$1
}

function random_kata {
	ls K*cpp|grep -v KX|shuf|head -1
}

function kata_file {
	awk '/BEGIN/{flag=1;next}/END/{flag=0}flag' $1 > a.cpp
}
