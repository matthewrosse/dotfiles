export EDITOR="nvim"
export TERMINAL="kitty"
export PATH="$HOME/.local/bin:$HOME/bin:$PATH"
export GOPATH=$HOME/.local/share/go

export ANDROID_HOME="$HOME/Android/Sdk"

export PATH="$ANDROID_HOME/platform-tools:$PATH"
export PATH="$HOME/.cargo/bin:$PATH"

# pnpm
export PNPM_HOME="/Users/matthewrosse/Library/pnpm"
case ":$PATH:" in
  *":$PNPM_HOME:"*) ;;
  *) export PATH="$PNPM_HOME:$PATH" ;;
esac
# pnpm end

export DOTNET_CLI_TELEMETRY_OPTOUT=1
