# Colorize grep output (good for log files)
alias grep='grep --color=auto'
alias egrep='egrep --color=auto'
alias fgrep='fgrep --color=auto'

# confirm before overwriting something
alias cp="cp -i"
alias mv='mv -i'
alias rm='rm -i'

# easier to read disk
alias df='df -h'     # human-readable sizes
alias free='free -m' # show sizes in MB

# get top process eating memory
alias psmem='ps auxf | sort -nr -k 4 | head -5'
# get top process eating cpu ##
alias pscpu='ps auxf | sort -nr -k 3 | head -5'

# Create alias override commands using 'exa'
alias ls='eza --group-directories-first --icons'
alias ll='ls -lh --git'
alias la='ll -a'
alias tree='ll --tree --level=2'

# navigation
alias ..='cd ..' 
alias ...='cd ../..'
alias .3='cd ../../..'
alias .4='cd ../../../..'
alias .5='cd ../../../../..'

alias f='fzf-tmux'
alias pn='pnpm'
alias python='python3'
alias pip='pip3'
alias lg='lazygit'

alias dev-update='brew update && brew upgrade && rustup update && bun upgrade && npm update -g && asdf update && asdf plugin update --all && gem update --system && gem update'
