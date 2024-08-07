local options = {
	backup = false, -- creates a backup file
	backspace = "indent,eol,start", -- allow backspace on indent, end of line or insert mode start position
	clipboard = "unnamedplus", -- allows neovim to access the system clipboard
	cmdheight = 0, -- more space in the neovim command line for displaying messages
	-- colorcolumn = "80",
	completeopt = { "menuone", "noselect" },
	conceallevel = 0, -- so that `` is visible in markdown files
	fileencoding = "utf-8", -- the encoding written to a file
	foldmethod = "manual", -- folding, set to "expr" for treesitter based folding
	guicursor = "n-v-c-i:block", -- thick cursor
	hidden = true, -- required to keep multiple buffers and open multiple buffers
	hlsearch = false, -- highlight all matches on previous search pattern
	incsearch = true,
	ignorecase = true, -- ignore case in search patterns
	laststatus = 3, -- always and ONLY the last window has a status line
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
	updatetime = 50, -- faster completion, defaults to 4000ms
	writebackup = false, -- if a file is being edited by another program (or was written to file while editing with another program), it is not allowed to be edited
	expandtab = true,
	shiftwidth = 2, -- the number of spaces inserted for each indentation
	tabstop = 2, -- insert x spaces for a tab
	softtabstop = 2,
	autoindent = true,
	cursorline = false, -- highlight the current line
	number = true, -- set numbered lines
	relativenumber = true, -- set relative numbered lines
	numberwidth = 2, -- set number column width to 2 {default 4}
	signcolumn = "yes", -- always show the sign column, otherwise it would shift the text each time
	wrap = false, -- display lines as one long line
	scrolloff = 8, -- IMPORTANT! minimal number of screen lines to keep above and below the cursor.
	sidescrolloff = 8, -- IMPORTANT! minimal number of screen lines to keep left and right of the cursor.
	showcmd = false,
	ruler = true, -- shows the line and column number of the cursor position, separated by a comma
}

vim.opt.iskeyword:append("-")
vim.opt.isfname:append("@-@")
vim.g.netrw_banner = 0 -- Disables the Netrw banner. Press 'I' to toggle.
vim.g.netrw_liststyle = 3 -- Sets the view to treeview.

vim.opt.path:append("/Users/matthewrosse/.opam/default/share/ocp-indent/vim")

for k, v in pairs(options) do
	vim.opt[k] = v
end
