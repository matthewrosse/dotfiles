local options = {
	backup = false, -- creates a backup file
	clipboard = "unnamedplus", -- allows neovim to access the system clipboard
	cmdheight = 0, -- more space in the neovim command line for displaying messages
	completeopt = { "menuone", "noselect" },
	conceallevel = 0, -- so that `` is visible in markdown files
	fileencoding = "utf-8", -- the encoding written to a file
	foldmethod = "manual", -- folding, set to "expr" for treesitter based folding
	hidden = true, -- required to keep multiple buffers and open multiple buffers
	hlsearch = true, -- highlight all matches on previous search pattern
	incsearch = true,
	ignorecase = true, -- ignore case in search patterns
	mouse = "a", -- allow the mouse to be used in neovim
	pumheight = 10, -- pop up menu height
	showmode = false, -- we don't need to see things like -- INSERT -- anymore
	showtabline = 2, -- always show tabs
	smartcase = true, -- smart case
	smarttab = true,
	smartindent = true,
	splitbelow = true, -- force all horizontal splits to go below current window
	splitright = true, -- force all vertical splits to go to the right of current window
	swapfile = false, -- creates a swapfile
	termguicolors = true, -- set term gui colors (most terminals support this)
  background = "dark",
	timeoutlen = 1000, -- time to wait for a mapped sequence to complete (in ms, default: 1000)
	title = true, -- set the title of window to the value of the titlestring
	undodir = os.getenv("HOME") .. "/.vim/undodir", --set an undo directory
	undofile = true, -- enable persistent undo
	updatetime = 500, -- faster completion, defaults to 4000ms
	writebackup = false, -- if a file is being edited by another program (or was written to file while editing with another program), it is not allowed to be edited
	expandtab = true,
	shiftwidth = 2, -- the number of spaces inserted for each indentation
	tabstop = 2, -- insert x spaces for a tab
	softtabstop = 2,
	autoindent = true,
	cursorline = false, -- highlight the current line
	number = true, -- set numbered lines
	relativenumber = true, -- set relative numbered lines
	numberwidth = 4, -- set number column width to 2 {default 4}
	signcolumn = "yes", -- always show the sign column, otherwise it would shift the text each time
	wrap = false, -- display lines as one long line
	scrolloff = 8, -- IMPORTANT! minimal number of screen lines to keep above and below the cursor.
	sidescrolloff = 8, -- IMPORTANT! minimal number of screen lines to keep left and right of the cursor.
	showcmd = false,
	ruler = true, -- shows the line and column number of the cursor position, separated by a comma
	laststatus = 3, -- always and ONLY the last window has a status line
	guicursor = "n-v-c-i:block", -- thick cursor
  backspace = "indent,eol,start" -- allow backspace on indent, end of line or insert mode start position
}

vim.opt.iskeyword:append("-")
vim.opt.isfname:append("@-@")

for k, v in pairs(options) do
	vim.opt[k] = v
end
