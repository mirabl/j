alias gp='git push -u origin master'
alias gc='git commit --allow-empty-message -m ""'
alias ga='git add'
alias gd='git diff'
alias gs='git status'
alias g='git'
alias gg='ga *cpp anki/*; gc; gp'

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
