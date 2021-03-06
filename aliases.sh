alias ga='git add'
alias gc='git commit --allow-empty-message -m "."'
alias gd='git diff'
alias gg='ga .gitignore KATA-LOG LESSON_LEARNED TODO aliases.sh *cpp anki/*tsv *tsv *.java; gc; gp'
alias ggg='pushd .; cdanki; cd ..; gg; popd'
alias gp='git push -u origin master'
alias gs='git status'
alias gpl='git pull'
alias kata='kata_file $(random_kata); subl a.cpp &'
alias rlcm='./rlc.sh 2'
alias rlch='./rlc.sh 3'
alias pat="cat patterns.txt |grep -E '(//|^$)' > patterns_todo.txt ; nano patterns_todo.txt"
alias patc="diff -y patterns*"

git config --local user.name "a"
git config --local user.email ""
